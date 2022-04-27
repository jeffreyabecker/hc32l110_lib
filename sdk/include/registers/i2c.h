#ifndef __HC32L110_REGISTERS_I2C_H__
#define __HC32L110_REGISTERS_I2C_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

typedef struct
{
    volatile uint32_t H1M : 1;
    uint32_t RESERVED1 : 1;
    volatile uint32_t AA : 1;
    volatile uint32_t SI : 1;
    volatile uint32_t STO : 1;
    volatile uint32_t STA : 1;
    volatile uint32_t ENS : 1;
} i2c_cr_field_t;

typedef struct
{
    volatile uint32_t enable_broadcast_reply : 1;
    volatile uint32_t address : 7;
} i2c_addr_field_t;

typedef struct
{

    volatile uint32_t enable_clock; // TMRUN
    volatile uint32_t clock_scaler; // TM
    i2c_cr_field_t CR;
    volatile uint32_t DATA;
    i2c_addr_field_t ADDR;
    volatile uint32_t status; // STA

} hc32_i2c_register_t;
#ifdef __cplusplus
}
#endif
#define HC32_I2C ((hc32_i2c_register_t *)0x40000400UL)
#endif
