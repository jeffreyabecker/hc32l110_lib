#include "hc32l110_ddl_buffers.h"
typedef struct
{
    uint8_t length : 8;
    uint8_t size : 8;
    uint8_t r : 8;
    uint8_t w : 8;
} ring_buffer_header_t;
#define buffer_header(BUFFER) ((ring_buffer_header_t *)BUFFER)
#define buffer_data(BUFFER) ((uint8_t *)((uint32_t)BUFFER + 4))
uint8_t buffer_remaining(buffer_t b)
{
    return buffer_header(b)->length;
}
uint8_t buffer_available(buffer_t b)
{
    return buffer_header(b)->size - buffer_header(b)->length;
}
void buffer_init(buffer_t b, uint16_t declared_length)
{

    buffer_header(b)->r = 0;
    buffer_header(b)->w = 0;
    buffer_header(b)->length = 0;
    buffer_header(b)->size = declared_length;
    uint8_t *data = buffer_data(b);

    for (uint16_t i = 0; i < buffer_header(b)->size; i++)
    {
        data[i] = 0x00;
    }
}
uint8_t buffer_append_byte(buffer_t b, const uint8_t byte)
{
    if (buffer_header(b)->length == buffer_header(b)->size)
    {
        return 0;
    }
    buffer_data(b)[buffer_header(b)->w] = byte;
    buffer_header(b)->length++;
    buffer_header(b)->w++;
    if (buffer_header(b)->w == buffer_header(b)->size)
    {
        buffer_header(b)->w = 0;
    }
    return 1;
}
uint8_t buffer_write(buffer_t b, const uint8_t *data, uint8_t data_length)
{
    uint8_t bytes_written = 0;

    for (uint16_t i = 0; i < data_length; i++)
    {
        if (buffer_header(b)->length == buffer_header(b)->size)
        {
            return bytes_written;
        }
        buffer_data(b)[buffer_header(b)->w] = data[i];
        buffer_header(b)->length++;
        buffer_header(b)->w++;
        if (buffer_header(b)->w == buffer_header(b)->size)
        {
            buffer_header(b)->w = 0;
        }
        bytes_written++;
    }
    return bytes_written;
}
uint8_t buffer_read(buffer_t b, uint8_t *data, uint8_t data_length)
{
    uint8_t bytes_read = 0;

    for (uint16_t i = 0; i < data_length; i++)
    {
        if (0 == buffer_header(b)->length)
        {
            return bytes_read;
        }
        data[i] = buffer_data(b)[buffer_header(b)->r];
        buffer_header(b)->length--;
        buffer_header(b)->r++;
        if (buffer_header(b)->r == buffer_header(b)->size)
        {
            buffer_header(b)->r = 0;
        }
        bytes_read++;
    }
    return bytes_read;
}

uint8_t buffer_peek(buffer_t b, uint8_t *data, uint8_t data_length)
{

    if (data_length > buffer_header(b)->length)
    {
        data_length = buffer_header(b)->length;
    }

    uint8_t r = buffer_header(b)->r;
    for (uint16_t i = 0; i < data_length; i++)
    {

        data[i] = buffer_data(b)[r];
        r++;
        if (r == buffer_header(b)->size)
        {
            r = 0;
        }
    }
    return data_length;
}

uint8_t buffer_get_byte(buffer_t b, uint8_t *byte)
{
    uint8_t bytes_read = 0;

    if (0 == buffer_header(b)->length)
    {
        return 0;
    }
    *byte = buffer_data(b)[buffer_header(b)->r];
    buffer_header(b)->length--;
    buffer_header(b)->r++;
    if (buffer_header(b)->r == buffer_header(b)->size)
    {
        buffer_header(b)->r = 0;
    }
    return 1;
}