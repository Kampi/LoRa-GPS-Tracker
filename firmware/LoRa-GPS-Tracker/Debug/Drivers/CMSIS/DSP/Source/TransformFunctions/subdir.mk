################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/Source/TransformFunctions/TransformFunctions.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.c \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.c 

S_UPPER_SRCS += \
../Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.S 

OBJS += \
./Drivers/CMSIS/DSP/Source/TransformFunctions/TransformFunctions.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.o \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.o 

S_UPPER_DEPS += \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.d 

C_DEPS += \
./Drivers/CMSIS/DSP/Source/TransformFunctions/TransformFunctions.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.d \
./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/Source/TransformFunctions/%.o Drivers/CMSIS/DSP/Source/TransformFunctions/%.su Drivers/CMSIS/DSP/Source/TransformFunctions/%.cyclo: ../Drivers/CMSIS/DSP/Source/TransformFunctions/%.c Drivers/CMSIS/DSP/Source/TransformFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/LoRa-GPS-Tracker -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/DSP/Source/TransformFunctions/%.o: ../Drivers/CMSIS/DSP/Source/TransformFunctions/%.S Drivers/CMSIS/DSP/Source/TransformFunctions/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-Source-2f-TransformFunctions

clean-Drivers-2f-CMSIS-2f-DSP-2f-Source-2f-TransformFunctions:
	-$(RM) ./Drivers/CMSIS/DSP/Source/TransformFunctions/TransformFunctions.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/TransformFunctions.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/TransformFunctions.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/TransformFunctions.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.o
	-$(RM) ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.su ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.cyclo ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.d ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.o ./Drivers/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-Source-2f-TransformFunctions

