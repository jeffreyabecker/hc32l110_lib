#ifndef __DDL_CORE_BASIC_TIMER_H__
#define __DDL_CORE_BASIC_TIMER_H__
#include "hc32l110_system.h"

#include "ddl/core/core.h"



class BasicTimer : public Timer
{
private:
    hc32_basic_timer_register_t *timer;

public:
    BasicTimer(hc32_basic_timer_register_t *t);

    static void enable_peripheral();

    basic_timer_mode_t mode() ;
    void mode(basic_timer_mode_t value) ;

    timer_function_t function() ;
    void function(timer_function_t value);

    basic_timer_prescaler_t prescaler() ;
    void prescaler(basic_timer_prescaler_t value) ;

    uint8_t enable_inverted_output();
    void enable_inverted_output(uint8_t value);

    uint8_t enable_gate();
    void enable_gate(uint8_t value) ;

    uint8_t gate_polarity() ;
    void gate_polarity(uint8_t value) ;

    uint8_t interrupt_enabled() ;
    void interrupt_enabled(uint8_t value);

    uint32_t reload();
    void reload(uint32_t value);

    virtual uint32_t count() override;
    virtual void count(uint32_t value) override;

    virtual void running(uint8_t enabled) override;
    virtual uint8_t running() override;

    virtual uint8_t has_interrupt() override;
    virtual void clear_interrupt() override;

};

#endif
