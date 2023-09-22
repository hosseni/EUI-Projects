#include <stdint.h>
#include <stdbool.h>
#include "MCAL/DIO/DIO.h"
#include "MCAL/CAN/CAN.h"
//#include "FreeRTOS.h"
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
//#include "FreeRTOS.h"
//#include "task.h"

// Function prototypes
//void Task1(void *pvParameters);
//void Task2(void *pvParameters);
//
//int main(void) {
//    // Set the clock to 80 MHz
//    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
//
//    // Initialize GPIO for LED
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
//
//    // Create tasks
//    xTaskCreate(Task1, "Task1", 128, NULL, 1, NULL);
//    xTaskCreate(Task2, "Task2", 128, NULL, 1, NULL);
//
//    // Start the FreeRTOS scheduler
//    vTaskStartScheduler();
//
//    while (1) {
//        // Should never get here
//    }
//}
//
//void Task1(void *pvParameters) {
//    while (1) {
//        // Toggle LED
//        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
//        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
//        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
//        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
//    }
//}
//
//void Task2(void *pvParameters) {
//    while (1) {
//        // Your code for Task2 here
//        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay for 0.5 seconds
//    }
//}


#define TRIGGER_MESSAGE 0x3C8F
#define ACKNOWLEDGE_MESSAGE 0x3C50

int main(void)
{
    DIO_Init(PORTF, PIN1, OUT);
    DIO_Init(PORTF, PIN2, OUT);
    DIO_Init(PORTF, PIN3, OUT);
    DIO_WritePin(PORTF, PIN3, 0);

    /* CAN message objects */
    tCANMsgObject can0RxStartFlashing;
    tCANMsgObject can0RxCodeFlashing;
    tCANMsgObject can0TxAcknowledge;

    CAN0_init();
    CAN0_adjustReceiveMessage(&can0RxStartFlashing, START_FLASHING_MSG_OBJ, START_FLASHING_MSG_OBJ, START_FLASHING_MSG_OBJ, 2);
    CAN0_adjustReceiveMessage(&can0RxCodeFlashing, CODE_MSG_OBJ, CODE_MSG_OBJ, CODE_MSG_OBJ, 8);
    CAN0_adjustSendMessage(&can0TxAcknowledge, ACKNOWLEDGE_MSG_OBJ, 2);

    uint8_t data[64];

    uint32_t cnt;
    while (1)
    {
        if (CAN0_receiveStatus(START_FLASHING_RECEIVED))
        {
            DIO_WritePin(PORTF, PIN3, 0);
            DIO_WritePin(PORTF, PIN1, 1);
            CAN0_receiveMessage(&can0RxStartFlashing, data, START_FLASHING_MSG_OBJ);
            uint16_t receivedMsg = (data[0] | (data[1] << 8));
            if (TRIGGER_MESSAGE == receivedMsg)
            {
                data[0] = ACKNOWLEDGE_MESSAGE & 0xFF;
                data[1] = (ACKNOWLEDGE_MESSAGE & 0xFF00) >> 8;
                CAN0_sendMessage(&can0TxAcknowledge, ACKNOWLEDGE_MSG_OBJ, data, 2);
            }
            CAN0_resetStatus(START_FLASHING_RECEIVED);
            for (cnt = 0; cnt < 2000000; cnt++)
            {
            }
            DIO_WritePin(PORTF, PIN1, 0);
        }
        else if (CAN0_receiveStatus(CODE_RECEIVED))
        {
            DIO_WritePin(PORTF, PIN3, 0);
            DIO_WritePin(PORTF, PIN2, 1);
            CAN0_receiveMessage(&can0RxCodeFlashing, data, CODE_MSG_OBJ);
            CAN0_resetStatus(CODE_RECEIVED);
            for (cnt = 0; cnt < 2000000; cnt++)
            {
            }
            DIO_WritePin(PORTF, PIN2, 0);
        }
        DIO_WritePin(PORTF, PIN3, 1);
    }
}

/***********************************************************************************************************************/

// #include <stdint.h>
// #include <stdbool.h>
// #include "MCAL/DIO/DIO.h"
// #include "MCAL/CAN/CAN.h"
//
//
// #define TRIGGER_MESSAGE 0x3C8F
// #define ACKNOWLEDGE_MESSAGE 0x3C50
//
// int main(void) {
//     DIO_Init(PORTF, PIN1, OUT);
//     DIO_Init(PORTF, PIN2, OUT);
//
//
//     /* CAN message objects */
//     tCANMsgObject can0TxStartFlashing;
//     tCANMsgObject can0TxCodeFlashing;
//     tCANMsgObject can0RxAcknowledge;
//
//     CAN0_init();
//     CAN0_adjustSendMessage(&can0TxStartFlashing, START_FLASHING_MSG_OBJ, 2);
//     CAN0_adjustSendMessage(&can0TxCodeFlashing, CODE_MSG_OBJ, 8);
//     CAN0_adjustReceiveMessage(&can0RxAcknowledge, ACKNOWLEDGE_MSG_OBJ, ACKNOWLEDGE_MSG_OBJ, ACKNOWLEDGE_MSG_OBJ, 2);
//
//     uint8_t data[64];
//
//     while (1) {
//         uint32_t cnt = 0;
//         /* sending start flash obj */
//         data[0] = TRIGGER_MESSAGE & 0xFF;
//         //
//         data[1] = (TRIGGER_MESSAGE & 0xFF00) >> 8;
//         DIO_WritePin(PORTF, PIN1, 1);
//         CAN0_sendMesage(&can0TxStartFlashing, START_FLASHING_MSG_OBJ, data, 2);
//         for(cnt = 0; cnt < 5000000; cnt++){}
//         DIO_WritePin(PORTF, PIN1, 0);
//         for(cnt = 0; cnt < 5000000; cnt++){}
//         if(CAN0_receiveStatus(ACKNOWLEDGE_RECEIVED))
//         {
//             CAN0_resetStatus(ACKNOWLEDGE_RECEIVED);
//             CAN0_receiveMessage(&can0RxAcknowledge, data, ACKNOWLEDGE_MSG_OBJ);
//             uint16_t receivedMsg = (data[0] | (data[1] << 8));
//             if(ACKNOWLEDGE_MESSAGE == receivedMsg){
//                 /* sending code object */
//                 data[0] = '1';
//                 data[1] = '2';
//                 data[2] = '3';
//                 data[3] = '4';
//                 data[4] = '5';
//                 data[5] = '6';
//                 data[6] = '7';
//                 data[7] = '8';
//                 data[8] = 'S';
//                 data[9] = 'T';
//                 data[10] = 'U';
//                 data[11] = 'V';
//                 data[12] = 'W';
//                 data[13] = 'X';
//                 data[14] = 'Y';
//                 data[15] = 'Z';
//                 data[16] = 'P';
//                 data[17] = 'O';
//                 DIO_WritePin(PORTF, PIN2, 1);
//                 CAN0_sendMessage(&can0TxCodeFlashing, CODE_MSG_OBJ, data, 8);
//                 for(cnt = 0; cnt < 5000000; cnt++){}
//                 DIO_WritePin(PORTF, PIN2, 0);
//                 for(cnt = 0; cnt < 5000000; cnt++){}
//                 DIO_WritePin(PORTF, PIN2, 1);
//                 CAN0_sendMessage(&can0TxCodeFlashing, CODE_MSG_OBJ, data+8, 8);
//                 for(cnt = 0; cnt < 5000000; cnt++){}
//                 DIO_WritePin(PORTF, PIN2, 0);
//                 for(cnt = 0; cnt < 5000000; cnt++){}
//             }
//         }
//     }
// }
//
//
