#ifndef INC_HAL_LCD_LCD_H_
#define INC_HAL_LCD_LCD_H_



/* Section : Includes */
#include <stdint.h>
/*  Section : Macro declarations */
#define _LCD_CLEAR                                   0x01
#define _LCD_RETURN_HOME                             0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF                0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON                 0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF                0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON                 0x07
#define _LCD_ENTRY_MODE                              0x06
#define _LCD_CURSOR_OFF_DISPLAY_ON                   0x0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF                  0x08
#define _LCD_CUROSR_ON_BLINK_ON                      0x0F
#define _LCD_CURSOR_ON_BLINK_ON                      0x0E
#define _LCD_DISPLAY_SHIFT_LEFT                      0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                     0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF     0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON      0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF      0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON       0x0F
#define _LCD_8BIT_2LINE                              0x38
#define _LCD_4BIT_2LINE                              0x28
#define _LCD_8BIT_1LINE                              0x30
#define _LCD_4BIT_1LINE                              0x20
#define _LCD_CGRAM_START                             0x40
#define _LCD_DDRAM_START                             0x80
/*  Section : Macro Functions declarations */

#define GPIO_PORT_BASE GPIO_PORTB_BASE
#define SYSCTL_PERIPH_GPIO_BASE SYSCTL_PERIPH_GPIOB
#define LCD_EN_HIGH 1
#define LCD_EN_LOW  0
#define LCD_RS_HIGH 1
#define LCD_RS_LOW  0
/*  Section : Data types declarations */
typedef enum {
    ROW0 = 0,
    ROW1,
    ROW2,
    ROW3
} row_t;

typedef enum {
    COL0 = 0,COL1,COL2,COL3,COL4,COL5,COL6,COL7,COL8,COL9,
    COL10,COL11,COL12,COL13,COL14,COL15,COL16,COL17,COL18,COL19
}col_t;

typedef enum {
    _4_BIT = 0,
    _8_BIT
} lcd_connection_t;

typedef struct {
    uint8_t lcd_en;
    uint8_t lcd_rs;
    uint8_t lcd_data_pins[8];
    lcd_connection_t lcd_connection;
} lcd_t;

void lcd_init(const lcd_t *lcd);
void lcd_send_command(const lcd_t *lcd, uint8_t command);
void lcd_send_chr(const lcd_t *lcd, uint8_t character);
void lcd_send_chr_pos(const lcd_t *lcd, uint8_t character, row_t row, col_t col);
void lcd_send_string(const lcd_t *lcd, uint8_t* data);
void lcd_send_string_pos(const lcd_t *lcd, uint8_t * data, row_t row, col_t col);
void lcd_send_number_pos(const lcd_t *lcd, uint16_t num, row_t row, col_t col);
void lcd_send_custome_chr_pos(const lcd_t *lcd, uint8_t * arr, uint8_t mem_pos, row_t row, col_t col);



#endif /* INC_HAL_LCD_LCD_H_ */
