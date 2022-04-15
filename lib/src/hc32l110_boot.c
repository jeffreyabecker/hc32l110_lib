#include <stdint.h>
#include "hc32l110_system.h"
#include "hc32l110_registers_clock.h"
extern uint32_t SystemCoreClock;
extern uint32_t PeripheralCoreClock;

extern uint32_t __etext;
extern uint32_t __StackTop;

// defines start and end of .data section in RAM
extern uint32_t __data_start__;
extern uint32_t __data_end__;
// defines start and end of .bss section in RAM
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern int main(void);
extern void SystemInit(void);

#define WEAK_ALIAS(x) __attribute__((weak, alias(#x)))
void Dummy_Handler(void);

void Reset_Handler(void);
void NMI_Handler(void) WEAK_ALIAS(Dummy_Handler);
void HardFault_Handler(void) WEAK_ALIAS(Dummy_Handler);
void SVC_Handler(void) WEAK_ALIAS(Dummy_Handler);
void PendSV_Handler(void) WEAK_ALIAS(Dummy_Handler);
void SysTick_Handler(void) WEAK_ALIAS(Dummy_Handler);

void IRQ00_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ01_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ02_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ03_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ04_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ05_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ06_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ07_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ08_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ09_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ10_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ11_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ12_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ13_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ14_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ15_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ16_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ17_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ18_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ19_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ20_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ21_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ22_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ23_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ24_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ25_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ26_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ27_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ28_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ29_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ30_Handler(void) WEAK_ALIAS(Dummy_Handler);
void IRQ31_Handler(void) WEAK_ALIAS(Dummy_Handler);

void *vector_table[] __attribute__((used, section(".vectors"))) = {
    &__StackTop,
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
__attribute__((used)) void Reset_Handler(void)
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
        __NOP();
    }
}

__WEAK void SystemInit(void)
{
    // set the clock trim for highspeed internal to the trim value for 4mhz (default)
    *((uint32_t *)0x4000200C) = (*((volatile uint16_t *)(0x00100C08)));
    // disable all the peripherals
    *((uint32_t *)0x40002000UL) = 0x00000000;
    SystemCoreClock = MHz_4;
    PeripheralCoreClock = MHz_4;
}

void Dummy_Handler(void)
{
}