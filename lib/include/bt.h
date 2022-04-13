#ifndef __BT__H__
#define __BT__H__
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
} hc32_basic_timer_control_flags_t;

typedef struct
{
    volatile uint32_t ARR;
    volatile uint32_t CNT;
    volatile uint32_t CNT32;
    union
    {
        volatile uint32_t CR;
        hc32_basic_timer_control_flags_t CR_f;
    };
    volatile uint32_t IFR;
    volatile uint32_t ICLR;

} hc32_basic_timer_t;

#define HC32_BASIC_TIMER0 ((hc32_basic_timer_t *)0x40000C00UL)
#define HC32_BASIC_TIMER1 ((hc32_basic_timer_t *)0x40000C20UL)
#define HC32_BASIC_TIMER2 ((hc32_basic_timer_t *)0x40000C40UL)

typedef struct
{
    volatile uint32_t TR : 1;
    volatile uint32_t MD : 1;
    volatile uint32_t CT : 1;
    volatile uint32_t TOG_EN : 1;
    volatile uint32_t TCK_SEL : 2;
    uint32_t RESERVED : 1;
    volatile uint32_t WT_FLAG : 1;
    volatile uint32_t GATE : 1;
    volatile uint32_t GATE_P : 1;
    volatile uint32_t IE : 1;
} lp_timer_cr_field_t;



typedef struct
{
    volatile uint32_t CNT;
    volatile uint32_t ARR;
    uint32_t RESERVED;
    union
    {
        volatile uint32_t CR;
        lp_timer_cr_field_t CR_f;
    };
    volatile uint32_t IFR;
    volatile uint32_t ICLR;
} hc32_low_power_timer_t;
#define HC32_LOW_POWER_TIMER ((hc32_low_power_timer_t *)0x40000C60UL)

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
    union
    {
        volatile uint32_t CCON_r;
        stc_pca_ccon_field_t CCON_f;
    };
    union
    {
        volatile uint32_t CMOD_r;
        stc_pca_cmod_field_t CMOD_f;
    };
    volatile uint32_t CNT;
    union
    {
        volatile uint32_t ICLR_r;
        stc_pca_iclr_field_t ICLR_f;
    };
    union
    {
        volatile uint32_t CCAPM0_r;
        stc_pca_ccapmx_field_t CCAPM0_f;
    };
    union
    {
        volatile uint32_t CCAPM1_r;
        stc_pca_ccapmx_field_t CCAPM1_f;
    };
    union
    {
        volatile uint32_t CCAPM2_r;
        stc_pca_ccapmx_field_t CCAPM2_f;
    };
    union
    {
        volatile uint32_t CCAPM3_r;
        stc_pca_ccapmx_field_t CCAPM3_f;
    };
    union
    {
        volatile uint32_t CCAPM4_r;
        stc_pca_ccapmx_field_t CCAPM4_f;
    };
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
    union
    {
        volatile uint32_t CCAPO_r;
        stc_pca_ccapo_field_t CCAPO_f;
    };
    volatile uint32_t CCAP0;
    volatile uint32_t CCAP1;
    volatile uint32_t CCAP2;
    volatile uint32_t CCAP3;
    volatile uint32_t CCAP4;
} hc32_capture_compare_register_t;

#define HC32_CAP_COMP ((hc32_capture_compare_register_t *)0x40001000UL)

#endif