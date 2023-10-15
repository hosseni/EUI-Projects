#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"


volatile uint32_t systick_counter = 0;

void SysTickInit(void)
{
    SysTickPeriodSet(SysCtlClockGet() / 10); // 100 ms interval
    SysTickEnable();
    SysTickIntEnable();
}

void SysTick_Handler(void) // top of stack pointer -> 0x200001D0
{
     systick_counter++;
}

void InitGPIO(void) {
    // Enable the GPIO Port F
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Wait for the GPIO module to be ready
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    // Configure Pin 1 (RED LED) and Pin 2 (BLUE LED) as outputs
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2);
}

// Function to toggle the red LED every 500 ms
void ToggleRedLED(void)   // its address -> 0x530
{

    // Infinite loop to toggle the red LED
    while (1)
    {
        // Toggle the red LED (Pin 1)
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);

        // Delay for 500 ms (assuming 16 MHz clock)
        SysCtlDelay(SysCtlClockGet() / 2); // 500 ms delay

        // Toggle off the red LED
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);

        // Delay for 500 ms
        SysCtlDelay(SysCtlClockGet() / 2); // 500 ms delay
    }
}

// Function to toggle the blue LED every 1000 ms
void ToggleBlueLED(void)  // its address -> 0x
{

    // Infinite loop to toggle the blue LED
    while (1)
    {
        // Toggle the blue LED (Pin 2)
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);

        // Delay for 1000 ms (assuming 16 MHz clock)
        SysCtlDelay(SysCtlClockGet()); // 1000 ms delay

        // Toggle off the blue LED
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);

        // Delay for 1000 ms
        SysCtlDelay(SysCtlClockGet()); // 1000 ms delay
    }
}

int main(void) {

    InitGPIO();
    SysTickInit ();

    ToggleRedLED();
    ToggleBlueLED();

    return 0;
}
