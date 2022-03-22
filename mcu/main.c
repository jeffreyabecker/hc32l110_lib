// #define DDL_USE_CORE 1
// #define DDL_USE_GPIO 1
// #define DDL_USE_BASIC_TIMERS 0
// #define DDL_USE_PCA 0
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_clock.h"



int main()
{
     M0P_CLOCK->peripheral_clock_enable_f.GPIO = 1;
uint8_t state = 0;
    //core_system_clock_config(default_system_config);
    M0P_GPIO->P0DIR = 0x00;
    M0P_GPIO->P1DIR = 0x00;
    M0P_GPIO->P2DIR = 0x00;
    M0P_GPIO->P3DIR = 0x00;
    M0P_GPIO->P0OUT = 14;
    M0P_GPIO->P1OUT  = 48;
    M0P_GPIO->P2OUT  = 248;
    M0P_GPIO->P3OUT  = 126;
    while(1){
        
        // M0P_GPIO->PORT0.OUT = 14;
        // M0P_GPIO->PORT1.OUT  = 48;
        // M0P_GPIO->PORT2.OUT  = 248;
        // M0P_GPIO->PORT3.OUT  = 126;
    }
    // for (uint32_t i = 0; i < 16; i++)
    // {
    //     gpio_configure(&port_descriptors[i], gpio_digital_output);
    // }
    // // basic_timer_configure(M0P_TIMER0, &pwm_timer_config, &pwm_update_output);
    // while (1)
    // {
    //     for (size_t i = 0; i < 16; i++)
    //     {
    //         gpio_digital_write(&port_descriptors[i], state);
    //     }
    //     state = ~state;
    //     core_systick_delay(333);
    // }
}