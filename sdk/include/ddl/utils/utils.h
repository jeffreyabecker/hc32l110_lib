#ifndef __DDL_UTILS_H__
#define __DDL_UTILS_H__
#include "ddl/utils/rng.h"
#include <stddef.h>
extern "C" {
    void* memset(void* dest, int ch, size_t count);

    int memcmp( const void* lhs, const void* rhs, size_t count );

    size_t strlen(const char *format);
}
#endif
