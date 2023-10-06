#include <xos/memory.h>
#include <board/memory_map.h>

#define PHYS_TO_VIRT(x) (((u32) (x)) + &_kernel_start)
#define VIRT_TO_PHYS(x) (((u32) (x)) - &_kernel_start)

#define SECTION_INDEX(x) ((u32) (x) >> 20)
#define PAGE_INDEX(x) (((u32) (x) >> 12) & 0xff)
#define PAGE_TABLE_TO_BASE(x) ((u32) (x) >> 10)
#define BASE_TO_PAGE_TABLE(x) ((void*) ((u32) (x) << 10))
#define PAGE_TO_BASE(x) ((u32) (x) >> 12)

// #define VMM_OFFSET_IN_DIRECTORY(a) (((a) >> 20) & 0xfff)
// #define VMM_OFFSET_IN_TABLE(a) (((a) >> 12) & 0xff)
// #define VMM_OFFSET_IN_PAGE(a) ((a)&0xfff)
// #define TABLE_START(vaddr) ((vaddr >> 20) << 20)
// #define PAGE_START(vaddr) ((vaddr >> 12) << 12)
// #define FRAME(addr) (addr / VMM_PAGE_SIZE)


static mem_mapping_t s_memory_mappings[16] = {0};

void mem_init() {
  s_memory_mappings[0].virt_addr = MEM_KERNEL_BASE;
  s_memory_mappings[0].phys_start = 0;
  s_memory_mappings[0].phys_end = VIRT_TO_PHYS(&_kernel_end);
  s_memory_mappings[0].access = MEM_ACCESS_RW_D;

  s_memory_mappings[1].virt_addr = MEM_PERIPHERALS_BASE;
  s_memory_mappings[1].phys_start = BOARD_MEM_PERIPHERALS_START;
  s_memory_mappings[1].phys_end = BOARD_MEM_PERIPHERALS_START + BOARD_MEM_PERIPHERALS_SIZE;
  s_memory_mappings[1].access = MEM_ACCESS_RW_D;

  s_memory_mappings[2].virt_addr = BOARD_RAM_START;
  s_memory_mappings[2].phys_start = BOARD_RAM_START;
  s_memory_mappings[2].phys_end = BOARD_RAM_START + BOARD_RAM_SIZE;
  s_memory_mappings[2].access = MEM_ACCESS_RW_D;


}

//
