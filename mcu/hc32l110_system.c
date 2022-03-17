#include "hc32l110_system.h"
uint32_t SystemCoreClock;
uint32_t PeripheralCoreClock;
typedef struct
{
    uint32_t const *src;
    uint32_t *dest;
    uint32_t wlen;
} __copy_table_t;

typedef struct
{
    uint32_t *dest;
    uint32_t wlen;
} __zero_table_t;

extern const __copy_table_t __copy_table_start__;
extern const __copy_table_t __copy_table_end__;
extern const __zero_table_t __zero_table_start__;
extern const __zero_table_t __zero_table_end__;
extern int main(void);
__attribute__((weak)) void SystemInit(void)
{
    *((uint32_t *)0x4000200C) = (*((volatile uint16_t *)(0x00100C08)));
}

void __main()
{
    for (__copy_table_t const *pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable)
    {
        for (uint32_t i = 0u; i < pTable->wlen; ++i)
        {
            pTable->dest[i] = pTable->src[i];
        }
    }

    for (__zero_table_t const *pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable)
    {
        for (uint32_t i = 0u; i < pTable->wlen; ++i)
        {
            pTable->dest[i] = 0u;
        }
    }
    main();
    while (1)
    {
        __asm volatile("wfi");
    }
}