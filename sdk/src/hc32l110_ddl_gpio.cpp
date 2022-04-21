#include "hc32l110_registers_clock.h"
#include "hc32l110_ddl_gpio.h"
#include "hc32l110_ddl_core.h"
#include <stddef.h>


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
    .drive_mode = gpio_drive_high,
    .pull_up = gpio_pullup_disable,
    .pull_down = gpio_pulldown_disable,
    .gpio_mode = gpio_mode_push_pull};

void GpioPort::enable_peripheral()
{
    HC32_GPIO_PORT0->DIR = 0xFF;
    HC32_GPIO_PORT1->DIR = 0xFF;
    HC32_GPIO_PORT2->DIR = 0xFF;
    HC32_GPIO_PORT3->DIR = 0xFF;
    HC32_GPIO_PORT0->OD = 0x00;
    HC32_GPIO_PORT1->OD = 0x00;
    HC32_GPIO_PORT2->OD = 0x00;
    HC32_GPIO_PORT3->OD = 0x00;
    peripheral_set_enabled((peripheral_t)(peripheral_get_enabled() | peripheral_gpio));
}
GpioPort::GpioPort(uint32_t *sel, gpio_port_ctl_t *port, gpio_port_interrupt_t *interrupt, uint8_t position, irq_t irq) : _sel(sel),
                                                                                                                          _port(port),
                                                                                                                          _interrupt(interrupt),
                                                                                                                          _position(position),
                                                                                                                          _irq(irq)
{
}
void configure(const gpio_port_config_t *cfg)
{
}
uint8_t GpioPort::digital_read()
{
    return (this->_port->IN >> this->_position) & 0x01;
}
void GpioPort::digital_write(uint8_t bit)
{
    this->_port->OUT = (this->_port->OUT & ~(1 << this->_position)) | (bit << this->_position);
}
uint8_t GpioPort::has_interrupt()
{
    return (this->_interrupt->STAT & (1 << this->_position)) > 0 ? 1 : 0;
}
void GpioPort::clear_interrupt()
{
    this->_interrupt->ICLR = (this->_interrupt->ICLR & ~(1 << this->_position));
}
void GpioPort::set_interrupt_handler(InterruptInvocationHandler<GpioPort> *handler)
{
    this->_handler = handler;
}
void GpioPort::invoke_interrupt(irq_t irq)
{
    if (this->has_interrupt() && this->_handler != NULL)
    {
        this->_handler->invoke(this, irq);
    }
}

gpio_direction_t GpioPort::direction() { return (gpio_direction_t)((this->_port->DIR & (1 << this->_position))); }
void GpioPort::direction(gpio_direction_t value) { this->_port->DIR = ((this->_port->DIR & ~(1 << this->_position)) | (value << this->_position)); }
gpio_analog_digital_t GpioPort::resolution() { return (gpio_analog_digital_t)((this->_port->ADS & (1 << this->_position))); }
void GpioPort::resolution(gpio_analog_digital_t value) { this->_port->ADS = ((this->_port->ADS & ~(1 << this->_position)) | (value << this->_position)); }
gpio_drive_capability_t GpioPort::drive_mode() { return (gpio_drive_capability_t)((this->_port->DR & (1 << this->_position))); }
void GpioPort::drive_mode(gpio_drive_capability_t value) { this->_port->DR = ((this->_port->DR & ~(1 << this->_position)) | (value << this->_position)); }
gpio_internal_pullup_t GpioPort::pull_up() { return (gpio_internal_pullup_t)((this->_port->PU & (1 << this->_position))); }
void GpioPort::pull_up(gpio_internal_pullup_t value) { this->_port->PU = ((this->_port->PU & ~(1 << this->_position)) | (value << this->_position)); }
gpio_internal_pulldown_t GpioPort::pull_down() { return (gpio_internal_pulldown_t)((this->_port->PD & (1 << this->_position))); }
void GpioPort::pull_down(gpio_internal_pulldown_t value) { this->_port->PD = ((this->_port->PD & ~(1 << this->_position)) | (value << this->_position)); }
gpio_mode_t GpioPort::gpio_mode() { return (gpio_mode_t)((this->_port->OD & (1 << this->_position))); }
void GpioPort::gpio_mode(gpio_mode_t value) { this->_port->OD = ((this->_port->OD & ~(1 << this->_position)) | (value << this->_position)); }

uint8_t GpioPort::function() { return (uint8_t) * (this->_sel); }
void GpioPort::function(uint8_t value) { *(this->_sel) = value; }

uint8_t GpioPort::enable_interrupt() { return (uint8_t)nvic_interrupt_enabled(this->_irq); }
void GpioPort::enable_interrupt(uint8_t value)
{

    if (value)
    {
        nvic_set_interrupt_priority(this->_irq, nvic_default_irq_priority);
        nvic_enable_interrupt(this->_irq);
    }
    else
    {
        nvic_disable_interrupt(this->_irq);
    }
}

gpio_interrupt_high_t GpioPort::interrupt_high() { return (gpio_interrupt_high_t)this->_port->HIE; }
void GpioPort::interrupt_high(gpio_interrupt_high_t value) { this->_port->HIE = value; }
gpio_interrupt_low_t GpioPort::interrupt_low() { return (gpio_interrupt_low_t)this->_port->LIE; }
void GpioPort::interrupt_low(gpio_interrupt_low_t value) { this->_port->LIE = value; }
gpio_interrupt_rising_t GpioPort::interrupt_rising() { return (gpio_interrupt_rising_t)this->_port->RIE; }
void GpioPort::interrupt_rising(gpio_interrupt_rising_t value) { this->_port->RIE = value; }
gpio_interrupt_falling_t GpioPort::interrupt_falling() { return (gpio_interrupt_falling_t)this->_port->FIE; }
void GpioPort::interrupt_falling(gpio_interrupt_falling_t value) { this->_port->FIE = value; }

GpioPort gpio_port_p01(HC32_GPIO_P01_SEL, HC32_GPIO_PORT0, HC32_GPIO_PORT0_INTERRUPT, 1, irq_port_0);
GpioPort gpio_port_p02(HC32_GPIO_P02_SEL, HC32_GPIO_PORT0, HC32_GPIO_PORT0_INTERRUPT, 2, irq_port_0);
GpioPort gpio_port_p03(HC32_GPIO_P03_SEL, HC32_GPIO_PORT0, HC32_GPIO_PORT0_INTERRUPT, 3, irq_port_0);
GpioPort gpio_port_p14(HC32_GPIO_P14_SEL, HC32_GPIO_PORT1, HC32_GPIO_PORT1_INTERRUPT, 4, irq_port_1);
GpioPort gpio_port_p15(HC32_GPIO_P15_SEL, HC32_GPIO_PORT1, HC32_GPIO_PORT1_INTERRUPT, 5, irq_port_1);
GpioPort gpio_port_p23(HC32_GPIO_P23_SEL, HC32_GPIO_PORT2, HC32_GPIO_PORT2_INTERRUPT, 3, irq_port_2);
GpioPort gpio_port_p24(HC32_GPIO_P24_SEL, HC32_GPIO_PORT2, HC32_GPIO_PORT2_INTERRUPT, 4, irq_port_2);
GpioPort gpio_port_p25(HC32_GPIO_P25_SEL, HC32_GPIO_PORT2, HC32_GPIO_PORT2_INTERRUPT, 5, irq_port_2);
GpioPort gpio_port_p26(HC32_GPIO_P26_SEL, HC32_GPIO_PORT2, HC32_GPIO_PORT2_INTERRUPT, 6, irq_port_2);
GpioPort gpio_port_p27(HC32_GPIO_P27_SEL, HC32_GPIO_PORT2, HC32_GPIO_PORT2_INTERRUPT, 7, irq_port_2);
GpioPort gpio_port_p31(HC32_GPIO_P31_SEL, HC32_GPIO_PORT3, HC32_GPIO_PORT3_INTERRUPT, 1, irq_port_3);
GpioPort gpio_port_p32(HC32_GPIO_P32_SEL, HC32_GPIO_PORT3, HC32_GPIO_PORT3_INTERRUPT, 2, irq_port_3);
GpioPort gpio_port_p33(HC32_GPIO_P33_SEL, HC32_GPIO_PORT3, HC32_GPIO_PORT3_INTERRUPT, 3, irq_port_3);
GpioPort gpio_port_p34(HC32_GPIO_P34_SEL, HC32_GPIO_PORT3, HC32_GPIO_PORT3_INTERRUPT, 4, irq_port_3);
GpioPort gpio_port_p35(HC32_GPIO_P35_SEL, HC32_GPIO_PORT3, HC32_GPIO_PORT3_INTERRUPT, 5, irq_port_3);
GpioPort gpio_port_p36(HC32_GPIO_P36_SEL, HC32_GPIO_PORT3, HC32_GPIO_PORT3_INTERRUPT, 6, irq_port_3);

void IRQ00_Handler(void)
{
    gpio_port_p01.invoke_interrupt(irq_port_0);
    gpio_port_p02.invoke_interrupt(irq_port_0);
    gpio_port_p03.invoke_interrupt(irq_port_0);
    nvic_clear_interrupt(irq_port_0);
}
void IRQ01_Handler(void)
{
    gpio_port_p14.invoke_interrupt(irq_port_1);
    gpio_port_p15.invoke_interrupt(irq_port_1);
    nvic_clear_interrupt(irq_port_1);
}
void IRQ02_Handler(void)
{
    gpio_port_p23.invoke_interrupt(irq_port_2);
    gpio_port_p24.invoke_interrupt(irq_port_2);
    gpio_port_p25.invoke_interrupt(irq_port_2);
    gpio_port_p26.invoke_interrupt(irq_port_2);
    gpio_port_p27.invoke_interrupt(irq_port_2);
    nvic_clear_interrupt(irq_port_2);
}
void IRQ03_Handler(void)
{
    gpio_port_p31.invoke_interrupt(irq_port_3);
    gpio_port_p32.invoke_interrupt(irq_port_3);
    gpio_port_p33.invoke_interrupt(irq_port_3);
    gpio_port_p34.invoke_interrupt(irq_port_3);
    gpio_port_p35.invoke_interrupt(irq_port_3);
    gpio_port_p36.invoke_interrupt(irq_port_3);
    nvic_clear_interrupt(irq_port_3);
}