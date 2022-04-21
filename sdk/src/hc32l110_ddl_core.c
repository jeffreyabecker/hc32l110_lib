#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_system.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>
uint32_t SystemCoreClock;
uint32_t PeripheralCoreClock;

__attribute__((always_inline)) static inline void __clock_config_unlock(void)
{
    HC32_CLOCK->SYSCTRL2 = 0x5A5A;
    HC32_CLOCK->SYSCTRL2 = 0xA5A5;
}
void clock_set_freq(uint32_t freqency_hz, uint16_t clock_trim)
{
    if (SystemCoreClock > KHz_38_4 && freqency_hz > KHz_38_4)
    {
        HC32_CLOCK->RCH_CR.TRIM = clock_trim;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock > KHz_38_4 && freqency_hz <= KHz_38_4)
    {
        // switching from RCH to RCL
        HC32_CLOCK->RCL_CR.TRIM = clock_trim;
        HC32_CLOCK->RCL_CR.STARTUP = 3;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCL_EN = 1;
        while (HC32_CLOCK->RCL_CR.STABLE != 1)
        {
        }
        HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = 2;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCH_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock <= KHz_38_4 && freqency_hz <= KHz_38_4)
    {
        HC32_CLOCK->RCL_CR.TRIM = clock_trim;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock <= KHz_38_4 && freqency_hz > KHz_38_4)
    {
        // switching from RCL to RCH
        HC32_CLOCK->RCH_CR.TRIM = clock_trim;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCH_EN = 1;
        while (HC32_CLOCK->RCH_CR.STABLE != 1)
        {
        }
        HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
}
void peripheral_set_enabled(peripheral_t peripheral) { HC32_CLOCK->peripheral_clock_enable = peripheral; }
peripheral_t peripheral_get_enabled() { return HC32_CLOCK->peripheral_clock_enable; }
void nvic_clear_interrupt(irq_t irq)
{
    if ((int32_t)(irq) >= 0)
    {
        HC32_NVIC->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL));
    }
}

void nvic_enable_interrupt(irq_t irq)
{
    if ((int32_t)(irq) >= 0)
    {
        __asm volatile("" ::
                           : "memory");
        HC32_NVIC->ISER[0U] = (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL));
        __asm volatile("" ::
                           : "memory");
    }
}
void nvic_disable_interrupt(irq_t irq)
{
    if ((int32_t)(irq) >= 0)
    {
        HC32_NVIC->ICER[0U] = (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL));
        data_barrier();
        instruction_barrier();
    }
}
uint8_t nvic_interrupt_enabled(irq_t irq)
{
    if ((int32_t)(irq) >= 0)
    {
        return ((uint32_t)(((HC32_NVIC->ISER[(((uint32_t)irq) >> 5UL)] & (1UL << (((uint32_t)irq) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
    }
    else
    {
        return (0U);
    }
}

#define _BIT_SHIFT(IRQn) (((((uint32_t)(int32_t)(IRQn))) & 0x03UL) * 8UL)
#define _SHP_IDX(IRQn) ((((((uint32_t)(int32_t)(IRQn)) & 0x0FUL) - 8UL) >> 2UL))
#define _IP_IDX(IRQn) ((((uint32_t)(int32_t)(IRQn)) >> 2UL))

void nvic_set_interrupt_priority(irq_t irq, uint8_t priority)
{
    if ((int32_t)(irq) >= 0)
    {
        HC32_NVIC->IP[_IP_IDX(irq)] = ((uint32_t)(HC32_NVIC->IP[_IP_IDX(irq)] & ~(0xFFUL << _BIT_SHIFT(irq))) |
                                       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << _BIT_SHIFT(irq)));
    }
    else
    {
        HC32_CONTROL_BLOCK->SHP[_SHP_IDX(irq)] = ((uint32_t)(HC32_CONTROL_BLOCK->SHP[_SHP_IDX(irq)] & ~(0xFFUL << _BIT_SHIFT(irq))) |
                                                  (((priority << (8U - 2)) & (uint32_t)0xFFUL) << _BIT_SHIFT(irq)));
    }
}

static void __systick_start()
{
    HC32_SYSTICK->CTRL = SYSTICK_RUNNING_MASK;
}
static void __systick_stop()
{
    HC32_SYSTICK->CTRL &= ~(SYSTICK_RUNNING_MASK);
}
void enable_systick(uint32_t systick_frequency_hz)
{

    if (systick_frequency_hz > 0)
    {
        peripheral_set_enabled(peripheral_get_enabled() | peripheral_tick);
        uint32_t ticks = (PeripheralCoreClock) / systick_frequency_hz;

        HC32_SYSTICK->LOAD = (uint32_t)(ticks - 1UL); /* set reload register */
        nvic_set_interrupt_priority(irq_sys_tick, nvic_default_irq_priority);
        HC32_SYSTICK->VAL = 0UL; /* Load the SysTick Counter Value */
        __systick_start();
    }
    else
    {
        __systick_stop();
        peripheral_set_enabled(peripheral_get_enabled() & ~peripheral_tick);
    }
}

static systick_counter_t counter_list_head;
uint32_t systick_time_since(uint32_t start)
{
    if (!systick_is_running())
    {
        return 0;
    }
    uint32_t now = counter_list_head.count;
    if (now < start)
    {
        return now + (0xFFFFFFFF - start);
    }
    else
    {
        return now - start;
    }
}
uint32_t systick_current_value()
{
    return counter_list_head.count;
}
void systick_counter_start(systick_counter_t *counter)
{
    if (counter == &counter_list_head)
    {
        return;
    }
    counter->count = 0;
    counter->next = NULL;
    systick_counter_t *last = &counter_list_head;
    __systick_stop();
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = counter;
    __systick_start();
}
uint32_t systick_counter_elapsed(systick_counter_t *counter)
{
    return counter->count;
}
void systick_counter_complete(systick_counter_t *counter)
{
    if (counter == &counter_list_head)
    {
        return;
    }
    systick_counter_t *last = &counter_list_head;
    __systick_stop();
    while (last->next != counter)
    {
        last = last->next;
    }
    last->next = counter->next;
    counter->next = NULL;
    counter->count = 0;
    __systick_start();
}
void systick_delay(uint32_t ticks)
{
    systick_counter_t counter;
    systick_counter_start(&counter);
    while (counter.count < ticks)
    {
        __nop();
    }
    systick_counter_complete(&counter);
}
void systick_counter_delay(systick_counter_t *counter, uint32_t ticks)
{
    systick_counter_start(counter);
    while (counter->count < ticks)
    {
        __nop();
    }
    systick_counter_complete(counter);
}

void SysTick_Handler(void)
{
    systick_counter_t *last = &counter_list_head;
    while (last != NULL)
    {
        last->count++;
        last = last->next;
    }
}