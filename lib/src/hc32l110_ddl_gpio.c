#include "hc32l110_ddl_gpio.h"
#include "hc32l110_ddl_core.h"
#include <stddef.h>

__read_only_data gpio_port_descriptor_t port_descriptors[16] = {
    /*port_p01*/
    {
        .sel = HC32_GPIO_P01_SEL,
        .port = HC32_GPIO_PORT0,
        .interrupt = HC32_GPIO_PORT0_INTERRUPT,
        .position = 1,
        .index = 0,
        .irq = PORT0_IRQn},
    /*port_p02*/
    {
        .sel = HC32_GPIO_P02_SEL,
        .port = HC32_GPIO_PORT0,
        .interrupt = HC32_GPIO_PORT0_INTERRUPT,
        .position = 2,
        .index = 1,
        .irq = PORT0_IRQn},
    /*port_p03*/
    {
        .sel = HC32_GPIO_P03_SEL,
        .port = HC32_GPIO_PORT0,
        .interrupt = HC32_GPIO_PORT0_INTERRUPT,
        .position = 3,
        .index = 2,
        .irq = PORT0_IRQn},

    /*port_p14*/
    {
        .sel = HC32_GPIO_P14_SEL,
        .port = HC32_GPIO_PORT1,
        .interrupt = HC32_GPIO_PORT1_INTERRUPT,
        .position = 4,
        .index = 3,
        .irq = PORT1_IRQn},
    /*port_p15*/
    {
        .sel = HC32_GPIO_P15_SEL,
        .port = HC32_GPIO_PORT1,
        .interrupt = HC32_GPIO_PORT1_INTERRUPT,
        .position = 5,
        .index = 4,
        .irq = PORT1_IRQn},

    /*port_p23*/
    {
        .sel = HC32_GPIO_P23_SEL,
        .port = HC32_GPIO_PORT2,
        .interrupt = HC32_GPIO_PORT2_INTERRUPT,
        .position = 3,
        .index = 5,
        .irq = PORT2_IRQn},
    /*port_p24*/
    {
        .sel = HC32_GPIO_P24_SEL,
        .port = HC32_GPIO_PORT2,
        .interrupt = HC32_GPIO_PORT2_INTERRUPT,
        .position = 4,
        .index = 6,
        .irq = PORT2_IRQn},
    /*port_p25*/
    {
        .sel = HC32_GPIO_P25_SEL,
        .port = HC32_GPIO_PORT2,
        .interrupt = HC32_GPIO_PORT2_INTERRUPT,
        .position = 5,
        .index = 7},
    /*port_p26*/
    {
        .sel = HC32_GPIO_P26_SEL,
        .port = HC32_GPIO_PORT2,
        .interrupt = HC32_GPIO_PORT2_INTERRUPT,
        .position = 6,
        .index = 8,
        .irq = PORT2_IRQn},
    /*port_p27*/
    {
        .sel = HC32_GPIO_P27_SEL,
        .port = HC32_GPIO_PORT2,
        .interrupt = HC32_GPIO_PORT2_INTERRUPT,
        .position = 7,
        .index = 9,
        .irq = PORT2_IRQn},

    /*port_p31*/
    {
        .sel = HC32_GPIO_P31_SEL,
        .port = HC32_GPIO_PORT3,
        .interrupt = HC32_GPIO_PORT3_INTERRUPT,
        .position = 1,
        .index = 10,
        .irq = PORT3_IRQn},
    /*port_p32*/
    {
        .sel = HC32_GPIO_P32_SEL,
        .port = HC32_GPIO_PORT3,
        .interrupt = HC32_GPIO_PORT3_INTERRUPT,
        .position = 2,
        .index = 11,
        .irq = PORT3_IRQn},
    /*port_p33*/
    {
        .sel = HC32_GPIO_P33_SEL,
        .port = HC32_GPIO_PORT3,
        .interrupt = HC32_GPIO_PORT3_INTERRUPT,
        .position = 3,
        .index = 12,
        .irq = PORT3_IRQn},
    /*port_p34*/
    {
        .sel = HC32_GPIO_P34_SEL,
        .port = HC32_GPIO_PORT3,
        .interrupt = HC32_GPIO_PORT3_INTERRUPT,
        .position = 4,
        .index = 13,
        .irq = PORT3_IRQn},
    /*port_p35*/
    {
        .sel = HC32_GPIO_P35_SEL,
        .port = HC32_GPIO_PORT3,
        .interrupt = HC32_GPIO_PORT3_INTERRUPT,
        .position = 5,
        .index = 14,
        .irq = PORT3_IRQn},
    /*port_p36*/
    {
        .sel = HC32_GPIO_P36_SEL,
        .port = HC32_GPIO_PORT3,
        .interrupt = HC32_GPIO_PORT3_INTERRUPT,
        .position = 6,
        .index = 15,
        .irq = PORT3_IRQn}};

void gpio_configure(const gpio_port_descriptor_t *port, gpio_port_config_t cfg)
{
    port->port->DIR = ((port->port->DIR & ~(1 << port->position)) | (cfg.direction << port->position));
    port->port->ADS = ((port->port->ADS & ~(1 << port->position)) | (cfg.resolution << port->position));
    port->port->DR = ((port->port->DR & ~(1 << port->position)) | (cfg.drive_mode << port->position));
    port->port->PU = ((port->port->PU & ~(1 << port->position)) | (cfg.pull_up << port->position));
    port->port->PD = ((port->port->PD & ~(1 << port->position)) | (cfg.pull_down << port->position));
    port->port->OD = ((port->port->OD & ~(1 << port->position)) | (cfg.gpio_mode << port->position));
    *(port->sel) = cfg.function;
    nvic_configure_interrupt(port->irq, nvic_default_irq_priority, cfg.enable_interrupt);
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

gpio_port_handler_t __port_handlers[16] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

void gpio_set_interrupt_handler(const gpio_port_descriptor_t *port, gpio_interrupt_config_t cfg, gpio_port_handler_t handler)
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
        if (((port_descriptors[i].interrupt->STAT & (0x01 << port_descriptors[i].position)) > 0))
        {
            if (__port_handlers[i] != NULL)
            {
                (*__port_handlers[i])(&port_descriptors[i]);
            }
            port_descriptors[i].interrupt->ICLR &= ~(1 << port_descriptors[i].position);
        }
    }
}

void GpioPort0_Handler(void)
{
    __handle_gpio_interrupt(0, 2);
    nvic_clear_interrupt(PORT0_IRQn);
}
void GpioPort1_Handler(void)
{
    __handle_gpio_interrupt(3, 4);
    nvic_clear_interrupt(PORT1_IRQn);
}
void GpioPort2_Handler(void)
{
    __handle_gpio_interrupt(5, 9);
    nvic_clear_interrupt(PORT2_IRQn);
}
void GpioPort3_Handler(void)
{
    __handle_gpio_interrupt(10, 15);
    nvic_clear_interrupt(PORT3_IRQn);
}
void peripheral_enable_gpio()
{

    HC32_GPIO_PORT0->DIR = 0xFF;
    HC32_GPIO_PORT1->DIR = 0xFF;
    HC32_GPIO_PORT2->DIR = 0xFF;
    HC32_GPIO_PORT3->DIR = 0xFF;
    HC32_GPIO_PORT0->OD = 0x00;
    HC32_GPIO_PORT1->OD = 0x00;
    HC32_GPIO_PORT2->OD = 0x00;
    HC32_GPIO_PORT3->OD = 0x00;

    peripheral_set_enabled(peripheral_get_enabled() | peripheral_gpio);
}