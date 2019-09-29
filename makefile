ARM-CC = arm-none-eabi-gcc
ARM-LL = arm-none-eabi-gcc
PC-CC = gcc

PCFLAGS = -Wall -Werror -c -std=c99

ARMFLAGS := -c -std=gnu99 -O0 \
	-g -fmessage-length=0 -ffunction-sections -fdata-sections \
	-fno-builtin -fno-common -mcpu=cortex-m0plus -mthumb

ARM_INCS = "./board" "./CMSIS" "./drivers" "./source" "./startup" "./utilities"

ARM_OBJS = 
board/board.o
board/clock_config.o
board/peripherals.o
board/pin_mux.o
CMSIS/system_MKL25Z4.o
drivers/fsl_clock.o
drivers/fsl_common.o
drivers/fsl_flash.o
drivers/fsl_gpio.o
drivers/fsl_lpsci.o
drivers/fsl_port.o
drivers/fsl_rtc.o
drivers/fsl_smc.o
drivers/fsl_uart.o
source/mtb.o
source/semihost_hardfault.o
startup/startup_mkl25z4.o
utilities/fsl_debug_console.o

ARM_DEPS =
board/board.d
board/clock_config.d
board/peripherals.d
board/pin_mux.d
CMSIS/system_MKL25Z4.d
drivers/fsl_clock.d
drivers/fsl_common.d
drivers/fsl_flash.d
drivers/fsl_gpio.d
drivers/fsl_lpsci.d
drivers/fsl_port.d
drivers/fsl_rtc.d
drivers/fsl_smc.d
drivers/fsl_uart.d
source/mtb.d
source/semihost_hardfault.d
startup/startup_mkl25z4.d
utilities/fsl_debug_console.d

fb_run:
fb_debug:
pc_run:
pc_debug:

