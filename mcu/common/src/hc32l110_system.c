#include <stdint.h>
#include "cmsis_compiler.h"
#include "hc32l110_system.h"
#ifdef __cplusplus
extern "C"
{
#endif
    
 
    uint32_t SystemCoreClock;
    uint32_t PeripheralCoreClock;

    __WEAK void SystemCoreClockUpdate(void) // Update core_system_clock_frequency variable
    {
        PeripheralCoreClock = SystemCoreClock = 4000000;
    }

    __WEAK void SystemInit(void)
    {
        (*((volatile uint32_t *)(0x4000200Cul))) = (*((volatile uint16_t *)(0x00100C08ul))); // Load 4MHz Trimming value into M0P_CLOCK_RCH
        SystemCoreClockUpdate();
    }
#ifdef __cplusplus
}
#endif