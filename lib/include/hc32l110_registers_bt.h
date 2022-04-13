#ifndef __HC32L110_REGISTERS_BT_H__
#define __HC32L110_REGISTERS_BT_H__

#include <stdint.h>

typedef struct
{
  volatile uint32_t TR : 1;
  volatile uint32_t MD : 1;
  volatile uint32_t CT : 1;
  volatile uint32_t TOG_EN : 1;
  volatile uint32_t PRS : 3;
  uint32_t RESERVED7 : 1;
  volatile uint32_t GATE : 1;
  volatile uint32_t GATE_P : 1;
  volatile uint32_t IE : 1;
} stc_bt_cr_field_t;

typedef struct
{
  volatile uint32_t ARR;
  volatile uint32_t CNT;
  volatile uint32_t CNT32;
  union
  {
    volatile uint32_t CR;
    stc_bt_cr_field_t CR_f;
  };
  volatile uint32_t IFR;
  volatile uint32_t ICLR;

} M0P_BT_TypeDef;

#define M0P_BT0 ((M0P_BT_TypeDef *)0x40000C00UL)
#define M0P_BT1 ((M0P_BT_TypeDef *)0x40000C20UL)
#define M0P_BT2 ((M0P_BT_TypeDef *)0x40000C40UL)
#endif
