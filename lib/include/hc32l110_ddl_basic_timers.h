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
    basic_timer_handler_t *__timer_handlers[4] = {NULL, NULL, NULL, NULL};
    typedef struct
    {
        basic_timer_mode_t mode : 1;
        basic_timer_source_t tick_source : 1;
        union
        {
            stc_basic_timer_prescaler_t prescaler : 4;
            stc_lp_timer_clock_select_t low_power_clock_source : 4;
        } uint8_t enable_inverted_output : 1;
        uint8_t enable_gate : 1;
        uint8_t gate_polarity : 1;
        uint8_t interrupt_enabled : 1;
        union
        {
            uint32_t one_shot_preload;
            struct
            {
                uint16_t : preload;
                uint16_t : reload;
            } periodic;
        }
    } basic_timer_config_t;
    static inline uint32_t __basic_timer_get_index(void *timer)
    {
        return ((((uint32_t)timer) - TIMER_0_ADDRESS) / 24);
    }
    void basic_timer_configure(void *timer, basic_timer_config_t cfg, basic_timer_handler_t *callback)
    {
        uint32_t index = __basic_timer_get_index(timer);
        __timer_handlers[index] = cfg.interrupt_enabled ? callback : NULL;
        if (((uint32_t)timer) == LPTIMER_ADDRESS)
        {
            core_peripheral_set_enabled(peripheral_lptimer);
            M0P_LPTIMER_TypeDef *l = timer;
            l->control.mode = cfg.mode;
            l->control.low_power.clock_source = cfg.low_power_clock_source
                                                    l->control.tick_source = cfg.tick_source;
            l->control.enable_inverted_output = cfg.enable_inverted_output;
            l->control.enable_gate = cfg.enable_gate;
            l->control.gate_polarity = cfg.gate_polarity;
            l->control.interrupt_enabled = cfg.interrupt_enabled;
            (((M0P_BasicTimer_TypeDef *)timer)->interrupt_clear) = 0;
            if (cfg.mode == basic_timer_mode_one_shot)
            {
                l->count_32 = cfg.one_shot_preload;
            }
            else
            {
                l->auto_reload = cfg.periodic.reload;
                l->count_16 = cfg.periodic.preload;
            }
        }
        else
        {
            core_peripheral_set_enabled(peripheral_base_timer);
            M0P_BasicTimer_TypeDef *t = timer;
            t->control.mode = cfg.mode;
            t->control.prescaler = cfg.prescaler;
            t->control.tick_source = cfg.tick_source;
            t->control.enable_inverted_output = cfg.enable_inverted_output;
            t->control.enable_gate = cfg.enable_gate;
            t->control.gate_polarity = cfg.gate_polarity;
            t->control.interrupt_enabled = cfg.interrupt_enabled;
            (((M0P_BasicTimer_TypeDef *)timer)->interrupt_clear) = 0;
            if (cfg.mode == basic_timer_mode_one_shot)
            {
                t->count_32 = cfg.one_shot_preload;
            }
            else
            {
                t->auto_reload = cfg.periodic.reload;
                t->count_16 = cfg.periodic.preload;
            }
        }
    }

    void basic_timer_interrupt_clear(void *timer)
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
    uint8_t basic_timer_interrupt_get(void *timer)
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

    void Timer0_Handler(void)
    {
        if (__timer_handlers[0] != NULL)
        {
            (*__timer_handlers[0])(M0P_TIMER0);
        }
    }
    void Timer1_Handler(void)
    {
        if (__timer_handlers[1] != NULL)
        {
            (*__timer_handlers[1])(M0P_TIMER1);
        }
    }
    void Timer2_Handler(void)
    {
        if (__timer_handlers[2] != NULL)
        {
            (*__timer_handlers[2])(M0P_TIMER2);
        }
    }
    void LpTimer_Handler(void)
    {
        if (__timer_handlers[3] != NULL)
        {
            (*__timer_handlers[3])(M0P_LPTIMER);
        }
    }
#ifdef __cplusplus
}
#endif

#endif
#endif