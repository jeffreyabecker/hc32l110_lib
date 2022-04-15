#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"
#include "hc32l110_ddl_basic_timers.h"
volatile uint32_t counter = 0x0000FFFF; // FFFF;
void handle_timer0_fired(hc32_basic_timer_register_t *timer)
{

    counter++;
}

__read_only_data basic_timer_config_t timer0_config = {
    .mode = basic_timer_mode_periodic,
    .tick_source = basic_timer_source_internal,
    .prescaler = basic_timer_prescaler_1_to_1,
    .enable_gate = 0,
    .enable_inverted_output = 0,
    .gate_polarity = 0,
    .interrupt_enabled = 1,
    .reload = 0xFF00};

int main()
{
    enable_systick(KHz_1);
    peripheral_enable_gpio();
    // peripheral_enable_basic_timer();

    gpio_configure(gpio_port_p01, gpio_digital_output);
    gpio_configure(gpio_port_p02, gpio_digital_output);
    gpio_configure(gpio_port_p25, gpio_digital_output);
    gpio_digital_write(gpio_port_p01, 1);
    gpio_digital_write(gpio_port_p02, 1);
    gpio_digital_write(gpio_port_p25, 1);

    // basic_timer_configure(HC32_TIMER0, &timer0_config, &handle_timer0_fired);
    // basic_timer_set_running(HC32_TIMER0, 1);

    while (1)
    {
        if (counter > 0)
        {
            systick_delay(500);
            gpio_digital_write(gpio_port_p01, 1);
            systick_delay(500);
            gpio_digital_write(gpio_port_p01, 0);
        }
    }
}
