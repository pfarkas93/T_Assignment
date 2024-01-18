#ifndef _RTE_COMMUNICATIONPROTOCOLPARSER_H_
#define _RTE_COMMUNICATIONPROTOCOLPARSER_H_

#include "GLOBALS_Types.h"

/**
 * @brief Fill buffer with request id message
 * 
 * @param[out] bufferToBeFilled             Buffer to be filled       
 * @param[out] sizeOfFilledBufferInBytes    Size of filled buffer in bytes       
 */
void RTE_CommunicationProtocolParser_FillBufferWithRequestIdMessage(uint8_t* bufferToBeFilled, uint16_t* sizeOfFilledBufferInBytes);

/**
 * @brief Fill buffer with ack and data readout request message
 * 
 * @param[out] bufferToBeFilled             Buffer to be filled       
 * @param[out] sizeOfFilledBufferInBytes    Size of filled buffer in bytes       
 * @param[in]  baudRateCharacterInHex       Baud rate character in hex, which is part of the message       
 */
void RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage(uint8_t* bufferToBeFilled, 
                                                                                   uint16_t* sizeOfFilledBufferInBytes, 
                                                                                   uint8_t baudRateCharacterInHex);

/**
 * @brief Get baud rate character in hexadecimal format fron the ID string 
 * 
 * @param[in] idString               Id string       
 * @param[in] sizeOfIdStringInBytes  Id string size in bytes    
 */                                                                                   
uint8_t RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(uint8_t* idString, uint16_t sizeOfIdStringInBytes);

/**
 * @brief Get terminating character for ID request reply   
 */ 
uint8_t RTE_CommunicationProtocolParser_GetIdReplyRxTerminatingCharacter(void);

/**
 * @brief Get terminating character for data read   
 */ 
uint8_t RTE_CommunicationProtocolParser_GetDataReadReplyRxTerminatingCharacter(void);

#endif //_RTE_COMMUNICATIONPROTOCOLPARSER_H_