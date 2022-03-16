#ifndef __hc32l110_INTERRUPTS_H__
#define __hc32l110_INTERRUPTS_H__
#if defined(DDL_USE_CORE) && (defined(DDL_USE_ALL) || defined(DDL_USE_INTERRUPTS))
#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_ddl_core.h"


    typedef void (*nvic_interrupt_handler_t)(nivc_irq_number_t irq_number, void *data);

    void nvic_interrupt_set_handler(nivc_irq_number_t irq_number, nvic_interrupt_handler_t handler, void *data);
    void nvic_interrupt_set_enabled(nivc_irq_number_t irq_number, uint8_t enabled);
    void nvic_interrupt_raise(nivc_irq_number_t irq_number);
    void nvic_interrupt_clear(nivc_irq_number_t irq_number);
    typedef struct
    {
        nvic_interrupt_handler_t handler;
        void *data;
    } nvic_interrupt_table_entry_t;

    static nvic_interrupt_table_entry_t nvic_indirection_table[36] = {NULL};
#define __nvic_table_index(irq_number) ((int32_t)irq_number >= 0 ? ((int32_t)irq_number + 5) : irq_number == irq_sys_tick ? 4 \
                                                                                           : irq_number == irq_pend_sv    ? 3 \
                                                                                           : irq_number == irq_svc        ? 2 \
                                                                                           : irq_number == irq_hard_fault ? 1 \
                                                                                                                          : 0)
    static inline void _nvic_invoke_irq(nivc_irq_number_t irq_number)
    {
        uint32_t idx = __nvic_table_index(irq_number);
        if (nvic_indirection_table[idx].handler != NULL)
        {
            nvic_indirection_table[idx].handler(irq_nmi, nvic_indirection_table[idx].data);
        }
        nvic_clear_pending_irq(irq_number);
    }
    void nvic_interrupt_set_handler(nivc_irq_number_t irq_number, nvic_interrupt_handler_t handler, void *data)
    {
        uint32_t index = __nvic_table_index(irq_number);
        nvic_indirection_table[index].handler = handler;
        nvic_indirection_table[index].data = data;
    }
    void nvic_interrupt_set_enabled(nivc_irq_number_t irq_number, uint8_t enabled)
    {
        nvic_clear_pending_irq(irq_number);
        if (enabled == 0)
        {
            nvic_disable_irq(irq_number);
        }
        else
        {
            nvic_enable_irq(irq_number);
        }
    }
    
    void nvic_interrupt_raise(nivc_irq_number_t irq_number)
    {
        if ((int32_t)(irq_number) >= 0)
        {
            NVIC->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)irq_number) & 0x1FUL));
        }
    }
    void nvic_interrupt_clear(nivc_irq_number_t irq_number)
    {
        nvic_clear_pending_irq(irq_number);
    }

    void NMI_Handler(void)
    {
        _nvic_invoke_irq(irq_nmi);
    }
    void HardFault_Handler(void)
    {
        _nvic_invoke_irq(irq_hard_fault);
    }
    void SVC_Handler(void)
    {
        _nvic_invoke_irq(irq_svc);
    }
    void PendSV_Handler(void)
    {
        _nvic_invoke_irq(irq_pend_sv);
    }
    void SysTick_Handler(void)
    {
        core_systick_increment_ticks();
        _nvic_invoke_irq(irq_sys_tick);
    }
    void GpioPort0_Handler(void)
    {
        _nvic_invoke_irq(irq_port_0);
    }
    void GpioPort1_Handler(void)
    {
        _nvic_invoke_irq(irq_port_1);
    }
    void GpioPort2_Handler(void)
    {
        _nvic_invoke_irq(irq_port_2);
    }
    void GpioPort3_Handler(void)
    {
        _nvic_invoke_irq(irq_port_3);
    }
    void UserInterrupt0_Handler(void)
    {
        _nvic_invoke_irq(irq_user_0);
    }
    void UserInterrupt1_Handler(void)
    {
        _nvic_invoke_irq(irq_user_1);
    }
    void Uart0_Handler(void)
    {
        _nvic_invoke_irq(irq_uart_0);
    }
    void Uart1_Handler(void)
    {
        _nvic_invoke_irq(irq_uart_1);
    }
    void LpUart_Handler(void)
    {
        _nvic_invoke_irq(irq_lpuart);
    }
    void UserInterrupt2_Handler(void)
    {
        _nvic_invoke_irq(irq_user_2);
    }
    void SPI_Handler(void)
    {
        _nvic_invoke_irq(irq_spi);
    }
    void UserInterrupt3_Handler(void)
    {
        _nvic_invoke_irq(irq_user_3);
    }
    void I2C_Handler(void)
    {
        _nvic_invoke_irq(irq_i2c);
    }
    void UserInterrupt4_Handler(void)
    {
        _nvic_invoke_irq(irq_user_4);
    }
    void Timer0_Handler(void)
    {
        _nvic_invoke_irq(irq_timer_0);
    }
    void Timer1_Handler(void)
    {
        _nvic_invoke_irq(irq_timer_1);
    }
    void Timer2_Handler(void)
    {
        _nvic_invoke_irq(irq_timer_2);
    }
    void LpTimer_Handler(void)
    {
        _nvic_invoke_irq(irq_low_power_timer);
    }
    void Timer4_Handler(void)
    {
        _nvic_invoke_irq(irq_timer_4);
    }
    void Timer5_Handler(void)
    {
        _nvic_invoke_irq(irq_timer_5);
    }
    void Timer6_Handler(void)
    {
        _nvic_invoke_irq(irq_timer_6);
    }
    void PCA_Handler(void)
    {
        _nvic_invoke_irq(irq_pca);
    }
    void WatchDogTimer_Handler(void)
    {
        _nvic_invoke_irq(irq_watchdog_timer);
    }
    void RTC_Handler(void)
    {
        _nvic_invoke_irq(irq_realtime_clock);
    }
    void ADC_Handler(void)
    {
        _nvic_invoke_irq(irq_analog_digital_converter);
    }
    void UserInterrupt5_Handler(void)
    {
        _nvic_invoke_irq(irq_user_5);
    }
    void VC0_Handler(void)
    {
        _nvic_invoke_irq(irq_voltage_comparitor_0);
    }
    void VC1_Handler(void)
    {
        _nvic_invoke_irq(irq_voltage_comparitor_1);
    }
    void LVD_Handler(void)
    {
        _nvic_invoke_irq(irq_low_voltage);
    }
    void EfRam_Handler(void)
    {
        _nvic_invoke_irq(irq_ef_ram);
    }
    void ClockTrim_Handler(void)
    {
        _nvic_invoke_irq(irq_clock_trim);
    }

#ifdef __cplusplus
}
#endif

#endif
#endif