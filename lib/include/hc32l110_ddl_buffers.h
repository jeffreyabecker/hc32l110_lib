#ifndef __SYSTEM_HC32L110_DDL_BUFFER_H__
#define __SYSTEM_HC32L110_DDL_BUFFER_H__
#include <stdint.h>
void buffer_init(void *b, uint16_t total_length);
uint8_t buffer_write(void *b, const uint8_t *data, uint8_t data_length);
uint8_t buffer_read(void *b, uint8_t *data, uint8_t data_length);
#define buffer_declare(name, size) uint8_t name[size + 4];

#endif