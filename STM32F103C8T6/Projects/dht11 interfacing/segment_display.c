#include "segment_display.h"
#include "timer.h"

static const char num[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
static const char hello[5] = {0x76,0x79,0x38,0x38,0x3F};

void Segment7x4_Display_Init(void)
{
	//Configure PA0 to PA7 as Output Push-Pull at speed of 2MHz
	GPIOA->CRL &= ~(0xFFFFFFFF);
	GPIOA->CRL |=  (0x22222222);
	
	//Configure PB12 to PB15 as Output Push-Pull at speed of 2MHz
	GPIOB->CRH &= ~(0xFFFF0000);
	GPIOB->CRH |=  (0x22220000);
	
	//Start 4x7 segment display sequence..
	GPIOB->ODR = 0x0000;//ALL selector pins set to LOW
	GPIOA->ODR = num[8] | 0x80;//All LEDs set to HIGH
	delay_ms(1000);
	
	//Display HELLO with delay of 1500 ms
	for(volatile int i = 0;i < 5;i++)
	{
		GPIOA->ODR = hello[i];
		delay_ms(500);
		GPIOA->ODR = 0;
		delay_ms(200);
	}
	
	//Clear display
	GPIOA->ODR = 0x0000;
	
	for(volatile int i = 0;i < 2;i++)
	{
		GPIOA->BSRR |= GPIO_BSRR_BS7; //Set Dot pin HIGH
		delay_ms(500); //Delay of 1000ms
		GPIOA->BSRR |= GPIO_BSRR_BR7; //Set Dot pin LOW
		delay_ms(500); //Delay of 1000ms
	}
}

void Display_Temperature(uint8_t* digit)
{
	for(volatile int j = 0;j < 910;j++)
	{
		GPIOB->ODR = 0x00007000;
		GPIOA->ODR = num[digit[3]];
		//Units Digit for 1 ms
		for(volatile int i = 0;i < 1000;i++);
		
		GPIOB->ODR = 0x0000B000;
		GPIOA->ODR = num[digit[2]];
		//Tens Digit for 1 ms
		for(volatile int i = 0;i < 1000;i++);

		GPIOB->ODR = 0x0000D000;
		GPIOA->ODR = num[digit[1]] | 0x80;
		//Hundreds Digit for 1 ms
		for(volatile int i = 0;i < 1000;i++);

		GPIOB->ODR = 0x0000E000;
		GPIOA->ODR = num[digit[0]];
		//Thousands Digit for 1 ms
		for(volatile int i = 0;i < 1000;i++);
	}
}