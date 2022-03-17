#ifndef __HC32L110_REGISTERS_LVD_H__
#define __HC32L110_REGISTERS_LVD_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

#include "hc32l110_registers_platform.h"

    typedef struct
    {
        volatile uint32_t LVDEN : 1;
        volatile uint32_t ACT : 1;
        volatile uint32_t SOURCE_SEL : 2;
        volatile uint32_t VTDS : 4;
        volatile uint32_t FLTEN : 1;
        volatile uint32_t DEBOUNCE_TIME : 3;
        volatile uint32_t FTEN : 1;
        volatile uint32_t RTEN : 1;
        volatile uint32_t HTEN : 1;
        volatile uint32_t IE : 1;
    } stc_lvd_cr_field_t;

    typedef struct
    {
        uint8_t RESERVED0[40];
        stc_lvd_cr_field_t CR;
        volatile uint32_t IFR;
    } M0P_LVD_TypeDef;

    typedef struct
    {
        volatile uint32_t DIV : 6;
        volatile uint32_t DIV_EN : 1;
        volatile uint32_t REF2P5_SEL : 1;
        volatile uint32_t VC0_BIAS_SEL : 2;
        volatile uint32_t VC0_HYS_SEL : 2;
        volatile uint32_t VC1_BIAS_SEL : 2;
        volatile uint32_t VC1_HYS_SEL : 2;
    } stc_vc_cr_field_t;

    typedef struct
    {
        volatile uint32_t EN : 1;
        volatile uint32_t P_SEL : 3;
        volatile uint32_t N_SEL : 4;
        volatile uint32_t FLTEN : 1;
        volatile uint32_t DEBOUNCE_TIME : 3;
        volatile uint32_t FALLING : 1;
        volatile uint32_t RISING : 1;
        volatile uint32_t LEVEL : 1;
        volatile uint32_t IE : 1;
    } stc_vc_vcx_cr_field_t;

    typedef struct
    {
        volatile uint32_t INV_TIMER : 1;
        volatile uint32_t TIM0G : 1;
        volatile uint32_t TIM1G : 1;
        volatile uint32_t TIM2G : 1;
        volatile uint32_t TIM3G : 1;
        volatile uint32_t TIM3ECLK : 1;
        volatile uint32_t INV_PCA : 1;
        volatile uint32_t PCACAP0 : 1;
        volatile uint32_t PCAECI : 1;
        volatile uint32_t INV_TIM4 : 1;
        volatile uint32_t TIM4 : 1;
        volatile uint32_t INV_TIM5 : 1;
        volatile uint32_t TIM5 : 1;
        volatile uint32_t INV_TIM6 : 1;
        volatile uint32_t TIM6 : 1;
        volatile uint32_t BRAKE : 1;
    } stc_vc_vcx_out_cfg_field_t;

    typedef struct
    {
        volatile uint32_t VC0_INTF : 1;
        volatile uint32_t VC1_INTF : 1;
        volatile uint32_t VC0_FILTER : 1;
        volatile uint32_t VC1_FILTER : 1;
    } stc_vc_ifr_field_t;

    typedef struct
    {
        uint8_t RESERVED0[16];
        stc_vc_cr_field_t CR;
        stc_vc_vcx_cr_field_t VC0_CR;
        stc_vc_vcx_cr_field_t VC1_CR;
        stc_vc_vcx_out_cfg_field_t VC0_OUT_CFG;
        stc_vc_vcx_out_cfg_field_t VC1_OUT_CFG;
        stc_vc_ifr_field_t IFR;

    } M0P_VC_TypeDef;

#define M0P_LVD ((M0P_LVD_TypeDef *)0x40002400UL)
#define M0P_VC ((M0P_VC_TypeDef *)0x40002400UL)

#ifdef __cplusplus
}
#endif

#endif
