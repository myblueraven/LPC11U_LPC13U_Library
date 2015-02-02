## LPC11U_LPC13U_Library

Based on excellent Kevin Townsend's [LPC11U_LPC13U_CodeBase](https://github.com/microbuilder/LPC11U_LPC13U_CodeBase)


CMSIS DSP Library
- arm_common_tables.h
- arm_const_structs.h
- arm_math.h
- math_helper.c
- math_helper.h
- libs/libarm_cortexM0l_math.a
- libs/libarm_cortexM3l_math.a

CMSIS-RTOS API
- cmsis_os.h
- RTX_CM_lib.h
- RTX_hook.c
- libs/libRTX_CM0.a
- libs/libRTX_CM3.a

CMSIS Cortex-M0 Core Peripheral Access Layer
- core_cm0.h

CMSIS Cortex-M3 Core Peripheral Access Layer
- core_cm3.h

CMSIS Cortex-M Core Function Access
- core_cmFunc.h
- core_cmInstr.h

CMSIS Cortex-M0 Core Peripheral Access Layer Header File for default LPC11Uxx Device Series
- LPC11Uxx.h : peripheral register definitions
- system_LPC11Uxx.c : definition of SystemInit() and SystemCoreClockUpdate()
- system_LPC11Uxx.h

CMSIS Cortex-M3 Core Peripheral Access Layer Header File for default LPC13Uxx Device Series
(peripheral register definitions)
- LPC13Uxx.h : peripheral register definitions
- system_LPC13Uxx.c : definition of SystemInit() and SystemCoreClockUpdate()
- system_LPC13Uxx.h

Startup definitions/functions:
interrupt vectors, default handlers, reset handler that initializes bss section, calls SystemInit() and calls _main() or main()
- startup_lpc11u_gnumake.c
- startup_lpc13u_gnumake.c
- startup_lpc11u_lpc13u_codered.c

