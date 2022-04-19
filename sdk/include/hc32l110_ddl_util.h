#ifndef __SYSTEM_HC32L110_DDL_UTIL_H__
#define __SYSTEM_HC32L110_DDL_UTIL_H__
#include <stdint.h>
#include <stddef.h>

void *memset(void *mem, uint8_t value, size_t length);
size_t strlen(const char *format);
int snprintf(char *s, size_t n, const char *format, ...);
#endif