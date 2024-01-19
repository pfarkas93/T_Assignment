#include "unity.h"
#include "RTE_Communication.h"
#include "mock_DRV_Uart.h"

void setUp(void)
{
    mock_DRV_Uart_Init();
}

void tearDown(void)
{
    mock_DRV_Uart_Verify();
    
    mock_DRV_Uart_Destroy();
}

/*RTE_Communication_Init()************************************************************/
void test_GivenNothing_WhenCommunicationInitCalled_ThenExpectInitUartDriver(void)
{
    DRV_Uart_Init_Expect();
    RTE_Communication_Init();
}

/*RTE_Communication_SendMessageToMeterDevice()************************************************************/
void test_GivenNothing_WhenSendMessageToMeterDeviceCalled_ThenExpectSetDataAndStartTx(void)
{
    uint8_t testData = 0u;
    uint16_t testSize = 0;
    TxDoneUartCallbackFunction_t testCallback;

    DRV_Uart_RegisterCallbackOnTxDone_Expect(testCallback);
    DRV_Uart_SetTxData_Expect(&testData, testSize);
    DRV_Uart_StartTx_Expect();
    RTE_Communication_SendMessageToMeterDevice(&testData, testSize, testCallback );
}

/*RTE_Communication_ListenToMeterDeviceAnswer()************************************************************/
void test_GivenNothing_WhenListenToMeterDeviceAnswerCalled_ThenExpectSetBuffersAndTerminatingCondition(void)
{
    uint8_t testBuffer = 0u;
    uint16_t testSize = 0;
    RxDoneUartCallbackFunction_t testCallback;
    uint8_t testEndCharacter = 'a';

    DRV_Uart_RegisterCallbackOnRxDone_Expect(testCallback);
    DRV_Uart_SetRxBuffer_Expect(&testBuffer, testSize);
    DRV_Uart_SetRxEndCharacter_Expect(testEndCharacter);
    DRV_Uart_EnableRx_Expect();
    RTE_Communication_ListenToMeterDeviceAnswer(&testBuffer, testSize, testEndCharacter, testCallback );
}

/*RTE_Communication_SetMeterDataRxBaudRate()************************************************************/
void test_GivenNothing_WhenSetMeterDataRxBaudRateCalled_ThenExpectSetBaudRate(void)
{
    uint16_t testNewBaudRate = 600u;
    DRV_Uart_SetBaudRate_Expect(testNewBaudRate);
    RTE_Communication_SetMeterDataRxBaudRate( testNewBaudRate );
}

/*RTE_Communication_ResetBaudRate()************************************************************/
void test_GivenNothing_WhenResetMeterDataRxBaudRateCalled_ThenExpectResetBaudRateTo300(void)
{
    DRV_Uart_SetBaudRate_Expect(300u);
    RTE_Communication_ResetBaudRate( );
}