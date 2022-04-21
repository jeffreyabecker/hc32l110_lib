#ifndef __HC32L110_INTERRUPT_CALLBACK_H__
#define __HC32L110_INTERRUPT_CALLBACK_H__
#include "hc32l110_system.h"
    template <typename TElement> class InterruptInvocationHandler
    {
    public:
        virtual void invoke(TElement *timer, irq_t irq);
    };
#endif