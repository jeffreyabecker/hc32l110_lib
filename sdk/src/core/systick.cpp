#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_system.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>








SysTickPeripheral::SysTickPeripheral(): _counter(0){}
void SysTickPeripheral::configure(uint32_t frequency_hz){
    if (frequency_hz > 0)
    {
        peripheral_set_enabled((peripheral_t)( peripheral_get_enabled() | peripheral_tick));
        uint32_t ticks = (PeripheralCoreClock) / frequency_hz;

        HC32_SYSTICK->LOAD = (uint32_t)(ticks - 1UL); /* set reload register */
        Nvic::set_priority(irq_sys_tick, Nvic::default_priority);
        HC32_SYSTICK->VAL = 0UL; /* Load the SysTick Counter Value */
        this->start();
    }
    else
    {
        this->stop();
        peripheral_set_enabled((peripheral_t)(peripheral_get_enabled() & ~peripheral_tick));
    }
}
uint32_t SysTickPeripheral::current(){ return this->_counter;}
uint32_t SysTickPeripheral::elapsed_since(uint32_t timestamp){
    return this->_counter - timestamp;
}
void SysTickPeripheral::delay(uint32_t ticks){
    uint32_t end = this->_counter + ticks;
    while(this->_counter != end){
        __nop();
    }
}
#define SYSTICK_RUNNING_MASK 0x00000007
void SysTickPeripheral::start(){
    this->_counter = 0;
    HC32_SYSTICK->CTRL = SYSTICK_RUNNING_MASK;
}
void SysTickPeripheral::stop(){
    HC32_SYSTICK->CTRL &= ~(SYSTICK_RUNNING_MASK);
    this->_counter = 0;
}

void SysTickPeripheral::invoke_interrupt(){
    this->_counter++;
}
uint8_t SysTickPeripheral::running(){
    return ((HC32_SYSTICK->CTRL & SYSTICK_RUNNING_MASK) == SYSTICK_RUNNING_MASK);
}
SysTickPeripheral systick;
void SysTick_Handler(void)
{
    systick.invoke_interrupt();

}