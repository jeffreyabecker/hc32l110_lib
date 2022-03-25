#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"

// uint8_t state = 0;
static  systick_counter_t counter;
int main()
{

    
    
    enable_systick(KHz_1);
    peripheral_enable_gpio();

    gpio_configure(gpio_port_p02, gpio_digital_output);
    gpio_configure(gpio_port_p01, gpio_digital_output);

    gpio_digital_write(gpio_port_p01, 1);
    



    while (1)
    {
        systck_counter_delay(&counter, 250);
        gpio_digital_write(gpio_port_p02, 0);
        systck_counter_delay(&counter, 250);
        gpio_digital_write(gpio_port_p02, 1);
    }
}
