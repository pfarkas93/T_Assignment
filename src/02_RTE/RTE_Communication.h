#ifndef _RTE_COMMUNICATION_H_
#define _RTE_COMMUNICATION_H_

#include "GLOBALS_Types.h"
#include "GLOBALS_UartCallbackTypes.h"

/**
 * @brief Initialize communication run time service
 */
void RTE_Communication_Init(void);

/**
 * @brief Send message to meter device via uart
 * 
 * @param[in] txDataAddress       Tx data address
 * @param[in] txDataSizeInBytes   Tx data size in bytes
 * @param[in] txDoneCallback      Tx done callback function pointer
 */
void RTE_Communication_SendMessageToMeterDevice(uint8_t *txDataAddress, 
                                                uint16_t txDataSizeInBytes, 
                                                TxDoneUartCallbackFunction_t txDoneCallback);

/**
 * @brief Listen and receive data from meter device
 * 
 * @param[in] rxBufferAddress       Rx buffer address
 * @param[in] rxBufferSizeInBytes   Rx buffer size in bytes
 * @param[in] rxEndCharacter        Rx end character
 * @param[in] rxDoneCallback        Rx done callback function pointer
 */
void RTE_Communication_ListenToMeterDeviceAnswer(uint8_t *rxBufferAddress, 
                                                 uint16_t rxBufferSizeInBytes, 
                                                 uint8_t rxEndCharacter, 
                                                 RxDoneUartCallbackFunction_t rxDoneCallback);

/**
 * @brief Set uart baud rate
 * 
 * @param[in] newBaudRate New baud rate value       
 */
void RTE_Communication_SetMeterDataRxBaudRate(uint16_t newBaudRate);

/**
 * @brief Reset baud rate to default (300)     
 */
void RTE_Communication_ResetBaudRate(void);

#endif //_RTE_COMMUNICATION_H_