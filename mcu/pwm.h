#include <stdint.h>
#include "hc32l110_ddl_gpio.h"
#ifndef __PWM_H__
#define __PWM_H__
void pwm_process_init();
void pwm_process_tick();
uint8_t pwm_channel_add(gpio_port_descriptor_t *port, uint8_t duty_cycle);
void pwm_channel_set_duty(gpio_port_descriptor_t *port, uint8_t duty_cycle);

#endif