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
    virtual basic_timer_mode_t get_mode();
    virtual void set_mode(basic_timer_mode_t value);

    virtual timer_function_t get_function();
    virtual void set_function(timer_function_t value);

    virtual uint8_t get_enable_inverted_output();
    virtual void set_enable_inverted_output(uint8_t value);

    virtual uint8_t get_enable_gate();
    virtual void set_enable_gate(uint8_t value);

    virtual uint8_t get_gate_polarity();
    virtual void set_gate_polarity(uint8_t value);

    virtual uint8_t get_interrupt_enabled();
    virtual void set_interrupt_enabled(uint8_t value);

    virtual uint32_t get_reload();
    virtual void set_reload(uint32_t value);

    virtual uint32_t get_count();
    virtual void set_count(uint32_t value);

    virtual void set_running(uint8_t enabled);
    virtual uint8_t get_running();

    virtual uint8_t has_interrupt();
    virtual void clear_interrupt();

    virtual void set_interrupt_handler(InterruptInvocationHandler<Timer> *handler);
    virtual void invoke_interrupt(irq_t irq);
};

typedef struct
{
    basic_timer_mode_t mode : 1;
    timer_function_t function : 1;
    basic_timer_prescaler_t prescaler : 4;
    uint8_t enable_inverted_output : 1;
    uint8_t enable_gate : 1;
    uint8_t gate_polarity : 1;
    uint8_t interrupt_enabled : 1;
    uint32_t reload;
} basic_timer_config_t;

class BasicTimer : Timer
{
private:
    hc32_basic_timer_register_t *timer;
    InterruptInvocationHandler<Timer> *handler;

public:
    BasicTimer(hc32_basic_timer_register_t *t);

    static void enable();
    void configure(const basic_timer_config_t *cfg);

    virtual basic_timer_mode_t get_mode();
    virtual void set_mode(basic_timer_mode_t value);

    virtual timer_function_t get_function();
    virtual void set_function(timer_function_t value);

    virtual basic_timer_prescaler_t get_prescaler();
    virtual void set_prescaler(basic_timer_prescaler_t value);

    virtual uint8_t get_enable_inverted_output();
    virtual void set_enable_inverted_output(uint8_t value);

    virtual uint8_t get_enable_gate();
    virtual void set_enable_gate(uint8_t value);

    virtual uint8_t get_gate_polarity();
    virtual void set_gate_polarity(uint8_t value);

    virtual uint8_t get_interrupt_enabled();
    virtual void set_interrupt_enabled(uint8_t value);

    virtual uint32_t get_reload();
    virtual void set_reload(uint32_t value);

    virtual uint32_t get_count();
    virtual void set_count(uint32_t value);

    virtual void set_running(uint8_t enabled);
    virtual uint8_t get_running();

    virtual uint8_t has_interrupt();
    virtual void clear_interrupt();

    virtual void set_interrupt_handler(InterruptInvocationHandler<Timer> *handler);
    virtual void invoke_interrupt(irq_t irq);
};

class LowPowerTimer : Timer
{
private:
    hc32_lp_timer_register_t *timer;
    InterruptInvocationHandler<Timer> *handler;

public:
    LowPowerTimer(hc32_lp_timer_register_t *t);

    static void enable();
    void configure(const basic_timer_config_t *cfg);

    virtual basic_timer_mode_t get_mode();
    virtual void set_mode(basic_timer_mode_t value);

    virtual timer_function_t get_function();
    virtual void set_function(timer_function_t value);

    lp_timer_clock_source_t get_clock_source();
    void set_clock_source(lp_timer_clock_source_t value);

    virtual basic_timer_prescaler_t get_prescaler();
    virtual void set_prescaler(basic_timer_prescaler_t value);

    virtual uint8_t get_enable_inverted_output();
    virtual void set_enable_inverted_output(uint8_t value);

    virtual uint8_t get_enable_gate();
    virtual void set_enable_gate(uint8_t value);

    virtual uint8_t get_gate_polarity();
    virtual void set_gate_polarity(uint8_t value);

    virtual uint8_t get_interrupt_enabled();
    virtual void set_interrupt_enabled(uint8_t value);

    virtual uint32_t get_reload();
    virtual void set_reload(uint32_t value);

    virtual uint32_t get_count();
    virtual void set_count(uint32_t value);

    virtual void set_running(uint8_t enabled);
    virtual uint8_t get_running();

    virtual uint8_t has_interrupt();
    virtual void clear_interrupt();

    virtual void set_interrupt_handler(InterruptInvocationHandler<Timer> *handler);
    virtual void invoke_interrupt(irq_t irq);
};

extern BasicTimer timer_tim0;
extern BasicTimer timer_tim1;
extern BasicTimer timer_tim2;
extern LowPowerTimer timer_lptim;
#endif
