#ifndef _USART_H
#define _USART_H
#include "delay.h"
#include "stdio.h"

void uart_init(u32 bound);
void usart_rxbuf_reset();
#endif

