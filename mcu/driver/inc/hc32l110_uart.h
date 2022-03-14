#ifndef __hc32l110_UART_H__
#define __hc32l110_UART_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"

#include "hc32l110_core.h"
#include "hc32l110_basic_timers.h"
    // __STATIC_FORCEINLINE uint8_t uart_get_rx_interrupt_enabled(M0P_UART_TypeDef* uart){ return uart->control.rx_interrupt_enabled;}
    // __STATIC_FORCEINLINE void uart_set_rx_interrupt_enabled(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.rx_interrupt_enabled = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_tx_interrupt_enabled(M0P_UART_TypeDef* uart){ return uart->control.tx_interrupt_enabled;}
    // __STATIC_FORCEINLINE void uart_set_tx_interrupt_enabled(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.tx_interrupt_enabled = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_data_recieved(M0P_UART_TypeDef* uart){ return uart->control.data_recieved;}
    // __STATIC_FORCEINLINE void uart_set_data_recieved(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.data_recieved = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_transmit_data(M0P_UART_TypeDef* uart){ return uart->control.transmit_data;}
    // __STATIC_FORCEINLINE void uart_set_transmit_data(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.transmit_data = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_rx_enabled(M0P_UART_TypeDef* uart){ return uart->control.rx_enabled;}
    // __STATIC_FORCEINLINE void uart_set_rx_enabled(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.rx_enabled = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_multi_host_enabled(M0P_UART_TypeDef* uart){ return uart->control.multi_host_enabled;}
    // __STATIC_FORCEINLINE void uart_set_multi_host_enabled(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.multi_host_enabled = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_mode(M0P_UART_TypeDef* uart){ return uart->control.mode;}
    // __STATIC_FORCEINLINE void uart_set_mode(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.mode = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_tx_buffer_empty_interrupt_enabled(M0P_UART_TypeDef* uart){ return uart->control.tx_buffer_empty_interrupt_enabled;}
    // __STATIC_FORCEINLINE void uart_set_tx_buffer_empty_interrupt_enabled(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.tx_buffer_empty_interrupt_enabled = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_double_baud_rate(M0P_UART_TypeDef* uart){ return uart->control.double_baud_rate;}
    // __STATIC_FORCEINLINE void uart_set_double_baud_rate(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.double_baud_rate = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_low_power_mode(M0P_UART_TypeDef* uart){ return uart->control.low_power_mode;}
    // __STATIC_FORCEINLINE void uart_set_low_power_mode(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.low_power_mode = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_clock_select(M0P_UART_TypeDef* uart){ return uart->control.clock_select;}
    // __STATIC_FORCEINLINE void uart_set_clock_select(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.clock_select = value; }
    // __STATIC_FORCEINLINE uint8_t uart_get_prescaler(M0P_UART_TypeDef* uart){ return uart->control.prescaler;}
    // __STATIC_FORCEINLINE void uart_set_prescaler(M0P_UART_TypeDef* uart, uint8_t value){ uart->control.prescaler = value; }

    __STATIC_FORCEINLINE uint8_t uart_get_rx_complete_flag(M0P_UART_TypeDef *uart) { return uart->ISR.rx_complete_flag; }
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
        uart_baud_mode_3 = 3
    } uart_mode_t;
    typedef struct
    {
        uint8_t enabled : 1;
        uart_interrupt_enabled_t interrupt : 2;
        uint8_t double_baud_rate : 1;
        uint8_t recieve_enabled : 1;
        uart_mode_t mode : 3;
        uint32_t baud_rate : 17;
    } uart_config_t;
#define uart_disabled() ((uart_config_t)0x00000000);

    __STATIC_INLINE M0P_BasicTimer_TypeDef *__uart_get_timer(M0P_UART_TypeDef *uart)
    {
        return ((uint32_t)uart) == UART00_ADDRESS   ? M0P_TIMER0
               : ((uint32_t)uart) == UART01_ADDRESS ? M0P_TIMER1
               : ((uint32_t)uart) == LPUART_ADDRESS ? M0P_TIMER2
                                                    : NULL;
    }

    //     #define TIMER_0_ADDRESS 0x40000C00UL
    // #define TIMER_1_ADDRESS 0x40000C20UL
    // #define TIMER_2_ADDRESS 0x40000C40UL
    // #define LPTIMER_ADDRESS 0x40000C60UL
    void uart_configure(M0P_UART_TypeDef *uart, uart_config_t config)
    {
        if (config.enabled)
        {
            uart->control.rx_interrupt_enabled = config.interrupt & uart_interrupt_enabled_recieve > 0 ? 1 : 0;
            uart->control.tx_interrupt_enabled = config.interrupt & uart_interrupt_enabled_transmit > 0 ? 1 : 0;
            uart->control.tx_buffer_empty_interrupt_enabled = config.interrupt & uart_interrupt_enabled_transmit_empty > 0 ? 1 : 0;
            uart->control.double_baud_rate = config.double_baud_rate;
            uart->control.rx_enabled = config.recieve_enabled;
        }
        else
        {
            uart->control.rx_interrupt_enabled = 0;
            uart->control.tx_interrupt_enabled = 0;
            uart->control.tx_buffer_empty_interrupt_enabled = 0;
            uart->control.double_baud_rate = config.double_baud_rate;
            uart->control.rx_enabled = 0;
        }
    }

    // typedef struct
    // {
    //     uint32_t rx_interrupt_enabled : 1;
    //     uint32_t tx_interrupt_enabled : 1;
    //     uint32_t data_recieved : 1;
    //     uint32_t transmit_data : 1;
    //     uint32_t rx_enabled : 1;
    //     uint32_t multi_host_enabled : 1;
    //     uint32_t mode : 2;
    //     uint32_t tx_buffer_empty_interrupt_enabled : 1;
    //     uint32_t double_baud_rate : 1;
    //     uint32_t low_power_mode : 1;
    //     uint32_t clock_select : 2;
    //     uint32_t prescaler : 3;
    // } stc_uart_scon_field_t;

    // typedef struct
    // {
    //     uint32_t rx_complete_flag : 1;
    //     uint32_t tx_complete_flag : 1;
    //     uint32_t frame_error_flag : 1;
    //     uint32_t tx_empty_flag : 1;
    // } stc_uart_isr_field_t;

    // typedef struct
    // {
    //     __IO uint8_t buffer;
    //     uint8_t RESERVED1[3];
    //     __IO stc_uart_scon_field_t control;
    //     __IO uint8_t peripheral_address;
    //     uint8_t RESERVED2[3];
    //     __IO uint8_t peripheral_address_mask;
    //     uint8_t RESERVED3[3];
    //     __I stc_uart_isr_field_t ISR;
    //     __O stc_uart_isr_field_t ICR;
    // } M0P_UART_TypeDef;

#ifdef __cplusplus
}
#endif

#endif
