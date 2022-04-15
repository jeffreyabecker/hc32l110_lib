#include "hc32l110_ddl_i2c_common.h"
#include "hc32l110_registers_clock.h"
#include "hc32l110_ddl_buffers.h"
#include "hc32l110_ddl_gpio.h"
#include "hc32l110_ddl_core.h"

typedef struct
{
    gpio_port_descriptor_t *sda;
    gpio_port_descriptor_t *scl;
    uint8_t function;
} gpio_i2c_cfg_lookup_t;

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
void peripheral_enable_i2c(i2c_on_port_t on_port, uint32_t bus_freqency_hz)
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
    HC32_RESET->PREI_RESET.I2C = 0;
    HC32_RESET->PREI_RESET.I2C = 1;
    HC32_I2C->clock_scaler = PeripheralCoreClock / (8 * bus_freqency_hz);
    HC32_I2C->CR.ENS = 1;
    HC32_I2C->enable_clock = 1;
}

i2c_event_t i2c_decode_event(uint8_t status, uint8_t data)
{
    switch (status)
    {
    case 0x08: // Start condition sent
        return (i2c_event_t){i2c_event_type_start_sent, i2c_addressing_type_controller, 0, data};
    case 0x10: // Repeated START sent
        return (i2c_event_t){i2c_event_type_repeat_start_sent, i2c_addressing_type_controller, 0, data};
    case 0x18: // SLA+W sent, ACK received
        return (i2c_event_t){i2c_event_type_write_address_sent, i2c_addressing_type_controller, 1, data};
    case 0x20: // SLA+W sent, non-ACK received
        return (i2c_event_t){i2c_event_type_write_address_sent, i2c_addressing_type_controller, 0, data};
    case 0x28: // Data in I2C_DATA has been sent, ACK has been received
        return (i2c_event_t){i2c_event_type_data_transmitted, i2c_addressing_type_controller, 1, data};
    case 0x30: // Data in I2C_DATA has been sent, non-ACK received
        return (i2c_event_t){i2c_event_type_data_transmitted, i2c_addressing_type_controller, 0, data};
    case 0x38: // Lost Arbitration on SLA+ Read or Write Data Bytes
        return (i2c_event_t){i2c_event_type_arbitration_lost, i2c_addressing_type_controller, 0, data};
    case 0x40: // SLA+R sent, ACK received
        return (i2c_event_t){i2c_event_type_read_address_sent, i2c_addressing_type_controller, 1, data};
    case 0x48: // SLA+R sent, non-ACK received
        return (i2c_event_t){i2c_event_type_read_address_sent, i2c_addressing_type_controller, 0, data};
    case 0x50: // Data bytes received, ACK returned
        return (i2c_event_t){i2c_event_type_data_recieved, i2c_addressing_type_controller, 1, data};
    case 0x58: // Data bytes received, not ACK returned
        return (i2c_event_t){i2c_event_type_data_recieved, i2c_addressing_type_controller, 0, data};
    case 0x60: // Received (matching itself) SLA+W; received ACK
        return (i2c_event_t){i2c_event_type_write_recieved, i2c_addressing_type_self, 1, data};
    case 0x70: // The general call address (data) has been received; ACK has been received
        return (i2c_event_t){i2c_event_type_write_recieved, i2c_addressing_type_broadcast, 1, data};
    case 0xA0: // Received stop condition or repeated start condition
        return (i2c_event_t){i2c_event_type_stop_condition, i2c_addressing_type_self, 0, data};
    case 0x68: // In the master control, the arbitration is lost in SLA+ read and write; own SLA+W has been received; ACK has been returned
        return (i2c_event_t){i2c_event_type_arbitration_lost, i2c_addressing_type_self, 1, data};
    case 0x78: // Arbitration lost in SLA+ read/write when mastering; general call address received; ACK returned
        return (i2c_event_t){i2c_event_type_arbitration_lost, i2c_addressing_type_broadcast, 1, data};
    case 0x88: // The previous addressing used its own slave address; data bytes have been received; non-ACK has been returned
        return (i2c_event_t){i2c_event_type_data_recieved, i2c_addressing_type_self, 0, data};
    case 0x80: // The previous addressing used its own slave address; data bytes have been received; ACK has been returned
        return (i2c_event_t){i2c_event_type_data_recieved, i2c_addressing_type_self, 1, data};
    case 0x98: // The previous addressing used the general call address; data has been received; non-ACK has been returned
        return (i2c_event_t){i2c_event_type_data_recieved, i2c_addressing_type_broadcast, 0, data};
    case 0x90: // The previous addressing used the general call address; data has been received; ACK has been returned
        return (i2c_event_t){i2c_event_type_data_recieved, i2c_addressing_type_broadcast, 1, data};
    case 0xA8: // Received its own SLA+R; ACK has been returned
        return (i2c_event_t){i2c_event_type_read_recieved, i2c_addressing_type_self, 1, data};
    case 0xB0: // Losing arbitration in SLA+ read and write when master; has received its own SLA+R; has returned ACK
        return (i2c_event_t){i2c_event_type_arbitration_lost, i2c_addressing_type_self, 1, data};
    case 0xC8: // The loaded data byte has been sent; ACK received
    case 0xB8: // Data sent; ACK received
        return (i2c_event_t){i2c_event_type_data_transmitted, i2c_addressing_type_self, 1, data};
    case 0xC0: // Send data, receive non-ACK
        return (i2c_event_t){i2c_event_type_data_transmitted, i2c_addressing_type_self, 0, data};
    default:
        return (i2c_event_t){i2c_event_type_none, i2c_addressing_type_self, 0, data};
    }
}