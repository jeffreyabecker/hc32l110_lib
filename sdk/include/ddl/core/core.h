
#ifndef __DDL_CORE_ALL_H__
#define __DDL_CORE_ALL_H__
#include "hc32l110_system.h"
#include "interrupt_handler.h"
#include "device.h"
#include "nvic.h"
#include "system_clock.h"
#include "systick.h"
#include "timer.h"
#include "timer_counter.h"


extern SystemClock system_clock;
extern SystickDevice systick;
extern TimerCounter systick_timer;




#endif
