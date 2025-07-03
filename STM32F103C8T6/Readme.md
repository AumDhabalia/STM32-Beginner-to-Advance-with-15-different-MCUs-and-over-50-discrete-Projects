# STM32F103C8T6 Projects
STM32F103C8T6 *BluePill* is *NUCLEO-32* development board from STM32F1 series MCUs.
<br>
### Technical Specification
- ARM 32-Bit Cortex-M3 core with **clock speed** of *72Mhz* max
- Memory of *64KB* on chip **flash** and ***20KB* SRAM** and **operating voltage of 2.0v to 3.6V**.
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
4. [Timers & Counters](Readme.md#4-timer)
5. [PWM]
6. [USART]
7. [SPI]
8. [I2C]
9. [CAN]
10. [USB]
11. [Projects]
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

<br>These GPIOs are handled by their registers. These registers are used to configure and set for desired requirements. For **_BluePill_**, there are total of 7 registers for configuring GPIOs and a set of **AFIO** registers for alternate function modes. They are
- Two Port Configuration Registers _32 bit_ (**CRL** & **CRH**).
  - CRL-> Lower 8 pins
  - CRH-> Upper 8 pins
- Two Data registers _32 bit_ (**IDR** & **ODR**).
  - Input Data Register = IDR
  - Output Data Register = ODR
- **Bit Set Reset Register _32 bit_ (_BSRR_)**
- **Bit Reset Register _16 bit_ (_BRR_)**
- Port Configuration Lock register _32 bit_ (**LCKR**).

<br>AFIO are alternate function I/O pins which are used for functionalities other than digital 1/0's. AFIO is used for ADC, PWM, External Interrupt, USART, timer, SWD/JTAG, CAN, SPI, I2C, etc.

<br>The GPIO pins have two modes which are configured into 4 different modes each.
- Mode bits
  - 00 = Input Mode
  - 01 = Output Mode with speed 10 MHz
  - 10 = Output Mode with speed 2 MHz
  - 11 = Output Mode with speed 50 MHz
- Configuration bits
  - Output Mode :
    - 00 = Push-Pull (General Purpose)
    - 01 = Open-Drain (General Purpose)
    - 10 = Push-Pull (Alternate Function)
    - 11 = Open-Drain (Alternate Function)
  - Input Mode :
    - 00 = Analog Mode
    - 01 = Floating Point
    - 10 = Input with PullUp-PullDown
    - 11 = **_Reserved_**
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
<br>
![Simple Blink](https://github.com/user-attachments/assets/8d2fc856-bf71-437b-9d1b-d38c8a28a595)
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
<br>
![Alternate Blink](https://github.com/user-attachments/assets/506d8c24-0e9d-41e2-8f2a-df685054206b)
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

<br>Initially set both pins _**HIGH**_ and then in while loop use BSRR for counter with regular interval. Circuit diagram is same as above.
<br>

   5. [N-Bit Counter](Blinky/counterNbit.c)<br>

This is same as previous one but for N bits. Here N is taken as 8. Therefore, there are 256 states from 0 to 255. For this case use ODR instead of BSRR and use for loop. Take PA7(_MSB_) to PA0(_LSB_) pins as general purpose output mode (2 MHz).
- Enable GPIOA
- Configure PA7 to PA0 as general purpose output (2 MHz, Push-Pull)
- Initially set all configured pins to 1.
- Take a for loop with limit to 256.
- Increment the ODR value by 1 with delay of 200 ms.
<br> **for(volatile int i = 0;i < 256;i++)**
<br> **{**
<br>   &emsp;**GPIOA->ODR = i;**
<br>   &emsp;**for(volatile int j = 0;j < 1000000;j++);**
<br> **}**

<br>The circuit diagram is shown below.
<br>
![N Bit Counter](https://github.com/user-attachments/assets/6183cf64-848f-475d-b1ff-6c7d3871f827)
<br>

   6. [Moving LEDs (One Way)](Blinky/movingled.c)<br>

In this tutorial, 8 LEDs are connected as the previous one but this time the LEDs are made to move from either **MSB to LSB** or **LSB to MSB**. Here, LEDs are moved from MSB to LSB. Configure GPIOA as the previous one connect LEDs as previous as well. Use Logical Shift Left (<<) for shifting bit from LSB to MSB.
- Set all configured pins to 0 initially.
- Use for loop with limit of 8 states.
- Shift a bit to left with delay of 1000 ms.
<br>**for(volatile int count = 0;count < 8;count++)**
<br> **{**
<br>  &emsp;**(GPIOA->ODR &= 0xFF00) |= (0x01 << count);**
<br>  &emsp;**for(volatile int i = 0;i < 1000000;i++);**
<br> **}**

<br>The circuit diagram is same as above one.
<br>The truth table for this tutorial is as shown.
|PA7|PA6|PA5|PA4|PA3|PA2|PA1|PA0|
|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
<br>

   7. [Moving LEDs (Back & Forth)](Blinky/movingled2way.c)<br>

This is same as previous one with added logic for moving LEDs in both ways i.e from **LSB to MSB** and **MSB to LSB**.
- Use two for loops one for moving MSB to LSB and another LSB to MSB.
<br>**for(volatile int count = 0;count < 8;count++)**
<br> **{**
<br>  &emsp;**(GPIOA->ODR &= 0xFF00) |= (0x01 << count);**
<br>  &emsp;**for(volatile int i = 0;i < 1000000;i++);**
<br> **}**
<br><br>**for(volatile int count = 0;count < 8;count++)**
<br> **{**
<br>  &emsp;**(GPIOA->ODR &= 0xFF00) |= (0x01 >> count);**
<br>  &emsp;**for(volatile int i = 0;i < 1000000;i++);**
<br> **}**

<br>The truth table for the tutoiral is given below.
|PA7|PA6|PA5|PA4|PA3|PA2|PA1|PA0|
|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|---|---|---|
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
<br>

   8. [Random LED(s) FLashing](Blinky/randomflashing.c)

This tutorial is about flashing LEDs in random pattern. For this the setup is same as the previous one. A random number is generated using SysTick timer. This timer is a 24-bit so, the 8 bit remainder from number generated is taken.
- Enable Systick Timer
- Configure Systick->LOAD to 0xFFFFFFFF and Systick->VAL = 0
- Set Systick->CTRL to enable timer.
<br>**Systick->CTRL = Systick_CTRL_CLKSOURCE_Msk | Systick_CTRL_ENABLE_Msk;**
- In while loop, pass the value from Systick->VAL to GPIOA->ODR
<br>**uint8_t random_value = (SysTick->VAL % 255) + 1;**
<br>**GPIOA->ODR = (GPIOA->ODR & 0xFF00) | random_value;**
- Use delay for observing the randomness generated.
<br>

   9. [Pushbutton Blinking](Blinky/pushbutton_blink.c)

In this tutorial, an external input is taken at PC15 and PB2 as output which is built-in LED. A pushbutton is connected at PC15 and set as input mode and PB as output mode. Here, the LED stays in ON state while the button is pressed. When button is released, the LED goes to OFF state.
- In while loop, use if condition to switch ON and OFF the LED.
<br>**if((GPIOC->IDR & (1 << 15)) == 0)**  
<br> **{**
<br> &emsp;**GPIOB->BSRR |= GPIO_BSRR_BS2; // Turn ON PB2 (LED)**
<br> **}**
<br>**else**
<br> **{**
<br>&emsp;**GPIOB->BSRR |= GPIO_BSRR_BR2; // Turn OFF PB2 (LED)**
<br> **}**

<br>The circuit diagram is as shown.
<br>
![PushButton Blink](https://github.com/user-attachments/assets/512f96df-2ee7-47e5-bc28-09aec61268a4)
<br>

   10. [7-Segment Display](Blinky/segment7display.c)

In this tutorial, a 7-segment display is interfaced with _BluePill_ for displaying numbers from 0 to 9. For this, 0.56 inch single digit 7-segment display is used. The below image is the pinout of the display.
<br>
![image](https://github.com/user-attachments/assets/9aa45fd8-5dad-4aa0-9ab9-8617b2428381)
<br>As shown there are ten pins in the module which are A to G and dot (DP) for 8 LEDs connected to these pins and two CC (_**Common Cathode**_) or CA (_**Common Anode**_) pins. CC or CA states how these LEDs are internally connected.
- Common Cathode (-) = LEDs are commonly connected ground.
- Common Anode (+) = LEDs are commonly connected to Vcc.

<br>For this tutorial, common cathode based display is used. Now there are 8 LEDs forming a shape of 8 as shown in the image. Each LED is connected to their respective pins. For displaying numbers, the pins of the appropriate LEDs are set. Given below table is the output data bits for respective pins for generating respective numbers from 0 to 9.
|NUM|Dot| G | F | E | D | C | B | A |
|---|---|---|---|---|---|---|---|---|
| 0 |1/0| 0 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 |1/0| 0 | 0 | 0 | 0 | 1 | 1 | 0 |
| 2 |1/0| 1 | 0 | 1 | 1 | 0 | 1 | 1 |
| 3 |1/0| 1 | 0 | 0 | 1 | 1 | 1 | 1 |
| 4 |1/0| 1 | 1 | 0 | 0 | 1 | 1 | 0 |
| 5 |1/0| 1 | 0 | 1 | 1 | 1 | 0 | 1 |
| 6 |1/0| 1 | 1 | 1 | 1 | 1 | 0 | 1 |
| 7 |1/0| 0 | 0 | 0 | 0 | 1 | 1 | 1 |
| 8 |1/0| 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 9 |1/0| 1 | 1 | 0 | 1 | 1 | 1 | 1 |

<br>GPIOA is taken as output mode push-pull configured. The pin mapping is from **PA7->Dot** to **PA0->A** where A is LSb and Dot is MSb. A volatile char array of the above table is taken where each number's 7-segment value is stored. After enabling and setting GPIOA, in while loop display all numbers with delay of 1000 ms.
<br>**for(volatile _int_ j = 0;j < 10;j++)**
<br> **{**
<br> &emsp;**GPIOA->*ODR* = num[j];**
<br> &emsp;**for(volatile _int_ i = 0;i < 1000000;i++);**
<br> **}**
<br>
<br>The circuit diagram is as shown.
<br>
![Segment 7 Display](https://github.com/user-attachments/assets/ba60a690-75b8-4002-a164-9d14128c5382)
<br>

   11. [4 digit 7-Segment Display](Blinky/segment7x4display.c)

This tutorial is same as previous one but here a four 7-segments are used instead of one. For this 0.56 inch 4x7-segment common _**cathode display**_ is used. The given below figure shows the display used and its pinout diagram.
<br>
![image](https://github.com/user-attachments/assets/c7b36705-786c-45af-b426-b23e7eac2277)
<br>
<br> As shown in image pins D1, D2, D3 and D4 are digit pins used to enable and disable the single digit segment. Note that display used is CC type meaning, to enable the digit the digit pin should be grounded. The data bit representation for their numbers are same as above. The only addition is of the four digit pins. The circuit diagram of the display is observed to have common anode lines for Vcc but different ground lines.
<br>
<br>If all four digits are grounded then the output display will have same number on all four digits. To overcome this issue, one digit is turned **_ON_** at a time for certain time period and then the next one and next one and so on. In this tutorial, a counter logic is designed for counting from 0000 to 9999 and display it on 7-segment.
<br>
<br>For this PA7 to PA0 is used as data pins and PB4 to PB7 is used as digit control pins. Enable and configure the pins of GPIOA and GPIOB. In while loop
- create a volatile variable count
- Take a for loop delay of 1000 ms
  - Create individual variables for each digit
  - Take a another for loop delay of 10 ms
    - Derive logic for extracting each digit from count.
    - Set the GPIOA->ODR to the digit extracted.
    - Enable the digit by set to digital LOW and other three to digital HIGH.

<br>**for(volatile int j = 0;j < 1000000;j++)**
<br> **{**
<br>&emsp;**while(count = 10000)**
<br>&emsp;&emsp;**count = 0;**
<br>&emsp;**volatile int digit0 = count%10;**&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;//Units digit at PB15
<br>&emsp;**volatile int digit1 = (count%100)/10;**&emsp;&emsp;//Tens LS digit at PB14
<br>&emsp;**volatile int digit2 = (count%1000)/100;**&emsp;&emsp;//Hundreds digit at PB13 
<br>&emsp;**volatile int digit3 = count/1000;**&emsp;&emsp;&emsp;&emsp;//Thousands digit at PB12
<br>
<br>&emsp;**for(volatile int i = 0;i < 10000;i++)**
<br>&emsp;**{**
<br>&emsp;&emsp;**GPIOB->ODR = 0x00000010;**
<br>&emsp;&emsp;**GPIOA->ODR = num[digit0];**
<br>&emsp; **}**
<br>
<br>&emsp;**for(volatile int i = 0;i < 10000;i++)**
<br>&emsp;**{**
<br>&emsp;**GPIOB->ODR = 0x00000020;**
<br>&emsp;**GPIOA->ODR = num[digit1];**
<br>&emsp;**}**
<br>
<br>&emsp;**for(volatile int i = 0;i < 10000;i++)**
<br>&emsp;**{**
<br>&emsp;&emsp;**GPIOB->ODR = 0x00000040;**
<br>&emsp;&emsp;**GPIOA->ODR = num[digit2];**
<br>&emsp;**}**
<br>&emsp;**for(volatile int i = 0;i < 10000;i++)**
<br>&emsp;**{**
<br>&emsp;&emsp;**GPIOB->ODR = 0x00000080;**
<br>&emsp;&emsp;**GPIOA->ODR = num[digit3];**
<br>&emsp;**}**
<br>&emsp;**count++;**
<br>

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
