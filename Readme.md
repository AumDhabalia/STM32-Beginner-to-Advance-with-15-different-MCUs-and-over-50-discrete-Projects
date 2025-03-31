# STM32 Bare Metal Programming using Keil uVision-5 IDE
## From Beginner to Advance on 17 different MCUs and over 50 Dedicated Projects
**In this repository, STM32 microcontrollers are programmed using ARM Keil uVision-5 IDE. It contains all the bare-metal programs for STM32 microcontrollers written from scratch using ARM Keil uVision-5 IDE.**
It includes introductory section of different MCU families to simultaneous operation of multiple blocks to dedicated project. Each of the program contains dedicated procedure including step-by-step process, components used, pin assignment & circuit diagram.
<br>
## Index
1. Introduction
   1. Introduction to STM32 MCUs
   2. List of STM32 Boards
2. Keil IDE
   1. Introduction
   2. Installation
   3. Project Setup
3. STM32 Projects
   1. Force Feedback Steering Wheel and Paddles
   2. Electromagentic Coil Gun
   3. Audio Spectrum Analyzer
   4. Signal Generator
   5. Anti Air Defence System
   6. Smart Home Automation
   7. Oscilloscope
   8. Remote Controlled Drone
   9. Plasma Boosted Drone
   10. Unmanned Marine vehicle
   11. Unmanned Combat Ground Vehicle (RC Battle Tank)

# 1. Introduction
## *Introduction to STM32 Family*



## *List of STM32 Boards...*

1. STM32C031C6 *NUCLEO-64*...............................**(Pending)**
2. STM32F051R8T6 *Discovery*.............................**(Pending)**
3. [STM32F103C8T6 *BluePill*](STM32F103C8T6).............*(In Progress)* <br>
4. STM32F207ZG *NUCLEO-144*..................................**(Pending)** <br>
5. STM32F334C8T6 *Discovery*.............................**(Pending)** <br>
6. STM32F411CEU6 *BlackPill*.............................**(Pending)** <br>
7. STM32F722ZE *NUCLEO-144*..............................**(Pending)** <br>
8. STM32G070RB *NULCEO-64*...............................**(Pending)** <br>
9. STM32G431KB *NUCLEO-32*...............................**(Pending)** <br>
10. STM32H503RB *NUCLEO-64*..............................**(Pending)** <br>
11. STM32H755ZI-Q *NUCLEO-144*...........................**(Pending)** <br>
12. STM32L031K6 *NUCLEO-32*..............................**(Pending)** <br>
13. STM32L152RE *NUCLEO-64*..............................**(Pending)** <br>
14. STM32L412KB *NUCLEO-32*..............................**(Pending)** <br>
15. STM32L552ZE-Q *NUCLEO-144*...........................**(Pending)** <br>
16. STM32U031R8 *NUCLEO-64*..............................**(Pending)** <br>
17. STM32U385RG-Q *NUCLEO-64*............................**(Pending)** <br>
<br>

# 2. Keil IDE
## Introduction
## Keil Installation
1. Download [Keil](https://www.keil.com/demo/eval/arm.htm)
<br/>![image](https://github.com/user-attachments/assets/43740124-5409-403b-9577-ed97e7dc00d0)

2. Right click on the file and run as administrator
<br/>![Step](https://github.com/user-attachments/assets/d06743c2-8f2d-4e8c-85b2-d2ee5520ff3e)

3. Click Next, Click on I Agree, Change Directories if required
4. Fillup the details
<br/>![image](https://github.com/user-attachments/assets/391b2c45-c876-4e2a-88ec-a3e38a11e280)

5. Wait for installation to complete
6. Installation Complete

## Project Setup
1. Start Keil uVision.
2. Go to Projects->New uVision Projects
<br>![image](https://github.com/user-attachments/assets/99590765-830d-410a-b37f-0eeaba7828a1)

3. Write name of the project (*Change directory or folder if needed*).<br>
4. In Target search for the MCU. Select the MCU. Click on Next.
<br>![Screenshot 2025-03-27 195257](https://github.com/user-attachments/assets/05eb6bbc-3019-45a8-99cc-441c1be32a2b)
5. In Manage Run Time Enviroment select on CMSIS->Core and Device->Startup. Make sure to install stable version of the pack otherwise the Startup file won't appear. Once done click on OK.
<br>![Screenshot 2025-03-27 195341](https://github.com/user-attachments/assets/72cb737d-e1fd-4a79-9e0c-69389350f3e2)
6. On Left panel navigate to Target_1->Device. Startup files should be displayed.
<br>![image](https://github.com/user-attachments/assets/987327d4-c52e-4ece-9fae-2ba354068a4a)
<br>
7. Create new text file by pressing Ctrl+N or by navigating to File->New. Save this file as main.c and add it to Source Group 1. Double click on Source Group 1 and search for main.c and then click Add. Its done.
