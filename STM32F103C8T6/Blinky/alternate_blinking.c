/*
This program is for blinking two LEDs alternately at constant delay.
Two LEDs at PB6 and PB7 are taken with 220ohm resistor between LED and pin.
Refer to RM0008 reference manual as well as STM32F103C8T6 datasheet.
Refer to stm32f10x.h file for macros used.
-------------------
| PB6 ON  PB7 OFF |
| Delay 500 ms    |
| PB6 OFF  PB7 ON |
| Delay 500 ms    |
-------------------
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
	GPIOB->CRL &= ~(0x0F000000 | 0xF0000000); // Clear bits
	GPIOB->CRL |= (0x02000000 | 0x20000000); // Set as Output (2 MHz, Push-Pull)

	while(1)
	{
		GPIOB->BSRR |= (GPIO_BSRR_BS6 | GPIO_BSRR_BR7); //Set PB6 (LED ON) & Reset PB7 (LED OFF)
		for(volatile int i = 0; i < 500000; i++); // 500 ms = 500,000 us
		
		GPIOB->BSRR |= (GPIO_BSRR_BR6 | GPIO_BSRR_BS7); //Reset PB6 (LED OFF) & Set PB7 (LED ON)
		for(volatile int i = 0;i < 500000;i++); // 500 ms = 500,000 us
	}
}
