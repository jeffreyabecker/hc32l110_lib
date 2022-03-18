#ifndef __HC32L110_REGISTERS_CRC_BG_H__
#define __HC32L110_REGISTERS_CRC_BG_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

#include "hc32l110_registers_platform.h"
  typedef struct
  {
    uint8_t RESERVED0[4];
    volatile uint32_t RESULT;
    uint8_t RESERVED1[120];
    union
    {
      volatile uint32_t DATA32;
      volatile uint16_t DATA16;
      volatile uint8_t DATA8;
    };
  } M0P_CRC_TypeDef;

#define M0P_CRC ((M0P_CRC_TypeDef *)0x40020900UL)
#ifdef __cplusplus
}
#endif

#endif
