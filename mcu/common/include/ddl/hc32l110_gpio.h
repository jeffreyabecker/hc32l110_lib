/**
 *******************************************************************************
 * @file  hc32l110_GPIO.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_GPIO_H__
#define __hc32l110_GPIO_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_interrupts.h"
#include "hc32l110_core.h"

    uint8_t gpio_digital_read(port_number_t port);
    void gpio_digital_write(port_number_t port, uint8_t value);

    typedef enum
    {
        gpio_interrupt_trigger_disabled = 0,
        gpio_interrupt_trigger_high = 1,
        gpio_interrupt_trigger_low = 2,
        gpio_interrupt_trigger_rising = 4,
        gpio_interrupt_trigger_falling = 8
    } gpio_interrupt_trigger_t;
    typedef struct
    {
        gpio_direction_t direction : 1;
        gpio_analog_digital_t resolution : 1;
        gpio_drive_capability_t drive_mode : 1;
        gpio_internal_pullup_t pull_up : 1;
        gpio_internal_pulldown_t pull_down : 1;
        gpio_mode_t gpio_mode : 1;
        gpio_interrupt_high_t interrupt_high : 1;
        gpio_interrupt_low_t interrupt_low : 1;
        gpio_interrupt_rising_t interrupt_rising : 1;
        gpio_interrupt_falling_t interrupt_falling : 1;
        uint8_t function : 3;
    } gpio_port_config_t;

    __STATIC_FORCEINLINE gpio_port_config_t gpio_create_config(gpio_direction_t direction, gpio_analog_digital_t resolution, gpio_drive_capability_t drive_mode,
                                                               gpio_internal_pullup_t pull_up, gpio_internal_pulldown_t pull_down, gpio_mode_t gpio_mode,
                                                               gpio_interrupt_high_t interrupt_high, gpio_interrupt_low_t interrupt_low, gpio_interrupt_rising_t interrupt_rising,
                                                               gpio_interrupt_falling_t interrupt_falling)
    {
        gpio_port_config_t result = {
            .direction = direction,
            .resolution = resolution,
            .drive_mode = drive_mode,
            .pull_up = pull_up,
            .pull_down = pull_down,
            .gpio_mode = gpio_mode,
            .interrupt_high = interrupt_high,
            .interrupt_low = interrupt_low,
            .interrupt_rising = interrupt_rising,
            .interrupt_falling = interrupt_falling};
        return result;
    }
    void gpio_set_config(port_number_t port, gpio_port_config_t cfg);
    gpio_port_config_t gpio_get_config(port_number_t port);

#ifdef __cplusplus
}
#endif

#endif
