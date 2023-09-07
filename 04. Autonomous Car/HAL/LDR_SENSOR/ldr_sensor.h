/*
 * ldr_sensor.h
 *
 *  Created on: Aug 31, 2023
 *      Author: Mohamed Abosreea
 */

#ifndef HAL_LDR_SENSOR_LDR_SENSOR_H_
#define HAL_LDR_SENSOR_LDR_SENSOR_H_
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"


typedef struct {
    uint32_t ldrPort;
    uint8_t  ldrPin;
    uint32_t sequencer;
    uint32_t adcChannel;
}ldrSensor_t;

/*This function is used to initialize the ultrasonic sensor
 * @param sensor [port , pin , analog channel]
 * @return
 * */
void ldrSensorInit(ldrSensor_t *sensor);

/*This function is used to initialize the ultrasonic sensor
 * @param sensor [port , pin , analog channel]
 * @return [ 0 - 4095]
 * */

uint32_t ldrSensorReading(ldrSensor_t *sensor);
#endif /* HAL_LDR_SENSOR_LDR_SENSOR_H_ */
