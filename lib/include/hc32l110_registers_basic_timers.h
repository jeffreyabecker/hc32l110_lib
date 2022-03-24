#ifndef __HC32L110_REGISTERS_BASIC_TIMERS_H__
#define __HC32L110_REGISTERS_BASIC_TIMERS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

  typedef enum
  {
    timer_prescaler_1_to_1 = 0,
    timer_prescaler_2_to_1 = 1,
    timer_prescaler_4_to_1 = 2,
    timer_prescaler_8_to_1 = 3,
    timer_prescaler_16_to_1 = 4,
    timer_prescaler_32_to_1 = 5,
    timer_prescaler_64_to_1 = 6,
    timer_prescaler_256_to_1 = 7,
  } basic_timer_prescaler_t;

  typedef enum
  {
    lptimer_clock_pclk = 0,
    lptimer_clock_xtl = 2,
    lptimer_clock_rcl = 3
  } lp_timer_clock_select_t;

  typedef enum
  {
    basic_timer_source_internal = 0,
    basic_timer_source_external = 1,
  } basic_timer_source_t;

  typedef enum
  {
    basic_timer_mode_one_shot = 0,
    basic_timer_mode_periodic = 1,
  } basic_timer_mode_t;

  typedef struct
  {
    volatile uint8_t timer_running : 1;            // TR
    volatile basic_timer_mode_t mode : 1;          // MD
    volatile basic_timer_source_t tick_source : 1; // CT
    volatile uint8_t enable_inverted_output : 1;   // TOG_EN
    union
    {
      volatile basic_timer_prescaler_t prescaler : 4; // PRS
      struct
      {
        volatile lp_timer_clock_select_t clock_source : 3; // TCK_SEL
        volatile uint32_t write_syncronizing : 1;          // WT_FLAG
      } low_power;
    };
    volatile uint8_t enable_gate : 1;       // GATE
    volatile uint8_t gate_polarity : 1;     // GATE_P
    volatile uint8_t interrupt_enabled : 1; // IE
  } basic_timer_cr_field_t;

  typedef struct
  {
    volatile uint32_t auto_reload;     // ARR
    volatile uint32_t count_16;        // CNT
    volatile uint32_t count_32;        // CNT32
    basic_timer_cr_field_t control;    // CR
    volatile uint32_t interrupt_flag;  // IFR
    volatile uint32_t interrupt_clear; // ICLR
  } M0P_BasicTimer_TypeDef;

  typedef struct
  {

    volatile uint32_t count_16;    // CNT
    volatile uint32_t auto_reload; // ARR
    uint32_t RESERVED;
    basic_timer_cr_field_t control;    // CR
    volatile uint32_t interrupt_flag;  // IFR
    volatile uint32_t interrupt_clear; // ICLR
  } M0P_LPTIMER_TypeDef;

#define TIMER_0_ADDRESS 0x40000C00UL
#define TIMER_1_ADDRESS 0x40000C20UL
#define TIMER_2_ADDRESS 0x40000C40UL
#define LPTIMER_ADDRESS 0x40000C60UL

#define M0P_TIMER0 ((M0P_BasicTimer_TypeDef *)TIMER_0_ADDRESS)
#define M0P_TIMER1 ((M0P_BasicTimer_TypeDef *)TIMER_1_ADDRESS)
#define M0P_TIMER2 ((M0P_BasicTimer_TypeDef *)TIMER_2_ADDRESS)
#define M0P_LPTIMER ((M0P_LPTIMER_TypeDef *)LPTIMER_ADDRESS)
#ifdef __cplusplus
}
#endif

#endif
