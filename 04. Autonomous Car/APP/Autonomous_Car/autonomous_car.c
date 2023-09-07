/*
 * main.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Hosseni Gamal , Ahmed Abdalla
 */

#include "autonomous_car.h"


ldrSensor_t  ldr_left        = {GPIO_PORTE_BASE, GPIO_PIN_3, 0, ADC_CTL_CH0};
ldrSensor_t  ldr_right       = {GPIO_PORTE_BASE, GPIO_PIN_2, 1, ADC_CTL_CH1};

ultraSonic_t ultraSonic1 = {GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_3};

carSide_t LEFT_SIDE  = {
                        .carSidePort = GPIO_PORTB_BASE,
                        .carSideDir1Pin = GPIO_PIN_7,
                        .carSideDir2Pin = GPIO_PIN_1,
                        .carSideEnPin = GPIO_PIN_6,
                        .carSideSpeed = 35

};
carSide_t RIGHT_SIDE = {
                        .carSidePort = GPIO_PORTB_BASE,
                        .carSideDir1Pin = GPIO_PIN_4,
                        .carSideDir2Pin = GPIO_PIN_5,
                        .carSideEnPin = GPIO_PIN_0,
                        .carSideSpeed = 35
};



static void robotInit();
static void robotMoveStop(void);
static void robotMoveRotate(void);
static void robotMoveLeft(void);
static void robotMoveRight(void);



volatile uint32_t millis=0;


void SycTickInt(){
    millis++;
}
void SysTickbegin(){
    SysTickPeriodSet(80000);
    SysTickIntRegister(SycTickInt);
    SysTickIntEnable();
    SysTickEnable();
}

void Wait(uint32_t time){
    uint32_t temp = millis;
    while( (millis-temp) < time){
    }
}

void autonomousCarInit ()
{
    SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);

    SysTickbegin();

    ultarsonicSensorInit(&ultraSonic1);
    ldrSensorInit(&ldr_left);
    ldrSensorInit(&ldr_right);
    robotInit();

}
void autonomousCarRun()
{
    uint16_t destance = 0;
    uint32_t ldr_right_read = 0;
    uint32_t ldr_left_read = 0;

    destance = ultarsonicSensorReadValue(&ultraSonic1);
    ldr_left_read = ldrSensorReading(&ldr_left);
    ldr_right_read = ldrSensorReading(&ldr_right);


    if ((destance > 5) && (ldr_left_read < ldr_right_read))
    {
        robotMoveLeft();
        Wait(50);
    }
    else if ((destance > 5) && (ldr_left_read > ldr_right_read))
    {
        robotMoveRight();
        Wait(50);

    }
    else if (destance < 5)
    {
        robotMoveStop();
        Wait(150);
        robotMoveRotate();
        Wait(150);
    }
}

static void robotInit()
{
    carSideInit(&LEFT_SIDE , &RIGHT_SIDE);
}


static void robotMoveStop(void)
{
    carSideConfig(&LEFT_SIDE , stop);
    carSideConfig(&RIGHT_SIDE , stop);
}

static void robotMoveRotate(void)
{
    carSideConfig(&LEFT_SIDE , backward);
    carSideConfig(&RIGHT_SIDE , forward);
}

static void robotMoveLeft(void)
{
    carSideConfig(&LEFT_SIDE , stop);
    carSideConfig(&RIGHT_SIDE , forward);
}

static void robotMoveRight(void)
{
    carSideConfig(&LEFT_SIDE , forward);
    carSideConfig(&RIGHT_SIDE , stop);
}
