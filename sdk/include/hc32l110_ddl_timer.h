#ifndef __HC32L110_DDL_TIMER_H__
#define __HC32L110_DDL_TIMER_H__

#include <stdint.h>
#include <stddef.h>
#include "hc32l110_registers.h"
#include "hc32l110_system.h"
#include "hc32l110_ddl_core.h"

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



class BasicTimer : public Timer
{
private:
    hc32_basic_timer_register_t *timer;

public:
    BasicTimer(hc32_basic_timer_register_t *t);

    static void enable_peripheral();

    basic_timer_mode_t mode() ;
    void mode(basic_timer_mode_t value) ;

    timer_function_t function() ;
    void function(timer_function_t value);

    basic_timer_prescaler_t prescaler() ;
    void prescaler(basic_timer_prescaler_t value) ;

    uint8_t enable_inverted_output();
    void enable_inverted_output(uint8_t value);

    uint8_t enable_gate();
    void enable_gate(uint8_t value) ;

    uint8_t gate_polarity() ;
    void gate_polarity(uint8_t value) ;

    uint8_t interrupt_enabled() ;
    void interrupt_enabled(uint8_t value);

    uint32_t reload();
    void reload(uint32_t value);

    virtual uint32_t count() override;
    virtual void count(uint32_t value) override;

    virtual void running(uint8_t enabled) override;
    virtual uint8_t running() override;

    virtual uint8_t has_interrupt() override;
    virtual void clear_interrupt() override;

};

class LowPowerTimer : public Timer
{
private:
    hc32_lp_timer_register_t *timer;

public:
    LowPowerTimer(hc32_lp_timer_register_t *t);

    static void enable_peripheral();
    basic_timer_mode_t mode();
    void mode(basic_timer_mode_t value);

    timer_function_t function();
    void function(timer_function_t value);

    lp_timer_clock_source_t clock_source();
    void clock_source(lp_timer_clock_source_t value);

    uint8_t enable_inverted_output();
    void enable_inverted_output(uint8_t value);

    uint8_t enable_gate();
    void enable_gate(uint8_t value);

    uint8_t gate_polarity();
    void gate_polarity(uint8_t value);

    uint8_t interrupt_enabled();
    void interrupt_enabled(uint8_t value);

    uint32_t reload();
    void reload(uint32_t value);

    virtual uint32_t count() override;
    virtual void count(uint32_t value) override;

    virtual void running(uint8_t enabled) override;
    virtual uint8_t running() override;

    virtual uint8_t has_interrupt() override;
    virtual void clear_interrupt() override;

};

extern BasicTimer timer_tim0;
extern BasicTimer timer_tim1;
extern BasicTimer timer_tim2;
extern LowPowerTimer timer_lptim;

class TimerCounter : InterruptHandler{
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


// uint32_t systick_current_value();
// uint32_t systick_time_since(uint32_t start);
// void systick_counter_start(systick_counter_t *counter);
// uint32_t systick_counter_elapsed(systick_counter_t *counter);
// void systick_counter_complete(systick_counter_t *counter);
// void systick_counter_delay(systick_counter_t *counter, uint32_t ticks);
// void systick_delay(uint32_t ticks);


#endif
