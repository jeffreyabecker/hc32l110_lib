#include <stdint.h>
#include <core_cm0plus.h>
#ifdef __cplusplus
extern "C"
{
#endif
    typedef void (*irq_handler_t)();
    extern uint32_t __INITIAL_SP;
    extern void main();

    void nvic_handle_reset(void) __WEAK __NO_RETURN;
    void nvic_handle_nmi(void) __WEAK;
    void nvic_handle_hard_fault(void) __WEAK;
    void nvic_handle_svc(void) __WEAK;
    void nvic_handle_pend_sv(void) __WEAK;
    void nvic_handle_sys_tick(void) __WEAK;
    void nvic_handle_port_0(void) __WEAK;
    void nvic_handle_port_1(void) __WEAK;
    void nvic_handle_port_2(void) __WEAK;
    void nvic_handle_port_3(void) __WEAK;
    void nvic_handle_user_0(void) __WEAK;
    void nvic_handle_user_1(void) __WEAK;
    void nvic_handle_uart_0(void) __WEAK;
    void nvic_handle_uart_1(void) __WEAK;
    void nvic_handle_lpuart(void) __WEAK;
    void nvic_handle_user_2(void) __WEAK;
    void nvic_handle_spi(void) __WEAK;
    void nvic_handle_user_3(void) __WEAK;
    void nvic_handle_i2c(void) __WEAK;
    void nvic_handle_user_4(void) __WEAK;
    void nvic_handle_timer_0(void) __WEAK;
    void nvic_handle_timer_1(void) __WEAK;
    void nvic_handle_timer_2(void) __WEAK;
    void nvic_handle_low_power_timer(void) __WEAK;
    void nvic_handle_timer_4(void) __WEAK;
    void nvic_handle_timer_5(void) __WEAK;
    void nvic_handle_timer_6(void) __WEAK;
    void nvic_handle_pca(void) __WEAK;
    void nvic_handle_watchdog_timer(void) __WEAK;
    void nvic_handle_realtime_clock(void) __WEAK;
    void nvic_handle_analog_digital_converter(void) __WEAK;
    void nvic_handle_user_5(void) __WEAK;
    void nvic_handle_voltage_comparitor_0(void) __WEAK;
    void nvic_handle_voltage_comparitor_1(void) __WEAK;
    void nvic_handle_low_voltage(void) __WEAK;
    void nvic_handle_user_6(void) __WEAK;
    void nvic_handle_ef_ram(void) __WEAK;
    void nvic_handle_clock_trim(void) __WEAK;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

    extern const irq_handler_t __VECTOR_TABLE[48];
    const irq_handler_t __VECTOR_TABLE[48] __attribute__((used, section(".vectors"))) = {
        (irq_handler_t)(&__INITIAL_SP), /*     Initial Stack Pointer */
        nvic_handle_reset,
        nvic_handle_nmi,
        nvic_handle_hard_fault,
        0, // Reserved
        0, // Reserved
        0, // Reserved
        0, // Reserved
        0, // Reserved
        0, // Reserved
        0, // Reserved
        nvic_handle_svc,
        0, // Reserved
        0, // Reserved
        nvic_handle_pend_sv,
        nvic_handle_sys_tick,
        nvic_handle_port_0,
        nvic_handle_port_1,
        nvic_handle_port_2,
        nvic_handle_port_3,
        nvic_handle_user_0,
        nvic_handle_user_1,
        nvic_handle_uart_0,
        nvic_handle_uart_1,
        nvic_handle_lpuart,
        nvic_handle_user_2,
        nvic_handle_spi,
        nvic_handle_user_3,
        nvic_handle_i2c,
        nvic_handle_user_4,
        nvic_handle_timer_0,
        nvic_handle_timer_1,
        nvic_handle_timer_2,
        nvic_handle_low_power_timer,
        nvic_handle_timer_4,
        nvic_handle_timer_5,
        nvic_handle_timer_6,
        nvic_handle_pca,
        nvic_handle_watchdog_timer,
        nvic_handle_realtime_clock,
        nvic_handle_analog_digital_converter,
        nvic_handle_user_5,
        nvic_handle_voltage_comparitor_0,
        nvic_handle_voltage_comparitor_1,
        nvic_handle_low_voltage,
        nvic_handle_user_6,
        nvic_handle_ef_ram,
        nvic_handle_clock_trim,
    };

#pragma GCC diagnostic pop

    __WEAK void SystemInit();

    typedef struct
    {
        uint32_t const *src;
        uint32_t *dest;
        uint32_t wlen;
    } __copy_table_t;

    typedef struct
    {
        uint32_t *dest;
        uint32_t wlen;
    } __zero_table_t;

    extern const __copy_table_t __copy_table_start__;
    extern const __copy_table_t __copy_table_end__;
    extern const __zero_table_t __zero_table_start__;
    extern const __zero_table_t __zero_table_end__;
    /*----------------------------------------------------------------------------
    Reset Handler called on controller reset
    *----------------------------------------------------------------------------*/

    __WEAK void nvic_handle_reset(void)
    {
        SystemInit(); /* CMSIS System Initialization */

        for (__copy_table_t const *pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable)
        {
            for (uint32_t i = 0u; i < pTable->wlen; ++i)
            {
                pTable->dest[i] = pTable->src[i];
            }
        }

        for (__zero_table_t const *pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable)
        {
            for (uint32_t i = 0u; i < pTable->wlen; ++i)
            {
                pTable->dest[i] = 0u;
            }
        }

        main();
        while (1)
        {
            __WFI();
        }
    }
    __WEAK void nvic_handle_nmi(void)
    {
        // this interrupt isnt actually implemented in the chip and will never be called
    }
    __WEAK void nvic_handle_hard_fault(void)
    {
        while (1)
        {
            __WFI();
        }
    }
    __WEAK void nvic_handle_svc(void) {}
    __WEAK void nvic_handle_pend_sv(void) {}
    __WEAK void nvic_handle_sys_tick(void) {}
    __WEAK void nvic_handle_port_0(void) {}
    __WEAK void nvic_handle_port_1(void) {}
    __WEAK void nvic_handle_port_2(void) {}
    __WEAK void nvic_handle_port_3(void) {}
    __WEAK void nvic_handle_user_0(void) {}
    __WEAK void nvic_handle_user_1(void) {}
    __WEAK void nvic_handle_uart_0(void) {}
    __WEAK void nvic_handle_uart_1(void) {}
    __WEAK void nvic_handle_lpuart(void) {}
    __WEAK void nvic_handle_user_2(void) {}
    __WEAK void nvic_handle_spi(void) {}
    __WEAK void nvic_handle_user_3(void) {}
    __WEAK void nvic_handle_i2c(void) {}
    __WEAK void nvic_handle_user_4(void) {}
    __WEAK void nvic_handle_timer_0(void) {}
    __WEAK void nvic_handle_timer_1(void) {}
    __WEAK void nvic_handle_timer_2(void) {}
    __WEAK void nvic_handle_low_power_timer(void) {}
    __WEAK void nvic_handle_timer_4(void) {}
    __WEAK void nvic_handle_timer_5(void) {}
    __WEAK void nvic_handle_timer_6(void) {}
    __WEAK void nvic_handle_pca(void) {}
    __WEAK void nvic_handle_watchdog_timer(void) {}
    __WEAK void nvic_handle_realtime_clock(void) {}
    __WEAK void nvic_handle_analog_digital_converter(void) {}
    __WEAK void nvic_handle_user_5(void) {}
    __WEAK void nvic_handle_voltage_comparitor_0(void) {}
    __WEAK void nvic_handle_voltage_comparitor_1(void) {}
    __WEAK void nvic_handle_low_voltage(void) {}
    __WEAK void nvic_handle_user_6(void) {}
    __WEAK void nvic_handle_ef_ram(void) {}
    __WEAK void nvic_handle_clock_trim(void) {}

    uint32_t SystemCoreClock;

    __WEAK void SystemCoreClockUpdate(void) // Update core_system_clock_frequency variable
    {
        SystemCoreClock = 4000000;
    }

    __WEAK void SystemInit(void)
    {
        (*((volatile uint32_t *)(0x4000200Cul))) = (*((volatile uint16_t *)(0x00100C08ul))); // Load 4MHz Trimming value into M0P_CLOCK_RCH
        SystemCoreClockUpdate();
    }
#ifdef __cplusplus
}
#endif