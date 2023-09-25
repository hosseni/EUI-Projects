/******************************************************************************
 *  File: AutonomousCar.c
 *  Description:
 *      This file contains the implementation of an autonomous car control system.
 *      It includes the initialization of hardware components, such as sensors,
 *      buttons, and actuators, as well as the logic for controlling the car's
 *      movement and displaying information on an LCD screen. The car's behavior
 *      is based on sensor readings and user inputs from start and stop buttons.
 *
 *  Author: Hosseni Gamal
 *  Date: 12/9/2023
 *****************************************************************************/
#include "Inc/AutonomousCar/AutonomousCar.h"

/* Define the ultrasonic sensor and LCD display */
ultraSonic_t ultraSonic1 = {PIN_B2, PIN_B3};
lcd_t lcd_car = {PIN_E2, PIN_E3, {PIN_A3, PIN_A4, PIN_A5, PIN_A6}, _4_BIT};

/* Define start and stop buttons */
button_t start_button = {PIN_F0, PULL_UP, RELEASED};
button_t stop_button = {PIN_F4, PULL_UP, RELEASED};

/* Define ADC configurations for LDR sensors */
adc_config_t LDR_1 = {.ADCn = 0, .ADC_Channel = ADC_CTL_CH4, .ADC_TRIGGER = 1, .sequencer = ADC_sequencer_3};
adc_config_t LDR_2 = {.ADCn = 0, .ADC_Channel = ADC_CTL_CH5, .ADC_TRIGGER = 1, .sequencer = ADC_sequencer_3};

/* Static variables for sensor readings and control flags */
static uint32 LDR_L_read;
static uint32 LDR_R_read;
static uint32 distance;
static sint32 LDR_Direction;
static uint8 move_flag;
static uint32 temp_read;


uint8 start_move_flag;
uint16 counter_time_out ;

/***************************************************************************************************
 *  Function: start_stop_condition
 *  Description:
 *      This function checks the state of the start and stop buttons and updates the
 *      `start_move_flag` accordingly. If the start button is pressed, `start_move_flag` is set to 1,
 *      indicating the car should start moving. If the stop button is pressed, `start_move_flag` is
 *      set to 0, indicating the car should stop moving.
 *  Parameters:
 *      None
 *  Return Value:
 *      None
 ***************************************************************************************************/
void start_stop_condition (void *pvParameters)
{
    const TickType_t delayPeriod = pdMS_TO_TICKS(1000); // Delay of 1000 ms (1 second)
    TickType_t lastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        // Check button state and update flags
        if (PRESSED == button_get_state(&start_button))
        {
            start_move_flag = 1;
        } else if (PRESSED == button_get_state(&stop_button))
        {
            start_move_flag = 0;
            counter_time_out = 0;
        }
        vTaskDelayUntil(&lastWakeTime, delayPeriod);
    }
}
/***************************************************************************************************
 *  Function: ldr_swing_car
 *  Description:
 *      This function reads the values from two LDR sensors, calculates the direction difference
 *      between them, and controls the car's movement based on the `move_flag`. If `move_flag` is 0,
 *      the car is stopped. If `move_flag` is 1 and the direction difference is greater than 400,
 *      the car turns right. If `move_flag` is 1 and the direction difference is less than 0, the car
 *      turns left. Otherwise, it moves forward. If `move_flag` is 2, the car alternates between
 *      moving back and rotating.
 *  Parameters:
 *      None
 *  Return Value:
 *      None
 ***************************************************************************************************/
void ldr_swing_car(void *pvParameters) {
    const TickType_t delayPeriod = pdMS_TO_TICKS(150); // Delay of 150 ms
    TickType_t lastWakeTime = xTaskGetTickCount();

    for (;;) {
        uint32_t counter = 0;
        LDR_L_read = ADC_Read_Data(&LDR_2);
        LDR_R_read = ADC_Read_Data(&LDR_1);
        LDR_Direction = LDR_R_read - LDR_L_read;

        if (move_flag == 0) {
            robotMoveStop();
        } else if (move_flag == 1) {
            if (LDR_Direction > 950) {
                robotMoveRight();
            } else if (LDR_Direction < 500) {
                robotMoveLeft();
            } else {
                robotMoveForward();
            }
        } else if (move_flag == 2) {
            while (counter < 50000) {
                counter++;
                robotMoveback();
            }
            counter = 0;
            while (counter < 50000) {
                counter++;
                robotMoveRotate();
            }
        }

        // Calculate the next wake time based on the current time and delay period
        vTaskDelayUntil(&lastWakeTime, delayPeriod);
    }
}


void get_temp (void *pvParameters)
{
   for (;;)
   {
       temp_read = ADC_Read_internal_temp();
          temp_read = (long)(147.5 - ((3.3 * 75.0 * (double)temp_read) / 4096.0));
   }
}
/***************************************************************************************************
 *  Function: lcd_display
 *  Description:
 *      This function displays information on an LCD screen.
 *  Parameters:
 *      None
 *  Return Value:
 *      None
 ***************************************************************************************************/
extern uint8 time_in_sec;

void lcd_display(void *pvParameters)
{
 for (;;)
 {
     if ((start_move_flag == 1))
      {
          lcd_send_string_pos(&lcd_car , "D:", ROW0, COL0);
          lcd_send_number_pos(&lcd_car , distance, ROW0, COL2);
          lcd_send_string_pos(&lcd_car , "T:", ROW1, COL0);
          lcd_send_number_pos(&lcd_car , temp_read, ROW1, COL4);
          lcd_send_string_pos(&lcd_car, "Time Out:",ROW0, COL5);
          lcd_send_number_pos(&lcd_car , time_in_sec, ROW0, COL14);
      }
 }

}
/***************************************************************************************************
 *  Function: avoid_obstacles
 *  Description:
 *      This function reads the distance from an ultrasonic sensor and updates the `move_flag`
 *      based on the value of `start_move_flag` and the distance reading. If `start_move_flag` is 0,
 *      `move_flag` is set to 0, indicating the car should stop. If `start_move_flag` is 1 and the
 *      distance is greater than 15, `move_flag` is set to 1, indicating the car should move forward.
 *      If the distance is less than 15, `move_flag` is set to 2, indicating the car should take
 *      evasive action.
 *  Parameters:
 *      None
 *  Return Value:
 *      None
 ***************************************************************************************************/
void avoid_obstacles(void *pvParameters)
{
    const TickType_t delayPeriod = pdMS_TO_TICKS(150); // Delay of 150 ms
       TickType_t lastWakeTime = xTaskGetTickCount();

   for (;;)
   {
       distance =  ultarsonicSensorReadValue(&ultraSonic1);
          if (start_move_flag == 0)
          {
              move_flag = 0;
          }
          else if ((start_move_flag == 1)&&(distance > 10))
          {
              move_flag = 1;
          }
          else if (distance < 10)
          {
              move_flag = 2;
          }
          // Calculate the next wake time based on the current time and delay period
              vTaskDelayUntil(&lastWakeTime, delayPeriod);

   }
}
/***************************************************************************************************
 *  Function: autonomous_car_init
 *  Description:
 *      This function initializes the autonomous car's hardware components and peripherals. It
 *      configures the system, clocks, GPIO pins, timers, ADCs, LCD, and the robot. It prepares
 *      the car for autonomous operation.
 *  Parameters:
 *      None
 *  Return Value:
 *      None
 ***************************************************************************************************/
void autonomous_car_init(void)
{
    /* Initialize System */
    SCB_Init();

    SCB_InitClock(CLOCK_0);

    DIO_Init();

    SYSTICK_Init ();

    GPT_Init();

    ADC_Init(&LDR_2);

    ADC_Init(&LDR_1);

    lcd_init(&lcd_car);

    robotInit();

}
