#ifndef __SYSTEM_HC32L110_DDL_RTC_H__
#define __SYSTEM_HC32L110_DDL_RTC_H__
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

void peripheral_enable_i2c(i2c_on_port_t on_port);


typedef struct
{
    uint8_t success : 1;
    uint8_t recieved_ack : 1;
    uint8_t status : 8;
    uint8_t bytes_processed : 8;

} i2c_controller_result_t;

i2c_controller_result_t i2c_controller_write(uint8_t recipient, const uint8_t *data, uint8_t length, uint8_t send_stop);
i2c_controller_result_t i2c_controller_read(uint8_t recipient, uint8_t *data, uint8_t length, uint8_t send_stop);

#endif