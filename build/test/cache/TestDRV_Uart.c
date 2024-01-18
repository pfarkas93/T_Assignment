#include "src/01_DRV/DRV_Uart.h"
#include "C:/Users/peter.farkas/Desktop/Coding/Tibber/vendor/ceedling/vendor/unity/src/unity.h"


extern volatile uint8_t* SV_rxBuffer;

extern volatile uint16_t SV_rxBufferSizeInBytes;

extern volatile uint16_t SV_rxBufferIterator;

extern volatile uint8_t SV_rxEndCharacter;



extern volatile uint8_t* SV_txData;

extern volatile uint16_t SV_txDataSizeInBytes;

extern volatile uint16_t SV_txDataIterator;



extern volatile RxDoneUartCallbackFunction_t SV_rxDoneCallback;

extern volatile TxDoneUartCallbackFunction_t SV_txDoneCallback;



extern uint16_t S_mockUartBaudRate;

extern uint8_t S_mockUartTxRegister;

extern uint8_t S_mockUartRxRegister;

extern bool S_mockIsTxBufferEmptyInterruptEnabled;

extern bool S_mockIsRxBufferNotEmptyInterruptEnabled;



static uint8_t S_testBuffer[10];



void setUp(void)

{

    SV_rxBuffer = 

                 ((void *)0)

                     ;

    SV_rxBufferSizeInBytes = 0u;

    SV_rxBufferIterator = 0u;

    SV_rxEndCharacter = 0u;



    SV_txData = 

               ((void *)0)

                   ;

    SV_txDataSizeInBytes = 0u;

    SV_txDataIterator = 0u;



    SV_rxDoneCallback = 

                       ((void *)0)

                           ;

    SV_txDoneCallback = 

                       ((void *)0)

                           ;



    S_mockUartBaudRate = 0u;

    S_mockUartTxRegister = 0u;

    S_mockUartRxRegister = 0u;

    S_mockIsTxBufferEmptyInterruptEnabled = (bool) 0;

    S_mockIsRxBufferNotEmptyInterruptEnabled = (bool) 0;

}



void tearDown(void)

{



}





void test_GivenStartup_WhenUartInitCalled_ThenExpectBaudRateIsSetTo300(void)

{

    DRV_Uart_Init();

    UnityAssertEqualNumber((UNITY_INT)((300u)), (UNITY_INT)((S_mockUartBaudRate)), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

}





void test_GivenBufferPointer_WhenUartSetRxBufferCalled_ThenExpectSetStaticVariables(void)

{

    DRV_Uart_SetRxBuffer(S_testBuffer, 10);



    UnityAssertEqualNumber((UNITY_INT)((S_testBuffer)), (UNITY_INT)((SV_rxBuffer)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((SV_rxBufferSizeInBytes)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SV_rxBufferIterator)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

}



void test_GivenBufferPointerNULL_WhenUartSetRxBufferCalled_ThenExpectBufferAddressNULL(void)

{

    DRV_Uart_SetRxBuffer(

                        ((void *)0)

                            , 10);



    UnityAssertEqualNumber((UNITY_INT)((

   ((void *)0)

   )), (UNITY_INT)((SV_rxBuffer)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((SV_rxBufferSizeInBytes)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SV_rxBufferIterator)), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);

}





void test_GivenTxDataPointer_WhenUartSetTxDataCalled_ThenExpectSetStaticVariables(void)

{

    DRV_Uart_SetTxData(S_testBuffer, 10);



    UnityAssertEqualNumber((UNITY_INT)((S_testBuffer)), (UNITY_INT)((SV_txData)), (

   ((void *)0)

   ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((SV_txDataSizeInBytes)), (

   ((void *)0)

   ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SV_txDataIterator)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

}



void test_GivenTxDataPointerNULL_WhenUartSetTxDataCalled_ThenExpectSetAddressNULL(void)

{

    DRV_Uart_SetTxData(

                      ((void *)0)

                          , 10);



    UnityAssertEqualNumber((UNITY_INT)((

   ((void *)0)

   )), (UNITY_INT)((SV_txData)), (

   ((void *)0)

   ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((SV_txDataSizeInBytes)), (

   ((void *)0)

   ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SV_txDataIterator)), (

   ((void *)0)

   ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);

}





void test_GivenEndCharacter_WhenUartSetRxEndCharacterCalled_ThenExpectSetEndCharacter(void)

{

    DRV_Uart_SetRxEndCharacter(0x08);



    UnityAssertEqualNumber((UNITY_INT)((0x08)), (UNITY_INT)((SV_rxEndCharacter)), (

   ((void *)0)

   ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

}





void test_Given600Baud_WhenUartSetBaudRateCalled_ThenExpectSetBaudRateTo600(void)

{

    DRV_Uart_SetBaudRate(600);



    UnityAssertEqualNumber((UNITY_INT)((600)), (UNITY_INT)((S_mockUartBaudRate)), (

   ((void *)0)

   ), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT);

}





void test_GivenCallback_WhenUartRegisterCallbackOnRxDoneCalled_ThenExpectCallbackRegistered(void)

{

    RxDoneUartCallbackFunction_t testCallback;

    DRV_Uart_RegisterCallbackOnRxDone(testCallback);



    UnityAssertEqualNumber((UNITY_INT)((testCallback)), (UNITY_INT)((SV_rxDoneCallback)), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

}



void test_GivenCallbackNULL_WhenUartRegisterCallbackOnRxDoneCalled_ThenExpectCallbackNULL(void)

{

    DRV_Uart_RegisterCallbackOnRxDone(

                                     ((void *)0)

                                         );



    UnityAssertEqualNumber((UNITY_INT)((

   ((void *)0)

   )), (UNITY_INT)((SV_rxDoneCallback)), (

   ((void *)0)

   ), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

}





void test_GivenCallback_WhenUartRegisterCallbackOnTxDoneCalled_ThenExpectCallbackRegistered(void)

{

    TxDoneUartCallbackFunction_t testCallback;

    DRV_Uart_RegisterCallbackOnTxDone(testCallback);



    UnityAssertEqualNumber((UNITY_INT)((testCallback)), (UNITY_INT)((SV_txDoneCallback)), (

   ((void *)0)

   ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_INT);

}



void test_GivenCallbackNULL_WhenUartRegisterCallbackOnTxDoneCalled_ThenExpectCallbackNULL(void)

{

    DRV_Uart_RegisterCallbackOnTxDone(

                                     ((void *)0)

                                         );



    UnityAssertEqualNumber((UNITY_INT)((

   ((void *)0)

   )), (UNITY_INT)((SV_txDoneCallback)), (

   ((void *)0)

   ), (UNITY_UINT)(140), UNITY_DISPLAY_STYLE_INT);

}





void test_GivenTxDataSet_WhenStartTxCalled_ThenExpectFillTxRegisterAndIncrementIterator(void)

{

    S_testBuffer[0] = 'a';

    DRV_Uart_SetTxData(S_testBuffer, sizeof(S_testBuffer));



    DRV_Uart_StartTx();



    UnityAssertEqualNumber((UNITY_INT)(('a')), (UNITY_INT)((S_mockUartTxRegister)), (

   ((void *)0)

   ), (UNITY_UINT)(151), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1u)), (UNITY_INT)((SV_txDataIterator)), (

   ((void *)0)

   ), (UNITY_UINT)(152), UNITY_DISPLAY_STYLE_INT);

}





void test_GivenRxDisabled_WhenEnableRxalled_ThenExpectEnableRx(void)

{

    UnityAssertEqualNumber((UNITY_INT)(((bool) 0)), (UNITY_INT)((S_mockIsRxBufferNotEmptyInterruptEnabled)), (

   ((void *)0)

   ), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_INT);



    DRV_Uart_EnableRx();



    UnityAssertEqualNumber((UNITY_INT)(((bool) 1)), (UNITY_INT)((S_mockIsRxBufferNotEmptyInterruptEnabled)), (

   ((void *)0)

   ), (UNITY_UINT)(162), UNITY_DISPLAY_STYLE_INT);

}





void test_GivenRxEnabled_WhenDisleRxalled_ThenExpectDisableRx(void)

{

    DRV_Uart_EnableRx();

    UnityAssertEqualNumber((UNITY_INT)(((bool) 1)), (UNITY_INT)((S_mockIsRxBufferNotEmptyInterruptEnabled)), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);



    DRV_Uart_DisableRx();

    UnityAssertEqualNumber((UNITY_INT)(((bool) 0)), (UNITY_INT)((S_mockIsRxBufferNotEmptyInterruptEnabled)), (

   ((void *)0)

   ), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_INT);

}
