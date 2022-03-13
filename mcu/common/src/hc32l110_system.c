#include <stdint.h>
#include "cmsis_compiler.h"
#ifdef __cplusplus
extern "C"
{
#endif
    __WEAK void SystemInit();

 
    uint32_t SystemCoreClock;

    __WEAK void SystemCoreClockUpdate(void) // Update core_system_clock_frequency variable
    {
        SystemCoreClock = 4000000;
    }

    __WEAK void SystemInit(void)
    {
        (*((volatile uint32_t *)(0x4000200Cul))) = (*((volatile uint16_t *)(0x00100C08ul))); // Load 4MHz Trimming value into M0P_CLOCK_RCH
        SystemCoreClockUpdate();
    }
#ifdef __cplusplus
}
#endif