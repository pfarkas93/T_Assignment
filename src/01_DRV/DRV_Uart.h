#ifndef _DRV_UART_H_
#define _DRV_UART_H_

#include "GLOBALS_Types.h"
#include "GLOBALS_UartCallbackTypes.h"


/**
 * @brief Initialize Uart Driver
 */
void DRV_Uart_Init(void);

/**
 * @brief Set RX buffer
 * 
 * @param[in] rxBufferAddress       Rx buffer address
 * @param[in] rxBufferSizeInBytes   Rx buffer size in bytes
 */
void DRV_Uart_SetRxBuffer(uint8_t* rxBufferAddress, uint16_t rxBufferSizeInBytes);

/**
 * @brief Set TX data
 * 
 * @param[in] txDataAddress       Tx data address
 * @param[in] txDataSizeInBytes   Rx data size in bytes
 */
void DRV_Uart_SetTxData(uint8_t* txDataAddress, uint16_t txDataSizeInBytes);

/**
 * @brief Set terminating character of receiving data.
 * 
 * @param[in] rxEndCharacter   Rx terminating character
 */
void DRV_Uart_SetRxEndCharacter(uint8_t rxEndCharacter);

/**
 * @brief Set uart baud rate
 * 
 * @param[in] newBaudRate New baud rate value
 */
void DRV_Uart_SetBaudRate(uint16_t newBaudRate);

/**
 * @brief Register Rx Done callback
 * 
 * @param[in] rxDoneCallback Function pointer to the callback
 */
void DRV_Uart_RegisterCallbackOnRxDone(RxDoneUartCallbackFunction_t rxDoneCallback);

/**
 * @brief Register Tx Done callback
 * 
 * @param[in] txDoneCallback Function pointer to the callback
 */
void DRV_Uart_RegisterCallbackOnTxDone(TxDoneUartCallbackFunction_t txDoneCallback);

/**
 * @brief Start uart transmit
 */
void DRV_Uart_StartTx(void);

/**
 * @brief Enable uart receiving
 */
void DRV_Uart_EnableRx(void);

/**
 * @brief Disable uart receiving
 */
void DRV_Uart_DisableRx(void);




#endif //_DRV_UART_H_