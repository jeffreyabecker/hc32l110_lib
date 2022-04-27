#include "hc32l110_system.h"

#include "ddl/core/core.h"


#include <stdint.h>



void SystickDevice::configure(uint32_t frequency_hz){
    if (frequency_hz > 0)
    {
        Device::enable( peripheral_tick);
        uint32_t ticks = (system_clock.peripheral_frequency()) / frequency_hz;

        HC32_SYSTICK->LOAD = (uint32_t)(ticks - 1UL); /* set reload register */
        Nvic::set_priority(irq_sys_tick, Nvic::default_priority);
        HC32_SYSTICK->VAL = 0UL; /* Load the SysTick Counter Value */
        this->running(1);
    }
    else
    {
        this->running(0);
         Device::disable(peripheral_tick);
    }
}
uint32_t SystickDevice:: count(){
    return HC32_SYSTICK->VAL;
}
void SystickDevice::count(uint32_t value){
    HC32_SYSTICK->VAL = value;
}
#define SYSTICK_RUNNING_MASK 0x00000007
void SystickDevice::running(uint8_t enabled){
    if(enabled){
        HC32_SYSTICK->CTRL = SYSTICK_RUNNING_MASK;
    }
    else{
        HC32_SYSTICK->CTRL &= ~(SYSTICK_RUNNING_MASK);
    }
}
uint8_t SystickDevice::running() {
    return ((HC32_SYSTICK->CTRL & SYSTICK_RUNNING_MASK) == SYSTICK_RUNNING_MASK);
}

uint8_t SystickDevice::has_interrupt(){
    return 0;
};
void SystickDevice::clear_interrupt(){};


SystickDevice systick;
TimerCounter systick_timer(&systick);
void SysTick_Handler(void)
{
    systick.interrupt.invoke(irq_sys_tick);

}