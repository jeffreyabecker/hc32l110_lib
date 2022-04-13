#ifndef __HC32L110C_CMSIS_H__
#define __HC32L110C_CMSIS_H__

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

#include <core_cm0.h>
#include <stdint.h>

#define __read_only_data __attribute__((section(".rodata"))) const
#define __used __attribute__((used))
/* following defines should be used for structure members */
#define __IM volatile const
#define __OM volatile
#define __IOM volatile

#endif /* __HC32L110C_H__ */
