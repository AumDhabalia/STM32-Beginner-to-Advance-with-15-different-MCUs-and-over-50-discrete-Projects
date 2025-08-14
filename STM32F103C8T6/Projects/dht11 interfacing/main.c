/*
==============================================================================
Project Title : Temperature sensing using DHT11
Author : Aum Dhabalia
Date : 14/08/2025
Components : STM32F103C8T6 BluePill, DHT11 Sensor, 4x7 Common Cathode Segment Display Module
==============================================================================
Description :-
This project describes how to interface DHT11 temperature and humidity sensor with BluePill board and display the readings on 4x7 Segment display module. DHT11 uses
single wire data communication where it uses single GPIO Pin to act as input and output sequentially.
Refer to the datasheet for details.
The program is written in bare-metal with modular blocks for each component used.

DHT11 -> dht11.c, dht11.h
4x7 Segment display module -> segment_display.c, segment_display.h
BluePill -> main.c, main.h
BluePill timer -> timer.c, timer.h

All the header files are included in main.h file
*/

#include "main.h"

static uint8_t digit[4] = {0,0,0,0};
static uint8_t dht11[5] = {0,0,0,0,0};

int main(void)
{
	RCC_Configuration();
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
	
	//Configure TIM2
	TIM2->PSC = 72 - 1; //Prescalar = 71, 1MHz frequency
	TIM2->ARR = 0xFFFF; //ARR = 0
	TIM2->CNT = 0; //Set counter to 0
	TIM2->CR1 |= TIM_CR1_CEN; //Enable Timer 2
	
	//Initialize 4x7 Segment display
	Segment7x4_Display_Init();
	
	//Configure PA8 as Output Push Pull...
	GPIOA->CRH &= ~(0x0000000F);
	GPIOA->CRH |=  (0x00000002);
	//Set to HIGH as DHT11 is kept in idle state when no data is received...
	GPIOA->BSRR = GPIO_BSRR_BS8;
	
	while(1)
	{
		//Initialize and start DHT11 sensor...
		Start_DHT11();
		//Read DHT11 sensor...
		Read_DHT11(digit,dht11);
		//Display temperature...
		Display_Temperature(digit);
	}
}

void RCC_Configuration(void)
{
	//Initialze 8MHz clock
	//Enable HSE
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	
	//Configure Flash Latency
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
	
	//Configure AHB, APB1, APB2 Prescalar
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
	
	//Update System Core Clock variable
	SystemCoreClock = 72000000;
}
