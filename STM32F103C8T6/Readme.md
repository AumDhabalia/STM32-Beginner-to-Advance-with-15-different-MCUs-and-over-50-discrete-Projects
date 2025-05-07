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

## Index
[***Block Diagram***](Readme.md#block-diagram)<br>
[***BluePill Pinout Diagram***](Readme.md#bluepill-pinout-diagram)<br>
[***STM32F103C8T6 Pin Planner***](Readme.md#STM32F103C8T6-Pin-Planner)<br>
[***Pre Setups and Configurations***](Readme.md#Pre-Setups-and-Configurations)
1. [Blinky](Readme.md#1-blinky)
2. [ADC](Readme.md#2-adc-analog-to-digital-converter)
3. [Interrupt](Readme.md#3-interrupt)
4. [Timer](Readme.md#4-timer)
5. PWM
6. USART
7. SPI
8. I2C
9. CAN
10. USB
11. Projects
12. [Exercise](Readme.md#12-exercise)

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

### *Pre Setups and Configurations*
Before starting, ensure Keil is installed. If not, refer [here](../Readme.md#2-keil-ide) to install Keil MDK_ARM.
<br>
<br>Open Pack Installer.
<br>
<br>Search for STM32F103C8.
<br>![Screenshot 2025-03-27 193005](https://github.com/user-attachments/assets/2252c3cb-cc2b-43f0-bcc9-1cc7f4d02cc1)
<br>
<br>On the right side specific packages will be displayed. Install DFP, CMSIS
<br>![Screenshot 2025-03-27 193050](https://github.com/user-attachments/assets/52359909-17b5-4a40-bdb1-a9927e6fd19f)
<br><br>On installation, popup for STLink Debugger will appear. Install it.
<br>
<br>**To create project click [here](../Readme.md#project-setup)**
<br>Once project is created, copy [main.c](main.c) file and paste it in your main.c file. It is advisable to name it as main.c. This main.c file contains the clock configurations for setting up internal (HSI) or external clocks (HSE). This clock will determine the data rate of the buses (**AHB and APB**)
<br>
<br>
## 1. Blinky
In the first chapter, **LED(s)** blinking i.e. LED ON/OFF based projects are be performed. Given below is the list of the projects associated to this chapter. The LED(s) here are nothing but output from the pins. The pins mentioned here are known as General Purpose Input/Output pins. STM32F103 line has total of five GPIO ports from A to E, each having 16 pins.
<br>BluePill has total of 40 pins
- GPIOA and GPIOB ports
- PD0 and PD1 for HSE
- PC13 & PC14
- 2 pins for ground, 2 pins for supply voltage.
<br>

   1. [Simple Blink](Blinky/simple_blinking.c)

This is the basic introductory project for getting started with STM32F103C8T6 BluePill board. In this project, a built-in LED at PC13 or PB2 is blinked at time interval of 500 ms.
- For this, first create a new &#181;vision project from Project->New &#181;Vision Project. Select STM32F103C8 Device, select CMSIS->Core, select Device->Startup and click OK.
- Create a new text file and save as main.c. Add main.c in Source Group 1
- Goto Target_1 Options and navigate to Debugger select STLINK-Debugger and goto its Settings
- Tick on Sharable STLINK, tick on Download to Flash.
- Navigate to Trace. Change crystal to 8 MHz from 10 MHz.
- Navigate to Flash Download. Tick on Erase full-chip. Tick on Reset & Run. Select STM32F10x Med-Density Flash. On the right bottom, in start change to 0x00010000.
- Apply this settings by clicking on ***OK***.

<br>Once this settings are applied, navigate to main.c.
<br>
<br>From this point onwards, the simple LED blinking programming starts. Connect the STLink debugger/programmer to ***BluePill***. Refer to the pinout on the debugger as well as on the mcu. Connect SWDIO pin of the debugger to the SWDIO pin of the board. Connect SWCLK of the debugger to the SWCLK/SWCK pin of the board. Connect ***3.3v*** to the ***Vcc*** of the board.
<br>
<br>Once it is done, connect debugger to the system such that the reset switch is kept pressed. Release the switch after connected. A STLink/V2 dialog box will appear. Click on Update. If the Update is not active then reconnect the debugger and keep the switch pressed and then release it after connected. Do it for two three times if not working.
<br>
<br>Now that, BluePill is setup
- Build the project. No error should be displayed.
- Download the program to the board by navigating to Flash->Download or by pressing ***F8***.
- Start debug session by pressing ***Ctrl+F5*** or navigating to Debug->Start Debug.
- This procedure is general for all the upcoming tutorials and projects.

<br>Since, the built-in LED is internally connected, no need for external connections. In the main.c,
- Enable GPIOB clock
<br>RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;<br>
- Configure GPIOB PB2 pin as General-Purpose Output Push-Pull (2 MHz) mode
<br>**GPIOB->CRL &= ~(0x00000F00);** _//Clear bits for PB2_
<br>**GPIOB->CRL |=  (0x00000200);**  _//Set as Output (2 MHz, Push-Pull)_
- In while loop, Set PB2 **_(ON State)_** wait for dely of 500 ms and reset PB12 **_(OFF State)_**.
<br>**GPIOB->BSRR |= GPIO_BSRR_BS2;** _//Set PB2 (LED ON)_
<br>**for(volatile int i = 0;i < 500000;i++);** _//500 ms = 500,000 us_
<br>**GPIOB->BSRR |= GPIO_BSRR_BR2;** _//Reset PB2 (LED OFF)_
<br>**for(volatile int i = 0;i < 500000;i++);** _//500 ms = 500,000 us_
<br>Given below figure shows the circuit diagram for the blinky.
<br>..........Image Pending...........
<br>

   2. [Lighthouse Blinking](Blinky/lighthouse_blinking.c)<br>

In this tutorial, the LED is blinked in a pattern of GpFl(2) which a maritime lighthouse flashing pattern. In this pattern, light signal is flashed in group of two flashesand then remains dark for same period as for flashing period.
<br>
<br>Here, the **ON** state for both flash is taken as 200 ms and **OFF** state as 100 ms and the **wait/dark** state for 400 ms (**OFF** state). Same procedure for setting up the device. Instead of regular time interval blinking in previous tutorial, pattern blinking is performed.
<br>
<br>In main.c, in while loop change the logic to
<br>**GPIOB->BSRR |= GPIO_BSRR_BS2;** _//Set PB2 (LED ON)_
<br>**for(volatile int i = 0;i < 200000;i++);** _//200 ms = 200,000 us_
<br>**GPIOB->BSRR |= GPIO_BSRR_BR2;** _//Reset PB2 (LED OFF)_
<br>**for(volatile int i = 0;i < 100000;i++);** _//100 ms = 100,000 us_

<br>**GPIOB->BSRR |= GPIO_BSRR_BS2;** _//Set PB2 (LED ON)_
<br>**for(volatile int i = 0;i < 200000;i++);** _//200 ms = 200,000 us_
<br>**GPIOB->BSRR |= GPIO_BSRR_BR2;** _//Reset PB2 (LED OFF)_
<br>**for(volatile int i = 0;i < 100000;i++);** _//100 ms = 100,000 us_

<br>**for(volatile int i = 0;i < 400000;i++);** _//400 ms = 400,000 us_

<br>The circuit diagram is same as of previous tutorial.
<br>

   3. [Alternate Blinking](Blinky/alternate_blinking.c)<br>

In this tutorial, two LEDs are blinked alternately. One LED is digital **HIGH** while other is digital **LOW** with regular interval. In the given circuit diagram pins PB6 and PB7 are taken as general purpose output mode connected to two LEDs. 220 &Omega; rsistance is connected between pin and the diode each respectively.
<br>
<br>........Image Pending.........
<br>
<br>After enabling GPIOB, configure PB6 & PB7 pins.
<br>**GPIOB->CRL &= ~(0xFF000000)** _//Clear PB6 & PB7_
<br>**GPIOB->CRL |=  (0x22000000)** _//Set as Output (2 MHz, Push-Pull)_
<br>
<br>Once configured, navigate to while loop and write logic for alternate blinking. It can be done either using **BSRR _(Bit Set Reset Register)_** or by using **ODR _(Output Data Register)_**.
<br>For this tutorial, BSRR is used.
<br>**GPIOB->BSRR |= (GPIO_BSRR_BS6 | GPIO_BSRR_BR7);** _//Set PB6 (LED ON) & Reset PB7 (LED OFF)_
<br>**for(volatile int i = 0; i < 500000; i++);** _//500 ms = 500,000 us_
<br>
<br>**GPIOB->BSRR |= (GPIO_BSRR_BR6 | GPIO_BSRR_BS7);** _//Reset PB6 (LED OFF) & Set PB7 (LED ON)_
<br>**for(volatile int i = 0;i < 500000;i++);** _//500 ms = 500,000 us_
<br>

   4. [2-Bit Counter](Blinky/counter2bit.c)<br>

In this tutorial, a simple 2 bit counter logic is developed. The connections are same and so is the circuit diagram. In while loop, PB7 is MSB and PB6 is LSB. The truth table for 2 bit counter is shown below.
|PB7|PB6|
|:---:|:---:|
|LOW|LOW|
|LOW|HIGH|
|HIGH|LOW|
|HIGH|HIGH|
Initially set both pins _**HIGH**_.And then in while use BSRR for counter with regular interval.
<br>

   5. [N-Bit Counter](Blinky/counterNbit.c)<br>

This is same as previous one but for N bits. Here N is taken as 8. Therefore, there are 256 states from 0 to 255. For this case use ODR instead of BSRR and use for loop. Take PA7(_MSB_) to PA0(_LSB_) pins as general purpose output mode (2 MHz).
- Enable GPIOA
- Configure PA7 to PA0 as general purpose output (2 MHz, Push-Pull)
- In while loop, set all bits to 0 initially.
- Take a for loop with limit to 256.
- Increment the ODR value by 1 with delay of 200 ms.
<br>

   6. [Moving LEDs (One Way)](Blinky/movingled.c)<br>
   
   7. [Moving LEDs (Back & Forth)](Blinky/movingled2way.c)<br>
   
   8. [Random LED(s) FLashing](Blinky/randomflashing.c)
   
   9. [Pushbutton Blinking](Blinky/pushbutton_blink.c)
   
   10. [7-Segment Display]()
   
   11. [4 digit 7-Segment Display]()

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
   1. [Blinky with Timer](Timer/timer_blink.c)
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
   1. CAN Setup
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
## 12. Exercise
   1. Write a progrm for 8-bit up/down counter using pushbutton and a counter switch which controls count direction (i.e. up counter = LOW, down counter = HIGH).
   2. Write a program for moving digits unidirectionally using eight 7-segment display module.
   3. Write a program reading 4 ADC inputs. Use multiple channel ADC.
   4. Write a program blinking 60 seconds timer and reading ADC input at every 5 seconds.
   5. Write a program for generating three different signals using multi-channel timers.
   6. Write a program for controlling voltage ranging from 10v to 220v. Use PWM.
   7. Write a program to transmit messages with time period based on user selection. Use USART.
   8. Design a Daisy-Chain setup for SPI communication interface.
   9. Write a program for interfacing two LCD display and two 4 digit 7-Segment display using I2C.
   10. Write a program for data transmission from Bluepill memory to System using USB.
   11. Write a program for CAN based Memory interfacing with multiple memory ICs.
