#include <stdint.h>
#include <hc32l110_system.h>
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

void Reset_Handler(void);
void NMI_Handler(void) WEAK_ALIAS(Dummy_Handler);
void HardFault_Handler(void) WEAK_ALIAS(Dummy_Handler);
void SVC_Handler(void) WEAK_ALIAS(Dummy_Handler);
void PendSV_Handler(void) WEAK_ALIAS(Dummy_Handler);
void SysTick_Handler(void) WEAK_ALIAS(Dummy_Handler);
void Dummy_Handler(void);
void PORT0_Handler(void) WEAK_ALIAS(Dummy_Handler);
void PORT1_Handler(void) WEAK_ALIAS(Dummy_Handler);
void PORT2_Handler(void) WEAK_ALIAS(Dummy_Handler);
void PORT3_Handler(void) WEAK_ALIAS(Dummy_Handler);
void UART0_Handler(void) WEAK_ALIAS(Dummy_Handler);
void UART1_Handler(void) WEAK_ALIAS(Dummy_Handler);
void LPUART_Handler(void) WEAK_ALIAS(Dummy_Handler);
void SPI_Handler(void) WEAK_ALIAS(Dummy_Handler);
void I2C_Handler(void) WEAK_ALIAS(Dummy_Handler);
void TIM0_Handler(void) WEAK_ALIAS(Dummy_Handler);
void TIM1_Handler(void) WEAK_ALIAS(Dummy_Handler);
void TIM2_Handler(void) WEAK_ALIAS(Dummy_Handler);
void LPTIM_Handler(void) WEAK_ALIAS(Dummy_Handler);
void TIM4_Handler(void) WEAK_ALIAS(Dummy_Handler);
void TIM5_Handler(void) WEAK_ALIAS(Dummy_Handler);
void TIM6_Handler(void) WEAK_ALIAS(Dummy_Handler);
void PCA_Handler(void) WEAK_ALIAS(Dummy_Handler);
void WDT_Handler(void) WEAK_ALIAS(Dummy_Handler);
void RTC_Handler(void) WEAK_ALIAS(Dummy_Handler);
void ADC_Handler(void) WEAK_ALIAS(Dummy_Handler);
void VC0_Handler(void) WEAK_ALIAS(Dummy_Handler);
void VC1_Handler(void) WEAK_ALIAS(Dummy_Handler);
void LVD_Handler(void) WEAK_ALIAS(Dummy_Handler);
void FLASH_Handler(void) WEAK_ALIAS(Dummy_Handler);
void CLK_Handler(void) WEAK_ALIAS(Dummy_Handler);
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
    PORT0_Handler,
    PORT1_Handler,
    PORT2_Handler,
    PORT3_Handler,
    UART0_Handler,
    UART1_Handler,
    LPUART_Handler,
    SPI_Handler,
    I2C_Handler,
    TIM0_Handler,
    TIM1_Handler,
    TIM2_Handler,
    LPTIM_Handler,
    TIM4_Handler,
    TIM5_Handler,
    TIM6_Handler,
    PCA_Handler,
    WDT_Handler,
    RTC_Handler,
    ADC_Handler,
    VC0_Handler,
    VC1_Handler,
    LVD_Handler,
    FLASH_Handler,
    CLK_Handler,
};
 void Reset_Handler(void)
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

__WEAK void SystemInit(void)
{
    // set the clock trim for highspeed internal to the trim value for 4mhz (default)
    *((uint32_t *)0x4000200C) = (*((volatile uint16_t *)(0x00100C08)));
    // disable all the peripherals
    *((uint32_t *)0x40002000UL) = 0x00000000;
    SystemCoreClock = MHz_4;
}

void Dummy_Handler(void)
{
}