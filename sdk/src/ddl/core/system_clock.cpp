#include "hc32l110_system.h"

#include "ddl/core/core.h"

SystemClock::SystemClock():
    _core_frequency((uint32_t)SystemClockFrequency::MHz_4)
{}
uint32_t SystemClock::core_frequency(){ return this->_core_frequency;}
uint32_t SystemClock::system_frequency(){ return this->_core_frequency >> HC32_CLOCK->SYSCTRL0_f.HCLK_PRS;}
uint32_t SystemClock::peripheral_frequency(){ return this->system_frequency() >> HC32_CLOCK->SYSCTRL0_f.PCLK_PRS ;}
uint16_t SystemClock::get_clock_trim(SystemClockFrequency frequency){
    switch(frequency){
        case SystemClockFrequency::MHz_8: return (*((volatile uint16_t *)(0x00100C06ul)));
        case SystemClockFrequency::MHz_16: return (*((volatile uint16_t *)(0x00100C04ul)));
        case SystemClockFrequency::MHz_22_12: return (*((volatile uint16_t *)(0x00100C02ul)));
        case SystemClockFrequency::MHz_24: return (*((volatile uint16_t *)(0x00100C00ul)));
        case SystemClockFrequency::MHz_4: return (*((volatile uint16_t *)(0x00100C08ul)));
        default: return HC32_CLOCK->RCH_CR.TRIM;
    }
}



uint8_t SystemClock::system_prescaler(){
    return HC32_CLOCK->SYSCTRL0_f.HCLK_PRS;
}
void SystemClock::system_prescaler(uint8_t prs){
        if(prs <= 7 ){
        HC32_CLOCK->SYSCTRL0_f.HCLK_PRS = prs;        
    }
}

void SystemClock::core_frequency(SystemClockFrequency frequency){
    uint16_t trim = this->get_clock_trim(frequency);
    if(trim != HC32_CLOCK->RCH_CR.TRIM){
        this->_core_frequency = (uint32_t)frequency;        
    }
}
void SystemClock::peripheral_prescaler(uint8_t prs){
    if(prs <= 3 ){
        HC32_CLOCK->SYSCTRL0_f.PCLK_PRS = prs;        
    }
}
uint8_t SystemClock::peripheral_prescaler(){
    return HC32_CLOCK->SYSCTRL0_f.PCLK_PRS;
}

SystemClock system_clock;

