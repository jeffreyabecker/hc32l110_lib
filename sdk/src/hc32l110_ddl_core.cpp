#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_system.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_system.h"
#include <stdint.h>
uint32_t SystemCoreClock;
uint32_t PeripheralCoreClock;

__attribute__((always_inline)) static inline void __clock_config_unlock(void)
{
    HC32_CLOCK->SYSCTRL2 = 0x5A5A;
    HC32_CLOCK->SYSCTRL2 = 0xA5A5;
}
void clock_set_freq(uint32_t freqency_hz, uint16_t clock_trim)
{
    if (SystemCoreClock > KHz_38_4 && freqency_hz > KHz_38_4)
    {
        HC32_CLOCK->RCH_CR.TRIM = clock_trim;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock > KHz_38_4 && freqency_hz <= KHz_38_4)
    {
        // switching from RCH to RCL
        HC32_CLOCK->RCL_CR.TRIM = clock_trim;
        HC32_CLOCK->RCL_CR.STARTUP = 3;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCL_EN = 1;
        while (HC32_CLOCK->RCL_CR.STABLE != 1)
        {
        }
        HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = 2;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCH_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock <= KHz_38_4 && freqency_hz <= KHz_38_4)
    {
        HC32_CLOCK->RCL_CR.TRIM = clock_trim;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
    else if (SystemCoreClock <= KHz_38_4 && freqency_hz > KHz_38_4)
    {
        // switching from RCL to RCH
        HC32_CLOCK->RCH_CR.TRIM = clock_trim;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCH_EN = 1;
        while (HC32_CLOCK->RCH_CR.STABLE != 1)
        {
        }
        HC32_CLOCK->SYSCTRL0_f.CLK_SW4_SEL = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.RCL_EN = 0;
        __clock_config_unlock();
        HC32_CLOCK->SYSCTRL0_f.XTH_EN = 0;
        SystemCoreClock = freqency_hz;
        PeripheralCoreClock = freqency_hz;
    }
}



