#include "ddl/core/core.h"
#include "ddl/timers/timers.h"
#include "hc32l110_system.h"

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
        Nvic::set_priority(irq, Nvic::default_priority);
        Nvic::enable(irq);
    }
    else
    {
        Nvic::disable(irq);
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
    Device::enable(peripheral_lptim);
}

LowPowerTimer::LowPowerTimer(hc32_lp_timer_register_t *t) : timer(t)
{
}
uint8_t LowPowerTimer::has_interrupt() { return this->timer->interrupt_flag > 0 ? 1 : 0; }
void LowPowerTimer::clear_interrupt() { this->timer->interrupt_clear = 0; }



LowPowerTimer timer_lptim(HC32_LPTIMER);


void IRQ17_Handler(void)
{
    timer_lptim.interrupt.invoke(irq_lp_timer);
    Nvic::clear(irq_lp_timer);
}