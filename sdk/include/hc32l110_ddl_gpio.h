#ifndef __HC32L110_DDL_GPIO__H__
#define __HC32L110_DDL_GPIO__H__

#include "hc32l110_system.h"

#include "hc32l110_ddl_core.h"
#include "hc32l110_registers.h"
#include "hc32l110_ddl_interrupt_invocation_handler.h"

typedef struct
{
    gpio_direction_t direction : 1;
    gpio_analog_digital_t resolution : 1;
    gpio_drive_capability_t drive_mode : 1;
    gpio_internal_pullup_t pull_up : 1;
    gpio_internal_pulldown_t pull_down : 1;
    gpio_mode_t gpio_mode : 1;
    uint8_t function : 3;
    uint8_t enable_interrupt : 1;
    gpio_interrupt_high_t interrupt_high : 1;
    gpio_interrupt_low_t interrupt_low : 1;
    gpio_interrupt_rising_t interrupt_rising : 1;
    gpio_interrupt_falling_t interrupt_falling : 1;
} gpio_port_config_t;

class GpioPort
{
private:
    uint32_t *_sel;
    gpio_port_ctl_t *_port;
    gpio_port_interrupt_t *_interrupt;
    uint8_t _position;
    irq_t _irq;
    InterruptInvocationHandler<GpioPort> *_handler;

public:
    static void enable_peripheral();
    GpioPort(uint32_t *sel, gpio_port_ctl_t *port, gpio_port_interrupt_t *interrupt, uint8_t position, irq_t irq);
    //const void configure(const gpio_port_config_t *cfg);
    const uint8_t digital_read();
    const void digital_write(uint8_t bit);
    const uint8_t has_interrupt();
    const void clear_interrupt();
    void set_interrupt_handler(InterruptInvocationHandler<GpioPort> *handler);
    void invoke_interrupt(irq_t irq);

    const gpio_direction_t direction();
    const void direction(gpio_direction_t value);
    const gpio_analog_digital_t resolution();
    const void resolution(gpio_analog_digital_t value);
    const gpio_drive_capability_t drive_mode();
    const void drive_mode(gpio_drive_capability_t value);
    const gpio_internal_pullup_t pull_up();
    const void pull_up(gpio_internal_pullup_t value);
    const gpio_internal_pulldown_t pull_down();
    const void pull_down(gpio_internal_pulldown_t value);
    const gpio_mode_t gpio_mode();
    const void gpio_mode(gpio_mode_t value);
    const uint8_t function();
    const void function(uint8_t value);
    const uint8_t enable_interrupt();
    const void enable_interrupt(uint8_t value);
    const gpio_interrupt_high_t interrupt_high();
    const void interrupt_high(gpio_interrupt_high_t value);
    const gpio_interrupt_low_t interrupt_low();
    const void interrupt_low(gpio_interrupt_low_t value);
    const gpio_interrupt_rising_t interrupt_rising();
    const void interrupt_rising(gpio_interrupt_rising_t value);
    const gpio_interrupt_falling_t interrupt_falling();
    const void interrupt_falling(gpio_interrupt_falling_t value);
};

// extern const gpio_port_config_t *gpio_digital_output;
// extern const gpio_port_config_t *gpio_digital_input;

extern GpioPort gpio_port_p01;
// extern GpioPort gpio_port_p02;
// extern GpioPort gpio_port_p03;
// extern GpioPort gpio_port_p14;
// extern GpioPort gpio_port_p15;
// extern GpioPort gpio_port_p23;
// extern GpioPort gpio_port_p24;
// extern GpioPort gpio_port_p25;
// extern GpioPort gpio_port_p26;
// extern GpioPort gpio_port_p27;
// extern GpioPort gpio_port_p31;
// extern GpioPort gpio_port_p32;
// extern GpioPort gpio_port_p33;
// extern GpioPort gpio_port_p34;
// extern GpioPort gpio_port_p35;
// extern GpioPort gpio_port_p36;
#endif
