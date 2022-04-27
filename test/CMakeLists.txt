cmake_minimum_required(VERSION 3.20)
set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/../sdk/gcc-arm-eabi.cmake")

include_directories("${CMAKE_CURRENT_LIST_DIR}/../sdk/include")
link_libraries("-T${CMAKE_CURRENT_LIST_DIR}/../sdk/hc32l110x6.ld")
link_libraries("gcc")
add_compile_options("-O0" "-g3" "-ggdb")


project(test)
set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -Wl,--gc-sections")
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--gc-sections")

add_executable("${CMAKE_PROJECT_NAME}.elf" 
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/hc32l110_boot.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/hc32l110_ddl_core.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/hc32l110_ddl_gpio.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../sdk/src/hc32l110_ddl_debug.c"
    main.cpp
)

