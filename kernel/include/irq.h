#ifndef _XOS_IRQ_H_
#define _XOS_IRQ_H_ 1

#define IRQ_NMI 2
#define IRQ_HARD_FAULT 3
#define IRQ_MEM_MANAGE 4
#define IRQ_BUS_FAULT 5
#define IRQ_USAGE_FAULT 6
#define IRQ_SVCALL 11
#define IRQ_DEBUG_MONITOR 12
#define IRQ_PENDSV 14
#define IRQ_SYS_TICK 15

typedef void (*irq_handler_t)();

void irq_handle(int irq);
void irq_register_handler(int irq, irq_handler_t handler);
void irq_remove_handler(int irq);

#endif /* _XOS_IRQ_H_ */