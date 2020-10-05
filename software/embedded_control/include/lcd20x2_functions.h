#ifndef LCD20X2_FUNCTIONS_H_INCLUDED
#define LCD20X2_FUNCTIONS_H_INCLUDED

/*****************************************/
//pin defines
#define LCD_PORT  GPIOB
#define RS        GPIO_Pin_0
#define RW        GPIO_Pin_1
#define START     GPIO_Pin_5
#define DB_0      GPIO_Pin_6
#define DB_1      GPIO_Pin_7
#define DB_2      GPIO_Pin_8
#define DB_3      GPIO_Pin_9
#define DB_4      GPIO_Pin_10
#define DB_5      GPIO_Pin_11
#define DB_6      GPIO_Pin_12
#define DB_7      GPIO_Pin_13
#define DB_ALL    (DB_0| DB_1 |DB_2| DB_3| DB_4| DB_5| DB_6| DB_7) // all data pins
#define LCD_ALL   (DB_0| DB_1 |DB_2| DB_3| DB_4| DB_5| DB_6| DB_7| RS| RW| START)// all pins
/*****************************************/
//command defines
#define clear_display         ((uint8_t) 0x01)
#define return_home           ((uint8_t) 0x02)
#define entry_mode            ((uint8_t) 0x06)
#define display_on_off        ((uint8_t) 0x08)
#define cursor_display_shift  ((uint8_t) 0x10)
#define function_set          ((uint8_t) 0x20)
#define set_position          ((uint8_t) 0x80)

//command parameters (have to included in the command function with a logical of (|)
//function set:
#define DL_8bit         ((uint8_t) 0x10)
#define DL_4bit         ((uint8_t) 0x00)
#define lines_1         ((uint8_t) 0x00)
#define lines_2         ((uint8_t) 0x08)
#define char_size5x10   ((uint8_t) 0x04)
#define char_size5x8    ((uint8_t) 0x00)

//display on/off
#define display_on      ((uint8_t) 0x04)
#define display_off     ((uint8_t) 0x00)
#define cursor_on       ((uint8_t) 0x02)
#define cursor_off      ((uint8_t) 0x00)
#define blinkey_on      ((uint8_t) 0x01)
#define blinkey_off     ((uint8_t) 0x00)

//entry mode
#define nextchar_left   ((uint8_t) 0x00)
#define nextchar_right  ((uint8_t) 0x02)
#define shift_display    ((uint8_t) 0x01)
#define shift_cursor    ((uint8_t) 0x00)

//cursor/display shift
#define move_display    ((uint8_t) 0x08)
#define mover_cursor    ((uint8_t) 0x00)
#define move_left       ((uint8_t) 0x00)
#define move_right      ((uint8_t) 0x06)

//characters
#define char_space      ((uint8_t) 0x20)
/*****************************************/

//prototypes
void toggle_START (void);
void send_cmd(uint8_t CMD);
void write_byte(uint8_t byte);
void write_char(uint8_t letter);
void write_string(char *lcd_string);
void to_line1 (void);
void to_line2 (void);
/*****************************************/
//decralations
char *lcd_string;

#endif /* LCD20X2_FUNCTIONS_H_INCLUDED */
