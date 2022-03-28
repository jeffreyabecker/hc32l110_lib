#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"

// uint8_t state = 0;

int main()
{

    
    
    enable_systick(KHz_1);
    peripheral_enable_gpio();
    //HC32_GPIO_PORT3->DIR = HC32_GPIO_PORT3->DIR & ~(0x02);
    // HC32_GPIO_PORT3->DIR = 0x00;
    // HC32_GPIO_PORT2->DIR = 0x00;
    // HC32_GPIO_PORT1->DIR = 0x00;
    // HC32_GPIO_PORT0->DIR = 0x00;


    // HC32_GPIO_PORT3->OUT = 0xFF;
    // HC32_GPIO_PORT2->OUT = 0xFF;
    // HC32_GPIO_PORT1->OUT = 0xFF;
    // HC32_GPIO_PORT0->OUT = 0xFF;
    const gpio_port_descriptor_t* port = gpio_port_p01;

    gpio_configure(port, gpio_digital_output);

    gpio_digital_write(port, 1);
   
    HC32_GPIO_PORT3->OUT = 0xFF;    
    HC32_GPIO_PORT3->DIR = 0x00;    

    while (1)
    {
        systick_delay(250);
        gpio_digital_write(port, 1);

        systick_delay(250);
        gpio_digital_write(port, 0);
    }
}
