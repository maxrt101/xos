#ifndef _XOS_BOARD_H_
#define _XOS_BOARD_H_ 1

#include <xos/types.h>
#include <xos/dev.h>

typedef struct board_t {
  char* name;
  char* model;
  char* manufacturer;
  char* arch;
  char* cpu;
  u32 irq_count;
  u32 device_count;
  dev_t* devices;
} board_t;

void set_board(board_t* board);
board_t* get_board();

#endif /* _XOS_BOARD_H_ */