#ifndef __HC32L110_SDK_H__
#define __HC32L110_SDK_H__
#include "hc32l110_system.h"
#include "ddl/core/core.h"

#ifdef HC32_USE_DDL_TIMERS
#include "ddl/timers/timers.h"
#endif
#ifdef HC32_USE_DDL_CLOCK_DYNAMIC
#include "hc32l110_ddl_clock_dynamic.h"
#endif
#ifdef HC32_USE_DDL_DEBUG
#include "hc32l110_ddl_debug.h"
#endif
#ifdef HC32_USE_DDL_GPIO
#include "ddl/gpio.h"
#endif
// #ifdef HC32_USE_DDL_I2C
// #include "hc32l110_ddl_i2c.h"
// #endif
#ifdef HC32_USE_DDL_UTILS
#include "ddl/utils/utils.h"
#endif

#endif
