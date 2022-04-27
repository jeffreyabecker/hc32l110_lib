
#ifndef __HC32L110_DDL_CORE_H__
#define __HC32L110_DDL_CORE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "hc32l110_system.h"
#include "hc32l110_system.h"
#include "hc32l110_registers.h"
#include <stddef.h>



class Nvic{
  public:
    static const uint8_t default_priority = 0x03;
    static void clear(irq_t irq);
    static void enable(irq_t irq);
    static void disable(irq_t irq);
    static uint8_t is_enabled(irq_t irq);
    static void set_priority(irq_t irq, uint8_t priority);
};

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




class Device {
  public:
    InterruptHandler interrupt;
    static void enabled(peripheral_t peripheral);
    static peripheral_t enabled();
    static enable(peripheral_t peripheral);
    static disable(peripheral_t peripheral);
};


void clock_set_freq(uint32_t freqency_hz, uint16_t clock_trim);

class SysTickPeripheral{
  private:
    volatile uint32_t _counter;
  public:
    SysTickPeripheral();
    void configure(uint32_t frequency_hz);
    uint32_t current();
    uint32_t elapsed_since(uint32_t timestamp);
    void delay(uint32_t ticks);
    void start();
    void stop();
    void invoke_interrupt();
    uint8_t running();
};
extern SysTickPeripheral systick;

#ifdef __cplusplus
}
#endif

#endif
