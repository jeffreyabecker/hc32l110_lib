
#include "hc32l110_core.h"
#include "hc32l110_system.h"
#include "hc32l110_basic_timers.h"

__INLINE IRQn_Type basic_timer_get_irq(void *timer)
{
    return irq_timer_0 + ((((uint32_t)timer) - TIMER_0_ADDRESS) / 24);
}
void basic_timer_set_interrupt_enabled(void *timer, uint8_t enabled)
{
    if (enabled)
    {
        NVIC_EnableIRQ(basic_timer_get_irq(timer));
    }
    else
    {
        NVIC_DisableIRQ(basic_timer_get_irq(timer));
    }
    if (((uint32_t)timer) == LPTIMER_ADDRESS)
    {
        ((M0P_LPTIMER_TypeDef *)timer)->control.interrupt_enabled = enabled;
    }
    else
    {
        ((M0P_BasicTimer_TypeDef *)timer)->control.interrupt_enabled = enabled;
    }
}
uint8_t basic_timer_get_interrupt_enabled(void *timer)
{
    uint8_t nvic_enabled = NVIC_GetEnableIRQ(basic_timer_get_irq(timer));
    if (((uint32_t)timer) == LPTIMER_ADDRESS)
    {
        return ((M0P_LPTIMER_TypeDef *)timer)->control.interrupt_enabled + nvic_enabled > 0 ? 1 : 0;
    }
    else
    {
        return ((M0P_BasicTimer_TypeDef *)timer)->control.interrupt_enabled + nvic_enabled > 0 ? 1 : 0;
    }
}
void basic_timer_set_config(void *timer, stc_basic_timer_cr_field_t value)
{

    if (value.interrupt_enabled)
    {
        NVIC_EnableIRQ(basic_timer_get_irq(timer));
    }
    else
    {
        NVIC_DisableIRQ(basic_timer_get_irq(timer));
    }

    if (((uint32_t)timer) == LPTIMER_ADDRESS)
    {
        ((M0P_LPTIMER_TypeDef *)timer)->control = value;
    }
    else
    {
        ((M0P_BasicTimer_TypeDef *)timer)->control = value;
    }
}
