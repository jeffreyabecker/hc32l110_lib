#include "hc32l110_registers.h"
#include "hc32l110_core.h"
#include "hc32l110_basic_timers.h"
#include "hc32l110_uart.h"

__STATIC_INLINE uint8_t __uart_get_index(M0P_UART_TypeDef *uart)
{
    return (LPUART_ADDRESS - ((uint32_t)uart)) / 256;
}

__STATIC_INLINE M0P_BasicTimer_TypeDef *__uart_get_timer(M0P_UART_TypeDef *uart)
{
    return ((uint32_t)uart) == UART00_ADDRESS   ? M0P_TIMER0
           : ((uint32_t)uart) == UART01_ADDRESS ? M0P_TIMER1
           : ((uint32_t)uart) == LPUART_ADDRESS ? M0P_TIMER2
                                                : NULL;
}

uint16_t __uart_calculate_timer_prescaler(uart_config_t *config)
{
    if (config->mode == uart_baud_mode_0 || config->mode == uart_baud_mode_2)
    {
        return 0;
    }
    else
    {
        return 0x10000 - ((core_get_peripheral_clock_frequency() * (config->double_baud_rate + 1)) / (config->baud_rate * 32));
    }
}
static uart_parity_t __uart_parity[3] = {uart_parity_even, uart_parity_even, uart_parity_even};
__STATIC_INLINE uint8_t __uart_get_index(M0P_UART_TypeDef *uart)
{
    return (LPUART_ADDRESS - ((uint32_t)uart)) / 256;
}
void uart_configure(M0P_UART_TypeDef *uart, uart_config_t *config)
{

    if (config->enabled)
    {
        uart->control.rx_interrupt_enabled = config->interrupt & uart_interrupt_enabled_recieve > 0 ? 1 : 0;
        uart->control.tx_interrupt_enabled = config->interrupt & uart_interrupt_enabled_transmit > 0 ? 1 : 0;
        uart->control.tx_buffer_empty_interrupt_enabled = config->interrupt & uart_interrupt_enabled_transmit_empty > 0 ? 1 : 0;
        uart->control.double_baud_rate = config->double_baud_rate;
        uart->control.rx_enabled = config->recieve_enabled;
        if (config->mode == uart_baud_mode_1 || config->mode == uart_baud_mode_3)
        {
            M0P_BasicTimer_TypeDef *timer = __uart_get_timer(uart);
            uint16_t arr = __uart_calculate_timer_prescaler(config);
            timer->control.mode = 1;
            timer->auto_reload = arr;
            timer->count_16 = arr;
            timer->control.timer_running = 1;
            __uart_parity[__uart_get_index(uart)] = config->parity;
        }
    }
    else
    {
        uart->control.rx_interrupt_enabled = 0;
        uart->control.tx_interrupt_enabled = 0;
        uart->control.tx_buffer_empty_interrupt_enabled = 0;
        uart->control.double_baud_rate = config->double_baud_rate;
        uart->control.rx_enabled = 0;
    }
}
uint8_t __uart_calculate_parity(uint8_t byte)
{
    uint8_t count = 0;
    for (size_t i = 0; i < 8; i++)
    {
        if ((byte & 0x80) == 0x80)
        {
            count++;
        }
        byte <<= 1;
    }
    return count == 0 ? 0 : 1;
}
__STATIC_INLINE M0P_BasicTimer_TypeDef *__uart_get_timer(M0P_UART_TypeDef *uart)
{
    return ((uint32_t)uart) == UART00_ADDRESS   ? M0P_TIMER0
           : ((uint32_t)uart) == UART01_ADDRESS ? M0P_TIMER1
           : ((uint32_t)uart) == LPUART_ADDRESS ? M0P_TIMER2
                                                : NULL;
}

uint16_t __uart_calculate_timer_prescaler(uart_config_t *config)
{
    if (config->mode == uart_baud_mode_0 || config->mode == uart_baud_mode_2)
    {
        return 0;
    }
    else
    {
        return 0x10000 - ((core_get_peripheral_clock_frequency() * (config->double_baud_rate + 1)) / (config->baud_rate * 32));
    }
}
void uart_configure(M0P_UART_TypeDef *uart, uart_config_t *config)
{
    if (config->enabled)
    {
        uart->control.rx_interrupt_enabled = config->interrupt & uart_interrupt_enabled_recieve > 0 ? 1 : 0;
        uart->control.tx_interrupt_enabled = config->interrupt & uart_interrupt_enabled_transmit > 0 ? 1 : 0;
        uart->control.tx_buffer_empty_interrupt_enabled = config->interrupt & uart_interrupt_enabled_transmit_empty > 0 ? 1 : 0;
        uart->control.double_baud_rate = config->double_baud_rate;
        uart->control.rx_enabled = config->recieve_enabled;
        if (config->mode == uart_baud_mode_1 || config->mode == uart_baud_mode_3)
        {
            M0P_BasicTimer_TypeDef *timer = __uart_get_timer(uart);
            uint16_t arr = __uart_calculate_timer_prescaler(config);
            timer->control.mode = 1;
            timer->auto_reload = arr;
            timer->count_16 = arr;
            timer->control.timer_running = 1;
        }
    }
    else
    {
        uart->control.rx_interrupt_enabled = 0;
        uart->control.tx_interrupt_enabled = 0;
        uart->control.tx_buffer_empty_interrupt_enabled = 0;
        uart->control.double_baud_rate = config->double_baud_rate;
        uart->control.rx_enabled = 0;
    }
}
uart_operation_result_t uart_send(M0P_UART_TypeDef *uart, uint8_t *data, size_t length)
{
    uint8_t use_parity = uart->control.mode == uart_baud_mode_2 || uart->control.mode == uart_baud_mode_3 ? 1 : 0;
    for (size_t i = 0; i < length; i++)
    {
        if (use_parity)
        {
            uart->control.transmit_parity_bit = __uart_calculate_parity(data[i]);
        }
        uart->ICR.tx_empty_flag = 0;
        uart->buffer = data[i];
        while (uart->ISR.tx_complete_flag == 0)
        {
        }
        uart->ICR.tx_empty_flag = 0;
    }
    return uart_operation_result_success;
}

uart_operation_result_t uart_recieve(M0P_UART_TypeDef *uart, uint8_t *data, size_t length)
{
    uint8_t use_parity = uart->control.mode == uart_baud_mode_2 || uart->control.mode == uart_baud_mode_3 ? 1 : 0;
    for (size_t i = 0; i < length; i++)
    {
        while (uart->ISR.rx_complete_flag == 0)
        {
        }
        data[i] = uart->buffer;
        if (use_parity)
        {
            if (__uart_calculate_parity(data[i]) != uart->control.recieve_parity_bit)
            {
                return uart_operation_result_parity_mismatch;
            }
        }
        uart->ICR.rx_complete_flag = 0;
    }
    return uart_operation_result_success;
}