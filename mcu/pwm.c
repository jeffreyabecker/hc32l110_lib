#include "pwm.h"
typedef struct
{
    const gpio_port_descriptor_t *port;
    uint8_t state;
    uint8_t flipped;
    uint8_t limit;
    uint8_t limit_buffer;
} pwm_channel_t;

typedef struct
{
    uint8_t counter;
    int8_t channel_count;
    pwm_channel_t channels[16];
} pwm_process_t;

static pwm_process_t pwm_process;
static uint8_t pwm_calculate_duty_cycle_limit(uint8_t duty_cycle)
{
    return (uint8_t)(((uint16_t)duty_cycle) * 255 / 100);
}

void pwm_process_init()
{
    pwm_process.channel_count = 0;
    pwm_process.counter = 0;
}

void pwm_channel_set_duty(gpio_port_descriptor_t *port, uint8_t duty_cycle)
{
    uint8_t channel = 0xFF;
    for (uint32_t i = 0; i < pwm_process.channel_count; i++)
    {
        if (pwm_process.channels[i].port == port)
        {
            channel = i;
            break;
        }
    }
    if (0xFF != channel)
    {
        pwm_process.channels[channel].limit_buffer = pwm_calculate_duty_cycle_limit(duty_cycle);
    }
}

uint8_t pwm_channel_add(gpio_port_descriptor_t *port, uint8_t duty_cycle)
{
    if (pwm_process.channel_count == 16)
    {
        return 0xFF;
    }
    uint8_t channel = pwm_process.channel_count;
    pwm_process.channel_count++;

    uint8_t limit = pwm_calculate_duty_cycle_limit(duty_cycle);
    pwm_process.channels[channel].port = port;
    pwm_process.channels[channel].state = limit == 0 ? 0 : 1;
    pwm_process.channels[channel].flipped = 1;
    pwm_process.channels[channel].limit = limit;
    pwm_process.channels[channel].limit_buffer = limit;
    gpio_digital_write(pwm_process.channels[channel].port, pwm_process.channels[channel].state);
    return channel;
}

void pwm_process_tick()
{
    for (uint32_t i = 0; i < pwm_process.channel_count; i++)
    {
        if (pwm_process.channels[i].flipped)
        {
            gpio_digital_write(pwm_process.channels[i].port, pwm_process.channels[i].state);
        }
    }
    pwm_process.counter++;
    if (0 == pwm_process.counter)
    {
        for (uint32_t i = 0; i < pwm_process.channel_count; i++)
        {
            pwm_process.channels[i].flipped = 1 == pwm_process.channels[i].state ? 0 : 1;
            pwm_process.channels[i].state = 1;
            pwm_process.channels[i].limit = pwm_process.channels[i].limit_buffer;

            if (pwm_process.channels[i].flipped)
            {
                gpio_digital_write(pwm_process.channels[i].port, pwm_process.channels[i].state);
            }
        }
    }
    for (uint32_t i = 0; i < pwm_process.channel_count; i++)
    {
        if (pwm_process.counter > pwm_process.channels[i].limit && 1 == pwm_process.channels[i].state)
        {
            pwm_process.channels[i].flipped = 1;
            pwm_process.channels[i].state = 0;
        }
    }
}
