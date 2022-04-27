#ifndef __HC32L110_DDL_TIMER_H__
#define __HC32L110_DDL_TIMER_H__

#include <stdint.h>
#include <stddef.h>
#include "hc32l110_registers.h"
#include "hc32l110_system.h"
#include "hc32l110_ddl_interrupt_invocation_handler.h"

class Timer
{
public:
    virtual basic_timer_mode_t mode() = 0;
    virtual void mode(basic_timer_mode_t value) = 0;

    virtual timer_function_t function() = 0;
    virtual void function(timer_function_t value) = 0;

    virtual uint8_t enable_inverted_output() = 0;
    virtual void enable_inverted_output(uint8_t value) = 0;

    virtual uint8_t enable_gate() = 0;
    virtual void enable_gate(uint8_t value) = 0;

    virtual uint8_t gate_polarity() = 0;
    virtual void gate_polarity(uint8_t value) = 0;

    virtual uint8_t interrupt_enabled() = 0;
    virtual void interrupt_enabled(uint8_t value) = 0;

    virtual uint32_t reload() = 0;
    virtual void reload(uint32_t value) = 0;

    virtual uint32_t count() = 0;
    virtual void count(uint32_t value) = 0;

    virtual void running(uint8_t enabled) = 0;
    virtual uint8_t running() = 0;

    virtual uint8_t has_interrupt() = 0;
    virtual void clear_interrupt() = 0;

    virtual void interrupt_handler(InterruptInvocationHandler<Timer> *h) = 0;
    virtual void invoke_interrupt(irq_t irq) = 0;
};



class BasicTimer : Timer
{
private:
    hc32_basic_timer_register_t *timer;
    InterruptInvocationHandler<Timer> *handler;

public:
    BasicTimer(hc32_basic_timer_register_t *t);

    static void enable_peripheral();


    virtual basic_timer_mode_t mode() override;
    virtual void mode(basic_timer_mode_t value) override;

    virtual timer_function_t function() override;
    virtual void function(timer_function_t value) override;

    virtual basic_timer_prescaler_t prescaler() ;
    virtual void prescaler(basic_timer_prescaler_t value) ;

    virtual uint8_t enable_inverted_output() override;
    virtual void enable_inverted_output(uint8_t value) override;

    virtual uint8_t enable_gate() override;
    virtual void enable_gate(uint8_t value) override;

    virtual uint8_t gate_polarity() override;
    virtual void gate_polarity(uint8_t value) override;

    virtual uint8_t interrupt_enabled() override;
    virtual void interrupt_enabled(uint8_t value) override;

    virtual uint32_t reload() override;
    virtual void reload(uint32_t value) override;

    virtual uint32_t count() override;
    virtual void count(uint32_t value) override;

    virtual void running(uint8_t enabled) override;
    virtual uint8_t running() override;

    virtual uint8_t has_interrupt() override;
    virtual void clear_interrupt() override;

    virtual void interrupt_handler(InterruptInvocationHandler<Timer> *h) override;
    virtual void invoke_interrupt(irq_t irq) override;
};

class LowPowerTimer : Timer
{
private:
    hc32_lp_timer_register_t *timer;
    InterruptInvocationHandler<Timer> *handler;

public:
    LowPowerTimer(hc32_lp_timer_register_t *t);

    static void enable_peripheral();


    virtual basic_timer_mode_t mode() override;
    virtual void mode(basic_timer_mode_t value) override;

    virtual timer_function_t function() override;
    virtual void function(timer_function_t value) override;

    lp_timer_clock_source_t clock_source();
    void clock_source(lp_timer_clock_source_t value);

    virtual uint8_t enable_inverted_output() override;
    virtual void enable_inverted_output(uint8_t value) override;

    virtual uint8_t enable_gate() override;
    virtual void enable_gate(uint8_t value) override;

    virtual uint8_t gate_polarity() override;
    virtual void gate_polarity(uint8_t value) override;

    virtual uint8_t interrupt_enabled() override;
    virtual void interrupt_enabled(uint8_t value) override;

    virtual uint32_t reload() override;
    virtual void reload(uint32_t value) override;

    virtual uint32_t count() override;
    virtual void count(uint32_t value) override;

    virtual void running(uint8_t enabled) override;
    virtual uint8_t running() override;

    virtual uint8_t has_interrupt() override;
    virtual void clear_interrupt() override;

    virtual void interrupt_handler(InterruptInvocationHandler<Timer> *handler) override;
    virtual void invoke_interrupt(irq_t irq) override;
};

extern BasicTimer timer_tim0;
extern BasicTimer timer_tim1;
extern BasicTimer timer_tim2;
extern LowPowerTimer timer_lptim;

class TimerCounter : InterruptInvocationHandler<Timer>{
    private:
        volatile uint32_t _count;
        Timer* _timer;
    public:
        TimerCounter(Timer* timer);
        virtual void invoke(Timer *device, irq_t irq) override;
        uint32_t elapsed();
        void start();
        void stop();
        void delay(uint32_t ticks);
};


// uint32_t systick_current_value();
// uint32_t systick_time_since(uint32_t start);
// void systick_counter_start(systick_counter_t *counter);
// uint32_t systick_counter_elapsed(systick_counter_t *counter);
// void systick_counter_complete(systick_counter_t *counter);
// void systick_counter_delay(systick_counter_t *counter, uint32_t ticks);
// void systick_delay(uint32_t ticks);


#endif
