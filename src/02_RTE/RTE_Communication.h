#ifndef _RTE_COMMUNICATION_H_
#define _RTE_COMMUNICATION_H_

#include "GLOBALS_Types.h"
#include "GLOBALS_UartCallbackTypes.h"

/**
 * @brief Initialize communication run time service
 * 
 * @return none
 */

void RTE_Communication_Init(void);

void RTE_Communication_SendMessageToMeterDevice(uint8_t *txDataAddress, 
                                                uint16_t txDataSizeInBytes, 
                                                TxDoneUartCallbackFunction_t txDoneCallback);

void RTE_Communication_ListenToMeterDeviceAnswer(uint8_t *rxBufferAddress, 
                                                    uint16_t rxBufferSizeInBytes, 
                                                    uint8_t rxEndCharacter, 
                                                    RxDoneUartCallbackFunction_t rxDoneCallback);

void RTE_Communication_SetMeterDataRxBaudRate(uint16_t newBaudRate);

void RTE_Communication_ResetBaudRate(void);

#endif //_RTE_COMMUNICATION_H_