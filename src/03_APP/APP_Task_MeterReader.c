#include "APP_Task_MeterReader.h"
#include "RTE_Communication.h"
#include "RTE_CommunicationProtocolParser.h"
#include "GLOBALS_UartCallbackTypes.h"

/************************************/
/*Local variables*******************/
/**********************************/
#define MESSAGE_BUFFER_SIZE 10u
#define READ_BUFFER_SIZE 1024u
#define ID_STRING_SIZE 40u

TESTABLE_STATIC uint8_t SV_messageBuffer[MESSAGE_BUFFER_SIZE] = {0u};
TESTABLE_STATIC uint8_t SV_readBuffer[READ_BUFFER_SIZE] = {0u};
TESTABLE_STATIC uint8_t S_baudRateCharacterInHex = 0u;
TESTABLE_STATIC uint8_t S_idString[ID_STRING_SIZE] = {0u};
TESTABLE_STATIC uint16_t S_sizeOfIdStringInBytes = 0u;
TESTABLE_STATIC uint16_t S_sizeOfMeterDataInBytes = 0u;

TESTABLE_STATIC E_MeterReaderStates_t S_meterReaderTaskState = E_MeterReaderStates_Init;





/************************************/
/*Local function definitions********/
/**********************************/
static void SendRequestIdToMeter(void);
static TxDoneUartCallbackFunction_t RequestIdMessageTxDoneCallback(void);
static TxDoneUartCallbackFunction_t AckMessageTxDoneCallback(void);
static void ListenToMeterDataReadoutReplyOnANewBaudRate(void);
static void ListenToMeterDeviceIdReply(void);
static RxDoneUartCallbackFunction_t IdRxDoneCallback(uint16_t sizeOfReceivedDataInBytes);
static void SaveIdStringToStaticVariable(void);
static void SendAckAndDataReadoutRequestToMeter(void);
static RxDoneUartCallbackFunction_t MeterDataRxDoneCallback(uint16_t sizeOfReceivedDataInBytes);
static void Sleep(void);
static void WakeUp(void);
static void NextState(E_MeterReaderStates_t nextState);




/************************************/
/*Global functions******************/
/**********************************/

void APP_Task_MeterReader(void)
{
    //task loop
    for(;;)
    {
        switch(S_meterReaderTaskState)
        {
            case E_MeterReaderStates_Init:
            {
                RTE_Communication_Init();
                NextState(E_MeterReaderStates_Idle);
                break;
            }
            case E_MeterReaderStates_Idle:
            {
                /*sleep until a trigger (button push or something) arrives and the communication can start*/
                NextState(E_MeterReaderStates_SendRequestId);
                break;
            }
            case E_MeterReaderStates_SendRequestId:
            {
                SendRequestIdToMeter();
                NextState(E_MeterReaderStates_SleepUntilRequestIdTxDone);
                Sleep();
                break;
            }
            case E_MeterReaderStates_SleepUntilRequestIdTxDone:
            {
                /*RequestIdTxDoneCallback wakes up the task*/
                NextState(E_MeterReaderStates_StartListeningToMeterDeviceIdReply);
                break;
            }
            case E_MeterReaderStates_StartListeningToMeterDeviceIdReply:
            {
                ListenToMeterDeviceIdReply();
                NextState(E_MeterReaderStates_SleepUntilMeterDeviceIdRxDone);
                Sleep();
                break;
            }
            case E_MeterReaderStates_SleepUntilMeterDeviceIdRxDone:
            {
                /*IdRxDoneCallback wakes up the task*/
                NextState(E_MeterReaderStates_SaveDeviceIdAndParseBaudRate);
                break;
            }
            case E_MeterReaderStates_SaveDeviceIdAndParseBaudRate:
            {   
                SaveIdStringToStaticVariable();
                S_baudRateCharacterInHex = RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(S_idString, S_sizeOfIdStringInBytes);
                NextState(E_MeterReaderStates_SendAckAndDataReadoutRequest);
                break;
            }
            case E_MeterReaderStates_SendAckAndDataReadoutRequest:
            {
                SendAckAndDataReadoutRequestToMeter();
                NextState(E_MeterReaderStates_SleepUntilAckAndDataReadoutRequestTxDone);
                Sleep();
                break;
            }
            case E_MeterReaderStates_SleepUntilAckAndDataReadoutRequestTxDone:
            {
                /*AckMessageTxDoneCallback wakes up the task*/
                NextState(E_MeterReaderStates_SetNewBaudRate);
                break;
            }
            case E_MeterReaderStates_SetNewBaudRate:
            {
                /*Parse baud rate to numerical value*/
                RTE_Communication_SetMeterDataRxBaudRate(S_baudRateCharacterInHex);
                NextState(E_MeterReaderStates_StartListeningToDataReadoutReply);
                break;
            }
            case E_MeterReaderStates_StartListeningToDataReadoutReply:
            {
                ListenToMeterDataReadoutReplyOnANewBaudRate();
                NextState(E_MeterReaderStates_SleepUntilDataReadoutReplyRxDone);
                Sleep();
                break;
            }
            case E_MeterReaderStates_SleepUntilDataReadoutReplyRxDone:
            {
                /*MeterDataRxDoneCallback wakes up the task*/
                NextState(E_MeterReaderStates_ParseAndSaveData);
                break;
            }
            case E_MeterReaderStates_ParseAndSaveData:
            {
                /*Parse and save data*/
                /*We have the length of read data from the callback*/
                NextState(E_MeterReaderStates_Idle);
                break;
            }
            case E_MeterReaderStates_HandleError:
            {
                /*Handle error*/
                NextState(E_MeterReaderStates_Idle);
                break;
            }
            case E_Count_of_MeterReaderStates:
            {
                NextState(E_MeterReaderStates_HandleError);
                break;
            }
            default:
            {
                NextState(E_MeterReaderStates_HandleError);
                break;
            }
        }
    }
}

/************************************/
/*Local functions*******************/
/**********************************/

static void SendRequestIdToMeter(void)
{
    uint16_t actualSizeOfMessageData = 0u;
    RTE_CommunicationProtocolParser_FillBufferWithRequestIdMessage(SV_messageBuffer, &actualSizeOfMessageData);
    RTE_Communication_SendMessageToMeterDevice(SV_messageBuffer, actualSizeOfMessageData, RequestIdMessageTxDoneCallback);
}

static TxDoneUartCallbackFunction_t RequestIdMessageTxDoneCallback(void)
{
    WakeUp();
}

static void ListenToMeterDeviceIdReply(void)
{
    uint8_t idReplyTerminatingCharacter = RTE_CommunicationProtocolParser_GetIdReplyRxTerminatingCharacter();

    RTE_Communication_ListenToMeterDeviceAnswer(SV_readBuffer, 
                                                sizeof(SV_readBuffer), 
                                                idReplyTerminatingCharacter,
                                                IdRxDoneCallback);
}

static RxDoneUartCallbackFunction_t IdRxDoneCallback(uint16_t sizeOfReceivedDataInBytes)
{
    S_sizeOfIdStringInBytes = sizeOfReceivedDataInBytes;
    WakeUp();
}

static void SaveIdStringToStaticVariable(void)
{
    uint16_t idStringIndex = 0u;

    for(idStringIndex = 0u; idStringIndex < S_sizeOfIdStringInBytes; idStringIndex++)
    {
        S_idString[idStringIndex] = SV_readBuffer[idStringIndex];
    }
}

static void SendAckAndDataReadoutRequestToMeter(void)
{
    uint16_t actualSizeOfMessageData = 0u;

    RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage(SV_messageBuffer, &actualSizeOfMessageData, S_baudRateCharacterInHex);
    RTE_Communication_SendMessageToMeterDevice(SV_messageBuffer, actualSizeOfMessageData, AckMessageTxDoneCallback);
}

static TxDoneUartCallbackFunction_t AckMessageTxDoneCallback(void)
{
    WakeUp();
}

static void ListenToMeterDataReadoutReplyOnANewBaudRate(void)
{
    uint8_t dataReadReplyTerminatingCharacter = RTE_CommunicationProtocolParser_GetDataReadReplyRxTerminatingCharacter();

    RTE_Communication_ListenToMeterDeviceAnswer(SV_readBuffer, 
                                                sizeof(SV_readBuffer), 
                                                dataReadReplyTerminatingCharacter,
                                                MeterDataRxDoneCallback);
}

static RxDoneUartCallbackFunction_t MeterDataRxDoneCallback(uint16_t sizeOfReceivedDataInBytes)
{
    S_sizeOfMeterDataInBytes = sizeOfReceivedDataInBytes;
    WakeUp();
}

static void Sleep(void)
{

}

static void WakeUp(void)
{

}

static void NextState(E_MeterReaderStates_t nextState)
{
    S_meterReaderTaskState = nextState;
}

