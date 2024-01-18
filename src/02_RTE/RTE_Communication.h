#ifndef _RTE_COMMUNICATION_H_
#define _RTE_COMMUNICATION_H_

#include "GLOBALS_Types.h"

/**
 * @brief Initialize communication run time service
 * 
 * @return none
 */

void RTE_Communication_Init(void);

void RTE_Communication_SendHello(uint8_t* txDataAddress, uint16_t txDataSizeInBytes, TxDoneUartCallbackFunction_t txDoneCallback);
void RTE_Communication_ListenToHelloAnswer(uint8_t* rxBufferAddress, uint16_t rxBufferSizeInBytes);

void RTE_Communication_SendMeterDataReadoutRequest(uint8_t* txDataAddress, uint16_t txDataSizeInBytes);
void RTE_Communication_SetMeterDataRxBaudRate(uint16_t newBaudRate);
void RTE_Communication_ListenToMeterData(uint8_t* rxBufferAddress, uint16_t rxBufferSizeInBytes);
void RTE_Communication_ResetBaudRate(void);

#endif //_RTE_COMMUNICATION_H_