
#ifndef __SYSTEM_HC32L110_H__
#define __SYSTEM_HC32L110_H__

#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif

    extern uint32_t SystemCoreClock;
    extern uint32_t PeripheralCoreClock;

    __attribute__((weak)) void SystemInit(void);
    void __main();
#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_HC32L110_H__ */
