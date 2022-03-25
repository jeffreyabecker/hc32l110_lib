#include "hc32l110_ddl_buffers.h"
typedef struct
{
    uint8_t length : 8;
    uint8_t size : 8;
    uint8_t r : 8;
    uint8_t w : 8;
} ring_buffer_header_t;
#define buffer_header(x) ((ring_buffer_header_t *)x)
#define buffer_data(x) ((uint8_t *)((uint32_t)x + 4))
void buffer_init(void *b, uint16_t total_length)
{

    buffer_header(b)->r = 0;
    buffer_header(b)->w = 0;
    buffer_header(b)->length = 0;
    buffer_header(b)->size = total_length - 4;
    uint8_t *data = buffer_data(b);

    for (uint16_t i = 0; i < buffer_header(b)->size; i++)
    {
        data[i] = 0x00;
    }
}
uint8_t buffer_write(void *b, const uint8_t *data, uint8_t data_length)
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
    }
    return bytes_written;
}
uint8_t buffer_read(void *b, uint8_t *data, uint8_t data_length)
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
    }
    return bytes_read;
}