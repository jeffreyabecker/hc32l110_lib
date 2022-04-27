#ifndef __DDL_CORE_SYSTICK_H__
#define __DDL_CORE_SYSTICK_H__
#include "hc32l110_system.h"

#include "timer.h"
#define KHz_1 1000
class SystickDevice : public Timer{

  public:
    void configure(uint32_t frequency_hz);
    virtual uint32_t count() override;
    virtual void count(uint32_t value) override;

    virtual void running(uint8_t enabled) override;
    virtual uint8_t running() override;

    virtual uint8_t has_interrupt() override;
    virtual void clear_interrupt() override;
};


#endif
