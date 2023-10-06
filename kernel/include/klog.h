#ifndef _XOS_KLOG_H_
#define _XOS_KLOG_H_ 1

#include <stdarg.h>

typedef enum klog_log_level_t {
  KLOG_DEBUG,
  KLOG_INFO,
  KLOG_WARNING,
  KLOG_ERROR,
  KLOG_FATAL,
} klog_log_level_t;

void klog(klog_log_level_t log_level, const char* fmt, ...);
void kvlog(klog_log_level_t log_level, const char* fmt, va_list args);

void klog_debug(const char* fmt, ...);
void klog_info(const char* fmt, ...);
void klog_warning(const char* fmt, ...);
void klog_error(const char* fmt, ...);
void klog_fatal(const char* fmt, ...);

void klog_debug_on();
void klog_debug_off();

#endif /* _XOS_KLOG_H_ */