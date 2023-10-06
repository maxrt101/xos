#ifndef _XOS_LIBC_DIVMOD_H_
#define _XOS_LIBC_DIVMOD_H_ 1

#include <stdint.h>

typedef struct divmod_result_t {
  uint32_t quotient;
  uint32_t remainder;
} divmod_result_t;

divmod_result_t ldivmod(int64_t numerator, int64_t denominator);
divmod_result_t uldivmod(uint64_t numerator, uint64_t denominator);

#endif /* _XOS_LIBC_DIVMOD_H_ */