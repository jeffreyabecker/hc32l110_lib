cmake_minimum_required(VERSION 3.20)
set(HC32_CHIP_SERIES "6")
set(HC32_USE_DDL_GPIO TRUE)
set(HC32_USE_DDL_BASIC_TIMERS FALSE)
set(HC32_USE_DDL_DEBUG FALSE)
set(HC32_USE_DDL_I2C FALSE)
set(HC32_USE_DDL_CLOCK_DYNAMIC FALSE)
cmake_path(GET CMAKE_CURRENT_LIST_DIR PARENT_PATH HC32_SDK_PATH)

include("${HC32_SDK_PATH}/hc32_sdk.cmake")

project(blinky)
add_executable("${CMAKE_PROJECT_NAME}.elf" src/main.c)



