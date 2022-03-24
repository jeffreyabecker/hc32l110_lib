#ifndef __HC32L110_REGISTERS_BASIC_TIMERS_H__
#define __HC32L110_REGISTERS_BASIC_TIMERS_H__

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
} HC32_BasicTimer_TypeDef;

typedef struct
{

  volatile uint32_t count_16;    // CNT
  volatile uint32_t auto_reload; // ARR
  uint32_t RESERVED;
  basic_timer_cr_field_t control;    // CR
  volatile uint32_t interrupt_flag;  // IFR
  volatile uint32_t interrupt_clear; // ICLR
} HC32_LPTIMER_TypeDef;

#define TIMER_0_ADDRESS 0x40000C00UL
#define TIMER_1_ADDRESS 0x40000C20UL
#define TIMER_2_ADDRESS 0x40000C40UL
#define LPTIMER_ADDRESS 0x40000C60UL

#define HC32_TIMER0 ((HC32_BasicTimer_TypeDef *)TIMER_0_ADDRESS)
#define HC32_TIMER1 ((HC32_BasicTimer_TypeDef *)TIMER_1_ADDRESS)
#define HC32_TIMER2 ((HC32_BasicTimer_TypeDef *)TIMER_2_ADDRESS)
#define HC32_LPTIMER ((HC32_LPTIMER_TypeDef *)LPTIMER_ADDRESS)

typedef enum
{
  basic_timer_gate_source_gate = 0,
  basic_timer_gate_source_uart0_rxd = 1,
  basic_timer_gate_source_uart1_rxd = 2,
  basic_timer_gate_source_lpuart_rxd = 3,
} basic_timer_gate_source_t;

typedef struct
{
  basic_timer_gate_source_t timer_0 : 2;
  basic_timer_gate_source_t timer_1 : 2;
  basic_timer_gate_source_t timer_2 : 2;
  basic_timer_gate_source_t timer_3 : 2;
} basic_timer_gate_selection_t;

#define HC32_BASIC_TIMER_GATE_CONTROL ((basic_timer_gate_selection_t *)0x40020F10)

#endif
