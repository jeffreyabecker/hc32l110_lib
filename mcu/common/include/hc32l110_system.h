
#ifndef __SYSTEM_HC32L110_H__
#define __SYSTEM_HC32L110_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


extern uint32_t SystemCoreClock;          // System Clock Frequency (Core Clock)
extern void SystemInit (void);            // Initialize the system
extern void SystemCoreClockUpdate (void); // Update core_system_clock_frequency variable

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_HC32L110_H__ */
