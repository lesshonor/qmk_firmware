# Configure for 128K flash
#MCU_LDSCRIPT = STM32F103xB

# Wildcard to allow APM32 MCU
DFU_SUFFIX_ARGS = -p FFFF -v FFFF

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# As noted in the readme, it is possible to add a solenoid to this PCB.
# This is left as an exercise to particularly enterprising readers,
# as nothing is known about the intended circuit/part numbers.
#HAPTIC_DRIVER += SOLENOID
