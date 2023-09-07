/*
 * main.h
 *
 *  Created on: Aug 31, 2023
 */

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../../HAL/LDR_SENSOR/ldr_sensor.h"
#include "../../HAL/MOTOR/motor.h"
#include "../../HAL/ULTRASONIC_SENSOR/ultrasonic_sensor.h"
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#include "driverlib/timer.h"
#include "driverlib/systick.h"
#include "HAL/ULTRASONIC_SENSOR/ultrasonic_sensor.h"
#include "HAL/LDR_SENSOR/ldr_sensor.h"
#include "HAL/MOTOR/motor.h"
#include "HAL/LCD/lcd.h"
#include "HAL/MOTOR/motor.h"


void autonomousCarInit ();
void autonomousCarRun();



#endif /* APPLICATION_APP_H_ */
