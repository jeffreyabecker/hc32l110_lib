
#ifndef __DDL_CORE_NVIC_H__
#define __DDL_CORE_NVIC_H__

class Nvic{
  public:
    static const uint8_t default_priority = 0x03;
    static void clear(irq_t irq);
    static void enable(irq_t irq);
    static void disable(irq_t irq);
    static uint8_t is_enabled(irq_t irq);
    static void set_priority(irq_t irq, uint8_t priority);
};


#endif