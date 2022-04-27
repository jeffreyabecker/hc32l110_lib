#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_system.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>
uint32_t SystemCoreClock;
uint32_t PeripheralCoreClock;

__attribute__((always_inline)) static inline void __clock_config_unlock(void)
{
    HC32_CLOCK->SYSCTRL2 = 0x5A5A;
    HC32_CLOCK->SYSCTRL2 = 0xA5A5;
}
void clock_set_freq(uint32_t freqency_hz, uint16_t clock_trim)
{
    if (SystemCoreClock > KHz_38_4 && freqency_hz > KHz_38_4)
    {
        HC32_CLOCK->RCH_CR.TRIM = clock_trim;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock > KHz_38_4 && freqency_hz <= KHz_38_4)
    {
        // switching from RCH to RCL
        HC32_CLOCK->RCL_CR.TRIM = clock_trim;
        HC32_CLOCK->RCL_CR.STARTUP = 3;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCL_EN = 1;
        while (HC32_CLOCK->RCL_CR.STABLE != 1)
        {
        }
        HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = 2;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCH_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock <= KHz_38_4 && freqency_hz <= KHz_38_4)
    {
        HC32_CLOCK->RCL_CR.TRIM = clock_trim;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock <= KHz_38_4 && freqency_hz > KHz_38_4)
    {
        // switching from RCL to RCH
        HC32_CLOCK->RCH_CR.TRIM = clock_trim;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCH_EN = 1;
        while (HC32_CLOCK->RCH_CR.STABLE != 1)
        {
        }
        HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
}
void peripheral_set_enabled(peripheral_t peripheral) { HC32_CLOCK->peripheral_clock_enable = peripheral; }
peripheral_t peripheral_get_enabled() { return HC32_CLOCK->peripheral_clock_enable; }

void Nvic::clear(irq_t irq){
        if ((int32_t)(irq) >= 0)
    {
        HC32_NVIC->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL));
    }
}
void Nvic::enable(irq_t irq){
        if ((int32_t)(irq) >= 0)
    {
        __asm volatile("" ::
                           : "memory");
        HC32_NVIC->ISER[0U] = (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL));
        __asm volatile("" ::
                           : "memory");
    }
}
void Nvic::disable(irq_t irq){
        if ((int32_t)(irq) >= 0)
    {
        HC32_NVIC->ICER[0U] = (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL));
        data_barrier();
        instruction_barrier();
    }
}
uint8_t Nvic::is_enabled(irq_t irq){
        if ((int32_t)(irq) >= 0)
    {
        return ((uint32_t)(((HC32_NVIC->ISER[(((uint32_t)irq) >> 5UL)] & (1UL << (((uint32_t)irq) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
    }
    else
    {
        return (1U);
    }
}

#define _BIT_SHIFT(IRQn) (((((uint32_t)(int32_t)(IRQn))) & 0x03UL) * 8UL)
#define _SHP_IDX(IRQn) ((((((uint32_t)(int32_t)(IRQn)) & 0x0FUL) - 8UL) >> 2UL))
#define _IP_IDX(IRQn) ((((uint32_t)(int32_t)(IRQn)) >> 2UL))
void Nvic::set_priority(irq_t irq, uint8_t priority){
    if ((int32_t)(irq) >= 0)
    {
        HC32_NVIC->IP[_IP_IDX(irq)] = ((uint32_t)(HC32_NVIC->IP[_IP_IDX(irq)] & ~(0xFFUL << _BIT_SHIFT(irq))) |
                                       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << _BIT_SHIFT(irq)));
    }
    else
    {
        HC32_CONTROL_BLOCK->SHP[_SHP_IDX(irq)] = ((uint32_t)(HC32_CONTROL_BLOCK->SHP[_SHP_IDX(irq)] & ~(0xFFUL << _BIT_SHIFT(irq))) |
                                                  (((priority << (8U - 2)) & (uint32_t)0xFFUL) << _BIT_SHIFT(irq)));
    }
}







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


InterruptHandler::InterruptHandler(): next(NULL){}
void InterruptHandler::invoke(irq_t irq){
    InterruptHandler* h = this->next;
    while(NULL != h){
        h->invoke(irq);
        h = h->next;
    }
}
void InterruptHandler::add(InterruptHandler* handler){
    if(NULL == handler){
        return;
    }
    if(NULL == this->next){
        this->next = handler;
    }
    InterruptHandler* h = this->next;
    while(NULL !=h->next){
        h = h->next;
    }
    h->next = handler;
}
void InterruptHandler::remove(InterruptHandler* handler){
    if(NULL == this->next || NULL == handler){
        return;
    }
    InterruptHandler* h = this->next;
    while(NULL != h && h->next != handler){
        h = h->next;
    }
    if(NULL != h){ // h->next == handler;
        h->next = handler->next;
    }
}
