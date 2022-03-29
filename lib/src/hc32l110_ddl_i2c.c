#include "hc32l110_ddl_i2c.h"
#include "hc32l110_ddl_buffers.h"
#include "hc32l110_ddl_gpio.h"
#include "hc32l110_ddl_core.h"

typedef struct
{
    gpio_port_descriptor_t *sda;
    gpio_port_descriptor_t *scl;
    uint8_t function;
} gpio_i2c_cfg_lookup_t;

typedef enum
{
    i2c_operation_read = 1,
    i2c_operation_write = 0,
} i2c_operation_t;

__read_only_data static gpio_i2c_cfg_lookup_t __port_configs[4] = {
    {.sda = gpio_port_p01, .scl = gpio_port_p02, .function = 2},
    {.sda = gpio_port_p15, .scl = gpio_port_p14, .function = 1},
    {.sda = gpio_port_p25, .scl = gpio_port_p26, .function = 6},
    {.sda = gpio_port_p35, .scl = gpio_port_p36, .function = 7},
};
__read_only_data static gpio_port_config_t i2c_port_setup = {
    .direction = gpio_output,
    .resolution = gpio_digital,
    .drive_mode = gpio_drive_high,
    .pull_up = gpio_pullup_enable,
    .pull_down = gpio_pulldown_disable,
    .gpio_mode = gpio_mode_open_drain,
};
void peripheral_enable_i2c(i2c_on_port_t on_port)
{
    if (on_port > 3)
    {
        return;
    }
    peripheral_set_enabled(peripheral_get_enabled() | peripheral_i2c);
    gpio_port_config_t cfg = i2c_port_setup;
    cfg.function = __port_configs[on_port].function;
    gpio_configure(__port_configs[on_port].sda, cfg);
    gpio_configure(__port_configs[on_port].scl, cfg);

    HC32_I2C->CR.ENS = 1;
}
#define i2c_operation_complete() HC32_I2C->CR.SI
#define i2c_get_status() HC32_I2C->status
static uint8_t i2c_wait()
{
    while (!i2c_operation_complete())
    {
        __NOP();
    }
    return i2c_get_status();
}

__STATIC_FORCEINLINE i2c_controller_result_t i2c_controller_result(uint8_t status, uint8_t success, uint8_t recieved_ack, uint8_t bytes_processed)
{
    i2c_controller_result_t result = {
        .recieved_ack = (recieved_ack ? 1 : 0),
        .status = status,
        .success = recieved_ack,
        .bytes_processed = bytes_processed};
    return result;
}

static i2c_controller_result_t i2c_controller_send_start()
{
    HC32_I2C->CR.SI = 0;
    HC32_I2C->CR.STA = 1;
    uint8_t status = i2c_wait();
    return i2c_controller_result(status, (status == 0x08 || status == 0x10), (status == 0x08 || status == 0x10), 0);
}
static void i2c_controller_send_stop()
{
    HC32_I2C->CR.STO = 1;
    HC32_I2C->CR.SI = 0;
    i2c_wait();
}
static i2c_controller_result_t i2c_controller_send_address(uint8_t recipient, i2c_operation_t operation)
{
    HC32_I2C->DATA = recipient << 1 | operation;
    HC32_I2C->CR.STA = 0;
    HC32_I2C->CR.SI = 0;
    uint8_t status = i2c_wait();
    if (operation == i2c_operation_write)
    {
        return i2c_controller_result(status, (status == 0x18 || status == 0x20), (status == 0x18), 0);
    }
    else
    {
        return i2c_controller_result(status, (status == 0x40 || status == 0x48), (status == 0x40), 0);
    }
}

i2c_controller_result_t i2c_controller_write(uint8_t recipient, const uint8_t *data, uint8_t length, uint8_t send_stop)
{
    i2c_controller_result_t result;
    uint8_t bytes_processed;
    result = i2c_controller_send_start();
    if (!result.success)
    {
        return result;
    }
    result = i2c_controller_send_address(recipient, i2c_operation_write);
    if (!result.success)
    {
        return result;
    }
    for (uint8_t i = 0; i < length; i++)
    {
        HC32_I2C->DATA = data[i];
        HC32_I2C->CR.SI = 0;
        uint8_t status = i2c_wait();
        result = i2c_controller_result(status, (status == 0x28 || status == 0x30), (status == 0x28), (status == 0x28) ? 1 : 0);
        if (!result.success || !result.recieved_ack)
        {
            result.success = 0;
            result.bytes_processed = bytes_processed;
            return result;
        }
        else
        {
            bytes_processed++;
        }
    }
    if (send_stop)
    {
        i2c_controller_send_stop();
    }
    result.bytes_processed = bytes_processed;
    return result;
}
i2c_controller_result_t i2c_controller_read(uint8_t recipient, uint8_t *data, uint8_t length, uint8_t send_stop)
{
    i2c_controller_result_t result;
    uint8_t bytes_processed;
    result = i2c_controller_send_start();
    if (!result.success)
    {
        return result;
    }
    result = i2c_controller_send_address(recipient, i2c_operation_read);
    if (!result.success)
    {
        return result;
    }
    for (uint8_t i = 0; i < length; i++)
    {
        HC32_I2C->CR.AA = (i < length - 1 ? 1 : 0);
        HC32_I2C->CR.SI = 0;
        uint8_t status = i2c_wait();
        result = i2c_controller_result(status, (result.status == 0x50 || result.status == 0x58), HC32_I2C->CR.AA, bytes_processed);
        if (result.success)
        {
            bytes_processed++;
        }
        else
        {
            return result;
        }
    }
    if (send_stop)
    {
        i2c_controller_send_stop();
    }
    result.bytes_processed = bytes_processed;
    return result;
}


//TODO: this chip supports an i2c peripheral mode as well. It'd be neat to set up a ring-buffer & event driven api using the interrupt handlers