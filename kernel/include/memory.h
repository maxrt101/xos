#ifndef _XOS_MEM_H_
#define _XOS_DEV_H_ 1

#include <xos/types.h>

#define MEM_KERNEL_BASE 0x80000000
#define MEM_PERIPHERALS_BASE (MEM_KERNEL_BASE + 0x40000000)

#define ROUND_DOWN(x, alignment) ((x) & ~((alignment) - 1))
#define ROUND_UP(x, alignment) (((x) + (alignment) - 1) & ~((alignment) - 1))

// Pages
#define MEM_PAGES_PER_SECTION 1024
#define MEM_SECTION_COUNT 4096
#define MEM_PAGE_SIZE 4096
#define MEM_SECTION_SIZE (MEM_PAGE_SIZE * MEM_PAGES_PER_SECTION)
#define MEM_INITIAL_MEMORY_SIZE 0x2000000 /* 32MB */

#define MEM_PAGE_TABLE_ALIGNMENT 1024
#define MEM_SECTION_TABLE_ALIGNMENT 16384
#define MEM_PAGE_TABLE_SIZE 1024
#define MEM_SECTION_TABLE_SIZE 16384

// Descriptor Types
#define MEM_DESCRIPTOR_SECTION 0x1
#define MEM_DESCRIPTOR_PAGE 0x2

// Access
#define MEM_ACCESS_RW_D 0x55
#define MEM_ACCESS_RW_R 0xaa
#define MEM_ACCESS_RW_RW 0xff

typedef struct mem_section_t {
  u32 type : 2;
  u32 : 3;
  u32 domain : 4;
  u32 : 1;
  u32 base_addr : 22;
} mem_section_t;

typedef struct mem_page_t {
  u32 type : 2;
  u32 bufferable : 1;
  u32 cachable : 1;
  u32 access : 8;
  u32 base_addr : 20;
} mem_page_t;

typedef struct mem_mapping_t {
  u32 virt_addr;
  u32 phys_start;
  u32 phys_end;
  u32 access;
} mem_mapping_t;

void mem_init();

#endif /* _XOS_DEV_H_ */