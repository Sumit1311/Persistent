################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Basic_Pthread.c \
../src/Conditional_Locks.c 

OBJS += \
./src/Basic_Pthread.o \
./src/Conditional_Locks.o 

C_DEPS += \
./src/Basic_Pthread.d \
./src/Conditional_Locks.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/sumit/JavaWorkplace/OS_Programs/src/include" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


