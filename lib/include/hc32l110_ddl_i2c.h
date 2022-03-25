#ifndef __SYSTEM_HC32L110_DDL_RTC_H__
#define __SYSTEM_HC32L110_DDL_RTC_H__
#include "hc32l110_cmsis.h"
#include "hc32l110_system.h"
#include "hc32l110_registers_i2c.h"

void peripheral_enable_i2c();
typedef enum
{
    i2c_operation_read = 1,
    i2c_operation_write = 0,
} i2c_operation_t;
typedef enum
{
    i2c_mode_controller = 1,
    i2c_mode_peripheral = 0,
} i2c_mode_t;


#define i2c_operation_successful(x) ((x & 0x01) == 1)
#define i2c_operation_error(x) ((x >> 1))

#endif