/**
 *******************************************************************************
 * @file  hc32l110_GPIO.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_GPIO_H__
#define __hc32l110_GPIO_H__
#if defined(DDL_USE_ALL) || ( defined(DDL_USE_CORE) && defined(DDL_USE_GPIO))
#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_interrupts.h"

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

    static inline gpio_port_config_t gpio_create_config(gpio_direction_t direction, gpio_analog_digital_t resolution, gpio_drive_capability_t drive_mode,
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
    void gpio_set_config(port_number_t port, gpio_port_config_t cfg)
    {
        switch (port)
        {

        case port_p01:
            M0P_GPIO->P0DIR.P01 = cfg.direction;
            M0P_GPIO->P0ADS.P01 = cfg.resolution;
            M0P_GPIO->P0DR.P01 = cfg.drive_mode;
            M0P_GPIO->P0PU.P01 = cfg.pull_up;
            M0P_GPIO->P0PD.P01 = cfg.pull_down;
            M0P_GPIO->P0OD.P01 = cfg.gpio_mode;
            M0P_GPIO->P0HIE.P01 = cfg.interrupt_high;
            M0P_GPIO->P0LIE.P01 = cfg.interrupt_low;
            M0P_GPIO->P0RIE.P01 = cfg.interrupt_rising;
            M0P_GPIO->P0FIE.P01 = cfg.interrupt_falling;
            M0P_GPIO->P01_SEL = cfg.function;
            return;
        case port_p02:
            M0P_GPIO->P0DIR.P02 = cfg.direction;
            M0P_GPIO->P0ADS.P02 = cfg.resolution;
            M0P_GPIO->P0DR.P02 = cfg.drive_mode;
            M0P_GPIO->P0PU.P02 = cfg.pull_up;
            M0P_GPIO->P0PD.P02 = cfg.pull_down;
            M0P_GPIO->P0OD.P02 = cfg.gpio_mode;
            M0P_GPIO->P0HIE.P02 = cfg.interrupt_high;
            M0P_GPIO->P0LIE.P02 = cfg.interrupt_low;
            M0P_GPIO->P0RIE.P02 = cfg.interrupt_rising;
            M0P_GPIO->P0FIE.P02 = cfg.interrupt_falling;
            M0P_GPIO->P02_SEL = cfg.function;
            return;
        case port_p03:
            M0P_GPIO->P0DIR.P03 = cfg.direction;
            M0P_GPIO->P0ADS.P03 = cfg.resolution;
            M0P_GPIO->P0DR.P03 = cfg.drive_mode;
            M0P_GPIO->P0PU.P03 = cfg.pull_up;
            M0P_GPIO->P0PD.P03 = cfg.pull_down;
            M0P_GPIO->P0OD.P03 = cfg.gpio_mode;
            M0P_GPIO->P0HIE.P03 = cfg.interrupt_high;
            M0P_GPIO->P0LIE.P03 = cfg.interrupt_low;
            M0P_GPIO->P0RIE.P03 = cfg.interrupt_rising;
            M0P_GPIO->P0FIE.P03 = cfg.interrupt_falling;
            M0P_GPIO->P03_SEL = cfg.function;
            return;
        case port_p14:
            M0P_GPIO->P1DIR.P14 = cfg.direction;
            M0P_GPIO->P1ADS.P14 = cfg.resolution;
            M0P_GPIO->P1DR.P14 = cfg.drive_mode;
            M0P_GPIO->P1PU.P14 = cfg.pull_up;
            M0P_GPIO->P1PD.P14 = cfg.pull_down;
            M0P_GPIO->P1OD.P14 = cfg.gpio_mode;
            M0P_GPIO->P1HIE.P14 = cfg.interrupt_high;
            M0P_GPIO->P1LIE.P14 = cfg.interrupt_low;
            M0P_GPIO->P1RIE.P14 = cfg.interrupt_rising;
            M0P_GPIO->P1FIE.P14 = cfg.interrupt_falling;
            M0P_GPIO->P14_SEL = cfg.function;
            return;
        case port_p15:
            M0P_GPIO->P1DIR.P15 = cfg.direction;
            M0P_GPIO->P1ADS.P15 = cfg.resolution;
            M0P_GPIO->P1DR.P15 = cfg.drive_mode;
            M0P_GPIO->P1PU.P15 = cfg.pull_up;
            M0P_GPIO->P1PD.P15 = cfg.pull_down;
            M0P_GPIO->P1OD.P15 = cfg.gpio_mode;
            M0P_GPIO->P1HIE.P15 = cfg.interrupt_high;
            M0P_GPIO->P1LIE.P15 = cfg.interrupt_low;
            M0P_GPIO->P1RIE.P15 = cfg.interrupt_rising;
            M0P_GPIO->P1FIE.P15 = cfg.interrupt_falling;
            M0P_GPIO->P15_SEL = cfg.function;
            return;
        case port_p23:
            M0P_GPIO->P2DIR.P23 = cfg.direction;
            M0P_GPIO->P2ADS.P23 = cfg.resolution;
            M0P_GPIO->P2DR.P23 = cfg.drive_mode;
            M0P_GPIO->P2PU.P23 = cfg.pull_up;
            M0P_GPIO->P2PD.P23 = cfg.pull_down;
            M0P_GPIO->P2OD.P23 = cfg.gpio_mode;
            M0P_GPIO->P2HIE.P23 = cfg.interrupt_high;
            M0P_GPIO->P2LIE.P23 = cfg.interrupt_low;
            M0P_GPIO->P2RIE.P23 = cfg.interrupt_rising;
            M0P_GPIO->P2FIE.P23 = cfg.interrupt_falling;
            M0P_GPIO->P23_SEL = cfg.function;
            return;
        case port_p24:
            M0P_GPIO->P2DIR.P24 = cfg.direction;
            M0P_GPIO->P2ADS.P24 = cfg.resolution;
            M0P_GPIO->P2DR.P24 = cfg.drive_mode;
            M0P_GPIO->P2PU.P24 = cfg.pull_up;
            M0P_GPIO->P2PD.P24 = cfg.pull_down;
            M0P_GPIO->P2OD.P24 = cfg.gpio_mode;
            M0P_GPIO->P2HIE.P24 = cfg.interrupt_high;
            M0P_GPIO->P2LIE.P24 = cfg.interrupt_low;
            M0P_GPIO->P2RIE.P24 = cfg.interrupt_rising;
            M0P_GPIO->P2FIE.P24 = cfg.interrupt_falling;
            M0P_GPIO->P24_SEL = cfg.function;
            return;
        case port_p25:
            M0P_GPIO->P2DIR.P25 = cfg.direction;
            M0P_GPIO->P2ADS.P25 = cfg.resolution;
            M0P_GPIO->P2DR.P25 = cfg.drive_mode;
            M0P_GPIO->P2PU.P25 = cfg.pull_up;
            M0P_GPIO->P2PD.P25 = cfg.pull_down;
            M0P_GPIO->P2OD.P25 = cfg.gpio_mode;
            M0P_GPIO->P2HIE.P25 = cfg.interrupt_high;
            M0P_GPIO->P2LIE.P25 = cfg.interrupt_low;
            M0P_GPIO->P2RIE.P25 = cfg.interrupt_rising;
            M0P_GPIO->P2FIE.P25 = cfg.interrupt_falling;
            M0P_GPIO->P25_SEL = cfg.function;
            return;
        case port_p26:
            M0P_GPIO->P2DIR.P26 = cfg.direction;
            M0P_GPIO->P2ADS.P26 = cfg.resolution;
            M0P_GPIO->P2DR.P26 = cfg.drive_mode;
            M0P_GPIO->P2PU.P26 = cfg.pull_up;
            M0P_GPIO->P2PD.P26 = cfg.pull_down;
            M0P_GPIO->P2OD.P26 = cfg.gpio_mode;
            M0P_GPIO->P2HIE.P26 = cfg.interrupt_high;
            M0P_GPIO->P2LIE.P26 = cfg.interrupt_low;
            M0P_GPIO->P2RIE.P26 = cfg.interrupt_rising;
            M0P_GPIO->P2FIE.P26 = cfg.interrupt_falling;
            M0P_GPIO->P26_SEL = cfg.function;
            return;
        case port_p27:
            M0P_GPIO->P2DIR.P27 = cfg.direction;
            M0P_GPIO->P2ADS.P27 = cfg.resolution;
            M0P_GPIO->P2DR.P27 = cfg.drive_mode;
            M0P_GPIO->P2PU.P27 = cfg.pull_up;
            M0P_GPIO->P2PD.P27 = cfg.pull_down;
            M0P_GPIO->P2OD.P27 = cfg.gpio_mode;
            M0P_GPIO->P2HIE.P27 = cfg.interrupt_high;
            M0P_GPIO->P2LIE.P27 = cfg.interrupt_low;
            M0P_GPIO->P2RIE.P27 = cfg.interrupt_rising;
            M0P_GPIO->P2FIE.P27 = cfg.interrupt_falling;
            M0P_GPIO->P27_SEL = cfg.function;
            return;
        case port_p31:
            M0P_GPIO->P3DIR.P31 = cfg.direction;
            M0P_GPIO->P3ADS.P31 = cfg.resolution;
            M0P_GPIO->P3DR.P31 = cfg.drive_mode;
            M0P_GPIO->P3PU.P31 = cfg.pull_up;
            M0P_GPIO->P3PD.P31 = cfg.pull_down;
            M0P_GPIO->P3OD.P31 = cfg.gpio_mode;
            M0P_GPIO->P3HIE.P31 = cfg.interrupt_high;
            M0P_GPIO->P3LIE.P31 = cfg.interrupt_low;
            M0P_GPIO->P3RIE.P31 = cfg.interrupt_rising;
            M0P_GPIO->P3FIE.P31 = cfg.interrupt_falling;
            M0P_GPIO->P31_SEL = cfg.function;
            return;
        case port_p32:
            M0P_GPIO->P3DIR.P32 = cfg.direction;
            M0P_GPIO->P3ADS.P32 = cfg.resolution;
            M0P_GPIO->P3DR.P32 = cfg.drive_mode;
            M0P_GPIO->P3PU.P32 = cfg.pull_up;
            M0P_GPIO->P3PD.P32 = cfg.pull_down;
            M0P_GPIO->P3OD.P32 = cfg.gpio_mode;
            M0P_GPIO->P3HIE.P32 = cfg.interrupt_high;
            M0P_GPIO->P3LIE.P32 = cfg.interrupt_low;
            M0P_GPIO->P3RIE.P32 = cfg.interrupt_rising;
            M0P_GPIO->P3FIE.P32 = cfg.interrupt_falling;
            M0P_GPIO->P32_SEL = cfg.function;
            return;
        case port_p33:
            M0P_GPIO->P3DIR.P33 = cfg.direction;
            M0P_GPIO->P3ADS.P33 = cfg.resolution;
            M0P_GPIO->P3DR.P33 = cfg.drive_mode;
            M0P_GPIO->P3PU.P33 = cfg.pull_up;
            M0P_GPIO->P3PD.P33 = cfg.pull_down;
            M0P_GPIO->P3OD.P33 = cfg.gpio_mode;
            M0P_GPIO->P3HIE.P33 = cfg.interrupt_high;
            M0P_GPIO->P3LIE.P33 = cfg.interrupt_low;
            M0P_GPIO->P3RIE.P33 = cfg.interrupt_rising;
            M0P_GPIO->P3FIE.P33 = cfg.interrupt_falling;
            M0P_GPIO->P33_SEL = cfg.function;
            return;
        case port_p34:
            M0P_GPIO->P3DIR.P34 = cfg.direction;
            M0P_GPIO->P3ADS.P34 = cfg.resolution;
            M0P_GPIO->P3DR.P34 = cfg.drive_mode;
            M0P_GPIO->P3PU.P34 = cfg.pull_up;
            M0P_GPIO->P3PD.P34 = cfg.pull_down;
            M0P_GPIO->P3OD.P34 = cfg.gpio_mode;
            M0P_GPIO->P3HIE.P34 = cfg.interrupt_high;
            M0P_GPIO->P3LIE.P34 = cfg.interrupt_low;
            M0P_GPIO->P3RIE.P34 = cfg.interrupt_rising;
            M0P_GPIO->P3FIE.P34 = cfg.interrupt_falling;
            M0P_GPIO->P34_SEL = cfg.function;
            return;
        case port_p35:
            M0P_GPIO->P3DIR.P35 = cfg.direction;
            M0P_GPIO->P3ADS.P35 = cfg.resolution;
            M0P_GPIO->P3DR.P35 = cfg.drive_mode;
            M0P_GPIO->P3PU.P35 = cfg.pull_up;
            M0P_GPIO->P3PD.P35 = cfg.pull_down;
            M0P_GPIO->P3OD.P35 = cfg.gpio_mode;
            M0P_GPIO->P3HIE.P35 = cfg.interrupt_high;
            M0P_GPIO->P3LIE.P35 = cfg.interrupt_low;
            M0P_GPIO->P3RIE.P35 = cfg.interrupt_rising;
            M0P_GPIO->P3FIE.P35 = cfg.interrupt_falling;
            M0P_GPIO->P35_SEL = cfg.function;
            return;
        case port_p36:
            M0P_GPIO->P3DIR.P36 = cfg.direction;
            M0P_GPIO->P3ADS.P36 = cfg.resolution;
            M0P_GPIO->P3DR.P36 = cfg.drive_mode;
            M0P_GPIO->P3PU.P36 = cfg.pull_up;
            M0P_GPIO->P3PD.P36 = cfg.pull_down;
            M0P_GPIO->P3OD.P36 = cfg.gpio_mode;
            M0P_GPIO->P3HIE.P36 = cfg.interrupt_high;
            M0P_GPIO->P3LIE.P36 = cfg.interrupt_low;
            M0P_GPIO->P3RIE.P36 = cfg.interrupt_rising;
            M0P_GPIO->P3FIE.P36 = cfg.interrupt_falling;
            M0P_GPIO->P36_SEL = cfg.function;
            return;
        default:
            break;
        }
    }
    gpio_port_config_t gpio_get_config(port_number_t port)
    {
        gpio_port_config_t cfg;
        switch (port)
        {

        case port_p01:
            cfg.direction = M0P_GPIO->P0DIR.P01;
            cfg.resolution = M0P_GPIO->P0ADS.P01;
            cfg.drive_mode = M0P_GPIO->P0DR.P01;
            cfg.pull_up = M0P_GPIO->P0PU.P01;
            cfg.pull_down = M0P_GPIO->P0PD.P01;
            cfg.gpio_mode = M0P_GPIO->P0OD.P01;
            cfg.interrupt_high = M0P_GPIO->P0HIE.P01;
            cfg.interrupt_low = M0P_GPIO->P0LIE.P01;
            cfg.interrupt_rising = M0P_GPIO->P0RIE.P01;
            cfg.interrupt_falling = M0P_GPIO->P0FIE.P01;
            cfg.function = M0P_GPIO->P01_SEL;
            return cfg;

        case port_p02:
            cfg.direction = M0P_GPIO->P0DIR.P02;
            cfg.resolution = M0P_GPIO->P0ADS.P02;
            cfg.drive_mode = M0P_GPIO->P0DR.P02;
            cfg.pull_up = M0P_GPIO->P0PU.P02;
            cfg.pull_down = M0P_GPIO->P0PD.P02;
            cfg.gpio_mode = M0P_GPIO->P0OD.P02;
            cfg.interrupt_high = M0P_GPIO->P0HIE.P02;
            cfg.interrupt_low = M0P_GPIO->P0LIE.P02;
            cfg.interrupt_rising = M0P_GPIO->P0RIE.P02;
            cfg.interrupt_falling = M0P_GPIO->P0FIE.P02;
            cfg.function = M0P_GPIO->P02_SEL;
            return cfg;

        case port_p03:
            cfg.direction = M0P_GPIO->P0DIR.P03;
            cfg.resolution = M0P_GPIO->P0ADS.P03;
            cfg.drive_mode = M0P_GPIO->P0DR.P03;
            cfg.pull_up = M0P_GPIO->P0PU.P03;
            cfg.pull_down = M0P_GPIO->P0PD.P03;
            cfg.gpio_mode = M0P_GPIO->P0OD.P03;
            cfg.interrupt_high = M0P_GPIO->P0HIE.P03;
            cfg.interrupt_low = M0P_GPIO->P0LIE.P03;
            cfg.interrupt_rising = M0P_GPIO->P0RIE.P03;
            cfg.interrupt_falling = M0P_GPIO->P0FIE.P03;
            cfg.function = M0P_GPIO->P03_SEL;
            return cfg;

        case port_p14:
            cfg.direction = M0P_GPIO->P1DIR.P14;
            cfg.resolution = M0P_GPIO->P1ADS.P14;
            cfg.drive_mode = M0P_GPIO->P1DR.P14;
            cfg.pull_up = M0P_GPIO->P1PU.P14;
            cfg.pull_down = M0P_GPIO->P1PD.P14;
            cfg.gpio_mode = M0P_GPIO->P1OD.P14;
            cfg.interrupt_high = M0P_GPIO->P1HIE.P14;
            cfg.interrupt_low = M0P_GPIO->P1LIE.P14;
            cfg.interrupt_rising = M0P_GPIO->P1RIE.P14;
            cfg.interrupt_falling = M0P_GPIO->P1FIE.P14;
            cfg.function = M0P_GPIO->P14_SEL;
            return cfg;

        case port_p15:
            cfg.direction = M0P_GPIO->P1DIR.P15;
            cfg.resolution = M0P_GPIO->P1ADS.P15;
            cfg.drive_mode = M0P_GPIO->P1DR.P15;
            cfg.pull_up = M0P_GPIO->P1PU.P15;
            cfg.pull_down = M0P_GPIO->P1PD.P15;
            cfg.gpio_mode = M0P_GPIO->P1OD.P15;
            cfg.interrupt_high = M0P_GPIO->P1HIE.P15;
            cfg.interrupt_low = M0P_GPIO->P1LIE.P15;
            cfg.interrupt_rising = M0P_GPIO->P1RIE.P15;
            cfg.interrupt_falling = M0P_GPIO->P1FIE.P15;
            cfg.function = M0P_GPIO->P15_SEL;
            return cfg;

        case port_p23:
            cfg.direction = M0P_GPIO->P2DIR.P23;
            cfg.resolution = M0P_GPIO->P2ADS.P23;
            cfg.drive_mode = M0P_GPIO->P2DR.P23;
            cfg.pull_up = M0P_GPIO->P2PU.P23;
            cfg.pull_down = M0P_GPIO->P2PD.P23;
            cfg.gpio_mode = M0P_GPIO->P2OD.P23;
            cfg.interrupt_high = M0P_GPIO->P2HIE.P23;
            cfg.interrupt_low = M0P_GPIO->P2LIE.P23;
            cfg.interrupt_rising = M0P_GPIO->P2RIE.P23;
            cfg.interrupt_falling = M0P_GPIO->P2FIE.P23;
            cfg.function = M0P_GPIO->P23_SEL;
            return cfg;

        case port_p24:
            cfg.direction = M0P_GPIO->P2DIR.P24;
            cfg.resolution = M0P_GPIO->P2ADS.P24;
            cfg.drive_mode = M0P_GPIO->P2DR.P24;
            cfg.pull_up = M0P_GPIO->P2PU.P24;
            cfg.pull_down = M0P_GPIO->P2PD.P24;
            cfg.gpio_mode = M0P_GPIO->P2OD.P24;
            cfg.interrupt_high = M0P_GPIO->P2HIE.P24;
            cfg.interrupt_low = M0P_GPIO->P2LIE.P24;
            cfg.interrupt_rising = M0P_GPIO->P2RIE.P24;
            cfg.interrupt_falling = M0P_GPIO->P2FIE.P24;
            cfg.function = M0P_GPIO->P24_SEL;
            return cfg;

        case port_p25:
            cfg.direction = M0P_GPIO->P2DIR.P25;
            cfg.resolution = M0P_GPIO->P2ADS.P25;
            cfg.drive_mode = M0P_GPIO->P2DR.P25;
            cfg.pull_up = M0P_GPIO->P2PU.P25;
            cfg.pull_down = M0P_GPIO->P2PD.P25;
            cfg.gpio_mode = M0P_GPIO->P2OD.P25;
            cfg.interrupt_high = M0P_GPIO->P2HIE.P25;
            cfg.interrupt_low = M0P_GPIO->P2LIE.P25;
            cfg.interrupt_rising = M0P_GPIO->P2RIE.P25;
            cfg.interrupt_falling = M0P_GPIO->P2FIE.P25;
            cfg.function = M0P_GPIO->P25_SEL;
            return cfg;

        case port_p26:
            cfg.direction = M0P_GPIO->P2DIR.P26;
            cfg.resolution = M0P_GPIO->P2ADS.P26;
            cfg.drive_mode = M0P_GPIO->P2DR.P26;
            cfg.pull_up = M0P_GPIO->P2PU.P26;
            cfg.pull_down = M0P_GPIO->P2PD.P26;
            cfg.gpio_mode = M0P_GPIO->P2OD.P26;
            cfg.interrupt_high = M0P_GPIO->P2HIE.P26;
            cfg.interrupt_low = M0P_GPIO->P2LIE.P26;
            cfg.interrupt_rising = M0P_GPIO->P2RIE.P26;
            cfg.interrupt_falling = M0P_GPIO->P2FIE.P26;
            cfg.function = M0P_GPIO->P26_SEL;
            return cfg;

        case port_p27:
            cfg.direction = M0P_GPIO->P2DIR.P27;
            cfg.resolution = M0P_GPIO->P2ADS.P27;
            cfg.drive_mode = M0P_GPIO->P2DR.P27;
            cfg.pull_up = M0P_GPIO->P2PU.P27;
            cfg.pull_down = M0P_GPIO->P2PD.P27;
            cfg.gpio_mode = M0P_GPIO->P2OD.P27;
            cfg.interrupt_high = M0P_GPIO->P2HIE.P27;
            cfg.interrupt_low = M0P_GPIO->P2LIE.P27;
            cfg.interrupt_rising = M0P_GPIO->P2RIE.P27;
            cfg.interrupt_falling = M0P_GPIO->P2FIE.P27;
            cfg.function = M0P_GPIO->P27_SEL;
            return cfg;

        case port_p31:
            cfg.direction = M0P_GPIO->P3DIR.P31;
            cfg.resolution = M0P_GPIO->P3ADS.P31;
            cfg.drive_mode = M0P_GPIO->P3DR.P31;
            cfg.pull_up = M0P_GPIO->P3PU.P31;
            cfg.pull_down = M0P_GPIO->P3PD.P31;
            cfg.gpio_mode = M0P_GPIO->P3OD.P31;
            cfg.interrupt_high = M0P_GPIO->P3HIE.P31;
            cfg.interrupt_low = M0P_GPIO->P3LIE.P31;
            cfg.interrupt_rising = M0P_GPIO->P3RIE.P31;
            cfg.interrupt_falling = M0P_GPIO->P3FIE.P31;
            cfg.function = M0P_GPIO->P31_SEL;
            return cfg;

        case port_p32:
            cfg.direction = M0P_GPIO->P3DIR.P32;
            cfg.resolution = M0P_GPIO->P3ADS.P32;
            cfg.drive_mode = M0P_GPIO->P3DR.P32;
            cfg.pull_up = M0P_GPIO->P3PU.P32;
            cfg.pull_down = M0P_GPIO->P3PD.P32;
            cfg.gpio_mode = M0P_GPIO->P3OD.P32;
            cfg.interrupt_high = M0P_GPIO->P3HIE.P32;
            cfg.interrupt_low = M0P_GPIO->P3LIE.P32;
            cfg.interrupt_rising = M0P_GPIO->P3RIE.P32;
            cfg.interrupt_falling = M0P_GPIO->P3FIE.P32;
            cfg.function = M0P_GPIO->P32_SEL;
            return cfg;

        case port_p33:
            cfg.direction = M0P_GPIO->P3DIR.P33;
            cfg.resolution = M0P_GPIO->P3ADS.P33;
            cfg.drive_mode = M0P_GPIO->P3DR.P33;
            cfg.pull_up = M0P_GPIO->P3PU.P33;
            cfg.pull_down = M0P_GPIO->P3PD.P33;
            cfg.gpio_mode = M0P_GPIO->P3OD.P33;
            cfg.interrupt_high = M0P_GPIO->P3HIE.P33;
            cfg.interrupt_low = M0P_GPIO->P3LIE.P33;
            cfg.interrupt_rising = M0P_GPIO->P3RIE.P33;
            cfg.interrupt_falling = M0P_GPIO->P3FIE.P33;
            cfg.function = M0P_GPIO->P33_SEL;
            return cfg;

        case port_p34:
            cfg.direction = M0P_GPIO->P3DIR.P34;
            cfg.resolution = M0P_GPIO->P3ADS.P34;
            cfg.drive_mode = M0P_GPIO->P3DR.P34;
            cfg.pull_up = M0P_GPIO->P3PU.P34;
            cfg.pull_down = M0P_GPIO->P3PD.P34;
            cfg.gpio_mode = M0P_GPIO->P3OD.P34;
            cfg.interrupt_high = M0P_GPIO->P3HIE.P34;
            cfg.interrupt_low = M0P_GPIO->P3LIE.P34;
            cfg.interrupt_rising = M0P_GPIO->P3RIE.P34;
            cfg.interrupt_falling = M0P_GPIO->P3FIE.P34;
            cfg.function = M0P_GPIO->P34_SEL;
            return cfg;

        case port_p35:
            cfg.direction = M0P_GPIO->P3DIR.P35;
            cfg.resolution = M0P_GPIO->P3ADS.P35;
            cfg.drive_mode = M0P_GPIO->P3DR.P35;
            cfg.pull_up = M0P_GPIO->P3PU.P35;
            cfg.pull_down = M0P_GPIO->P3PD.P35;
            cfg.gpio_mode = M0P_GPIO->P3OD.P35;
            cfg.interrupt_high = M0P_GPIO->P3HIE.P35;
            cfg.interrupt_low = M0P_GPIO->P3LIE.P35;
            cfg.interrupt_rising = M0P_GPIO->P3RIE.P35;
            cfg.interrupt_falling = M0P_GPIO->P3FIE.P35;
            cfg.function = M0P_GPIO->P35_SEL;
            return cfg;

        case port_p36:
            cfg.direction = M0P_GPIO->P3DIR.P36;
            cfg.resolution = M0P_GPIO->P3ADS.P36;
            cfg.drive_mode = M0P_GPIO->P3DR.P36;
            cfg.pull_up = M0P_GPIO->P3PU.P36;
            cfg.pull_down = M0P_GPIO->P3PD.P36;
            cfg.gpio_mode = M0P_GPIO->P3OD.P36;
            cfg.interrupt_high = M0P_GPIO->P3HIE.P36;
            cfg.interrupt_low = M0P_GPIO->P3LIE.P36;
            cfg.interrupt_rising = M0P_GPIO->P3RIE.P36;
            cfg.interrupt_falling = M0P_GPIO->P3FIE.P36;
            cfg.function = M0P_GPIO->P36_SEL;
            return cfg;

        default:
            return cfg;
        }
    }

    uint8_t gpio_digital_read(port_number_t port)
    {
        switch (port)
        {
        case port_p01:
            return M0P_GPIO->P0IN.P01;
        case port_p02:
            return M0P_GPIO->P0IN.P02;
        case port_p03:
            return M0P_GPIO->P0IN.P03;
        case port_p14:
            return M0P_GPIO->P1IN.P14;
        case port_p15:
            return M0P_GPIO->P1IN.P15;
        case port_p23:
            return M0P_GPIO->P2IN.P23;
        case port_p24:
            return M0P_GPIO->P2IN.P24;
        case port_p25:
            return M0P_GPIO->P2IN.P25;
        case port_p26:
            return M0P_GPIO->P2IN.P26;
        case port_p27:
            return M0P_GPIO->P2IN.P27;
        case port_p31:
            return M0P_GPIO->P3IN.P31;
        case port_p32:
            return M0P_GPIO->P3IN.P32;
        case port_p33:
            return M0P_GPIO->P3IN.P33;
        case port_p34:
            return M0P_GPIO->P3IN.P34;
        case port_p35:
            return M0P_GPIO->P3IN.P35;
        case port_p36:
            return M0P_GPIO->P3IN.P36;
        default:
            return 0xFF;
        }
    }
    void gpio_digital_write(port_number_t port, uint8_t value)
    {
        switch (port)
        {
        case port_p01:
            M0P_GPIO->P0OUT.P01 = value;
        case port_p02:
            M0P_GPIO->P0OUT.P02 = value;
        case port_p03:
            M0P_GPIO->P0OUT.P03 = value;
        case port_p14:
            M0P_GPIO->P1OUT.P14 = value;
        case port_p15:
            M0P_GPIO->P1OUT.P15 = value;
        case port_p23:
            M0P_GPIO->P2OUT.P23 = value;
        case port_p24:
            M0P_GPIO->P2OUT.P24 = value;
        case port_p25:
            M0P_GPIO->P2OUT.P25 = value;
        case port_p26:
            M0P_GPIO->P2OUT.P26 = value;
        case port_p27:
            M0P_GPIO->P2OUT.P27 = value;
        case port_p31:
            M0P_GPIO->P3OUT.P31 = value;
        case port_p32:
            M0P_GPIO->P3OUT.P32 = value;
        case port_p33:
            M0P_GPIO->P3OUT.P33 = value;
        case port_p34:
            M0P_GPIO->P3OUT.P34 = value;
        case port_p35:
            M0P_GPIO->P3OUT.P35 = value;
        case port_p36:
            M0P_GPIO->P3OUT.P36 = value;
        default:
            break;
        }
    }

#ifdef __cplusplus
}
#endif

#endif
#endif