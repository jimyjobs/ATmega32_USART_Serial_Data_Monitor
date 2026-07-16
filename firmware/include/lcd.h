#ifndef LCD_H
#define LCD_H

#include <avr/io.h>

/* LCD Control Pins */
#define LCD_RS PC0
#define LCD_RW PC1
#define LCD_EN PC2

/* LCD Data Pins */
#define LCD_D4 PC3
#define LCD_D5 PC4
#define LCD_D6 PC5
#define LCD_D7 PC6

/* Function Prototypes */

void LCD_Init(void);

void LCD_Command(unsigned char cmd);

void LCD_Char(unsigned char data);

void LCD_String(const char *str);

void LCD_Clear(void);

void LCD_SetCursor(unsigned char row, unsigned char col);

#endif