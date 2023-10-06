# xos libc

PKG := libc
SRC := ctype.c string.c stdio.c divmod.c
TARGET_CFLAGS += -DXOS_LIBC=1 -Iinclude -fno-builtin

include $(TOPDIR)/include/package.mk

define Package/Install
	cp $(PKG_BUILD_DIR)/libc.o $(LIBC)
	cp include/*.h $(BUILD_DIR)/include
endef

define Package/Build
	$(TARGET_CC) $(TARGET_CFLAGS) -r $(PKG_BUILD_DIR)/obj/*.o -o $(PKG_BUILD_DIR)/libc.o
endef

define Package/Compile
	for file in $(SRC); do \
		$(TARGET_CC) $(TARGET_CFLAGS) -c src/$$file -o "$(PKG_BUILD_DIR)/obj/$$(echo $${file%.*} | sed 's/\//_/g').o"; \
	done
endef

define Package/Prepare
	mkdir -p $(PKG_BUILD_DIR)/obj
endef
