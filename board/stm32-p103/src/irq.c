#include <xos/asm.h>
#include <xos/types.h>
#include <board/register.h>
#include <xos/io.h>

#define IRQ_COUNT 59

extern void irq_handle(int irq);
extern void reset_handler();

void generic_irq_handler() {
  // TODO: save registers to stack
  u32 ipsr = get_ipsr();
  u8 irq_number = ipsr & 0xFF;
  irq_handle(irq_number);
}

ASM_SECTION(".isr_vector")
u32* isr_vectors[IRQ_COUNT] = {
  // (u32*) &_end_stack, // FIXME: ?
  0,
  (u32*) reset_handler,       // Reset
  (u32*) generic_irq_handler, // NMI
  (u32*) generic_irq_handler, // HardFault
  (u32*) generic_irq_handler, // MemManage
  (u32*) generic_irq_handler, // BusFault
  (u32*) generic_irq_handler, // UsageFault
  0,
  0,
  0,
  0,
  (u32*) generic_irq_handler, // SVCall
  (u32*) generic_irq_handler, // DebugMonitor
  0,
  (u32*) generic_irq_handler, // PendSV
  (u32*) generic_irq_handler, // SysTick
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler,
  (u32*) generic_irq_handler
};

