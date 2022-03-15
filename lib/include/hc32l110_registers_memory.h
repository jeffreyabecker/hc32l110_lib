#ifndef __HC32L110_REGISTERS_MEMORY_H__
#define __HC32L110_REGISTERS_MEMORY_H__

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
        __IO uint32_t OP : 2;
        __IO uint32_t WAIT : 1;
        uint32_t RESERVED3 : 1;
        __IO uint32_t BUSY : 1;
        __IO uint32_t IE : 2;
    } stc_flash_cr_field_t;

    typedef struct
    {
        __IO uint32_t IF0 : 1;
        __IO uint32_t IF1 : 1;
    } stc_flash_ifr_field_t;

    typedef struct
    {
        __IO uint32_t ICLR0 : 1;
        __IO uint32_t ICLR1 : 1;
    } stc_flash_iclr_field_t;

    typedef struct
    {
        __IO uint32_t TNVS;
        __IO uint32_t TPGS;
        __IO uint32_t TPROG;
        __IO uint32_t TSERASE;
        __IO uint32_t TMERASE;
        __IO uint32_t TPRCV;
        __IO uint32_t TSRCV;
        __IO uint32_t TMRCV;
        stc_flash_cr_field_t CR;
        stc_flash_ifr_field_t IFR;
        stc_flash_iclr_field_t ICLR;
        __IO uint32_t BYPASS;
        __IO uint32_t SLOCK;
    } M0P_FLASH_TypeDef;
    typedef struct
    {
        __IO uint32_t CHKEN : 1;
        __IO uint32_t IE : 1;
    } stc_ram_cr_field_t;
    typedef struct
    {
        stc_ram_cr_field_t CR;
        __IO uint32_t ERRADDR;
        __IO uint32_t IFR;
        __O uint32_t ICLR;
    } M0P_RAM_TypeDef;

#define M0P_FLASH ((M0P_FLASH_TypeDef *)0x40020000UL)
#define M0P_RAM ((M0P_RAM_TypeDef *)0x40020400UL)    
#ifdef __cplusplus
}
#endif

#endif
