#include "unity.h"
#include "DRV_Uart.h"

extern volatile uint8_t* SV_rxBuffer;
extern volatile uint16_t SV_rxBufferSizeInBytes;
extern volatile uint16_t SV_rxBufferIterator;
extern volatile uint8_t SV_rxEndCharacter;

extern volatile uint8_t* SV_txData;
extern volatile uint16_t SV_txDataSizeInBytes;
extern volatile uint16_t SV_txDataIterator;

extern volatile RxDoneUartCallbackFunction_t SV_rxDoneCallback;
extern volatile TxDoneUartCallbackFunction_t SV_txDoneCallback;

extern uint16_t S_mockUartBaudRate;
extern uint8_t S_mockUartTxRegister;
extern uint8_t S_mockUartRxRegister;
extern bool S_mockIsTxBufferEmptyInterruptEnabled;
extern bool S_mockIsRxBufferNotEmptyInterruptEnabled;

static uint8_t S_testBuffer[10];

void setUp(void)
{
    SV_rxBuffer = NULL;
    SV_rxBufferSizeInBytes = 0u;
    SV_rxBufferIterator = 0u;
    SV_rxEndCharacter = 0u;

    SV_txData = NULL;
    SV_txDataSizeInBytes = 0u;
    SV_txDataIterator = 0u;

    SV_rxDoneCallback = NULL;
    SV_txDoneCallback = NULL;

    S_mockUartBaudRate = 0u;
    S_mockUartTxRegister = 0u;
    S_mockUartRxRegister = 0u;
    S_mockIsTxBufferEmptyInterruptEnabled = false;
    S_mockIsRxBufferNotEmptyInterruptEnabled = false;
}

void tearDown(void)
{

}

/*DRV_Uart_Init()************************************************************/
void test_GivenStartup_WhenUartInitCalled_ThenExpectBaudRateIsSetTo300(void)
{
    DRV_Uart_Init();
    TEST_ASSERT_EQUAL(300u, S_mockUartBaudRate );
}

/*DRV_Uart_SetRxBuffer()*****************************************************/
void test_GivenBufferPointer_WhenUartSetRxBufferCalled_ThenExpectSetStaticVariables(void)
{
    DRV_Uart_SetRxBuffer(S_testBuffer, 10);
    
    TEST_ASSERT_EQUAL(S_testBuffer, SV_rxBuffer );
    TEST_ASSERT_EQUAL(10, SV_rxBufferSizeInBytes );
    TEST_ASSERT_EQUAL(0, SV_rxBufferIterator );
}

void test_GivenBufferPointerNULL_WhenUartSetRxBufferCalled_ThenExpectBufferAddressNULL(void)
{
    DRV_Uart_SetRxBuffer(NULL, 10);
    
    TEST_ASSERT_EQUAL(NULL, SV_rxBuffer );
    TEST_ASSERT_EQUAL(10, SV_rxBufferSizeInBytes );
    TEST_ASSERT_EQUAL(0, SV_rxBufferIterator );
}

/*DRV_Uart_SetTxData()*****************************************************/
void test_GivenTxDataPointer_WhenUartSetTxDataCalled_ThenExpectSetStaticVariables(void)
{
    DRV_Uart_SetTxData(S_testBuffer, 10);
    
    TEST_ASSERT_EQUAL(S_testBuffer, SV_txData );
    TEST_ASSERT_EQUAL(10, SV_txDataSizeInBytes );
    TEST_ASSERT_EQUAL(0, SV_txDataIterator );
}

void test_GivenTxDataPointerNULL_WhenUartSetTxDataCalled_ThenExpectSetAddressNULL(void)
{
    DRV_Uart_SetTxData(NULL, 10);
    
    TEST_ASSERT_EQUAL(NULL, SV_txData );
    TEST_ASSERT_EQUAL(10, SV_txDataSizeInBytes );
    TEST_ASSERT_EQUAL(0, SV_txDataIterator );
}

/*DRV_Uart_SetRxEndCharacter()*************************************************/
void test_GivenEndCharacter_WhenUartSetRxEndCharacterCalled_ThenExpectSetEndCharacter(void)
{
    DRV_Uart_SetRxEndCharacter(0x08);
    
    TEST_ASSERT_EQUAL(0x08, SV_rxEndCharacter );
}

/* DRV_Uart_SetBaudRate()*************************************************/
void test_Given600Baud_WhenUartSetBaudRateCalled_ThenExpectSetBaudRateTo600(void)
{
    DRV_Uart_SetBaudRate(600);
    
    TEST_ASSERT_EQUAL(600, S_mockUartBaudRate );
}

/* DRV_Uart_RegisterCallbackOnRxDone()*************************************************/
void test_GivenCallback_WhenUartRegisterCallbackOnRxDoneCalled_ThenExpectCallbackRegistered(void)
{
    RxDoneUartCallbackFunction_t testCallback;
    DRV_Uart_RegisterCallbackOnRxDone(testCallback);
    
    TEST_ASSERT_EQUAL(testCallback, SV_rxDoneCallback );
}

void test_GivenCallbackNULL_WhenUartRegisterCallbackOnRxDoneCalled_ThenExpectCallbackNULL(void)
{
    DRV_Uart_RegisterCallbackOnRxDone(NULL);
    
    TEST_ASSERT_EQUAL(NULL, SV_rxDoneCallback );
}

/* DRV_Uart_RegisterCallbackOnTxDone()*************************************************/
void test_GivenCallback_WhenUartRegisterCallbackOnTxDoneCalled_ThenExpectCallbackRegistered(void)
{
    TxDoneUartCallbackFunction_t testCallback;
    DRV_Uart_RegisterCallbackOnTxDone(testCallback);
    
    TEST_ASSERT_EQUAL(testCallback, SV_txDoneCallback );
}

void test_GivenCallbackNULL_WhenUartRegisterCallbackOnTxDoneCalled_ThenExpectCallbackNULL(void)
{
    DRV_Uart_RegisterCallbackOnTxDone(NULL);
    
    TEST_ASSERT_EQUAL(NULL, SV_txDoneCallback );
}

/* DRV_Uart_StartTx()*************************************************/
void test_GivenTxDataSet_WhenStartTxCalled_ThenExpectFillTxRegisterAndIncrementIterator(void)
{
    S_testBuffer[0] = 'a';
    DRV_Uart_SetTxData(S_testBuffer, sizeof(S_testBuffer));

    DRV_Uart_StartTx();
    
    TEST_ASSERT_EQUAL('a', S_mockUartTxRegister );
    TEST_ASSERT_EQUAL(1u, SV_txDataIterator );
}

/* DRV_Uart_EnableRx()*************************************************/
void test_GivenRxDisabled_WhenEnableRxalled_ThenExpectEnableRx(void)
{
    TEST_ASSERT_EQUAL(false, S_mockIsRxBufferNotEmptyInterruptEnabled );

    DRV_Uart_EnableRx();
    
    TEST_ASSERT_EQUAL(true, S_mockIsRxBufferNotEmptyInterruptEnabled );
}

/* DRV_Uart_DisableRx()*************************************************/
void test_GivenRxEnabled_WhenDisleRxalled_ThenExpectDisableRx(void)
{
    DRV_Uart_EnableRx();
    TEST_ASSERT_EQUAL(true, S_mockIsRxBufferNotEmptyInterruptEnabled );

    DRV_Uart_DisableRx();
    TEST_ASSERT_EQUAL(false, S_mockIsRxBufferNotEmptyInterruptEnabled );
}