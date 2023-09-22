
#include "dio.h"

#include "inc/tm4c123gh6pm.h"
#include <stdint.h>
#include "../../LIB/bitwise_operation.h"


#define GPIO_PORTF_BIT_DATA(BIT_NUMBER) *((volatile uint32_t *)(0x40025000 + ((1 << BIT_NUMBER) << 2)))

void DIO_Init(unsigned char portNum, unsigned char pinNum, unsigned char dir)
{
    if(portNum == PORTA){
        SYSCTL_RCGCGPIO_R |= (1<<PORTA);
        while(getBit(SYSCTL_RCGCGPIO_R, PORTA) != 1){}
        if(dir == IN){
            clearBit(GPIO_PORTA_DIR_R, pinNum);
            setBit(GPIO_PORTA_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTA_DIR_R, pinNum);
        }
        setBit(GPIO_PORTA_DEN_R, pinNum);
    }
    else if(portNum == PORTB){
        SYSCTL_RCGCGPIO_R |= (1<<PORTB);
        while(getBit(SYSCTL_RCGCGPIO_R, PORTB) != 1){}
        if(dir == IN){
            clearBit(GPIO_PORTB_DIR_R, pinNum);
            setBit(GPIO_PORTB_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTB_DIR_R, pinNum);
        }
        setBit(GPIO_PORTB_DEN_R, pinNum);
    }
    else if(portNum == PORTC){
        SYSCTL_RCGCGPIO_R |= (1<<PORTC);
        while(getBit(SYSCTL_RCGCGPIO_R, PORTC) != 1){}
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        setBit(GPIO_PORTC_CR_R, pinNum);
        if(dir == IN){
            clearBit(GPIO_PORTC_DIR_R, pinNum);
            setBit(GPIO_PORTC_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTC_DIR_R, pinNum);
        }
        setBit(GPIO_PORTC_DEN_R, pinNum);
    }
    else if(portNum == PORTD){
        SYSCTL_RCGCGPIO_R |= (1<<PORTD);
        while(getBit(SYSCTL_RCGCGPIO_R, PORTD) != 1){}
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        setBit(GPIO_PORTD_CR_R, pinNum);
        if(dir == IN){
            clearBit(GPIO_PORTD_DIR_R, pinNum);
            setBit(GPIO_PORTD_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTD_DIR_R, pinNum);
        }
        setBit(GPIO_PORTD_DEN_R, pinNum);
    }
    else if(portNum == PORTE){
        SYSCTL_RCGCGPIO_R |= (1<<PORTE);
        while(getBit(SYSCTL_RCGCGPIO_R, PORTE) != 1){}
        if(dir == IN){
            clearBit(GPIO_PORTE_DIR_R, pinNum);
            setBit(GPIO_PORTE_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTE_DIR_R, pinNum);
        }
        setBit(GPIO_PORTE_DEN_R, pinNum);
    }
    else if(portNum == PORTF){
        SYSCTL_RCGCGPIO_R |= (1<<PORTF);
        while(getBit(SYSCTL_RCGCGPIO_R, PORTF) != 1){}
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        setBit(GPIO_PORTF_CR_R, pinNum);
        if(dir == IN){
            clearBit(GPIO_PORTF_DIR_R, pinNum);
            setBit(GPIO_PORTF_PUR_R, pinNum);
        }
        else if(dir == OUT){
            setBit(GPIO_PORTF_DIR_R, pinNum);
        }
        setBit(GPIO_PORTF_DEN_R, pinNum);
    }
}

void DIO_WritePin(unsigned char portNum, unsigned char pinNum, unsigned char Val){
    if(portNum == PORTA){
        if(Val == 0){
            clearBit(GPIO_PORTA_DATA_R, pinNum);
        }
        else if(Val == 1){
            setBit(GPIO_PORTA_DATA_R, pinNum);
        }
    }

    else if(portNum == PORTB){
        if(Val == 0){
            clearBit(GPIO_PORTB_DATA_R, pinNum);
        }
        else if(Val == 1){
            setBit(GPIO_PORTB_DATA_R, pinNum);
        }
    }

    else if(portNum == PORTC){
        if(Val == 0){
            clearBit(GPIO_PORTC_DATA_R, pinNum);
        }
        else if(Val == 1){
            setBit(GPIO_PORTC_DATA_R, pinNum);
        }
    }

    else if(portNum == PORTD){
        if(Val == 0){
            clearBit(GPIO_PORTD_DATA_R, pinNum);
        }
        else if(Val == 1){
            setBit(GPIO_PORTD_DATA_R, pinNum);
        }
    }

    else if(portNum == PORTE){
        if(Val == 0){
            clearBit(GPIO_PORTE_DATA_R, pinNum);
        }
        else if(Val == 1){
            setBit(GPIO_PORTE_DATA_R, pinNum);
        }
    }

    else if(portNum == PORTF){
        GPIO_PORTF_BIT_DATA(pinNum) = (Val<<pinNum);
        /*if(Val == 0){
            clearBit(GPIO_PORTF_DATA_R, pinNum);
        }
        else if(Val == 1){
            setBit(GPIO_PORTF_DATA_R, pinNum);
        }*/
    }
}

void DIO_WritePort(unsigned char portNum, unsigned char Val){
    if(portNum == PORTA){
        GPIO_PORTA_DATA_R=Val;
    }

    else if(portNum == PORTB){
        GPIO_PORTB_DATA_R=Val;
    }

    else if(portNum == PORTC){
        GPIO_PORTC_DATA_R=Val;
    }

    else if(portNum == PORTD){
        GPIO_PORTD_DATA_R=Val;
    }

    else if(portNum == PORTE){
        GPIO_PORTE_DATA_R=Val;
    }

    else if(portNum == PORTF){
        GPIO_PORTF_DATA_R=Val;
    }

}

unsigned long DIO_getPortValue(unsigned char portNum){
    if(portNum == PORTA){
        return GPIO_PORTA_DATA_R;
    }
    else if(portNum == PORTB){
        return GPIO_PORTB_DATA_R;
    }
    else if(portNum == PORTC){
        return GPIO_PORTC_DATA_R;
    }
    else if(portNum == PORTD){
        return GPIO_PORTD_DATA_R;
    }
    else if(portNum == PORTE){
        return GPIO_PORTE_DATA_R;
    }
    else if(portNum == PORTF){
        return GPIO_PORTF_DATA_R;
    }
}

unsigned char DIO_getPinValue(unsigned char portNum, unsigned char pinNum){
    unsigned char value;
    if(portNum == PORTA){
        value = getBit(GPIO_PORTA_DATA_R, pinNum);
    }
    else if(portNum == PORTB){
        value = getBit(GPIO_PORTB_DATA_R, pinNum);
    }
    else if(portNum == PORTC){
        value = getBit(GPIO_PORTC_DATA_R, pinNum);
    }
    else if(portNum == PORTD){
        value = getBit(GPIO_PORTD_DATA_R, pinNum);

    }
    else if(portNum == PORTE){
        value = getBit(GPIO_PORTE_DATA_R, pinNum);

    }
    else if(portNum == PORTF){
        value = getBit(GPIO_PORTF_DATA_R, pinNum);
    }
    return value;
}
