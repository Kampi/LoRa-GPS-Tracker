################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo.c \
../Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo_radio.c 

OBJS += \
./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo.o \
./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo_radio.o 

C_DEPS += \
./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo.d \
./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo_radio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/LoRa-GPS-Tracker/%.o Drivers/BSP/LoRa-GPS-Tracker/%.su Drivers/BSP/LoRa-GPS-Tracker/%.cyclo: ../Drivers/BSP/LoRa-GPS-Tracker/%.c Drivers/BSP/LoRa-GPS-Tracker/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../SubGHz_Phy/App -I../SubGHz_Phy/Target -I../Utilities/trace/adv_trace -I../Utilities/misc -I../Utilities/sequencer -I../Utilities/timer -I../Utilities/lpm/tiny_lpm -I../Middlewares/Third_Party/SubGHz_Phy -I../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../Drivers/BSP/LoRa-GPS-Tracker -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-LoRa-2d-GPS-2d-Tracker

clean-Drivers-2f-BSP-2f-LoRa-2d-GPS-2d-Tracker:
	-$(RM) ./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo.cyclo ./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo.d ./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo.o ./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo.su ./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo_radio.cyclo ./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo_radio.d ./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo_radio.o ./Drivers/BSP/LoRa-GPS-Tracker/stm32wlxx_nucleo_radio.su

.PHONY: clean-Drivers-2f-BSP-2f-LoRa-2d-GPS-2d-Tracker

