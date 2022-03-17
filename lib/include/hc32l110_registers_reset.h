#ifndef __HC32L110_REGISTERS_RESET_H__
#define __HC32L110_REGISTERS_RESET_H__

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
    stc_reset_reset_flag_field_t RESET_FLAG;
    uint8_t RESERVED1[8];
    stc_reset_prei_reset_field_t PREI_RESET;
  } M0P_RESET_TypeDef;

#define M0P_RESET ((M0P_RESET_TypeDef *)0x4000201CUL)
#ifdef __cplusplus
}
#endif

#endif
