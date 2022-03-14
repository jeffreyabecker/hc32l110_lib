#include "hc32l110_core.h"
#include "hc32l110_system.h"

static uint32_t tick_increment_step = 0ul;
__IO static uint32_t current_tick_count = 0ul;

#define clock_trim_high_24mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C00ul))) * 1000)
#define clock_trim_high_22_12mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C02ul))) * 1000)
#define clock_trim_high_16mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C04ul))) * 1000)
#define clock_trim_high_8mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C06ul))) * 1000)
#define clock_trim_high_4mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C08ul))) * 1000)

#define clock_trim_low_38_4_khz ((uint32_t)(*((volatile uint16_t *)(0x00100C20ul))) * 1000)
#define clock_trim_low_32_8_khz ((uint32_t)(*((volatile uint16_t *)(0x00100C22ul))) * 1000)
#define khz32_8 32800
#define khz38_4 38400
#define mhz4 4000000
#define mhz8 8000000
#define mhz16 16000000
#define mhz22_12 22120000
#define mhz24 24000000
__STATIC_FORCEINLINE uint32_t __clock_interpolate(uint32_t clock_frequency, uint32_t low_freqency, uint32_t high_frequency, uint32_t low_trim, uint32_t high_trim)
{
    return (low_trim + ((clock_frequency - low_freqency) * ((high_trim - low_trim) / (high_frequency - low_freqency)))) / 1000;
}
__STATIC_FORCEINLINE void __core_clock_config_unlock(void)
{
    M0P_CLOCK->SYSCTRL2 = 0x5A5A;
    M0P_CLOCK->SYSCTRL2 = 0xA5A5;
}

uint16_t __core_calculate_clock_trim(core_system_config_t config)
{
    if (config.clock_source == core_clock_source_internal_high_speed)
    {
        if (mhz4 <= config.clock_frequency_hz && config.clock_frequency_hz <= mhz24)
        {
            if (mhz4 == config.clock_frequency_hz)
            {
                return clock_trim_high_4mhz;
            }
            else if (config.clock_frequency_hz < mhz8)
            {
                return __clock_interpolate(config.clock_frequency_hz, mhz4, mhz8, clock_trim_high_4mhz, clock_trim_high_8mhz);
            }
            else if (config.clock_frequency_hz == mhz8)
            {
                return clock_trim_high_8mhz;
            }
            else if (config.clock_frequency_hz < mhz16)
            {
                return __clock_interpolate(config.clock_frequency_hz, mhz8, mhz16, clock_trim_high_8mhz, clock_trim_high_16mhz);
            }
            else if (config.clock_frequency_hz == mhz16)
            {
                return clock_trim_high_16mhz;
            }
            else if (config.clock_frequency_hz < mhz22_12)
            {
                return __clock_interpolate(config.clock_frequency_hz, mhz16, mhz22_12, clock_trim_high_16mhz, clock_trim_high_22_12mhz);
            }
            else if (config.clock_frequency_hz == mhz22_12)
            {
                return clock_trim_high_22_12mhz;
            }
            else if (config.clock_frequency_hz < mhz24)
            {
                return __clock_interpolate(config.clock_frequency_hz, mhz22_12, mhz24, clock_trim_high_22_12mhz, clock_trim_high_24mhz);
            }
            return clock_trim_high_22_12mhz;
        }
    }
    else if (config.clock_source == core_clock_source_internal_low_speed)
    {
        if (khz32_8 == config.clock_frequency_hz)
        {
            return clock_trim_low_32_8_khz;
        }
        if (khz38_4 == config.clock_frequency_hz)
        {
            return clock_trim_low_38_4_khz;
        }
        if (khz32_8 < config.clock_frequency_hz && config.clock_frequency_hz < khz38_4)
        {
            return __clock_interpolate(config.clock_frequency_hz, khz32_8, khz38_4, clock_trim_low_32_8_khz, clock_trim_low_32_8_khz);
        }
    }
    return 0;
}

void core_system_clock_config(core_system_config_t config)
{
    uint16_t clock_trim = __core_calculate_clock_trim(config);
    if (M0P_CLOCK->SYSCTRL0.CLK_SW4_SEL != config.clock_source)
    {
        if (config.clock_source == core_clock_source_external_low_speed)
        {
            M0P_GPIO->P1ADS.P14 = gpio_analog;
            M0P_GPIO->P1ADS.P15 = gpio_analog;
            __core_clock_config_unlock();
            M0P_CLOCK->XTL_CR.STARTUP = 3;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.XTL_EN = 1;
            while (M0P_CLOCK->XTL_CR.STABLE != 1)
            {
            }
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.CLK_SW4_SEL = config.clock_source;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.RCL_EN = 0;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.RCH_EN = 0;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.XTH_EN = 0;
        }
        if (config.clock_source == core_clock_source_external_high_speed)
        {
            __core_clock_config_unlock();
            M0P_CLOCK->XTH_CR.STARTUP = 3;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.XTH_EN = 1;
            while (M0P_CLOCK->XTH_CR.STABLE != 1)
            {
            }
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.CLK_SW4_SEL = config.clock_source;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.RCL_EN = 0;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.RCH_EN = 0;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.XTL_EN = 0;
        }
        if (config.clock_source == core_clock_source_internal_low_speed)
        {
            __core_clock_config_unlock();
            M0P_CLOCK->RCL_CR.TRIM = clock_trim;
            __core_clock_config_unlock();
            M0P_CLOCK->RCL_CR.STARTUP = 3;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.RCL_EN = 1;
            while (M0P_CLOCK->RCL_CR.STABLE != 1)
            {
            }
            M0P_CLOCK->SYSCTRL0.CLK_SW4_SEL = config.clock_source;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.XTL_EN = 0;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.RCH_EN = 0;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.XTH_EN = 0;
        }
        if (config.clock_source == core_clock_source_internal_high_speed)
        {
            __core_clock_config_unlock();
            M0P_CLOCK->RCH_CR.TRIM = clock_trim;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.RCH_EN = 1;
            while (M0P_CLOCK->RCH_CR.STABLE != 1)
            {
            }
            M0P_CLOCK->SYSCTRL0.CLK_SW4_SEL = config.clock_source;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.XTL_EN = 0;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.RCL_EN = 0;
            __core_clock_config_unlock();
            M0P_CLOCK->SYSCTRL0.XTH_EN = 0;
        }
    }
    if (M0P_CLOCK->SYSCTRL0.RCH_EN && clock_trim != M0P_CLOCK->RCH_CR.TRIM)
    {
        __core_clock_config_unlock();
        M0P_CLOCK->RCH_CR.TRIM = clock_trim;
    }
    if (M0P_CLOCK->SYSCTRL0.RCL_EN && clock_trim != M0P_CLOCK->RCL_CR.TRIM)
    {
        __core_clock_config_unlock();
        M0P_CLOCK->RCL_CR.TRIM = clock_trim;
    }
    __core_clock_config_unlock();
    M0P_CLOCK->SYSCTRL0.HCLK_PRS = config.system_clock_prescaler;
    __core_clock_config_unlock();
    M0P_CLOCK->SYSCTRL0.PCLK_PRS = config.peripheral_clock_prescaler;

    SystemCoreClock = config.clock_frequency_hz / (0x01 << config.system_clock_prescaler);
    PeripheralCoreClock = SystemCoreClock / (0x01 << config.peripheral_clock_prescaler);
    if (config.enable_systick)
    {
        peripheral_set_enabled(peripheral_get_enabled() | peripheral_systick);
        SysTick_Config(PeripheralCoreClock / config.systick_frequency_hz);
        core_systick_enable();
    }
}

/**
 * @brief This function provides minimum delay in ticks.
 * @param [in] delay_ticks Delay specifies the delay time.
 * @retval None
 */
void core_systick_delay(uint32_t delay_ticks)
{
    const uint32_t tick_start = systick_get_tick();
    uint32_t tick_end;
    uint32_t tickMax;

    if (tick_increment_step != 0ul)
    {
        tickMax = (0xFFFFFFFFul / tick_increment_step) * tick_increment_step;
        /* Add a freq to guarantee minimum wait */
        if ((delay_ticks >= tickMax) || ((tickMax - delay_ticks) < tick_increment_step))
        {
            tick_end = tickMax;
        }
        else
        {
            tick_end = delay_ticks + tick_increment_step;
        }

        while ((systick_get_tick() - tick_start) < tick_end)
        {
        }
    }
}

/**
 * @brief This function is called to increment a global variable "u32TickCount".
 * @note  This variable is incremented in SysTick ISR.
 * @param None
 * @retval None
 */
void core_systick_increment_ticks(void)
{
    current_tick_count += tick_increment_step;
}

/**
 * @brief Provides a tick value
 * @param None
 * @retval Tick value
 */
uint32_t core_systick_get_tick(void)
{
    return current_tick_count;
}

/**
 * @brief Suspend SysTick increment.
 * @param None
 * @retval None
 */
void core_systick_disable(void)
{
    /* Disable SysTick Interrupt */
    CLEAR_REG32_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Pos);
}

/**
 * @brief Resume SysTick increment.
 * @param None
 * @retval None
 */
void core_systick_enable(void)
{
    SET_REG32_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Pos);
}
void core_ports_set_function(port_number_t port, uint8_t function)
{
    switch (port)
    {
    case port_p01:
        M0P_GPIO->P01_SEL = function;
        return;
    case port_p02:
        M0P_GPIO->P02_SEL = function;
        return;
    case port_p03:
        M0P_GPIO->P03_SEL = function;
        return;
    case port_p14:
        M0P_GPIO->P14_SEL = function;
        return;
    case port_p15:
        M0P_GPIO->P15_SEL = function;
        return;
    case port_p23:
        M0P_GPIO->P23_SEL = function;
        return;
    case port_p24:
        M0P_GPIO->P24_SEL = function;
        return;
    case port_p25:
        M0P_GPIO->P25_SEL = function;
        return;
    case port_p26:
        M0P_GPIO->P26_SEL = function;
        return;
    case port_p27:
        M0P_GPIO->P27_SEL = function;
        return;
    case port_p31:
        M0P_GPIO->P31_SEL = function;
        return;
    case port_p32:
        M0P_GPIO->P32_SEL = function;
        return;
    case port_p33:
        M0P_GPIO->P33_SEL = function;
        return;
    case port_p34:
        M0P_GPIO->P34_SEL = function;
        return;
    case port_p35:
        M0P_GPIO->P35_SEL = function;
        return;
    case port_p36:
        M0P_GPIO->P36_SEL = function;
        return;
    default:
        break;
    }
}

uint8_t core_ports_get_function(port_number_t port)
{
    switch (port)
    {
    case port_p01:
        return M0P_GPIO->P01_SEL;
    case port_p02:
        return M0P_GPIO->P02_SEL;
    case port_p03:
        return M0P_GPIO->P03_SEL;
    case port_p14:
        return M0P_GPIO->P14_SEL;
    case port_p15:
        return M0P_GPIO->P15_SEL;
    case port_p23:
        return M0P_GPIO->P23_SEL;
    case port_p24:
        return M0P_GPIO->P24_SEL;
    case port_p25:
        return M0P_GPIO->P25_SEL;
    case port_p26:
        return M0P_GPIO->P26_SEL;
    case port_p27:
        return M0P_GPIO->P27_SEL;
    case port_p31:
        return M0P_GPIO->P31_SEL;
    case port_p32:
        return M0P_GPIO->P32_SEL;
    case port_p33:
        return M0P_GPIO->P33_SEL;
    case port_p34:
        return M0P_GPIO->P34_SEL;
    case port_p35:
        return M0P_GPIO->P35_SEL;
    case port_p36:
        return M0P_GPIO->P36_SEL;
    default:
        return 0;
    }
}
