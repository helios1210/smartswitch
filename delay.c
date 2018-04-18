#include "delay.h"
extern uint32_t TIME;
void delay_10us(uint32_t t){
	TIME = t;
  while (TIME);
}


void delay_init(){
	if (SysTick_Config(SystemCoreClock / 100000))
		while (1);
}
