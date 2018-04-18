#include "usart.h"


uint8_t usart_rxbuf_over=0;     //接收buf标志，0未满，1已满
uint8_t usart_rxbuf_start=1;    //首次开始接收标志，1准备开始，0非首次
uint8_t usart_rx_n=0;
uint8_t RX_BUF[1024];


extern uint32_t TIME;

int fputc(int ch, FILE *f)
{      
  USART_SendData(USART1,(uint8_t)ch);
  while(USART_GetFlagStatus(USART1, USART_FLAG_TXE)==RESET);   
	return ch;
}


void uart_init(u32 bound){
 
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);
  

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
   
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		
	NVIC_Init(&NVIC_InitStructure);
  


	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART1, &USART_InitStructure);
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  USART_Cmd(USART1, ENABLE);                   

}

void USART1_IRQHandler(void){  
      unsigned char RxData;  
      if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {  
            USART_ClearITPendingBit(USART1, USART_IT_RXNE);  
            RxData=USART_ReceiveData(USART1);
            if(TIME|usart_rxbuf_start){
						usart_rxbuf_start=0;
						RX_BUF[usart_rx_n]=RxData;
						usart_rx_n++;
						TIME=100;
						}else{
						USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
						usart_rxbuf_over=1;
						}
      }  
} 

void usart_rxbuf_reset(){
uint16_t i=0;
for(i=0;i<usart_rxbuf_over;i++)RX_BUF[i]=0;
usart_rxbuf_over=0;
usart_rx_n=0;
usart_rxbuf_start=1;
USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

