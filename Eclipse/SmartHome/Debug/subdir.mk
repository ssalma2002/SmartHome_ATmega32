################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_Motor.c \
../PWM.c \
../adc.c \
../buzzer.c \
../flame.c \
../gpio.c \
../lcd.c \
../ldr.c \
../led.c \
../lm35_sensor.c \
../main.c 

OBJS += \
./DC_Motor.o \
./PWM.o \
./adc.o \
./buzzer.o \
./flame.o \
./gpio.o \
./lcd.o \
./ldr.o \
./led.o \
./lm35_sensor.o \
./main.o 

C_DEPS += \
./DC_Motor.d \
./PWM.d \
./adc.d \
./buzzer.d \
./flame.d \
./gpio.d \
./lcd.d \
./ldr.d \
./led.d \
./lm35_sensor.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


