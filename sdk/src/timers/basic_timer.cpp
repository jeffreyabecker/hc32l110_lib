#include "hc32l110_ddl_core.h"

#include "hc32l110_registers.h"
#include "hc32l110_ddl_timer.h"

#define __basic_timer_index(timer) ((((uint32_t)timer) - TIMER_0_ADDRESS) / 0x20)
#define __basic_timer_irq(timer) (irq_t)(irq_timer_0 + __basic_timer_index(timer))

basic_timer_mode_t BasicTimer::mode() { return this->timer->control_flags.mode; }
void BasicTimer::mode(basic_timer_mode_t value) { this->timer->control_flags.mode = value; }

timer_function_t BasicTimer::function() { return this->timer->control_flags.clock_source; }
void BasicTimer::function(timer_function_t value) { this->timer->control_flags.clock_source = value; }

basic_timer_prescaler_t BasicTimer::prescaler() { return this->timer->control_flags.prescaler; }
void BasicTimer::prescaler(basic_timer_prescaler_t value) { this->timer->control_flags.prescaler = value; }

uint8_t BasicTimer::enable_inverted_output() { return this->timer->control_flags.toggle_enabled; }
void BasicTimer::enable_inverted_output(uint8_t value) { this->timer->control_flags.toggle_enabled = value; }

uint8_t BasicTimer::enable_gate() { return this->timer->control_flags.gate_enabled; }
void BasicTimer::enable_gate(uint8_t value) { this->timer->control_flags.gate_enabled = value; }

uint8_t BasicTimer::gate_polarity() { return this->timer->control_flags.gate_polarity; }
void BasicTimer::gate_polarity(uint8_t value) { this->timer->control_flags.gate_polarity = value; }

uint8_t BasicTimer::interrupt_enabled()
{
    return this->timer->control_flags.interrupt_enabled;
}
void BasicTimer::interrupt_enabled(uint8_t value)
{
    this->timer->control_flags.interrupt_enabled = value;
    irq_t irq = __basic_timer_irq(this->timer);
    if (value)
    {
        nvic_set_interrupt_priority(irq, nvic_default_irq_priority);
        nvic_enable_interrupt(irq);
    }
    else
    {
        nvic_disable_interrupt(irq);
    }
}
void BasicTimer::running(uint8_t enabled)
{
    this->timer->control_flags.timer_running = enabled;
}
uint8_t BasicTimer::running()
{
    return this->timer->control_flags.timer_running;
}
uint32_t BasicTimer::reload()
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
void BasicTimer::reload(uint32_t value)
{
    if (this->timer->control_flags.mode == basic_timer_mode_periodic)
    {
        this->timer->auto_reload = value;
    }
}

uint32_t BasicTimer::count()
{
    if (this->timer->control_flags.mode == basic_timer_mode_periodic)
    {
        return this->timer->count16;
    }
    else
    {
        return this->timer->count32;
    }
}
void BasicTimer::count(uint32_t value)
{
    if (this->timer->control_flags.mode == basic_timer_mode_periodic)
    {
        this->timer->count16 = value;
    }
    else
    {
        this->timer->count32 = value;
    }
}

void BasicTimer::enable_peripheral()
{
    peripheral_set_enabled((peripheral_t)(peripheral_get_enabled() | peripheral_basetim));
}
void BasicTimer::interrupt_handler(InterruptInvocationHandler<Timer> *h)
{
    this->handler = h;
}
void BasicTimer::invoke_interrupt(irq_t irq)
{
    if (this->handler != NULL)
    {
        this->handler->invoke(this, irq);
    }
}
BasicTimer::BasicTimer(hc32_basic_timer_register_t *t) : timer(t), handler(NULL)
{
}
uint8_t BasicTimer::has_interrupt() { return this->timer->interrupt_flag > 0 ? 1 : 0; }
void BasicTimer::clear_interrupt() { this->timer->interrupt_clear = 0; }


BasicTimer timer_tim0(HC32_TIMER0);
BasicTimer timer_tim1(HC32_TIMER1);
BasicTimer timer_tim2(HC32_TIMER2);

void IRQ14_Handler(void)
{
    timer_tim0.invoke_interrupt(irq_timer_0);
    nvic_clear_interrupt(irq_timer_0);
}
void IRQ15_Handler(void)
{
    timer_tim1.invoke_interrupt(irq_timer_1);
    nvic_clear_interrupt(irq_timer_1);
}
void IRQ16_Handler(void)
{
    timer_tim2.invoke_interrupt(irq_timer_2);
    nvic_clear_interrupt(irq_timer_2);
}