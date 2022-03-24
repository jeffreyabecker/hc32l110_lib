#ifndef __SYSTEM_HC32L110_DDL_BASIC_TIMERS_H__
#define __SYSTEM_HC32L110_DDL_BASIC_TIMERS_H__
#include <stdint.h>
#include <stddef.h>
#include "hc32l110_registers_basic_timers.h"
typedef void (*basic_timer_handler_t)(const void *timer);
typedef struct
{
    basic_timer_mode_t mode : 1;
    basic_timer_source_t tick_source : 1;
    union
    {
        basic_timer_prescaler_t prescaler : 4;
        lp_timer_clock_select_t low_power_clock_source : 4;
    };
    uint8_t enable_inverted_output : 1;
    uint8_t enable_gate : 1;
    uint8_t gate_polarity : 1;
    uint8_t interrupt_enabled : 1;
    union
    {
        uint32_t oneshot;
        struct
        {
            uint16_t preload : 16;
            uint16_t reload : 16;
        } periodic;
    } preload;
} basic_timer_config_t;

void basic_timer_configure(const void *timer, const basic_timer_config_t *cfg, const basic_timer_handler_t *callback);
void basic_timer_interrupt_clear(const void *timer);
uint8_t basic_timer_interrupt_get(const void *timer);
void basic_timer_set_running(const void *timer, uint8_t enabled);


#endif