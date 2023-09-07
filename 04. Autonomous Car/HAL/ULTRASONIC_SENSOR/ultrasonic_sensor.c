/*
 * ultrasonic_sensor.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Hosseni Gamal, Ahmed Abdalla
 */
#include "ultrasonic_sensor.h"

void ultarsonicSensorInit(ultraSonic_t *sensor)
{
    if(sensor == NULL)
    {
        return ;
    }else{
        /*Set echo pin as input*/
        GPIOPinTypeGPIOInput(sensor->ultrasonicPort, sensor->ultrasonicEchoPin);
        /*Set trigger pin as output*/
        GPIOPinTypeGPIOOutput(sensor->ultrasonicPort,  sensor->ultrasonicTriggerPin);
        /*Disable Timer1-A to use it to calculate time*/
        TimerDisable(TIMER1_BASE, TIMER_A);
        /*Configure Timer1-A to one shot mode in  down counting mode*/
        TimerConfigure(TIMER1_BASE , TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_ONE_SHOT);
        /*To stop timer during debugging*/
        TimerControlStall(TIMER1_BASE , TIMER_A , true);
        /*To load timer with initial value = 0xFFFF */
        TimerLoadSet(TIMER1_BASE , TIMER_A , 0xFFFF);
    }
}

uint16_t ultarsonicSensorReadValue(ultraSonic_t *sensor)
{
    if(sensor == NULL)
    {
        return 0 ;
    }else{
        /*Variable to store time of ultrasonic*/
        uint16_t duration = 0U;
        /*Variable to store distance*/
        uint16_t reading = 0U ;
        /*Variable to store the state of echo pin*/
        uint8_t pinValue = 0U ;
        /*Sending 10uS pulse on trigger pin to enable ultrasonic sensor*/
        GPIOPinWrite(sensor->ultrasonicPort, sensor->ultrasonicTriggerPin, 0xFF);
        /*Delay 10 micro Second*/
        SysCtlDelay(55U);
        GPIOPinWrite(sensor->ultrasonicPort, sensor->ultrasonicTriggerPin, 0);


        /*Waiting for echo pin to be high*/
        while(!(pinValue & sensor->ultrasonicEchoPin))
        {
            pinValue =  GPIOPinRead(sensor->ultrasonicPort, sensor->ultrasonicEchoPin);
        }
        /*Start calculating time*/
        TimerLoadSet(TIMER1_BASE, TIMER_A, ~0U);
        TimerEnable(TIMER1_BASE, TIMER_A);

        /*Waiting for echo pin to be low*/
        while((pinValue & sensor->ultrasonicEchoPin))
        {
            pinValue =  GPIOPinRead(sensor->ultrasonicPort, sensor->ultrasonicEchoPin);
        }
        /*Getting the time value*/
        duration = TimerValueGet(TIMER1_BASE ,TIMER_A);
        /*Calculate the actual time*/
        duration = 0xffff - duration;
        /*Disable timer1-A*/
        TimerDisable(TIMER1_BASE, TIMER_A);
        /*Calculating distance in cm*/
        reading = (duration *340.0 *100) / (2.0*16000000);
        /*Returning distance*/
        return reading;
    }
}

