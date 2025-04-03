/*
Project Title : LED Blink on PB2
Author : Aum Dhabalia
Date : 31/03/2025
This program is for setting up timers for generating time periods rather than using delays in main thread.
A built-in LED connected to PB2 is blinked with time period of 1000 ms.
Refer RM0008 reference manual as well as STM32F103C8T6 datasheet.
Refer to stm32f10x.h file for macros used.
*/

#include "stm32f10x.h"

int main(void)
{
	//Initialize HSE 8 MHz
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	
	// Configure Flash Latency
	FLASH->ACR |= FLASH_ACR_LATENCY_2;
	
	//Configure PLL
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE;
	RCC->CFGR |= RCC_CFGR_PLLMULL9;
	
	//Enable PLL
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	
	//Set PLL as System Clock
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
	
	//Configure AHB, APB1, APB2 Prescaler
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
	
	//Update System Core Clock variable
	SystemCoreClock = 72000000;
	
	//Enable Clock for GPIOB and TIM2
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	//Configure PB2 as General-Purpose Output Push-Pull (2 MHz)
	GPIOB->CRL &= ~(0x00000F00); // Clear bits for PB2
	GPIOB->CRL |=  (0x00000200);  // Set as Output (2 MHz, Push-Pull)
	
	//Configure Timer 2
	//Set Prescalar
	TIM2->PSC = 7200-1; //Prescalar to 72 MHz/7200 = 10kHz
	
	//Set Auto Reload Register
	TIM2->ARR = 10000-1; //Auto reload for 1000 ms ; 10,000 ticks = 10kHz
	
	//Enable update interrupt
	TIM2->DIER = TIM_DIER_UIE;
	
	//Enable NVIC for TIM2
	NVIC_EnableIRQ(TIM2_IRQn);
	
	//Start Timer 2
	TIM2->CR1 |= TIM_CR1_CEN;
	
	while(1)
	{}
}

void TIM2_IRQHandler(void)
{
	if(TIM2->SR & TIM_SR_UIF)
	{
		TIM2->SR &= ~TIM_SR_UIF;
		GPIOB->ODR ^= GPIO_ODR_ODR2;
	}
}
