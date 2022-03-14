#ifndef __hc32l110_UART_H__
#define __hc32l110_UART_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"

#include "hc32l110_core.h"
#include "hc32l110_basic_timers.h"

    __STATIC_FORCEINLINE uint8_t uart_get_rx_complete_flag(M0P_UART_TypeDef *uart)
    {
        return uart->ISR.rx_complete_flag;
    }
    __STATIC_FORCEINLINE void uart_clear_rx_complete_flag(M0P_UART_TypeDef *uart) { uart->ICR.rx_complete_flag = 0; }
    __STATIC_FORCEINLINE uint8_t uart_get_tx_complete_flag(M0P_UART_TypeDef *uart) { return uart->ISR.tx_complete_flag; }
    __STATIC_FORCEINLINE void uart_clear_tx_complete_flag(M0P_UART_TypeDef *uart) { uart->ICR.tx_complete_flag = 0; }
    __STATIC_FORCEINLINE uint8_t uart_get_frame_error_flag(M0P_UART_TypeDef *uart) { return uart->ISR.frame_error_flag; }
    __STATIC_FORCEINLINE void uart_clear_frame_error_flag(M0P_UART_TypeDef *uart) { uart->ICR.frame_error_flag = 0; }
    __STATIC_FORCEINLINE uint8_t uart_get_tx_empty_flag(M0P_UART_TypeDef *uart) { return uart->ISR.tx_empty_flag; }
    __STATIC_FORCEINLINE void uart_clear_tx_empty_flag(M0P_UART_TypeDef *uart) { uart->ICR.tx_empty_flag = 0; }

    typedef enum
    {
        uart_interrupt_enabled_none = 0,
        uart_interrupt_enabled_recieve = 1,
        uart_interrupt_enabled_transmit = 2,
        uart_interrupt_enabled_transmit_empty = 4,
    } uart_interrupt_enabled_t;
    typedef enum
    {
        /*synchronous, half-duplex, 8 data bits, 0 start bits, 0 stop bits, 0 parity bits, timer required = false, baud = PeripheralClock/12*/
        uart_baud_mode_0 = 0,
        /*aynchronous, full-duplex, 8 data bits, 1 start bits, 1 stop bits, 0 parity bits, timer required = true, baud = ((dbaud+1)*PeripheralClock)/ (32* (65536 - TIMX_ARR))*/
        uart_baud_mode_1 = 1,
        /*aynchronous, full-duplex, 8 data bits, 1 start bits, 1 stop bits, 1 parity bits, timer required = false, baud = ((dbaud+1)*PeripheralClock)/ 64)*/
        uart_baud_mode_2 = 2,
        /*aynchronous, full-duplex, 8 data bits, 1 start bits, 1 stop bits, 1 parity bits, timer required = false, baud = ((dbaud+1)*PeripheralClock)/ (32* (65536 - TIMX_ARR))*/
        uart_baud_mode_3 = 3
    } uart_mode_t;
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
        uart_mode_t mode : 3;
        uart_parity_t parity : 1;
        uint32_t baud_rate : 17;
    } uart_config_t;
    typedef enum
    {
        uart_operation_result_success = 0,
        uart_operation_result_parity_mismatch = 1,
    } uart_operation_result_t;
#define uart_disabled() ((uart_config_t)0x00000000);

    void uart_configure(M0P_UART_TypeDef *uart, uart_config_t *config);

    uart_operation_result_t uart_send(M0P_UART_TypeDef *uart, uint8_t *data, size_t length);
    uart_operation_result_t uart_recieve(M0P_UART_TypeDef *uart, uint8_t *data, size_t length);
#ifdef __cplusplus
}
#endif

#endif
