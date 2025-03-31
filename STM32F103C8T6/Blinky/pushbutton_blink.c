/*
Project Title : Pushbutton Blinking
Author : Aum Dhabalia
Date : 26/03/2025
This program is for blinking LED using a pushbutton.
LED built-in on the BluePill board is taken (LED Pin may vary on different BluePill supplier).
Refer RM0008 reference manual and STM32F103C8T6 datasheet.
Refer to stm32f10x.h for macros used.

LED Blinks when button is pressed.
PushButton is set to Pull-Up mode (Default High).
*/
#include "stm32f10x.h"

int main(void)
{
    // Initialize HSE 8 MHz
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));
    
    // Configure Flash Latency
    FLASH->ACR |= FLASH_ACR_LATENCY_2;
    
    // Configure PLL
    RCC->CFGR |= RCC_CFGR_PLLSRC_HSE; // HSE as PLL Source
    RCC->CFGR |= RCC_CFGR_PLLMULL9;   // PLL * 9 = 72MHz
    
    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));
    
    // Set PLL as System Clock
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
    
    // Configure AHB, APB1, APB2 Prescaler
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;   // AHB Prescaler = 1 (72 MHz)
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;  // APB1 Prescaler = 2 (36 MHz max)
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;  // APB2 Prescaler = 1 (72 MHz)
    
    // Update System Core Clock variable
    SystemCoreClock = 72000000;
    
    // Enable GPIOB and GPIOC clock
    RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN);
    
    // Configure PC15 as Input with Pull-up (User Button)
    GPIOC->CRH &= ~(GPIO_CRH_CNF15 | GPIO_CRH_MODE15); // Clear mode bits for PC15
    GPIOC->CRH |= (0x8 << 28);  // Set PC15 as input with pull-up/pull-down
    GPIOC->ODR |= (1 << 15);    // Enable pull-up on PC15
    
    // Configure PB2 as Output (LED)
    GPIOB->CRL &= ~(GPIO_CRL_CNF2 | GPIO_CRL_MODE2);  // Clear PB2 mode bits
    GPIOB->CRL |= (GPIO_CRL_MODE2_1);   // Set PB2 as output, max speed 2MHz
    
    // Turn OFF PB2 initially
    GPIOB->BSRR |= GPIO_BSRR_BR2;
    
    // Control Loop
    while (1)
    {
        // Read PC15 (User button)
        if ((GPIOC->IDR & (1 << 15)) == 0)  
        {
            GPIOB->BSRR |= GPIO_BSRR_BS2; // Turn ON PB2 (LED)
        }
        else
        {
            GPIOB->BSRR |= GPIO_BSRR_BR2; // Turn OFF PB2 (LED)
        }
    }
}
