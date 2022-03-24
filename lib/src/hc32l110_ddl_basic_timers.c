#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_basic_timers.h"
typedef void (*basic_timer_handler_t)(const void *timer);
basic_timer_handler_t *__timer_handlers[4] = {NULL, NULL, NULL, NULL};

inline uint32_t __basic_timer_get_index(const void *timer)
{
    return ((((uint32_t)timer) - TIMER_0_ADDRESS) / 0x20);
}
inline IRQn_Type __basic_timer_get_irq(const void *timer)
{
    return TIM0_IRQn + __basic_timer_get_index(timer);
}
void basic_timer_configure(const void *timer, const basic_timer_config_t *cfg, const basic_timer_handler_t *callback)
{
    uint32_t index = __basic_timer_get_index(timer);
    __timer_handlers[index] = cfg->interrupt_enabled ? callback : NULL;
    if (((uint32_t)timer) == LPTIMER_ADDRESS)
    {

        HC32_LPTIMER_TypeDef *l = timer;
        l->control.mode = cfg->mode;
        l->control.low_power.clock_source = cfg->low_power_clock_source;
        l->control.tick_source = cfg->tick_source;
        l->control.enable_inverted_output = cfg->enable_inverted_output;
        l->control.enable_gate = cfg->enable_gate;
        l->control.gate_polarity = cfg->gate_polarity;
        l->control.interrupt_enabled = cfg->interrupt_enabled;
        (((HC32_BasicTimer_TypeDef *)timer)->interrupt_clear) = 0;
        if (cfg->mode == basic_timer_mode_one_shot)
        {
            l->count_16 = cfg->preload.oneshot;
        }
        else
        {
            l->auto_reload = cfg->preload.periodic.reload;
            l->count_16 = cfg->preload.periodic.preload;
        }
    }
    else
    {

        HC32_BasicTimer_TypeDef *t = timer;

        t->control.mode = cfg->mode;
        t->control.prescaler = cfg->prescaler;
        t->control.tick_source = cfg->tick_source;
        t->control.enable_inverted_output = cfg->enable_inverted_output;
        t->control.enable_gate = cfg->enable_gate;
        t->control.gate_polarity = cfg->gate_polarity;
        t->control.interrupt_enabled = cfg->interrupt_enabled;
        (((HC32_BasicTimer_TypeDef *)timer)->interrupt_clear) = 0;
        if (cfg->mode == basic_timer_mode_one_shot)
        {
            t->count_32 = cfg->preload.oneshot;
        }
        else
        {
            t->auto_reload = cfg->preload.periodic.reload;
            t->count_16 = cfg->preload.periodic.preload;
        }
    }
    if (cfg->interrupt_enabled)
    {
        NVIC_EnableIRQ(__basic_timer_get_irq(timer));
    }
    else
    {
        NVIC_DisableIRQ(__basic_timer_get_irq(timer));
    }
}
void basic_timer_interrupt_clear(const void *timer)
{
    if (((uint32_t)timer) == LPTIMER_ADDRESS)
    {
        (((HC32_LPTIMER_TypeDef *)timer)->interrupt_clear) = 0;
    }
    else
    {
        (((HC32_BasicTimer_TypeDef *)timer)->interrupt_clear) = 0;
    }
    NVIC_ClearPendingIRQ(__basic_timer_get_irq(timer));
}
uint8_t basic_timer_interrupt_get(const void *timer)
{
    if (((uint32_t)timer) == LPTIMER_ADDRESS)
    {
        return (((HC32_LPTIMER_TypeDef *)timer)->interrupt_flag);
    }
    else
    {
        return (((HC32_BasicTimer_TypeDef *)timer)->interrupt_flag);
    }
}
void basic_timer_set_running(const void *timer, uint8_t enabled)
{
    if (((uint32_t)timer) == LPTIMER_ADDRESS)
    {
        (((HC32_LPTIMER_TypeDef *)timer)->control).timer_running = enabled;
    }
    else
    {
        (((HC32_BasicTimer_TypeDef *)timer)->control).timer_running = enabled;
    }
}

void Timer0_Handler(void)
{
    if (__timer_handlers[0] != NULL)
    {
        (*__timer_handlers[0])(HC32_TIMER0);
    }
}
void Timer1_Handler(void)
{
    if (__timer_handlers[1] != NULL)
    {
        (*__timer_handlers[1])(HC32_TIMER1);
    }
}
void Timer2_Handler(void)
{
    if (__timer_handlers[2] != NULL)
    {
        (*__timer_handlers[2])(HC32_TIMER2);
    }
}
void LpTimer_Handler(void)
{
    if (__timer_handlers[3] != NULL)
    {
        (*__timer_handlers[3])(HC32_LPTIMER);
    }
}