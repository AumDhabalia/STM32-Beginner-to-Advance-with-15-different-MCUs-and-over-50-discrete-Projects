#include "timer.h"

void TIM2_Init(void)
{
	//Enable Timer 2 clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	//Configure Timer 2 with 1MHz frequency or 1us delay
	TIM2->PSC = 72 - 1; //Prescalar = 71, 1MHz frequency
	TIM2->ARR = 0xFFFF; //ARR = 0
	TIM2->CNT = 0; //Set counter to 0
	TIM2->CR1 |= TIM_CR1_CEN; //Enable Timer 2
}

//Delay function for microsecond count
void delay_us(uint32_t us)
{
	uint32_t start = TIM2->CNT;
	while((TIM2->CNT - start) < us);
}

//Delay function for millisecond count
void delay_ms(uint32_t ms)
{
	while(ms--)
	{
		uint32_t start = TIM2->CNT;
		while((TIM2->CNT - start) < 1000);
	}
}