#include <avr/io.h>

#include "../include/usart.h"
#include "../include/gpio.h"
#include "../include/commands.h"

int main(void)
{
    char cmd[20];
    char c;
    int i = 0;

    USART_Init();
    GPIO_Init();

    while(1)
    {        
        c = USART_ReceiveChar();

        if(c == '\r' || c == '\n')
        {
            cmd[i] = '\0';

            if(i > 0)
            {
                ProcessCommand(cmd);
            }

            i = 0;
        }
        else
        {
            if(i < sizeof(cmd) - 1)
            {
                cmd[i++] = c;
            }
        }
    }

    return 0;
}
