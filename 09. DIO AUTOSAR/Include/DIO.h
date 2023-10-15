/*
 * File: DIO.h
 * Created Date: 2022-07-25
 * Author: Mohamed Atef
 * -----
 * Last Modified: Mon Jul 25 2022
 * Modified By: Mohamed Atef
 * -----
 * Copyright (c) 2022
 * -----
 * Description:
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */


#ifndef DIO_H_INCLUDED
#define DIO_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "Std_Types.h"
#include "DIO_Types.h"
#include "tm4c123gh6pm_hw.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/

/************************************
 * GLOBAL DATA PROTOTYPES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
DIO_LevelType DIO_ReadChannel(DIO_ChannelType Channelid);
void DIO_WriteChannel(DIO_ChannelType Channelid, DIO_LevelType Level);
DIO_PortLevelType DIO_ReadPort(DIO_PortType Portid);
void DIO_WritePort(DIO_PortType Portid, DIO_PortLevelType Level);
DIO_LevelType DIO_FlipChannel(DIO_ChannelType Channelid);

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif
/* DIO_H_INCLUDED */
