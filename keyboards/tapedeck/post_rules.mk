ifeq ($(strip $(POT_ENABLE)), yes)
	OPT_DEFS += -DPOT_ENABLE
    QUANTUM_LIB_SRC += analog.c
endif
