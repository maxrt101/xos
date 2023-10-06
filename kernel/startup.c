#include <xos/types.h>
#include <xos/asm.h>
#include <board/memory_map.h>

extern void kmain(void);

void reset_handler(void) {
  // Copy data segment init from flash to ram 
  u32* init_data_start = &_init_data_start;
  u32* data_start = &_data_start;
  u32* data_end = &_data_end;

  while (data_start < data_end) {
    *data_start++ = *init_data_start++;
  }

  // Zero bss
  u32* bss_start = &_bss_start;
  u32* bss_end = &_bss_end;

  while (bss_start < bss_end) {
    *bss_start++ = 0;
  }

  kmain();
}
