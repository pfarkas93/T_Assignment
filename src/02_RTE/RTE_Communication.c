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

void RTE_Communication_SendMessageToMeterDevice(uint8_t *txDataAddress, uint16_t txDataSizeInBytes, TxDoneUartCallbackFunction_t txDoneCallback)
{
    DRV_Uart_RegisterCallbackOnTxDone(txDoneCallback);
    DRV_Uart_SetTxData(txDataAddress, txDataSizeInBytes);

    DRV_Uart_StartTx();
}

void RTE_Communication_ListenToMeterDeviceAnswer(uint8_t *rxBufferAddress, uint16_t rxBufferSizeInBytes, uint8_t rxEndCharacter, RxDoneUartCallbackFunction_t rxDoneCallback)
{
    DRV_Uart_RegisterCallbackOnRxDone(rxDoneCallback);
    DRV_Uart_SetRxBuffer(rxBufferAddress, rxBufferSizeInBytes);
    DRV_Uart_SetRxEndCharacter(rxEndCharacter);

    DRV_Uart_EnableRx();
}

void RTE_Communication_SetMeterDataRxBaudRate(uint16_t newBaudRate)
{
    DRV_Uart_SetBaudRate(newBaudRate);
}

void RTE_Communication_ResetBaudRate(void)
{
    uint16_t defaultBaudRate = 300u;
    DRV_Uart_SetBaudRate(defaultBaudRate);
}

/************************************/
/*Local functions*******************/
/**********************************/