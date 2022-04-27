#ifndef __HC32L110_INTERRUPT_INVOCATION_WRAPPER_H__
#define __HC32L110_INTERRUPT_INVOCATION_WRAPPER_H__
#include "hc32l110_system.h"
#include "hc32l110_ddl_interrupt_invocation_handler.h"

template <typename TDevice>
class InterruptInvocationWrapper : public InterruptInvocationHandler<TDevice>
{
private:
    void (*_handler)(TDevice *, irq_t);
public:
    constexpr InterruptInvocationWrapper(void (*h)(TDevice *, irq_t)) : _handler(h){}
    void invoke(TDevice *device, irq_t irq)  override {
        if(this->_handler != NULL){
            this->_handler(device, irq);
        }
    }
};

#endif