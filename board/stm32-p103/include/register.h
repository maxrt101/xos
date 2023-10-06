#ifndef _STM32_P103_REGISTER_H_
#define _STM32_P103_REGISTER_H_ 1

#include <xos/types.h>

static inline u32 get_ipsr() {
  volatile u32 result = 0;
  __asm__("MRS %0, ipsr" : "=r"(result));
  return result;
}

#endif /* _STM32_P103_REGISTER_H_ */