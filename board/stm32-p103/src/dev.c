#include <board/memory_map.h>
#include <board/flags.h>
#include <xos/types.h>

/* 72MHz */
#define CPU_CLOCK_HZ 72000000

/* 100 ms per tick. */
#define TICK_RATE_HZ 10

void clock_init() {
  *RCC_CR |= (u32) 0x00000001;   // Reset RCC clock (and set HSION)
  *RCC_CFGR &= (u32) 0xF8FF0000; // Reset SW HPRE PPRE1 PPRE2 ADCPRE MCO
  *RCC_CR &= (u32) 0xFEF6FFFF;   // Reset HSEON CSSON PLLON
  *RCC_CR &= (u32) 0xFFFBFFFF;   // Reset HSEBYP
  *RCC_CFGR &= 0xFF80FFFF;       // Reset PLLSRC PLLXTPRE PLLMUL USBPRE/OTGFSPRE
  *RCC_CIR = 0x009F0000;         // Disable interrupts and clear pending

  volatile u32 startup_counter = 0, hse_status = 0;

  *RCC_CR |= (u32) RCC_CR_HSEON; // Enable HSE 

  // Wait for HSE
  do {
    hse_status = *RCC_CR & RCC_CR_HSERDY;
    startup_counter++;
  } while (hse_status == 0 && startup_counter < HSE_STARTUP_TIMEOUT);

  if ((*RCC_CR & RCC_CR_HSERDY) != 0) {
    hse_status = 0x1;
  } else {
    hse_status = 0x0;
  }

  if (hse_status == 0x1) {
    *FLASH_ACR |= FLASH_ACR_PRFTBE;         // Enable prefetch buffer
    *FLASH_ACR &= (u32) ~FLASH_ACR_LATENCY; // Flash 0 wait state
    *FLASH_ACR |= (u32) FLASH_ACR_LATENCY_0;
    *RCC_CFGR |= RCC_CFGR_HPRE_DIV1;        // HCLK = SYSCLK
    *RCC_CFGR |= RCC_CFGR_PPRE2_DIV1;       // PCLK2 = HCLK
    *RCC_CFGR |= RCC_CFGR_PPRE1_DIV1;       // PCLK1 = HCLK
    *RCC_CFGR &= ~RCC_CFGR_SW;              // Set HSE as system clock
    *RCC_CFGR |= RCC_CFGR_SW_HSE;

    // Wait for HSE to be used as system clock
    while ((*RCC_CFGR & RCC_CFGR_SWS) != 0x4) {}
  } else {
    /* HSE startup failure */
  }
}

void timer_init() {
  *SYSTICK_LOAD = (CPU_CLOCK_HZ / TICK_RATE_HZ) - 1UL;
  *SYSTICK_VAL = 0;
  *SYSTICK_CTRL = 0x07;
}

void usart2_init() {
  *(RCC_APB2ENR) |= (u32) (0x00000001 | 0x00000004);
	*(RCC_APB1ENR) |= (u32) (0x00020000);

	// /* USART2 Configuration, Rx->PA3, Tx->PA2 */
	GPIOA[GPIO_CRL] = 0x00004B00;
	GPIOA[GPIO_CRH] = 0x44444444;
	GPIOA[GPIO_ODR] = 0x00000000;
	GPIOA[GPIO_BSRR] = 0x00000000;
	GPIOA[GPIO_BRR] = 0x00000000;

	USART2[USART_CR1] = 0x0000000C;
	USART2[USART_CR2] = 0x00000000;
	USART2[USART_CR3] = 0x00000000;
	USART2[USART_CR1] |= 0x2000;
}

void usart2_write(u8 c) {
  while (!(USART2[USART_SR] & USART_FLAG_TXE)) {}
  USART2[USART_DR] = c;
}