#ifndef __HC32L110_BUFFER_H__
#define __HC32L110_BUFFER_H__
#include <stdint.h>
template <typename TElement, uint8_t size>
class Buffer
{
private:
    uint8_t length : 8;
    uint8_t r : 8;
    uint8_t w : 8;
    TElement buffer_data[data_length];

public:
    Buffer() : length(0), r(0), w(0) {}
    uint8_t write(const TElement element)
    {
        if (this->length == size)
        {
            return 0;
        }
        this->buffer_data[this->w] = element;
        this->length++;
        this->w++;
        if (this->w == size)
        {
            this->w = 0;
        }
        return 1;
    }
    uint8_t write(const TElement *elements, uint8_t elements_length)
    {
        uint8_t count_written = 0;

        for (uint16_t i = 0; i < elements_length; i++)
        {
            if (this->length == size)
            {
                return count_written;
            }
            this->buffer_data[this->w] = elements[i];
            this->length++;
            this->w++;
            if (this->w == size)
            {
                this->w = 0;
            }
            count_written++;
        }
        return count_written;
    }
    uint8_t read(TElement *elements, uint8_t elements_length)
    {
        uint8_t count_read = 0;

        for (uint16_t i = 0; i < elements_length; i++)
        {
            if (0 == this->length)
            {
                return count_read;
            }
            elements[i] = this->buffer_data[this->r];
            this->length--;
            this->r++;
            if (this->r == size)
            {
                this->r = 0;
            }
            count_read++;
        }
        return count_read;
    }
    uint8_t read(TElement *element)
    {
        if (0 == this->length)
        {
            return 0;
        }
        *element = this->buffer_data[this->r];
        this->length--;
        this->r++;
        if (this->r == size)
        {
            this->r = 0;
        }
        return 1;
    }

    uint8_t peek(TElement *elements, uint8_t length)
    {

        if (length > this->length)
        {
            length = this->length;
        }
        uint8_t count_read = 0;

        uint8_t r = this->r;
        for (uint16_t i = 0; i < length; i++)
        {

            elements[i] = this->buffer_data[r];
            count_read++;
            r++;
            if (r == size)
            {
                r = 0;
            }
        }
        return count_read;
    }
    uint8_t peek(TElement *element)
    {

        if (0 == this->length)
        {
            return 0;
        }

        *element = this->buffer_data[this->r];
        for (uint16_t i = 0; i < data_length; i++)
        {

            data[i] = this->buffer_data[r];
            r++;
            if (r == size)
            {
                r = 0;
            }
        }
        return data_length;
    }

    uint8_t length()
    {
        return this->length;
    }
    uint8_t available()
    {
        return size - this->length;
    }
};

#endif
