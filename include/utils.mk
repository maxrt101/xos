
ifeq ($(TOPDIR),)
$(error [!] No TOPDIR defined)
endif

# $(1) - prefix for config
define GetConfigOptionsByPrefix
`cat $(TOPDIR)/.config | grep $(1) | xargs -I % echo -D % | tr '\n' ' '`
endef
