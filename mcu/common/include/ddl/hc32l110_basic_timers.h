/**
 *******************************************************************************
 * @file  hc32l110_BASIC_TIMERS.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_BASIC_TIMERS_H__
#define __hc32l110_BASIC_TIMERS_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_core.h"
#include "hc32l110_interrupts.h"

    IRQn_Type basic_timer_get_irq(void *timer);
    void basic_timer_set_interrupt_enabled(void *timer, uint8_t enabled);
    uint8_t basic_timer_get_interrupt_enabled(void *timer);
    void basic_timer_set_config(void *timer, stc_basic_timer_cr_field_t value);

    __INLINE stc_basic_timer_cr_field_t basic_timer_get_config(void *timer)
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

    __INLINE void basic_timer_set_reload(void *timer, uint16_t reload_value)
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
    __INLINE uint16_t basic_timer_get_reload(void *timer, uint16_t reload_value)
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

    __INLINE void basic_timer_set_count(void *timer, uint32_t count)
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
    __INLINE uint32_t basic_timer_get_count(void *timer)
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

    __INLINE void basic_timer_clear_interrupt(void *timer)
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
    __INLINE uint8_t basic_timer_get_interrupt(void *timer)
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

    __INLINE void basic_timer_set_running(void *timer, uint8_t enabled)
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
    __INLINE uint8_t basic_timer_get_running(void *timer)
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
#ifdef __cplusplus
}
#endif

#endif
