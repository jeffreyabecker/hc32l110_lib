#ifndef __HC32L110_REGISTERS_ADVANCED_TIMERS_H__
#define __HC32L110_REGISTERS_ADVANCED_TIMERS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

#include "hc32l110_registers_platform.h"

  typedef struct
  {
    volatile uint32_t START : 1;
    volatile uint32_t MODE : 3;
    volatile uint32_t CKDIV : 3;
    uint32_t RESERVED7 : 1;
    volatile uint32_t DIR : 1;
    uint32_t RESERVED9 : 7;
    volatile uint32_t ZMSKREV : 1;
    volatile uint32_t ZMSKPOS : 1;
    volatile uint32_t ZMSK : 2;
  } stc_adt_gconr_field_t;

  typedef struct
  {
    volatile uint32_t INTENA : 1;
    volatile uint32_t INTENB : 1;
    volatile uint32_t INTENC : 1;
    volatile uint32_t INTEND : 1;
    uint32_t RESERVED4 : 2;
    volatile uint32_t INTENOVF : 1;
    volatile uint32_t INTENUDF : 1;
    volatile uint32_t INTENDE : 1;
  } stc_adt_iconr_field_t;

  typedef struct
  {
    volatile uint32_t CAPCA : 1;
    volatile uint32_t STACA : 1;
    volatile uint32_t STPCA : 1;
    volatile uint32_t STASTPSA : 1;
    volatile uint32_t CMPCA : 2;
    volatile uint32_t PERCA : 2;
    volatile uint32_t OUTENA : 1;
    volatile uint32_t DISSELA : 2;
    volatile uint32_t DISVALA : 2;
    uint32_t RESERVED13 : 3;
    volatile uint32_t CAPCB : 1;
    volatile uint32_t STACB : 1;
    volatile uint32_t STPCB : 1;
    volatile uint32_t STASTPSB : 1;
    volatile uint32_t CMPCB : 2;
    volatile uint32_t PERCB : 2;
    volatile uint32_t OUTENB : 1;
    volatile uint32_t DISSELB : 2;
    volatile uint32_t DISVALB : 2;
  } stc_adt_pconr_field_t;

  typedef struct
  {
    volatile uint32_t BENA : 1;
    uint32_t RESERVED1 : 1;
    volatile uint32_t BENB : 1;
    uint32_t RESERVED3 : 5;
    volatile uint32_t BENP : 1;
  } stc_adt_bconr_field_t;

  typedef struct
  {
    volatile uint32_t DTCEN : 1;
    uint32_t RESERVED1 : 7;
    volatile uint32_t SEPA : 1;
  } stc_adt_dconr_field_t;

  typedef struct
  {
    volatile uint32_t NOFIENGA : 1;
    volatile uint32_t NOFICKGA : 2;
    uint32_t RESERVED3 : 1;
    volatile uint32_t NOFIENGB : 1;
    volatile uint32_t NOFICKGB : 2;
    uint32_t RESERVED7 : 9;
    volatile uint32_t NOFIENTA : 1;
    volatile uint32_t NOFICKTA : 2;
    uint32_t RESERVED19 : 1;
    volatile uint32_t NOFIENTB : 1;
    volatile uint32_t NOFICKTB : 2;
    uint32_t RESERVED23 : 1;
    volatile uint32_t NOFIENTC : 1;
    volatile uint32_t NOFICKTC : 2;
    uint32_t RESERVED27 : 1;
    volatile uint32_t NOFIENTD : 1;
    volatile uint32_t NOFICKTD : 2;
  } stc_adt_fconr_field_t;

  typedef struct
  {
    volatile uint32_t GEPERIA : 1;
    volatile uint32_t GEPERIB : 1;
    volatile uint32_t GEPERIC : 1;
    volatile uint32_t GEPERID : 1;
    uint32_t RESERVED4 : 12;
    volatile uint32_t PCNTE : 2;
    volatile uint32_t PCNTS : 3;
  } stc_adt_vperr_field_t;

  typedef struct
  {
    volatile uint32_t CMAF : 1;
    volatile uint32_t CMBF : 1;
    volatile uint32_t CMCF : 1;
    volatile uint32_t CMDF : 1;
    uint32_t RESERVED4 : 2;
    volatile uint32_t OVFF : 1;
    volatile uint32_t UDFF : 1;
    volatile uint32_t DTEF : 1;
    uint32_t RESERVED9 : 12;
    volatile uint32_t VPERNUM : 3;
    uint32_t RESERVED24 : 7;
    volatile uint32_t DIRF : 1;
  } stc_adt_stflr_field_t;

  typedef struct
  {
    volatile uint32_t HSTA0 : 1;
    volatile uint32_t HSTA1 : 1;
    volatile uint32_t HSTA2 : 1;
    volatile uint32_t HSTA3 : 1;
    volatile uint32_t HSTA4 : 1;
    volatile uint32_t HSTA5 : 1;
    volatile uint32_t HSTA6 : 1;
    volatile uint32_t HSTA7 : 1;
    volatile uint32_t HSTA8 : 1;
    volatile uint32_t HSTA9 : 1;
    volatile uint32_t HSTA10 : 1;
    volatile uint32_t HSTA11 : 1;
    volatile uint32_t HSTA12 : 1;
    volatile uint32_t HSTA13 : 1;
    volatile uint32_t HSTA14 : 1;
    volatile uint32_t HSTA15 : 1;
    uint32_t RESERVED16 : 15;
    volatile uint32_t STARTS : 1;
  } stc_adt_hstar_field_t;

  typedef struct
  {
    volatile uint32_t HSTP0 : 1;
    volatile uint32_t HSTP1 : 1;
    volatile uint32_t HSTP2 : 1;
    volatile uint32_t HSTP3 : 1;
    volatile uint32_t HSTP4 : 1;
    volatile uint32_t HSTP5 : 1;
    volatile uint32_t HSTP6 : 1;
    volatile uint32_t HSTP7 : 1;
    volatile uint32_t HSTP8 : 1;
    volatile uint32_t HSTP9 : 1;
    volatile uint32_t HSTP10 : 1;
    volatile uint32_t HSTP11 : 1;
    volatile uint32_t HSTP12 : 1;
    volatile uint32_t HSTP13 : 1;
    volatile uint32_t HSTP14 : 1;
    volatile uint32_t HSTP15 : 1;
    uint32_t RESERVED16 : 15;
    volatile uint32_t STOPS : 1;
  } stc_adt_hstpr_field_t;

  typedef struct
  {
    volatile uint32_t HCEL0 : 1;
    volatile uint32_t HCEL1 : 1;
    volatile uint32_t HCEL2 : 1;
    volatile uint32_t HCEL3 : 1;
    volatile uint32_t HCEL4 : 1;
    volatile uint32_t HCEL5 : 1;
    volatile uint32_t HCEL6 : 1;
    volatile uint32_t HCEL7 : 1;
    volatile uint32_t HCEL8 : 1;
    volatile uint32_t HCEL9 : 1;
    volatile uint32_t HCEL10 : 1;
    volatile uint32_t HCEL11 : 1;
    volatile uint32_t HCEL12 : 1;
    volatile uint32_t HCEL13 : 1;
    volatile uint32_t HCEL14 : 1;
    volatile uint32_t HCEL15 : 1;
    uint32_t RESERVED16 : 15;
    volatile uint32_t CLEARS : 1;
  } stc_adt_hcelr_field_t;

  typedef struct
  {
    volatile uint32_t HCPA0 : 1;
    volatile uint32_t HCPA1 : 1;
    volatile uint32_t HCPA2 : 1;
    volatile uint32_t HCPA3 : 1;
    volatile uint32_t HCPA4 : 1;
    volatile uint32_t HCPA5 : 1;
    volatile uint32_t HCPA6 : 1;
    volatile uint32_t HCPA7 : 1;
    volatile uint32_t HCPA8 : 1;
    volatile uint32_t HCPA9 : 1;
    volatile uint32_t HCPA10 : 1;
    volatile uint32_t HCPA11 : 1;
    volatile uint32_t HCPA12 : 1;
    volatile uint32_t HCPA13 : 1;
    volatile uint32_t HCPA14 : 1;
    volatile uint32_t HCPA15 : 1;
  } stc_adt_hcpar_field_t;

  typedef struct
  {
    volatile uint32_t HCPB0 : 1;
    volatile uint32_t HCPB1 : 1;
    volatile uint32_t HCPB2 : 1;
    volatile uint32_t HCPB3 : 1;
    volatile uint32_t HCPB4 : 1;
    volatile uint32_t HCPB5 : 1;
    volatile uint32_t HCPB6 : 1;
    volatile uint32_t HCPB7 : 1;
    volatile uint32_t HCPB8 : 1;
    volatile uint32_t HCPB9 : 1;
    volatile uint32_t HCPB10 : 1;
    volatile uint32_t HCPB11 : 1;
    volatile uint32_t HCPB12 : 1;
    volatile uint32_t HCPB13 : 1;
    volatile uint32_t HCPB14 : 1;
    volatile uint32_t HCPB15 : 1;
  } stc_adt_hcpbr_field_t;

  typedef struct
  {
    volatile uint32_t HCUP0 : 1;
    volatile uint32_t HCUP1 : 1;
    volatile uint32_t HCUP2 : 1;
    volatile uint32_t HCUP3 : 1;
    volatile uint32_t HCUP4 : 1;
    volatile uint32_t HCUP5 : 1;
    volatile uint32_t HCUP6 : 1;
    volatile uint32_t HCUP7 : 1;
    volatile uint32_t HCUP8 : 1;
    volatile uint32_t HCUP9 : 1;
    volatile uint32_t HCUP10 : 1;
    volatile uint32_t HCUP11 : 1;
    volatile uint32_t HCUP12 : 1;
    volatile uint32_t HCUP13 : 1;
    volatile uint32_t HCUP14 : 1;
    volatile uint32_t HCUP15 : 1;
    volatile uint32_t HCUP16 : 1;
    volatile uint32_t HCUP17 : 1;
    volatile uint32_t HCUP18 : 1;
    volatile uint32_t HCUP19 : 1;
  } stc_adt_hcupr_field_t;

  typedef struct
  {
    volatile uint32_t HCDO0 : 1;
    volatile uint32_t HCDO1 : 1;
    volatile uint32_t HCDO2 : 1;
    volatile uint32_t HCDO3 : 1;
    volatile uint32_t HCDO4 : 1;
    volatile uint32_t HCDO5 : 1;
    volatile uint32_t HCDO6 : 1;
    volatile uint32_t HCDO7 : 1;
    volatile uint32_t HCDO8 : 1;
    volatile uint32_t HCDO9 : 1;
    volatile uint32_t HCDO10 : 1;
    volatile uint32_t HCDO11 : 1;
    volatile uint32_t HCDO12 : 1;
    volatile uint32_t HCDO13 : 1;
    volatile uint32_t HCDO14 : 1;
    volatile uint32_t HCDO15 : 1;
    volatile uint32_t HCDO16 : 1;
    volatile uint32_t HCDO17 : 1;
    volatile uint32_t HCDO18 : 1;
    volatile uint32_t HCDO19 : 1;
  } stc_adt_hcdor_field_t;

  typedef struct
  {
    volatile uint32_t CMAF : 1;
    volatile uint32_t CMBF : 1;
    volatile uint32_t CMCF : 1;
    volatile uint32_t CMDF : 1;
    uint32_t RESERVED4 : 2;
    volatile uint32_t OVFF : 1;
    volatile uint32_t UDFF : 1;
    volatile uint32_t DTEF : 1;
    uint32_t RESERVED9 : 5;
    volatile uint32_t SAMLF : 1;
    volatile uint32_t SAMHF : 1;
  } stc_adt_ifr_field_t;

  typedef struct
  {
    volatile uint32_t CMAC : 1;
    volatile uint32_t CMBC : 1;
    volatile uint32_t CMCC : 1;
    volatile uint32_t CMDC : 1;
    uint32_t RESERVED4 : 2;
    volatile uint32_t OVFC : 1;
    volatile uint32_t UDFC : 1;
    volatile uint32_t DTEC : 1;
    uint32_t RESERVED9 : 5;
    volatile uint32_t SAMLC : 1;
    volatile uint32_t SAMHC : 1;
  } stc_adt_iclr_field_t;

  typedef struct
  {
    volatile uint32_t CMAE : 1;
    volatile uint32_t CMBE : 1;
    volatile uint32_t CMCE : 1;
    volatile uint32_t CMDE : 1;
    uint32_t RESERVED4 : 2;
    volatile uint32_t OVFE : 1;
    volatile uint32_t UDFE : 1;
    volatile uint32_t DITENA : 1;
    volatile uint32_t DITENB : 1;
    volatile uint32_t DITENS : 1;
  } stc_adt_cr_field_t;

  typedef struct
  {
    volatile uint32_t FBRAKE : 1;
    volatile uint32_t FSAME : 1;
    volatile uint32_t BFILTS : 2;
    volatile uint32_t BFILTEN : 1;
    uint32_t RESERVED5 : 2;
    volatile uint32_t SOFTBK : 1;
    volatile uint32_t SML0 : 1;
    volatile uint32_t SML1 : 1;
    volatile uint32_t SML2 : 1;
    volatile uint32_t SMH0 : 1;
    volatile uint32_t SMH1 : 1;
    volatile uint32_t SMH2 : 1;
  } stc_adt_aossr_field_t;

  typedef struct
  {
    volatile uint32_t FBRAKE : 1;
    volatile uint32_t FSAME : 1;
  } stc_adt_aoscl_field_t;

  typedef struct
  {
    volatile uint32_t EN0 : 1;
    volatile uint32_t EN1 : 1;
    volatile uint32_t EN2 : 1;
    volatile uint32_t EN3 : 1;
    volatile uint32_t EN4 : 1;
    volatile uint32_t EN5 : 1;
    volatile uint32_t EN6 : 1;
    volatile uint32_t EN7 : 1;
    volatile uint32_t EN8 : 1;
    volatile uint32_t EN9 : 1;
    volatile uint32_t EN10 : 1;
    volatile uint32_t EN11 : 1;
    volatile uint32_t EN12 : 1;
    volatile uint32_t EN13 : 1;
    volatile uint32_t EN14 : 1;
    volatile uint32_t EN15 : 1;
  } stc_adt_ptbks_field_t;

  typedef struct
  {
    volatile uint32_t TRIGAS : 4;
    volatile uint32_t TRIGBS : 4;
    volatile uint32_t TRIGCS : 4;
    volatile uint32_t TRIGDS : 4;
  } stc_adt_ttrig_field_t;

  typedef struct
  {
    volatile uint32_t IAOS0S : 4;
    volatile uint32_t IAOS1S : 4;
    volatile uint32_t IAOS2S : 4;
    volatile uint32_t IAOS3S : 4;
  } stc_adt_itrig_field_t;

  typedef struct
  {
    volatile uint32_t POL0 : 1;
    volatile uint32_t POL1 : 1;
    volatile uint32_t POL2 : 1;
    volatile uint32_t POL3 : 1;
    volatile uint32_t POL4 : 1;
    volatile uint32_t POL5 : 1;
    volatile uint32_t POL6 : 1;
    volatile uint32_t POL7 : 1;
    volatile uint32_t POL8 : 1;
    volatile uint32_t POL9 : 1;
    volatile uint32_t POL10 : 1;
    volatile uint32_t POL11 : 1;
    volatile uint32_t POL12 : 1;
    volatile uint32_t POL13 : 1;
    volatile uint32_t POL14 : 1;
    volatile uint32_t POL15 : 1;
  } stc_adt_ptbkp_field_t;

  typedef struct
  {
    volatile uint32_t SSTA0 : 1;
    volatile uint32_t SSTA1 : 1;
    volatile uint32_t SSTA2 : 1;
  } stc_adt_sstar_field_t;

  typedef struct
  {
    volatile uint32_t SSTP0 : 1;
    volatile uint32_t SSTP1 : 1;
    volatile uint32_t SSTP2 : 1;
  } stc_adt_sstpr_field_t;

  typedef struct
  {
    volatile uint32_t SCLR0 : 1;
    volatile uint32_t SCLR1 : 1;
    volatile uint32_t SCLR2 : 1;
  } stc_adt_sclrr_field_t;

  typedef struct
  {
    volatile uint32_t CNTER;
    volatile uint32_t PERAR;
    volatile uint32_t PERBR;
    uint8_t RESERVED3[4];
    volatile uint32_t GCMAR;
    volatile uint32_t GCMBR;
    volatile uint32_t GCMCR;
    volatile uint32_t GCMDR;
    uint8_t RESERVED7[32];
    volatile uint32_t DTUAR;
    volatile uint32_t DTDAR;
    uint8_t RESERVED9[8];
    union
    {
      volatile uint32_t GCONR;
      stc_adt_gconr_field_t GCONR_f;
    };
    union
    {
      volatile uint32_t ICONR;
      stc_adt_iconr_field_t ICONR_f;
    };
    union
    {
      volatile uint32_t PCONR;
      stc_adt_pconr_field_t PCONR_f;
    };
    union
    {
      volatile uint32_t BCONR;
      stc_adt_bconr_field_t BCONR_f;
    };
    union
    {
      volatile uint32_t DCONR;
      stc_adt_dconr_field_t DCONR_f;
    };
    uint8_t RESERVED14[4];
    union
    {
      volatile uint32_t FCONR;
      stc_adt_fconr_field_t FCONR_f;
    };
    union
    {
      volatile uint32_t VPERR;
      stc_adt_vperr_field_t VPERR_f;
    };
    union
    {
      volatile uint32_t STFLR;
      stc_adt_stflr_field_t STFLR_f;
    };
    union
    {
      volatile uint32_t HSTAR;
      stc_adt_hstar_field_t HSTAR_f;
    };
    union
    {
      volatile uint32_t HSTPR;
      stc_adt_hstpr_field_t HSTPR_f;
    };
    union
    {
      volatile uint32_t HCELR;
      stc_adt_hcelr_field_t HCELR_f;
    };
    union
    {
      volatile uint32_t HCPAR;
      stc_adt_hcpar_field_t HCPAR_f;
    };
    union
    {
      volatile uint32_t HCPBR;
      stc_adt_hcpbr_field_t HCPBR_f;
    };
    union
    {
      volatile uint32_t HCUPR;
      stc_adt_hcupr_field_t HCUPR_f;
    };
    union
    {
      volatile uint32_t HCDOR;
      stc_adt_hcdor_field_t HCDOR_f;
    };
    uint8_t RESERVED24[112];
    union
    {
      volatile uint32_t IFR;
      stc_adt_ifr_field_t IFR_f;
    };
    union
    {
      volatile uint32_t ICLR;
      stc_adt_iclr_field_t ICLR_f;
    };
    union
    {
      volatile uint32_t CR;
      stc_adt_cr_field_t CR_f;
    };
    uint8_t RESERVED27[4];
    union
    {
      volatile uint32_t AOSSR;
      stc_adt_aossr_field_t AOSSR_f;
    };
    union
    {
      volatile uint32_t AOSCL;
      stc_adt_aoscl_field_t AOSCL_f;
    };
    union
    {
      volatile uint32_t PTBKS;
      stc_adt_ptbks_field_t PTBKS_f;
    };
    union
    {
      volatile uint32_t TTRIG;
      stc_adt_ttrig_field_t TTRIG_f;
    };
    union
    {
      volatile uint32_t ITRIG;
      stc_adt_itrig_field_t ITRIG_f;
    };
    union
    {
      volatile uint32_t PTBKP;
      stc_adt_ptbkp_field_t PTBKP_f;
    };
    uint8_t RESERVED33[716];
    union
    {
      volatile uint32_t SSTAR;
      stc_adt_sstar_field_t SSTAR_f;
    };
    union
    {
      volatile uint32_t SSTPR;
      stc_adt_sstpr_field_t SSTPR_f;
    };
    union
    {
      volatile uint32_t SCLRR;
      stc_adt_sclrr_field_t SCLRR_f;
    };
  } M0P_AdvancedTimer_TypeDef;
#define M0P_ADT0 ((M0P_AdvancedTimer_TypeDef *)0x40003000UL)
#define M0P_ADT1 ((M0P_AdvancedTimer_TypeDef *)0x40003400UL)
#define M0P_ADT2 ((M0P_AdvancedTimer_TypeDef *)0x40003800UL)
#ifdef __cplusplus
}
#endif

#endif 
