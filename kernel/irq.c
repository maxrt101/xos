#include <xos/irq.h>
#include <xos/klog.h>
#include <xos/types.h>
#include <stdio.h>
#include <string.h>

#define IRQ_COUNT 59 // FIXME:

irq_handler_t irq_vector[IRQ_COUNT] = {0};

void irq_handle(int irq) {
  klog_debug("irq: %d", irq);

  if (irq_vector[irq]) {
    irq_vector[irq]();
  }
}

void irq_register_handler(int irq, irq_handler_t handler) {
  irq_vector[irq] = handler;
}

void irq_remove_handler(int irq) {
  irq_vector[irq] = 0x0;
}
