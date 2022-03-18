/**
 *******************************************************************************
 * @file  hc32l110_BASIC_TIMERS.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_BASIC_TIMERS_H__
#define __hc32l110_BASIC_TIMERS_H__
#if defined(DDL_USE_ALL) || (defined(DDL_USE_CORE) && defined(DDL_USE_BASIC_TIMERS))
#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_interrupts.h"
    typedef void (*basic_timer_handler_t)(void *timer);
    nvic_irq_number_t basic_timer_get_irq(void *timer);
    void basic_timer_set_interrupt_enabled(void *timer, uint8_t enabled);
    uint8_t basic_timer_get_interrupt_enabled(void *timer);
    void basic_timer_set_config(void *timer, stc_basic_timer_cr_field_t value);

    inline stc_basic_timer_cr_field_t basic_timer_get_config(void *timer)
    {

        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            return ((M0P_LPTIMER_TypeDef *)timer)->control;
        }
        else
        {
            return ((M0P_BasicTimer_TypeDef *)timer)->control;
        }
    }

    inline void basic_timer_set_reload(void *timer, uint16_t reload_value)
    {
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            ((M0P_LPTIMER_TypeDef *)timer)->auto_reload = reload_value;
        }
        else
        {
            ((M0P_BasicTimer_TypeDef *)timer)->auto_reload = reload_value;
        }
    }
    inline uint16_t basic_timer_get_reload(void *timer, uint16_t reload_value)
    {
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            return (((M0P_LPTIMER_TypeDef *)timer)->auto_reload);
        }
        else
        {
            return (((M0P_BasicTimer_TypeDef *)timer)->control.mode) == 0 ? 0 : ((M0P_BasicTimer_TypeDef *)timer)->auto_reload;
        }
    }

    inline void basic_timer_set_count(void *timer, uint32_t count)
    {
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            (((M0P_LPTIMER_TypeDef *)timer)->count_16) = count;
        }
        else
        {
            if ((((M0P_BasicTimer_TypeDef *)timer)->control.mode) == 0)
            {
                ((M0P_BasicTimer_TypeDef *)timer)->count_32 = count;
            }
            else
            {
                ((M0P_BasicTimer_TypeDef *)timer)->count_16 = count;
            }
        }
    }
    inline uint32_t basic_timer_get_count(void *timer)
    {
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            return (((M0P_LPTIMER_TypeDef *)timer)->count_16);
        }
        else
        {
            return (((M0P_BasicTimer_TypeDef *)timer)->control.mode) == 0 ? ((M0P_BasicTimer_TypeDef *)timer)->count_32 : ((M0P_BasicTimer_TypeDef *)timer)->count_16;
        }
    }

    inline void basic_timer_clear_interrupt(void *timer)
    {
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            (((M0P_LPTIMER_TypeDef *)timer)->interrupt_clear) = 0;
        }
        else
        {
            (((M0P_BasicTimer_TypeDef *)timer)->interrupt_clear) = 0;
        }
    }
    inline uint8_t basic_timer_get_interrupt(void *timer)
    {
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            return (((M0P_LPTIMER_TypeDef *)timer)->interrupt_flag);
        }
        else
        {
            return (((M0P_BasicTimer_TypeDef *)timer)->interrupt_flag);
        }
    }

    inline void basic_timer_set_running(void *timer, uint8_t enabled)
    {
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            (((M0P_LPTIMER_TypeDef *)timer)->control).timer_running = enabled;
        }
        else
        {
            (((M0P_BasicTimer_TypeDef *)timer)->control).timer_running = enabled;
        }
    }
    inline uint8_t basic_timer_get_running(void *timer)
    {
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            return (((M0P_LPTIMER_TypeDef *)timer)->control).timer_running;
        }
        else
        {
            return (((M0P_BasicTimer_TypeDef *)timer)->control).timer_running;
        }
    }

    inline nvic_irq_number basic_timer_get_irq(void *timer)
    {
        return irq_timer_0 + ((((uint32_t)timer) - TIMER_0_ADDRESS) / 24);
    }
    void basic_timer_set_interrupt_enabled(void *timer, uint8_t enabled)
    {
        if (enabled)
        {
            nvic_interrupt_set_enabled(basic_timer_get_irq(timer));
        }
        else
        {
            nvic_interrupt_set_enabled(basic_timer_get_irq(timer));
        }
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            ((M0P_LPTIMER_TypeDef *)timer)->control.interrupt_enabled = enabled;
        }
        else
        {
            ((M0P_BasicTimer_TypeDef *)timer)->control.interrupt_enabled = enabled;
        }
    }
    uint8_t basic_timer_get_interrupt_enabled(void *timer)
    {
        uint8_t nvic_enabled = nvic_is_interrupt_enabled(basic_timer_get_irq(timer));
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            return ((M0P_LPTIMER_TypeDef *)timer)->control.interrupt_enabled + nvic_enabled > 0 ? 1 : 0;
        }
        else
        {
            return ((M0P_BasicTimer_TypeDef *)timer)->control.interrupt_enabled + nvic_enabled > 0 ? 1 : 0;
        }
    }
    void basic_timer_set_config(void *timer, stc_basic_timer_cr_field_t value)
    {

        if (value.interrupt_enabled)
        {
            nvic_interrupt_enable(basic_timer_get_irq(timer));
        }
        else
        {
            nvic_interrupt_disable(basic_timer_get_irq(timer));
        }

        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            ((M0P_LPTIMER_TypeDef *)timer)->control = value;
        }
        else
        {
            ((M0P_BasicTimer_TypeDef *)timer)->control = value;
        }
    }
    basic_timer_handler_t *timer_handlers[4] = {NULL, NULL, NULL, NULL};

    void Timer0_Handler(void)
    {
        if (timer_handlers[0] != NULL)
        {
            (*timer_handlers[0])(M0P_TIMER0);
        }
    }
    void Timer1_Handler(void)
    {
        if (timer_handlers[1] != NULL)
        {
            (*timer_handlers[1])(M0P_TIMER1);
        }
    }
    void Timer2_Handler(void)
    {
        if (timer_handlers[2] != NULL)
        {
            (*timer_handlers[2])(M0P_TIMER2);
        }
    }
    void LpTimer_Handler(void)
    {
        if (timer_handlers[3] != NULL)
        {
            (*timer_handlers[3])(M0P_LPTIMER);
        }
    }
#ifdef __cplusplus
}
#endif

#endif
#endif