#include <xos/klog.h>
#include <stdbool.h>
#include <stdio.h>

static bool s_klog_debug = false;

void klog_debug_on() {
  s_klog_debug = true;
}

void klog_debug_off() {
  s_klog_debug = false;
}

void kvlog(klog_log_level_t log_level, const char* fmt, va_list args) {
  if (log_level == KLOG_DEBUG && !s_klog_debug) {
    return;
  }

  switch (log_level) {
    case KLOG_DEBUG:
      puts("[debug] ");
      break;
    case KLOG_INFO:
      puts("[info] ");
      break;
    case KLOG_WARNING:
      puts("[warn] ");
      break;
    case KLOG_ERROR:
      puts("[error] ");
      break;
    case KLOG_FATAL:
      puts("[fatal] ");
      break;
    default:
      printf("[%d] ", log_level);
      break;
  }
  vprintf(fmt, args);
  putc('\n');
}

void klog(klog_log_level_t log_level, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  kvlog(log_level, fmt, args);
  va_end(args);
}

void klog_debug(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  kvlog(KLOG_DEBUG, fmt, args);
  va_end(args);
}

void klog_info(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  kvlog(KLOG_INFO, fmt, args);
  va_end(args);
}

void klog_warning(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  kvlog(KLOG_WARNING, fmt, args);
  va_end(args);
}

void klog_error(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  kvlog(KLOG_ERROR, fmt, args);
  va_end(args);
}

void klog_fatal(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  kvlog(KLOG_FATAL, fmt, args);
  va_end(args);
}
