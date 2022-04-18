
#ifndef __SYSTEM_HC32L110_SYSTEM_H__
#define __SYSTEM_HC32L110_SYSTEM_H__

#include <stdint.h>

#include "hc32l110_system.h"
#ifdef __cplusplus
extern "C"
{
#endif
#define __MPU_PRESENT 0
#define __NVIC_PRIO_BITS 2
#define __Vendor_SysTickConfig 0

    typedef enum IRQn
    {
        NMI_IRQn = -14,
        HardFault_IRQn = -13,
        SVC_IRQn = -5,
        PendSV_IRQn = -2,
        SysTick_IRQn = -1,
        PORT0_IRQn = 0,
        PORT1_IRQn = 1,
        PORT2_IRQn = 2,
        PORT3_IRQn = 3,
        IRQ04_IRQn = 4,
        IRQ05_IRQn = 5,
        UART0_IRQn = 6,
        UART1_IRQn = 7,
        LPUART_IRQn = 8,
        IRQ09_IRQn = 9,
        SPI_IRQn = 10,
        IRQ11_IRQn = 11,
        I2C_IRQn = 12,
        IRQ13_IRQn = 13,
        TIM0_IRQn = 14,
        TIM1_IRQn = 15,
        TIM2_IRQn = 16,
        LPTIM_IRQn = 17,
        TIM4_IRQn = 18,
        TIM5_IRQn = 19,
        TIM6_IRQn = 20,
        PCA_IRQn = 21,
        WDT_IRQn = 22,
        RTC_IRQn = 23,
        ADC_IRQn = 24,
        IRQ25_IRQn = 25,
        VC0_IRQn = 26,
        VC1_IRQn = 27,
        LVD_IRQn = 28,
        IRQ29_IRQn = 29,
        FLASH_RAM_IRQn = 30,
        CLK_TRIM_IRQn = 31,

    } IRQn_Type;

#define __read_only_data __attribute__((section(".rodata"))) const
#define __used __attribute__((used))
    extern uint32_t SystemCoreClock;
    extern uint32_t PeripheralCoreClock;

    void SystemInit(void);
#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_HC32L110_H__ */
