
#ifndef __HC32L110_PLATFORM_H__
#define __HC32L110_PLATFORM_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>
/******************************************************************************
 * Configuration of the Cortex-M0P Processor and Core Peripherals
 ******************************************************************************/
#define __MPU_PRESENT 0          /* No MPU                                       */
#define __NVIC_PRIO_BITS 2       /* M0P uses 2 Bits for the Priority Levels      */
#define __Vendor_SysTickConfig 0 /* Set to 1 if different SysTick Config is used */

    /******************************************************************************
     * Interrupt Number Definition
     ******************************************************************************/

    typedef enum IRQn
    {

        irq_nmi = -14,        /*  2 Non Maskable*/
        irq_hard_fault = -13, /*  3 Hard Fault*/
        irq_svc = -5,         /* 11 SV Call*/
        irq_pend_sv = -2,     /* 14 Pend SV*/
        irq_sys_tick = -1,    /* 15 System Tick*/
        irq_port_0 = 0,
        irq_port_1 = 1,
        irq_port_2 = 2,
        irq_port_3 = 3,
        irq_user_0 = 4,
        irq_user_1 = 5,
        irq_uart_0 = 6,
        irq_uart_1 = 7,
        irq_lpuart = 8,
        irq_user_2 = 9,
        irq_spi = 10,
        irq_user_3 = 11,
        irq_i2c = 12,
        irq_user_4 = 13,
        irq_timer_0 = 14,
        irq_timer_1 = 15,
        irq_timer_2 = 16,
        irq_low_power_timer = 17,
        irq_timer_4 = 18,
        irq_timer_5 = 19,
        irq_timer_6 = 20,
        irq_pca = 21,
        irq_watchdog_timer = 22,
        irq_realtime_clock = 23,
        irq_analog_digital_converter = 24,
        irq_user_5 = 25,
        irq_voltage_comparitor_0 = 26,
        irq_voltage_comparitor_1 = 27,
        irq_low_voltage = 28,
        irq_ef_ram = 30,
        irq_clock_trim = 31,
    } IRQn_Type;

#include "core_cm0plus.h"

#ifdef __cplusplus
}
#endif

#endif /* __HC32L110_PLATFORM_H__ */
