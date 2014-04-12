################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../unitTesting/threadTest/testThread.cpp 

OBJS += \
./unitTesting/threadTest/testThread.o 

CPP_DEPS += \
./unitTesting/threadTest/testThread.d 


# Each subdirectory must supply rules for building sources it contributes
unitTesting/threadTest/%.o: ../unitTesting/threadTest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/weijian/workspace/workspace_linux/Linux_Program/common" -I"/home/weijian/workspace/workspace_linux/Linux_Program/unitTesting/common" -I"/home/weijian/workspace/workspace_linux/Linux_Program/unitTesting/lib" -I"/home/weijian/workspace/workspace_linux/Linux_Program/lib/threads" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


