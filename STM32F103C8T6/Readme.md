# STM32F103C8T6 Projects
STM32F103C8T6 *BluePill* is *NUCLEO-32* development board from STM32F1 series MCUs.
<br>
### Technical Specification
- ARM 32-Bit Cortex-M3 core with **clock speed** of *72Mhz* max
- Memory of *64kB* on chip **flash** and ***20KB* SRAM** and **operating voltage of 2.0v to 3.6V**.
- *Seven channel* DMA controller (with supported peripherals Timer, ADC, I2Cs, SPIs and USARTs).
- Two 12 bit (upto 16 channels) ADC with conversion range **0 to 3.6v**.
- Upto *five GPIO ports* from A to E.
- **Seven** timers
  - **Three** 16-bit timers
  - **One** 16-bit motor PWM
  - **Two** watchdog timers
  - **One** 24-bit SysTick downcounter timer.
- **Nine** communication interfaces (two I2Cs, two SPIs, three USARTs, USB, CAN).

### Block Diagram
![STM32F103C8 Block Diagram](https://github.com/user-attachments/assets/0e6b4937-05f9-40ae-9498-1def41f2ab82)
<br>
Refer [RM0008](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) Reference Manual and STM32F103C8T6 [datasheet](https://www.st.com/resource/en/datasheet/cd00161566.pdf). Refer to ***BluePill Pinout Diagram*** as well as ***STM32F103C8T6 PIN PLANNER***.

## BluePill Pinout Diagram
![image](https://github.com/user-attachments/assets/d8f85397-d5e6-4402-8ca8-7de60f78d5b5)
***Note : The general built-in LED connection is at PC13. However, it may change based on BluePill board manufacturers. For WaveShare STM32-BluePill built-in LED is at PB2.***
## STM32F103C8T6 PIN PLANNER

| Pins | Name | Main Function | Default | Remap |
|:------:|:------:|:--------------:|:---------:|:-------:|
| 1 | VBat | VBat | VBat | - |
| 2 | PC13-Tamper RTC | PC13 | TAMPER-RTC | - |
| 3 | PC14-OSC32_IN | PC14 | OSC32_IN | - |
| 4 | PC15-OSC32_OUT | PC15 | OSC32_OUT | - |
| 5 | OSC_IN | OSC_IN | - | PD0 |
| 6 | OSC_OUT | OSC_OUT | - | PD1 |
| 7 | NRST | NRST | - | - |
| 8 | VSS_A | VSS_A | - | - |
| 9 | VDD_A | VDD_A | - | - |
| 10 | PA0-WKUP | PA0 | WKUP/USART2_CTS/ADC12_IN0/TIM2_CH1_ETR | - |
| 11 | PA1 | PA1 | USART2_RTS/ADC12_IN1/TIM2_CH2 | - |
| 12 | PA2 | PA2 | USART2_Tx / ADC12_IN2 / TIM2_CH3 | - |
| 13 | PA3 | PA3 | USART2_Rx / ADC12_IN3 / TIM2_CH4 | - |
| 14 | PA4 | PA4 | SPI1_NSS / USART2_CK / ADC12_IN4 | - |
| 15 | PA5 | PA5 | SPI1_SCK / ADC12_IN5 | - |
| 16 | PA6 | PA6 | SPI1_MISO / ADC12_IN6 / TIM3_CH1 | TIM1_BKIN |
| 17 | PA7 | PA7 | SPI1_MOSI / ADC12_IN7 / TIM3_CH2 | TIM1_CH1N |
| 18 | PB0 | PB0 | ADC12_IN8 / TIM3_CH3 | TIM1_CH2N |
| 19 | PB1 | PB1 | ADC12_IN9 / TIM3_CH4 | TIM1_CH3N |
| 20 | PB2 | PB2/BOOT1/LD2 | - | - |
| 21 | PB10 | PB10 | I2C2_SCL / USART3_Tx | TIM2_CH3 |
| 22 | PB11 | PB11 | I2C2_SDA / USART3_Rx | TIM2_CH4 |
| 23 | VSS_1 | VSS_1 | - | - |
| 24 | VDD_1 | VDD_1 | - | - |
| 25 | PB12 | PB12 | SPI2_NSS / I2C2_SMBAI / USART3_CK / TIM1_BKIN | - |
| 26 | PB13 | PB13 | SPI2_SCK / USART3_CTS / TIM1_CH1N | - |
| 27 | PB14 | PB14 | SPI2_MISO / USART3_RTS / TIM2_CH2N | - |
| 28 | PB15 | PB15 | SPI2_MOSI / TIM1_CH3N | - |
| 29 | PA8 | PA8 | USART1_CK / TIM1_CH1 / MCO | - |
| 30 | PA9 | PA9 | USART1_Tx / TIM1_CH2 | - |
| 31 | PA10 | PA10 | USART1_Rx / TIM1_CH3 | - |
| 32 | PA11 | PA11 | USART1_CTS / CANRx / USBDM / TIM1_CH4 | - |
| 33 | PA12 | PA12 | USART1_RTS / CANtX / USBDP / TIM1_CH5 | - |
| 34 | PA13 | PA13 | - | PA13 |
| 35 | VSS_2 | VSS_2 | - | - |
| 36 | VDD_2 | VDD_2 | - | - |
| 37 | PA14 | JTCLK/SWCLK | - | PA14 |
| 38 | PA15 | JTDI | - | TIM2_CH1_ETR / PA15 / SPI1_NSS |
| 39 | PB3 | JTDO | - | TIM2_CH2 / PB3 / TRACESWO / SPI1_SCK |
| 40 | PB4 | JNTRST | - | TIM3_CH1 / PB4 / SPI1_MISO |
| 41 | PB5 | PB5 | I2C1_SMBAI | TIM3_CH2 / SPI1_MOSI |
| 42 | PB6 | PB6 | I2C1_SCK/TIM4_CH1 | USART1_Tx |
| 43 | PB7 | PB7 | I2C1_SDA/TIM4_CH2 | USART1_Rx |
| 44 | BOOT0 | BOOT0 | - | - |
| 45 | PB8 | PB8 | TIM4_CH3 | I2C1_SCL / CANRx |
| 46 | PB9 | PB9 | TIM4_CH4 | I2C1_SDA / CANTx |
| 47 | VSS_3 | VSS_3 | - | - |
| 48 | VDD_3 | VDD_3 | - | - |

<br/>In this readme, individual documentation for each of the tutorial is provided.

## Index
***Pre Setups and Configurations***
1. [Blinky](Readme.md#1-blinky)
2. [ADC](Readme.md#2-adc-analog-to-digital-converter)
3. Interrupt
4. Timer
5. PWM
6. USART
7. SPI
8. I2C
9. CAN
10. USB
11. Other Projects

### *Pre Setup and Configurations*
Before starting, ensure Keil is installed. If not, refer [here](../Readme.md#2-keil-ide) to install Keil MDK_ARM.
<br>
<br/>Open Pack Installer.
<br/>
<br>Search for STM32F103C8.
<br/>![Screenshot 2025-03-27 193005](https://github.com/user-attachments/assets/2252c3cb-cc2b-43f0-bcc9-1cc7f4d02cc1)
<br/>
<br>On the right side specific packages will be displayed. Install DFP, CMSIS
<br/>![Screenshot 2025-03-27 193050](https://github.com/user-attachments/assets/52359909-17b5-4a40-bdb1-a9927e6fd19f)
<br><br>On installation, popup for STLink Debugger will appear. Install it.
<br>
<br>**To create project click [here](../README.md#project-creation-on-keil)**
<br>Once project is created, copy [main.c](main.c) file and paste it in your main.c file. It is advisable to name it as main.c. This main.c file contains the clock configurations for setting up internal (HSI) or external clocks (HSE). This clock will determine the data rate of the buses (**AHB and APB**)
<br>
<br>
## 1. Blinky
In the first chapter, **LED(s)** blinking i.e. LED ON/OFF based projects are be performed. Given below is the list of the projects associated to this chapter.<br/>
   1. [Simple Blink](Blinky/simple_blinking.c)
   2. [Lighthouse Blinking](Blinky/lighthouse_blinking.c)
   3. [Alternate Blinking](Blinky/alternate_blinking.c)
   4. [2-Bit Counter](Blinky/counter2bit.c)
   5. [N-Bit Counter](Blinky/counterNbit.c)
   6. [Moving LEDs (One Way)](Blinky/movingled.c)
   7. [Moving LEDs (Back & Forth)](Blinky/movingled2way.c)
   8. [Random LED(s) FLashing](Blinky/randomflashing.c)
   9. [Pushbutton Blinking](Blinky/pushbutton_blink.c)
   10. [Up-Down Counter with Pushbutton]()
   11. [7-Segment Display]()
   12. [4 digit 7-Segment Display]()
## 2. ADC (Analog to Digital Converter)
   1. Basic ADC setup
   2. Read 10kohm Potentiometer
   3. Dual Axis Potentiometer
   4. Signal Processing
   5. Temperature & Humidity Sensing
   6. Voltage Sensing
   7. Dual Channel ADC
   8. N-Channel ADC
## 3. Interrupt
   1. LED & Interrupt Pushbutton
   2. N-Bit Counter using Pushbutton
   3. ADC channel control using Pushbutton
   4. Sensor based interrupt generation
## 4. Timer
   1. Blinky with Timer
   2. Signal Generation using timer
   3. Input Capture
   4. Multiple sensor reading using timer
   5. Real-Time Clock
   6. Multi-channel signal generation
## 5. PWM
   1. PWM Setup
   2. LED Intensity Control
   3. DC Motor Speed Control
   4. Servo Motor Control
   5. PWM Signal Generation
   6. Multi-channel PWM
   7. Moving LEDs (One Way)
   8. Moving LEDs (Back Forth)
   9. RGB using PWM
## 6. USART
   1. USART Setup
   2. Message Transmission
   3. Message Reception
## 7. SPI
   1. SPI Setup
   2. RFID Interfacing
   3. Master-Slave Configuration (wired)
   4. Memory Interfacing
## 8. I2C
   1. I2C Setup
   2. I2C LCD Interfacing
   3. Multiple LCD Interfacing
## 9. CAN
## 10. USB
   1. USB Setup
   2. USB HID
   3. USB 2.0 Device Driver
## 11. Advanced Projects
   1. Motor Speed Control using user input
   2. Multiple event execution simultaneously
   3. Battery Monitoring System
   4. Solar based battery charger
   5. Battery Charger
   6. LED Positioning using Pot
   7. USB based Xbox Game Controller
   8. Memory Interfacing
   9. Rotary Encoder and LCD interfacing
