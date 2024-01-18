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





/************************************/
/*Local function definitions********/
/**********************************/
static void SendRequestIdToMeter(void);
static TxDoneUartCallbackFunction_t RequestIdMessageTxDoneCallback(void);
static TxDoneUartCallbackFunction_t AckMessageTxDoneCallback(void);
static RxDoneUartCallbackFunction_t IdRxDoneCallback(uint16_t sizeOfReceivedDataInBytes);
static RxDoneUartCallbackFunction_t MeterDataRxDoneCallback(uint16_t sizeOfReceivedDataInBytes);
static void Sleep(void);
static void WakeUp(void);




/************************************/
/*Global functions******************/
/**********************************/

void APP_Task_MeterReader(void)
{
    //task loop
    for(;;)
    {
        
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
    Sleep();

}

static TxDoneUartCallbackFunction_t RequestIdMessageTxDoneCallback(void)
{
    /*@TODO:*/
    // step to the next state -- set state variable
    WakeUp();
}


static void ListenToMeterDeviceIdReply(void)
{
    uint8_t idReplyTerminatingCharacter = RTE_CommunicationProtocolParser_GetIdReplyRxTerminatingCharacter();

    RTE_Communication_ListenToMeterDeviceAnswer(SV_readBuffer, 
                                                sizeof(SV_readBuffer), 
                                                idReplyTerminatingCharacter,
                                                IdRxDoneCallback);

    /*@TODO:*/
    // step to the next state -- set state variable
    Sleep();
}

static RxDoneUartCallbackFunction_t IdRxDoneCallback(uint16_t sizeOfReceivedDataInBytes)
{
    /*@TODO:*/
    // step to the next state -- set state variable
    S_sizeOfIdStringInBytes = sizeOfReceivedDataInBytes;
    WakeUp();
}

static void SendAckAndDataReadoutRequestToMeter(void)
{
    uint16_t actualSizeOfMessageData = 0u;
    uint8_t baudRateCharacterInHex = RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(S_idString, S_sizeOfIdStringInBytes);

    RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage(SV_messageBuffer, &actualSizeOfMessageData, baudRateCharacterInHex);
    RTE_Communication_SendMessageToMeterDevice(SV_messageBuffer, actualSizeOfMessageData, AckMessageTxDoneCallback);
    
    /*@TODO:*/
    // step to the next state -- set state variable
    Sleep();
}

static TxDoneUartCallbackFunction_t AckMessageTxDoneCallback(void)
{
    /*@TODO:*/
    // step to the next state -- set state variable
    WakeUp();
}

static void ListenToMeterDataReadoutReplyOnANewBaudRate(void)
{
    uint8_t dataReadReplyTerminatingCharacter = RTE_CommunicationProtocolParser_GetDataReadReplyRxTerminatingCharacter();

    RTE_Communication_SetMeterDataRxBaudRate(S_baudRateCharacterInHex); //it will be converted with the parser beforehand

    RTE_Communication_ListenToMeterDeviceAnswer(SV_readBuffer, 
                                                sizeof(SV_readBuffer), 
                                                dataReadReplyTerminatingCharacter,
                                                MeterDataRxDoneCallback);
    /*@TODO:*/
    // step to the next state -- set state variable
    Sleep();
}

static RxDoneUartCallbackFunction_t MeterDataRxDoneCallback(uint16_t sizeOfReceivedDataInBytes)
{
    /*@TODO:*/
    // step to the next state -- set state variable
    S_sizeOfMeterDataInBytes = sizeOfReceivedDataInBytes;
    WakeUp();

}

static void Sleep(void)
{

}

static void WakeUp(void)
{

}

