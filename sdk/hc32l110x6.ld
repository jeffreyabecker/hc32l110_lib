
MEMORY
{
    FLASH  (rx): ORIGIN = 0x00000000, LENGTH = 32K
    RAM   (rwx): ORIGIN = 0x20000000, LENGTH = 4K
}

ENTRY(Reset_Handler)
SECTIONS
{
    __StackTop = ORIGIN(RAM) + LENGTH(RAM);
    
    .text :
    {
        KEEP(*(.vectors))
        *(.text*)
        *(.rodata*)
    } > FLASH

    __text_end__ = .;

    .data : AT (__text_end__)
    {
        __data_start__ = .;
        *(.data*)
        __data_end__ = .;

    } > RAM

    .bss :
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM

}