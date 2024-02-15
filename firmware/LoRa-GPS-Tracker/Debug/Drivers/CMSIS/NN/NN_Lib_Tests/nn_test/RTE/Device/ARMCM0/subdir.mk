################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/startup_ARMCM0.s 

C_SRCS += \
../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/system_ARMCM0.c 

OBJS += \
./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/startup_ARMCM0.o \
./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/system_ARMCM0.o 

S_DEPS += \
./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/startup_ARMCM0.d 

C_DEPS += \
./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/system_ARMCM0.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/%.o: ../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/%.s Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"
Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/%.o Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/%.su Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/%.cyclo: ../Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/%.c Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/LoRa-GPS-Tracker -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-NN-2f-NN_Lib_Tests-2f-nn_test-2f-RTE-2f-Device-2f-ARMCM0

clean-Drivers-2f-CMSIS-2f-NN-2f-NN_Lib_Tests-2f-nn_test-2f-RTE-2f-Device-2f-ARMCM0:
	-$(RM) ./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/startup_ARMCM0.d ./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/startup_ARMCM0.o ./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/system_ARMCM0.cyclo ./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/system_ARMCM0.d ./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/system_ARMCM0.o ./Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/Device/ARMCM0/system_ARMCM0.su

.PHONY: clean-Drivers-2f-CMSIS-2f-NN-2f-NN_Lib_Tests-2f-nn_test-2f-RTE-2f-Device-2f-ARMCM0

