#ifndef __BUFFER_TEMPLATE_H__
#define __BUFFER_TEMPLATE_H__
#include <stdint.h>
#define BUFFER_DECLARATION(BUFFER_TYPE, BUFFER_ELEMENT_TYPE, BUFFER_LENGTH)                                \
    typedef struct                                                                                         \
    {                                                                                                      \
        uint8_t length : 8;                                                                                \
        uint8_t r : 8;                                                                                     \
        uint8_t w : 8;                                                                                     \
        BUFFER_ELEMENT_TYPE data[BUFFER_LENGTH];                                                           \
    } BUFFER_TYPE##_t;                                                                                     \
    void buffer_init(BUFFER_TYPE##_t *b, BUFFER_ELEMENT_TYPE default_value);                               \
    uint8_t BUFFER_TYPE##_length(BUFFER_TYPE##_t *b);                                                      \
    uint8_t BUFFER_TYPE##_available(BUFFER_TYPE##_t *b);                                                   \
    uint8_t BUFFER_TYPE##_append_element(BUFFER_TYPE##_t *b, const BUFFER_ELEMENT_TYPE element);           \
    uint8_t BUFFER_TYPE##_write(BUFFER_TYPE##_t *b, const BUFFER_ELEMENT_TYPE *data, uint8_t data_length); \
    uint8_t BUFFER_TYPE##_read(BUFFER_TYPE##_t *b, BUFFER_ELEMENT_TYPE *data, uint8_t data_length);        \
    uint8_t BUFFER_TYPE##_peek(BUFFER_TYPE##_t *b, BUFFER_ELEMENT_TYPE *data, uint8_t data_length);        \
    uint8_t BUFFER_TYPE##_get_element(BUFFER_TYPE##_t *b, BUFFER_ELEMENT_TYPE *element);

#define BUFFER_IMPLEMENTATION(BUFFER_TYPE, BUFFER_ELEMENT_TYPE, BUFFER_LENGTH)                            \
    void BUFFER_TYPE##_init(BUFFER_TYPE##_t *b, BUFFER_ELEMENT_TYPE default_value)                        \
    {                                                                                                     \
        b->r = 0;                                                                                         \
        b->w = 0;                                                                                         \
        b->length = 0;                                                                                    \
                                                                                                          \
        for (uint8_t i = 0; i < BUFFER_LENGTH; i++)                                                       \
        {                                                                                                 \
            b->data[i] = default_value;                                                                   \
        }                                                                                                 \
    }                                                                                                     \
    uint8_t BUFFER_TYPE##_length(BUFFER_TYPE##_t *b)                                                      \
    {                                                                                                     \
        return b->length;                                                                                 \
    }                                                                                                     \
    uint8_t BUFFER_TYPE##_available(BUFFER_TYPE##_t *b)                                                   \
    {                                                                                                     \
        return BUFFER_LENGTH - b->length;                                                                 \
    }                                                                                                     \
    uint8_t BUFFER_TYPE##_append_element(BUFFER_TYPE##_t *b, const BUFFER_ELEMENT_TYPE element)           \
    {                                                                                                     \
        if (b->length == BUFFER_LENGTH)                                                                   \
        {                                                                                                 \
            return 0;                                                                                     \
        }                                                                                                 \
        b->data[b->w] = element;                                                                          \
        b->length++;                                                                                      \
        b->w++;                                                                                           \
        if (b->w == BUFFER_LENGTH)                                                                        \
        {                                                                                                 \
            b->w = 0;                                                                                     \
        }                                                                                                 \
        return 1;                                                                                         \
    }                                                                                                     \
    uint8_t BUFFER_TYPE##_write(BUFFER_TYPE##_t *b, const BUFFER_ELEMENT_TYPE *data, uint8_t data_length) \
    {                                                                                                     \
        uint8_t elements_written = 0;                                                                     \
                                                                                                          \
        for (uint8_t i = 0; i < data_length; i++)                                                         \
        {                                                                                                 \
            if (b->length == BUFFER_LENGTH)                                                               \
            {                                                                                             \
                return elements_written;                                                                  \
            }                                                                                             \
            b->data[b->w] = data[i];                                                                      \
            b->length++;                                                                                  \
            b->w++;                                                                                       \
            if (b->w == BUFFER_LENGTH)                                                                    \
            {                                                                                             \
                b->w = 0;                                                                                 \
            }                                                                                             \
            elements_written++;                                                                           \
        }                                                                                                 \
        return elements_written;                                                                          \
    }                                                                                                     \
    uint8_t BUFFER_TYPE##_read(BUFFER_TYPE##_t *b, BUFFER_ELEMENT_TYPE *data, uint8_t data_length)        \
    {                                                                                                     \
        uint8_t elements_read = 0;                                                                        \
                                                                                                          \
        for (uint8_t i = 0; i < data_length; i++)                                                         \
        {                                                                                                 \
            if (0 == b->length)                                                                           \
            {                                                                                             \
                return elements_read;                                                                     \
            }                                                                                             \
            data[i] = b->data[b->r];                                                                      \
            b->length--;                                                                                  \
            b->r++;                                                                                       \
            if (b->r == BUFFER_LENGTH)                                                                    \
            {                                                                                             \
                b->r = 0;                                                                                 \
            }                                                                                             \
            elements_read++;                                                                              \
        }                                                                                                 \
        return elements_read;                                                                             \
    }                                                                                                     \
                                                                                                          \
    uint8_t BUFFER_TYPE##_peek(BUFFER_TYPE##_t *b, BUFFER_ELEMENT_TYPE *data, uint8_t data_length)        \
    {                                                                                                     \
        if (data_length > b->length)                                                                      \
        {                                                                                                 \
            data_length = b->length;                                                                      \
        }                                                                                                 \
        uint8_t r = b->r;                                                                     \
        for (uint8_t i = 0; i < data_length; i++)                                                         \
        {                                                                                                 \
                                                                                                          \
            data[i] = b->data[r];                                                                         \
            r++;                                                                                          \
            if (r == BUFFER_LENGTH)                                                                       \
            {                                                                                             \
                r = 0;                                                                                    \
            }                                                                                             \
        }                                                                                                 \
        return data_length;                                                                               \
    }                                                                                                     \
                                                                                                          \
    uint8_t BUFFER_TYPE##_get_element(BUFFER_TYPE##_t *b, BUFFER_ELEMENT_TYPE *element)                   \
    {                                                                                                     \
        uint8_t elements_read = 0;                                                                        \
                                                                                                          \
        if (0 == b->length)                                                                               \
        {                                                                                                 \
            return 0;                                                                                     \
        }                                                                                                 \
        *element = b->data[b->r];                                                                         \
        b->length--;                                                                                      \
        b->r++;                                                                                           \
        if (b->r == BUFFER_LENGTH)                                                                        \
        {                                                                                                 \
            b->r = 0;                                                                                     \
        }                                                                                                 \
        return 1;                                                                                         \
    }


#endif