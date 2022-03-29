#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"

int main()
{

    enable_systick(KHz_1);
    peripheral_enable_gpio();
    const gpio_port_descriptor_t *port = gpio_port_p01;

    gpio_configure(port, gpio_digital_output);

    gpio_digital_write(port, 1);

    while (1)
    {
        systick_delay(250);
        gpio_digital_write(port, 1);

        systick_delay(250);
        gpio_digital_write(port, 0);
    }
}
