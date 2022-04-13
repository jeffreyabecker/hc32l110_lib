#ifndef __SYSTEM_HC32L110_DDL_BASIC_TIMERS_H__
#define __SYSTEM_HC32L110_DDL_BASIC_TIMERS_H__
#include <stdint.h>
#include <stddef.h>
#include "hc32l110_registers_basic_timers.h"
typedef void (*basic_timer_handler_t)(hc32_basic_timer_register_t *timer);


typedef struct
{
    basic_timer_mode_t mode : 1;
    basic_timer_source_t tick_source : 1;
    basic_timer_prescaler_t prescaler : 4;
    uint8_t enable_inverted_output : 1;
    uint8_t enable_gate : 1;
    uint8_t gate_polarity : 1;
    uint8_t interrupt_enabled : 1;
    uint32_t reload;
} basic_timer_config_t;


void basic_timer_configure(hc32_basic_timer_register_t *timer, const basic_timer_config_t *cfg, const basic_timer_handler_t callback);
void basic_timer_set_running(hc32_basic_timer_register_t *timer, uint8_t enabled);
#define peripheral_enable_basic_timer() peripheral_set_enabled(peripheral_get_enabled() | peripheral_basetim )


#endif