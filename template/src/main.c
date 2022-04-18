#include <hc32l110_sdk.h>

int main()
{
    enable_systick(KHz_1);
    peripheral_enable_gpio();
    gpio_configure(gpio_port_p01, gpio_digital_output);
    gpio_digital_write(gpio_port_p01, 1);

    while (1)
    {
        systick_delay(500);
        gpio_digital_write(gpio_port_p01, 1);
        systick_delay(500);
        gpio_digital_write(gpio_port_p01, 0);
    }
}
