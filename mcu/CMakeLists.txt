cmake_minimum_required(VERSION 3.19)
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
set (CMAKE_TOOLCHAIN_FILE "${PARENT_DIR}/gcc-arm-eabi.cmake")

project(hc32l110_boot LANGUAGES ASM)
add_library ("${CMAKE_PROJECT_NAME}" hc32l110_boot.s)