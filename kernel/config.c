#include <xos/config.h>
#include <string.h>
#include <stddef.h>

static xos_config_t s_config;

void xos_config_init() {
  s_config.console = NULL;
}

void xos_config_set(xos_config_t* conf) {
  memcpy(&s_config, conf, sizeof(xos_config_t));
}

xos_config_t* xos_config_get() {
  return &s_config;
}
