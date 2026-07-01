#include <avr/io.h>
#include <string.h>

#include "../include/usart.h"
#include "../include/commands.h"

void ProcessCommand(char *cmd)
{
    if(strcmp(cmd, "STATUS") == 0)
    {
        USART_SendString("\r\n");

        USART_SendString("SW1=");
        USART_SendChar((PINA & (1<<PA0)) ? '1' : '0');
        USART_SendString("\r\n");

        USART_SendString("SW2=");
        USART_SendChar((PINA & (1<<PA1)) ? '1' : '0');
        USART_SendString("\r\n");

        USART_SendString("SW3=");
        USART_SendChar((PINA & (1<<PA2)) ? '1' : '0');
        USART_SendString("\r\n");

        /* Flash Command LED */
        PORTB |= (1<<PB2);

        for(volatile long i = 0; i < 50000; i++);

        PORTB &= ~(1<<PB2);
    }
    else if(strcmp(cmd, "HELLO") == 0)
    {
        USART_SendString("HELLO\r\n");
    }
    else
    {
        USART_SendString("\r\nINVALID COMMAND\r\n");
    }
}
