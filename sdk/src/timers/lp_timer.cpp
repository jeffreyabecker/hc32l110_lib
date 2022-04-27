#include "hc32l110_ddl_timer.h"
#include "hc32l110_registers.h"
#include "hc32l110_ddl_core.h"

#define __basic_timer_index(timer) ((((uint32_t)timer) - TIMER_0_ADDRESS) / 0x20)
#define __basic_timer_irq(timer) (irq_t)(irq_timer_0 + __basic_timer_index(timer))

basic_timer_mode_t LowPowerTimer::mode() { return this->timer->control_flags.mode; }
void LowPowerTimer::mode(basic_timer_mode_t value) { this->timer->control_flags.mode = value; }

timer_function_t LowPowerTimer::function() { return this->timer->control_flags.clock_source; }
void LowPowerTimer::function(timer_function_t value) { this->timer->control_flags.clock_source = value; }

uint8_t LowPowerTimer::enable_inverted_output() { return this->timer->control_flags.toggle_enabled; }
void LowPowerTimer::enable_inverted_output(uint8_t value) { this->timer->control_flags.toggle_enabled = value; }

uint8_t LowPowerTimer::enable_gate() { return this->timer->control_flags.gate_enabled; }
void LowPowerTimer::enable_gate(uint8_t value) { this->timer->control_flags.gate_enabled = value; }

uint8_t LowPowerTimer::gate_polarity() { return this->timer->control_flags.gate_polarity; }
void LowPowerTimer::gate_polarity(uint8_t value) { this->timer->control_flags.gate_polarity = value; }

uint8_t LowPowerTimer::interrupt_enabled()
{
    return this->timer->control_flags.interrupt_enabled;
}
void LowPowerTimer::interrupt_enabled(uint8_t value)
{
    this->timer->control_flags.interrupt_enabled = value;
    irq_t irq = __basic_timer_irq(this->timer);
    if (value)
    {
        nvic_interrupt_priority(irq, nvic_default_irq_priority);
        nvic_enable_interrupt(irq);
    }
    else
    {
        nvic_disable_interrupt(irq);
    }
}
void LowPowerTimer::running(uint8_t enabled)
{
    this->timer->control_flags.timer_running = enabled;
}
uint8_t LowPowerTimer::running()
{
    return this->timer->control_flags.timer_running;
}
uint32_t LowPowerTimer::reload()
{
    if (this->timer->control_flags.mode == basic_timer_mode_periodic)
    {
        return this->timer->auto_reload;
    }
    else
    {
        return 0;
    }
}
void LowPowerTimer::reload(uint32_t value)
{
    if (this->timer->control_flags.mode == basic_timer_mode_periodic)
    {
        while (this->timer->control_flags.write_allowed == 0)
        {
            __nop();
        }
        this->timer->auto_reload = value;
    }
}

uint32_t LowPowerTimer::count()
{
    return this->timer->count16;
}
void LowPowerTimer::count(uint32_t value)
{
    this->timer->count16 = value;
}

void LowPowerTimer::enable_peripheral()
{
    peripheral_enabled((peripheral_t)(peripheral_enabled() | peripheral_lptim));
}
void LowPowerTimer::interrupt_handler(InterruptInvocationHandler<Timer> *h)
{
    this->handler = h;
}
void LowPowerTimer::invoke_interrupt(irq_t irq)
{
    if (this->handler != NULL)
    {
        this->handler->invoke(this, irq);
    }
}
LowPowerTimer::LowPowerTimer(hc32_lp_timer_register_t *t) : timer(t), handler(NULL)
{
}
uint8_t LowPowerTimer::has_interrupt() { return this->timer->interrupt_flag > 0 ? 1 : 0; }
void LowPowerTimer::clear_interrupt() { this->timer->interrupt_clear = 0; }

void LowPowerTimer::configure(const basic_timer_config_t *cfg)
{
    this->mode(cfg->mode);

    this->function(cfg->function);
    this->enable_inverted_output(cfg->enable_inverted_output);
    this->enable_gate(cfg->enable_gate);
    this->gate_polarity(cfg->gate_polarity);
    this->reload(cfg->reload);
    this->count(cfg->reload);
    this->clear_interrupt();
    this->interrupt_enabled(cfg->interrupt_enabled);
}

LowPowerTimer timer_lptim(HC32_LPTIMER);


void IRQ17_Handler(void)
{
    timer_lptim.invoke_interrupt(irq_lp_timer);
    nvic_clear_interrupt(irq_lp_timer);
}