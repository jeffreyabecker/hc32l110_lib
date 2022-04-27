#ifndef __DDL_CORE_DEVICE_H__
#define __DDL_CORE_DEVICE_H__
#include "hc32l110_system.h"

#include "interrupt_handler.h"
class Device {
  public:
    InterruptHandler interrupt;
    static void enabled(peripheral_t peripheral);
    static peripheral_t enabled();
    static void enable(peripheral_t peripheral);
    static void disable(peripheral_t peripheral);
};

#endif
