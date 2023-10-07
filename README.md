```
   _  ______  _____
  | |/ / __ \/ ___/
  |   / / / /\__ \
 /   / /_/ /___/ /
/_/|_\____//____/

ARM32 Operating System for Microcontrollers
```

# About
XOS is a RTOS made specifically for microcontrollers that run on ARM32.  
It provides some APIs and abstractions that should make it easier to write bare-bones code for ARM32 SoCs.  

# How to compile
Prerequisies:  
 - Mac or Linux system  
 - `make`  
 - `arm-none-eabi-gcc`  

Steps:  
 - Clone the project  
 - Run `make`  
 - Output image can be found in `build/TARGET/bin/image.bin`  

The image is ready to be loaded directly into the flash.  

# Features
Currentry xos provides APIs for IRQ handling, devices (uart, i2c, etc) and memory.  
Features in development are - multitasking, command line user interface, libraries for networking, protocols, etc.  

# Targets
 - `stm32-p103`

Upcoming targets are raspberry pi 2, 3 and 4, versatilepb
