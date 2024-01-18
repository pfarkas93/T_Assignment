#include "unity.h"
#include "RTE_Communication.h"
#include "mock_DRV_Uart.h"

void setUp(void)
{
    mock_DRV_Uart_Init();
}

void tearDown(void)
{
    mock_DRV_Uart_Verify();
    
    mock_DRV_Uart_Destroy();
}

/*RTE_Communication_Init()************************************************************/
void test_Given_WhenCommunicationInitCalled_ThenExpect(void)
{
   

    RTE_Communication_Init();
}


/*RTE_Communication_SendMessageToMeterDevice()************************************************************/
/*RTE_Communication_ListenToMeterDeviceAnswer()************************************************************/
/*RTE_Communication_SetMeterDataRxBaudRate()************************************************************/
/*RTE_Communication_ResetBaudRate()************************************************************/