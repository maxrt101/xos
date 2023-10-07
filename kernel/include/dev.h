#ifndef _XOS_DEV_H_
#define _XOS_DEV_H_ 1

#include <xos/types.h>
#include <stdbool.h>

#define DEV_TAG_MEM_INIT "mem_init"
#define DEV_TAG_IO "io"

typedef void (*dev_init_fn_t)();
typedef u32 (*dev_ctrl_fn_t)(u32, void*);
typedef u8 (*dev_read_fn_t)();
typedef void (*dev_write_fn_t)(u8);

typedef struct dev_t {
  char* name;
  char* type;
  u32 addr;
  u32 size;
  dev_init_fn_t init;
  dev_ctrl_fn_t ctrl;
  dev_read_fn_t read;
  dev_write_fn_t write;
} dev_t;

void dev_blank(dev_t* dev);
void dev_init();
dev_t* dev_get(const char* name);

#endif /* _XOS_DEV_H_ */