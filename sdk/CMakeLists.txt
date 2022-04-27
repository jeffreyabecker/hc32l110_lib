cmake_minimum_required(VERSION 3.19)
set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/gcc-arm-eabi.cmake")

set (LIB_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
project(hc32l110_ddl)
include_directories("${CMAKE_CURRENT_LIST_DIR}/include")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_library ("${CMAKE_PROJECT_NAME}_core" 
    "${LIB_SOURCE_DIR}/ddl/core/boot.cpp"
    "${LIB_SOURCE_DIR}/ddl/core/device.cpp"
    "${LIB_SOURCE_DIR}/ddl/core/interrupt_handler.cpp"
    "${LIB_SOURCE_DIR}/ddl/core/nvic.cpp"
    "${LIB_SOURCE_DIR}/ddl/core/systick.cpp"
    "${LIB_SOURCE_DIR}/ddl/core/system_clock.cpp"
    "${LIB_SOURCE_DIR}/ddl/core/timer_counter.cpp"

)
add_library ("${CMAKE_PROJECT_NAME}_gpio" "${LIB_SOURCE_DIR}/ddl/gpio.cpp")
#add_library ("${CMAKE_PROJECT_NAME}_debug" "${LIB_SOURCE_DIR}/hc32l110_ddl_debug.cpp")
#add_library ("${CMAKE_PROJECT_NAME}_i2c" "${LIB_SOURCE_DIR}/hc32l110_ddl_i2c.c")
#add_library ("${CMAKE_PROJECT_NAME}_clock_dynamic" "${LIB_SOURCE_DIR}/hc32l110_ddl_clock_dynamic.c")
#add_library ("${CMAKE_PROJECT_NAME}_uart" "${LIB_SOURCE_DIR}/hc32l110_ddl_uart.c")
add_library ("${CMAKE_PROJECT_NAME}_utils" "${LIB_SOURCE_DIR}/ddl/utils/rng.cpp" "${LIB_SOURCE_DIR}/ddl/utils/strlen.cpp")
add_library ("${CMAKE_PROJECT_NAME}_timers" "${LIB_SOURCE_DIR}/ddl/timers/basic_timer.cpp" "${LIB_SOURCE_DIR}/ddl/timers/lp_timer.cpp")



# add_executable("${CMAKE_PROJECT_NAME}.elf" 

#     "${CMAKE_CURRENT_LIST_DIR}/ddl/gpio.cpp"
#     "${CMAKE_CURRENT_LIST_DIR}/hc32l110_ddl_debug.cpp"
    
#     "${CMAKE_CURRENT_LIST_DIR}/ddl/timers/basic_timer.cpp"
#     "${CMAKE_CURRENT_LIST_DIR}/ddl/timers/lp_timer.cpp"
    

#     main.cpp
# )

