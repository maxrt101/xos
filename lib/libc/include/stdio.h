#ifndef _XOS_LIBC_STDIO_H_
#define _XOS_LIBC_STDIO_H_ 1

#include <stdarg.h>
#include <xos/dev.h>

void printf(const char* fmt, ...);
void vprintf(const char* fmt, va_list args);

void putc(const char c);
int puts(const char* str);

#endif /* _XOS_LIBC_STDIO_H_ */