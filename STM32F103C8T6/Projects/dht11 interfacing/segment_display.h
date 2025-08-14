#ifndef SEGMENT_DISPLAY_H
#define SEGMENT_DISPLAY_H

#include "stm32f10x.h"

void Segment7x4_Display_Init(void);
void Display_Temperature(uint8_t* digit);

#endif