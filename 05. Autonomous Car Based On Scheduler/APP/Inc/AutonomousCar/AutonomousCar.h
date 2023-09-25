

#ifndef INC_APP_AUTONOMOUSCAR_AUTONOMOUSCAR_H_
#define INC_APP_AUTONOMOUSCAR_AUTONOMOUSCAR_H_

#include "../../../MCAL/Inc/SCB/SCB_interface.h"
#include "../../../MCAL/Inc/GPIO/GPIO_interface.h"
#include "../../../MCAL/Inc/SysTick/SYSTICK_interface.h"
#include "../../../MCAL/Inc/GPT/GPT_interface.h"
#include "../../../MCAL/Inc/ADC/adc.h"
#include "../../../SERVICES/Inc/SCHEDULAR/Schedular_interface.h"


#include "../../HAL/Inc/ULTRASONIC/ultrasonic.h"
#include "../../HAL/Inc/LCD/lcd.h"
#include "../../HAL/Inc/MOTOR/motor.h"
#include "../../HAL/Inc/SWITCH/switch.h"

#include "AutonomousCar.h"

#include "LIB/DELAY.h"

#include "../../../FreeRTOS/include/FreeRTOS.h"
#include "../../../FreeRTOS/include/task.h"

void robotInit(void);

void robotMoveForward(void);

void robotMoveStop(void);

void robotMoveRotate(void);

void robotMoveLeft(void);

void robotMoveRight(void);

void robotMoveback (void);


void autonomous_car_init(void);
void start_stop_condition (void *pvParameters);
void ldr_swing_car(void *pvParameters);
void lcd_display(void *pvParameters);
void avoid_obstacles(void *pvParameters);
void get_temp (void *pvParameters);






#endif /* INC_APP_AUTONOMOUSCAR_AUTONOMOUSCAR_H_ */
