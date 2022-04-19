#include "hc32l110_ddl_util.h"
#include "hc32l110_registers.h"

size_t strlen(const char *format)
{
    size_t len = 0;
    while (*format != '\0')
    {
        len++;
    }
    return len;
}