#include "hc32l110_cmsis.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>
uint32_t SystemCoreClock;
uint32_t PeripheralCoreClock;

void peripheral_set_enabled(peripheral_t peripheral) { HC32_CLOCK->peripheral_clock_enable = peripheral; }
peripheral_t peripheral_get_enabled() { return HC32_CLOCK->peripheral_clock_enable; }
void nvic_clear_interrupt(IRQn_Type irq)
{
    NVIC_ClearPendingIRQ(irq);
}

void nvic_enable_interrupt(IRQn_Type irq)
{
    NVIC_EnableIRQ(irq);
}
void nvic_disable_interrupt(IRQn_Type irq)
{
    NVIC_DisableIRQ(irq);
}
void nvic_set_interrupt_priority(IRQn_Type irq, uint8_t priority){
    NVIC_SetPriority(irq, priority);
}

static void __systick_start()
{
    SysTick->CTRL = SYSTICK_RUNNING_MASK;
}
static void __systick_stop()
{
    SysTick->CTRL &= ~(SYSTICK_RUNNING_MASK);
}
void enable_systick(uint32_t systick_frequency_hz)
{

    if (systick_frequency_hz > 0)
    {
        peripheral_set_enabled(peripheral_get_enabled() | peripheral_tick);
        uint32_t ticks = (PeripheralCoreClock) / systick_frequency_hz;
        SysTick_Config(ticks);
        NVIC_SetPriority(SysTick_IRQn, nvic_default_irq_priority);
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
        __NOP();
    }
    systick_counter_complete(&counter);
}
void systick_counter_delay(systick_counter_t *counter, uint32_t ticks)
{
    systick_counter_start(counter);
    while (counter->count < ticks)
    {
        __NOP();
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