# xos kernel

include $(TOPDIR)/include/utils.mk

PKG := kernel
SRC := main.c startup.c irq.c board.c dev.c kalloc.c config.c io.c klog.c abort.c
TARGET_CFLAGS += -DXOS_KERNEL=1 $(call GetConfigOptionsByPrefix,CONFIG_KERNEL)

include $(TOPDIR)/include/package.mk

define Package/Build
	$(TARGET_CC) $(TARGET_CFLAGS) -T $(TOPDIR)/board/$(TARGET)/linker.ld $(PKG_BUILD_DIR)/obj/*.o $(BOARD) $(LIBC) -o $(PKG_BUILD_DIR)/kernel.o 
	$(TARGET_OBJCOPY) -Obinary $(PKG_BUILD_DIR)/kernel.o $(KERNEL)
endef

define Package/Compile
	for file in $(SRC); do \
		$(TARGET_CC) $(TARGET_CFLAGS) -c $$file -o "$(PKG_BUILD_DIR)/obj/$$(echo $${file%.*} | sed 's/\//_/g').o"; \
	done
endef

define Package/Prepare
	mkdir -p $(PKG_BUILD_DIR)/obj
endef

# 	$(TARGET_CC) $(TARGET_CFLAGS) -T $(TOPDIR)/board/$(TARGET)/linker.ld $(SRC) -o $(BUILD_DIR)/obj/kernel.o 
# 	$(TARGET_OBJCOPY) -Obinary $(BUILD_DIR)/obj/kernel.o $(KERNEL)
