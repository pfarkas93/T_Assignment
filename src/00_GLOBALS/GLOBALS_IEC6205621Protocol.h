#ifndef _GLOBALS_IEC6205621PROTOCOL_H_
#define _GLOBALS_IEC6205621PROTOCOL_H_

// Chapter references from the IEC62056-21 standard are mared with '@'


#define CR_Character 0x0D // carriage return
#define LF_Character 0x0A // line feed

//Hello: @6.3.1 Request message

#define IEC6205621_HELLO_SIZE_IN_BYTES 5

#define IEC6205621_HELLO__place_of_StartCharacter 0
    #define IEC6205621_HELLO__value_of_StartCharacter 0x2F // '/'

#define IEC6205621_HELLO__place_of_TransmissionRequestCharacter 1
    #define IEC6205621_HELLO__value_of_TransmissionRequestCharacter 0x3F // '?'

#define IEC6205621_HELLO__place_of_EndCharacter 2
    #define IEC6205621_HELLO__value_of_EndCharacter 0x21 // '!'

#define IEC6205621_HELLO__place_of_CR 3
    #define IEC6205621_HELLO__value_of_CR CR_Character // carriage return

#define IEC6205621_HELLO__place_of_LF 4
    #define IEC6205621_HELLO__value_of_LF LF_Character // line feed


// Answer to Hello: @6.3.2 Identification message
#define IEC6205621_METER_ID__place_of_BaudRateCharacter 4 // 5th byte of the answer

//ACK and option select: @6.3.3 Acknowledgement/option select message
#define IEC6205621_ACK_AND_OPTION_SELECT_SIZE_IN_BYTES 6

#define IEC6205621_ACK_AND_OPTION_SELECT__place_of_ACK 0   // ACK character
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_ACK 0x06 // ACK character

#define IEC6205621_ACK_AND_OPTION_SELECT__place_of_V 1 // V: protocol control character 
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_V__normal_protocol_procedure    0x30 //'0'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_V__secondary_protocol_procedure 0x31 //'1'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_V__HDLC_protocol_procedure      0x32 //'2'

#define IEC6205621_ACK_AND_OPTION_SELECT__place_of_Z 2 // Z: baud rate
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Z__300   0x30 //'0'   
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Z__600   0x31 //'1'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Z__1200  0x32 //'2'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Z__2400  0x33 //'3'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Z__4800  0x34 //'4'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Z__9600  0x35 //'5'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Z__19200 0x36 //'6'

#define IEC6205621_ACK_AND_OPTION_SELECT__place_of_Y 3 // Y: mode control character
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Y__data_readout 0x30 //'0'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Y__programming_mode 0x31 //'1'
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_Y__binary_mode_HDLC 0x32 //'2'

#define IEC6205621_ACK_AND_OPTION_SELECT__place_of_CR 4 // carriage return
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_CR CR_Character

#define IEC6205621_ACK_AND_OPTION_SELECT__place_of_LF 5 // line feed
    #define IEC6205621_ACK_AND_OPTION_SELECT__value_of_LF LF_Character


/*
Answer:
2F 4C 47 5A 34 5A 4D 46 31 30 30 41 43 2E 4D 32 39 0D 0A
Z = ID[4] -- baud

ACK:
ACK V   Z   Y  CR LF
4) 10) 13) 11) 3) 3)

ACK: 0x06
V: protocol control character 
	0 - normal protocol procedure.
	1 - secondary protocol procedure.
	2 - HDLC protocol procedure, see Annex E.
	3-9 - reserved for future applications.
Z: baud 
	0 - 300 Bd
	1 - 600 Bd
	2 - 1 200 Bd
	3 - 2 400 Bd
	4 - 4 800 Bd
	5 - 9 600 Bd
	6 - 19 200 Bd
Y: mode control character
	0 - data readout.
	1 - programming mode.
	2 - binary mode (HDLC), see Annex E.
	3-5 and A-Z - reserved for future applications.
	6-9 - manufacturer-specific use.
CR: carriage return 0x0D
LF: line feed 0x0A


STX: start of text 0x02
ETX: enf od text  0x03
BS: backspace  0x08
*/
#endif //_GLOBALS_IEC6205621PROTOCOL_H_