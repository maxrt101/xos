#ifndef _STM32_P103_REGISTER_FLAGS_H_
#define _STM32_P103_REGISTER_FLAGS_H_ 1

#include <xos/types.h>
#include <board/memory_map.h>

// RCC_CR FLags
#define RCC_CR_HSION        ((u32) 0x00000001)  // Internal High Speed clock enable 
#define RCC_CR_HSEON        ((u32) 0x00010000)  // External High Speed clock enable 
#define RCC_CR_HSERDY       ((u32) 0x00020000)  // External High Speed clock ready flag 
#define RCC_CR_CSSON        ((u32) 0x00080000)  // Clock Security System enable 

// RCC_CFGR Flags
#define RCC_CFGR_SW         ((u32) 0x00000003)  // SW[1:0] bits (System clock Switch) 
#define RCC_CFGR_SW_HSE     ((u32) 0x00000001)  // HSE selected as system clock 
#define RCC_CFGR_SWS        ((u32) 0x0000000C)  // SWS[1:0] bits (System Clock Switch Status) 
#define RCC_CFGR_HPRE_DIV1  ((u32) 0x00000000)  // SYSCLK not divided 
#define RCC_CFGR_PPRE1_DIV1 ((u32) 0x00000000)  // HCLK not divided 
#define RCC_CFGR_PPRE2_DIV1 ((u32) 0x00000000)  // HCLK not divided 

// FLASH_ACR Flags
#define FLASH_ACR_LATENCY   ((u8) 0x03)         // LATENCY[2:0] bits (Latency)
#define FLASH_ACR_LATENCY_0 ((u8) 0x00)         // Bit 0
#define FLASH_ACR_PRFTBE    ((u8) 0x10)         // Prefetch Buffer Enable 

#define HSE_STARTUP_TIMEOUT ((u16) 0x0500)      // Time out for HSE start up 

// USART Flags
#define USART_FLAG_TXE	    ((u16) 0x0080)

#endif // _STM32_P103_REGISTER_FLAGS_H_