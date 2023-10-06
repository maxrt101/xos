#ifndef _XOS_CONFIG_H_
#define _XOS_CONFIG_H_ 1

#include <xos/types.h>

typedef struct xos_config_t {
  const char* console;
} xos_config_t;

void xos_config_init();
void xos_config_set(xos_config_t* conf);
xos_config_t* xos_config_get();

#endif /* _XOS_CONFIG_H_ */