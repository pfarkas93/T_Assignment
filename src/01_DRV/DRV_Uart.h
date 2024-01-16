#ifndef _DRV_UART_H_
#define _DRV_UART_H_

#include "GLOBALS_Types.h"


/**
 * @brief Initialize Uart Driver
 * 
 * @return none
 */
void DRV_Uart_Init(void);

/*
RegisterRxBuffer
ClearRxBuffer
SetBaudRate
RegisterCallbackOnRxDone
RegisterCallbackOnTxDone
Send
EnableTx
DisableTx
EnableRx
DisableRx
SetRxEndCharacter
*/
#endif //_DRV_UART_H_