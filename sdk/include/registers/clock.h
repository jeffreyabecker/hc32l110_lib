#ifndef __HC32L110_REGISTERS_CLOCK_H__
#define __HC32L110_REGISTERS_CLOCK_H__
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

  typedef struct
  {
    volatile uint32_t STOP : 1;
    volatile uint32_t CALCNT_OF : 1;
    volatile uint32_t XTL_FAULT : 1;
    volatile uint32_t XTH_FAULT : 1;
  } clk_trim_ifr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 2;
    volatile uint32_t XTL_FAULT_CLR : 1;
    volatile uint32_t XTH_FAULT_CLR : 1;
  } clk_trim_iclr_field_t;

  typedef struct
  {
    volatile uint32_t RCH_EN : 1;
    volatile uint32_t XTH_EN : 1;
    volatile uint32_t RCL_EN : 1;
    volatile uint32_t XTL_EN : 1;
    volatile uint32_t CLK_SW4_SEL : 2;
    volatile uint32_t HCLK_PRS : 3;
    volatile uint32_t PCLK_PRS : 2;
    uint32_t RESERVED11 : 4;
    volatile uint32_t WAKEUP_BYRCH : 1;
  } clock_sysctrl0_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 1;
    volatile uint32_t EXTH_EN : 1;
    volatile uint32_t EXTL_EN : 1;
    volatile uint32_t XTL_ALWAYSON : 1;
    volatile uint32_t CLOCK_FT_EN : 1;
    volatile uint32_t RTC_LPW : 1;
    volatile uint32_t LOCK_EN : 1;
    volatile uint32_t RES_UIO : 1;
    volatile uint32_t SWD_UIO : 1;
    volatile uint32_t RTC_FREQ_ADJUST : 3;
  } clock_sysctrl1_field_t;

  typedef struct
  {
    volatile uint32_t TRIM : 11;
    volatile uint32_t STABLE : 1;
  } clock_rch_cr_field_t;

  typedef struct
  {
    volatile uint32_t TRIM : 10;
    volatile uint32_t STARTUP : 2;
    volatile uint32_t STABLE : 1;
  } clock_rcl_cr_field_t;

  typedef struct
  {
    volatile uint32_t DRIVER : 4;
    volatile uint32_t STARTUP : 2;
    volatile uint32_t STABLE : 1;
  } clock_external_cr_field_t;

  typedef enum
  {
    peripheral_none = 0x00000000UL,
    peripheral_uart0 = 0x00000001,   // 0
    peripheral_uart1 = 0x00000002,   // 1
    peripheral_lpuart = 0x00000004,  // 2
    peripheral_i2c = 0x00000010,     // 4
    peripheral_spi = 0x00000040,     // 6
    peripheral_basetim = 0x00000100, // 8
    peripheral_lptim = 0x00000200,   // 9
    peripheral_advtim = 0x00000400,  // 10
    peripheral_pca = 0x00004000,     // 14
    peripheral_wdt = 0x00008000,     // 15
    peripheral_adc = 0x00010000,     // 16
    peripheral_vc = 0x00020000,      // 17
    peripheral_rtc = 0x00100000,     // 20
    peripheral_trim = 0x00200000,    // 21
    peripheral_tick = 0x01000000,    // 24
    peripheral_crc = 0x04000000,     // 26
    peripheral_gpio = 0x10000000,    // 28
    peripheral_flash = 0x80000000,   // 31
  } peripheral_t;

  typedef struct
  {
    volatile uint32_t STCALIB : 24;
    volatile uint32_t SKEW : 1;
    volatile uint32_t NOREF : 1;
    volatile uint32_t CLK_SEL : 2;
  } clock_systick_cr_field_t;

  typedef struct
  {
    volatile uint32_t TIM0 : 1;
    volatile uint32_t TIM1 : 1;
    volatile uint32_t TIM2 : 1;
    volatile uint32_t LPTIM : 1;
    volatile uint32_t TIM4 : 1;
    volatile uint32_t TIM5 : 1;
    volatile uint32_t TIM6 : 1;
    volatile uint32_t PCA : 1;
    volatile uint32_t WDT : 1;
    volatile uint32_t RTC : 1;
    volatile uint32_t TICK : 1;
  } clock_debug_active_field_t;

  typedef struct
  {
    union
    {
      clock_sysctrl0_field_t SYSCTRL0_f;
      volatile uint32_t SYSCTRL0_r;
    };
    clock_sysctrl1_field_t SYSCTRL1;
    volatile uint32_t SYSCTRL2;
    clock_rch_cr_field_t RCH_CR;
    clock_external_cr_field_t XTH_CR;
    clock_rcl_cr_field_t RCL_CR;
    clock_external_cr_field_t XTL_CR;
    uint8_t RESERVED7[4];
    peripheral_t peripheral_clock_enable;
    uint8_t RESERVED8[16];
    clock_systick_cr_field_t SYSTICK_CR;
    clock_debug_active_field_t DEBUG_ACTIVE_f;
  } hc32_clock_register_t;
#define HC32_CLOCK ((hc32_clock_register_t *)0x40002000UL)

  typedef struct
  {
    volatile uint32_t POR5V : 1;
    volatile uint32_t POR15V : 1;
    volatile uint32_t LVD : 1;
    volatile uint32_t WDT : 1;
    volatile uint32_t PCA : 1;
    volatile uint32_t LOCKUP : 1;
    volatile uint32_t SYSREQ : 1;
    volatile uint32_t RSTB : 1;
  } stc_reset_reset_flag_field_t;

  typedef struct
  {
    volatile uint32_t UART0 : 1;
    volatile uint32_t UART1 : 1;
    volatile uint32_t LPUART : 1;
    uint32_t RESERVED3 : 1;
    volatile uint32_t I2C : 1;
    uint32_t RESERVED5 : 1;
    volatile uint32_t SPI : 1;
    uint32_t RESERVED7 : 1;
    volatile uint32_t BASETIM : 1;
    volatile uint32_t LPTIM : 1;
    volatile uint32_t ADVTIM : 1;
    uint32_t RESERVED11 : 3;
    volatile uint32_t PCA : 1;
    uint32_t RESERVED15 : 1;
    volatile uint32_t ADC : 1;
    volatile uint32_t VC : 1;
    uint32_t RESERVED18 : 2;
    volatile uint32_t RTC : 1;
    volatile uint32_t TRIM : 1;
    uint32_t RESERVED22 : 2;
    volatile uint32_t TICK : 1;
    uint32_t RESERVED25 : 1;
    volatile uint32_t CRC : 1;
    uint32_t RESERVED27 : 1;
    volatile uint32_t GPIO : 1;
  } stc_reset_prei_reset_field_t;

  typedef struct
  {

    stc_reset_reset_flag_field_t RESET_FLAG;
    uint8_t RESERVED1[8];
    stc_reset_prei_reset_field_t PREI_RESET;

  } hc32_reset_register_t;
#define HC32_RESET ((hc32_reset_register_t *)0x4000201CUL)

#define CLOCK_TRIM_HIGH_24_mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C00ul))))
#define CLOCK_TRIM_HIGH_22_12_mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C02ul))))
#define CLOCK_TRIM_HIGH_16_mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C04ul))))
#define CLOCK_TRIM_HIGH_8_mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C06ul))))
#define CLOCK_TRIM_HIGH_4_mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C08ul))))
#define CLOCK_TRIM_LOW_38_4_khz ((uint32_t)(*((volatile uint16_t *)(0x00100C20ul))))
#define CLOCK_TRIM_LOW_32_8_khz ((uint32_t)(*((volatile uint16_t *)(0x00100C22ul))))

#define MAX_SYSTICK_VALUE 0x007FFFFFUL



#ifdef __cplusplus
}
#endif

#endif
