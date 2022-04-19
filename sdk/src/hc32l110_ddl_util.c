#include <stdarg.h>
#include <stddef.h>
#include "hc32l110_system.h"

void *memset(void *mem, uint8_t value, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        ((uint8_t *)mem)[i] = value;
    }
    return mem;
}
size_t strlen(const char *format)
{
    size_t len = 0;
    while (*format != '\0')
    {
        len++;
    }
    return len;
}
__read_only_data char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
void __hex_format_value(uint8_t *formatted, uint32_t val, uint8_t bits, uint8_t bits_per_digit)
{
    uint8_t end = bits / bits_per_digit;
    uint8_t shift = bits >> bits_per_digit;
    for (uint8_t i = bits; i > 0; i -= bits_per_digit)
    {
        formatted[(end - (i >> shift))] = digits[((val >> (i - bits_per_digit)) & 0xF)];
    }
}
size_t __interpolate_string(char *s, size_t n, const char *inner)
{
    size_t i_index = 0;
    size_t i_length = strlen(inner);
    size_t s_index = 0;
    while (s_index < n && i_index < i_length && inner[i_index] != '\0')
    {
        s[s_index] = inner[i_index];
        s_index++;
        i_index++;
    }
    return s_index;
}
// supports %c, %i, %u, %x, %p, %s, %%
#define FORMAT_BUFFER_LENGTH 16
int snprintf(char *s, size_t n, const char *format, ...)
{
    va_list argp;
    va_start(argp, format);
    size_t s_index = 0;
    size_t f_index = 0;
    size_t f_len = strlen(format);
    uint8_t format_buffer[FORMAT_BUFFER_LENGTH];
    while (s_index < n && f_index < f_len && format[f_index] != '\0')
    {

        if (format[f_index] == '%')
        {
            size_t f_next = f_index + 1;
            if (f_next < f_len)
            {
                char next_char = format[f_next];
                // supports  %i, %u, %x, %p, %s,
                if (next_char == '%')
                {
                    s[s_index] = format[f_index];
                }
                if (next_char == 'c')
                {
                    s[s_index] = (char)va_arg(argp, int);
                }
                else if (next_char == 's')
                {
                    char *inner = (char *)va_arg(argp, int);
                    s_index += __interpolate_string(&(s[s_index]), n - s_index, inner);
                }
                else if (next_char == 'b')
                {
                    memset(format_buffer, '\0', FORMAT_BUFFER_LENGTH);
                    format_buffer[0] = '0';
                    format_buffer[1] = 'x';
                    uint8_t value = (uint8_t)va_arg(argp, int);
                    __hex_format_value(&(format_buffer[2]), value, 8);
                    s_index += __interpolate_string(&(s[s_index]), n - s_index, format_buffer);
                }
                else if (next_char == 'x')
                {
                    memset(format_buffer, '\0', FORMAT_BUFFER_LENGTH);
                    format_buffer[0] = '0';
                    format_buffer[1] = 'x';
                    uint32_t value = (uint32_t)va_arg(argp, int);
                    __hex_format_value(&(format_buffer[2]), value, 32);
                    s_index += __interpolate_string(&(s[s_index]), n - s_index, format_buffer);
                }
                else
                {
                }
            }
            else
            {
                s[s_index] = format[f_index];
            }
        }
        else
        {
            s[s_index] = format[f_index];
        }
        f_index++;
        s_index++;
    }

    va_end(argp);
}