#include "hc32l110_cmsis.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>

void peripheral_set_enabled(peripheral_t peripheral) { HC32_CLOCK->peripheral_clock_enable = peripheral; }
peripheral_t peripheral_get_enabled() { return HC32_CLOCK->peripheral_clock_enable; }
void nvic_configure_interrupt(IRQn_Type irq, uint8_t priority, uint8_t enabled)
{
    NVIC_ClearPendingIRQ(irq);
    NVIC_SetPriority(irq, priority);
    if (enabled)
    {
        NVIC_EnableIRQ(irq);
    }
    else
    {
        NVIC_DisableIRQ(irq);
    }
}

__STATIC_FORCEINLINE void __clock_config_unlock(void)
{
    HC32_CLOCK->SYSCTRL2 = 0x5A5A;
    HC32_CLOCK->SYSCTRL2 = 0xA5A5;
}

#define sub_4mhz_scale_factor 8000
static uint32_t __clock_interpolate(uint32_t clock_frequency, uint32_t low_freqency, uint32_t high_frequency, uint32_t low_trim, uint32_t high_trim)
{
    return (low_trim + ((clock_frequency - low_freqency) * ((high_trim - low_trim) / (high_frequency - low_freqency)))) / 1000;
}
static uint16_t __calculate_rch_trim(uint32_t clock_frequency_hz)
{
    if (clock_frequency_hz < MHz_4)
    {
        return CLOCK_TRIM_HIGH_4mhz - sub_4mhz_scale_factor * (MHz_4 - clock_frequency_hz);
    }
    if (MHz_4 <= clock_frequency_hz && clock_frequency_hz <= MHz_24)
    {
        if (MHz_4 == clock_frequency_hz)
        {
            return CLOCK_TRIM_HIGH_4mhz;
        }
        else if (clock_frequency_hz < MHz_8)
        {
            return __clock_interpolate(clock_frequency_hz, MHz_4, MHz_8, CLOCK_TRIM_HIGH_4mhz, CLOCK_TRIM_HIGH_8mhz);
        }
        else if (clock_frequency_hz == MHz_8)
        {
            return CLOCK_TRIM_HIGH_8mhz;
        }
        else if (clock_frequency_hz < MHz_16)
        {
            return __clock_interpolate(clock_frequency_hz, MHz_8, MHz_16, CLOCK_TRIM_HIGH_8mhz, CLOCK_TRIM_HIGH_16mhz);
        }
        else if (clock_frequency_hz == MHz_16)
        {
            return CLOCK_TRIM_HIGH_16mhz;
        }
        else if (clock_frequency_hz < MHz_22_12)
        {
            return __clock_interpolate(clock_frequency_hz, MHz_16, MHz_22_12, CLOCK_TRIM_HIGH_16mhz, CLOCK_TRIM_HIGH_22_12mhz);
        }
        else if (clock_frequency_hz == MHz_22_12)
        {
            return CLOCK_TRIM_HIGH_22_12mhz;
        }
        else if (clock_frequency_hz < MHz_24)
        {
            return __clock_interpolate(clock_frequency_hz, MHz_22_12, MHz_24, CLOCK_TRIM_HIGH_22_12mhz, CLOCK_TRIM_HIGH_24mhz);
        }
        return CLOCK_TRIM_HIGH_22_12mhz;
    }
    return 0;
}
// this function interpolates the clock-trim value from known reference points
static uint16_t __calculate_rcl_trim(uint32_t clock_frequency_hz)
{
    if (KHz_32_8 == clock_frequency_hz)
    {
        return CLOCK_TRIM_LOW_32_8_khz;
    }
    if (KHz_38_4 == clock_frequency_hz)
    {
        return CLOCK_TRIM_LOW_38_4_khz;
    }
    if (KHz_32_8 < clock_frequency_hz && clock_frequency_hz < KHz_38_4)
    {
        return __clock_interpolate(clock_frequency_hz, KHz_32_8, KHz_38_4, CLOCK_TRIM_LOW_32_8_khz, CLOCK_TRIM_LOW_32_8_khz);
    }
    return 0;
}
static void update_clock_freq_global(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.HCLK_PRS = system_clock_prescaler;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.PCLK_PRS = peripheral_clock_prescaler;
    SystemCoreClock = clock_frequency_hz >> system_clock_prescaler;
    PeripheralCoreClock = SystemCoreClock >> peripheral_clock_prescaler;
}
static void set_system_clock_external_low(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    HC32_GPIO_PORT0->ADS = 0x30;

    HC32_CLOCK->XTL_CR.STARTUP = 3;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTL_EN = 1;
    while (HC32_CLOCK->XTL_CR.STABLE != 1)
    {
    }
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.CLK_SW4_SEL = clock_sourceexternal_low_speed;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCH_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void set_system_clock_external_high(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{

    HC32_CLOCK->XTH_CR.STARTUP = 3;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTH_EN = 1;
    while (HC32_CLOCK->XTH_CR.STABLE != 1)
    {
    }
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.CLK_SW4_SEL = clock_sourceexternal_high_speed;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCH_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTL_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void set_system_clock_internal_low(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    uint16_t clock_trim = __calculate_rcl_trim(clock_frequency_hz);
    __clock_config_unlock();
    HC32_CLOCK->RCL_CR.TRIM = clock_trim;

    HC32_CLOCK->RCL_CR.STARTUP = 3;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCL_EN = 1;
    while (HC32_CLOCK->RCL_CR.STABLE != 1)
    {
    }
    HC32_CLOCK->SYSCTRL0.CLK_SW4_SEL = clock_sourceinternal_low_speed;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCH_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void set_system_clock_internal_high(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    uint16_t clock_trim = __calculate_rch_trim(clock_frequency_hz);
    __clock_config_unlock();
    HC32_CLOCK->RCH_CR.TRIM = clock_trim;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCH_EN = 1;
    while (HC32_CLOCK->RCH_CR.STABLE != 1)
    {
    }
    HC32_CLOCK->SYSCTRL0.CLK_SW4_SEL = clock_sourceinternal_high_speed;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
void set_system_clock(clock_sourcet source, uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    switch (source)
    {
    case clock_sourceinternal_high_speed:
        set_system_clock_internal_high(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
        return;
    case clock_sourceinternal_low_speed:
        set_system_clock_internal_low(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
        return;
    case clock_sourceexternal_high_speed:
        set_system_clock_external_high(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
        return;
    case clock_sourceexternal_low_speed:
        set_system_clock_external_low(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
        return;
    default:
        break;
    }
}
static void __systick_start()
{
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
static void __systick_stop()
{
    SysTick->CTRL &= ~(SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
}
void enable_systick(uint32_t systick_frequency_hz)
{

    if (systick_frequency_hz > 0)
    {
        peripheral_set_enabled(peripheral_get_enabled() | peripheral_systick);
        uint32_t ticks = (SystemCoreClock) / systick_frequency_hz;
        if ((ticks - 1UL) > MAX_SYSTICK_VALUE)
        {
            return;
        }
        SysTick->LOAD = (uint32_t)(ticks - 1UL); /* set reload register */
        SysTick->VAL = 0UL;
        nvic_enable_irq(SysTick_IRQn);
        __systick_start();
    }
    else
    {
        __systick_stop();
        peripheral_set_enabled(peripheral_get_enabled() & ~peripheral_systick);
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
void systick_delay(uint32_t ticks){
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