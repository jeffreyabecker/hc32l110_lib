#ifndef __HC32L110_DDL_UART__
#define __HC32L110_DDL_UART__
#include "hc32l110_registers_uart.h"

typedef enum
{
    uart_interrupt_enabled_none = 0,
    uart_interrupt_enabled_recieve = 1,
    uart_interrupt_enabled_transmit = 2,
    uart_interrupt_enabled_transmit_empty = 4,
} uart_interrupt_enabled_t;
typedef enum
{
    uart_parity_even = 0,
    uart_parity_odd = 1
} uart_parity_t;
typedef struct
{
    uint8_t enabled : 1;
    uart_interrupt_enabled_t interrupt : 2;
    uint8_t double_baud_rate : 1;
    uint8_t recieve_enabled : 1;
    uint8_t mode : 3;
    uart_parity_t parity : 1;
    uint32_t baud_rate : 17;
} uart_config_t;

typedef enum
{
    uart_operation_result_success = 0,
    uart_operation_result_parity_mismatch = 1,
} uart_operation_result_t;

#define uart_disabled_cfg ((uart_config_t)0x00000000);
typedef enum{
    use_uart_0 = 0,
    use_uart_1 = 2,
    use_lpuart = 4,
} use_which_uart_t;

void peripheral_enable_uart(use_which_uart_t which_uarts);

void uart_configure(hc32_uart_register_t *uart, const uart_config_t *config);
uart_operation_result_t uart_send(hc32_uart_register_t *uart, uint8_t *data, uint8_t length);
uart_operation_result_t uart_recieve(hc32_uart_register_t *uart, uint8_t *data, uint8_t length);
#endif