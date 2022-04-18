#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_basic_timers.h"
#include "hc32l110_ddl_debug.h"

static basic_timer_handler_t __timer_handlers[3] = {NULL, NULL, NULL};

#define __basic_timer_get_index(timer) ((((uint32_t)timer) - TIMER_0_ADDRESS) / 0x20)
#define __basic_timer_get_irq(timer) (irq_timer_0 + __basic_timer_get_index(timer))
void basic_timer_configure(hc32_basic_timer_register_t *timer, const basic_timer_config_t *cfg, const basic_timer_handler_t callback)
{
    uint32_t index = __basic_timer_get_index(timer);
    __timer_handlers[index] = cfg->interrupt_enabled ? callback : NULL;

    timer->control_flags.mode = cfg->mode;
    timer->control_flags.prescaler = cfg->prescaler;
    timer->control_flags.clock_source = cfg->tick_source;
    timer->control_flags.toggle_enabled = cfg->enable_inverted_output;
    timer->control_flags.gate_enabled = cfg->enable_gate;
    timer->control_flags.gate_polarity = cfg->gate_polarity;
    timer->control_flags.interrupt_enabled = cfg->interrupt_enabled;
    timer->interrupt_clear = 0;
    if (cfg->mode == basic_timer_mode_one_shot)
    {
        timer->count32 = cfg->reload;
    }
    else
    {
        timer->auto_reload = cfg->reload;
        timer->count16 = cfg->reload;
    }
    irq_t irq = __basic_timer_get_irq(timer);
    if(cfg->interrupt_enabled){
        nvic_set_interrupt_priority(irq, nvic_default_irq_priority);
        nvic_enable_interrupt(irq);
    }
    else{
        nvic_disable_interrupt(irq);
    }
    
}

void basic_timer_set_running(hc32_basic_timer_register_t *timer, uint8_t enabled)
{
    timer->control_flags.timer_running = enabled;
}

void IRQ14_Handler (void)
{
    if (__timer_handlers[0] != NULL)
    {
        (*__timer_handlers[0])(HC32_TIMER0);
    }
    HC32_TIMER0->interrupt_clear = 0;
    nvic_clear_interrupt(irq_timer_0);
}
void IRQ15_Handler (void)
{
    if (__timer_handlers[1] != NULL)
    {
        (*__timer_handlers[1])(HC32_TIMER1);
    }
    HC32_TIMER1->interrupt_clear = 0;
    nvic_clear_interrupt(irq_timer_1);
}
void IRQ16_Handler (void)
{
    if (__timer_handlers[2] != NULL)
    {
        (*__timer_handlers[2])(HC32_TIMER2);
    }
    HC32_TIMER2->interrupt_clear = 0;
    nvic_clear_interrupt(irq_timer_2);
}
// void LpTimer_Handler(void)
// {
//     if (__timer_handlers[3] != NULL)
//     {
//         (*__timer_handlers[3])(HC32_LPTIMER);
//     }
//     HC32_LPTIMER->interrupt_clear = 0;
//     nvic_clear_interrupt(irq_lp_timer);
// }