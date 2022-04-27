#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_system.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>




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


InterruptFunctionWrapper::InterruptFunctionWrapper(void (*h)(irq_t irq)) : _handler(h){}

void InterruptFunctionWrapper::invoke(irq_t irq) {
    if(this->_handler != NULL){
        this->_handler(device, irq);
    }
}