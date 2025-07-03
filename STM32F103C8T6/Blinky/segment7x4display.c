/*
Project Title : 7 Segment Display
Author : Aum Dhabalia
Date : 10/04/2025
This program is for interfacing 4 x 7 Segment display. The display module used is common cathode type. Digital HIGH is sent for flashing diodes of the display.
Here, PA0 to PA7 are connected to the display module from Pin A to G with dot at PA7 and CC to GND. PB12 to PB15 pins are used for digit selection.
Refer RM0008 reference manual as well as STM32F103C8T6 datasheet.
Refer stm32f10x.h file for macros used.
-------------------------------------------------------
| NUM | PA7 | PA6 | PA5 | PA4 | PA3 | PA2 | PA1 | PA0 |
-------------------------------------------------------
|     | Dot |  G  |  F  |  E  |  D  |  C  |  B  |  A  |
-------------------------------------------------------
|  0  | 1/0 |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
|  1  | 1/0 |  0  |  0  |  0  |  0  |  1  |  1  |  0  |
|  2  | 1/0 |  1  |  0  |  1  |  1  |  0  |  1  |  1  |
|  3  | 1/0 |  1  |  0  |  0  |  1  |  1  |  1  |  1  |
|  4  | 1/0 |  1  |  1  |  0  |  0  |  1  |  1  |  0  |
|  5  | 1/0 |  1  |  1  |  0  |  1  |  1  |  0  |  1  |
|  6  | 1/0 |  1  |  1  |  1  |  1  |  1  |  0  |  1  |
|  7  | 1/0 |  0  |  0  |  0  |  0  |  1  |  1  |  1  |
|  8  | 1/0 |  1  |  1  |  1  |  1  |  1  |  1  |  1  |
|  9  | 1/0 |  1  |  1  |  0  |  1  |  1  |  1  |  1  |
-------------------------------------------------------
PB15 -> Digit 0
PB14 -> Digit 1
PB13 -> Digit 2
PB12 -> Digit 3
*/

#include "stm32f10x.h"

volatile char num[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

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

	//Enable GPIOA & GPIOB
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	//Configure PA0 to PA7 and PB4 to PB7 as Genral-Purpose Output Push-Pull mode (2 MHz)
	GPIOA->CRL &= ~(0xFFFFFFFF);
	GPIOB->CRH &= ~(0xFFFF0000);

	GPIOA->CRL |= (0x22222222);
	GPIOB->CRH |= (0x22220000);
	
	//User Code initialization...
	while(1)
	{
		volatile int count = 0;

		while(count < 10000)
		{
			volatile int digit0 = count%10;         //Units digit at PB15
			volatile int digit1 = (count%100)/10;   //Tens LS digit at PB14
			volatile int digit2 = (count%1000)/100; //Hundreds digit at PB13 
			volatile int digit3 = count/1000;       //Thousands digit at PB12
			
			//Time delay of 1000 ms...
			//The delay here is adjusted based on the instruction cycles. Here, 910 iterations are executed instead of 1000.
			//The reason being synchronous to the real time clock measurements.
			for(volatile int j = 0;j < 910;j++)
			{
				GPIOB->ODR = 0x00007000;
				GPIOA->ODR = num[digit0];
				//Units Digit for 1 ms
				for(volatile int i = 0;i < 1000;i++);

				GPIOB->ODR = 0x0000B000;
				GPIOA->ODR = num[digit1];
				//Tens Digit for 1 ms
				for(volatile int i = 0;i < 1000;i++);

				GPIOB->ODR = 0x0000D000;
				GPIOA->ODR = num[digit2];
				//Hundreds Digit for 1 ms
				for(volatile int i = 0;i < 1000;i++);

				GPIOB->ODR = 0x0000E000;
				GPIOA->ODR = num[digit3];
				//Thousands Digit for 1 ms
				for(volatile int i = 0;i < 1000;i++);
			}
			count++;
		}
	}
}
