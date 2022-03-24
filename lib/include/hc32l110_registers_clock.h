#ifndef __HC32L110_REGISTERS_CLOCK_H__
#define __HC32L110_REGISTERS_CLOCK_H__

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
    peripheral_uart0 = 0x00000001UL,          // 0
    peripheral_uart1 = 0x00000002UL,          // 1
    peripheral_lpuart = 0x00000004UL,         // 2
    peripheral_i2c = 0x00000010UL,            // 4
    peripheral_spi = 0x00000040UL,            // 6
    peripheral_base_timer = 0x00000100UL,     // 8
    peripheral_lptimer = 0x00000200UL,        // 9
    peripheral_advanced_timer = 0x00000400UL, // 10
    peripheral_pca = 0x00004000UL,            // 14
    peripheral_watchdog_timer = 0x00008000UL, // 15
    peripheral_adc = 0x00010000UL,            // 16
    peripheral_vc = 0x00020000UL,             // 17
    peripheral_rtc = 0x00100000UL,            // 20
    peripheral_trim = 0x00200000UL,           // 21
    peripheral_systick = 0x01000000UL,        // 24
    peripheral_crc = 0x04000000UL,            // 26
    peripheral_gpio = 0x10000000UL,           // 28
    peripheral_flash = 0x80000000UL,          // 31
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
    clock_sysctrl0_field_t SYSCTRL0;
    clock_sysctrl1_field_t SYSCTRL1;
    volatile uint32_t SYSCTRL2;
    clock_rch_cr_field_t RCH_CR;
    clock_external_cr_field_t XTH_CR;
    clock_rcl_cr_field_t RCL_CR;
    clock_external_cr_field_t XTL_CR;
    uint8_t RESERVED7[4];
    uint32_t peripheral_clock_enable;
    uint8_t RESERVED8[16];
    clock_systick_cr_field_t SYSTICK_CR;
    clock_debug_active_field_t DEBUG_ACTIVE;
  } HC32_CLOCK_TypeDef;
#define HC32_CLOCK ((HC32_CLOCK_TypeDef *)0x40002000UL)


typedef struct {
volatile uint8_t enabled:1;
volatile uint8_t interrupt_enabled:1;
volatile uint8_t clock_source:2;
uint16_t reserved1: 12;
volatile uint8_t counter_overflow:1;
uint16_t reserved2: 16;
} systick_ctrl_flags_t;

typedef struct
{
  systick_ctrl_flags_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  volatile uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  volatile uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} HC32_SYSTICK_TypeDef;
#define HC32_SYSTICK ((HC32_SYSTICK_TypeDef *)0xE000E010UL)


#define CLOCK_TRIM_HIGH_24mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C00ul))) * 1000)
#define CLOCK_TRIM_HIGH_22_12mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C02ul))) * 1000)
#define CLOCK_TRIM_HIGH_16mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C04ul))) * 1000)
#define CLOCK_TRIM_HIGH_8mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C06ul))) * 1000)
#define CLOCK_TRIM_HIGH_4mhz ((uint32_t)(*((volatile uint16_t *)(0x00100C08ul))) * 1000)
#define CLOCK_TRIM_LOW_38_4_khz ((uint32_t)(*((volatile uint16_t *)(0x00100C20ul))) * 1000)
#define CLOCK_TRIM_LOW_32_8_khz ((uint32_t)(*((volatile uint16_t *)(0x00100C22ul))) * 1000)
#define MAX_SYSTICK_VALUE 0x007FFFFFUL
#define khz32_8 32800
#define khz38_4 38400
#define mhz4 4000000
#define mhz8 8000000
#define mhz16 16000000
#define mhz22_12 22120000
#define mhz24 24000000


#endif
