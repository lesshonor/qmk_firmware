VIA_ENABLE = yes

CONSOLE_ENABLE = yes
DEBUG_ENABLE = yes

EXTERNAL_EEPROM_ENABLE = no

ifeq ($(strip $(EXTERNAL_EEPROM_ENABLE)), yes)
    EEPROM_DRIVER = spi
endif

ifeq ($(strip $(CONSOLE_ENABLE)), yes)
    MOUSEKEY_ENABLE = no
    EXTRAKEY_ENABLE = no
    NKRO_ENABLE = no
    KEYBOARD_SHARED_EP = yes
endif
