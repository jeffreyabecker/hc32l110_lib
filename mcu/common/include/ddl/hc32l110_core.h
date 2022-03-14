
#ifndef __hc32l110_CORE_H__
#define __hc32l110_CORE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"

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

  extern uint32_t SystemCoreClock;
  extern uint32_t PeripheralCoreClock;

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
  __STATIC_FORCEINLINE void core_peripheral_set_enabled(peripheral_t enabled)
  {
    M0P_CLOCK->peripheral_clock_enable = (uint32_t)enabled;
  }
  __STATIC_FORCEINLINE peripheral_t core_peripheral_get_enabled()
  {
    return (peripheral_t)M0P_CLOCK->peripheral_clock_enable;
  }
  __STATIC_FORCEINLINE peripheral_t core_peripheral_is_enabled(peripheral_t enabled)
  {
    return enabled & M0P_CLOCK->peripheral_clock_enable > 0 ? 1 : 0;
  }

#ifdef __cplusplus
}
#endif

#endif
