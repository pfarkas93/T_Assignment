#ifndef _GLOBALS_UARTCALLBACKTYPES_H_
#define _GLOBALS_UARTCALLBACKTYPES_H_

#include "GLOBALS_Types.h"

/**
 * @brief Function pointer type for rx done uart callbacks
 * 
 * @param[in] receivedDataSizeInBytes Size of the received data in bytes
 */
typedef void (*RxDoneUartCallbackFunction_t)(uint16_t receivedDataSizeInBytes);

/**
 * @brief Function pointer type for tx done uart callbacks
 *
 */
typedef void (*TxDoneUartCallbackFunction_t)(void);

#endif //_GLOBALS_UARTCALLBACKTYPES_H_