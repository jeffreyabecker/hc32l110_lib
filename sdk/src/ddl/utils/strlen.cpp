#include <stddef.h>
#include "ddl/utils/utils.h"

size_t strlen(const char *format)
{
    size_t len = 0;
    while (*format != '\0')
    {
        len++;
    }
    return len;
}