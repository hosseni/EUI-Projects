/*******************************
 * ldr_sensor.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Hosseni Gamal
 ********************************/
#include "ldr_sensor.h"

/***************************************************************************************************
 *  Function: ldrSensorInit
 *  Description:
 *      This function initializes the Light Dependent Resistor (LDR) sensor based on the provided configuration.
 *  Parameters:
 *      sensor: Pointer to an ldrSensor_t structure containing LDR sensor configuration settings.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void ldrSensorInit(ldrSensor_t *sensor)
{
    if (sensor == NULL)
    {
        return;
    }
    else
    {
        /* Enable clock gate for PORTE for PINE2 for ADC0 */
        //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_PLL);

        /* Configure pin E2 in analog mode */
        GPIOPinTypeADC(sensor->ldrPort, sensor->ldrPin);

        /* Configure sequencer 0 to be triggered by processor */
        ADCSequenceConfigure(ADC0_BASE, sensor->sequencer, ADC_TRIGGER_PROCESSOR, 0);

        /* Configure ADC step */
        ADCSequenceStepConfigure(ADC0_BASE, sensor->sequencer, 0, ADC_CTL_END | sensor->adcChannel | ADC_CTL_IE);

        /* Enable ADC sequencer 0 */
        ADCSequenceEnable(ADC0_BASE, sensor->sequencer);
    }
}

/***************************************************************************************************
 *  Function: ldrSensorReading
 *  Description:
 *      This function reads the value from the Light Dependent Resistor (LDR) sensor.
 *  Parameters:
 *      sensor: Pointer to an ldrSensor_t structure containing LDR sensor configuration settings.
 *  Return Value:
 *      The ADC value read from the LDR sensor.
 ***************************************************************************************************/
uint32_t ldrSensorReading(ldrSensor_t *sensor)
{
    if (sensor == NULL)
    {
        return 0;
    }
    else
    {
        /* Variable to return ADC value */
        uint32_t ui32Value = 0;

        /* Start ADC conversion */
        ADCProcessorTrigger(ADC0_BASE, sensor->sequencer);

        /* Wait for conversion completion */
        while (!ADCIntStatus(ADC0_BASE, sensor->sequencer, false))
        { }

        /* Clear interrupt flag */
        ADCIntClear(ADC0_BASE, sensor->sequencer);

        /* Reading ADC value */
        ADCSequenceDataGet(ADC0_BASE, sensor->sequencer, &ui32Value);

        return ui32Value;
    }
}
