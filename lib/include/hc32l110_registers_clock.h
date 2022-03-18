#ifndef __HC32L110_REGISTERS_CLOCK_H__
#define __HC32L110_REGISTERS_CLOCK_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

#include "hc32l110_registers_platform.h"
  typedef struct
  {
    volatile uint32_t STOP : 1;
    volatile uint32_t CALCNT_OF : 1;
    volatile uint32_t XTL_FAULT : 1;
    volatile uint32_t XTH_FAULT : 1;
  } stc_clk_trim_ifr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 2;
    volatile uint32_t XTL_FAULT_CLR : 1;
    volatile uint32_t XTH_FAULT_CLR : 1;
  } stc_clk_trim_iclr_field_t;

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
  } stc_clock_sysctrl0_field_t;

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
  } stc_clock_sysctrl1_field_t;

  typedef struct
  {
    volatile uint32_t TRIM : 11;
    volatile uint32_t STABLE : 1;
  } stc_clock_rch_cr_field_t;



  typedef struct
  {
    volatile uint32_t TRIM : 10;
    volatile uint32_t STARTUP : 2;
    volatile uint32_t STABLE : 1;
  } stc_clock_rcl_cr_field_t;

  typedef struct
  {
    volatile uint32_t DRIVER : 4;
    volatile uint32_t STARTUP : 2;
    volatile uint32_t STABLE : 1;
  } stc_clock_external_cr_field_t;


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
    volatile uint32_t WDT : 1;
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
    uint32_t RESERVED29 : 2;
    volatile uint32_t FLASH : 1;
  } stc_clock_peri_clken_field_t;



  typedef struct
  {
    volatile uint32_t STCALIB : 24;
    volatile uint32_t SKEW : 1;
    volatile uint32_t NOREF : 1;
    volatile uint32_t CLK_SEL : 2;
  } stc_clock_systick_cr_field_t;

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
  } stc_clock_debug_active_field_t;

  typedef struct
  {
    stc_clock_sysctrl0_field_t SYSCTRL0;
    stc_clock_sysctrl1_field_t SYSCTRL1;
    volatile uint32_t SYSCTRL2;
    stc_clock_rch_cr_field_t RCH_CR;
    stc_clock_external_cr_field_t XTH_CR;
    stc_clock_rcl_cr_field_t RCL_CR;
    stc_clock_external_cr_field_t XTL_CR;
    uint8_t RESERVED7[4];
    union{
      uint32_t peripheral_clock_enable;
      stc_clock_peri_clken_field_t peripheral_clock_enable_f;
    };
    uint8_t RESERVED8[16];
    stc_clock_systick_cr_field_t SYSTICK_CR;
    stc_clock_debug_active_field_t DEBUG_ACTIVE;
  } M0P_CLOCK_TypeDef;
#define M0P_CLOCK ((M0P_CLOCK_TypeDef *)0x40002000UL)

#ifdef __cplusplus
}
#endif

#endif
