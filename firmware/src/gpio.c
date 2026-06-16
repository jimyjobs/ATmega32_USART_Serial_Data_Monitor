#include <avr/io.h>
#include "../include/gpio.h"

void GPIO_Init(void)
{
    // Switches
    DDRA &= ~((1<<PA0) | (1<<PA1) | (1<<PA2));

    // LEDs
    DDRB |= (1<<PB1) | (1<<PB2);

    // Status LED ON
    PORTB |= (1<<PB1);

    // Command LED OFF
    PORTB &= ~(1<<PB2);
}