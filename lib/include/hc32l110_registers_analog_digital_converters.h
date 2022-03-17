#ifndef __HC32L110_REGISTERS_ANALOG_DIGITAL_CONVERTERS_H__
#define __HC32L110_REGISTERS_ANALOG_DIGITAL_CONVERTERS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

#include "hc32l110_registers_platform.h"

  typedef struct
  {
    volatile uint32_t ADCEN : 1;
    volatile uint32_t START : 1;
    volatile uint32_t CLKSEL : 2;
    volatile uint32_t SEL : 4;
    volatile uint32_t SREF : 2;
    volatile uint32_t BUFEN : 1;
    volatile uint32_t SAM : 2;
    uint32_t RESERVED13 : 1;
    volatile uint32_t IE : 1;
    volatile uint32_t STATERST : 1;
  } stc_adc_cr0_field_t;

  typedef struct
  {
    volatile uint32_t TRIGS0 : 5;
    volatile uint32_t TRIGS1 : 5;
    volatile uint32_t CT : 1;
    volatile uint32_t RACC_EN : 1;
    volatile uint32_t LTCMP : 1;
    volatile uint32_t HTCMP : 1;
    volatile uint32_t REGCMP : 1;
    volatile uint32_t RACC_CLR : 1;
  } stc_adc_cr1_field_t;

  typedef struct
  {
    volatile uint32_t CH0EN : 1;
    volatile uint32_t CH1EN : 1;
    volatile uint32_t CH2EN : 1;
    volatile uint32_t CH3EN : 1;
    volatile uint32_t CH4EN : 1;
    volatile uint32_t CH5EN : 1;
    volatile uint32_t CH6EN : 1;
    volatile uint32_t CH7EN : 1;
    volatile uint32_t ADCCNT : 8;
  } stc_adc_cr2_field_t;

  typedef struct
  {
    volatile uint32_t LLT_INTF : 1;
    volatile uint32_t HHT_INTF : 1;
    volatile uint32_t REG_INTF : 1;
    volatile uint32_t CONT_INTF : 1;
  } stc_adc_ifr_field_t;

  typedef struct
  {
    volatile uint32_t LLT_INTC : 1;
    volatile uint32_t HHT_INTC : 1;
    volatile uint32_t REG_INTC : 1;
    volatile uint32_t CONT_INTC : 1;
  } stc_adc_iclr_field_t;
  typedef struct
  {
    uint8_t RESERVED0[4];
    union
    {
      volatile uint32_t CR0;
      stc_adc_cr0_field_t CR0_f;
    };
    union
    {
      volatile uint32_t CR1;
      stc_adc_cr1_field_t CR1_f;
    };
    union
    {
      volatile uint32_t CR2;
      stc_adc_cr2_field_t CR2_f;
    };
    uint8_t RESERVED3[32];
    volatile uint32_t RESULT_ARR[9];
    volatile uint32_t RESULT_ACC;
    volatile uint32_t HT;
    volatile uint32_t LT;
    union
    {
      volatile uint32_t IFR;
      stc_adc_ifr_field_t IFR_f;
    };
    union
    {
      volatile uint32_t ICLR;
      stc_adc_iclr_field_t ICLR_f;
    };
    volatile uint32_t RESULT;
  } M0P_ADC_TypeDef;
#define M0P_ADC ((M0P_ADC_TypeDef *)0x40002400UL)

#ifdef __cplusplus
}
#endif

#endif
