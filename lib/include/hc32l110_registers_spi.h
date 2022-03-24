#ifndef __HC32L110_REGISTERS_SPI_H__
#define __HC32L110_REGISTERS_SPI_H__
#include <stdint.h>

typedef struct
{
    volatile uint32_t SPR0 : 1;
    volatile uint32_t SPR1 : 1;
    volatile uint32_t CPHA : 1;
    volatile uint32_t CPOL : 1;
    volatile uint32_t MODE : 1;
    uint32_t RESERVED5 : 1;
    volatile uint32_t SPEN : 1;
    volatile uint32_t SPR2 : 1;
} spi_cr_field_t;
typedef struct
{
    uint32_t RESERVED0 : 4;
    volatile uint32_t MDF : 1;
    volatile uint32_t SSERR : 1;
    volatile uint32_t WCOL : 1;
    volatile uint32_t SPIF : 1;
} spi_stat_field_t;

typedef struct
{
    union
    {
        volatile uint32_t CR;
        spi_cr_field_t CR_f;
    };
    volatile uint32_t SSN;
    union
    {
        volatile uint32_t STAT;
        spi_stat_field_t STAT_f;
    };
    volatile uint32_t DATA;

} hc32_spi_register_t;

#define HC32_SPI ((hc32_spi_register_t *)0x40000800UL)
#endif
