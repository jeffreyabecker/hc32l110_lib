#include <stdint.h>
#include "hc32l110_system.h"
#include "hc32l110_registers_clock.h"
#include "hc32l110_registers_system.h"
typedef void (*ptr_func_t)();

extern uint32_t SystemCoreClock;
extern uint32_t PeripheralCoreClock;

extern uint32_t __data_start;
extern uint32_t __data_end;
extern uint32_t __data_load;

extern uint32_t __bss_start;
extern uint32_t __bss_end;

extern uint32_t __heap_start;
extern uint32_t __stacktop;

extern ptr_func_t __preinit_array_start[];
extern ptr_func_t __preinit_array_end[];

extern ptr_func_t __init_array_start[];
extern ptr_func_t __init_array_end[];

extern ptr_func_t __fini_array_start[];
extern ptr_func_t __fini_array_end[];

extern int main(void);
extern void SystemInit(void);

extern "C" void Dummy_Handler(void)
{
}

extern "C" void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Dummy_Handler")));

void IRQ00_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ01_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ02_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ03_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ04_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ05_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ06_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ07_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ08_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ09_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ10_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ11_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ12_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ13_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ14_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ15_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ16_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ17_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ18_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ19_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ20_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ21_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ22_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ23_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ24_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ25_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ26_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ27_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ28_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ29_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ30_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void IRQ31_Handler(void) __attribute__((weak, alias("Dummy_Handler")));

__attribute__((section(".stack"), used)) uint32_t *__stack_init = &__stacktop;
__attribute__((section(".vectors"), used)) ptr_func_t vector_table[] = {
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SVC_Handler,
    0,
    0,
    PendSV_Handler,
    SysTick_Handler,
    IRQ00_Handler,
    IRQ01_Handler,
    IRQ02_Handler,
    IRQ03_Handler,
    IRQ04_Handler,
    IRQ05_Handler,
    IRQ06_Handler,
    IRQ07_Handler,
    IRQ08_Handler,
    IRQ09_Handler,
    IRQ10_Handler,
    IRQ11_Handler,
    IRQ12_Handler,
    IRQ13_Handler,
    IRQ14_Handler,
    IRQ15_Handler,
    IRQ16_Handler,
    IRQ17_Handler,
    IRQ18_Handler,
    IRQ19_Handler,
    IRQ20_Handler,
    IRQ21_Handler,
    IRQ22_Handler,
    IRQ23_Handler,
    IRQ24_Handler,
    IRQ25_Handler,
    IRQ26_Handler,
    IRQ27_Handler,
    IRQ28_Handler,
    IRQ29_Handler,
    IRQ30_Handler,
    IRQ31_Handler};
/** Copy default data to DATA section
 */
void copy_data()
{
    uint32_t *src = &__data_load;
    uint32_t *dst = &__data_start;
    while (dst < &__data_end)
    {
        *dst++ = *src++;
    }
}

/** Erase BSS section
 */
void zero_bss()
{
    uint32_t *dst = &__bss_start;
    while (dst < &__bss_end)
    {
        *dst++ = 0;
    }
}

/** Call constructors for static objects
 */
void call_init_array()
{
    auto array = __preinit_array_start;
    while (array < __preinit_array_end)
    {
        (*array)();
        array++;
    }

    array = __init_array_start;
    while (array < __init_array_end)
    {
        (*array)();
        array++;
    }
}

/** Call destructors for static objects
 */
void call_fini_array()
{
    auto array = __fini_array_start;
    while (array < __fini_array_end)
    {
        (*array)();
        array++;
    }
}

extern "C" __attribute__((used)) void Reset_Handler(void)
{
    copy_data();
    zero_bss();
    SystemInit();
    call_init_array();
    main();
    // call destructors for static instances
    call_fini_array();
    while (1)
    {
        __nop();
    }
}

__weak void SystemInit(void)
{
    HC32_CLOCK->RCH_CR.TRIM = CLOCK_TRIM_HIGH_4_mhz;
    HC32_CLOCK->peripheral_clock_enable = peripheral_none;
    SystemCoreClock = MHz_4;
    PeripheralCoreClock = MHz_4;
}

extern "C" void __cxa_pure_virtual() { while (1); }