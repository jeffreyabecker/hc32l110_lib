#ifndef __SYSTEM_HC32L110_DDL_UTIL_H__
#define __SYSTEM_HC32L110_DDL_UTIL_H__
#include <stdint.h>
#include <stddef.h>
void srand(uint32_t seed);
uint32_t rand();
void *memset(void *mem, uint8_t value, size_t length);
size_t strlen(const char *format);
#endif