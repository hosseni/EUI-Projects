/*
 * motor.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Hosseni Gamal, Ahmed Abdalla
 */
#include "motor.h"

void carSideInit(carSide_t * sideA , carSide_t * sideB)
{
    if(sideA == NULL || sideB == NULL)
    {
        return ;
    }else{



        /*pins direction*/
        /*side A*/
        GPIOPinTypeGPIOOutput(sideA->carSidePort , sideA->carSideDir1Pin|sideA->carSideDir2Pin);
        /*side B*/
        GPIOPinTypeGPIOOutput(sideB->carSidePort , sideB->carSideDir1Pin|sideB->carSideDir2Pin);

        /*alternative pin for PWM */
        /*pins as a timer */
        GPIOPinConfigure(GPIO_PB6_T0CCP0);
        GPIOPinConfigure(GPIO_PB0_T2CCP0);
        /*pin selected*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_6);
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_0);

        /*Disable timer*/
        TimerDisable(TIMER0_BASE, TIMER_A);
        TimerDisable(TIMER2_BASE, TIMER_A);

        /*configure timer as a PWM*/
        TimerConfigure(TIMER0_BASE , TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);
        TimerConfigure(TIMER2_BASE , TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);

        /*inverted*/
        TimerControlLevel(TIMER0_BASE , TIMER_A , false);
        TimerControlLevel(TIMER2_BASE , TIMER_A , false);

        /*Set initial value to timer for period of pwm*/
        TimerLoadSet(TIMER0_BASE , TIMER_A , 0xFFFF);
        TimerLoadSet(TIMER2_BASE , TIMER_A , 0xFFFF);

        /*duty cycle for speed*/
        TimerMatchSet(TIMER0_BASE, TIMER_A,  (100- sideA->carSideSpeed) * 0xFFFF / 100);
        TimerMatchSet(TIMER2_BASE, TIMER_A,  (100- sideB->carSideSpeed) * 0xFFFF / 100);

        /*Enable Timer*/
        TimerEnable(TIMER0_BASE , TIMER_A);
        TimerEnable(TIMER2_BASE , TIMER_A);
    }
}

void carSideConfig(carSide_t * carSide , carSideDirection_t direction)
{
    if(carSide == NULL)
    {
        return ;
    }else{
        switch(direction)
        {
            case forward:
                /*Set direction to moving forward*/
                GPIOPinWrite(carSide->carSidePort, carSide->carSideDir1Pin  , 0xFFU);
                GPIOPinWrite(carSide->carSidePort, carSide->carSideDir2Pin  , 0U);
                break;
            case backward:
                /*Set direction to moving backward*/
                GPIOPinWrite(carSide->carSidePort, carSide->carSideDir1Pin  , 0U);
                GPIOPinWrite(carSide->carSidePort, carSide->carSideDir2Pin  , 0xFFU);
                break;
            case stop:
                /*Stop car side motors*/
                GPIOPinWrite(carSide->carSidePort, carSide->carSideDir1Pin  , 0U);
                GPIOPinWrite(carSide->carSidePort, carSide->carSideDir2Pin  , 0U);
                break;
            default:
                ;
        }
    }
}


