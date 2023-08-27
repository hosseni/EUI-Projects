#include "Inc/MCAL/SCB/SCB_interface.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"
#include "Inc/MCAL/SysTick/SYSTICK_interface.h"
#include "Inc/MCAL/GPT/GPT_interface.h"
#include "Inc/APP/StopWatch/stopWatch.h"
#include "Inc/LIB/DELAY.h"
#include <stdlib.h>

extern const SCB_ConfigType SCBConfig[SCB_CLOCK_SETTINGS_SIZE];
extern const Port_ConfigType portConfig[NUM_PINS];
extern const GPT_ConfigType gptConfig[NUM_TIMER];

void App0 (void)
{
    DIO_WriteChannel(PIN_F1, HIGH);
    DIO_WriteChannel(PIN_F2, LOW);
    DIO_WriteChannel(PIN_F3, LOW);
}
void App1 (void)
{
    DIO_WriteChannel(PIN_F1, LOW);
    DIO_WriteChannel(PIN_F2, HIGH);
    DIO_WriteChannel(PIN_F3, LOW);
}




// Main function
void main(void)
{
    /* Initialize System */
    SCB_Init(SCBConfig);
    SCB_InitClock(CLOCK_0);
    DIO_Init(portConfig);
    GPT_Init(gptConfig);

    /* Enable NVIC (Nested Vectored Interrupt Controller) for Timer Interrupts */
    *((volatile uint32 *)0xE000E100) |= (1 << (19)); // NVIC_EN0_Timer0
    *((volatile uint32 *)0xE000E100) |= (1 << (21)); // NVIC_EN0_Timer1

    /* Set Callback Functions for Timer Interrupts */
    GPT_EnableNotification(GPT_CHNL_TIMER0, App0);
    GPT_EnableNotification(GPT_CHNL_TIMER1, App1);

    /* Start Timers */
    GPT_StartTimer(GPT_CHNL_TIMER0, (0.500 * (16000000 - 1))); // 1400 ms
    GPT_StartTimer(GPT_CHNL_TIMER1, (2 * (16000000 - 1))); // 1000 ms


    /* Infinite Loop */
    while (1)
    {
        // Application runs based on timer interrupts
    }
}
