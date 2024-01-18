#include "RTE_CommunicationProtocolParser.h"
#include "GLOBALS_IEC6205621Protocol.h"

/************************************/
/*Local variables*******************/
/**********************************/

/************************************/
/*Local function definitions********/
/**********************************/

/************************************/
/*Global functions******************/
/**********************************/

void RTE_CommunicationProtocolParser_FillBufferWithRequestIdMessage(uint8_t *bufferToBeFilled, uint16_t* sizeOfFilledBufferInBytes)
{
    uint8_t requestIdMessage[IEC6205621_REQUEST_ID_SIZE_IN_BYTES] = {0u};
    uint16_t bufferIndex = 0u;

    requestIdMessage[IEC6205621_REQUEST_ID__place_of_StartCharacter]                 = IEC6205621_REQUEST_ID__value_of_StartCharacter;
    requestIdMessage[IEC6205621_REQUEST_ID__place_of_TransmissionRequestCharacter]   = IEC6205621_REQUEST_ID__value_of_TransmissionRequestCharacter;
    requestIdMessage[IEC6205621_REQUEST_ID__place_of_EndCharacter]                   = IEC6205621_REQUEST_ID__value_of_EndCharacter;
    requestIdMessage[IEC6205621_REQUEST_ID__place_of_CR]                             = IEC6205621_REQUEST_ID__value_of_CR;
    requestIdMessage[IEC6205621_REQUEST_ID__place_of_LF]                             = IEC6205621_REQUEST_ID__value_of_LF;

    *sizeOfFilledBufferInBytes = IEC6205621_REQUEST_ID_SIZE_IN_BYTES;

    for(bufferIndex = 0u; bufferIndex < *sizeOfFilledBufferInBytes; bufferIndex++)
    {
        bufferToBeFilled[bufferIndex] = requestIdMessage[bufferIndex];
    }
}

void RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage(uint8_t *bufferToBeFilled, 
                                                                                   uint16_t *sizeOfFilledBufferInBytes, 
                                                                                   uint8_t baudRateCharacterInHex)
{
    uint8_t ackMessage[IEC6205621_ACK_AND_OPTION_SELECT_SIZE_IN_BYTES] = {0u};
    uint16_t bufferIndex = 0u;

    ackMessage[IEC6205621_ACK_AND_OPTION_SELECT__place_of_ACK] = IEC6205621_ACK_AND_OPTION_SELECT__value_of_ACK;
    ackMessage[IEC6205621_ACK_AND_OPTION_SELECT__place_of_V]   = IEC6205621_ACK_AND_OPTION_SELECT__value_of_V__normal_protocol_procedure;
    ackMessage[IEC6205621_ACK_AND_OPTION_SELECT__place_of_Z]   = baudRateCharacterInHex;
    ackMessage[IEC6205621_ACK_AND_OPTION_SELECT__place_of_Y]   = IEC6205621_ACK_AND_OPTION_SELECT__value_of_Y__data_readout;
    ackMessage[IEC6205621_ACK_AND_OPTION_SELECT__place_of_CR]  = IEC6205621_ACK_AND_OPTION_SELECT__place_of_CR;
    ackMessage[IEC6205621_ACK_AND_OPTION_SELECT__place_of_LF]  = IEC6205621_ACK_AND_OPTION_SELECT__place_of_LF;

    *sizeOfFilledBufferInBytes = IEC6205621_ACK_AND_OPTION_SELECT_SIZE_IN_BYTES;
    for(bufferIndex = 0u; bufferIndex < *sizeOfFilledBufferInBytes; bufferIndex++)
    {
        bufferToBeFilled[bufferIndex] = ackMessage[bufferIndex];
    }
}

uint8_t RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(uint8_t *idString, uint16_t sizeOfIdStringInBytes)
{
    uint8_t baudRateCharacter = 0u;

    if(IEC6205621_METER_ID__place_of_BaudRateCharacter < sizeOfIdStringInBytes )
    {
        // we could test here if the value is valid. If not, then return 0 -- default 300 baud
        baudRateCharacter = idString[IEC6205621_METER_ID__place_of_BaudRateCharacter];
    }

    return baudRateCharacter;
}

uint8_t RTE_CommunicationProtocolParser_GetIdReplyRxTerminatingCharacter(void)
{
    return (uint8_t)IEC6205621_REQUEST_ID_REPLY_TERMINATING_CHARACTER;
}

uint8_t RTE_CommunicationProtocolParser_GetDataReadReplyRxTerminatingCharacter(void)
{
    return (uint8_t)IEC6205621_DATA_READOUT_REPLY_TERMINATING_CHARACTER;
}

/************************************/
/*Local functions*******************/
/**********************************/