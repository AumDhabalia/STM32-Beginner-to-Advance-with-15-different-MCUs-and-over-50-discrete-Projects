#ifndef DHT11_H
#define DHT11_H

#include "stm32f10x.h"

void Init_DHT11(void);
void Start_DHT11(void);
uint8_t Read_Data(uint8_t* data);
void Read_DHT11(uint8_t* digit,uint8_t* data);

#endif