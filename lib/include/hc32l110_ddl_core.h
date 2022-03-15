
#ifndef __hc32l110_CORE_H__
#define __hc32l110_CORE_H__
#if defined(DDL_USE_ALL) ||  defined(DDL_USE_CORE) 
#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_system.h"

  typedef enum
  {
    core_clock_source_internal_high_speed = 0,
    core_clock_source_external_high_speed = 1,
    core_clock_source_internal_low_speed = 2,
    core_clock_source_external_low_speed = 3
  } core_clock_source_t;

  typedef enum
  {
    core_system_clock_divider_0 = 0,
    core_system_clock_divider_2 = 1,
    core_system_clock_divider_4 = 2,
    core_system_clock_divider_8 = 3,
    core_system_clock_divider_16 = 4,
    core_system_clock_divider_32 = 5,
    core_system_clock_divider_64 = 6,
    core_system_clock_divider_128 = 7,
  } core_system_clock_divider_t;
  typedef enum
  {
    core_peripheral_clock_divider_0 = 0,
    core_peripheral_clock_divider_2 = 1,
    core_peripheral_clock_divider_4 = 2,
    core_peripheral_clock_divider_8 = 3,
  } core_peripheral_clock_divider_t;

  typedef struct
  {
    core_clock_source_t clock_source : 2;
    core_system_clock_divider_t system_clock_prescaler : 3;
    core_peripheral_clock_divider_t peripheral_clock_prescaler : 2;
    uint8_t enable_systick : 1;
    uint32_t clock_frequency_hz;
    uint32_t systick_frequency_hz;
  } core_system_config_t;

  __STATIC_INLINE core_system_config_t default_system_config()
  {
    core_system_config_t result = {
        .clock_source = core_clock_source_internal_high_speed,
        .system_clock_prescaler = 0,
        .peripheral_clock_prescaler = 0,
        .enable_systick = 1,
        .clock_frequency_hz = 4000000,
        .systick_frequency_hz = 100000};
    return result;
  }
  void core_system_clock_config(core_system_config_t config);
  __STATIC_FORCEINLINE uint32_t core_get_system_clock_frequency() { return SystemCoreClock; };
  __STATIC_FORCEINLINE uint32_t core_get_peripheral_clock_frequency() { return PeripheralCoreClock; };

  void core_systick_delay(uint32_t delay_ticks);
  void core_systick_increment_ticks(void);
  uint32_t core_systick_get_tick(void);
  void core_systick_disable(void);
  void core_systick_enable(void);

  typedef enum
  {
    port_p01 = 1,
    port_p02 = 2,
    port_p03 = 3,
    port_p14 = 14,
    port_p15 = 15,
    port_p23 = 23,
    port_p24 = 24,
    port_p25 = 25,
    port_p26 = 26,
    port_p27 = 27,
    port_p31 = 31,
    port_p32 = 32,
    port_p33 = 33,
    port_p34 = 34,
    port_p35 = 35,
    port_p36 = 36,
  } port_number_t;

  void core_ports_set_function(port_number_t port, uint8_t function);

  uint8_t core_ports_get_function(port_number_t port);

  typedef enum
  {
    peripheral_uart0 = 0x00000001UL,
    peripheral_uart1 = 0x00000002UL,
    peripheral_lpuart = 0x00000004UL,
    peripheral_i2c = 0x00000010UL,
    peripheral_spi = 0x00000040UL,
    peripheral_base_timer = 0x00000100UL,
    peripheral_lptimer = 0x00000200UL,
    peripheral_advanced_timer = 0x00000400UL,
    peripheral_pca = 0x00004000UL,
    peripheral_watchdog_timer = 0x00008000UL,
    peripheral_adc = 0x00010000UL,
    peripheral_vc = 0x00020000UL,
    peripheral_rtc = 0x00100000UL,
    peripheral_trim = 0x00200000UL,
    peripheral_systick = 0x01000000UL,
    peripheral_crc = 0x04000000UL,
    peripheral_gpio = 0x10000000UL,
    peripheral_flash = 0x80000000UL,
  } peripheral_t;
  __STATIC_FORCEINLINE void core_peripheral_set_enabled(peripheral_t enabled) { M0P_CLOCK->peripheral_clock_enable = (uint32_t)enabled; }
  __STATIC_FORCEINLINE peripheral_t core_peripheral_get_enabled()
  {
    return (peripheral_t)M0P_CLOCK->peripheral_clock_enable;
  }
  __STATIC_FORCEINLINE peripheral_t core_peripheral_is_enabled(peripheral_t enabled)
  {
    return enabled & M0P_CLOCK->peripheral_clock_enable > 0 ? 1 : 0;
  }
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
#define sub_4mhz_scale_factor 8000
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
      if (config.clock_frequency_hz < mhz4)
      {
        return clock_trim_high_4mhz - sub_4mhz_scale_factor * (mhz4 - config.clock_frequency_hz);
      }
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

#if not( defined(DDL_USE_ALL) || defined(DDL_USE_INTERRUPTS))
  void SysTick_Handler(void)
  {
    core_systick_increment_ticks();
  }
#endif
#endif
#ifdef __cplusplus
}
#endif

#endif
