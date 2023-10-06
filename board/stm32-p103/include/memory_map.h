#ifndef _STM32_P103_MEMORY_MAP_H_
#define _STM32_P103_MEMORY_MAP_H_ 1

#include <xos/types.h>

// RCC Memory Map 
#define RCC           ((volatile u32) 0x40021000)
#define RCC_CR        ((volatile u32*) (RCC + 0x00))
#define RCC_CFGR      ((volatile u32*) (RCC + 0x04))
#define RCC_CIR       ((volatile u32*) (RCC + 0x08))
#define RCC_APB2RSTR  ((volatile u32*) (RCC + 0x0C))
#define RCC_APB1RSTR  ((volatile u32*) (RCC + 0x10))
#define RCC_AHBENR    ((volatile u32*) (RCC + 0x14))
#define RCC_APB2ENR   ((volatile u32*) (RCC + 0x18))
#define RCC_APB1ENR   ((volatile u32*) (RCC + 0x1C))
#define RCC_BDCR      ((volatile u32*) (RCC + 0x20))
#define RCC_CSR       ((volatile u32*) (RCC + 0x24))

// Flash Memory Map 
#define FLASH         ((volatile u32) 0x40022000)
#define FLASH_ACR     ((volatile u32*) (FLASH + 0x00))

// GPIO Memory Map 
#define GPIOA         ((volatile u32*) 0x40010800)
#define GPIOB         ((volatile u32*) 0x40010C00)
#define GPIOC         ((volatile u32*) 0x40011000)
#define GPIOD         ((volatile u32*) 0x40011400)
#define GPIOE         ((volatile u32*) 0x40011800)

#define GPIO_CRL      0x00
#define GPIO_CRH      0x01
#define GPIO_IDR      0x02
#define GPIO_ODR      0x03
#define GPIO_BSRR     0x04
#define GPIO_BRR      0x05
#define GPIO_LCKR     0x06

// USART Memory Map
#define USART1        ((volatile u32*) 0x40013800)
#define USART2        ((volatile u32*) 0x40004400)
#define USART3        ((volatile u32*) 0x40004800)

#define USART_SR      0x00
#define USART_DR      0x01
#define USART_BRR     0x02
#define USART_CR1     0x03
#define USART_CR2     0x04
#define USART_CR3     0x05
#define USART_GTPR    0x06

// SysTick Memory Map
#define SYSTICK		    ((volatile u32) 0xE000E010)
#define SYSTICK_CTRL	((volatile u32*) (SYSTICK + 0x00))
#define SYSTICK_LOAD	((volatile u32*) (SYSTICK + 0x04))
#define SYSTICK_VAL	  ((volatile u32*) (SYSTICK + 0x08))
#define SYSTICK_CALIB	((volatile u32*) (SYSTICK + 0x0C))

// Addresses from ld file

extern u32 _text_start;
extern u32 _text_end;
extern u32 _init_data_start;
extern u32 _data_start;
extern u32 _data_end;
extern u32 _bss_start;
extern u32 _bss_end;
extern u32 _isr_vector_start;
extern u32 _isr_vector_end;
extern u32 _kernel_start;
extern u32 _kernel_end;
extern u32 _stack_end;

#endif // _STM32_P103_MEMORY_MAP_H_