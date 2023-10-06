# xos
export TOPDIR    := $(shell pwd)

include $(TOPDIR)/.config

export TARGET    := $(CONFIG_TARGET)
export BUILD_DIR := $(TOPDIR)/build/$(TARGET)

include $(TOPDIR)/board/$(TARGET)/build.mk

export TARGET_CFLAGS += -I$(BUILD_DIR)/include \
	-nostdlib \
	-fno-builtin-strlen \
	-fno-builtin-printf -fno-builtin-vprintf -fno-builtin-puts -fno-builtin-putc \
	-fno-builtin-memcmp -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-memmove

export IMAGE     := $(BUILD_DIR)/bin/image.bin
export KERNEL    := $(BUILD_DIR)/bin/kernel.bin
export BOARD     := $(BUILD_DIR)/bin/board.o
export LIBC      := $(BUILD_DIR)/bin/libc.o

.PHONY: image kernel board kernel-headers qemu clean

image: kernel
	$(info [+] image)
	cp $(KERNEL) $(IMAGE)

kernel: board
	$(info [+] kernel)
	make -C kernel

board: libc
	$(info [+] board)
	make -C board

libc: kernel-headers
	$(info [+] libc)
	make -C lib/libc

kernel-headers: prepare
	rm -rf $(BUILD_DIR)/include/xos
	cp -r $(TOPDIR)/kernel/include $(BUILD_DIR)/include/xos
	rm -rf $(BUILD_DIR)/include/board
	cp -r $(TOPDIR)/board/$(TARGET)/include $(BUILD_DIR)/include/board

prepare: build-info
	mkdir -p $(TOPDIR)/build
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/bin
	mkdir -p $(BUILD_DIR)/include
	mkdir -p $(BUILD_DIR)/lib

build-info:
	echo "xos v0.1.0 target $(TARGET)"

qemu:
	~/dev/build/qemu_stm32/arm-softmmu/qemu-system-arm -M stm32-p103 -nographic -kernel $(IMAGE)

clean:
	rm -rf $(BUILD_DIR)

$(V).SILENT:
