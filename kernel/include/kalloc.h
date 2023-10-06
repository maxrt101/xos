#ifndef _XOS_KALLOC_H_
#define _XOS_KALLOC_H_ 1

#include <xos/types.h>
#include <stdlib.h>
#include <stddef.h>

void kalloc_init();
void kalloc_setup(u32 start, u32 end);

void* kalloc(size_t size);
void kfree(void* ptr);

#endif /* _XOS_KALLOC_H_ */