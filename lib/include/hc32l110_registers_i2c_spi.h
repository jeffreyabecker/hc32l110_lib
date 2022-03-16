#ifndef __HC32L110_REGISTERS_I2C_SPI_H__
#define __HC32L110_REGISTERS_I2C_SPI_H__

#ifdef __cplusplus
extern "C"
{
#endif
#if defined(__CC_ARM)
#pragma anon_unions
#endif

#include "hc32l110_registers_platform.h"

  typedef struct
  {
    volatile uint32_t H1M : 1;
    uint32_t RESERVED1 : 1;
    volatile uint32_t AA : 1;
    volatile uint32_t SI : 1;
    volatile uint32_t STO : 1;
    volatile uint32_t STA : 1;
    volatile uint32_t ENS : 1;
  } stc_i2c_cr_field_t;

  typedef struct
  {
    volatile uint32_t GC : 1;
    volatile uint32_t I2CADR : 7;
  } stc_i2c_addr_field_t;

  typedef struct
  {
    volatile uint32_t TMRUN;
    volatile uint32_t TM;
    stc_i2c_cr_field_t CR;
    volatile uint32_t DATA;
    stc_i2c_addr_field_t ADDR;
    volatile uint32_t STAT;
  } M0P_I2C_TypeDef;
  typedef struct
  {
    volatile uint32_t SPR0 : 1;
    volatile uint32_t SPR1 : 1;
    volatile uint32_t CPHA : 1;
    volatile uint32_t CPOL : 1;
    volatile uint32_t MSTR : 1;
    uint32_t RESERVED5 : 1;
    volatile uint32_t SPEN : 1;
    volatile uint32_t SPR2 : 1;
  } stc_spi_cr_field_t;

  typedef struct
  {
    uint32_t RESERVED0 : 4;
    volatile uint32_t MDF : 1;
    volatile uint32_t SSERR : 1;
    volatile uint32_t WCOL : 1;
    volatile uint32_t SPIF : 1;
  } stc_spi_stat_field_t;

  typedef struct
  {
    stc_spi_cr_field_t CR;
    volatile uint32_t SSN;
    stc_spi_stat_field_t STAT;
    volatile uint32_t DATA;
  } M0P_SPI_TypeDef;

#define M0P_I2C ((M0P_I2C_TypeDef *)0x40000400UL)
#define M0P_SPI ((M0P_SPI_TypeDef *)0x40000800UL)
#ifdef __cplusplus
}
#endif

#endif
