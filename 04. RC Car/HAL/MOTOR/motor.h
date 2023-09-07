/*
 * motor.h
 *
 *  Created on: Aug 31, 2023
 *      Author: Hosseni Gamal, Ahmed Abdalla
 */

#ifndef HAL_MOTOR_MOTOR_H_
#define HAL_MOTOR_MOTOR_H_

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
#include "driverlib/timer.h"
typedef struct
{
    uint32_t carSidePort;
    uint8_t  carSideDir1Pin;
    uint8_t  carSideDir2Pin;
    uint8_t  carSideEnPin;
    uint8_t  carSideSpeed;
}carSide_t;

typedef enum
{
    forward=0,
    backward,
    stop
}carSideDirection_t;

/*This function is used to initialize the a car side of the robot
 * @param sideA [carSidePort , carSideDir1Pin ,carSideDir2Pin , carSideEnPin , carSideSpeed ]
 * @return
 * */

void carSideInit(carSide_t * sideA , carSide_t * sideB);

void carSideConfig(carSide_t * carSide , carSideDirection_t direction);


#endif /* HAL_MOTOR_MOTOR_H_ */
