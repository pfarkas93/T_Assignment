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
/* DRV_Uart_RegisterCallbackOnRxDone()*************************************************/
/* DRV_Uart_RegisterCallbackOnTxDone()*************************************************/
/* DRV_Uart_StartTx()*************************************************/
/* DRV_Uart_EnableRx()*************************************************/
/* DRV_Uart_DisableRx()*************************************************/