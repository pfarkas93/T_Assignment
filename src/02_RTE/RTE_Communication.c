#include "RTE_Communication.h"
#include "RTE_CommunicationProtocolParser.h"
#include "DRV_Uart.h"
/************************************/
/*Local variables*******************/
/**********************************/

/************************************/
/*Local function definitions********/
/**********************************/

/************************************/
/*Global functions******************/
/**********************************/

void RTE_Communication_Init(void)
{
    DRV_Uart_Init();
}

void RTE_Communication_SendHello(uint8_t *txDataAddress, uint16_t txDataSizeInBytes, TxDoneUartCallbackFunction_t txDoneCallback)
{

    DRV_Uart_RegisterCallbackOnRxDone(txDoneCallback);
    DRV_Uart_SetTxData(txDataAddress, txDataSizeInBytes);
    DRV_Uart_StartTx();
}

void RTE_Communication_ListenToHelloAnswer(uint8_t *rxBufferAddress, uint16_t rxBufferSizeInBytes)
{
}

void RTE_Communication_SendMeterDataReadoutRequest(uint8_t *txDataAddress, uint16_t txDataSizeInBytes)
{
}

void RTE_Communication_SetMeterDataRxBaudRate(uint16_t newBaudRate)
{
}

void RTE_Communication_ListenToMeterData(uint8_t *rxBufferAddress, uint16_t rxBufferSizeInBytes)
{
}

void RTE_Communication_ResetBaudRate(void)
{
}

/************************************/
/*Local functions*******************/
/**********************************/