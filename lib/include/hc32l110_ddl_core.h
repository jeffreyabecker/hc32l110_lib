
#ifndef __hc32l110_CORE_H__
#define __hc32l110_CORE_H__
#if defined(DDL_USE_ALL) || defined(DDL_USE_CORE)
#ifdef __cplusplus
extern "C"
{
#endif
#include <stddef.h>
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
    core_peripheral_clock_divider_1 = 0,
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

  __read_only_data core_system_config_t default_system_config = {
      .clock_source = core_clock_source_internal_high_speed,
      .system_clock_prescaler = 0,
      .peripheral_clock_prescaler = 0,
      .enable_systick = 1,
      .clock_frequency_hz = 4000000,
      .systick_frequency_hz = 1000};
  void core_system_clock_config(core_system_config_t config);
  __FORCE_INLINE uint32_t core_get_system_clock_frequency() { return SystemCoreClock; };
  __FORCE_INLINE uint32_t core_get_peripheral_clock_frequency() { return PeripheralCoreClock; };

  void core_systick_delay(uint32_t delay_ticks);
  void core_systick_increment_ticks(void);
  __FORCE_INLINE uint32_t core_systick_get_tick(void);
  void core_systick_disable(void);
  void core_systick_enable(void);
  typedef void (*core_systick_handler_t)();
  void core_set_systick_handler(core_systick_handler_t *handler);

  void nvic_interrupt_set_enabled(nivc_irq_number_t irq_number, uint8_t enabled);
  void nvic_interrupt_raise(nivc_irq_number_t irq_number);
  void nvic_interrupt_clear(nivc_irq_number_t irq_number);

#define systick_max_reload_value 0xFFFFFFUL

  typedef enum
  {
    peripheral_uart0 = 0x00000001UL, 
    peripheral_uart1 = 0x00000002UL, // 1
    peripheral_lpuart = 0x00000004UL, // 2
    peripheral_i2c = 0x00000010UL, // 4
    peripheral_spi = 0x00000040UL, // 6
    peripheral_base_timer = 0x00000100UL, // 8
    peripheral_lptimer = 0x00000200UL, // 9
    peripheral_advanced_timer = 0x00000400UL, // 10
    peripheral_pca = 0x00004000UL, // 14
    peripheral_watchdog_timer = 0x00008000UL, // 15
    peripheral_adc = 0x00010000UL, // 16
    peripheral_vc = 0x00020000UL, // 17
    peripheral_rtc = 0x00100000UL, // 20
    peripheral_trim = 0x00200000UL, // 21
    peripheral_systick = 0x01000000UL, // 24
    peripheral_crc = 0x04000000UL, // 26
    peripheral_gpio = 0x10000000UL, // 28
    peripheral_flash = 0x80000000UL, // 31
  } peripheral_t;

  uint32_t tick_increment_step = 0ul;
  volatile uint32_t current_tick_count = 0ul;

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
    void nvic_interrupt_raise(nivc_irq_number_t irq_number)
    {
        if ((int32_t)(irq_number) >= 0)
        {
            NVIC->SCS_SETPEND = (uint32_t)(1UL << (((uint32_t)irq_number -5) & 0x1FUL));
        }
    }
  /**
    \brief   System Reset
    \details Initiates a system reset request to reset the MCU.
   */
  void core_system_reset(void)
  {
    __DSB(); /* Ensure all outstanding memory accesses included
                buffered write are completed before reset */
    SCB->AIRCR = 0x05FA0004UL;
    __DSB(); /* Ensure completion of memory access */

    for (;;) /* wait until reset */
    {
      __NOP();
    }
  }
  static uint32_t __clock_interpolate(uint32_t clock_frequency, uint32_t low_freqency, uint32_t high_frequency, uint32_t low_trim, uint32_t high_trim)
  {
    return (low_trim + ((clock_frequency - low_freqency) * ((high_trim - low_trim) / (high_frequency - low_freqency)))) / 1000;
  }
  static void __core_clock_config_unlock(void)
  {
    M0P_CLOCK->SYSCTRL2 = 0x5A5A;
    M0P_CLOCK->SYSCTRL2 = 0xA5A5;
  }

  static uint16_t __core_calculate_clock_trim(core_system_config_t config)
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
  /**
    \brief   Enable Interrupt
    \details Enables a device specific interrupt in the NVIC interrupt controller.
    \param [in]      irq_number  Device specific interrupt number.
    \note    irq_number must not be negative.
   */
  inline void nvic_interrupt_set_enabled(nivc_irq_number_t irq_number, uint8_t enabled)
  {
    if ((int32_t)(irq_number) >= 5)
    {

      NVIC->SCS_SETENA = (uint32_t)(1UL << (((uint32_t)irq_number - 5) & 0x1FUL & enabled));
      __DSB();
      __ISB();
    }
    else if (irq_number == irq_sys_tick)
    {
      SysTick->CTRL_f.interrupt_enable = enabled;
      SysTick->CTRL_f.enable = enabled;
    }
  }

  /**
    \brief   Get Interrupt Enable status
    \details Returns a device specific interrupt enable status from the NVIC interrupt controller.
    \param [in]      irq_number  Device specific interrupt number.
    \return             0  Interrupt is not enabled.
    \return             1  Interrupt is enabled.
    \note    irq_number must not be negative.
   */
  inline uint32_t nvic_is_interrupt_enabled(nivc_irq_number_t irq_number)
  {
    if ((int32_t)(irq_number) >= 5)
    {
      return ((uint32_t)(((NVIC->SCS_SETENA & (1UL << (((uint32_t)irq_number - 5) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
    }
    else if (irq_number == irq_sys_tick)
    {
      return SysTick->CTRL_f.interrupt_enable;
    }
    else
    {
      return (0U);
    }
  }

  /**
    \brief   Get Pending Interrupt
    \details Reads the NVIC pending register and returns the pending bit for the specified device specific interrupt.
    \param [in]      irq_number  Device specific interrupt number.
    \return             0  Interrupt status is not pending.
    \return             1  Interrupt status is pending.
    \note    irq_number must not be negative.
   */
  inline uint32_t nvic_is_interrupt_pending(nivc_irq_number_t irq_number)
  {
    if ((int32_t)(irq_number) >= 5)
    {
      return ((uint32_t)(((NVIC->SCS_SETENA & (1UL << (((uint32_t)irq_number - 5) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
    }
    else
    {
      return (0U);
    }
  }

  /**
    \brief   Clear Pending Interrupt
    \details Clears the pending bit of a device specific interrupt in the NVIC pending register.
    \param [in]      irq_number  Device specific interrupt number.
    \note    irq_number must not be negative.
   */
  inline void nvic_interrupt_clear_pending(nivc_irq_number_t irq_number)
  {
    if ((int32_t)(irq_number) >= 5)
    {
      NVIC->SCS_CLRPEND = (uint32_t)(1UL << (((uint32_t)irq_number - 5) & 0x1FUL));
    }
  }
  inline void core_peripheral_set_enabled(peripheral_t enabled)
  {
    M0P_CLOCK->peripheral_clock_enable = (uint32_t)enabled;
  }
  static inline peripheral_t core_peripheral_get_enabled()
  {
    return (peripheral_t)M0P_CLOCK->peripheral_clock_enable;
  }
  static inline uint8_t core_peripheral_is_enabled(peripheral_t enabled)
  {
    return enabled & M0P_CLOCK->peripheral_clock_enable > 0 ? 1 : 0;
  }
  /**
   * @brief This function provides minimum delay in ticks.
   * @param [in] delay_ticks Delay specifies the delay time.
   * @retval None
   */
  void core_systick_delay(uint32_t delay_ticks)
  {
    const uint32_t tick_start = core_systick_get_tick();
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

      while ((core_systick_get_tick() - tick_start) < tick_end)
      {
        __WFI();
      }
    }
  }

  /**
   * @brief This function is called to increment a global variable "u32TickCount".
   * @note  This variable is incremented in SysTick ISR.
   * @param None
   * @retval None
   */
  __FORCE_INLINE void core_systick_increment_ticks(void)
  {
    current_tick_count += tick_increment_step;
  }

  /**
   * @brief Provides a tick value
   * @param None
   * @retval Tick value
   */
  __FORCE_INLINE uint32_t core_systick_get_tick(void) { return current_tick_count; }

  // PORT0 0x40020CCAUL
  // 64 bytes

  void core_system_clock_config(core_system_config_t config)
  {
    uint16_t clock_trim = __core_calculate_clock_trim(config);
    if (M0P_CLOCK->SYSCTRL0.CLK_SW4_SEL != config.clock_source)
    {
      if (config.clock_source == core_clock_source_external_low_speed)
      {
        M0P_GPIO->P1ADS = 0x30;

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
      core_peripheral_set_enabled(core_peripheral_get_enabled() | peripheral_systick);
      uint32_t ticks = PeripheralCoreClock / config.systick_frequency_hz;
      if ((ticks - 1UL) > systick_max_reload_value)
      {
        return; /* Reload value impossible */
      }

      SysTick->LOAD = (uint32_t)(ticks - 1UL); /* set reload register */
      SysTick->VAL = 0UL;                      /* Load the SysTick Counter Value */
      SysTick->CTRL_f.clock_source = 1;
      SysTick->CTRL_f.interrupt_enable = 1;
      SysTick->CTRL_f.enable = 1;
    }
  }



#ifdef __cplusplus
}
#endif

#endif

#endif
