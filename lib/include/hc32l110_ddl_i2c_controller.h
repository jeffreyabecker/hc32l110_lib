#ifndef __SYSTEM_HC32L110_DDL_I2C_CONTROLLER_H__
#define __SYSTEM_HC32L110_DDL_I2C_CONTROLLER_H__
#include "hc32l110_cmsis.h"
#include "hc32l110_system.h"
#include "hc32l110_ddl_i2c_common.h"




typedef struct
{
    uint8_t success : 1;
    uint8_t recieved_ack : 1;
    uint8_t status : 8;
    uint8_t bytes_processed : 8;

} i2c_controller_result_t;

i2c_controller_result_t i2c_controller_write(uint8_t peripheral, const uint8_t *data, uint8_t length, uint8_t send_stop);
i2c_controller_result_t i2c_controller_read(uint8_t peripheral, uint8_t *data, uint8_t length, uint8_t send_stop);

#endif