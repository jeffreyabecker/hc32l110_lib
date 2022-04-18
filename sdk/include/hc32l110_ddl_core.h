
#ifndef __SYSTEM_HC32L110_DDL_CORE_H__
#define __SYSTEM_HC32L110_DDL_CORE_H__
#include "hc32l110_cmsis.h"
#include "hc32l110_system.h"
#include "hc32l110_registers_clock.h"
#include <stddef.h>

typedef struct systick_counter_type
{
  struct systick_counter_type *next;
  uint32_t count;
} systick_counter_t;

void peripheral_set_enabled(peripheral_t peripheral);
peripheral_t peripheral_get_enabled();
#define peripheral_enable(peripheral) peripheral_set_enabled(peripheral_get_enabled() | peripheral);
#define peripheral_disable(peripheral) peripheral_set_enabled(peripheral_get_enabled() & ~peripheral);

void nvic_clear_interrupt(IRQn_Type irq);
void nvic_enable_interrupt(IRQn_Type irq);
void nvic_disable_interrupt(IRQn_Type irq);
void nvic_set_interrupt_priority(IRQn_Type irq, uint8_t priority);
#define nvic_default_irq_priority 0x03

#define SYSTICK_RUNNING_MASK 0x00000007
#define systick_is_running() ((HC32_SYSTICK->CTRL & SYSTICK_RUNNING_MASK) == SYSTICK_RUNNING_MASK)
void enable_systick(uint32_t systick_frequency_hz);
uint32_t systick_current_value();
uint32_t systick_time_since(uint32_t start);
void systick_counter_start(systick_counter_t *counter);
uint32_t systick_counter_elapsed(systick_counter_t *counter);
void systick_counter_complete(systick_counter_t *counter);
void systick_counter_delay(systick_counter_t *counter, uint32_t ticks);
void systick_delay(uint32_t ticks);
void clock_set_freq(uint32_t freqency_hz, uint16_t clock_trim);
#endif