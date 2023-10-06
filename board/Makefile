# xos board

PKG := board
SRC := init.c irq.c dev.c 

include $(TOPDIR)/include/package.mk

define Package/Install
	cp $(PKG_BUILD_DIR)/board.o $(BOARD)
endef

define Package/Build
	$(TARGET_CC) $(TARGET_CFLAGS) -r $(PKG_BUILD_DIR)/obj/*.o -o $(PKG_BUILD_DIR)/board.o
endef

define Package/Compile
	for file in $(SRC); do \
		$(TARGET_CC) $(TARGET_CFLAGS) -c $(TARGET)/src/$$file -o "$(PKG_BUILD_DIR)/obj/$$(echo $${file%.*} | sed 's/\//_/g').o"; \
	done
endef

define Package/Prepare
	mkdir -p $(PKG_BUILD_DIR)/obj
endef
