#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"

extern uint8_t usart_rx_n;
extern uint8_t usart_rxbuf_over;
int main(void)
{
	delay_init();
	uart_init(115200);
  /* Infinite loop */
  while (1)
  {
		
		if(usart_rxbuf_over){
		
			 usart_rxbuf_reset();
		}
		
  }
}


