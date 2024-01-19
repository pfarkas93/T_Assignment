# Assignment:
In this assignment, you will be implementing an international standard IEC 62056-21 (Mode
C) client on an MCU of your choice that can communicate with a metering device


# MCU:
I will go with STM32 F - series. There are low power, robust, reasonable priced MCU-s in that series.
I do not have hardware at home at the moment, so my solution will be without MCU specific code.

# Environment:
I chose **C** language with **cMake**, **Unity test** and **cMock** (with **Ceedling** build system in Ruby environment). 
I could integrate it to **VS Code**.
For STM32 specific code, I would use EMbitz IDE or STM-Cube. 
Depends, if we want to use Cube´s HAL or the direct register accessing defines in ST libraries.

# FreeRTOS:
- Tx and Rx will be done in uart interrupt
- FreeRTOS task will go to sleep (Delay or Suspend) after Tx and Rx started
- Callback will wake up the task at the end of the Tx and Rx transactions
- Waking up with notification, it is fast and low consumption and only this task will receive it
- Other tasks can run, because communication is nonblocking. No polling is needed
- Timeout needs to be set. 
----Either in FreeRTOS level (Delay) or watchdog or some other timer during the communication

# Running on battery powered device:
- Minimize heavy calculations and processor usage
  - Just do the minimal data parsing. Converting text to numbers can happen on the server/computer
  - Send short data to server/computer
  - No polling, using interrupts instead
  - Consider saving the extract of the data to persistent memory. 
    - Handheld device can be powered off (or go to low power mode),
    - data will be kept and transferred in bulk to server. 
  - Optimize code.

# Format:
A string will be sent, then the computer can parse it properly.
{ID:[id];L1:[volts]:[amps];L2:[volts]:[amps];L3:[volts]:[amps];TS:[timestamp];}
for example:
"{ID:LGZ4ZMF100AC.M29CRLF;L1:231:00.000;L2:231:00.000;L3:231:00.000;TS:59-59-23-18-01-2024;}"
  - timestamp is not necessary if it is a large overhead

# Error handling:
- checking pointers against NULL
- checking callbacks against NULL. if it is NULL, then the watchdog or something shall wake up the sleeping task.
- error message to the task OR functions always return error code...
- parser should check if BAUD rate is valid. if not, then set the Data redaout message baud to 300
- parser should check if the message will fit in the given buffer by getting the buffer max size as a parameter
- NOW we expect the buffers to be large enough to all the applications

# TX and RX:
- timeout should be set
- RX can be monitored with a timer
- Switching baud rate will happen in microseconds
- there is minimum 20 ms (according to the standard) time before the metering device starts the faster communication, so it will not be a problem

# Diagrams:

![tibber_plan_diagrams](https://github.com/pfarkas93/Tibber/assets/23613541/8174180d-cc49-41c5-8012-65f99fdc4f37)
