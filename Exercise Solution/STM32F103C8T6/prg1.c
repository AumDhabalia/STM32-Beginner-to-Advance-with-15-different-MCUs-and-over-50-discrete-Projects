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
    //Enable clocks for GPIOA and GPIOB
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    
    //Configure PA0 as input with pull-down
    GPIOA->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);
    GPIOA->CRL |= GPIO_CRL_CNF0_1;  // Input mode with pull-down
    GPIOA->ODR &= ~GPIO_ODR_ODR0;   // Ensure pull-down is active
    
    // Configure PB0-PB7 as output (push-pull, 2MHz)
    GPIOB->CRL = 0x22222222;  // Output mode, 2MHz, push-pull
    
    // Variables
    uint8_t counter = 0;
    uint8_t buttonPressed = 0;
    
    while(1)
    {
        //Check if button is pressed (active HIGH)
        if((GPIOA->IDR & GPIO_IDR_IDR0) && buttonPressed == 0)
        {
            for(uint32_t i = 0; i < 100000; i++); //Debounce delay
            //Confirm button is still pressed
            if(GPIOA->IDR & GPIO_IDR_IDR0)
            {
                buttonPressed = 1; //Set flag to indicate button press event
                counter++; //Increase counter by 1
                GPIOB->ODR = (GPIOB->ODR & 0xFF00) | counter; //Display Counter
            }
        }
        //Check if button is released
        if(!(GPIOA->IDR & GPIO_IDR_IDR0) && buttonPressed == 1)
        {
            for(uint32_t i = 0; i < 100000; i++); //Debounce delay
            // Confirm button is still released
            if(!(GPIOA->IDR & GPIO_IDR_IDR0))
                buttonPressed = 0; //Clear flag to allow next press event
        }
    }
}
