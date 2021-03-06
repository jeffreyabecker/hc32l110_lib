cmake_minimum_required(VERSION 3.19)
set(TOOLCHAIN_PREFIX arm-none-eabi-)
if(WIN32)
    set(TOOLCHAIN_EXT ".exe" )
else()
    set(TOOLCHAIN_EXT "" )
endif()




if("${HC32_TOOLCHAIN_PATH}" STREQUAL "")
    if(NOT "$ENV{HC32_TOOLCHAIN_PATH}" STREQUAL "")
        set(HC32_TOOLCHAIN_PATH $ENV{HC32_TOOLCHAIN_PATH})
    else()
        find_program(
            TMP_COMPILER_CC "${TOOLCHAIN_PREFIX}gcc${TOOLCHAIN_EXT}"
            PATHS $ENV{PATH}
            PATH_SUFFIXES bin
            NO_DEFAULT_PATH
        )
        get_filename_component(TMP_COMPILER_DIR "${TMP_COMPILER_CC}" DIRECTORY)
        get_filename_component(HC32_TOOLCHAIN_PATH "${TMP_COMPILER_DIR}" DIRECTORY)    
    endif()    
endif()
set(CMAKE_AR                    "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}ar${TOOLCHAIN_EXT}")
set(CMAKE_ASM_COMPILER          "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}as${TOOLCHAIN_EXT}")
set(CMAKE_C_COMPILER            "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}gcc${TOOLCHAIN_EXT}")
set(CMAKE_CXX_COMPILER          "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}g++${TOOLCHAIN_EXT}")
set(CMAKE_LINKER                "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}ld${TOOLCHAIN_EXT}")
set(CMAKE_RANLIB                "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}ranlib${TOOLCHAIN_EXT}")
set(CMAKE_SIZE                  "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}size${TOOLCHAIN_EXT}")
set(CMAKE_STRIP                 "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}strip${TOOLCHAIN_EXT}")
set(CMAKE_OBJCOPY               "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}objcopy${TOOLCHAIN_EXT}")
set(CMAKE_OBJDUMP               "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}objdump${TOOLCHAIN_EXT}")
set(CMAKE_READELF               "${HC32_TOOLCHAIN_PATH}/bin/${TOOLCHAIN_PREFIX}readelf${TOOLCHAIN_EXT}")
set(CMAKE_C_OUTPUT_EXTENSION .o)
set(CMAKE_ASM_COMPILE_OBJECT "<CMAKE_ASM_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -o <OBJECT>   -c <SOURCE>")
set(CMAKE_INCLUDE_FLAG_ASM "-I")


set(CMAKE_FIND_ROOT_PATH HC32_TOOLCHAIN_PATH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(ARM_GCC_COMMON_FLAGS "-mcpu=cortex-m0 -mthumb -ffreestanding -ffunction-sections -fdata-sections -nostdlib")

foreach(LANG IN ITEMS C CXX ASM)
    set(CMAKE_${LANG}_FLAGS_INIT "${ARM_GCC_COMMON_FLAGS}")
    set(CMAKE_${LANG}_FLAGS_DEBUG_INIT "-Og")
    set(CMAKE_${LANG}_LINK_FLAGS "-Wl,--build-id=none")
endforeach()