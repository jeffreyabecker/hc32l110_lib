#ifndef __HC32L110_REGISTERS_UART_H__
#define __HC32L110_REGISTERS_UART_H__

#ifdef __cplusplus
extern "C"
{
#endif
#if defined(__CC_ARM)
#pragma anon_unions
#endif

#include "hc32l110_registers_platform.h"

    typedef struct
    {
        uint32_t rx_interrupt_enabled : 1;
        uint32_t tx_interrupt_enabled : 1;
        uint32_t recieve_parity_bit : 1;
        uint32_t transmit_parity_bit : 1;
        uint32_t rx_enabled : 1;
        uint32_t multi_host_enabled : 1;
        uint32_t mode : 2;
        uint32_t tx_buffer_empty_interrupt_enabled : 1;
        uint32_t double_baud_rate : 1;
        uint32_t low_power_mode : 1;
        uint32_t clock_select : 2;
        uint32_t prescaler : 3;
    } stc_uart_scon_field_t;

    typedef struct
    {
        uint32_t rx_complete_flag : 1;
        uint32_t tx_complete_flag : 1;
        uint32_t frame_error_flag : 1;
        uint32_t tx_empty_flag : 1;
    } stc_uart_isr_field_t;

    typedef struct
    {
        volatile uint8_t buffer;
        uint8_t RESERVED1[3];
        volatile stc_uart_scon_field_t control;
        volatile uint8_t peripheral_address;
        uint8_t RESERVED2[3];
        volatile uint8_t peripheral_address_mask;
        uint8_t RESERVED3[3];
        __I stc_uart_isr_field_t ISR;
        volatile stc_uart_isr_field_t ICR;
    } M0P_UART_TypeDef;

#define UART00_ADDRESS 0x40000000UL
#define UART01_ADDRESS 0x40000100UL
#define LPUART_ADDRESS 0x40000200UL
#define M0P_UART0 ((M0P_UART_TypeDef *)0x40000000UL)
#define M0P_UART1 ((M0P_UART_TypeDef *)0x40000100UL)
#define M0P_LPUART ((M0P_UART_TypeDef *)LPUART_ADDRESS)
#ifdef __cplusplus
}
#endif

#endif
