/*
Project Title : LED Blink on PB2
Author : Aum Dhabalia
Date : 16/03/2025
This program is to get general introduction to the STM32 BluePill and a basic LED blinking with a certain timeperiod.
A built-in LED is connected to PB2 is blinked at time period of 500 ms.
Refer RM0008 reference manual as well as STM32F103C8T6 datasheet.
Refer to stm32f10x.h file for macros used.
*/

#include "stm32f10x.h"

void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 1000; i++);
}

int main(void)
{
    // Initialize HSE 8 MHz
    RCC->CR |= RCC_CR_HSEON;
    while(!(RCC->CR & RCC_CR_HSERDY));
    
    // Configure Flash Latency
    FLASH->ACR |= FLASH_ACR_LATENCY_2;
    
    // Configure PLL
    RCC->CFGR |= RCC_CFGR_PLLSRC_HSE;
    RCC->CFGR |= RCC_CFGR_PLLMULL9;
    
    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR & RCC_CR_PLLRDY));
    
    // Set PLL as System Clock
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
    
    // Configure AHB, APB1, APB2 Prescaler
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
    
    // Update System Core Clock variable
    SystemCoreClock = 72000000;
    
    // Enable Clock for GPIOB
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    
    // Configure PB2 as General-Purpose Output Push-Pull (2 MHz)
    GPIOB->CRL &= ~(0x00000F00); // Clear bits for PB2
    GPIOB->CRL |=  (0x00000200);  // Set as Output (2 MHz, Push-Pull)
    
    while(1)
    {
        GPIOB->BSRR |= GPIO_BSRR_BS2; //Set PB2 (LED ON)
        for(volatile int i = 0;i < 500000;i++); //500 ms = 500,000 us
        
        GPIOB->BSRR |= GPIO_BSRR_BR2; //Reset PB2 (LED OFF)
        for(volatile int i = 0;i < 500000;i++); //500 ms = 500,000 us
    }
}
