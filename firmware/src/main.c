#include <avr/io.h>

#include "../include/usart.h"
#include "../include/gpio.h"
#include "../include/commands.h"

int main(void)
{
    char cmd[7];
    int i;

    USART_Init();
    GPIO_Init();

    while(1)
    {
        for(i = 0; i < 6; i++)
        {
            cmd[i] = USART_ReceiveChar();
        }

        cmd[6] = '\0';

        ProcessCommand(cmd);
    }

    return 0;
}