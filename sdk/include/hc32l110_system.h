#ifndef __SYSTEM_HC32L110_SYSTEM_H__
#define __SYSTEM_HC32L110_SYSTEM_H__
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

#define __MPU_PRESENT 0
#define __NVIC_PRIO_BITS 2
#define __Vendor_SysTickConfig 0

    typedef enum
    {
        irq_nmi = -14,
        irq_hard_fault = -13,
        irq_svc = -5,
        irq_pend_sv = -2,
        irq_sys_tick = -1,
        irq_port_0 = 0,
        irq_port_1 = 1,
        irq_port_2 = 2,
        irq_port_3 = 3,
        irq_open_04 = 4,
        irq_open_05 = 5,
        irq_uart_0 = 6,
        irq_uart_1 = 7,
        irq_lp_uart = 8,
        irq_open_09 = 9,
        irq_SPI = 10,
        irq_open_11 = 11,
        irq_i2c = 12,
        irq_open_13 = 13,
        irq_timer_0 = 14,
        irq_timer_1 = 15,
        irq_timer_2 = 16,
        irq_lp_timer = 17,
        irq_timer_4 = 18,
        irq_timer_5 = 19,
        irq_timer_6 = 20,
        irq_pca = 21,
        irq_wdt = 22,
        irq_rtc = 23,
        irq_adc = 24,
        irq_open_25 = 25,
        irq_vc_0 = 26,
        irq_vc_1 = 27,
        irq_lvd = 28,
        irq_open_29 = 29,
        irq_flash_ram = 30,
        irq_clock_trim = 31,

    } irq_t;

#define __read_only_data __attribute__((section(".rodata"))) const
#define __used __attribute__((used))
    // extern uint32_t SystemCoreClock;
    // extern uint32_t PeripheralCoreClock;

void SystemInit(void);
#include "registers/registers.h"
#ifdef __cplusplus
}
#endif


#endif /* __SYSTEM_HC32L110_H__ */
