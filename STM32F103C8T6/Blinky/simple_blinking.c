/*
This program is for blinking an LED at time period of 0.5 seconds.
LED built-in on the BluePill board is taken (LED Pin may vary on different BluePill Supplier).
Refer to RM0008 reference manual as well as STM32F103C8T6 datasheet.
*/

#include "stm32f10x.h"

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
		
	//Enable Clock for GPIOB
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	//Configure PB6 and PB7 as General-Purpose Output Push-Pull (2 MHz)
	GPIOB->CRL &= ~(0x0F00); // Clear bits for PB2
	GPIOB->CRL |= 0x0200; // Set as Output (2 MHz, Push-Pull)
	
	//Turn off PB2 initially
	GPIOB->BSRR |= GPIO_BSRR_BR2;

	while(1)
	{
		GPIOB->BSRR |= GPIO_BSRR_BS2; //Set PB6   (LED ON)
		for(volatile int i = 0; i < 500000; i++); // 500 ms = 500,000 us
		//Delay can be changed as per user requirement...
		GPIOB->BSRR |= GPIO_BSRR_BR2; //Reset PB6 (LED OFF)
		for(volatile int i = 0;i < 500000;i++);*/
	}
}
