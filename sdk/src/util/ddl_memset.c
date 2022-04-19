#include "hc32l110_ddl_util.h"
#include "hc32l110_registers.h"

void *memset(void *mem, uint8_t value, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        ((uint8_t *)mem)[i] = value;
    }
    return mem;
}