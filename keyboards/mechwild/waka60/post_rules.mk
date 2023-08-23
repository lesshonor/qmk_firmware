ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    ifneq ($(strip $(RGB_INDICATORS_ENABLE)), no)
        OPT_DEFS += -DRGB_INDICATORS_ENABLE
    endif
endif
