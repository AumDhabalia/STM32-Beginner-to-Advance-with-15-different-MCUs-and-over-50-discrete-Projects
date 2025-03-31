/*
Project Title : Random LED Flashing
Author : Aum Dhabalia
Date : 31/03/2025
This program is for blinking LEDs randomly.
Here, 8 LEDs are taken for application of random flashing.
8 LEDs are connected with 220 ohm resistor from PA0 to PA7.
Refer RM0008 reference manual as well as STM32F103C8T6 datasheet.
Refer stm32f10x.h file for macros used.

PA7 to PA0 = 8 bit random number generated.
*/
#include "stm32f10x.h"

int main(void)
{
	//Initialize Clock
	//Enable Clock
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	
	//Configure Flash Latency
	FLASH->ACR |= FLASH_ACR_LATENCY_2;
	
	//Configure PLL
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE; // RCC->CFGR |= 0x0001 0000
	RCC->CFGR |= RCC_CFGR_PLLMULL9;   // RCC->CFGR |= 0x001C 0000
	
	//Enable PLL
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLON));
	
	//Set PLL as system clock
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
	
	//Configure AHB, APB1,APB2 Buses
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; // AHB Prescalar = 1
	RCC->CFGR |= RCC_CFGR_PPRE1_2;   // APB1 Prescalar = 2
	RCC->CFGR |= RCC_CFGR_PPRE2_1;   // APB2 Prescalar = 1
	
	//Update System Core Clock
	SystemCoreClock = 72000000;
	
	//User Code Initialization
	//Enable GPIOA
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	//Configure PA0 to PA&
	GPIOA->CRL &= 0;
	GPIOA->CRL |= (0x22222222);
	
	//Set PA0 to PA7 to 1
	GPIOA->ODR |= (0xFF);
	
	//Enable SysTIck Timer
	SysTick->LOAD = 0xFFFFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
	
	//User Code Control Loop
	while(1)
	{
		uint8_t random_value = (SysTick->VAL % 255) + 1;
		GPIOA->ODR = (GPIOA->ODR & 0xFF00) | random_value;
		for(volatile int i = 0;i < 2000000;i++);
	}
	return 0;
}
