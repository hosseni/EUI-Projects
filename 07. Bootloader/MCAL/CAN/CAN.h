/*
 * CAN.h
 *
 *  Created on: Sep 21, 2023
 *      Author: mohas
 */

#ifndef MCAL_CAN_H_
#define MCAL_CAN_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_can.h"
#include "driverlib/can.h"

#define START_FLASHING_RECEIVED 1
#define CODE_RECEIVED 2
#define ACKNOWLEDGE_RECEIVED 3

#define START_FLASHING_MSG_OBJ 1
#define CODE_MSG_OBJ 2
#define ACKNOWLEDGE_MSG_OBJ 3

void CAN0_init(void);

void CAN0_adjustReceiveMessage(tCANMsgObject* can0RxMessage, uint32_t messageObj, uint32_t messageId, uint32_t msgIdMask, uint32_t msgLength);

void CAN0_adjustSendMessage(tCANMsgObject* can0TxMessage, uint32_t messageId, uint32_t msgLength);

void CAN0_receiveMessage(tCANMsgObject* can0RxMessage, uint8_t* data, uint32_t messageObj);


void CAN0_sendMessage(tCANMsgObject* can0TxMessage, uint32_t messageObj, uint8_t* data, uint32_t dataSize);

uint8_t CAN0_receiveStatus(uint32_t typeMessage);

void CAN0_resetStatus(uint32_t typeMessage);

#endif /* MCAL_CAN_H_ */
