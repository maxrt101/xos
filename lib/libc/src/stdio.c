#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <xos/io.h>

void printf(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
}

void vprintf(const char* fmt, va_list args) {
  size_t length = strlen(fmt);
  for (size_t i = 0; i < length; ++i) {
    char buff[32] = {0};
    if (fmt[i] == '%') {
      switch (fmt[i+1]) {
        case 'c':
          putc(va_arg(args, int));
          i++;
          break;
        case 's':
          puts(va_arg(args, const char*));
          i++;
          break;
        case 'b':
          puts(itoa(va_arg(args, int), buff, 2));
          i++;
          break;
        case 'o':
          puts(itoa(va_arg(args, int), buff, 8));
          i++;
          break;
        case 'd':
        case 'i':
          puts(itoa(va_arg(args, int), buff, 10));
          i++;
          break;
        case 'l':
          if (fmt[i+2] == 'x') {
            puts(lltoa(va_arg(args, long long), buff, 16));
            i++;
          } else if (fmt[i+2] == 'u') {
            puts(ulltoa(va_arg(args, unsigned long long), buff, 10));
            i++;
          } else if (fmt[i+2] == 'd' || fmt[i+2] == 'i') {
            puts(ulltoa(va_arg(args, long long), buff, 10));
            i++;
          } else {
            puts(lltoa(va_arg(args, long long), buff, 10));
          }
          i++;
          break;
        case 'u':
          puts(utoa(va_arg(args, unsigned), buff, 10));
          i++;
          break;
        case 'x':
        case 'X':
          puts(utoa(va_arg(args, unsigned), buff, 16));
          i++;
          break;
        case 'p':
          puts("0x");
          puts(utoa(va_arg(args, unsigned int), buff, 16));
          i++;
          break;
        default:
          putc('%');
          break;
      }
    } else {
      putc(fmt[i]);
    }
  }
}

void putc(const char c) {
  kputc(c);
}

int puts(const char* str) {
  kputs(str);
}
