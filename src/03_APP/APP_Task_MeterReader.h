#ifndef _APP_TASK_METERREADER_H_
#define _APP_TASK_METERREADER_H_

#include "GLOBALS_Types.h"

void APP_Task_MeterReader(void);

typedef enum
{
    E_MeterReaderStates_Init,
    E_MeterReaderStates_Idle,
    E_MeterReaderStates_SendRequestId,
    E_MeterReaderStates_SleepUntilRequestIdTxDone,
    E_MeterReaderStates_StartListeningToMeterDeviceIdReply,
    E_MeterReaderStates_SleepUntilMeterDeviceIdRxDone,
    E_MeterReaderStates_SaveDeviceIdAndParseBaudRate,
    E_MeterReaderStates_SendAckAndDataReadoutRequest,
    E_MeterReaderStates_SleepUntilAckAndDataReadoutRequestTxDone,
    E_MeterReaderStates_SetNewBaudRate,
    E_MeterReaderStates_StartListeningToDataReadoutReply,
    E_MeterReaderStates_SleepUntilDataReadoutReplyRxDone,
    E_MeterReaderStates_ParseAndSaveData,
    E_MeterReaderStates_HandleError,
    E_Count_of_MeterReaderStates
} E_MeterReaderStates_t;

#endif //_APP_TASK_METERREADER_H_