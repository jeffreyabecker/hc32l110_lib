#ifndef __HC32L110_DDL_UTIL_H__
#define __HC32L110_DDL_UTIL_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
void srand(uint32_t seed);
uint32_t rand();
void *memset(void *mem, uint8_t value, size_t length);

size_t strlen(const char *format);
#ifdef __cplusplus
}
#endif
#endif
