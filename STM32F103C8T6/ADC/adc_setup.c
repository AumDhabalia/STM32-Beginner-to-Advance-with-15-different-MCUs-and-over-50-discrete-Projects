/*
Project Title : ADC Setup & Testing
Author : Aum Dhabalia
Date : 03/07/2025
This program is for setting up and testing the ADC module within the BluePill and to learn about the ADC, its modes, its registers, etc.
ADC works by reading the variable voltage values received from the potentiomenter.
In this program, the ADC is setup and tested using a 10k ohm potentiometer. The pot has three terminals 
*/

#include "stm32f10x.h"

volatile uint16_t val = 0;
volatile float out = 0;

void ADC1_2_IRQHandler(void);

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
	
	//Enable ADC1, GPIOA, AFIO
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	//Set ADC1 clock to 12 MHz
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
	
	//Configure GPIOA as Input Analog Mode
	GPIOA->CRL &= ~(0x0000000F);
	GPIOA->CRL |=  (0x00000008);
	
	//Enable ADC1 interrupt
	ADC1->CR1 |= ADC_CR1_EOCIE;
	NVIC_EnableIRQ(ADC1_2_IRQn);
	
	//Set Sampling rate for Channel 0
	ADC1->SMPR2 |= ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_0 | ADC_SMPR2_SMP0_1;
	
	//Set Sequence of the Channel
	ADC1->SQR3 |= 0x00000000;
	
	//Enable for the very first time (ADC Wake-Up)...
	ADC1->CR2 |= ADC_CR2_ADON | ADC_CR2_CONT; //Set ADC in Continuous mode
	for(volatile int i = 0;i < 10000;i++);
	
	//Enable for second time (Actual enable)...
	ADC1->CR2 |= ADC_CR2_ADON;
	for(volatile int i = 0;i < 10000;i++);
	
	//Calibrate
	ADC1->CR2 |= ADC_CR2_CAL;
	for(volatile int i = 0; i < 20000;i++);
	
	//User Code initialization...
	while(1)
	{
		
	}
}

void ADC1_2_IRQHandler(void)
{
	if(ADC1->SR & ADC_SR_EOC)
	{
		val = ADC1->DR;
		out = (float)(val*(5/4096));
	}
}
