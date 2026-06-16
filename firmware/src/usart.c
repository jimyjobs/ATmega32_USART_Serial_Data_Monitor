#include <avr/io.h>
#include "../include/usart.h"

#define F_CPU 8000000UL
#define BAUD 9600
#define UBRR_VALUE 51

void USART_Init(void)
{
    UBRRH = (unsigned char)(UBRR_VALUE >> 8);
    UBRRL = (unsigned char)UBRR_VALUE;

    UCSRB = (1 << TXEN) | (1 << RXEN);

    UCSRC = (1 << URSEL) |
            (1 << UCSZ1) |
            (1 << UCSZ0); // 8-bit data
}

void USART_SendChar(char data)
{
    while (!(UCSRA & (1 << UDRE)));

    UDR = data;
}

void USART_SendString(const char *str)
{
    while (*str)
    {
        USART_SendChar(*str++);
    }
}

char USART_ReceiveChar(void)
{
    while (!(UCSRA & (1 << RXC)));

    return UDR;
}