#ifndef _DRV_UART_H_
#define _DRV_UART_H_

#include "GLOBALS_Types.h"
#include "GLOBALS_UartCallbackTypes.h"


/**
 * @brief Initialize Uart Driver
 * 
 * @return none
 */
void DRV_Uart_Init(void);


void DRV_Uart_SetRxBuffer(uint8_t* rxBufferAddress, uint16_t rxBufferSizeInBytes);

void DRV_Uart_SetTxData(uint8_t* txDataAddress, uint16_t txDataSizeInBytes);

void DRV_Uart_SetRxEndCharacter(uint8_t rxEndCharacter);

void DRV_Uart_ClearRxBuffer(void);

void DRV_Uart_SetBaudRate(uint16_t newBaudRate);

void DRV_Uart_RegisterCallbackOnRxDone(RxDoneUartCallbackFunction_t rxDoneCallback);
void DRV_Uart_RegisterCallbackOnTxDone(TxDoneUartCallbackFunction_t txDoneCallback);

void DRV_Uart_StartTx(void);

void DRV_Uart_EnableRx(void);
void DRV_Uart_DisableRx(void);




#endif //_DRV_UART_H_