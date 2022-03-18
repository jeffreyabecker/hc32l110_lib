#define DDL_USE_CORE 1
#define DDL_USE_GPIO 1

#include "hc32l110.h"

int main()
{

    core_system_clock_config(default_system_config);
    gpio_configure(port_p01, gpio_digital_output);
    while (1)
    {
        gpio_digital_write(port_p01, 1);
        core_systick_delay(1000);
        gpio_digital_write(port_p01, 0);
        core_systick_delay(1000);
    }
}