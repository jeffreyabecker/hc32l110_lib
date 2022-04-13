#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_basic_timers.h"
#include "hc32l110_ddl_debug.h"

static basic_timer_handler_t __timer_handlers[3] = {NULL, NULL, NULL};

#define __basic_timer_get_index(timer) ((((uint32_t)timer) - TIMER_0_ADDRESS) / 0x20)
#define __basic_timer_get_irq(timer) (TIM0_IRQn + __basic_timer_get_index(timer))
void basic_timer_configure(hc32_basic_timer_register_t *timer, const basic_timer_config_t *cfg, const basic_timer_handler_t callback)
{
    uint32_t index = __basic_timer_get_index(timer);
    __timer_handlers[index] = cfg->interrupt_enabled ? callback : NULL;
    timer->control.mode = cfg->mode;
    timer->control.prescaler = cfg->prescaler;
    timer->control.tick_source = cfg->tick_source;
    timer->control.enable_inverted_output = cfg->enable_inverted_output;
    timer->control.enable_gate = cfg->enable_gate;
    timer->control.gate_polarity = cfg->gate_polarity;
    timer->control.interrupt_enabled = cfg->interrupt_enabled;
    timer->interrupt_clear = 0;
    if (cfg->mode == basic_timer_mode_one_shot)
    {
        timer->count_32 = cfg->reload;
    }
    else
    {
        timer->auto_reload = cfg->reload;
        timer->count_16 = cfg->reload;
    }
    nvic_configure_interrupt(__basic_timer_get_irq(timer), nvic_default_irq_priority, cfg->interrupt_enabled);
}

void basic_timer_set_running(hc32_basic_timer_register_t *timer, uint8_t enabled)
{
    timer->control.timer_running = enabled;
}

void TIM0_Handler(void)
{
    debug_print("timer0_interrupt\n");
    if (__timer_handlers[0] != NULL)
    {
        (*__timer_handlers[0])(HC32_TIMER0);
    }
    HC32_TIMER0->interrupt_clear = 0;
    nvic_clear_interrupt(TIM0_IRQn);
}
void TIM1_Handler(void)
{
    debug_print("timer1_interrupt\n");
    if (__timer_handlers[1] != NULL)
    {
        (*__timer_handlers[1])(HC32_TIMER1);
    }
    HC32_TIMER1->interrupt_clear = 0;
    nvic_clear_interrupt(TIM1_IRQn);
}
void TIM2_Handler(void)
{
    debug_print("timer1_interrupt\n");
    if (__timer_handlers[2] != NULL)
    {
        (*__timer_handlers[2])(HC32_TIMER2);
    }
    HC32_TIMER2->interrupt_clear = 0;
    nvic_clear_interrupt(TIM2_IRQn);
}
// void LpTimer_Handler(void)
// {
//     if (__timer_handlers[3] != NULL)
//     {
//         (*__timer_handlers[3])(HC32_LPTIMER);
//     }
//     HC32_LPTIMER->interrupt_clear = 0;
//     nvic_clear_interrupt(LPTIM_IRQn);
// }