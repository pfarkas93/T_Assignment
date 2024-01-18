#ifndef _RTE_COMMUNICATIONPROTOCOLPARSER_H_
#define _RTE_COMMUNICATIONPROTOCOLPARSER_H_

#include "GLOBALS_Types.h"


void RTE_CommunicationProtocolParser_FillBufferWithRequestIdMessage(uint8_t* bufferToBeFilled, uint16_t* sizeOfFilledBufferInBytes);

void RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage(uint8_t* bufferToBeFilled, 
                                                                                   uint16_t* sizeOfFilledBufferInBytes, 
                                                                                   uint8_t baudRateCharacterInHex);
                                                                                   
uint8_t RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(uint8_t* idString, uint16_t sizeOfIdStringInBytes);

uint8_t RTE_CommunicationProtocolParser_GetIdReplyRxTerminatingCharacter(void);

uint8_t RTE_CommunicationProtocolParser_GetDataReadReplyRxTerminatingCharacter(void);
#endif //_RTE_COMMUNICATIONPROTOCOLPARSER_H_