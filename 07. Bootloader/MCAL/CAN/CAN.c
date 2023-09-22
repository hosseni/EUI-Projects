/*
 * CAN.c
 *
 *  Created on: Sep 21, 2023
 *      Author: mohasseb
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "can.h"

uint8_t err = 0;
uint8_t rx_startFlashing = 0;
uint8_t rx_codeFlashing = 0;
uint8_t rx_acknowledge = 0;

static void CAN0_Int_Handler();

/* this function is used to initialize CAN0 */
void CAN0_init(void)
{
    /* Enable GPIOB peripheral to use pins for CAN0 */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    /* Configure pins for CAN0 (PB4 - CAN0RX, PB5 - CAN0TX) */
    GPIOPinConfigure(GPIO_PB4_CAN0RX);
    GPIOPinConfigure(GPIO_PB5_CAN0TX);
    GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    /* Enable CAN0 peripheral */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
    /* Initialize the CAN controller */
    CANInit(CAN0_BASE);
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000); /* 500Kbps */
    CANIntRegister(CAN0_BASE, CAN0_Int_Handler);
    /* Enable CAN interrupt */
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR); /* | CAN_INT_STATUS if we want to make interrupt for status register */
    IntEnable(INT_CAN0);
    /* Enable CAN0 */
    CANEnable(CAN0_BASE);
}

/* this function takes structure of message and initialization values to adjust message object and configure CAN to receive this message */
void CAN0_adjustReceiveMessage(tCANMsgObject *can0RxMessage, uint32_t messageObj, uint32_t messageId, uint32_t msgIdMask, uint32_t msgLength)
{
    can0RxMessage->ui32MsgID = messageId;                                     /* Message ID to match */
    can0RxMessage->ui32MsgIDMask = msgIdMask;                                 /* if mask is enabled we configure mask to accept which messages */
    can0RxMessage->ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER; /* Enable interrupt when receiving */
    can0RxMessage->ui32MsgLen = msgLength;                                    /* Maximum message length (adjust as needed) in bytes */
    /* This call also allows the message object to be configured to generate interrupts on completion of message receipt or transmission */
    CANMessageSet(CAN0_BASE, messageObj, can0RxMessage, MSG_OBJ_TYPE_RX);
}

/* we use this function to receive message from can, we pass pointer to array to store data in it */
void CAN0_receiveMessage(tCANMsgObject *can0RxMessage, uint8_t *data, uint32_t messageObj)
{
    can0RxMessage->pui8MsgData = data;
    CANMessageGet(CAN0_BASE, messageObj, can0RxMessage, 1);
}

/* this function takes structure of message and initialization values to adjust message object and configure CAN to send this message */
void CAN0_adjustSendMessage(tCANMsgObject *can0TxMessage, uint32_t messageId, uint32_t msgLength)
{
    can0TxMessage->ui32MsgID = messageId; /* Message ID to match */
    can0TxMessage->ui32MsgIDMask = 0;
    can0TxMessage->ui32Flags = MSG_OBJ_TX_INT_ENABLE; /* Enable interrupt when receiving */
    can0TxMessage->ui32MsgLen = msgLength;            /* Maximum message length (adjust as needed) */
}

/* this function takes data and size and message obj and structure to send */
void CAN0_sendMessage(tCANMsgObject *can0TxMessage, uint32_t messageObj, uint8_t *data, uint32_t dataSize)
{
    can0TxMessage->ui32MsgLen = dataSize;
    can0TxMessage->pui8MsgData = data;
    CANMessageSet(CAN0_BASE, messageObj, can0TxMessage, MSG_OBJ_TYPE_TX); /* Send the message */
}

uint8_t CAN0_receiveStatus(uint32_t typeMessage)
{
    if (START_FLASHING_RECEIVED == typeMessage)
    {
        return rx_startFlashing;
    }
    else if (CODE_RECEIVED == typeMessage)
    {
        return rx_codeFlashing;
    }
    else if (ACKNOWLEDGE_RECEIVED == typeMessage)
    {
        return rx_acknowledge;
    }
}

void CAN0_resetStatus(uint32_t typeMessage)
{
    if (START_FLASHING_RECEIVED == typeMessage)
    {
        rx_startFlashing = 0;
    }
    else if (CODE_RECEIVED == typeMessage)
    {
        rx_codeFlashing = 0;
    }
    else if (ACKNOWLEDGE_RECEIVED == typeMessage)
    {
        rx_acknowledge = 0;
    }
}

void CAN0_Int_Handler()
{
    uint32_t ui32Status;
    ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);
    /* to know which message object make interrupt */
    if (START_FLASHING_MSG_OBJ == ui32Status)
    {
        CANIntClear(CAN0_BASE, START_FLASHING_MSG_OBJ);
        rx_startFlashing = 1;
    }
    else if (CODE_MSG_OBJ == ui32Status)
    {
        CANIntClear(CAN0_BASE, CODE_MSG_OBJ);
        rx_codeFlashing = 1;
    }
    /* that message object we need in sending ECU */
    else if (ACKNOWLEDGE_MSG_OBJ == ui32Status)
    {
        CANIntClear(CAN0_BASE, ACKNOWLEDGE_MSG_OBJ);
        rx_acknowledge = 1;
    }
}
