#include <stdint.h>
#include <hc32l110_system.h>
uint32_t SystemCoreClock;
uint32_t PeripheralCoreClock;

extern uint32_t __etext;

// defines start and end of .data section in RAM
extern uint32_t __data_start__;
extern uint32_t __data_end__;
// defines start and end of .bss section in RAM
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern int main(void);

void __main()
{
    uint32_t *src, *dst;

    // copy .data area
    src = &__etext;
    dst = &__data_start__;
    while (dst < &__data_end__)
    {
        *dst++ = *src++;
    }

    // clear .bss area
    dst = &__bss_start__;
    while (dst < &__bss_end__)
    {
        *dst++ = 0;
    }
    SystemInit();
    main();
    while (1)
    {
        __asm volatile("wfi");
    }
}

__attribute__((weak)) void SystemInit(void)
{
    *((uint32_t *)0x4000200C) = (*((volatile uint16_t *)(0x00100C08)));
}
