#include <xos/xos.h>
#include <xos/irq.h>
#include <xos/klog.h>
#include <xos/types.h>
#include <xos/board.h>
#include <xos/kalloc.h>
#include <xos/config.h>

#include <board/init.h>
#include <board/memory_map.h>

#include <stdio.h>
#include <string.h>

void tick() {
  klog_info("tick");
}

void kmain(void) {
  board_init();
  dev_init();

  xos_config_get()->console = "usart2";

  printf("xos dev %s\n", XOS_VERSION);

  klog_debug_on();

  klog_info("kernel end 0x%x", &_kernel_end);

  kalloc_init();

  irq_register_handler(IRQ_SYS_TICK, tick);

  // Tests

  void* var = kalloc(sizeof(i32));
  void* var2 = kalloc(sizeof(i32));

  i32* x = (i32*) var;
  i32* y = (i32*) var2;

  *x = 124;
  *y = 45003;

  printf("*x = %d\nx = 0x%x\n", *x, (u32) x);
  printf("*y = %d\ny = 0x%x\n", *y, (u32) y);

  kfree(var);
  kfree(var2);

  while (1) {}
}
