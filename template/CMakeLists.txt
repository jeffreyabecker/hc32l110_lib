cmake_minimum_required(VERSION 3.19)
#=================
if(WIN32)
    set(TOOLCHAIN_EXT ".exe" )
else()
    set(TOOLCHAIN_EXT "" )
endif()


get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)


set (CMAKE_TOOLCHAIN_FILE "${PARENT_DIR}/gcc-arm-eabi.cmake")

project(blinky)
add_executable("${CMAKE_PROJECT_NAME}" main.c)