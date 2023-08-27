/*
 * GPT_config.c
 *
 *  Created on: 25/8/2023
 *      Author: HOSSENI
 */


#include "Inc/MCAL/GPT/GPT_interface.h"
const GPT_ConfigType gptConfig[NUM_TIMER] =
{
 /* Channel                  (16or32)(32or64)        Prescale            Mode */
        {GPT_CHNL_TIMER0,     Extended,               0,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER1,     Extended,               0,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER2,     Extended,               0,              GPT_CH_MODE_CONTINUOUS},

        {END_LIST}

};
