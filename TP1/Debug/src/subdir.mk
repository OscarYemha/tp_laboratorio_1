################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/OperacionesMatematicas.c \
../src/TP1.c \
../src/Utn.c 

OBJS += \
./src/OperacionesMatematicas.o \
./src/TP1.o \
./src/Utn.o 

C_DEPS += \
./src/OperacionesMatematicas.d \
./src/TP1.d \
./src/Utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


