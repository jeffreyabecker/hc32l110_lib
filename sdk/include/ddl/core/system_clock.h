#ifndef __DDL_CORE_SYSTEM_CLOCK_H__
#define __DDL_CORE_SYSTEM_CLOCK_H__
#include "hc32l110_system.h"


enum class SystemClockFrequency : uint32_t { 
  // KHz_32_8 = 32800,
  // KHz_38_4 = 38400,
  MHz_4 = 4000000,
  MHz_8 = 8000000,
  MHz_16 = 16000000,
  MHz_22_12 = 22120000,
  MHz_24 = 24000000,
};

//void clock_set_freq(uint32_t freqency_hz, uint16_t clock_trim);
class SystemClock{
  private:
    uint32_t _core_frequency;
    uint16_t get_clock_trim(SystemClockFrequency frequency);
  public:
    SystemClock();
    uint32_t core_frequency();
    void core_frequency(SystemClockFrequency frequency);

    uint32_t system_frequency();
    uint32_t peripheral_frequency();
    
    uint8_t system_prescaler();
    void system_prescaler(uint8_t prs);

    uint8_t peripheral_prescaler();  
    void peripheral_prescaler(uint8_t prs);
};

#endif
