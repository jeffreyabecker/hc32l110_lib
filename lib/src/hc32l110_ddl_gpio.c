#include "hc32l110_ddl_gpio.h"
#include "hc32l110_ddl_core.h"
#include <stddef.h>

__read_only_data gpio_port_descriptor_t port_descriptors[16] = {
    /*port_p01*/
    {
        .sel = ((uint32_t *)0x40020C04),
        .port = M0P_GPIO_PORT0,
        .interrupt = ((gpio_port_interrupt_t *)0x40020DD0),
        .position = 1,
        .index = 0},
    /*port_p02*/
    {
        .sel = ((uint32_t *)0x40020C08),
        .port = M0P_GPIO_PORT0,
        .interrupt = ((gpio_port_interrupt_t *)0x40020DD0),
        .position = 2,
        .index = 1},
    /*port_p03*/
    {
        .sel = ((uint32_t *)0x40020C0C),
        .port = M0P_GPIO_PORT0,
        .interrupt = ((gpio_port_interrupt_t *)0x40020DD0),
        .position = 3,
        .index = 2},

    /*port_p14*/
    {
        .sel = ((uint32_t *)0x40020C50),
        .port = M0P_GPIO_PORT1,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E10),
        .position = 5,
        .index = 3},
    /*port_p15*/
    {
        .sel = ((uint32_t *)0x40020C54),
        .port = M0P_GPIO_PORT1,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E10),
        .position = 6,
        .index = 4},

    /*port_p23*/
    {
        .sel = ((uint32_t *)(0x40020C8c)),
        .port = M0P_GPIO_PORT2,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E50),
        .position = 4,
        .index = 5},
    /*port_p24*/
    {
        .sel = ((uint32_t *)(0x40020C90)),
        .port = M0P_GPIO_PORT2,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E50),
        .position = 5,
        .index = 6},
    /*port_p25*/
    {
        .sel = ((uint32_t *)(0x40020C94)),
        .port = ((gpio_port_ctl_t *)0x40020D50),
        .interrupt = ((gpio_port_interrupt_t *)0x40020E50),
        .position = 6,
        .index = 7},
    /*port_p26*/
    {
        .sel = ((uint32_t *)(0x40020C98)),
        .port = M0P_GPIO_PORT2,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E50),
        .position = 7,
        .index = 8},
    /*port_p27*/
    {
        .sel = ((uint32_t *)(0x40020C9C)),
        .port = M0P_GPIO_PORT2,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E50),
        .position = 8,
        .index = 9},

    /*port_p31*/
    {
        .sel = ((uint32_t *)(0x40020CC4)),
        .port = M0P_GPIO_PORT3,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E90),
        .position = 1,
        .index = 10},
    /*port_p32*/
    {
        .sel = ((uint32_t *)(0x40020CC8)),
        .port = M0P_GPIO_PORT3,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E90),
        .position = 2,
        .index = 11},
    /*port_p33*/
    {
        .sel = ((uint32_t *)(0x40020CCC)),
        .port = M0P_GPIO_PORT3,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E90),
        .position = 3,
        .index = 12},
    /*port_p34*/
    {
        .sel = ((uint32_t *)(0x40020CD0)),
        .port = M0P_GPIO_PORT3,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E90),
        .position = 4,
        .index = 13},
    /*port_p35*/
    {
        .sel = ((uint32_t *)(0x40020CD4)),
        .port = ((gpio_port_ctl_t *)0x40020D90),
        .interrupt = ((gpio_port_interrupt_t *)0x40020E90),
        .position = 5,
        .index = 14},
    /*port_p36*/
    {
        .sel = ((uint32_t *)(0x40020CD8)),
        .port = M0P_GPIO_PORT3,
        .interrupt = ((gpio_port_interrupt_t *)0x40020E90),
        .position = 6,
        .index = 15}};

void gpio_configure(const gpio_port_descriptor_t *port, gpio_port_config_t cfg)
{
    port->port->DIR = ((port->port->DIR & ~(1 << port->position)) | (cfg.direction << port->position));
    port->port->ADS = ((port->port->ADS & ~(1 << port->position)) | (cfg.resolution << port->position));
    port->port->DR = ((port->port->DR & ~(1 << port->position)) | (cfg.drive_mode << port->position));
    port->port->PU = ((port->port->PU & ~(1 << port->position)) | (cfg.pull_up << port->position));
    port->port->PD = ((port->port->PD & ~(1 << port->position)) | (cfg.pull_down << port->position));
    port->port->OD = ((port->port->OD & ~(1 << port->position)) | (cfg.gpio_mode << port->position));
    *(port->sel) = cfg.function;
}

uint8_t gpio_digital_read(const gpio_port_descriptor_t *port)
{
    return (port->port->IN >> port->position) & 0x01;
}
void gpio_digital_write(const gpio_port_descriptor_t *port, uint8_t value)
{
    port->port->OUT = (port->port->OUT & ~(1 << port->position)) | (value << port->position);
}
void gpio_clear_interrupt(const gpio_port_descriptor_t *port)
{
    port->interrupt->ICLR = (port->interrupt->ICLR & ~(1 << port->position));
}

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

gpio_port_handler_t *__port_handlers[16] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

void gpio_set_interrupt_handler(const gpio_port_descriptor_t *port, gpio_interrupt_config_t cfg, gpio_port_handler_t *handler)
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
void peripheral_enable_gpio()
{

    M0P_GPIO_PORT0->DIR = 0xFF;
    M0P_GPIO_PORT1->DIR = 0xFF;
    M0P_GPIO_PORT2->DIR = 0xFF;
    M0P_GPIO_PORT3->DIR = 0xFF;
    M0P_GPIO_PORT0->OD = 0x00;
    M0P_GPIO_PORT1->OD = 0x00;
    M0P_GPIO_PORT2->OD = 0x00;
    M0P_GPIO_PORT3->OD = 0x00;

    peripheral_set_enabled(peripheral_get_enabled() | peripheral_gpio);
}