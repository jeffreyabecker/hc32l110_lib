#include <hc32l110_sdk.h>


int main()
{
    systick.configure(KHz_1);
    
    GpioPort::enable();

    gpio_port_p01.configure(gpio_digital_output);
    gpio_port_p02.configure(gpio_digital_output);
    gpio_port_p01.digital_write(1);
    gpio_port_p02.digital_write(1);
    while (1)
    {
        systick_timer.delay(650);
        gpio_port_p01.digital_write(0);
        systick_timer.delay(650);
        gpio_port_p01.digital_write(1);
    }

}