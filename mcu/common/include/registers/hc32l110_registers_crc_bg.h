#ifndef __HC32L110_REGISTERS_CRC_BG_H__
#define __HC32L110_REGISTERS_CRC_BG_H__

#ifdef __cplusplus
extern "C"
{
#endif
#if defined(__CC_ARM)
#pragma anon_unions
#endif

#include "hc32l110_registers_cmsis.h"
  typedef struct
  {
    uint8_t RESERVED0[4];
    __IO uint32_t RESULT;
    uint8_t RESERVED1[120];
    union
    {
      __IO uint32_t DATA32;
      __IO uint16_t DATA16;
      __IO uint8_t DATA8;
    };
  } M0P_CRC_TypeDef;
  typedef struct
  {
    __IO uint32_t BGR_EN : 1;
    __IO uint32_t TS_EN : 1;
  } stc_bgr_cr_field_t;

  typedef struct
  {
    stc_bgr_cr_field_t CR;
  } M0P_BGR_TypeDef;

#define M0P_BGR ((M0P_BGR_TypeDef *)0x40002400UL)
#define M0P_CRC ((M0P_CRC_TypeDef *)0x40020900UL)  
#ifdef __cplusplus
}
#endif

#endif
