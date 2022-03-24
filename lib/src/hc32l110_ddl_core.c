#include "hc32l110_cmsis.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>
volatile static uint32_t delay_tick_count = 0ul;
volatile static uint32_t current_tick_count = 0ul;

uint32_t systick_current_value()
{
    return current_tick_count;
}
#define SYSTICK_RUNNING_MASK (SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk)
void systick_delay(uint32_t delay_ticks)
{
    if ((SysTick->CTRL & SYSTICK_RUNNING_MASK) == SYSTICK_RUNNING_MASK)
    {
        delay_tick_count = 0;

        while (delay_tick_count < delay_ticks)
        {
            __NOP();
        }
    }
}
__STATIC_FORCEINLINE void __core_clock_config_unlock(void)
{
    HC32_CLOCK->SYSCTRL2 = 0x5A5A;
    HC32_CLOCK->SYSCTRL2 = 0xA5A5;
}

#define sub_4mhz_scale_factor 8000
static uint32_t __clock_interpolate(uint32_t clock_frequency, uint32_t low_freqency, uint32_t high_frequency, uint32_t low_trim, uint32_t high_trim)
{
    return (low_trim + ((clock_frequency - low_freqency) * ((high_trim - low_trim) / (high_frequency - low_freqency)))) / 1000;
}
static uint16_t __core_calculate_rch_trim(uint32_t clock_frequency_hz)
{
    if (clock_frequency_hz < mhz4)
    {
        return CLOCK_TRIM_HIGH_4mhz - sub_4mhz_scale_factor * (mhz4 - clock_frequency_hz);
    }
    if (mhz4 <= clock_frequency_hz && clock_frequency_hz <= mhz24)
    {
        if (mhz4 == clock_frequency_hz)
        {
            return CLOCK_TRIM_HIGH_4mhz;
        }
        else if (clock_frequency_hz < mhz8)
        {
            return __clock_interpolate(clock_frequency_hz, mhz4, mhz8, CLOCK_TRIM_HIGH_4mhz, CLOCK_TRIM_HIGH_8mhz);
        }
        else if (clock_frequency_hz == mhz8)
        {
            return CLOCK_TRIM_HIGH_8mhz;
        }
        else if (clock_frequency_hz < mhz16)
        {
            return __clock_interpolate(clock_frequency_hz, mhz8, mhz16, CLOCK_TRIM_HIGH_8mhz, CLOCK_TRIM_HIGH_16mhz);
        }
        else if (clock_frequency_hz == mhz16)
        {
            return CLOCK_TRIM_HIGH_16mhz;
        }
        else if (clock_frequency_hz < mhz22_12)
        {
            return __clock_interpolate(clock_frequency_hz, mhz16, mhz22_12, CLOCK_TRIM_HIGH_16mhz, CLOCK_TRIM_HIGH_22_12mhz);
        }
        else if (clock_frequency_hz == mhz22_12)
        {
            return CLOCK_TRIM_HIGH_22_12mhz;
        }
        else if (clock_frequency_hz < mhz24)
        {
            return __clock_interpolate(clock_frequency_hz, mhz22_12, mhz24, CLOCK_TRIM_HIGH_22_12mhz, CLOCK_TRIM_HIGH_24mhz);
        }
        return CLOCK_TRIM_HIGH_22_12mhz;
    }
    return 0;
}
// this function interpolates the clock-trim value from known reference points
static uint16_t __core_calculate_rcl_trim(uint32_t clock_frequency_hz)
{
    if (khz32_8 == clock_frequency_hz)
    {
        return CLOCK_TRIM_LOW_32_8_khz;
    }
    if (khz38_4 == clock_frequency_hz)
    {
        return CLOCK_TRIM_LOW_38_4_khz;
    }
    if (khz32_8 < clock_frequency_hz && clock_frequency_hz < khz38_4)
    {
        return __clock_interpolate(clock_frequency_hz, khz32_8, khz38_4, CLOCK_TRIM_LOW_32_8_khz, CLOCK_TRIM_LOW_32_8_khz);
    }
    return 0;
}
static void update_clock_freq_global(uint32_t clock_frequency_hz, core_system_clock_divider_t system_clock_prescaler, core_peripheral_clock_divider_t peripheral_clock_prescaler)
{
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.HCLK_PRS = system_clock_prescaler;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.PCLK_PRS = peripheral_clock_prescaler;
    SystemCoreClock = clock_frequency_hz >> system_clock_prescaler;
    PeripheralCoreClock = SystemCoreClock >> peripheral_clock_prescaler;
}
static void core_set_system_clock_external_low(uint32_t clock_frequency_hz, core_system_clock_divider_t system_clock_prescaler, core_peripheral_clock_divider_t peripheral_clock_prescaler)
{
    HC32_GPIO_PORT0->ADS = 0x30;

    HC32_CLOCK->XTL_CR.STARTUP = 3;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTL_EN = 1;
    while (HC32_CLOCK->XTL_CR.STABLE != 1)
    {
    }
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.CLK_SW4_SEL = core_clock_source_external_low_speed;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCL_EN = 0;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCH_EN = 0;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void core_set_system_clock_external_high(uint32_t clock_frequency_hz, core_system_clock_divider_t system_clock_prescaler, core_peripheral_clock_divider_t peripheral_clock_prescaler)
{

    HC32_CLOCK->XTH_CR.STARTUP = 3;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTH_EN = 1;
    while (HC32_CLOCK->XTH_CR.STABLE != 1)
    {
    }
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.CLK_SW4_SEL = core_clock_source_external_high_speed;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCL_EN = 0;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCH_EN = 0;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTL_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void core_set_system_clock_internal_low(uint32_t clock_frequency_hz, core_system_clock_divider_t system_clock_prescaler, core_peripheral_clock_divider_t peripheral_clock_prescaler)
{
    uint16_t clock_trim = __core_calculate_rcl_trim(clock_frequency_hz);
    __core_clock_config_unlock();
    HC32_CLOCK->RCL_CR.TRIM = clock_trim;

    HC32_CLOCK->RCL_CR.STARTUP = 3;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCL_EN = 1;
    while (HC32_CLOCK->RCL_CR.STABLE != 1)
    {
    }
    HC32_CLOCK->SYSCTRL0.CLK_SW4_SEL = core_clock_source_internal_low_speed;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTL_EN = 0;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCH_EN = 0;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void core_set_system_clock_internal_high(uint32_t clock_frequency_hz, core_system_clock_divider_t system_clock_prescaler, core_peripheral_clock_divider_t peripheral_clock_prescaler)
{
    uint16_t clock_trim = __core_calculate_rch_trim(clock_frequency_hz);
    __core_clock_config_unlock();
    HC32_CLOCK->RCH_CR.TRIM = clock_trim;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCH_EN = 1;
    while (HC32_CLOCK->RCH_CR.STABLE != 1)
    {
    }
    HC32_CLOCK->SYSCTRL0.CLK_SW4_SEL = core_clock_source_internal_high_speed;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTL_EN = 0;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.RCL_EN = 0;
    __core_clock_config_unlock();
    HC32_CLOCK->SYSCTRL0.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
void core_set_system_clock(core_clock_source_t source, uint32_t clock_frequency_hz, core_system_clock_divider_t system_clock_prescaler, core_peripheral_clock_divider_t peripheral_clock_prescaler)
{
    switch (source)
    {
    case core_clock_source_internal_high_speed:
        core_set_system_clock_internal_high(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
        return;
    case core_clock_source_internal_low_speed:
        core_set_system_clock_internal_low(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
        return;
    case core_clock_source_external_high_speed:
        core_set_system_clock_external_high(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
        return;
    case core_clock_source_external_low_speed:
        core_set_system_clock_external_low(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
        return;
    default:
        break;
    }
}
void core_enable_systick(uint32_t systick_frequency_hz)
{

    if (systick_frequency_hz > 0)
    {
        peripheral_set_enabled(peripheral_get_enabled() | peripheral_systick);
        uint32_t ticks = (SystemCoreClock) / systick_frequency_hz;
        if ((ticks - 1UL) > MAX_SYSTICK_VALUE)
        {
            return;
        }
        SysTick_Config(ticks);
    }
    else
    {
        peripheral_set_enabled(peripheral_get_enabled() & ~peripheral_systick);
        SysTick->CTRL &= ~(SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
    }
}
void peripheral_set_enabled(peripheral_t peripheral) { HC32_CLOCK->peripheral_clock_enable = peripheral; }
peripheral_t peripheral_get_enabled() { return HC32_CLOCK->peripheral_clock_enable; }

void SysTick_Handler(void)
{
    delay_tick_count += 1;
    current_tick_count += 1;
}