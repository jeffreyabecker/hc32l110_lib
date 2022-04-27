#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_system.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>



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
