#ifndef __HC32L110_REGISTERS_MEMORY_H__
#define __HC32L110_REGISTERS_MEMORY_H__

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
        volatile uint32_t OP : 2;
        volatile uint32_t WAIT : 1;
        uint32_t RESERVED3 : 1;
        volatile uint32_t BUSY : 1;
        volatile uint32_t IE : 2;
    } stc_flash_cr_field_t;

    typedef struct
    {
        volatile uint32_t IF0 : 1;
        volatile uint32_t IF1 : 1;
    } stc_flash_ifr_field_t;

    typedef struct
    {
        volatile uint32_t ICLR0 : 1;
        volatile uint32_t ICLR1 : 1;
    } stc_flash_iclr_field_t;

    typedef struct
    {
        volatile uint32_t TNVS;
        volatile uint32_t TPGS;
        volatile uint32_t TPROG;
        volatile uint32_t TSERASE;
        volatile uint32_t TMERASE;
        volatile uint32_t TPRCV;
        volatile uint32_t TSRCV;
        volatile uint32_t TMRCV;
        stc_flash_cr_field_t CR;
        stc_flash_ifr_field_t IFR;
        stc_flash_iclr_field_t ICLR;
        volatile uint32_t BYPASS;
        volatile uint32_t SLOCK;
    } M0P_FLASH_TypeDef;
    typedef struct
    {
        volatile uint32_t CHKEN : 1;
        volatile uint32_t IE : 1;
    } stc_ram_cr_field_t;
    typedef struct
    {
        stc_ram_cr_field_t CR;
        volatile uint32_t ERRADDR;
        volatile uint32_t IFR;
        volatile uint32_t ICLR;
    } M0P_RAM_TypeDef;

#define M0P_FLASH ((M0P_FLASH_TypeDef *)0x40020000UL)
#define M0P_RAM ((M0P_RAM_TypeDef *)0x40020400UL)    
#ifdef __cplusplus
}
#endif

#endif
