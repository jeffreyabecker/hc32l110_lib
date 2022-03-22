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
        uint8_t enabled : 1;
        gpio_interrupt_high_t interrupt_high : 1;
        gpio_interrupt_low_t interrupt_low : 1;
        gpio_interrupt_rising_t interrupt_rising : 1;
        gpio_interrupt_falling_t interrupt_falling : 1;
    } gpio_interrupt_config_t;
    typedef struct
    {
        uint32_t *sel;
        port_ctl_t *port;
        port_interrupt_t *interrupt;
        uint8_t position;
        uint8_t index;
    } port_descriptor_t;

    typedef void (*gpio_port_handler_t)(const port_descriptor_t *port_number);

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

    uint8_t gpio_digital_read(const port_descriptor_t *port);
    void gpio_digital_write(const port_descriptor_t *port, uint8_t value);
    void gpio_configure(const port_descriptor_t *port, gpio_port_config_t cfg);
    void _interrupt(const port_descriptor_t *port, gpio_interrupt_config_t cfg, gpio_port_handler_t *handler);
    void gpio_clear_interrupt(const port_descriptor_t *port);

    __read_only_data port_descriptor_t port_descriptors[16] = {
        /*port_p01*/
        {
            .sel = ((uint32_t *)0x40020C04),
            .port = ((port_ctl_t *)0x40020CD0),
            .interrupt = ((port_interrupt_t *)0x40020DD0),
            .position = 1,
            .index = 0},
        /*port_p02*/
        {
            .sel = ((uint32_t *)0x40020C08),
            .port = ((port_ctl_t *)0x40020CD0),
            .interrupt = ((port_interrupt_t *)0x40020DD0),
            .position = 2,
            .index = 1},
        /*port_p03*/
        {
            .sel = ((uint32_t *)0x40020C0C),
            .port = ((port_ctl_t *)0x40020CD0),
            .interrupt = ((port_interrupt_t *)0x40020DD0),
            .position = 3,
            .index = 2},

        /*port_p14*/
        {
            .sel = ((uint32_t *)0x40020C50),
            .port = ((port_ctl_t *)0x40020D10),
            .interrupt = ((port_interrupt_t *)0x40020E10),
            .position = 5,
            .index = 3},
        /*port_p15*/
        {
            .sel = ((uint32_t *)0x40020C54),
            .port = ((port_ctl_t *)0x40020D10),
            .interrupt = ((port_interrupt_t *)0x40020E10),
            .position = 6,
            .index = 4},

        /*port_p23*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 0)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 4,
            .index = 5},
        /*port_p24*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 4)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 5,
            .index = 6},
        /*port_p25*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 8)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 6,
            .index = 7},
        /*port_p26*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 12)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 7,
            .index = 8},
        /*port_p27*/
        {
            .sel = ((uint32_t *)(0x40020C8C + 16)),
            .port = ((port_ctl_t *)0x40020D50),
            .interrupt = ((port_interrupt_t *)0x40020E50),
            .position = 8,
            .index = 9},

        /*port_p31*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 0))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 1,
            .index = 10},
        /*port_p32*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 1))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 2,
            .index = 11},
        /*port_p33*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 2))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 3,
            .index = 12},
        /*port_p34*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 3))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 4,
            .index = 13},
        /*port_p35*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 4))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 5,
            .index = 14},
        /*port_p36*/
        {
            .sel = ((uint32_t *)(0x40020CC4 + (4 * 5))),
            .port = ((port_ctl_t *)0x40020D90),
            .interrupt = ((port_interrupt_t *)0x40020E90),
            .position = 6,
            .index = 15}};

#define gpio_port_p01 (&(port_descriptors[0]))
#define gpio_port_p02 (&(port_descriptors[1]))
#define gpio_port_p03 (&(port_descriptors[2]))
#define gpio_port_p14 (&(port_descriptors[3]))
#define gpio_port_p15 (&(port_descriptors[4]))
#define gpio_port_p23 (&(port_descriptors[5]))
#define gpio_port_p24 (&(port_descriptors[6]))
#define gpio_port_p25 (&(port_descriptors[7]))
#define gpio_port_p26 (&(port_descriptors[8]))
#define gpio_port_p27 (&(port_descriptors[9]))
#define gpio_port_p31 (&(port_descriptors[10]))
#define gpio_port_p32 (&(port_descriptors[11]))
#define gpio_port_p33 (&(port_descriptors[12]))
#define gpio_port_p34 (&(port_descriptors[13]))
#define gpio_port_p35 (&(port_descriptors[14]))
#define gpio_port_p36 (&(port_descriptors[15]))
#define __set_port_flag(port_num, property, value) port_descriptors[port_num].port->property = ((port_descriptors[port_num].port->property & ~(1 << port_descriptors[port_num].position)) | (value << port_descriptors[port_num].position))
#define __get_port_flag(port_num, property) ((port_descriptors[port_num].port->property >> port_descriptors[port_num].position) & 0x01)

    void gpio_configure(const port_descriptor_t *port, gpio_port_config_t cfg)
    {
        core_peripheral_set_enabled(peripheral_gpio);
        port->port->DIR = cfg.direction;
        port->port->ADS = cfg.resolution;
        port->port->DR = cfg.drive_mode;
        port->port->PU = cfg.pull_up;
        port->port->PD = cfg.pull_down;
        port->port->OD = cfg.gpio_mode;
        *(port->sel) = cfg.function;
    }

    uint8_t gpio_digital_read(const port_descriptor_t *port)
    {
        return (port->port->IN >> port->position) & 0x01;
    }
    void gpio_digital_write(const port_descriptor_t *port, uint8_t value)
    {
        port->port->OUT = (port->port->OUT & ~(1 << port->position)) | (value << port->position);
    }
    void gpio_clear_interrupt(const port_descriptor_t *port)
    {
        port->interrupt->ICLR = (port->interrupt->ICLR & ~(1 << port->position));
    }

    gpio_port_handler_t *__port_handlers[16] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

#define gpio_disable_interrupt(port_number) (gpio_interrupt_config_t) port_number, NULL
    void gpio_configure_interrupt(const port_descriptor_t *port, gpio_interrupt_config_t cfg, gpio_port_handler_t *handler)
    {
        port->port->HIE = cfg.interrupt_high;
        port->port->LIE = cfg.interrupt_low;
        port->port->RIE = cfg.interrupt_rising;
        port->port->FIE = cfg.interrupt_falling;
        __port_handlers[port->index] = handler;
    }
    void __handle_gpio_interrupt(uint32_t low, uint32_t high)
    {
        for (uint32_t i = low; i <= high; i++)
        {
            if (__port_handlers[i] != NULL && ((port_descriptors[i].interrupt->STAT & (0x01 << port_descriptors[i].position)) > 0))
            {
                (*__port_handlers[i])(&port_descriptors[i]);
            }
        }
    }

    void GpioPort0_Handler(void)
    {
        __handle_gpio_interrupt(0, 2);
    }
    void GpioPort1_Handler(void)
    {
        __handle_gpio_interrupt(3, 4);
    }
    void GpioPort2_Handler(void)
    {
        __handle_gpio_interrupt(5, 9);
    }
    void GpioPort3_Handler(void)
    {
        __handle_gpio_interrupt(10, 15);
    }
#ifdef __cplusplus
}
#endif

#endif
#endif