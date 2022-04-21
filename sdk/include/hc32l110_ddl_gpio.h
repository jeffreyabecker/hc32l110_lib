#ifndef __HC32L110_DDL_GPIO__H__
#define __HC32L110_DDL_GPIO__H__
#ifdef __cplusplus
extern "C" {
#endif
#include "hc32l110_system.h"
#include "hc32l110_system.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_registers.h"
typedef struct
{
    uint32_t *sel;
    gpio_port_ctl_t *port;
    gpio_port_interrupt_t *interrupt;
    uint8_t position;
    uint8_t index;
    irq_t irq;
} gpio_port_descriptor_t;
extern const gpio_port_descriptor_t port_descriptors[16];

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

typedef struct
{
    gpio_direction_t direction : 1;
    gpio_analog_digital_t resolution : 1;
    gpio_drive_capability_t drive_mode : 1;
    gpio_internal_pullup_t pull_up : 1;
    gpio_internal_pulldown_t pull_down : 1;
    gpio_mode_t gpio_mode : 1;
    uint8_t function : 3;
    uint8_t enable_interrupt:1;
} gpio_port_config_t;

extern const gpio_port_config_t gpio_digital_output;
extern const gpio_port_config_t gpio_digital_input;
uint8_t gpio_digital_read(const gpio_port_descriptor_t *port);
void gpio_digital_write(const gpio_port_descriptor_t *port, uint8_t value);
void gpio_configure(const gpio_port_descriptor_t *port, gpio_port_config_t cfg);
void gpio_clear_interrupt(const gpio_port_descriptor_t *port);
typedef void (*gpio_port_handler_t)(const gpio_port_descriptor_t *port);
typedef struct
{
    uint8_t enabled : 1;
    gpio_interrupt_high_t interrupt_high : 1;
    gpio_interrupt_low_t interrupt_low : 1;
    gpio_interrupt_rising_t interrupt_rising : 1;
    gpio_interrupt_falling_t interrupt_falling : 1;
} gpio_interrupt_config_t;
void gpio_set_interrupt_handler(const gpio_port_descriptor_t *port, gpio_interrupt_config_t cfg, gpio_port_handler_t handler);
#define gpio_clear_interrupt_handler(port) gpio_set_interrupt_handler(port, (gpio_interrupt_config_t)NULL, NULL)

void peripheral_enable_gpio();
#ifdef __cplusplus
}
#endif
#endif
