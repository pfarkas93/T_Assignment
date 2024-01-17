#ifndef _RTE_COMMUNICATION_H_
#define _RTE_COMMUNICATION_H_

#include "GLOBALS_Types.h"

/**
 * @brief Initialize communication run time service
 * 
 * @return none
 */
void RTE_Communication_Init(void);

/*
SendHello(uint8_t* txDataAddress, uint16_t txDataSizeInBytes);
ListenToHelloAnswer

SendMeterDataReadoutRequest(uint8_t* txDataAddress, uint16_t txDataSizeInBytes);
SetMeterDataRxBaudRate
ListenToMeterData
ResetBaudRate

*/

#endif //_RTE_COMMUNICATION_H_