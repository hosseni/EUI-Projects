#include "Inc/MCAL/SCB/SCB_interface.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"
#include "Inc/MCAL/SysTick/SYSTICK_interface.h"
#include "Inc/MCAL/GPT/GPT_interface.h"
#include "Inc/APP/StopWatch/stopWatch.h"
#include "Inc/LIB/DELAY.h"
#include <stdlib.h>

extern const SCB_ConfigType SCBConfig[SCB_CLOCK_SETTINGS_SIZE];
extern const Port_ConfigType portConfig[NUM_PINS];

void main(void)
{
    /* Initialize the System Control Block (SCB) */
    SCB_Init(SCBConfig);

    /* Initialize and configure the system clock */
    SCB_InitClock(CLOCK_0);

    /* Initialize and configure GPIO pins */
    DIO_Init(portConfig);

    /* Initialize the stopwatch application */
    stopWatch_init();

    while (1)
    {
        /* Continuously handle the stopwatch functionality */
        stopWatch_HandleMain();
    }
}
