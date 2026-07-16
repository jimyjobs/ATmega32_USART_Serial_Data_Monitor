#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../include/usart.h"
#include "../include/gpio.h"
#include "../include/commands.h"
#include "../include/lcd.h"

int main(void)
{
    char cmd[20];
    char c;
    int i = 0;

    USART_Init();
    GPIO_Init();
    LCD_Init();

    /* Startup Message */
    LCD_Clear();
    LCD_SetCursor(1,1);
    LCD_Char('U');
    LCD_String("USART READY");

    LCD_SetCursor(2,1);
    LCD_Char('M');
    LCD_String("Monitoring...");

    while(1)
    {

        /* Check if a serial character has been received */
        if(UCSRA & (1<<RXC))
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
    }

    return 0;
}