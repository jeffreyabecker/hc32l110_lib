#include "hc32l110_cmsis.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_ddl_clock_dynamic.h"
#include "hc32l110_system.h"
#include <stdint.h>



#define sub_4mhz_scale_factor 8000
__STATIC_FORCEINLINE void __clock_config_unlock(void)
{
    HC32_CLOCK->SYSCTRL2 = 0x5A5A;
    HC32_CLOCK->SYSCTRL2 = 0xA5A5;
}
static uint32_t __clock_interpolate(uint32_t clock_frequency, uint32_t low_freqency, uint32_t high_frequency, uint32_t low_trim, uint32_t high_trim)
{
    return (low_trim + ((clock_frequency - low_freqency) * ((high_trim - low_trim) / (high_frequency - low_freqency)))) / 1000;
}
static uint16_t __calculate_rch_trim(uint32_t clock_frequency_hz)
{
    if (clock_frequency_hz < MHz_4)
    {
        return CLOCK_TRIM_HIGH_4_mhz * 1000 - sub_4mhz_scale_factor * (MHz_4 - clock_frequency_hz);
    }
    if (MHz_4 <= clock_frequency_hz && clock_frequency_hz <= MHz_24)
    {
        if (MHz_4 == clock_frequency_hz)
        {
            return CLOCK_TRIM_HIGH_4_mhz * 1000;
        }
        else if (clock_frequency_hz < MHz_8)
        {
            return __clock_interpolate(clock_frequency_hz, MHz_4, MHz_8, CLOCK_TRIM_HIGH_4_mhz * 1000, CLOCK_TRIM_HIGH_8_mhz * 1000);
        }
        else if (clock_frequency_hz == MHz_8)
        {
            return CLOCK_TRIM_HIGH_8_mhz * 1000;
        }
        else if (clock_frequency_hz < MHz_16)
        {
            return __clock_interpolate(clock_frequency_hz, MHz_8, MHz_16, CLOCK_TRIM_HIGH_8_mhz * 1000, CLOCK_TRIM_HIGH_16_mhz * 1000);
        }
        else if (clock_frequency_hz == MHz_16)
        {
            return CLOCK_TRIM_HIGH_16_mhz * 1000;
        }
        else if (clock_frequency_hz < MHz_22_12)
        {
            return __clock_interpolate(clock_frequency_hz, MHz_16, MHz_22_12, CLOCK_TRIM_HIGH_16_mhz * 1000, CLOCK_TRIM_HIGH_22_12_mhz * 1000);
        }
        else if (clock_frequency_hz == MHz_22_12)
        {
            return CLOCK_TRIM_HIGH_22_12_mhz * 1000;
        }
        else if (clock_frequency_hz < MHz_24)
        {
            return __clock_interpolate(clock_frequency_hz, MHz_22_12, MHz_24, CLOCK_TRIM_HIGH_22_12_mhz * 1000, CLOCK_TRIM_HIGH_24_mhz * 1000);
        }
        return CLOCK_TRIM_HIGH_22_12_mhz * 1000;
    }
    return 0;
}
// this function interpolates the clock-trim value from known reference points
static uint16_t __calculate_rcl_trim(uint32_t clock_frequency_hz)
{
    if (KHz_32_8 == clock_frequency_hz)
    {
        return CLOCK_TRIM_LOW_32_8_khz * 1000;
    }
    if (KHz_38_4 == clock_frequency_hz)
    {
        return CLOCK_TRIM_LOW_38_4_khz * 1000;
    }
    if (KHz_32_8 < clock_frequency_hz && clock_frequency_hz < KHz_38_4)
    {
        return __clock_interpolate(clock_frequency_hz, KHz_32_8, KHz_38_4, CLOCK_TRIM_LOW_32_8_khz * 1000, CLOCK_TRIM_LOW_32_8_khz * 1000);
    }
    return 0;
}
static void update_clock_freq_global(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.HCLK_PRS = system_clock_prescaler;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.PCLK_PRS = peripheral_clock_prescaler;
    SystemCoreClock = clock_frequency_hz >> system_clock_prescaler;
    PeripheralCoreClock = SystemCoreClock >> peripheral_clock_prescaler;
}
static void set_system_clock_external_low(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    HC32_GPIO_PORT0->ADS = 0x30;

    HC32_CLOCK->XTL_CR.STARTUP = 3;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.XTL_EN = 1;
    while (HC32_CLOCK->XTL_CR.STABLE != 1)
    {
    }
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = clock_sourceexternal_low_speed;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.RCL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.RCH_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void set_system_clock_external_high(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{

    HC32_CLOCK->XTH_CR.STARTUP = 3;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.XTH_EN = 1;
    while (HC32_CLOCK->XTH_CR.STABLE != 1)
    {
    }
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = clock_sourceexternal_high_speed;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.RCL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.RCH_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void set_system_clock_internal_low(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    uint16_t clock_trim = __calculate_rcl_trim(clock_frequency_hz);

    HC32_CLOCK->RCL_CR.TRIM = clock_trim;
    HC32_CLOCK->RCL_CR.STARTUP = 3;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.RCL_EN = 1;
    while (HC32_CLOCK->RCL_CR.STABLE != 1)
    {
    }
    HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = clock_sourceinternal_low_speed;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.RCH_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
static void set_system_clock_internal_high(uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
{
    uint16_t clock_trim = __calculate_rch_trim(clock_frequency_hz);

    HC32_CLOCK->RCH_CR.TRIM = clock_trim;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.RCH_EN = 1;
    while (HC32_CLOCK->RCH_CR.STABLE != 1)
    {
    }
    HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = clock_sourceinternal_high_speed;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.RCL_EN = 0;
    __clock_config_unlock();
    HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
    update_clock_freq_global(clock_frequency_hz, system_clock_prescaler, peripheral_clock_prescaler);
}
void set_system_clock(clock_source_t source, uint32_t clock_frequency_hz, system_clock_divider_t system_clock_prescaler, peripheral_clock_divider_t peripheral_clock_prescaler)
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
