#include <avr/io.h>
#include <string.h>

#include "../include/usart.h"
#include "../include/commands.h"
#include "../include/lcd.h"

void ProcessCommand(char *cmd)
{
    /*---------------- HELLO ----------------*/
    if(strcmp(cmd, "HELLO") == 0)
    {
        USART_SendString("HELLO\r\n");

        LCD_Clear();

        LCD_SetCursor(1,1);
        LCD_String("HELLO");

        LCD_SetCursor(2,1);
        LCD_String("WELCOME");

        /* Flash Command LED */
        PORTB |= (1<<PB2);

        for(volatile long i=0;i<50000;i++);

        PORTB &= ~(1<<PB2);
    }

    /*---------------- STATUS ----------------*/
    else if(strcmp(cmd,"STATUS") == 0)
    {
        USART_SendString("\r\n");

        USART_SendString("SW1=");
        USART_SendChar((PINA&(1<<PA0)) ? '1':'0');
        USART_SendString("\r\n");

        USART_SendString("SW2=");
        USART_SendChar((PINA&(1<<PA1)) ? '1':'0');
        USART_SendString("\r\n");

        USART_SendString("SW3=");
        USART_SendChar((PINA&(1<<PA2)) ? '1':'0');
        USART_SendString("\r\n");

        LCD_Clear();

        LCD_SetCursor(1,1);
        LCD_String("SW1=");
        LCD_Char((PINA&(1<<PA0)) ? '1':'0');

        LCD_String(" SW2=");
        LCD_Char((PINA&(1<<PA1)) ? '1':'0');

        LCD_SetCursor(2,1);
        LCD_String("SW3=");
        LCD_Char((PINA&(1<<PA2)) ? '1':'0');

        /* Flash Command LED */
        PORTB |= (1<<PB2);

        for(volatile long i=0;i<50000;i++);

        PORTB &= ~(1<<PB2);
    }

    /*---------------- INVALID COMMAND ----------------*/
    else
    {
        USART_SendString("\r\nINVALID COMMAND\r\n");

        LCD_Clear();

        LCD_SetCursor(1,1);
        LCD_String("INVALID");

        LCD_SetCursor(2,1);
        LCD_String("COMMAND");
    }
}