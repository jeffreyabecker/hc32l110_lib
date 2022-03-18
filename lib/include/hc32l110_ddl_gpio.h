/**
 *******************************************************************************
 * @file  hc32l110_GPIO.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_GPIO_H__
#define __hc32l110_GPIO_H__
#if defined(DDL_USE_ALL) || (defined(DDL_USE_CORE) && defined(DDL_USE_GPIO))
#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_ddl_core.h"

    typedef enum
    {
        port_p01 = 0,
        port_p02 = 1,
        port_p03 = 2,
        port_p14 = 3,
        port_p15 = 4,
        port_p23 = 5,
        port_p24 = 6,
        port_p25 = 7,
        port_p26 = 8,
        port_p27 = 9,
        port_p31 = 10,
        port_p32 = 11,
        port_p33 = 12,
        port_p34 = 13,
        port_p35 = 14,
        port_p36 = 15,
    } port_number_t;
    typedef struct
    {
        uint32_t *sel;
        port_ctl_t *port;
        port_interrupt_t *interrupt;
        uint8_t position;
    } port_descriptor_t;
    __read_only_data port_descriptor_t __port_info[16] = {
        /*port_p01*/
        {
            .sel = ((uint32_t *)0x40020C04),
            .port = ((port_ctl_t *)0x40020CD0),
            .interrupt = ((port_interrupt_t *)0x40020DD0),
            .position = 1},
        /*port_p02*/
        {
            .sel = ((uint32_t *)0x40020C08),
            .port = ((port_ctl_t *)0x40020CD0),
            .interrupt = ((port_interrupt_t *)0x40020DD0),
            .position = 2},
        /*port_p03*/
        {
            .sel = ((uint32_t *)0x40020C0C),
            .port = ((port_ctl_t *)0x40020CD0),
            .interrupt = ((port_interrupt_t *)0x40020DD0),
            .position = 3},

        /*port_p14*/
        {
            .sel = ((uint32_t *)0x40020C50),
            .port = ((port_ctl_t *)0x40020D10),
            .interrupt = ((port_interrupt_t *)0x40020E10),
            .position = 5},
        /*port_p15*/
        {
            .sel = ((uint32_t *)0x40020C54),
            .port = ((port_ctl_t *)0x40020D10),
            .interrupt = ((port_interrupt_t *)0x40020E10),
            .position = 6},

        /*port_p23*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 0)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 4},
        /*port_p24*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 4)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 5},
        /*port_p25*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 8)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 6},
        /*port_p26*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 12)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 7},
        /*port_p27*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 16)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 8},

        /*port_p31*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 0))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 1},
        /*port_p32*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 1))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 2},
        /*port_p33*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 2))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 3},
        /*port_p34*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 3))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 4},
        /*port_p35*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 4))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 5},
        /*port_p36*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 5))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 6}};
    void gpio_set_function(port_number_t port, uint8_t function);

    uint8_t gpio_get_function(port_number_t port);

    uint8_t gpio_digital_read(port_number_t port);
    void gpio_digital_write(port_number_t port, uint8_t value);
    uint8_t gpio_get_function(port_number_t port) { return *(__port_info[port].sel); }

#define __set_port_flag(port_num, property, value) __port_info[port_num].port->property = ((__port_info[port_num].port->property & ~(1 << __port_info[port_num].position)) | (value << __port_info[port_num].position))
#define __get_port_flag(port_num, property) ((__port_info[port_num].port->property >> __port_info[port_num].position) & 0x01)
    void gpio_set_function(port_number_t port, uint8_t function)
    {
        *(__port_info[port].sel) = function;
    }
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
        uint8_t function : 3;
    } gpio_port_config_t;
    typedef struct
    {
        port_number_t port : 8;
        uint8_t enabled : 1;
        gpio_interrupt_high_t interrupt_high : 1;
        gpio_interrupt_low_t interrupt_low : 1;
        gpio_interrupt_rising_t interrupt_rising : 1;
        gpio_interrupt_falling_t interrupt_falling : 1;
    } gpio_interrupt_config_t;

    __read_only_data gpio_port_config_t gpio_digital_output = {
        .direction = gpio_output,
        .resolution = gpio_digital,
        .drive_mode = gpio_drive_high,
        .pull_up = gpio_pullup_enable,
        .pull_down = gpio_pulldown_disable,
        .gpio_mode = gpio_mode_push_pull};
    __read_only_data gpio_port_config_t gpio_digital_input = {
        .direction = gpio_input,
        .resolution = gpio_digital,
        .drive_mode = 0,
        .pull_up = 0,
        .pull_down = 0,
        .gpio_mode = 0};

    void gpio_set_config(port_number_t port, gpio_port_config_t cfg);
    gpio_port_config_t gpio_get_config(port_number_t port);

    void gpio_set_config(port_number_t port, gpio_port_config_t cfg)
    {
        __set_port_flag(port, DIR, cfg.direction);
        __set_port_flag(port, ADS, cfg.resolution);
        __set_port_flag(port, DR, cfg.drive_mode);
        __set_port_flag(port, PU, cfg.pull_up);
        __set_port_flag(port, PD, cfg.pull_down);
        __set_port_flag(port, OD, cfg.gpio_mode);
        *(__port_info[port].sel) = cfg.function;
    }

    uint8_t gpio_digital_read(port_number_t port)
    {
        return __get_port_flag(port, IN);
    }
    void gpio_digital_write(port_number_t port, uint8_t value)
    {
        __set_port_flag(port, OUT, value);
    }
    void gpio_clear_interrupt(port_number_t port_num)
    {
        __port_info[port_num].interrupt->ICLR = (__port_info[port_num].interrupt->ICLR & ~(1 << __port_info[port_num].position));
    }
    typedef void (*gpio_port_handler_t)(port_number_t port_number);
    gpio_port_handler_t *__port_handlers[16] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

#define gpio_disable_interrupt(port_number) (gpio_interrupt_config_t) port_number, NULL
    void gpio_configure_interrupt(gpio_interrupt_config_t cfg, gpio_port_handler_t *handler)
    {
        __set_port_flag(cfg.port, HIE, cfg.interrupt_high);
        __set_port_flag(cfg.port, LIE, cfg.interrupt_low);
        __set_port_flag(cfg.port, RIE, cfg.interrupt_rising);
        __set_port_flag(cfg.port, FIE, cfg.interrupt_falling);
        __port_handlers[cfg.port] = handler;
    }
    void __handle_gpio_interrupt(port_number_t low, port_number_t high)
    {
        for (uint32_t i = low; i <= high; i++)
        {
            if (__port_handlers[i] != NULL && (__port_info[i].interrupt->STAT & (0x01 << __port_info[i].position) > 0))
            {
                (*__port_handlers[i])((port_number_t)i);
            }
        }
    }
    void GpioPort0_Handler(void)
    {
        __handle_gpio_interrupt(port_p01, port_p03);
    }
    void GpioPort1_Handler(void)
    {
        __handle_gpio_interrupt(port_p14, port_p15);
    }
    void GpioPort2_Handler(void)
    {
        __handle_gpio_interrupt(port_p23, port_p27);
    }
    void GpioPort3_Handler(void)
    {
        __handle_gpio_interrupt(port_p31, port_p36);
    }
#ifdef __cplusplus
}
#endif

#endif
#endif