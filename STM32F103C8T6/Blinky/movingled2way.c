/*
Project Title : Moving LEDs (Back and Forth)
Author : Aum Dhabalia
Date : 31/03/2025
This program makes LEDs move from right to left and then left to right repeatedly.
Connect 8 LEDs with 220-ohm resistors from PA0 to PA7.
Refer RM0008 reference manual as well as STM32F103C8T6 datasheet.
Refer to stm32f10x.h file for macros used.
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
    RCC->CFGR |= RCC_CFGR_PLLSRC_HSE; // RCC->CFGR |= 0x00010000;
    RCC->CFGR |= RCC_CFGR_PLLMULL9;   // RCC->CFGR |= 0x001C0000;

    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Set PLL as System Clock
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL));

    // Configure AHB, APB1, APB2 Prescaler
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;   // AHB Prescaler = 1 (72 MHz)
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;  // APB1 Prescaler = 2 (36 MHz max)
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;  // APB2 Prescaler = 1 (72 MHz)

    // Update System Core Clock variable
    SystemCoreClock = 72000000;

    // Enable Clock for GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Configure PA0 to PA7 as General-Purpose Output Push-Pull (2 MHz)
    GPIOA->CRL &= ~(0xFFFFFFFF); // Clear bits
    GPIOA->CRL |= 0x22222222; // Set as Output (2 MHz, Push-Pull)

    // Set PA0 to PA7 to 0
    GPIOA->ODR &= 0xFF00;

    while (1)
    {
        //Move LEDs from PA7 to PA0 (Left to Right)
        for(uint8_t count = 1; count < 8; count--)
        {
            GPIOA->ODR = (0x80 >> count);
            for (volatile int i = 0; i < 1000000; i++); // Delay
        }
        
        // Move LEDs from PA0 to PA7 (Right to Left)
        for (uint8_t count = 1; count < 8; count++)
        {
            GPIOA->ODR = (0x01 << count);
            for (volatile int i = 0; i < 1000000; i++); // Delay
        }
    }
}
