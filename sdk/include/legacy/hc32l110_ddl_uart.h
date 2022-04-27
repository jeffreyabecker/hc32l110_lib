#ifndef __HC32L110_DDL_UART_H__
#define __HC32L110_DDL_UART_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "hc32l110_system.h"

#include "hc32l110_ddl_buffers.h"
#define peripheral_enable_uart() peripheral_set_enabled(peripheral_get_enabled() | peripheral_uart0 | peripheral_uart1 | peripheral_basetim)
void init_uart(hc32_uart_register_t* uart, uint32_t baud);
void uart_put_byte(hc32_uart_register_t* uart, uint8_t byte);
void uart_send(hc32_uart_register_t *uart, uint8_t* data, uint8_t length);
uint8_t uart_get_byte(hc32_uart_register_t* uart);

void uart_set_buffer(hc32_uart_register_t *uart, buffer_t tx_buffer, uint8_t tx_length, buffer_t rx_buffer, uint8_t rx_length);
uint8_t uart_buffered_tx(hc32_uart_register_t *uart, const uint8_t *data, uint8_t length);
uint8_t uart_buffered_rx(hc32_uart_register_t *uart, uint8_t *data, uint8_t length);

typedef enum{
    uart_event_none = 0,
    uart_event_rx = 1,
    uart_event_tx = 2,
    uart_event_err = 4,
} uart_event_t;
typedef void (*uart_event_handler_t)(hc32_uart_register_t *uart, uart_event_t event, buffer_t tx_buffer, buffer_t rx_buffer);

void uart_set_handler(hc32_uart_register_t *uart, uart_event_handler_t handler);
#ifdef __cplusplus
}
#endif
#endif
