/*
 * File: DIO.c
 * Created Date: 14/10/2023
 * Author: Elhosseni Gamal
 * Description:
 * ----------	---	---------------------------------------------------------
 */


/************************************
 * INCLUDES
 ************************************/
#include "DIO.h"
#include "Bit_Op.h"

/************************************
 * LOCAL DATA
 ************************************/

/************************************
 * LOCAL FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
void DIO_WriteChannel(DIO_ChannelType Channelid, DIO_LevelType Level)
{
    uint32 bitPos;
    uint32 regOffset;
    
    bitPos = Channelid%8u;
    
    /* This should be replaced with an array access (or a hash function) to reduce access time*/
    regOffset = (Channelid/8u)*(GPIO_B_AHB_BASE-GPIO_A_AHB_BASE) + 0x3FCu + GPIO_A_AHB_BASE - BITBAND_PRPH_BASE; /* The 0x3FCu is essential to allow writing to the GPIO regsiter (check datasheet) */
    
    if(Level == HIGH)
    {
        /*Bit Banding*/
        ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE) = 1;
    }
    else
    {
        /*Bit Banding*/
        ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE) = 0;
    }
}

DIO_LevelType DIO_ReadChannel(DIO_ChannelType Channelid)
{
    DIO_LevelType value;
    
    uint32 bitPos;
    uint32 regAdr;
    
    bitPos = Channelid%8u;
    
    regOffset = (Channelid/8u)*(GPIO_B_APB_BASE-GPIO_A_APB_BASE) + 0x3FCu + GPIO_A_APB_BASE - BITBAND_PRPH_BASE; /* The 0x3FCu is essential to allow writing to the GPIO regsiter (check datasheet) */
    value = ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE);

    return value;

DIO_PortLevelType DIO_ReadPort(DIO_PortType Portid)
{
    DIO_PortLevelType value;
    
    switch(Portid)
    {
        default:
            value = (DIO_PortLevelType)GPIODATA_AHB_A;
            break;
        case PORT_B:
            value = (DIO_PortLevelType)GPIODATA_AHB_B;
            break;
        case PORT_C:
            value = (DIO_PortLevelType)GPIODATA_AHB_C;
            break;
        #warning "Add remaining ports"
    }
    return value;
}

void DIO_WritePort(DIO_PortType Portid, DIO_PortLevelType Level)
{
    switch(Portid)
    {
        default:
            GPIODATA_AHB_A = Level;
            break;
        case PORT_B:
            GPIODATA_AHB_B = Level;
            break;
        case PORT_C:
            GPIODATA_AHB_C = Level;
            break;
        case PORT_F:
            GPIODATA_AHB_F = Level;
            break;
        #warning "Add remaining ports"
    }
}

DIO_LevelType DIO_FlipChannel(DIO_ChannelType Channelid)
{
    DIO_LevelType oldLevel = DIO_ReadChannel(Channelid);
    DIO_WriteChannel(Channelid, (1u-oldLevel));
    return oldLevel;
}
