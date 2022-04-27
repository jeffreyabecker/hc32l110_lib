#ifndef __DDL_CORE_TIMERS_H__
#define __DDL_CORE_TIMERS_H__
#include "hc32l110_system.h"

#include "ddl/core/core.h"
#include "ddl/timers/basic_timer.h"
#include "ddl/timers/lp_timer.h"
extern BasicTimer timer_tim0;
extern BasicTimer timer_tim1;
extern BasicTimer timer_tim2;
extern LowPowerTimer timer_lptim;

#endif
