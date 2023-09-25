/*******************************************************
 * UART_config.c
 *
 *  Created on: 8/9/2023
 *      Author: HOSSENI
 *******************************************************/


#include "MCAL/Inc/UART/UART_interface.h"
#include "../CONFIG/Inc/UART_config.h"


UART_ConfigType const uartConfig [NUM_OF_UARTS] =
                             {
                             {UART_0_, 9600, _8_BitDatat, evenParity, oneStopBit, UART_INTERRUPT_DESABLE, FIFO_DISABLE},
                             {END_OF_LIST}
                             };
