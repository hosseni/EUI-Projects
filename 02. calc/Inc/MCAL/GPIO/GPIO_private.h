/*
 * GPIO_private.h
 *
 *  Created on: 13/8/2023
 *      Author: HOSSENI
 */

#ifndef INC_MCAL_GPIO_PRIVATE_H_
#define INC_MCAL_GPIO_PRIVATE_H_
#define ACCESS_ADR(x)                           (*((volatile uint32* )(x)))
#define ACCESS_BITBAND_ADR(adr, bit, base)      ACCESS_ADR((32u*adr)+base+(4u*bit))


#define BITBAND_PRPH_BASE           0x40000000lu
#define BITBAND_PRPH_ALIAS_BASE     0x42000000lu


#define GPIO_A_AHB_BASE         0x40058000lu
#define GPIO_B_AHB_BASE         0x40059000lu
#define GPIO_C_AHB_BASE         0x4005A000lu
#define GPIO_D_AHB_BASE         0x4005B000lu
#define GPIO_E_AHB_BASE         0x4005C000lu
#define GPIO_F_AHB_BASE         0x4005D000lu

#define GPIO_A_APB_BASE         0x40004000lu
#define GPIO_B_APB_BASE         0x40005000lu
#define GPIO_C_APB_BASE         0x40006000lu
#define GPIO_D_APB_BASE         0x40007000lu
#define GPIO_E_APB_BASE         0x40024000lu
#define GPIO_F_APB_BASE         0x40025000lu


#define GPIODATA_APB_A          ACCESS_ADR(GPIO_A_APB_BASE+DATA_BASE_ADD )
#define GPIOAFSEL_APB_A         ACCESS_ADR(GPIO_A_APB_BASE+AFSEL_BASE_ADD)
#define GPIODEN_APB_A           ACCESS_ADR(GPIO_A_APB_BASE+DEN_BASE_ADD  )
#define GPIODIR_APB_A           ACCESS_ADR(GPIO_A_APB_BASE+DIR_BASE_ADD  )
#define GPIOODR_APB_A           ACCESS_ADR(GPIO_A_APB_BASE+ODR_BASE_ADD  )
#define GPIOPUR_APB_A           ACCESS_ADR(GPIO_A_APB_BASE+PUR_BASE_ADD  )
#define GPIOPDR_APB_A           ACCESS_ADR(GPIO_A_APB_BASE+PDR_BASE_ADD  )
#define GPIOLOCK_APB_A          ACCESS_ADR(GPIO_A_APB_BASE+LOCK_BASE_ADD )
#define GPIOCR_APB_A            ACCESS_ADR(GPIO_A_APB_BASE+CR_BASE_ADD   )

#define GPIODATA_APB_B          ACCESS_ADR(GPIO_B_APB_BASE+DATA_BASE_ADD )
#define GPIOAFSEL_APB_B         ACCESS_ADR(GPIO_B_APB_BASE+AFSEL_BASE_ADD)
#define GPIODEN_APB_B           ACCESS_ADR(GPIO_B_APB_BASE+DEN_BASE_ADD  )
#define GPIODIR_APB_B           ACCESS_ADR(GPIO_B_APB_BASE+DIR_BASE_ADD  )
#define GPIOODR_APB_B           ACCESS_ADR(GPIO_B_APB_BASE+ODR_BASE_ADD  )
#define GPIOPUR_APB_B           ACCESS_ADR(GPIO_B_APB_BASE+PUR_BASE_ADD  )
#define GPIOPDR_APB_B           ACCESS_ADR(GPIO_B_APB_BASE+PDR_BASE_ADD  )
#define GPIOLOCK_APB_B          ACCESS_ADR(GPIO_A_APB_BASE+LOCK_BASE_ADD )
#define GPIOCR_APB_B            ACCESS_ADR(GPIO_A_APB_BASE+CR_BASE_ADD   )

#define GPIODATA_APB_C          ACCESS_ADR(GPIO_C_APB_BASE+DATA_BASE_ADD )
#define GPIOAFSEL_APB_C         ACCESS_ADR(GPIO_C_APB_BASE+AFSEL_BASE_ADD)
#define GPIODEN_APB_C           ACCESS_ADR(GPIO_C_APB_BASE+DEN_BASE_ADD  )
#define GPIODIR_APB_C           ACCESS_ADR(GPIO_C_APB_BASE+DIR_BASE_ADD  )
#define GPIOODR_APB_C           ACCESS_ADR(GPIO_C_APB_BASE+ODR_BASE_ADD  )
#define GPIOPUR_APB_C           ACCESS_ADR(GPIO_C_APB_BASE+PUR_BASE_ADD  )
#define GPIOPDR_APB_C           ACCESS_ADR(GPIO_C_APB_BASE+PDR_BASE_ADD  )
#define GPIOLOCK_APB_C          ACCESS_ADR(GPIO_C_APB_BASE+LOCK_BASE_ADD )
#define GPIOCR_APB_C            ACCESS_ADR(GPIO_C_APB_BASE+CR_BASE_ADD   )

#define GPIODATA_APB_D          ACCESS_ADR(GPIO_D_APB_BASE+DATA_BASE_ADD )
#define GPIOAFSEL_APB_D         ACCESS_ADR(GPIO_D_APB_BASE+AFSEL_BASE_ADD)
#define GPIODEN_APB_D           ACCESS_ADR(GPIO_D_APB_BASE+DEN_BASE_ADD  )
#define GPIODIR_APB_D           ACCESS_ADR(GPIO_D_APB_BASE+DIR_BASE_ADD  )
#define GPIOODR_APB_D           ACCESS_ADR(GPIO_D_APB_BASE+ODR_BASE_ADD  )
#define GPIOPUR_APB_D           ACCESS_ADR(GPIO_D_APB_BASE+PUR_BASE_ADD  )
#define GPIOPDR_APB_D           ACCESS_ADR(GPIO_D_APB_BASE+PDR_BASE_ADD  )
#define GPIOLOCK_APB_D          ACCESS_ADR(GPIO_D_APB_BASE+LOCK_BASE_ADD )
#define GPIOCR_APB_D            ACCESS_ADR(GPIO_D_APB_BASE+CR_BASE_ADD   )

#define GPIODATA_APB_E          ACCESS_ADR(GPIO_E_APB_BASE+DATA_BASE_ADD )
#define GPIOAFSEL_APB_E         ACCESS_ADR(GPIO_E_APB_BASE+AFSEL_BASE_ADD)
#define GPIODEN_APB_E           ACCESS_ADR(GPIO_E_APB_BASE+DEN_BASE_ADD  )
#define GPIODIR_APB_E           ACCESS_ADR(GPIO_E_APB_BASE+DIR_BASE_ADD  )
#define GPIOODR_APB_E           ACCESS_ADR(GPIO_E_APB_BASE+ODR_BASE_ADD  )
#define GPIOPUR_APB_E           ACCESS_ADR(GPIO_E_APB_BASE+PUR_BASE_ADD  )
#define GPIOPDR_APB_E           ACCESS_ADR(GPIO_E_APB_BASE+PDR_BASE_ADD  )
#define GPIOLOCK_APB_E          ACCESS_ADR(GPIO_E_APB_BASE+LOCK_BASE_ADD )
#define GPIOCR_APB_E            ACCESS_ADR(GPIO_E_APB_BASE+CR_BASE_ADD   )

#define GPIODATA_APB_F          ACCESS_ADR(GPIO_F_APB_BASE+DATA_BASE_ADD )
#define GPIOAFSEL_APB_F         ACCESS_ADR(GPIO_F_APB_BASE+AFSEL_BASE_ADD)
#define GPIODEN_APB_F           ACCESS_ADR(GPIO_F_APB_BASE+DEN_BASE_ADD  )
#define GPIODIR_APB_F           ACCESS_ADR(GPIO_F_APB_BASE+DIR_BASE_ADD  )
#define GPIOODR_APB_F           ACCESS_ADR(GPIO_F_APB_BASE+ODR_BASE_ADD  )
#define GPIOPUR_APB_F           ACCESS_ADR(GPIO_F_APB_BASE+PUR_BASE_ADD  )
#define GPIOPDR_APB_F           ACCESS_ADR(GPIO_F_APB_BASE+PDR_BASE_ADD  )
#define GPIOLOCK_APB_F          ACCESS_ADR(GPIO_F_APB_BASE+LOCK_BASE_ADD )
#define GPIOCR_APB_F            ACCESS_ADR(GPIO_F_APB_BASE+CR_BASE_ADD   )
#define GPIO_PORTF_PCTL_F       ACCESS_ADR(GPIO_F_APB_BASE+0x52C         )


#define DATA_BASE_ADD    0x3FCu
#define AFSEL_BASE_ADD   0x420u
#define DEN_BASE_ADD     0x51Cu
#define DIR_BASE_ADD     0x400u
#define ODR_BASE_ADD     0x50Cu
#define PUR_BASE_ADD     0x510u
#define PDR_BASE_ADD     0x514u
#define LOCK_BASE_ADD    0x520u
#define CR_BASE_ADD      0x524u







#endif /* INC_MCAL_GPIO_PRIVATE_H_ */
