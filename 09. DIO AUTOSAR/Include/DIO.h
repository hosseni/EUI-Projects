/*
 * File: DIO.h
 * Created Date: 14/10/2023
 * Author: Elhosseni Gamal
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
#define DIO_PIN_NUM         64U
#define DIO_PORT_NUM        6U
#define DIO_PORT_RW       255U

#define STD_HIGH            1U
#define STD_LOW             0U

#define DIO_PORT_PIN_NUM    8U


/************************************
 * GLOBAL TYPES
 ************************************/
typedef uint8_t Dio_ChannelType;
typedef uint8_t Dio_PortType;
typedef uint8_t Dio_LevelType;
typedef uint8_t Dio_PortLevelType;

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
