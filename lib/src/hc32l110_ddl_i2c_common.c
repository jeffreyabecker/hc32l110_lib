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
