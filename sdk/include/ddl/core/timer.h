#ifndef __DDL_CORE_TIMER_H__
#define __DDL_CORE_TIMER_H__
#include "hc32l110_system.h"

#include "device.h"
class Timer : public Device
{
public:
    virtual uint32_t count() =0;
    virtual void count(uint32_t value) =0;

    virtual void running(uint8_t enabled) = 0;
    virtual uint8_t running() = 0;

    virtual uint8_t has_interrupt() = 0;
    virtual void clear_interrupt() = 0;

};

#endif
