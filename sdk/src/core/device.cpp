#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_system.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"

void Device::enabled(peripheral_t peripheral){
    HC32_CLOCK->peripheral_clock_enable = peripheral;
}
peripheral_t Device::enabled(){
    return HC32_CLOCK->peripheral_clock_enable;
}

void Device::enable(peripheral_t peripheral){
    HC32_CLOCK->peripheral_clock_enable = HC32_CLOCK->peripheral_clock_enable | peripheral
}
void Device::disable(peripheral_t peripheral){
     HC32_CLOCK->peripheral_clock_enable = HC32_CLOCK->peripheral_clock_enable & ~peripheral;
}
