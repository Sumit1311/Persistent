################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vector/run_vector.cpp 

OBJS += \
./src/vector/run_vector.o 

CPP_DEPS += \
./src/vector/run_vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/vector/%.o: ../src/vector/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


