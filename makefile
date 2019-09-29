ARM_CC = arm-none-eabi-gcc
ARM_LL = arm-none-eabi-gcc
PC_CC = gcc

EXE := \
	./object/pes_project_2.axf

PC_FLAGS := -Wall -Werror -c -std=c99 -g3

ARM_FLAGS := -c -std=gnu99 -O0 \
	-g3 -fmessage-length=0 -ffunction-sections -fdata-sections \
	-fno-builtin -fno-common -mcpu=cortex-m0plus -mthumb

LL_FLAGS := -nostdlib -Xlinker -Map="object/MyMakeProject.map" \
	-Xlinker --gc-sections -Xlinker -print-memory-usage \
	-mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o $(EXE)

ARM_INCS := -I"./board" -I"./CMSIS" -I"./drivers" -I"./source" -I"./startup" -I"./utilities" -I"./source/fb" -I"./include"

ARM_DEFS := -D__REDLIB__ -DDEBUG -DCPU_MKL25Z128VLK4 \
	-DFRDM_KL25Z -DFREEDOM -DCPU_MKL25Z128VLK4_cm0plus \
	-DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO \
	-D__USE_CMSIS

PC_INCS := -I"./source" -I"./source/pc"

ARM_OBJS = \
	./object/board/board.o \
	./object/board/clock_config.o \
	./object/board/peripherals.o \
	./object/board/pin_mux.o \
	./object/CMSIS/system_MKL25Z4.o \
	./object/drivers/fsl_clock.o \
	./object/drivers/fsl_common.o \
	./object/drivers/fsl_flash.o \
	./object/drivers/fsl_gpio.o \
	./object/drivers/fsl_lpsci.o \
	./object/drivers/fsl_rtc.o \
	./object/drivers/fsl_smc.o \
	./object/drivers/fsl_uart.o \
	./object/startup/startup_mkl25z4.o \
	./object/utilities/fsl_debug_console.o \
	./object/source/fb/fb_led.o \
	./object/source/fb/fb_loop.o

PC_OBJS = \
	./object/source/pc/pc_print.o \
	./object/source/pc/pc_loop.o

ARM_DEPS = \
	./object/board/board.d \
	./object/board/clock_config.d \
	./object/board/peripherals.d \
	./object/board/pin_mux.d \
	./object/CMSIS/system_MKL25Z4.d \
	./object/drivers/fsl_clock.d \
	./object/drivers/fsl_common.d \
	./object/drivers/fsl_flash.d \
	./object/drivers/fsl_gpio.d \
	./object/drivers/fsl_lpsci.d \
	./object/drivers/fsl_rtc.d \
	./object/drivers/fsl_smc.d \
	./object/drivers/fsl_uart.d \
	./object/startup/startup_mkl25z4.d \
	./object/utilities/fsl_debug_console.d \
	./object/source/fb/fb_led.o \
	./object/source/fb/fb_loop.o
	

all: fb_run

pc_run:	directories $(PC_OBJS)
	$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC_RUN -o ./object/source/main.o ./source/main.c
	$(PC_CC) -o $(PC_OBJS) ./object/source/main.o -o $(EXE)
	./$(EXE)
	
pc_debug: directories $(PC_OBJS)
	$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC_DEBUG -o ./object/source/main.o ./source/main.c
	$(PC_CC) -o $(PC_OBJS) ./object/source/main.o -o $(EXE)
	./$(EXE)

fb_run: directories $(ARM_OBJS) linkerfile.ld
	$(ARM_CC) $(ARM_FLAGS) $(ARM_INCS) -DFB_RUN -o ./object/source/main.o ./source/main.c
	$(ARM_LL) $(LL_FLAGS) $(ARM_OBJS) ./object/source/main.o
	
fb_debug: directories  $(ARM_OBJS) linkerfile.ld
	$(ARM_CC) $(ARM_FLAGS) $(ARM_INCS) -DFB_DEBUG -o ./object/source/main.o ./source/main.c
	$(ARM_LL) $(LL_FLAGS) $(ARM_OBJS) ./object/source/main.o
	


# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
# Leveraged code
OUT_DIR := object object/CMSIS object/drivers object/board object/source \
	object/source/fb object/source/pc object/utilities object/startup
	
MK := mkdir -p
directories:
	$(MK) $(OUT_DIR)


# https://mcuoneclipse.com/2017/07/22/tutorial-makefile-projects-with-eclipse/
# Leveraged code


./object/CMSIS/%.o: ./CMSIS/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./object/drivers/%.o: ./drivers/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./object/board/%.o: ./board/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./object/startup/%.o: ./startup/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./object/utilities/%.o: ./utilities/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	
./object/source/fb/%.o: ./source/fb/%.c
	$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"



	
./object/source/pc/%.o: ./source/pc/%.c
	$(PC_CC) $(PC_FLAGS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"

	
clean:
	rm -rf object
	
	
