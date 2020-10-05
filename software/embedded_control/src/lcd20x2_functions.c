/* *******************************************************************
file        : lcd 20x2
version     : 1.0
author      : harm hongerkamp
start date  : 2-2-2017
end date    : -

purpose     : library for hd44780a00 driven lcd screen.

**********************************************************************
wiring: can be found in the header file.


**********************************************************************/

#include "stm32f10x_conf.h"
#include "lcd20x2_functions.h"


void toggle_START(void)
//input : -
//output: -
//effect: toggles startbit and resets all the I/O pins.
{
    delay(5);
    GPIO_ResetBits(LCD_PORT, START);
    delay(5);
    GPIO_SetBits(LCD_PORT, START);
}

void send_cmd (uint8_t CMD)
//input  : 8-bits integer cmd
//output : -
//effect : sends command to LCD screen
{
    GPIO_SetBits(LCD_PORT, RW |RS); //sets r/w and rs to 0
    write_byte(CMD); //sets the command on the databus
    toggle_START();  //send command
}

void write_byte(uint8_t byte)
//input : 8-bits byte
//output: -
//effect: sets the byte on the databus
{
    GPIO_SetBits(LCD_PORT, DB_ALL);//DATABUS IS 0
    if(byte & 0x80)
    {
        GPIO_ResetBits(LCD_PORT, DB_7);
    }

    if(byte & 0x40)
    {
        GPIO_ResetBits(LCD_PORT, DB_6);
    }

    if(byte & 0x20)
    {
        GPIO_ResetBits(LCD_PORT, DB_5);
    }

    if(byte & 0x10)
    {
        GPIO_ResetBits(LCD_PORT, DB_4);
    }

    if(byte & 0x08)
    {
        GPIO_ResetBits(LCD_PORT, DB_3);
    }

    if(byte & 0x04)
    {
        GPIO_ResetBits(LCD_PORT, DB_2);
    }

    if(byte & 0x02)
    {
        GPIO_ResetBits(LCD_PORT, DB_1);
    }

    if(byte & 0x01)
    {
        GPIO_ResetBits(LCD_PORT, DB_0);
    }
}

void write_char(uint8_t letter)
//input : 8 bits char
//output: -
//effect: writes a character on the display on the position determent by set position command or last character
{
    GPIO_ResetBits(LCD_PORT, RS);
    GPIO_SetBits(LCD_PORT, RW);
    write_byte(letter);
    toggle_START();
    GPIO_SetBits(LCD_PORT, RS);
}

void write_string(char *lcd_string)
//input : string
//output: -
//effect: prints a string
{
    uint8_t i, j;
    for(i=0; lcd_string[i]; i++)
    {
        j = (uint8_t) lcd_string[i];
        write_char(j);
    }
}

void to_line1(void)
{
    send_cmd(set_position | 0x00);
}

void to_line2(void)
{
    send_cmd(set_position | 0x40);
}
