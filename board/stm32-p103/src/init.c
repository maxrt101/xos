#include <board/init.h>
#include <board/memory_map.h>
#include <board/flags.h>
#include <xos/types.h>
#include <xos/board.h>

board_t stm32_p103;
dev_t devices[32] = {0};

extern void clock_init();
extern void timer_init();
extern void usart2_init();
extern void usart2_write(u8);

void board_init() {
  stm32_p103.name = "stm32-p103";
  stm32_p103.model = "stm32-p103";
  stm32_p103.manufacturer = "STMicroelectronics";
  stm32_p103.arch = "arm32";
  stm32_p103.cpu = "cortex-m3";
  stm32_p103.irq_count = 59;
  stm32_p103.device_count = 5;

  dev_blank(&devices[0]);
  devices[0].name = "ram";
  devices[0].type = "ram";
  devices[0].tags[0] = DEV_TAG_MEM_INIT;
  devices[0].addr = 0x20000000;
  devices[0].size = 0x5000;

  dev_blank(&devices[1]); // FIXME: is needed without vmm?
  devices[1].name = "peripherals";
  devices[1].type = "peripherals";
  devices[1].tags[0] = DEV_TAG_MEM_INIT;
  devices[1].addr = 0x40000000;
  devices[1].size = 0x23400;

  dev_blank(&devices[2]);
  devices[2].name = "clock";
  devices[2].type = "clock";
  devices[2].init = clock_init;

  dev_blank(&devices[3]);
  devices[3].name = "timer";
  devices[3].type = "timer";
  devices[3].init = timer_init;

  dev_blank(&devices[4]);
  devices[4].name = "usart2";
  devices[4].type = "usart";
  devices[4].tags[0] = DEV_TAG_IO;
  devices[4].init = usart2_init;
  devices[4].write = usart2_write;

  stm32_p103.devices = devices;
  set_board(&stm32_p103);
}
