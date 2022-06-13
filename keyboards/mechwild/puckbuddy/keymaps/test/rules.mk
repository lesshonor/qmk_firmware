VIA_ENABLE = yes

LTO_ENABLE = yes

EEPROM_DRIVER = vendor

# You don't need to uncomment this.
#ALT_CIRQUE_PIN = yes

CONSOLE_ENABLE = yes

ifeq ($(strip $(CONSOLE_ENABLE)), yes)
    MOUSEKEY_ENABLE = no
    EXTRAKEY_ENABLE = no
    NKRO_ENABLE = no
    KEYBOARD_SHARED_EP = yes
endif

# This adds A LOT of output to console from frequently-called processes.
# Maybe run `grep -r dprint` before enabling.
DEBUG_ENABLE = yes
