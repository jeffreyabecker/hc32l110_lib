cmake_minimum_required(VERSION 3.20)
# Change this line to set the path to the sdk
set(HC32_SDK_PATH "../")



#This line set which series of hc32l110 chip you're using
#  * The 6 series has 4k of ram and 32k of flash
#  * The 4 series has 2k of ram and 16k of flash
set(HC32_CHIP_SERIES "6")

#change these lines to enable / disable ddl drivers
set(HC32_USE_DDL_GPIO TRUE)
set(HC32_USE_DDL_BASIC_TIMERS FALSE)
set(HC32_USE_DDL_DEBUG FALSE)
set(HC32_USE_DDL_I2C FALSE)
set(HC32_USE_DDL_CLOCK_DYNAMIC FALSE)

# If the toolchain isnt in your path it should be set as such
# 1) set the HC32_TOOLCHAIN_PATH environment variable
# 2) set(HC32_TOOLCHAIN_PATH "/path/to/toolchain/folder")

include("${HC32_SDK_PATH}/hc32_sdk.cmake")

project(blinky)
add_executable("${CMAKE_PROJECT_NAME}.elf" src/main.c)



