#ifndef USART_H
#define USART_H

void USART_Init(void);
void USART_SendChar(char data);
void USART_SendString(const char *str);

char USART_ReceiveChar(void);
/* Returns non-zero when data is available */
unsigned char USART_DataAvailable(void);

#endif