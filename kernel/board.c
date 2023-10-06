#include <xos/board.h>
#include <stddef.h>

static board_t* s_board = NULL;

void set_board(board_t* board) {
  s_board = board;
}

board_t* get_board() {
  return s_board;
}
