#include <xos/dev.h>
#include <xos/board.h>
#include <stddef.h>
#include <string.h>

void dev_blank(dev_t* dev) {
  if (!dev) {
    return;
  }

  dev->name = NULL;
  dev->type = NULL;
  dev->addr = 0;
  dev->size = 0;
  dev->init = NULL;
  dev->ctrl = NULL;
  dev->read = NULL;
  dev->write = NULL;
}

void dev_init() {
  board_t* board = get_board();

  if (!board) {
    return;
  }

  for (u32 i = 0; i < board->device_count; i++) {
    if (board->devices[i].init) {
      board->devices[i].init();
    }
  }
}

dev_t* dev_get(const char* name) {
  board_t* board = get_board();

  if (!board) {
    return NULL;
  }

  for (u32 i = 0; i < board->device_count; i++) {
    if (!strcmp(board->devices[i].name, name)) {
      return &board->devices[i];
    }
  }

  return NULL;
}
