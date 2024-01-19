#include "unity.h"
#include "RTE_CommunicationProtocolParser.h"

void setUp(void)
{

}

void tearDown(void)
{

}

/*RTE_CommunicationProtocolParser_FillBufferWithRequestIdMessage()************************************************************/
void test_GivenNothing_WhenFillBufferWithRequestIdMessageCalled_ThenExpectFilledBuffer(void)
{
    uint8_t testBufferToBeFilled[5] = {0u};
    uint16_t testSizeOfFilledBufferInBytes = 0u;

    uint8_t comparingBuffer[5] = {0x2F, 0x3F, 0x21, 0x0D, 0x0A};

   RTE_CommunicationProtocolParser_FillBufferWithRequestIdMessage(testBufferToBeFilled, &testSizeOfFilledBufferInBytes);

   TEST_ASSERT_EQUAL_UINT8_ARRAY(comparingBuffer, testBufferToBeFilled, 5);
   TEST_ASSERT_EQUAL(5, testSizeOfFilledBufferInBytes);
}

/*RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage()********************************************/
void test_GivenBaud4_WhenFillBufferWithAckAndDataReadoutRequestMessageCalled_ThenExpectFilledBuffer(void)
{
    uint8_t testBufferToBeFilled[6] = {0u};
    uint16_t testSizeOfFilledBufferInBytes = 0u;
    uint8_t testBaudRateCharacterInHex = '4';

    uint8_t comparingBuffer[6] = {0x06, 0x30, 0x34, 0x30, 0x0D, 0x0A};

   RTE_CommunicationProtocolParser_FillBufferWithAckAndDataReadoutRequestMessage(testBufferToBeFilled, 
                                                                                &testSizeOfFilledBufferInBytes,
                                                                                testBaudRateCharacterInHex);

   TEST_ASSERT_EQUAL_UINT8_ARRAY(comparingBuffer, testBufferToBeFilled, 6);
   TEST_ASSERT_EQUAL(6, testSizeOfFilledBufferInBytes);
}

/*RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString()***********************************************/
void test_GivenBaud4AndLength6_WhenGetBaudRateValueCharacterInHexFromIdStringCalled_ThenExpectGetBaud4(void)
{
    uint8_t testBufferToBeFilled[6] = {0x00,0x00,0x00,0x00,0x34,0x00};
    uint16_t testSizeOfFilledBufferInBytes = 6u;


    uint8_t baud = RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(testBufferToBeFilled, testSizeOfFilledBufferInBytes);

    TEST_ASSERT_EQUAL('4', baud);
}

void test_GivenBaud4AndLength4_WhenGetBaudRateValueCharacterInHexFromIdStringCalled_ThenExpectGetBaud0(void)
{
    uint8_t testBufferToBeFilled[6] = {0x00,0x00,0x00,0x00,0x34,0x00};
    uint16_t testSizeOfFilledBufferInBytes = 4u;

    uint8_t baud = RTE_CommunicationProtocolParser_GetBaudRateValueCharacterInHexFromIdString(testBufferToBeFilled, testSizeOfFilledBufferInBytes);

    TEST_ASSERT_EQUAL('0', baud);
}

/*RTE_CommunicationProtocolParser_GetIdReplyRxTerminatingCharacter()***************************************/
void test_GivenNothing_WhenGetIdReplyRxTerminatingCharacterCalled_ThenExpectGet0x0A(void)
{
    uint8_t endCharacter = RTE_CommunicationProtocolParser_GetIdReplyRxTerminatingCharacter();

    TEST_ASSERT_EQUAL(0x0A, endCharacter);
}

/*RTE_CommunicationProtocolParser_GetDataReadReplyRxTerminatingCharacter()**********************************/
void test_GivenNothing_WhenGetDataReadReplyRxTerminatingCharacterCalled_ThenExpectGet0x08(void)
{
    uint8_t endCharacter = RTE_CommunicationProtocolParser_GetDataReadReplyRxTerminatingCharacter();

    TEST_ASSERT_EQUAL(0x08, endCharacter);
}