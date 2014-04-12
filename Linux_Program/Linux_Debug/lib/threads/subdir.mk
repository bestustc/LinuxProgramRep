################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/threads/task.cpp 

OBJS += \
./lib/threads/task.o 

CPP_DEPS += \
./lib/threads/task.d 


# Each subdirectory must supply rules for building sources it contributes
lib/threads/%.o: ../lib/threads/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/weijian/workspace/workspace_linux/Linux_Program/common" -I"/home/weijian/workspace/workspace_linux/Linux_Program/unitTesting/common" -I"/home/weijian/workspace/workspace_linux/Linux_Program/unitTesting/lib" -I"/home/weijian/workspace/workspace_linux/Linux_Program/lib/threads" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


