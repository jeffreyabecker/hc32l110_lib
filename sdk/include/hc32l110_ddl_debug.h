#ifndef __HC32L110_DDL_DEBUG_H__
#define __HC32L110_DDL_DEBUG_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
void debug_init_uart();
void debug_print(const char *str);
void debug_print_uint32(uint32_t val);
#define debug_breakpoint() __asm("bkpt 1")

#ifdef __cplusplus
}
#endif

#endif
