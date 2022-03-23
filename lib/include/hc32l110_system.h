
#ifndef __SYSTEM_HC32L110_SYSTEM_H__
#define __SYSTEM_HC32L110_SYSTEM_H__

#include <stdint.h>
#include "cmsis_compiler.h"
#ifdef __cplusplus
extern "C"
{
#endif

    extern uint32_t SystemCoreClock;
    extern uint32_t PeripheralCoreClock;

    __WEAK void SystemInit(void);
    void __main();
#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_HC32L110_H__ */
