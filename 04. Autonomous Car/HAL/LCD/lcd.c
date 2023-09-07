#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "lcd.h" // Define your lcd_t and row_t, col_t, and other macros here

/***************************************************************************************************
 *  Function: lcd_send_command
 *  Description:
 *      This function sends a command to the LCD module. It handles both 4-bit and 8-bit LCD modes.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      command: Command to be sent to the LCD module.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_command(const lcd_t *lcd, uint8_t command) {
    uint8_t count;
    GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_rs, LCD_RS_LOW); // RS = 0 for command

    if (lcd->lcd_connection == _4_BIT) {
        // Send upper 4 bits
        for (count = 4; count < 8; count++) {
            GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_data_pins[count - 4], (command >> count) & 0x01);
        }
        GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_en, LCD_EN_HIGH);
        SysCtlDelay(200); // Small delay
        GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_en, LCD_EN_LOW);
        SysCtlDelay(200); // Delay for command execution

        // Send lower 4 bits
        for (count = 0; count < 4; count++) {
            GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_data_pins[count], (command >> count) & 0x01);
        }
        GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_en, LCD_EN_HIGH);
        SysCtlDelay(200); // Small delay
        GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_en, LCD_EN_LOW);
        SysCtlDelay(200); // Delay for command execution
    }
    // Implement the 8-bit mode part if needed
}

/***************************************************************************************************
 *  Function: lcd_set_cursor
 *  Description:
 *      This function sets the cursor position on the LCD module based on the specified row and column.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      row: Desired row for the cursor.
 *      col: Desired column for the cursor.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_set_cursor(const lcd_t *lcd, row_t row, col_t col) {
    switch (row) {
        case ROW0:
            lcd_send_command(lcd, (0x80 + col));
            break;
        case ROW1:
            lcd_send_command(lcd, (0xc0 + col));
            break;
        case ROW2:
            lcd_send_command(lcd, (0x94 + col));
            break;
        case ROW3:
            lcd_send_command(lcd, (0xD4 + col));
            break;
    }
}
/***************************************************************************************************
 *  Function: lcd_init
 *  Description:
 *      This function initializes the LCD module based on the provided configuration.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD configuration settings.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_init(const lcd_t *lcd) {

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIO_BASE); // Enable GPIO peripheral

    // Configure LCD pins as outputs
    GPIOPinTypeGPIOOutput(GPIO_PORT_BASE, lcd->lcd_rs | lcd->lcd_en | lcd->lcd_data_pins[0] |
                                              lcd->lcd_data_pins[1] | lcd->lcd_data_pins[2] |
                                              lcd->lcd_data_pins[3]);

    SysCtlDelay(20000); // Wait for the LCD to become stable (usually requires >15ms after power-on)

    if (lcd->lcd_connection == _4_BIT) {
        // Initialize the LCD in 4-bit mode
        lcd_send_command(lcd, 0x33); // Initialization sequence for 4-bit mode
        lcd_send_command(lcd, 0x32); // Initialization sequence for 4-bit mode
        lcd_send_command(lcd, _LCD_4BIT_2LINE);
    } else if (lcd->lcd_connection == _8_BIT) {
        // Initialize the LCD in 8-bit mode if needed
    } else {
        /* Do Nothing */
    }

    lcd_send_command(lcd, _LCD_CLEAR);
    lcd_send_command(lcd, _LCD_RETURN_HOME);
}

/***************************************************************************************************
 *  Function: lcd_send_chr
 *  Description:
 *      This function sends a character to the LCD module for display. It handles both 4-bit and
 *      8-bit LCD modes.
 *  Parameters:
 *      lcd: Pointer to an lcd_t structure containing LCD pin configurations.
 *      character: Character to be displayed on the LCD.
 *  Return Value:
 *      None
 ***************************************************************************************************/
void lcd_send_chr(const lcd_t *lcd, uint8_t character) {
    GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_rs, LCD_RS_HIGH); // RS = 1 for data

    if (lcd->lcd_connection == _4_BIT) {
        // Send upper 4 bits
        uint8_t count;
        for (count = 4; count < 8; count++) {
            GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_data_pins[count - 4], (character >> count) & 0x01);
        }
        GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_en, LCD_EN_HIGH);
        SysCtlDelay(200); // Small delay
        GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_en, LCD_EN_LOW);
        SysCtlDelay(200); // Delay for data to be written

        // Send lower 4 bits
        for (count = 0; count < 4; count++) {
            GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_data_pins[count], (character >> count) & 0x01);
        }
        GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_en, LCD_EN_HIGH);
        SysCtlDelay(200); // Small delay
        GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_en, LCD_EN_LOW);
        SysCtlDelay(200); // Delay for data to be written
    }
    // Implement the 8-bit mode part if needed
}

// Implement the remaining functions similarly

void lcd_send_string(const lcd_t *lcd, uint8_t* data) {
    uint8_t index = 0;

    GPIOPinWrite(GPIO_PORT_BASE, lcd->lcd_rs, LCD_RS_HIGH); // RS = 1 for data

    while (data[index] != '\0') {
        lcd_send_chr(lcd, data[index]);
        index++;
    }
}
