/*
 * ultrasonic_sensor.h
 *
 *  Created on: Aug 31, 2023
 *      Author: Hosseni Gamal
 */

#ifndef HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_
#define HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"


typedef struct
{
    uint32_t ultrasonicPort;
    uint8_t ultrasonicEchoPin;
    uint8_t ultrasonicTriggerPin;
}ultraSonic_t;

/*This function is used to initialize the ultrasonic sensor
 * @param sensor [port , echo pin , trigger pin]
 * @return
 * */
void ultarsonicSensorInit(ultraSonic_t *sensor);

/*This function is used to get the ultrasonic sensor reading value
 * @param sensor [port , echo pin , trigger pin]
 * @return distance in cm
 * */
uint16_t ultarsonicSensorReadValue(ultraSonic_t *sensor);

#endif /* HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_ */
