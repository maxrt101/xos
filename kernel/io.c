#include <xos/io.h>
#include <xos/dev.h>
#include <xos/config.h>

int kputc(const char c) {
  const char* console = xos_config_get()->console;

  if (!console) {
    return 1;
  }

  dev_t* dev = dev_get(console);

  if (!dev) {
    return 2;
  }

  dev->write(c);

  return 0;
}

int kputs(const char* str) {
  const char* console = xos_config_get()->console;

  if (!console) {
    return 1;
  }

  dev_t* dev = dev_get(console);

  if (!dev) {
    return 2;
  }

  while (*str) {
    dev->write(*str++);
  }

  return 0;
}
