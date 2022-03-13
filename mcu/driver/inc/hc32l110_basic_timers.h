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
    stc_basic_timer_cr_field_t basic_timer_get_config(void *timer);
    void basic_timer_set_reload(void *timer, uint16_t reload_value);
    uint16_t basic_timer_get_reload(void *timer, uint16_t reload_value);
    void basic_timer_set_count(void *timer, uint32_t count);
    uint32_t basic_timer_get_count(void *timer);
    void basic_timer_clear_interrupt(void *timer);
    uint8_t basic_timer_get_interrupt(void *timer);
    void basic_timer_set_running(void *timer, uint8_t enabled);
    uint8_t basic_timer_get_running(void *timer);

#ifdef __cplusplus
}
#endif

#endif
