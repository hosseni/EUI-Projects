/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SCB.c
 *        \brief  Microcontroller Unit Driver
 *
 *      \details The SCB driver provides services for basic microcontroller initialization,
 *               Clock Control and reset
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CONFIG/Inc/SYSTICK_config.h"
#include "MCAL/Inc/SysTick/SYSTICK_interface.h"
#include "MCAL/Inc/SysTick/SYSTICK_private.h"

#include "LIB/BIT_MATH.h"
#include "COMMON/TM4C123GH6PM.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

#define SYSTICK_SINGLE_INTERVAL   0
#define SYSTICK_PERIOD_INTERVAL   1


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern uint8 start_move_flag;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax          : void SYSTICK_Init ( const SCB_ConfigType* SYSTIC_Config )
 * \Description     : This service initializes the systick driver.
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : SYSTIC_Config       Pointer to systick driver configuration set.
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
static void (* SysTick_CallBack) (void) = NULL;
 uint8 SYSTICK_u8ModeOfInterval;
extern uint16 counter_time_out;
extern  const SYSTIC_ConfigType SYSTIC_Config [1];

void SYSTICK_Init ( )
{
    //init mode of operation
    if(SYSTIC_Config->op_mode == Systick_Enable)
    {
        SET_BIT(SYSTICK->STCTRL, 0);
    }
    else if (SYSTIC_Config->op_mode == Systick_Disable)
    {
        CLR_BIT(SYSTICK->STCTRL, 0);
    }
    //init clock source
    if (SYSTIC_Config->sys_clock == Sys_Clock)
    {
        SET_BIT(SYSTICK->STCTRL, 2);
    }
    else if (SYSTIC_Config->sys_clock == Sys_Clock_div_4)
    {
        CLR_BIT(SYSTICK->STCTRL, 2);
    }
    //init enable or disable interrupt
    if(SYSTIC_Config->intterrupt_state == Interrupt_Enable)
    {
        SET_BIT(SYSTICK->STCTRL, 1);
    }
    else if (SYSTIC_Config->intterrupt_state == Interrupt_Diable)
    {
        CLR_BIT(SYSTICK->STCTRL, 1);
    }
}


/******************************************************************************
 * \Syntax          : void SYSTICK_setBusyWait(uint32 delay_ms)
 * \Description     : This function creates a busy wait delay of the specified milliseconds using the SysTick timer.
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non-Reentrant
 * \Parameters (in) : delay_ms - The delay time in milliseconds.
 * \Parameters (out): None
 * \Return value    : None
 *******************************************************************************/
void SYSTICK_setBusyWait (uint32 delay_ms)
{
    //set count value
    if (SYSTIC_Config->sys_clock == Sys_Clock)
     {
        SYSTICK->STRELOAD = delay_ms*16000;
     }
     else if (SYSTIC_Config->sys_clock == Sys_Clock_div_4)
     {
         SYSTICK->STRELOAD = delay_ms*4000;
     }
        //start counter
        SET_BIT(SYSTICK->STCTRL, 0);
        while (GET_BIT(SYSTICK->STCTRL, 16) == 0);

        CLR_BIT( SYSTICK-> STCTRL , 0);
        SYSTICK ->STRELOAD = 0;
        SYSTICK -> STCURRENT  = 0;


}
/******************************************************************************
 * \Syntax          : void SYSTIC_voidSetIntervalPeriodic(uint32 delay_ms, void (* Copy_PF)(void))
 * \Description     : This function sets up a periodic timer interval using the SysTick timer.
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non-Reentrant
 * \Parameters (in) : delay_ms - The interval duration in milliseconds.
 *                    Copy_PF - Pointer to the function to be called periodically.
 * \Parameters (out): None
 * \Return value    : None
 *******************************************************************************/
void SYSTIC_voidSetIntervalPeriodic (uint32 delay_ms, void (* Copy_PF)(void))
{
    /*disable timer */
        CLR_BIT( SYSTICK -> STCTRL , 0);
        SYSTICK ->STCURRENT  = 0;

        /*load ticks to load register*/

        if (SYSTIC_Config->sys_clock == Sys_Clock)
        {
            SYSTICK->STRELOAD = delay_ms*16000;
        }
        else if (SYSTIC_Config->sys_clock == Sys_Clock_div_4)
        {
            SYSTICK->STRELOAD = delay_ms*4000;
        }
        /*start timer                */
        SET_BIT(SYSTICK -> STCTRL, 0);

        /*save call back*/
        SysTick_CallBack = Copy_PF;

        /*Enable interrupt*/
        SET_BIT(SYSTICK -> STCTRL, 1);

        /*set mode single interval*/
        SYSTICK_u8ModeOfInterval = SYSTICK_PERIOD_INTERVAL;

}
/******************************************************************************
 * \Syntax          : void SYSTICK_Handler(void)
 * \Description     : This is the SysTick interrupt handler function.
 *                    It is called when a periodic timer interval elapses.
 * \Sync\Async      : Asynchronous (interrupt-driven)
 * \Reentrancy      : Non-Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value    : None
 *******************************************************************************/
uint8 time_in_sec;
void SYSTICK_Handler (void)
{
    if((counter_time_out <= 1200) && (start_move_flag == 1))
    {
        if ((counter_time_out % 20) == 0)
            time_in_sec++;
            counter_time_out++;
    }
    else
    {
        counter_time_out = 0;
        start_move_flag = 0;
    }
    if (SYSTICK_u8ModeOfInterval == SYSTICK_SINGLE_INTERVAL)
        {
        /*disable timer */
        CLR_BIT( SYSTICK ->STCTRL , 0);
        SYSTICK ->STCURRENT  = 0;
        /*stop timer */
        CLR_BIT( SYSTICK -> STCTRL , 0);
        SYSTICK ->STRELOAD = 0;
        SYSTICK -> STCURRENT  = 0;
        }

        SysTick_CallBack();

}
