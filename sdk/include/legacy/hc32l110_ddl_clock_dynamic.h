
#ifndef __HC32L110_DDL_CLOCK_DYNAMIC_H__
#define __HC32L110_DDL_CLOCK_DYNAMIC_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "hc32l110_system.h"

#include <stddef.h>
#define KHz_32_8 32800
#define KHz_38_4 38400
#define MHz_4 4000000
#define MHz_8 8000000
#define MHz_16 16000000
#define MHz_22_12 22120000
#define MHz_24 24000000

typedef enum
{
  clock_sourceinternal_high_speed = 0,
  clock_sourceexternal_high_speed = 1,
  clock_sourceinternal_low_speed = 2,
  clock_sourceexternal_low_speed = 3
} clock_source_t;

typedef enum
{
  system_clock_divider_1 = 0,
  system_clock_divider_2 = 1,
  system_clock_divider_4 = 2,
  system_clock_divider_8 = 3,
  system_clock_divider_16 = 4,
  system_clock_divider_32 = 5,
  system_clock_divider_64 = 6,
  system_clock_divider_128 = 7,
} system_clock_divider_t;
typedef enum
{
  peripheral_clock_divider_1 = 0,
  peripheral_clock_divider_2 = 1,
  peripheral_clock_divider_4 = 2,
  peripheral_clock_divider_8 = 3,
} peripheral_clock_divider_t;


void set_system_clock(clock_source_t source, uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler);
#ifdef __cplusplus
}
#endif

#endif
