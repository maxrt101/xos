# xos-build package

ifeq ($(PKG),)
$(error [!] No PKG defined, but package.mk is included)
endif

export PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG)

.PHONY: build

install: build
	$(call Package/Install)

build: compile
	$(call Package/Build)

compile: prepare
	$(call Package/Compile)

prepare:
	rm -rf $(PKG_BUILD_DIR)
	mkdir -p $(PKG_BUILD_DIR)
	$(call Package/Prepare)

