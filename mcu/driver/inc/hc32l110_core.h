
#ifndef __hc32l110_CORE_H__
#define __hc32l110_CORE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"

  uint8_t systick_init(uint32_t tick_frequency);
  void systick_delay(uint32_t delay_ticks);
  void systick_increment_ticks(void);
  uint32_t systick_get_tick(void);
  void systick_disable(void);
  void systick_enable(void);

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

  void ports_set_function(port_number_t port, uint8_t function);

  uint8_t ports_get_function(port_number_t port);

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
  __STATIC_INLINE void peripheral_set_enabled(peripheral_t enabled)
  {
    M0P_CLOCK->peripheral_clock_enable = enabled;
  }
  __STATIC_INLINE peripheral_t peripheral_get_enabled()
  {
    return (peripheral_t)M0P_CLOCK->peripheral_clock_enable;
  }

#ifdef __cplusplus
}
#endif

#endif
