#ifndef _XOS_LIBC_STDBOOL_H_
#define _XOS_LIBC_STDBOOL_H_ 1

#if defined(_Bool)
#define bool _Bool
#else
#define bool u8
#endif

#define true 1
#define false 0

#endif /* _XOS_LIBC_STDBOOL_H_ */