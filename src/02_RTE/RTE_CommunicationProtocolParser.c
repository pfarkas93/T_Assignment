#include "RTE_CommunicationProtocolParser.h"
#include "GLOBALS_IEC6205621Protocol.h"

void RTE_CommunicationProtocolParser_Init(void)
{
}

void RTE_CommunicationProtocolParser_FillBufferWithHelloMessage(uint8_t *bufferToBeFilled, uint16_t* sizeOfBufferInBytes)
{
    uint8_t helloMessage[IEC6205621_HELLO_SIZE_IN_BYTES] = {0u};
    uint16_t bufferIndex = 0u;

    helloMessage[IEC6205621_HELLO__place_of_StartCharacter]                 = IEC6205621_HELLO__value_of_StartCharacter;
    helloMessage[IEC6205621_HELLO__place_of_TransmissionRequestCharacter]   = IEC6205621_HELLO__value_of_TransmissionRequestCharacter;
    helloMessage[IEC6205621_HELLO__place_of_EndCharacter]                   = IEC6205621_HELLO__value_of_EndCharacter;
    helloMessage[IEC6205621_HELLO__place_of_CR]                             = IEC6205621_HELLO__value_of_CR;
    helloMessage[IEC6205621_HELLO__place_of_LF]                             = IEC6205621_HELLO__value_of_LF;

    sizeOfBufferInBytes = IEC6205621_HELLO_SIZE_IN_BYTES;

    for(bufferIndex = 0u; bufferIndex < sizeOfBufferInBytes; bufferIndex++)
    {
        bufferToBeFilled[bufferIndex] = helloMessage[bufferIndex];
    }
}

void RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage(uint8_t *bufferToBeFilled, 
                                                                             uint16_t *sizeOfBufferInBytes, 
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

    sizeOfBufferInBytes = IEC6205621_ACK_AND_OPTION_SELECT_SIZE_IN_BYTES;
    for(bufferIndex = 0u; bufferIndex < sizeOfBufferInBytes; bufferIndex++)
    {
        bufferToBeFilled[bufferIndex] = ackMessage[bufferIndex];
    }
}

uint8_t RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(uint8_t *idString, uint16_t sizeOfIdStringInBytes)
{
    return 0;
}
