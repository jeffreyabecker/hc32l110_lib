#include "hc32l110_system.h"
#include "ddl/gpio.h"
#include "ddl/core/core.h"

#include <stddef.h>

__attribute__((section(".rodata"))) const gpio_port_config_t gpio_digital_output_cfg = {
    .direction = gpio_output,
    .resolution = gpio_digital,
    .drive_mode = gpio_drive_high,
    .pull_up = gpio_pullup_enable,
    .pull_down = gpio_pulldown_disable,
    .gpio_mode = gpio_mode_push_pull,
    .function = 0,
    .enable_interrupt = 0,
    .interrupt_high = gpio_interrupt_high_disable,
    .interrupt_low = gpio_interrupt_low_disable,
    .interrupt_rising = gpio_interrupt_rising_disable,
    .interrupt_falling = gpio_interrupt_falling_disable,
};

__attribute__((section(".rodata"))) const gpio_port_config_t gpio_digital_input_cfg = {
    .direction = gpio_input,
    .resolution = gpio_digital,
    .drive_mode = gpio_drive_high,
    .pull_up = gpio_pullup_disable,
    .pull_down = gpio_pulldown_disable,
    .gpio_mode = gpio_mode_push_pull,
    .function = 0,
    .enable_interrupt = 0,
    .interrupt_high = gpio_interrupt_high_disable,
    .interrupt_low = gpio_interrupt_low_disable,
    .interrupt_rising = gpio_interrupt_rising_disable,
    .interrupt_falling = gpio_interrupt_falling_disable};



void GpioPort::enable()
{
    Device::enable( peripheral_gpio);
}
void GpioPort::disable()
{
    Device::disable( peripheral_gpio);
}
GpioPort::GpioPort(uint32_t *sel, gpio_port_ctl_t *port, gpio_port_interrupt_t *i, uint8_t position, irq_t irq)
    : _sel{sel},
    _port{port},
    _interrupt{i},
    _position{position},
    _irq{irq}
{ }


void GpioPort::configure(const gpio_port_config_t *cfg)
{
    this->direction(cfg->direction);
    this->resolution(cfg->resolution);
    this->drive_mode(cfg->drive_mode);
    this->pull_up(cfg->pull_up);
    this->pull_down(cfg->pull_down);
    this->gpio_mode(cfg->gpio_mode);
    this->function(cfg->function);
    this->enable_interrupt(cfg->enable_interrupt);
    this->interrupt_high(cfg->interrupt_high);
    this->interrupt_low(cfg->interrupt_low);
    this->interrupt_rising(cfg->interrupt_rising);
    this->interrupt_falling(cfg->interrupt_falling);   
}
uint8_t GpioPort::digital_read()
{
    return (this->_port->IN >> this->_position) & 0x01;
}
void GpioPort::digital_write(const uint8_t bit)
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

uint8_t GpioPort::function() { return (uint8_t) * (this->_sel); }
void GpioPort::function(uint8_t value) { *(this->_sel) = value; }

uint8_t GpioPort::enable_interrupt() { return (uint8_t)Nvic::is_enabled(this->_irq); }
void GpioPort::enable_interrupt(uint8_t value)
{

    if (value)
    {
        Nvic::set_priority(this->_irq, Nvic::default_priority);
        Nvic::enable(this->_irq);
    }
    else
    {
        Nvic::disable(this->_irq);
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
    gpio_port_p01.interrupt.invoke(irq_port_0);
    gpio_port_p02.interrupt.invoke(irq_port_0);
    gpio_port_p03.interrupt.invoke(irq_port_0);
    HC32_GPIO_PORT0_INTERRUPT->ICLR = 0;
    Nvic::clear(irq_port_0);
}
void IRQ01_Handler(void)
{
    gpio_port_p14.interrupt.invoke(irq_port_1);
    gpio_port_p15.interrupt.invoke(irq_port_1);
    HC32_GPIO_PORT1_INTERRUPT->ICLR = 0;
    Nvic::clear(irq_port_1);
}
void IRQ02_Handler(void)
{
    gpio_port_p23.interrupt.invoke(irq_port_2);
    gpio_port_p24.interrupt.invoke(irq_port_2);
    gpio_port_p25.interrupt.invoke(irq_port_2);
    gpio_port_p26.interrupt.invoke(irq_port_2);
    gpio_port_p27.interrupt.invoke(irq_port_2);
    HC32_GPIO_PORT2_INTERRUPT->ICLR = 0;
    Nvic::clear(irq_port_2);
}
void IRQ03_Handler(void)
{
    gpio_port_p31.interrupt.invoke(irq_port_3);
    gpio_port_p32.interrupt.invoke(irq_port_3);
    gpio_port_p33.interrupt.invoke(irq_port_3);
    gpio_port_p34.interrupt.invoke(irq_port_3);
    gpio_port_p35.interrupt.invoke(irq_port_3);
    gpio_port_p36.interrupt.invoke(irq_port_3);
    HC32_GPIO_PORT3_INTERRUPT->ICLR = 0;
    Nvic::clear(irq_port_3);
}