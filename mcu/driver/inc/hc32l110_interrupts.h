#ifndef __hc32l110_INTERRUPTS_H__
#define __hc32l110_INTERRUPTS_H__


#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_core.h"




#define nivc_irq_number_t IRQn_Type 

typedef void (*nvic_interrupt_handler_t)(nivc_irq_number_t irq_number, void* data);

void nvic_interrupt_cfg(nivc_irq_number_t irq_number, nvic_interrupt_handler_t handler,  void* data);
void nvic_interrupt_set_enabled(nivc_irq_number_t irq_number, uint8_t enabled);
void nvic_interrupt_set_priority(nivc_irq_number_t irq_number, uint8_t priority);
uint8_t nvic_interrupt_get_priority(nivc_irq_number_t irq_number);
void nvic_interrupt_raise(nivc_irq_number_t irq_number);
void nvic_interrupt_clear(nivc_irq_number_t irq_number);

#ifdef __cplusplus
}
#endif

#endif 
