/******************************
 * LAB2.c
 *
 *      Author: Hosseni
 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "utils/uartstdio.c"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Define the struct for sensor data
typedef struct
{
    int sensorID;
    int sensorValue;

} SensorData;

// Queue handle
QueueHandle_t xQueue;

#define UART0_BASE 0x4000C000 // UART0 base address

void UART0_Init(void)
{
    // Enable the UART0 module and GPIO Port A
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Configure the UART pins (PA0 = U0Rx, PA1 = U0Tx)
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Initialize the UART for 115200 baud rate, 8-N-1
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                UART_CONFIG_PAR_NONE));

    // Enable the UART0 module
    UARTEnable(UART0_BASE);

    // Initialize the UARTStdio library
    UARTStdioConfig(0, 115200, SysCtlClockGet());
}
// Sender task 1
void SenderTask1(void *pvParameters)
{
    SensorData data;
    data.sensorID = 1;

    while (1)
    {
        data.sensorValue = rand() % 100; // Generate random sensor value

        // Send data to the queue
        if (xQueueSend(xQueue, &data, portMAX_DELAY) == pdPASS)
        {
            UARTprintf(ANSI_COLOR_RED"SenderTask1 sent: SensorID %d, Value %d\n", data.sensorID, data.sensorValue);
        }
    }
}

// Sender task 2
void SenderTask2(void *pvParameters)
{
    SensorData data;
    data.sensorID = 2;

    while (1)
    {
        data.sensorValue = rand() % 100; // Generate random sensor value

        // Send data to the queue
        if (xQueueSend(xQueue, &data, portMAX_DELAY) == pdPASS)
        {
            UARTprintf(ANSI_COLOR_GREEN"SenderTask2 sent: SensorID %d, Value %d\n", data.sensorID, data.sensorValue);
        }

    }
}

// Receiver task
void ReceiverTask(void *pvParameters)
{
    SensorData receivedData;

    while (1)
    {
        // Receive data from the queue
        if (xQueueReceive(xQueue, &receivedData, portMAX_DELAY) == pdPASS)
        {
            UARTprintf(ANSI_COLOR_RESET"ReceiverTask received: SensorID %d, Value %d\n", receivedData.sensorID, receivedData.sensorValue);
        }
    }
}


void LAB1 (void)
{
    UART0_Init();
    // Initialize FreeRTOS
    xQueue = xQueueCreate(4, sizeof(SensorData)); // Create a queue with a capacity of 4 structs

    if (xQueue == NULL)
    {
        UARTprintf("Queue creation failed\n");
    }
    else
    {
        UARTprintf("Queue creation success\n");
    }

    xTaskCreate(SenderTask1, "SenderTask1", configMINIMAL_STACK_SIZE, NULL,  2, NULL);
    xTaskCreate(SenderTask2, "SenderTask2", configMINIMAL_STACK_SIZE, NULL,  2, NULL);
    xTaskCreate(ReceiverTask, "ReceiverTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();

    // The scheduler should never return, but if it does, there was an error
    while (1)
    {
        UARTprintf("Scheduler returned unexpectedly\n");
    }
}
