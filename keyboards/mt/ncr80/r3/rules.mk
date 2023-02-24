# Wildcard to allow APM32 MCU
DFU_SUFFIX_ARGS = -p FFFF -v FFFF

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# As noted in the readme, it is possible to add a solenoid to this PCB.
# This is left as an exercise to particularly enterprising readers,
# as several required components have not been populated on the PCB
# and nothing is known about the circuit.
#HAPTIC_DRIVER += SOLENOID
