################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/HelperFunctions.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/mat_helper.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/ref_helper.c 

OBJS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/HelperFunctions.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/mat_helper.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/ref_helper.o 

C_DEPS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/HelperFunctions.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/mat_helper.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/ref_helper.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/%.o Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/%.su Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/%.cyclo: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/%.c Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/LoRa-GPS-Tracker -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-RefLibs-2f-src-2f-HelperFunctions

clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-RefLibs-2f-src-2f-HelperFunctions:
	-$(RM) ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/HelperFunctions.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/HelperFunctions.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/HelperFunctions.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/HelperFunctions.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/mat_helper.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/mat_helper.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/mat_helper.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/mat_helper.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/ref_helper.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/ref_helper.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/ref_helper.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/RefLibs/src/HelperFunctions/ref_helper.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-RefLibs-2f-src-2f-HelperFunctions

