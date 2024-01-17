#include "DRV_Uart.h"

/************************************/
/*Local variables*******************/
/**********************************/
TESTABLE_STATIC volatile uint8_t* SV_rxBuffer = NULL;
TESTABLE_STATIC volatile uint16_t SV_rxBufferSizeInBytes = 0u;
TESTABLE_STATIC volatile uint16_t SV_rxBufferIterator = 0u;
TESTABLE_STATIC volatile uint8_t SV_rxEndCharacter = 0u;

TESTABLE_STATIC uint16_t S_mockUartBaudRate = 0u;

/************************************/
/*Local function definitions********/
/**********************************/
static void DRV_Uart_EnableTx(void);
static void DRV_Uart_DisableTx(void);
static void DRV_Uart_EnableRx(void);
static void DRV_Uart_DisableRx(void);
/************************************/
/*Global functions******************/
/**********************************/

void DRV_Uart_Init(void)
{
    S_mockUartBaudRate = 300u;
}

void DRV_Uart_RegisterRxBuffer(uint8_t* rxBufferAddress, uint16_t rxBufferSizeInBytes)
{
    SV_rxBuffer = rxBufferAddress;
    SV_rxBufferSizeInBytes = rxBufferSizeInBytes;
    SV_rxBufferIterator = 0u;
}

void DRV_Uart_SetRxEndCharacter(uint8_t rxEndCharacter)
{
    SV_rxEndCharacter = rxEndCharacter;
}

void DRV_Uart_ClearRxBuffer(void)
{
    SV_rxBufferIterator = 0u;
}

void DRV_Uart_SetBaudRate(uint16_t newBaudRate)
{

}

void DRV_Uart_RegisterCallbackOnRxDone(RxDoneUartCallbackFunction_t rxDoneCallback)
{

}

void DRV_Uart_RegisterCallbackOnTxDone(TxDoneUartCallbackFunction_t txDoneCallback)
{

}

void DRV_Uart_Send(uint8_t* txDataAddress, uint16_t txDataSizeInBytes)
{
    
}

/************************************/
/*Local functions*******************/
/**********************************/

