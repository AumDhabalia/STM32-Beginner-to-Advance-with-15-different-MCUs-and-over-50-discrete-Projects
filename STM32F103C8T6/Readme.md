# STM32F103C8T6 Projects
STM32F103C8T6 *BluePill* is *NUCLEO-32* development board from STM32F1 series MCUs.
<br>
<br>The microntroller has ARM 32-Bit Cortex-M3 core with **clock speed** of *72Mhz* max, memory of *64kB* on chip **flash** and ***20KB* SRAM** and **operating voltage of 2.0v to 3.6V**. It has *seven channel* DMA controller (with supported peripherals Timer, ADC, I2Cs, SPIs and USARTs). Two 12 bit (upto 16 channels) ADC with conversion range **0 to 3.6v**. Upto *five GPIO ports* from A to E. **Three** 16-bit timers, a 16-bit motor PWM, **two** watchdog timers and **one** 24-bit SysTick downcounter timer. **Nine** communication interfaces (two I2Cs, two SPIs, three USARTs, USB, CAN).
<br/>
<br/>Refer [RM0008](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) Reference Manual and STM32F103C8T6 [datasheet](https://www.st.com/resource/en/datasheet/cd00161566.pdf)
## BluePill Pinout Diagram
![image](https://github.com/user-attachments/assets/d8f85397-d5e6-4402-8ca8-7de60f78d5b5)
***Note : The general built-in LED connection is at PC13. However, it may change based on BluePill board manufacturers. For WaveShare STM32-BluePill built-in LED is at PB2.***
<br>
<br>In this readme, individual documentation for each of the tutorial from basic introduction to modules to advanced projects is provided.
## Index
Pre Setups and configurations
1. Blinky
2. ADC
3. Interrupt
4. Timer
5. PWM
6. USART
7. SPI
8. I2C
9. CAN
10. USB
11. Other Projects

### Pre Setup and configurations
Before starting, ensure Keil is installed. If not, refer here to install Keil MDK_ARM.
<br/>Open Pack Installer.
<br/>Search for STM32F103C8.
<br/>On the right side specific packages will be displayed. Install DFP, CMSIS
#### 1. Blinky
In the first chapter, **LED(s)** blinking i.e. LED ON and OFF based projects will be performed. Given below is the list of the projects associated to this chapter.
#### 2. ADC (Analog to Digital Converter)
#### 3. Interrupt
#### 4. Timer
#### 5. PWM
#### 6. USART
#### 7. SPI
#### 8. I2C
#### 9. CAN
#### 10. USB
#### 11. Blinky
