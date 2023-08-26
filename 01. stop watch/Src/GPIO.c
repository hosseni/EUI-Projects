#include "Inc/MCAL/GPIO/GPIO_private.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"
#include "Inc/MCAL/GPIO/GPIO_config.h"
/***************************************************************************************************
 *  Function: DIO_Config
 *  Description:
 *      This function configures the GPIO pins according to the provided configuration array.
 *  Parameters:
 *      portConfig: Pointer to an array of Port_ConfigType containing pin configuration settings.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void DIO_Init(const Port_ConfigType portConfig[])
{
    Port_ConfigType currentConfig;

    uint8 i = 0;

    /* Loop until either the sentinel value is reached to detect the end of array or until maximum number of pins is reached */
    for (i = 0; i < NUM_PINS; i++)
    {
        /* Get the values of the current iteration of the array  */
        currentConfig = portConfig[i];

        /* Exit if this is the PORT_NC pin*/
        if (currentConfig.pin == PIN_NC)
        {
            break;
        }

        if (currentConfig.pin == PIN_F0)
        {
            GPIOLOCK_APB_F = 0x4C4F434Bu;
            GPIOCR_APB_F = 0x01u;
        }
        if (currentConfig.pin == PIN_F4)
        {
            GPIOLOCK_APB_F = 0x4C4F434Bu;
            GPIOCR_APB_F = 0x01u;
        }

        /* Adjust the pin direction */
        switch (((uint8)currentConfig.pin / 8u))
        {
        /* Case Port A */
        case PORT_A:
            if (currentConfig.direction == PIN_OUTPUT)
                SET_BIT(GPIODIR_APB_A, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODIR_APB_A, (currentConfig.pin % 8));
            break;
        /* Case Port B */
        case PORT_B:
            if (currentConfig.direction == PIN_OUTPUT)
                SET_BIT(GPIODIR_APB_B, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODIR_APB_B, (currentConfig.pin % 8));
            break;
        /* Case Port C */
        case PORT_C:
            if (currentConfig.direction == PIN_OUTPUT)
                SET_BIT(GPIODIR_APB_C, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODIR_APB_C, (currentConfig.pin % 8));
            break;
        /* Case Port D */
        case PORT_D:
            if (currentConfig.direction == PIN_OUTPUT)
                SET_BIT(GPIODIR_APB_D, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODIR_APB_D, (currentConfig.pin % 8));
            break;
        case PORT_E:
            if (currentConfig.direction == PIN_OUTPUT)
                SET_BIT(GPIODIR_APB_E, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODIR_APB_E, (currentConfig.pin % 8));
            break;
        case PORT_F:
            if (currentConfig.direction == PIN_OUTPUT)
                SET_BIT(GPIODIR_APB_F, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODIR_APB_F, (currentConfig.pin % 8));
            break;
        }

        /* Adjust the pin function */
        switch (((uint8)currentConfig.pin / 8u))
        {
        /* Case Port A */
        case PORT_A:
            if (currentConfig.type == PIN_AF_DISABLE)
                CLR_BIT(GPIOAFSEL_APB_A, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOAFSEL_APB_A, (currentConfig.pin % 8));

            break;
        /* Case Port B */
        case PORT_B:
            if (currentConfig.type == PIN_AF_DISABLE)
                CLR_BIT(GPIOAFSEL_APB_B, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOAFSEL_APB_B, (currentConfig.pin % 8));
            break;
        /* Case Port C */
        case PORT_C:
            if (currentConfig.type == PIN_AF_DISABLE)
                CLR_BIT(GPIOAFSEL_APB_C, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOAFSEL_APB_C, (currentConfig.pin % 8));
            break;
        case PORT_D:
            if (currentConfig.type == PIN_AF_DISABLE)
                CLR_BIT(GPIOAFSEL_APB_D, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOAFSEL_APB_D, (currentConfig.pin % 8));
            break;
        case PORT_E:
            if (currentConfig.type == PIN_AF_DISABLE)
                CLR_BIT(GPIOAFSEL_APB_E, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOAFSEL_APB_E, (currentConfig.pin % 8));
            break;
        /* Case Port F */
        case PORT_F:
            if (currentConfig.type == PIN_AF_DISABLE)
                CLR_BIT(GPIOAFSEL_APB_F, (currentConfig.pin % 8));
            else
            {
               SET_BIT(GPIOAFSEL_APB_F, (currentConfig.pin % 8));
               GPIO_PORTF_PCTL_F = 0x700;
            }
            break;
        }

        /* Adjust the pin mode */
        switch (((uint8)currentConfig.pin / 8u))
        {
        /* Case Port A */
        case PORT_A:
            if (currentConfig.mode == PIN_DIO)
                SET_BIT(GPIODEN_APB_A, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODEN_APB_A, (currentConfig.pin % 8));
            break;
        /* Case Port B */
        case PORT_B:
            if (currentConfig.mode == PIN_DIO)
                SET_BIT(GPIODEN_APB_B, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODEN_APB_B, (currentConfig.pin % 8));
            break;
        /* Case Port C */
        case PORT_C:
            if (currentConfig.mode == PIN_DIO)
                SET_BIT(GPIODEN_APB_C, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODEN_APB_C, (currentConfig.pin % 8));
            break;
        case PORT_D:
            if (currentConfig.mode == PIN_DIO)
                SET_BIT(GPIODEN_APB_D, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODEN_APB_D, (currentConfig.pin % 8));
            break;
        case PORT_E:
            if (currentConfig.mode == PIN_DIO)
                SET_BIT(GPIODEN_APB_E, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODEN_APB_E, (currentConfig.pin % 8));
            break;

        /* Case Port F */
        case PORT_F:
            if (currentConfig.mode == PIN_DIO)
                SET_BIT(GPIODEN_APB_F, (currentConfig.pin % 8));
            else
                CLR_BIT(GPIODEN_APB_F, (currentConfig.pin % 8));
            break;
        }

        /* Adjust the pin attachement */
        switch (((uint8)currentConfig.pin / 8u))
        {
        /* Case Port A */
        case PORT_A:
            if (currentConfig.internalAttach == PIN_PULLUP)
                SET_BIT(GPIOPUR_APB_A, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOPDR_APB_A, (currentConfig.pin % 8));
            break;
        /* Case Port B */
        case PORT_B:
            if (currentConfig.internalAttach == PIN_PULLUP)
                SET_BIT(GPIOPUR_APB_B, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOPDR_APB_B, (currentConfig.pin % 8));
            break;
        /* Case Port C */
        case PORT_C:
            if (currentConfig.internalAttach == PIN_PULLUP)
                SET_BIT(GPIOPUR_APB_C, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOPDR_APB_C, (currentConfig.pin % 8));
            break;
        /* Case Port D */
        case PORT_D:
            if (currentConfig.internalAttach == PIN_PULLUP)
                SET_BIT(GPIOPUR_APB_D, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOPDR_APB_D, (currentConfig.pin % 8));
            break;
        case PORT_E:
            if (currentConfig.internalAttach == PIN_PULLUP)
                SET_BIT(GPIOPUR_APB_E, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOPDR_APB_E, (currentConfig.pin % 8));
            break;
        case PORT_F:
            if (currentConfig.internalAttach == PIN_PULLUP)
                SET_BIT(GPIOPUR_APB_F, (currentConfig.pin % 8));
            else
                SET_BIT(GPIOPDR_APB_F, (currentConfig.pin % 8));
            break;
        }

        /* Lock the pin if it was originally locked */
        if (currentConfig.pin == PIN_F0)
        {
            GPIOLOCK_APB_F = 0x4C4F434Bu;
            GPIOCR_APB_F = 0x00u;
        }
    }
}
/***************************************************************************************************
 *  Function: DIO_ReadChannel
 *  Description:
 *      This function reads the logical level of a specific GPIO channel.
 *  Parameters:
 *      Channelid: The ID of the GPIO channel to be read.
 *  Return Value:
 *      DIO_LevelType: The logical level of the specified channel.
 ***************************************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_ChannelType Channelid)
{
    DIO_LevelType value;

    uint32 bitPos;
    //uint32 regOffset;

    bitPos = Channelid%8u;

    switch ((Channelid / 8))
    {
    case PORT_A:
        value = GET_BIT(GPIODATA_APB_A, bitPos);
        break;
    case PORT_B:
        value = GET_BIT(GPIODATA_APB_B, bitPos);
        break;
    case PORT_C:
        value = GET_BIT(GPIODATA_APB_C, bitPos);
        break;
    case PORT_D:
        value = GET_BIT(GPIODATA_APB_D, bitPos);
        break;
    case PORT_E:
        value = GET_BIT(GPIODATA_APB_E, bitPos);
        break;
    case PORT_F:
        value = GET_BIT(GPIODATA_APB_F, bitPos);
        break;
    }
    /* This should be replaced with an array access (or a hash function) to reduce access time*/
    //regOffset = (Channelid/8u)*(GPIO_B_APB_BASE-GPIO_A_APB_BASE) + 0x3FCu + GPIO_A_APB_BASE - BITBAND_PRPH_BASE; /* The 0x3FCu is essential to allow writing to the GPIO regsiter (check datasheet) */
    //value = ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE);

    return value;
}
/***************************************************************************************************
 *  Function: DIO_WriteChannel
 *  Description:
 *      This function writes a logical level to a specific GPIO channel.
 *  Parameters:
 *      Channelid: The ID of the GPIO channel to be written.
 *      Level: The logical level to be written (HIGH or LOW).
 *  Return Value:
 *      None
 ***************************************************************************************************/
void DIO_WriteChannel(DIO_ChannelType Channelid, DIO_LevelType Level)
{

       uint32 bitPos;
       //uint32 regOffset;

       bitPos = Channelid%8u;
       switch (Channelid / 8)
           {
           case PORT_A:
               if (HIGH == Level)
                   SET_BIT(GPIODATA_APB_A, bitPos);
               else
                   CLR_BIT(GPIODATA_APB_A, bitPos);
               break;
           case PORT_B:
               if (HIGH == Level)
                   SET_BIT(GPIODATA_APB_B, bitPos);
               else
                   CLR_BIT(GPIODATA_APB_B, bitPos);
               break;
           case PORT_C:
               if (HIGH == Level)
                   SET_BIT(GPIODATA_APB_C, bitPos);
               else
                   CLR_BIT(GPIODATA_APB_C, bitPos);
               break;
           case PORT_D:
               if (HIGH == Level)
                   SET_BIT(GPIODATA_APB_D, bitPos);
               else
                   CLR_BIT(GPIODATA_APB_D, bitPos);
               break;
           case PORT_E:
               if (HIGH == Level)
                   SET_BIT(GPIODATA_APB_E, bitPos);
               else
                   CLR_BIT(GPIODATA_APB_E, bitPos);
               break;
           case PORT_F:
               if (HIGH == Level)
                   SET_BIT(GPIODATA_APB_F, bitPos);
               else
                   CLR_BIT(GPIODATA_APB_F, bitPos);
               break;
           }
       /* This should be replaced with an array access (or a hash function) to reduce access time*/
//       regOffset = (Channelid/8u)*(GPIO_B_APB_BASE-GPIO_A_APB_BASE) + 0x3FCu + GPIO_A_APB_BASE - BITBAND_PRPH_BASE; /* The 0x3FCu is essential to allow writing to the GPIO regsiter (check datasheet) */
//
//       if((Level == HIGH)&&(Channelid/8 != PORT_F))
//       {
//           ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE) = 1;
//       }
//       else if ((Level == LOW)&&(Channelid/8 != PORT_F))
//       {
//           ACCESS_BITBAND_ADR(regOffset, bitPos, BITBAND_PRPH_ALIAS_BASE) = 0;
//       }
}
/***************************************************************************************************
 *  Function: DIO_ReadPort
 *  Description:
 *      This function reads the logical levels of all pins within a specific GPIO port.
 *  Parameters:
 *      Portid: The ID of the GPIO port to be read.
 *  Return Value:
 *      DIO_PortLevelType: The logical levels of all pins within the specified port.
 ***************************************************************************************************/
DIO_PortLevelType DIO_ReadPort(DIO_PortType Portid)
{
    DIO_PortLevelType value;

    switch (Portid)
    {
    case PORT_A:
        value = (DIO_PortLevelType)GPIODATA_APB_A;
        break;
    case PORT_B:
        value = (DIO_PortLevelType)GPIODATA_APB_B;
        break;
    case PORT_C:
        value = (DIO_PortLevelType)GPIODATA_APB_C;
        break;
    case PORT_D:
        value = (DIO_PortLevelType)GPIODATA_APB_D;
        break;
    case PORT_E:
        value = (DIO_PortLevelType)GPIODATA_APB_E;
        break;
    case PORT_F:
        value = (DIO_PortLevelType)GPIODATA_APB_F;
        break;
    }
    return value;
}
/***************************************************************************************************
 *  Function: DIO_WritePort
 *  Description:
 *      This function writes logical levels to all pins within a specific GPIO port.
 *  Parameters:
 *      Portid: The ID of the GPIO port to be written.
 *      Level: The logical levels to be written to all pins within the specified port.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void DIO_WritePort(DIO_PortType Portid, DIO_PortLevelType Level)
{
    switch (Portid)
    {
    default:
        GPIODATA_APB_A = Level;
        break;
    case PORT_B:
        GPIODATA_APB_B = Level;
        break;
    case PORT_C:
        GPIODATA_APB_C = Level;
        break;
    case PORT_F:
        GPIODATA_APB_F = Level;
        break;
    }
}
/***************************************************************************************************
 *  Function: DIO_FlipChannel
 *  Description:
 *      This function toggles the logical level of a specific GPIO channel and returns its previous
 *      logical level.
 *  Parameters:
 *      Channelid: The ID of the GPIO channel to be toggled.
 *  Return Value:
 *      DIO_LevelType: The previous logical level of the specified channel.
 ***************************************************************************************************/
DIO_LevelType DIO_FlipChannel(DIO_ChannelType Channelid)
{
    DIO_LevelType oldLevel = DIO_ReadChannel(Channelid);
    DIO_WriteChannel(Channelid, (1u - oldLevel));
    return oldLevel;
}
