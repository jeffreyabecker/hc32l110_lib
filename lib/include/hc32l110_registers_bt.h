#ifndef __HC32L110_REGISTERS_BT_H__
#define __HC32L110_REGISTERS_BT_H__

#include <stdint.h>
typedef enum
{
  basic_timer_prescaler_1_to_1 = 0,
  basic_timer_prescaler_2_to_1 = 1,
  basic_timer_prescaler_4_to_1 = 2,
  basic_timer_prescaler_8_to_1 = 3,
  basic_timer_prescaler_16_to_1 = 4,
  basic_timer_prescaler_32_to_1 = 5,
  basic_timer_prescaler_64_to_1 = 6,
  basic_timer_prescaler_256_to_1 = 7,
} basic_timer_prescaler_t;



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
  volatile uint32_t timer_running : 1;
  volatile basic_timer_mode_t mode : 1;
  volatile basic_timer_source_t clock_source : 1;
  volatile uint32_t toggle_enabled : 1;
  volatile basic_timer_prescaler_t prescaler : 3;
  uint32_t RESERVED : 1;
  volatile uint32_t gate_enabled : 1;
  volatile uint32_t gate_polarity : 1;
  volatile uint32_t interrupt_enabled : 1;
} hc32_basic_timer_control_register_t;

typedef struct
{
  volatile uint32_t auto_reload;
  volatile uint32_t count16;
  volatile uint32_t count32;
  union
  {
    volatile uint32_t control;
    hc32_basic_timer_control_register_t control_flags;
  };
  volatile uint32_t interrupt_flag;
  volatile uint32_t interrupt_clear;

} hc32_basic_timer_register_t;
#define TIMER_0_ADDRESS 0x40000C00UL
#define TIMER_1_ADDRESS 0x40000C20UL
#define TIMER_2_ADDRESS 0x40000C40UL
#define HC32_TIMER0 ((hc32_basic_timer_register_t *)TIMER_0_ADDRESS)
#define HC32_TIMER1 ((hc32_basic_timer_register_t *)TIMER_1_ADDRESS)
#define HC32_TIMER2 ((hc32_basic_timer_register_t *)TIMER_2_ADDRESS)


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
