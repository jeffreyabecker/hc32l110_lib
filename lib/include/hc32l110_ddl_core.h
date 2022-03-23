
#ifndef __SYSTEM_HC32L110_DDL_CORE_H__
#define __SYSTEM_HC32L110_DDL_CORE_H__
#include "hc32l110_cmsis.h"
#include "hc32l110_system.h"
#include "hc32l110_registers_clock.h"

typedef enum
{
  core_clock_source_internal_high_speed = 0,
  core_clock_source_external_high_speed = 1,
  core_clock_source_internal_low_speed = 2,
  core_clock_source_external_low_speed = 3
} core_clock_source_t;

typedef enum
{
  core_system_clock_divider_1 = 0,
  core_system_clock_divider_2 = 1,
  core_system_clock_divider_4 = 2,
  core_system_clock_divider_8 = 3,
  core_system_clock_divider_16 = 4,
  core_system_clock_divider_32 = 5,
  core_system_clock_divider_64 = 6,
  core_system_clock_divider_128 = 7,
} core_system_clock_divider_t;
typedef enum
{
  core_peripheral_clock_divider_1 = 0,
  core_peripheral_clock_divider_2 = 1,
  core_peripheral_clock_divider_4 = 2,
  core_peripheral_clock_divider_8 = 3,
} core_peripheral_clock_divider_t;

void peripheral_set_enabled(peripheral_t peripheral);
peripheral_t peripheral_get_enabled();
#define peripheral_enable(peripheral) peripheral_set_enabled(peripheral_get_enabled() | peripheral);
#define peripheral_disable(peripheral) peripheral_set_enabled(peripheral_get_enabled() & ~peripheral);

uint32_t systick_current_value();
void systick_delay(uint32_t delay_ticks);
void core_set_system_clock(core_clock_source_t source,uint32_t clock_frequency_hz, core_system_clock_divider_t system_clock_prescaler, core_peripheral_clock_divider_t peripheral_clock_prescaler);

void core_enable_systick(uint32_t systick_frequency_hz);

#define KHz_1 1000

#endif