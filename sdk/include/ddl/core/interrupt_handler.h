
#ifndef __DDL_CORE_INTERRUPT_HANDLER_H__
#define __DDL_CORE_INTERRUPT_HANDLER_H__
#include "hc32l110_system.h"

#include <cstddef>
class InterruptHandler
{
  private:
    InterruptHandler* next = NULL;
  public:
    InterruptHandler();
    virtual void invoke(irq_t irq);
    void add(InterruptHandler* handler);
    void remove(InterruptHandler* handler);
};

class InterruptFunctionWrapper : public InterruptHandler
{
private:
    void (*_handler)(irq_t irq);
public:
    InterruptFunctionWrapper(void (*h)(irq_t irq));
    virtual void invoke(irq_t irq) override;
};



#endif