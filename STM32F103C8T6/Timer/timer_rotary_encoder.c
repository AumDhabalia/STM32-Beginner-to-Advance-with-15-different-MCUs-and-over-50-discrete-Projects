/*
Initial steps before starting user code.
*/

#include "stm32f103xb.h"

int8_t encoder_value = 0;
uint16_t current_pos = 0;

int main(void)
{
	//Initialize HSE 8 MHz
	//Enable HSE
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	
	//Configure Flash Latency
	FLASH->ACR |= FLASH_ACR_LATENCY_2;
	
	//Configure PLL
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE; // RCC->CFGR |= 0x0001 0000;
	RCC->CFGR |= RCC_CFGR_PLLMULL9;   // RCC->CFGR |= 0x001C 0000;
	
	//Enable PLL
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	
	//Set PLL as System Clock
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
	
	//Configure AHB, APB1, APB2 Prescaler
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;   // AHB Prescaler = 1 (72 MHz)
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;  // APB1 Prescaler = 2 (36 MHz max)
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;  // APB2 Prescaler = 1 (72 MHz)
	
	//Update System Core Clock variable
	SystemCoreClock = 72000000;
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	GPIOA->CRL &= ~(0x00000FFF);
	GPIOA->CRL |= GPIO_CRL_CNF0_1 | GPIO_CRL_CNF1_1 | GPIO_CRL_CNF2_1;
	GPIOA->ODR |= GPIO_ODR_ODR0 | GPIO_ODR_ODR1 | GPIO_ODR_ODR2;
	
	TIM2->ARR = 0xFFFF; //ARR = 65536
	TIM2->CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0; //Capture on TI1 and TI2
    TIM2->CCMR1 |= TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1 | TIM_CCMR1_IC2F_0 | TIM_CCMR1_IC2F_1; //Input filter = 10
    TIM2->CCER |= TIM_CCER_CC1P; //Capture on falling edge of TI1
	TIM2->SMCR |= TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0;
	TIM2->CR1 |= TIM_CR1_CEN;
	
	//User Code initialization...
	while(1)
	{
		encoder_value = TIM2->CNT;
		current_pos = encoder_value / 4;
		for(uint32_t i = 0;i < 50000;i++);
	}
	
	return 0;
}
