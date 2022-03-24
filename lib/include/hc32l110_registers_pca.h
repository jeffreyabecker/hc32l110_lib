#ifndef __HC32L110_REGISTERS_PCA_H__
#define __HC32L110_REGISTERS_PCA_H__

#include <stdint.h>

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
} pca_ccon_field_t;

typedef struct
{
    volatile uint32_t CFIE : 1;
    volatile uint32_t CPS : 3;
    uint32_t RESERVED4 : 2;
    volatile uint32_t WDTE : 1;
    volatile uint32_t CIDL : 1;
} pca_cmod_field_t;

typedef struct
{
    volatile uint32_t CCF0 : 1;
    volatile uint32_t CCF1 : 1;
    volatile uint32_t CCF2 : 1;
    volatile uint32_t CCF3 : 1;
    volatile uint32_t CCF4 : 1;
    uint32_t RESERVED5 : 2;
    volatile uint32_t CF : 1;
} pca_iclr_field_t;

typedef struct
{
    volatile uint32_t CCIE : 1;
    volatile uint32_t PWM : 1;
    volatile uint32_t TOG : 1;
    volatile uint32_t MAT : 1;
    volatile uint32_t CAPN : 1;
    volatile uint32_t CAPP : 1;
    volatile uint32_t ECOM : 1;
} pca_ccapmx_field_t;

typedef struct
{
    union
    {
        volatile uint32_t CCON;
        pca_ccon_field_t CCON_f;
    };
    union
    {
        volatile uint32_t CMOD;
        pca_cmod_field_t CMOD_f;
    };

    volatile uint32_t CNT;

    union
    {
        volatile uint32_t ICLR;
        pca_iclr_field_t ICLR_f;
    };

} HC32_PCA_TypeDef;
#define HC32_PCA ((HC32_PCA_TypeDef *)0x40001000UL)
typedef struct
{
    uint32_t H;
    uint32_t L;
} pca_capture_high_low_list_t[5];
typedef uint32_t pca_capture_list_t[5];
typedef pca_ccapmx_field_t pca_mode_list_t[5];

#define HC32_PCA_MODE
#define HC32_PCA_MODULE_MODES ((pca_mode_list_t *)0x40001010UL)
#define HC32_PCA_CAPTURE_HIGH_LOW ((pca_capture_high_low_list_t *)0x40001024UL)
#define HC32_PCA_CAPTURE (((pca_capture_list_t) *)0x40001050UL)
#define HC32_PCA_HIGHSPEED_OUTPUT ((uint32_t *)0x4000104CUL)
typedef enum
{
    pcap4_source_pca_chx = 0,
    pcap4_source_uart0_rxd = 1,
    pcap4_source_uart1_rxd = 2,
    pcap4_source_lpuart_rxd = 3
} pca_capture_source_t;

typedef pca_capture_source_t pca_capture_source_list_t[5];

#define HC32_PCA_CAPTURE_SOURCE ((pca_capture_source_list_t *)0x40020F08UL)

#endif
