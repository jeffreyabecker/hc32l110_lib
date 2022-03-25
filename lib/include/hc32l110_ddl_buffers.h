#ifndef __SYSTEM_HC32L110_DDL_BUFFER_H__
#define __SYSTEM_HC32L110_DDL_BUFFER_H__
#include <stdint.h>
/** \defgroup DDL buffers @{*/
/** Statically allocates a buffer. This buffer must be passed to buffer_init prior to useage*/
typedef void *buffer_t;
#define buffer_declare(NAME, declared_length)         \
    static uint8_t __store_NAME[declared_length + 4]; \
    static buffer_t NAME = &__store_NAME
void buffer_init(buffer_t b, uint16_t declared_length);
uint8_t buffer_write(buffer_t b, const uint8_t *data, uint8_t data_length);

uint8_t buffer_read(buffer_t b, uint8_t *data, uint8_t data_length);
uint8_t buffer_append_byte(buffer_t b, const uint8_t byte);
uint8_t buffer_get_byte(buffer_t b, uint8_t *byte);

#endif