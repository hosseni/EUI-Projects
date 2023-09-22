/*
 * DIO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: mohas
 */

#ifndef DIO_H_
#define DIO_H_

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define IN 0
#define OUT 1

void DIO_Init(unsigned char portNum, unsigned char pinNum, unsigned char dir);
void DIO_WritePin(unsigned char portNum, unsigned char pinNum, unsigned char Val);
void DIO_WritePort(unsigned char portNum, unsigned char Val);
unsigned long DIO_getPortValue(unsigned char portNum);
unsigned char DIO_getPinValue(unsigned char portNum, unsigned char pinNum);
#endif /* DIO_H_ */
