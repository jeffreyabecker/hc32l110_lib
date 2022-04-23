#ifndef __HC32L110_INTERRUPT_INVOCATION_HANDLER_H__
#define __HC32L110_INTERRUPT_INVOCATION_HANDLER_H__
#include "hc32l110_system.h"
template <typename TDevice>
class InterruptInvocationHandler
{
public:
    virtual void invoke(TDevice *device, irq_t irq);
};
#endif