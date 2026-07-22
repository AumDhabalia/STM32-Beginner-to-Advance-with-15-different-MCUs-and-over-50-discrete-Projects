#include "dht11.h"
#include "timer.h"
#include "segment_display.h"

void Init_DHT11(void)
{
	//Set to Output Push-Pull Mode with 2Mhz speed
	GPIOA->CRH &= ~(0x0000000F);
	GPIOA->CRH |=  (0x00000002);
	
	//Set to HIGH. DHT11 is kept in idle state when no data transmission is happening.
	GPIOA->BSRR = GPIO_BSRR_BS8;
}

void Start_DHT11(void)
{
	//Output mode
	GPIOA->CRH &= ~(0x0000000F);
	GPIOA->CRH |=  (0x00000002);
	
	//Pull low for 18ms
	GPIOA->BSRR = GPIO_BSRR_BR8;
	delay_ms(18);
	
	//Pull high for 30us
	GPIOA->BSRR = GPIO_BSRR_BS8;
	delay_us(30);
	
	//Input mode
	GPIOA->CRH &= ~(0x0000000F);
	GPIOA->CRH |=  (0x00000004);
}

uint8_t Read_Data(uint8_t* data)
{	
	//Clear data buffer
	for(volatile int  j = 0;j < 5;j++)
		data[j] = 0;
	
	//--- Wait for sensor response ---
	//Wait for LOW (~80us)
	uint32_t wait_time = 0;
	while((GPIOA->IDR & (1 << 8)))
	{
		delay_us(1);
		if(++wait_time > 100) return 1; //No low detected
	}
	
	//Wait for HIGH (~80us)
	wait_time = 0;
	while(!(GPIOA->IDR & (1 << 8)))
	{
		delay_us(1);
		if(++wait_time > 100)
			return 1;
	}
	
	//Wait for LOW (start of first bit)
	wait_time = 0;
	while((GPIOA->IDR & (1 << 8)))
	{
		delay_us(1);
		if(++wait_time > 100)
			return 1;
	}
	
	//Read Data
	for(volatile int j = 0; j < 5; j++)
	{
		for(volatile int i = 0; i < 8; i++)
		{
			//Wait for HIGH
			while(!(GPIOA->IDR & (1 << 8)));
			
			//Delay of 40us
			delay_us(40);
			if(GPIOA->IDR & (1 << 8))
				data[j] |= (1 << (7 - i));
			
			//Wait for LOW
			while(GPIOA->IDR & (1 << 8));
		}
	}
	
	//Verify Checksum
	if(data[4] != (uint8_t)(data[0] + data[1] + data[2] + data[3]))
		return 1;
	return 0; // OK
}

void Read_DHT11(uint8_t* digit,uint8_t* data)
{
	if(Read_Data(data) == 0)
	{
		digit[0] = data[2]/10;
		digit[1] = data[2]%10;
		digit[2] = data[3]/10;
		digit[3] = data[3]%10;
	}
}