#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../include/lcd.h"

/*----------------------------------------------------------
  Send 4 bits to LCD
-----------------------------------------------------------*/
static void LCD_SendNibble(unsigned char nibble)
{
    /* Clear data pins */
    PORTC &= ~((1<<LCD_D4) |
               (1<<LCD_D5) |
               (1<<LCD_D6) |
               (1<<LCD_D7));

    if(nibble & 0x01) PORTC |= (1<<LCD_D4);
    if(nibble & 0x02) PORTC |= (1<<LCD_D5);
    if(nibble & 0x04) PORTC |= (1<<LCD_D6);
    if(nibble & 0x08) PORTC |= (1<<LCD_D7);

    /* Enable Pulse */
    PORTC |= (1<<LCD_EN);
    _delay_us(5);

    PORTC &= ~(1<<LCD_EN);
    _delay_us(200);
}

/*----------------------------------------------------------
  Send Command
-----------------------------------------------------------*/
void LCD_Command(unsigned char cmd)
{
    PORTC &= ~(1<<LCD_RS);      // Command Mode

    LCD_SendNibble(cmd >> 4);
    LCD_SendNibble(cmd & 0x0F);

    _delay_ms(2);
}

/*----------------------------------------------------------
  Send Character
-----------------------------------------------------------*/
void LCD_Char(unsigned char data)
{
    PORTC |= (1<<LCD_RS);       // Data Mode

    LCD_SendNibble(data >> 4);
    LCD_SendNibble(data & 0x0F);

    _delay_ms(2);
}

/*----------------------------------------------------------
  Send String
-----------------------------------------------------------*/
void LCD_String(const char *str)
{
    _delay_ms(2);
    LCD_Char(*str);      // First character
    str++;  
    while(*str)
    {
        LCD_Char(*str);
        str++;
    }
}

/*----------------------------------------------------------
  Clear LCD
-----------------------------------------------------------*/
void LCD_Clear(void)
{
    LCD_Command(0x01);
    _delay_ms(2);
}

/*----------------------------------------------------------
  Cursor Position
-----------------------------------------------------------*/
void LCD_SetCursor(unsigned char row, unsigned char col)
{
    unsigned char address;

    if(row == 1)
        address = 0x80 + (col - 1);
    else
        address = 0xC0 + (col - 1);

    LCD_Command(address);
}

/*----------------------------------------------------------
  LCD Initialization
-----------------------------------------------------------*/
void LCD_Init(void)
{
    /* Configure LCD pins as outputs */

    DDRC |= (1<<LCD_RS) |
            (1<<LCD_EN) |
            (1<<LCD_D4) |
            (1<<LCD_D5) |
            (1<<LCD_D6) |
            (1<<LCD_D7);

    _delay_ms(20);

    /* Initialize LCD in 4-bit mode */

    LCD_SendNibble(0x03);
    _delay_ms(5);

    LCD_SendNibble(0x03);
    _delay_us(150);

    LCD_SendNibble(0x03);

    LCD_SendNibble(0x02);

    /* Function Set */
    LCD_Command(0x28);

    /* Display ON */
    LCD_Command(0x0C);

    /* Entry Mode */
    LCD_Command(0x06);

    /* Clear Display */
    LCD_Command(0x01);

    _delay_ms(2);
}