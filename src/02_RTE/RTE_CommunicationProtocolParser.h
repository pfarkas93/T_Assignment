#ifndef _RTE_COMMUNICATIONPROTOCOLPARSER_H_
#define _RTE_COMMUNICATIONPROTOCOLPARSER_H_

#include "GLOBALS_Types.h"

/**
 * @brief Initialize communication protocol parser run time service
 * 
 * @return none
 */

void RTE_CommunicationProtocolParser_Init(void);
void RTE_CommunicationProtocolParser_FillBufferWithHelloMessage(uint8_t* bufferToBeFilled, uint16_t* sizeOfBufferInBytes);
void RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage(uint8_t* bufferToBeFilled, 
                                                              uint16_t* sizeOfBufferInBytes, 
                                                              uint8_t baudRateCharacterInHex);
uint8_t RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(uint8_t* idString, uint16_t sizeOfIdStringInBytes);

#endif //_RTE_COMMUNICATIONPROTOCOLPARSER_H_