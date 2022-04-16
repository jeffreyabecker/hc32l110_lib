#ifndef __SYSTEM_HC32L110_DDL_I2C_H__
#define __SYSTEM_HC32L110_DDL_I2C_H__
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
    i2c_event_type_none = 0,
    i2c_event_type_write_recieved = 1,
    i2c_event_type_read_recieved = 2,
    i2c_event_type_arbitration_lost = 3,
    i2c_event_type_start_condition = 4,
    i2c_event_type_stop_condition = 5,
    i2c_event_type_data_recieved = 6,
    i2c_event_type_data_transmitted = 7,
    i2c_event_type_start_sent = 8,
    i2c_event_type_repeat_start_sent = 9,
    i2c_event_type_stop_sent = 9,
    i2c_event_type_write_address_sent = 11,
    i2c_event_type_read_address_sent = 12,
} i2c_event_type_t;
typedef enum
{
    i2c_addressing_type_self = 0,
    i2c_addressing_type_broadcast = 1,
    i2c_addressing_type_controller = 2,
} i2c_addressing_type_t;
typedef struct
{
    i2c_event_type_t type : 8;
    i2c_addressing_type_t at_address : 8;
    uint8_t acked : 8;
    uint8_t data;
} i2c_event_t;
typedef void (*i2c_event_handler_t)(i2c_event_t event);
void peripheral_enable_i2c(i2c_on_port_t on_port, uint32_t bus_freqency_hz);
i2c_event_t i2c_decode_event(uint8_t status, uint8_t data);
#define i2c_get_event() i2c_decode_event(HC32_I2C->status, HC32_I2C->DATA)

#define i2c_has_irq() HC32_I2C->CR.SI
#define i2c_clear_irq() HC32_I2C->CR.SI = 0
void i2c_event_handler_set(i2c_event_handler_t handler, uint8_t enabled);

typedef struct
{
    uint8_t status;
    uint8_t success;
    uint8_t recieved_ack;
    uint8_t bytes_processed;

} i2c_controller_result_t;

i2c_controller_result_t i2c_controller_write(uint8_t peripheral, const uint8_t *data, uint8_t length, uint8_t send_stop);
i2c_controller_result_t i2c_controller_read(uint8_t peripheral, uint8_t *data, uint8_t length, uint8_t send_stop);
#endif