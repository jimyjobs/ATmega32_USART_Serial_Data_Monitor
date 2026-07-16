#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../include/gpio.h"


void GPIO_Init(void)
{
    /* Configure Switches as Inputs */
    DDRA &= ~((1<<PA0) | (1<<PA1) | (1<<PA2));

    /* Enable Internal Pull-up Resistors */
    PORTA |= (1<<PA0) | (1<<PA1) | (1<<PA2);

    /* Configure LEDs as Outputs */
    DDRB |= (1<<PB1) | (1<<PB2);

    /* Status LED ON */
    PORTB |= (1<<PB1);

    /* Command LED OFF */
    PORTB &= ~(1<<PB2);
}