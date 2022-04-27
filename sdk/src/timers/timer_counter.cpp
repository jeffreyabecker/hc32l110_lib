#include "hc32l110_ddl_timer.h"

TimerCounter::TimerCounter(Timer* timer) : _count(0), _timer(timer){
    if(NULL != timer){
        timer->interrupt.add(this);
    }
}
TimerCounter :: ~TimerCounter(){
    if(NULL != this->_timer){
        this->_timer->interrupt.add(this);
    }
}
void TimerCounter::invoke(Timer *device, irq_t irq){
    this->_count++;
}

uint32_t TimerCounter::elapsed(){ return _count;}
void TimerCounter::start(){
    this->_count = 0;
    this->_timer->interrupt_enabled(1);
    this->_timer->running(1);
}
void TimerCounter::stop(){
    this->_timer->running(0);
    this->_timer->interrupt_enabled(0);
    this->_count = 0;
}
void TimerCounter::delay(uint32_t ticks){
    uint32_t end = this->_count + start;
    while(this->_count != end){
        __nop();
    }
}

