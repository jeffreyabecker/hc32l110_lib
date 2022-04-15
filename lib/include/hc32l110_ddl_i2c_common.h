#ifndef __SYSTEM_HC32L110_DDL_I2C_COMMON_H__
#define __SYSTEM_HC32L110_DDL_I2C_COMMON_H__
#include "hc32l110_cmsis.h"
#include "hc32l110_system.h"
#include "hc32l110_registers_i2c.h"

typedef enum
{
    i2c_on_port_0 = 0,
    i2c_on_port_1 = 1,
    i2c_on_port_2 = 2,
    i2c_on_port_3 = 3,
} i2c_on_port_t;

typedef enum
{
    i2c_operation_read = 1,
    i2c_operation_write = 0,
} i2c_operation_t;

void peripheral_enable_i2c(i2c_on_port_t on_port, uint32_t bus_freqency_hz);


#endif