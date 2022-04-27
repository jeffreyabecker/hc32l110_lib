#ifndef __DDL_CORE_TIMER_COUNTER_H__
#define __DDL_CORE_TIMER_COUNTER_H__
#include "hc32l110_system.h"

#include "timer.h"
class TimerCounter : public InterruptHandler {
    private:
        volatile uint32_t _count;
        Timer* _timer;
    public:
        TimerCounter(Timer* timer);
        ~TimerCounter();
        virtual void invoke(irq_t irq) override;
        uint32_t elapsed();
        void start();
        void stop();
        void delay(uint32_t ticks);
};

#endif
