#ifndef _GLOBALS_TYPES_H_
#define _GLOBALS_TYPES_H_

// Application Type Definitions
typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char uint8_t;

#ifndef __cplusplus
typedef unsigned char bool;
#define false (bool) 0
#define true  (bool) 1
#endif

// Application Special Value Definitions
#ifndef TRUE
#define TRUE (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif
#ifndef NULL
#define NULL (0)
#endif // NULL
#define DONT_CARE (0)

#ifndef INFINITY
#define INFINITY (1.0 / 0.0)
#endif

#ifndef NAN
#define NAN (0.0 / 0.0)
#endif

// MIN/MAX Definitions for Standard Types
#ifndef INT8_MAX
#define INT8_MAX 127
#endif

#ifndef INT8_MIN
#define INT8_MIN (-128)
#endif

#ifndef UINT8_MAX
#define UINT8_MAX 0xFFU
#endif

#ifndef UINT8_MIN
#define UINT8_MIN 0x00U
#endif

#ifndef INT16_MAX
#define INT16_MAX 32767
#endif

#ifndef INT16_MIN
#define INT16_MIN (-32768)
#endif

#ifndef UINT16_MAX
#define UINT16_MAX 0xFFFFU
#endif

#ifndef UINT16_MIN
#define UINT16_MIN 0x0000U
#endif

#ifndef INT32_MAX
#define INT32_MAX 0x7FFFFFFF
#endif

#ifndef INT32_MIN
#define INT32_MIN (-INT32_MAX - 1)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX 0xFFFFFFFFU
#endif

#ifndef UINT32_MIN
#define UINT32_MIN 0x00000000U
#endif

#ifdef TEST
#define TESTABLE_STATIC
#else
#define TESTABLE_STATIC static
#endif

#endif // _GLOBALS_TYPES_H_