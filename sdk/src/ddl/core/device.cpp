#include "hc32l110_system.h"

#include "ddl/core/core.h"

void Device::enabled(peripheral_t peripheral){
    HC32_CLOCK->peripheral_clock_enable = peripheral;
}
peripheral_t Device::enabled(){
    return HC32_CLOCK->peripheral_clock_enable;
}

void Device::enable(peripheral_t peripheral){
    HC32_CLOCK->peripheral_clock_enable = (peripheral_t)(HC32_CLOCK->peripheral_clock_enable | peripheral);
}
void Device::disable(peripheral_t peripheral){
     HC32_CLOCK->peripheral_clock_enable = (peripheral_t)(HC32_CLOCK->peripheral_clock_enable & ~peripheral);
}
