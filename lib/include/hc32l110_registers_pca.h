#ifndef __HC32L110_REGISTERS_PCA_H__
#define __HC32L110_REGISTERS_PCA_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers_platform.h"
  typedef struct
  {
    volatile uint32_t CCF0 : 1;
    volatile uint32_t CCF1 : 1;
    volatile uint32_t CCF2 : 1;
    volatile uint32_t CCF3 : 1;
    volatile uint32_t CCF4 : 1;
    uint32_t RESERVED5 : 1;
    volatile uint32_t CR : 1;
    volatile uint32_t CF : 1;
  } stc_pca_ccon_field_t;

  typedef struct
  {
    volatile uint32_t CFIE : 1;
    volatile uint32_t CPS : 3;
    uint32_t RESERVED4 : 2;
    volatile uint32_t WDTE : 1;
    volatile uint32_t CIDL : 1;
  } stc_pca_cmod_field_t;

  typedef struct
  {
    volatile uint32_t CCF0 : 1;
    volatile uint32_t CCF1 : 1;
    volatile uint32_t CCF2 : 1;
    volatile uint32_t CCF3 : 1;
    volatile uint32_t CCF4 : 1;
    uint32_t RESERVED5 : 2;
    volatile uint32_t CF : 1;
  } stc_pca_iclr_field_t;

  typedef struct
  {
    volatile uint32_t CCIE : 1;
    volatile uint32_t PWM : 1;
    volatile uint32_t TOG : 1;
    volatile uint32_t MAT : 1;
    volatile uint32_t CAPN : 1;
    volatile uint32_t CAPP : 1;
    volatile uint32_t ECOM : 1;
  } stc_pca_ccapmx_field_t;

  typedef struct
  {
    volatile uint32_t CCAPO0 : 1;
    volatile uint32_t CCAPO1 : 1;
    volatile uint32_t CCAPO2 : 1;
    volatile uint32_t CCAPO3 : 1;
    volatile uint32_t CCAPO4 : 1;
  } stc_pca_ccapo_field_t;

  typedef struct
  {
    stc_pca_ccon_field_t CCON;
    stc_pca_cmod_field_t CMOD;
    volatile uint32_t CNT;
    stc_pca_iclr_field_t ICLR;
    stc_pca_ccapmx_field_t CCAPM0;
    stc_pca_ccapmx_field_t CCAPM1;
    stc_pca_ccapmx_field_t CCAPM2;
    stc_pca_ccapmx_field_t CCAPM3;
    stc_pca_ccapmx_field_t CCAPM4;
    volatile uint32_t CCAP0H;
    volatile uint32_t CCAP0L;
    volatile uint32_t CCAP1H;
    volatile uint32_t CCAP1L;
    volatile uint32_t CCAP2H;
    volatile uint32_t CCAP2L;
    volatile uint32_t CCAP3H;
    volatile uint32_t CCAP3L;
    volatile uint32_t CCAP4H;
    volatile uint32_t CCAP4L;
    stc_pca_ccapo_field_t CCAPO;
    volatile uint32_t CCAP0;
    volatile uint32_t CCAP1;
    volatile uint32_t CCAP2;
    volatile uint32_t CCAP3;
    volatile uint32_t CCAP4;
  } M0P_PCA_TypeDef;
#define M0P_PCA ((M0P_PCA_TypeDef *)0x40001000UL)
#ifdef __cplusplus
}
#endif

#endif
