#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"
#include "hc32l110_ddl_basic_timers.h"
volatile static uint8_t blink_counter = 0;
// typedef struct
// {
//     const gpio_port_descriptor_t *port;
//     uint8_t state;
//     uint8_t limit;
//     uint8_t limit_buffer;
// } pwm_channel_t;




static volatile uint8_t limit;
static volatile uint8_t limit_buffer;
static volatile uint8_t state ;
void handle_timer_fired(hc32_basic_timer_register_t *timer)
{
    gpio_digital_write(gpio_port_p02, state);
    blink_counter++;
    if(0 == blink_counter){
        limit = limit_buffer;
        state = 1;
    }
    if(blink_counter > limit){
        state = 0;
    }

    
}

__read_only_data basic_timer_config_t timer_config = {
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
    peripheral_enable_basic_timer();


    gpio_configure(gpio_port_p01, gpio_digital_output);
    gpio_configure(gpio_port_p02, gpio_digital_output);
    gpio_configure(gpio_port_p25, gpio_digital_output);
    gpio_digital_write(gpio_port_p01, 1);
    gpio_digital_write(gpio_port_p02, 1);
    gpio_digital_write(gpio_port_p25, 1);

    limit = 16;
    limit_buffer = 16;
    state = 1;
    basic_timer_configure(HC32_TIMER0, &timer_config, &handle_timer_fired);
    basic_timer_set_running(HC32_TIMER0, 1);

    while (1)
    {
        systick_delay(500);
        gpio_digital_write(gpio_port_p01, 1);
        systick_delay(500);
        gpio_digital_write(gpio_port_p01, 0);
    }
}
