/************************************
 * INCLUDES
 ************************************/

#include "Inc/MCAL/GPIO/GPIO_config.h"
#include "Inc/MCAL/GPIO/GPIO_interface.h"



/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/



const Port_ConfigType portConfig[NUM_PINS] =
{
 /* Pin          Direction           Mode            Attach Type         Output Current */
 {PIN_B0,        PIN_INPUT,          PIN_DIO,     PIN_AF_ENABLE,       PIN_PULLUP,         PIN_CURRENT_2mA}, // Timer2 AF

 { PIN_A2,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_A3,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_A4,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_A6,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,   PIN_PULLUP,          PIN_CURRENT_2mA},

 { PIN_B4,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_B5,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_B6,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_B7,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},

 { PIN_C6,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_C7,       PIN_OUTPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},




 { PIN_D2,       PIN_OUTPUT,         PIN_DIO,    PIN_AF_DISABLE,     PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_D3,       PIN_OUTPUT,         PIN_DIO,    PIN_AF_DISABLE,     PIN_PULLUP,          PIN_CURRENT_2mA},

 { PIN_D6,       PIN_OUTPUT,         PIN_DIO,    PIN_AF_DISABLE,     PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_D7,       PIN_OUTPUT,         PIN_DIO,    PIN_AF_DISABLE,        PIN_PULLUP,          PIN_CURRENT_2mA},


 { PIN_E0,       PIN_INPUT,         PIN_DIO,    PIN_AF_DISABLE,     PIN_PULLDOWN,          PIN_CURRENT_2mA},
 { PIN_E1,       PIN_INPUT,         PIN_DIO,    PIN_AF_DISABLE,     PIN_PULLDOWN,          PIN_CURRENT_2mA},
 { PIN_E2,       PIN_INPUT,         PIN_DIO,    PIN_AF_DISABLE,     PIN_PULLDOWN,          PIN_CURRENT_2mA},
 { PIN_E3,       PIN_INPUT,         PIN_DIO,    PIN_AF_DISABLE,     PIN_PULLDOWN,          PIN_CURRENT_2mA},

 { PIN_F4,       PIN_INPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_F0,       PIN_INPUT,         PIN_DIO,     PIN_AF_DISABLE,    PIN_PULLUP,          PIN_CURRENT_2mA},
 { PIN_F1,       PIN_OUTPUT,         PIN_DIO,    PIN_AF_DISABLE,     PIN_PULLUP,          PIN_CURRENT_2mA},

 { PIN_F2,       PIN_OUTPUT,         PIN_DIO,    PIN_AF_ENABLE,     PIN_PULLUP,          PIN_CURRENT_2mA},


 { PIN_NC }

 /* This is the sentinel terminating element of the array and should never be changed */

};


/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
