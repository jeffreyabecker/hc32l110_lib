#ifndef __HC32L110_REGISTERS_RTC_H__
#define __HC32L110_REGISTERS_RTC_H__

#ifdef __cplusplus
extern "C"
{
#endif
#if defined(__CC_ARM)
#pragma anon_unions
#endif
#include <stdint.h>
#include "hc32l110_registers_platform.h"

  typedef struct
  {
    volatile uint32_t TRIM_START : 1;
    volatile uint32_t REFCLK_SEL : 3;
    volatile uint32_t CALCLK_SEL : 2;
    volatile uint32_t MON_EN : 1;
    volatile uint32_t IE : 1;
  } stc_clk_trim_cr_field_t;

  typedef struct
  {
    stc_clk_trim_cr_field_t CR;
    volatile uint32_t REFCON;
    volatile uint32_t REFCNT;
    volatile uint32_t CALCNT;
    volatile uint32_t IFR;
    volatile uint32_t ICLR;
    volatile uint32_t CALCON;
  } M0P_CLK_TRIM_TypeDef;

  typedef struct
  {
    volatile uint32_t PRDS : 3;
    volatile uint32_t AMPM : 1;
    uint32_t RESERVED1 : 1;
    volatile uint32_t HZ1OE : 1;
    volatile uint32_t HZ1SEL : 1;
    volatile uint32_t START : 1;
    volatile uint32_t PRDX : 6;
    volatile uint32_t PRDSEL : 1;
    uint32_t RESERVED2 : 17;
    volatile uint32_t WAIT : 1;
    volatile uint32_t WAITF : 1;
    uint32_t RESERVED3 : 1;
    volatile uint32_t PRDF : 1;
    volatile uint32_t ALMF : 1;
    uint32_t RESERVED4 : 1;
    volatile uint32_t alarm_interrupt_enabled : 1;
    volatile uint32_t alarm_enabled : 1;
    volatile uint32_t clock_divisor_exponent : 3;
    uint32_t RESERVED5 : 21;
  } stc_rtc_cr_field_t;

  typedef struct
  {
    volatile uint32_t low_digit : 4;
    volatile uint32_t high_digit : 3;
  } stc_rtc_4_3_field_t;

  typedef struct
  {
    volatile uint32_t low_digit : 4;
    volatile uint32_t high_digit : 2;
  } stc_rtc_4_2_field_t;

  // typedef struct
  // {
  //   volatile uint32_t low_digit : 4;
  //   volatile uint32_t high_digit : 2;
  // } stc_rtc_day_field_t;

  typedef struct
  {
    volatile uint32_t low_digit : 4;
    volatile uint32_t high_digit : 4;
  } stc_rtc_year_field_t;

  typedef enum
  {
    sunday = 1,
    monday = 2,
    tuesday = 4,
    wednesday = 8,
    thursday = 16,
    friday = 32,
    saturday = 64
  } rtc_day_of_week_t;

  typedef struct
  {
    volatile uint32_t CR : 9;
    uint32_t RESERVED9 : 6;
    volatile uint32_t EN : 1;
  } stc_rtc_compen_field_t;

  typedef struct
  {
    stc_rtc_cr_field_t control;
    stc_rtc_4_3_field_t second;
    stc_rtc_4_3_field_t minute;
    stc_rtc_4_2_field_t hour;
    volatile uint32_t week;
    stc_rtc_4_2_field_t day;
    volatile uint32_t month;
    stc_rtc_year_field_t year;
    stc_rtc_4_3_field_t alarm_minute;
    stc_rtc_4_2_field_t alarm_hour;
    rtc_day_of_week_t alarm_day_of_week;
  } M0P_RTC_TypeDef;

  typedef struct
  {
    volatile uint32_t WOV : 4;
    volatile uint32_t WDTR : 1;
    volatile uint32_t WINT_EN : 1;
    uint32_t RESERVED6 : 1;
    volatile uint32_t WDINT : 1;
    volatile uint32_t WCNTL : 8;
  } stc_wdt_con_field_t;

  typedef struct
  {
    uint8_t RESERVED0[128];
    volatile uint32_t RST;
    stc_wdt_con_field_t CON;
  } M0P_WDT_TypeDef;

#define M0P_CLK_TRIM ((M0P_CLK_TRIM_TypeDef *)0x40001800UL)
#define M0P_RTC ((M0P_RTC_TypeDef *)0x40001400UL)
#define M0P_WDT ((M0P_WDT_TypeDef *)0x40000C00UL)

#ifdef __cplusplus
}
#endif

#endif
