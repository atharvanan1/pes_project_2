ARM_CC = arm-none-eabi-gcc
ARM_LL = arm-none-eabi-gcc
PC_CC = gcc

EXE := \
	./Debug/pes_project_2.axf

PC_FLAGS := -Wall -Werror -c -std=c99 -O0 -g3

ARM_FLAGS := -c -std=gnu99 -O0 \
	-g3 -fmessage-length=0 -ffunction-sections -fdata-sections \
	-fno-builtin -fno-common -mcpu=cortex-m0plus -mthumb

LL_FLAGS := -nostdlib -Xlinker -Map="Debug/pes_project_2.map" \
	-Xlinker --gc-sections -Xlinker -print-memory-usage \
	-mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o $(EXE)

ARM_INCS := -I"./board" -I"./CMSIS" -I"./drivers" -I"./source" -I"./startup" -I"./utilities" -I"./source/fb" -I"./include"

PC_INCS := -I"./source" -I"./source/pc"

ARM_DEFS := -D__REDLIB__ -DDEBUG -DCPU_MKL25Z128VLK4 \
	-DFRDM_KL25Z -DFREEDOM -DCPU_MKL25Z128VLK4_cm0plus \
	-DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO \
	-D__USE_CMSIS

ARM_OBJS = \
	./Debug/board/board.o \
	./Debug/board/clock_config.o \
	./Debug/board/peripherals.o \
	./Debug/board/pin_mux.o \
	./Debug/CMSIS/system_MKL25Z4.o \
	./Debug/drivers/fsl_clock.o \
	./Debug/drivers/fsl_common.o \
	./Debug/drivers/fsl_flash.o \
	./Debug/drivers/fsl_gpio.o \
	./Debug/drivers/fsl_lpsci.o \
	./Debug/drivers/fsl_rtc.o \
	./Debug/drivers/fsl_smc.o \
	./Debug/drivers/fsl_uart.o \
	./Debug/startup/startup_mkl25z4.o \
	./Debug/utilities/fsl_debug_console.o \
	./Debug/source/fb/fb_led.o \
	./Debug/source/fb/fb_loop.o \
	./Debug/source/fb/fb_debug.o

ARM_DEPS = \
	./Debug/board/board.d \
	./Debug/board/clock_config.d \
	./Debug/board/peripherals.d \
	./Debug/board/pin_mux.d \
	./Debug/CMSIS/system_MKL25Z4.d \
	./Debug/drivers/fsl_clock.d \
	./Debug/drivers/fsl_common.d \
	./Debug/drivers/fsl_flash.d \
	./Debug/drivers/fsl_gpio.d \
	./Debug/drivers/fsl_lpsci.d \
	./Debug/drivers/fsl_rtc.d \
	./Debug/drivers/fsl_smc.d \
	./Debug/drivers/fsl_uart.d \
	./Debug/startup/startup_mkl25z4.d \
	./Debug/utilities/fsl_debug_console.d \
	./Debug/source/fb/fb_led.d \
	./Debug/source/fb/fb_loop.d \
	./Debug/source/fb/fb_debug.d

PC_OBJS = \
	./Debug/source/pc/pc_print.o \
	./Debug/source/pc/pc_loop.o \
	./Debug/source/pc/pc_debug.o
	
PC_DEPS = \
	./Debug/source/pc/pc_print.d \
	./Debug/source/pc/pc_loop.d \
	./Debug/source/pc/pc_debug.d

ifeq ($(BV),FB_RUN)
build_version := fb_run
else ifeq ($(BV),FB_DEBUG)
build_version := fb_debug
else ifeq ($(BV),PC_RUN)
build_version := pc_run
else ifeq ($(BV),PC_DEBUG)
build_version := pc_debug
endif

all: $(EXE)

$(EXE): $(build_version)

pc_run: directories	$(PC_OBJS)
	$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC_RUN -o ./Debug/source/main.o ./source/main.c
	$(PC_CC) $(PC_OBJS) ./Debug/source/main.o -o $(EXE)
	
pc_debug: directories $(PC_OBJS)
	$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC_DEBUG -o ./Debug/source/main.o ./source/main.c
	$(PC_CC) $(PC_OBJS) ./Debug/source/main.o -o $(EXE)

fb_run: directories	$(ARM_OBJS) linkerfile.ld
	$(ARM_CC) $(ARM_FLAGS) $(ARM_INCS) -DFB_RUN -o ./Debug/source/main.o ./source/main.c
	$(ARM_LL) $(LL_FLAGS) $(ARM_OBJS) ./Debug/source/main.o -o $(EXE)
	
fb_debug: directories $(ARM_OBJS) linkerfile.ld
	$(ARM_CC) $(ARM_FLAGS) $(ARM_INCS) -DFB_DEBUG -o ./Debug/source/main.o ./source/main.c
	$(ARM_LL) $(LL_FLAGS) $(ARM_OBJS) ./Debug/source/main.o  -o $(EXE)
	


# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
# Leveraged code
OUT_DIR := Debug Debug/CMSIS Debug/drivers Debug/board Debug/source \
	Debug/source/fb Debug/source/pc Debug/utilities Debug/startup
	
MK := mkdir -p
directories:
	$(MK) $(OUT_DIR)


# https://mcuoneclipse.com/2017/07/22/tutorial-makefile-projects-with-eclipse/
# Leveraged code


./Debug/CMSIS/%.o: ./CMSIS/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./Debug/drivers/%.o: ./drivers/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./Debug/board/%.o: ./board/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./Debug/startup/%.o: ./startup/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./Debug/utilities/%.o: ./utilities/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./Debug/source/fb/%.o: ./source/fb/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"



	
./Debug/source/pc/%.o: ./source/pc/%.c
	$(PC_CC) $(PC_FLAGS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"

	
clean:
	rm -rf Debug
	
	
