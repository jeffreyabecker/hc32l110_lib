cmake_minimum_required(VERSION 3.20)
set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/../sdk/gcc-arm-eabi.cmake")

include_directories("${CMAKE_CURRENT_LIST_DIR}/../sdk/include")
link_libraries("-T${CMAKE_CURRENT_LIST_DIR}/../sdk/hc32l110x6.ld")
link_libraries("gcc")
add_compile_options("-O0" "-g3" "-ggdb")
add_compile_definitions("HC32_USE_DDL_GPIO")
add_compile_definitions("HC32_USE_DDL_TIMERS")

project(test)
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -Wl,--gc-sections")
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--gc-sections")

add_executable("${CMAKE_PROJECT_NAME}.elf" 
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/core/boot.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/core/device.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/core/interrupt_handler.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/core/nvic.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/core/systick.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/core/system_clock.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/core/timer_counter.cpp"

    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/gpio.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/hc32l110_ddl_debug.cpp"
    
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/timers/basic_timer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/ddl/timers/lp_timer.cpp"
    

    main.cpp
)

