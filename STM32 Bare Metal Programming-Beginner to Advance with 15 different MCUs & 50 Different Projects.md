# STM32 Bare Metal Programming
## From Beginner to Advance on 15 different MCUs and over 50 Different Projects
**Projects based on STM32 Boards
<br>This repository contains all the programs related to STM32 based bare-metal programming using *STM32 Boards*.**
<br>
<br>**Pre-Requisites**
<br>Download and install Keil MDK_ARM from [here](https://www.keil.com/demo/eval/arm.htm) on your system. This will install non-commercial version of MDK_ARM.
<br>Open Pack Installer and install package for necesssary MCU from the list. ***Make sure to install the pack that contains the startup files.<br/>Generally base version contains the Startup file for the required MCU.***
<br>
## *List of STM32 Boards*...
1. STM32C031C6 *NUCLEO-64*...............................**(Pending)**
2. STM32F051R8T6 *Discovery*.............................**(Pending)**
3. [STM32F103C8T6 *BluePill*](STM32F103C8T6).............*(In Progress)*
4. STM32F207ZG *NUCLEO*..................................**(Pending)**
5. STM32F334C8T6 *Discovery*.............................**(Pending)**
6. STM32F411CEU6 *BlackPill*.............................**(Pending)**
7. STM32F722ZE *NUCLEO-144*..............................**(Pending)**
8. STM32G070RB *NULCEO-64*...............................**(Pending)**
9. STM32G431KB *NUCLEO-32*...............................**(Pending)**
10. STM32H503RB *NUCLEO-64*..............................**(Pending)**
11. STM32H755ZI-Q *NUCLEO-144*...........................**(Pending)**
12. STM32L031K6 *NUCLEO-32*..............................**(Pending)**
13. STM32L152RE *NUCLEO-64*..............................**(Pending)**
14. STM32L412KB *NUCLEO-32*..............................**(Pending)**
15. STM32L552ZE-Q *NUCLEO-144*...........................**(Pending)**
16. STM32U031R8 *NUCLEO-64*..............................**(Pending)**
17. STM32U385RG-Q *NUCLEO-64*............................**(Pending)**
<br>

## Keil Installation Procedure
1. Download [Keil](https://www.keil.com/demo/eval/arm.htm)
<br/>![image](https://github.com/user-attachments/assets/43740124-5409-403b-9577-ed97e7dc00d0)

2. Right click on the file and run as administrator
<br/>![Step](https://github.com/user-attachments/assets/d06743c2-8f2d-4e8c-85b2-d2ee5520ff3e)

3. Click Next, Click on I Agree, Change Directories if required
4. Fillup the details
<br/>![image](https://github.com/user-attachments/assets/391b2c45-c876-4e2a-88ec-a3e38a11e280)

5. Wait for installation to complete
6. Installation Complete
## Project Creation on Keil
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
