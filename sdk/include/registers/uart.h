#ifndef __HC32L110_REGISTERS_UART_H__
#define __HC32L110_REGISTERS_UART_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
typedef struct
{
    volatile uint8_t rx_interrupt_enabled : 1;
    volatile uint8_t tx_interrupt_enabled : 1;
    volatile uint8_t recieve_parity_bit : 1;
    volatile uint8_t transmit_parity_bit : 1;
    volatile uint8_t rx_enabled : 1;
    volatile uint8_t multi_host_enabled : 1;
    volatile uint8_t mode : 2;
    volatile uint8_t tx_buffer_empty_interrupt_enabled : 1;
    volatile uint8_t double_baud_rate : 1;
    volatile uint8_t low_power_mode : 1;
    volatile uint8_t clock_select : 2;
    volatile uint8_t prescaler : 3;
} uart_scon_field_t;

typedef struct
{
    volatile uint32_t rx_complete_flag : 1;
    volatile uint32_t tx_complete_flag : 1;
    volatile uint32_t frame_error_flag : 1;
    volatile uint32_t tx_empty_flag : 1;
} uart_isr_field_t;

typedef struct
{
    volatile uint8_t buffer;
    uint8_t reserved1[3];
    volatile uart_scon_field_t control;
    volatile uint8_t peripheral_address;
    uint8_t reserved2[3];
    volatile uint8_t peripheral_address_mask;
    uint8_t reserved3[3];
    union
    {
        volatile uint32_t ISR;
        uart_isr_field_t interrupt_flags;
    };
    union
    {
        volatile uint32_t ICR;
        uart_isr_field_t interrupt_clear;
    };
} hc32_uart_register_t;

#define UART00_ADDRESS 0x40000000UL
#define UART01_ADDRESS 0x40000100UL
#define LPUART_ADDRESS 0x40000200UL
#define HC32_UART0 ((hc32_uart_register_t *)UART00_ADDRESS)
#define HC32_UART1 ((hc32_uart_register_t *)UART01_ADDRESS)
#define HC32_LPUART ((hc32_uart_register_t *)LPUART_ADDRESS)
#ifdef __cplusplus
}
#endif

#endif
