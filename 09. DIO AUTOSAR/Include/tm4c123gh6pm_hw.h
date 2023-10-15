/*
 * File: tm4c123gh6pm_hw.h
 * Created Date: 14/10/2023
 * Author: Elhosseni Gamal

 * ----------	---	---------------------------------------------------------
 */

#ifndef TM4C123GH6PM_HW_H_INCLUDED
#define TM4C123GH6PM_HW_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "Std_Types.h"

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/
#define ACCESS_ADR(x)                           (*(( volatile uint32* )(x)))
#define ACCESS_BITBAND_ADR(adr, bit, base)      ACCESS_ADR((32u*adr)+base+(4u*bit))

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/
#define NUM_INTERRUPTS          154u

#define NUM_PINS                43u
#define NUM_PORTS               6u
#define NUM_TIMER               12u

#define CM4_PRPH_BASE           0xE000E000lu
#define SYSCTRL_BASE            0x400FE000lu

#define GPIO_A_AHB_BASE         0x40058000lu
#define GPIO_B_AHB_BASE         0x40059000lu
#define GPIO_C_AHB_BASE         0x4005A000lu
#define GPIO_D_AHB_BASE         0x4005B000lu
#define GPIO_E_AHB_BASE         0x4005C000lu
#define GPIO_F_AHB_BASE         0x4005D000lu

#define GPT_0_BASE              0x40030000lu
#define GPT_1_BASE              0x40031000lu
#define GPT_2_BASE              0x40032000lu
#define GPT_3_BASE              0x40033000lu
#define GPT_4_BASE              0x40034000lu
#define GPT_5_BASE              0x40035000lu

#define GPWT_0_BASE             0x40036000lu
#define GPWT_1_BASE             0x40037000lu
#define GPWT_2_BASE             0x4004C000lu
#define GPWT_3_BASE             0x4004D000lu
#define GPWT_4_BASE             0x4004E000lu
#define GPWT_5_BASE             0x4004F000lu

#define BITBAND_PRPH_BASE           0x40000000lu
#define BITBAND_PRPH_ALIAS_BASE     0x42000000lu

#define INTCTRL                 ACCESS_ADR(CM4_PRPH_BASE+0xD04u)
#define VTABLE                  ACCESS_ADR(CM4_PRPH_BASE+0xD08u)
#define APINT                   ACCESS_ADR(CM4_PRPH_BASE+0xD0Cu)
#define SYSHNDCTRL              ACCESS_ADR(CM4_PRPH_BASE+0xD24u)
#define FAULTSTAT               ACCESS_ADR(CM4_PRPH_BASE+0xD28u)
#define HFAULTSTAT              ACCESS_ADR(CM4_PRPH_BASE+0xD2Cu)
#define SWTRIG                  ACCESS_ADR(CM4_PRPH_BASE+0xF00u)

#define EN0                     ACCESS_ADR(CM4_PRPH_BASE+0x100u)
#define EN1                     ACCESS_ADR(CM4_PRPH_BASE+0x104u)

#define PRI0                    ACCESS_ADR(CM4_PRPH_BASE+0x400u)
#define PRI1                    ACCESS_ADR(CM4_PRPH_BASE+0x404u)
#define PRI2                    ACCESS_ADR(CM4_PRPH_BASE+0x408u)
#define PRI3                    ACCESS_ADR(CM4_PRPH_BASE+0x40Cu)
#define PRI4                    ACCESS_ADR(CM4_PRPH_BASE+0x410u)
#define PRI5                    ACCESS_ADR(CM4_PRPH_BASE+0x414u)
#define PRI6                    ACCESS_ADR(CM4_PRPH_BASE+0x418u)
#define PRI7                    ACCESS_ADR(CM4_PRPH_BASE+0x41Cu)
#define PRI8                    ACCESS_ADR(CM4_PRPH_BASE+0x420u)
#define PRI9                    ACCESS_ADR(CM4_PRPH_BASE+0x424u)
#define PRI10                   ACCESS_ADR(CM4_PRPH_BASE+0x428u)
#define PRI11                   ACCESS_ADR(CM4_PRPH_BASE+0x42Cu)
#define PRI12                   ACCESS_ADR(CM4_PRPH_BASE+0x430u)
#define PRI13                   ACCESS_ADR(CM4_PRPH_BASE+0x434u)
#define PRI14                   ACCESS_ADR(CM4_PRPH_BASE+0x438u)
#define PRI15                   ACCESS_ADR(CM4_PRPH_BASE+0x43Cu)

#define SYSPRI1                 ACCESS_ADR(CM4_PRPH_BASE+0xD18u)
#define SYSPRI2                 ACCESS_ADR(CM4_PRPH_BASE+0xD1Cu)
#define SYSPRI3                 ACCESS_ADR(CM4_PRPH_BASE+0xD20u)

#define RCC                     ACCESS_ADR(SYSCTRL_BASE+0x060u)
#define RCC2                    ACCESS_ADR(SYSCTRL_BASE+0x070u)
#define RCC                     ACCESS_ADR(SYSCTRL_BASE+0x060u)
#define GPIOHBCTL               ACCESS_ADR(SYSCTRL_BASE+0x06Cu)
#define RCGCGPIO                ACCESS_ADR(SYSCTRL_BASE+0x608u)
#define RCGCTIMER               ACCESS_ADR(SYSCTRL_BASE+0x604u)
#define RCGCWTIMER              ACCESS_ADR(SYSCTRL_BASE+0x65Cu)

#define GPIODATA_AHB_A          ACCESS_ADR(GPIO_A_AHB_BASE+0x000u+0x3FCu) 
#define GPIOAFSEL_AHB_A         ACCESS_ADR(GPIO_A_AHB_BASE+0x420u)
#define GPIODEN_AHB_A           ACCESS_ADR(GPIO_A_AHB_BASE+0x51Cu)
#define GPIODIR_AHB_A           ACCESS_ADR(GPIO_A_AHB_BASE+0x400u)
#define GPIOODR_AHB_A           ACCESS_ADR(GPIO_A_AHB_BASE+0x50Cu)
#define GPIOPUR_AHB_A           ACCESS_ADR(GPIO_A_AHB_BASE+0x510u)
#define GPIOPDR_AHB_A           ACCESS_ADR(GPIO_A_AHB_BASE+0x514u)
#define GPIOLOCK_AHB_A          ACCESS_ADR(GPIO_A_AHB_BASE+0x520u)
#define GPIOCR_AHB_A            ACCESS_ADR(GPIO_A_AHB_BASE+0x524u)

#define GPIODATA_AHB_B          ACCESS_ADR(GPIO_B_AHB_BASE+0x000u+0x3FCu)
#define GPIOAFSEL_AHB_B         ACCESS_ADR(GPIO_B_AHB_BASE+0x420u)
#define GPIODEN_AHB_B           ACCESS_ADR(GPIO_B_AHB_BASE+0x51Cu)
#define GPIODIR_AHB_B           ACCESS_ADR(GPIO_B_AHB_BASE+0x400u)
#define GPIOODR_AHB_B           ACCESS_ADR(GPIO_B_AHB_BASE+0x50Cu)
#define GPIOPUR_AHB_B           ACCESS_ADR(GPIO_B_AHB_BASE+0x510u)
#define GPIOPDR_AHB_B           ACCESS_ADR(GPIO_B_AHB_BASE+0x514u)
#define GPIOLOCK_AHB_B          ACCESS_ADR(GPIO_A_AHB_BASE+0x520u)
#define GPIOCR_AHB_B            ACCESS_ADR(GPIO_A_AHB_BASE+0x524u)

#define GPIODATA_AHB_C          ACCESS_ADR(GPIO_C_AHB_BASE+0x000u+0x3FCu)
#define GPIOAFSEL_AHB_C         ACCESS_ADR(GPIO_C_AHB_BASE+0x420u)
#define GPIODEN_AHB_C           ACCESS_ADR(GPIO_C_AHB_BASE+0x51Cu)
#define GPIODIR_AHB_C           ACCESS_ADR(GPIO_C_AHB_BASE+0x400u)
#define GPIOODR_AHB_C           ACCESS_ADR(GPIO_C_AHB_BASE+0x50Cu)
#define GPIOPUR_AHB_C           ACCESS_ADR(GPIO_C_AHB_BASE+0x510u)
#define GPIOPDR_AHB_C           ACCESS_ADR(GPIO_C_AHB_BASE+0x514u)
#define GPIOLOCK_AHB_C          ACCESS_ADR(GPIO_C_AHB_BASE+0x520u)
#define GPIOCR_AHB_C            ACCESS_ADR(GPIO_C_AHB_BASE+0x524u)

#define GPIODATA_AHB_F          ACCESS_ADR(GPIO_F_AHB_BASE+0x000u+0x3FCu)
#define GPIOAFSEL_AHB_F         ACCESS_ADR(GPIO_F_AHB_BASE+0x420u)
#define GPIODEN_AHB_F           ACCESS_ADR(GPIO_F_AHB_BASE+0x51Cu)
#define GPIODIR_AHB_F           ACCESS_ADR(GPIO_F_AHB_BASE+0x400u)
#define GPIOODR_AHB_F           ACCESS_ADR(GPIO_F_AHB_BASE+0x50Cu)
#define GPIOPUR_AHB_F           ACCESS_ADR(GPIO_F_AHB_BASE+0x510u)
#define GPIOPDR_AHB_F           ACCESS_ADR(GPIO_F_AHB_BASE+0x514u)
#define GPIOLOCK_AHB_F          ACCESS_ADR(GPIO_F_AHB_BASE+0x520u)
#define GPIOCR_AHB_F            ACCESS_ADR(GPIO_F_AHB_BASE+0x524u)

#define ACCESS_GPTMCFG(x)       ACCESS_ADR(x + 0x000u)
#define ACCESS_GPTMTAMR(x)      ACCESS_ADR(x + 0x004u)
#define ACCESS_GPTMTBMR(x)      ACCESS_ADR(x + 0x008u)
#define ACCESS_GPTMCTL(x)       ACCESS_ADR(x + 0x00Cu)
#define ACCESS_GPTMIMR(x)       ACCESS_ADR(x + 0x018u)
#define ACCESS_GPTMTAV(x)       ACCESS_ADR(x + 0x050u)
#define ACCESS_GPTMTAR(x)       ACCESS_ADR(x + 0x048u)
#define ACCESS_GPTMTAPR(x)      ACCESS_ADR(x + 0x038u)
#define ACCESS_GPTMICR(x)       ACCESS_ADR(x + 0x024u)
#define ACCESS_GPTMTAILR(x)     ACCESS_ADR(x + 0x028u)

/************************************
 * GLOBAL TYPES
 ************************************/

/************************************
 * GLOBAL DATA PROTOTYPES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif
/* TM4C123GH6PM_HW_H_INCLUDED */
