#include "DRV_Uart.h"

/************************************/
/*Local variables*******************/
/**********************************/
TESTABLE_STATIC volatile uint8_t* SV_rxBuffer = NULL;
TESTABLE_STATIC volatile uint16_t SV_rxBufferSizeInBytes = 0u;
TESTABLE_STATIC volatile uint16_t SV_rxBufferIterator = 0u;
TESTABLE_STATIC volatile uint8_t  SV_rxEndCharacter = 0u;

TESTABLE_STATIC volatile uint8_t* SV_txData = NULL;
TESTABLE_STATIC volatile uint16_t SV_txDataSizeInBytes = 0u;
TESTABLE_STATIC volatile uint16_t SV_txDataIterator = 0u;

TESTABLE_STATIC volatile RxDoneUartCallbackFunction_t SV_rxDoneCallback = NULL;
TESTABLE_STATIC volatile TxDoneUartCallbackFunction_t SV_txDoneCallback = NULL;

TESTABLE_STATIC uint16_t S_mockUartBaudRate = 0u;
TESTABLE_STATIC uint8_t  S_mockUartTxRegister = 0u;
TESTABLE_STATIC uint8_t  S_mockUartRxRegister = 0u;
TESTABLE_STATIC bool     S_mockIsTxBufferEmptyInterruptEnabled = false;
TESTABLE_STATIC bool     S_mockIsRxBufferNotEmptyInterruptEnabled = false;


/************************************/
/*Local function definitions********/
/**********************************/
static void EnableTx(void);
static void DisableTx(void);

static void TxInterruptRoutine(void);
static void RxInterruptRoutine(void);
/************************************/
/*Global functions******************/
/**********************************/

void DRV_Uart_Init(void)
{
    S_mockUartBaudRate = 300u;
}

void DRV_Uart_SetRxBuffer(uint8_t* rxBufferAddress, uint16_t rxBufferSizeInBytes)
{
    SV_rxBuffer = rxBufferAddress;
    SV_rxBufferSizeInBytes = rxBufferSizeInBytes;
    SV_rxBufferIterator = 0u;
}

void DRV_Uart_SetTxData(uint8_t* txDataAddress, uint16_t txDataSizeInBytes)
{
    SV_txData = txDataAddress;
    SV_txDataSizeInBytes = txDataSizeInBytes;
    SV_txDataIterator = 0u;
}

void DRV_Uart_SetRxEndCharacter(uint8_t rxEndCharacter)
{
    SV_rxEndCharacter = rxEndCharacter;
}

void DRV_Uart_ClearRxBuffer(void)
{
    SV_rxBufferIterator = 0u;
}

void DRV_Uart_EnableRx(void)
{
    S_mockIsRxBufferNotEmptyInterruptEnabled = true;
}

void DRV_Uart_DisableRx(void)
{
    S_mockIsRxBufferNotEmptyInterruptEnabled = false;
}

void DRV_Uart_SetBaudRate(uint16_t newBaudRate)
{
    /* First disable UART */

    S_mockUartBaudRate = newBaudRate;

    /* Enable UART (restart with new baud settings) */
}

void DRV_Uart_RegisterCallbackOnRxDone(RxDoneUartCallbackFunction_t rxDoneCallback)
{
    SV_rxDoneCallback = rxDoneCallback;
}

void DRV_Uart_RegisterCallbackOnTxDone(TxDoneUartCallbackFunction_t txDoneCallback)
{
    SV_txDoneCallback = txDoneCallback;
}

void DRV_Uart_StartTx(void)
{
    S_mockUartTxRegister = SV_txData[SV_txDataIterator];
    SV_txDataIterator++;

    EnableTx();

    /*
        First byte will be written to Uart tx register and it will send it automatically.
        Tx interrupt will kick in, if UartTxRegister is empty.
        Uart tx register will be fed with the next byte of the SV_txData in the interrupt routine.
        SV_txDataIterator will be incremented.
        Tx will be done, if the SV_txDataIterator == SV_txDataSizeInBytes.
        At Tx Done, the SV_txDoneCallback will be called and Tx interrupt will be disabled.
    */
}

/************************************/
/*Local functions*******************/
/**********************************/

static void EnableTx(void)
{
    S_mockIsTxBufferEmptyInterruptEnabled = true;
}

static void DisableTx(void)
{
    S_mockIsTxBufferEmptyInterruptEnabled = false;
}

static void TxInterruptRoutine(void)
{
    S_mockUartTxRegister = SV_txData[SV_txDataIterator];
    SV_txDataIterator++;

    if(SV_txDataSizeInBytes <= SV_txDataIterator)
    {
        DisableTx();
        SV_txDoneCallback();
    }
}

static void RxInterruptRoutine(void)
{
    SV_rxBuffer[SV_rxBufferIterator] = S_mockUartRxRegister;
    SV_rxBufferIterator++;

    if((SV_rxEndCharacter == S_mockUartRxRegister) || (SV_rxBufferIterator >= SV_rxBufferSizeInBytes))
    {
        DRV_Uart_DisableRx();
        SV_rxDoneCallback((SV_rxBufferIterator - 1u));
    }
}

