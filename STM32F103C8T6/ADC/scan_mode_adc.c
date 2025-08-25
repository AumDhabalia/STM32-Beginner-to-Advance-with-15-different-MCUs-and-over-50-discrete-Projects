/*
Project Title : ADC Scan mode.
Author : Aum Dhabalia
Date : 21/07/2025
This program is for setting up multiple analog to digital conversions using single ADC.
In this program, ADC1 is used in scan mode and set up with two channels on PA0 and PA1.
The conversions take place in sequence as set up on the registers.
*/

#include "stm32f10x.h"

volatile uint16_t adc_ch0_val = 0;
volatile uint16_t adc_ch1_val = 0;
volatile uint8_t channel_index;

//void ADC1_2_IRQHandler(void);

int main(void)
{
	//Initialize HSE 8MHz
	//Enable HSE
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));

	//Configure Flash Latency
	FLASH->ACR |= FLASH_ACR_LATENCY_2;

	//Configure PLL
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE; //RCC->CFGR |= 0x0001 0000;
	RCC->CFGR |= RCC_CFGR_PLLMULL9;   //RCC->CFGR |= 0x001C 0000;

	//Enable PLL
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));

	//Set PLL as system clock
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));

	//Configure AHB, APB1, APB2 Prescalar
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;  //AHB Presclar = 1 (72 MHz)
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; //APB1 Presclar = 2 (36 MHz)
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; //A2B2 Presclar = 1 (72 MHz)
	
	//Update System Core Clock variable
	SystemCoreClock = 72000000;

	//Enable clocks for GPIOA, ADC1, AFIO
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	//Setup ADC1 to 12 MHz
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;

	//Configure GPIO as Input mode
	GPIOA->CRL &= ~(0x0000FFFF); //PA0 and PA1 as input channel
	GPIOA->CRL |=  (0x00002200); //PA0 PA1 as analog input, pa2 pa3 as output

	//Enable ADC1 interrupt
	ADC1->CR1 |= ADC_CR1_EOCIE;
//	NVIC_EnableIRQ(ADC1_2_IRQn);

	//Enable Scan mode and Continuous conversion
	ADC1->CR1 |= ADC_CR1_SCAN;
	ADC1->CR2 |= ADC_CR2_CONT;

	//Set sampling rate for channels 0 and 1
	ADC1->SMPR2 |= ADC_SMPR2_SMP0 | ADC_SMPR2_SMP1;

	//Set channel sequence length = 2
	ADC1->SQR1 &= ~ADC_SQR1_L;
	ADC1->SQR1 |= ADC_SQR1_L_0; // L[3:0] = 2 conversions

	// Set channel sequence: 1st conversion = CH0 (PA0), 2nd = CH1 (PA1)
	ADC1->SQR3 = (0 << 0) | (1 << 5);

	//Enable ADC for first time (Wake Up)
	ADC1->CR2 |= ADC_CR2_ADON;
	for(volatile int i = 0; i < 10000; i++);
	
	//Enable ADC for second time (Actual Enable)
	ADC1->CR2 |= ADC_CR2_ADON;
	for(volatile int i = 0; i < 10000; i++);
	
	//Calibrate ADC1
	//Reset Calibration
	ADC1->CR2 |= ADC_CR2_RSTCAL;
	while(ADC1->CR2 & ADC_CR2_RSTCAL); //Wait for calibration to reset
	//Start Calibration
	ADC1->CR2 |= ADC_CR2_CAL;
	while(ADC1->CR2 & ADC_CR2_CAL); //Wait for calibration to complete

	//Start conversion
	ADC1->CR2 |= ADC_CR2_ADON | ADC_CR2_SWSTART;
	
	//Set channel index to 0
	channel_index = 0; //First conversion of Channel 0 at PA0
	
	//User Code initialization...
	while(1)
	{
		if(ADC1->SR & ADC_SR_EOC)
		{
			if(channel_index == 0)
			{
				adc_ch0_val = ADC1->DR;
				channel_index = 1;
			}
			else
			{
				adc_ch1_val = ADC1->DR;
				channel_index = 0;
			}
		}
	}
}
