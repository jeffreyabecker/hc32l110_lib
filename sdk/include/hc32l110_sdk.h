#ifndef __HC32L110_SDK_H__
#define __HC32L110_SDK_H__
#include "hc32l110_registers_bt.h"
#include "hc32l110_registers_clock.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_i2c.h"
#include "hc32l110_registers_pca.h"
#include "hc32l110_registers_rtc_wdt.h"
#include "hc32l110_registers_spi.h"
#include "hc32l110_registers_uart.h"

#include "hc32l110_ddl_core.h"

#ifdef HC32_USE_DDL_BASIC_TIMERS
#include "hc32l110_ddl_basic_timers.h"
#endif
#ifdef HC32_USE_DDL_CLOCK_DYNAMIC
#include "hc32l110_ddl_clock_dynamic.h"
#endif
#ifdef HC32_USE_DDL_DEBUG
#include "hc32l110_ddl_debug.h"
#endif
#ifdef HC32_USE_DDL_GPIO
#include "hc32l110_ddl_gpio.h"
#endif
#ifdef HC32_USE_DDL_I2C
#include "hc32l110_ddl_i2c.h"
#endif


#endif