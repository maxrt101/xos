#include <xos/kalloc.h>
#include <xos/types.h>
#include <xos/abort.h>
#include <xos/klog.h>
#include <xos/dev.h>
#include <board/memory_map.h>
#include <string.h>
#include <stdio.h>

#define MEMBLOCK_ALIGN 0x100
#define KALLOC_ALIGN 4

#define ROUND_DOWN(x, alignment) ((x) & ~((alignment) - 1))
#define ROUND_UP(x, alignment) (((x) + (alignment) - 1) & ~((alignment) - 1))

typedef enum kalloc_flags_t {
  KALLOC_USED = 0x1
} kalloc_flags_t;

typedef struct kalloc_memblock_t {
  struct kalloc_memblock_t* next;
  u32 size;
  u32 flags;
} kalloc_memblock_t;

static kalloc_memblock_t* s_blocks = NULL;

void kalloc_init() {
  dev_t* ram = dev_get("ram");

  if (!ram) {
    klog_fatal("Can't retrieve ram device");
    abort();
  }

  kalloc_setup((u32) &_kernel_end, ram->addr + ram->size);
}

void kalloc_setup(u32 start, u32 end) {
  u8* start_addr = (u8*) ROUND_UP(start, MEMBLOCK_ALIGN);
  u8* end_addr = (u8*) ROUND_DOWN(end, MEMBLOCK_ALIGN);

  kalloc_memblock_t* block = (kalloc_memblock_t*) start_addr;

  block->next = NULL;
  block->size = end_addr - start_addr;
  block->flags = 0;

  klog_info("kalloc_setup: start=0x%x end=0x%x block=0x%x size=0x%x",
    start_addr, end_addr, (u32)block, block->size);

  s_blocks = block;
}

// TODO: test
static void kdefrag(kalloc_memblock_t* block) {
  if (!block) {
    return;
  }

  if (!(block->flags & KALLOC_USED)) {
    if (block->next && !(block->next->flags & KALLOC_USED)) {
      klog_debug("kdefrag: merging %p(size=%u) and %p(size=%u)", block, block->size, block->next, block->next->size);
      block->next = block->next->next;
      block->size += block->next->size;
      kdefrag(block);
    }
  }

  kdefrag(block->next);
}

static void* _kalloc(kalloc_memblock_t* block, size_t size) {
  if (!block) {
    klog_error("kalloc: bad block");
    return NULL;
  }

  if (block->flags & KALLOC_USED) {
    if (block->next) {
      return _kalloc(block->next, size);
    }
    return NULL;
  } else {
    if (block->size > size) {
      kalloc_memblock_t* new_block = (kalloc_memblock_t*) ( ((u8*) block) + block->size - size - sizeof(kalloc_memblock_t));
      new_block->next = NULL;
      new_block->size = size;
      new_block->flags = KALLOC_USED;
      block->next = new_block;
      u32 result = (((u32) new_block) - sizeof(kalloc_memblock_t));
      klog_debug("kalloc(%p, %d) block=%p result=0x%x", block, size, new_block, result);
      return (void*) result;
    } else {
      if (block->next) {
        return _kalloc(block->next, size);
      }
      return NULL;
    }
  }
}

void* kalloc(size_t size) {
  return _kalloc(s_blocks, ROUND_UP(size, KALLOC_ALIGN));
}

static void _kfree(kalloc_memblock_t* block, void* ptr) {
  if (!block) {
    klog_error("kfree: bad block");
    return;
  }

  if (ptr == (u8*) block - sizeof(kalloc_memblock_t)) {
    klog_debug("kfree(%p) block=0x%x size=0x%x", ptr, block, block->size);
    block->flags &= ~KALLOC_USED;
  } else {
    if (block->next) {
      _kfree(block->next, ptr);
    }
  }
}

void kfree(void* ptr) {
  _kfree(s_blocks, ptr);
  kdefrag(s_blocks);
}
