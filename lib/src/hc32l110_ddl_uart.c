#include "hc32l110_ddl_uart.h"
#include "hc32l110_ddl_buffers.h"
#include "hc32l110_ddl_basic_timers.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"

#ifndef DDL_UART_BUFFER_SIZE
#define DDL_UART_BUFFER_SIZE 16
#endif

buffer_declare(UART00_RX_BUFFER, DDL_UART_BUFFER_SIZE);
buffer_declare(UART01_RX_BUFFER, DDL_UART_BUFFER_SIZE);
buffer_declare(UARTLP_RX_BUFFER, DDL_UART_BUFFER_SIZE);


void peripheral_enable_uart(peripheral_t which_uarts)
{
    peripheral_t enabled = peripheral_get_enabled();
    if (which_uarts & peripheral_uart0 > 0)
    {
        enabled = enabled | peripheral_uart0 | peripheral_base_timer;
    }
    if (which_uarts & peripheral_uart1 > 0)
    {
        enabled = enabled | peripheral_uart1 | peripheral_base_timer;
    }
    if (which_uarts & peripheral_lpuart > 0)
    {
        enabled = enabled | peripheral_lpuart | peripheral_lptimer;
    }
    peripheral_set_enabled(enabled);
}

static hc32_basic_timer_register_t *__uart_get_timer(hc32_uart_register_t *uart)
{
    return ((uint32_t)uart) == UART00_ADDRESS   ? HC32_TIMER0
           : ((uint32_t)uart) == UART01_ADDRESS ? HC32_TIMER1
           : ((uint32_t)uart) == LPUART_ADDRESS ? HC32_TIMER2
                                                : NULL;
}
static inline void __init_buffer(hc32_uart_register_t *uart){
    buffer_t buff = NULL;
    uint32_t idx = (((uint32_t)uart) - UART00_ADDRESS)/0x100;
    if(idx == 0){
        buff = UART00_RX_BUFFER;
    }
    else if (idx ==1){
        buff = UART01_RX_BUFFER;
    }
    else if(idx == 2){
        buff = UARTLP_RX_BUFFER;
    }
    if(buff != NULL){
        buffer_init(buff,DDL_UART_BUFFER_SIZE);
    }
}
void uart_configure(hc32_uart_register_t *uart, uint32_t baud_rate)
{
    if (baud_rate > 0)
    {
        uart->control.rx_enabled = 0;
        
        uint16_t offset = PeripheralCoreClock / (baud_rate * 32);
        uint8_t dbaud = 0;
        if(offset == 0){
            dbaud = 1; 
            offset = (PeripheralCoreClock *2) / (baud_rate * 32);
        }
        uart->control.rx_interrupt_enabled = 1;
        uart->control.tx_interrupt_enabled = 0;
        uart->control.tx_buffer_empty_interrupt_enabled = 0;
        
        
        uart->control.mode = 1;
        uart->control.double_baud_rate = dbaud;
        hc32_basic_timer_register_t *timer = __uart_get_timer(uart);
        timer->control.timer_running = 0;
        timer->control.tick_source = 0;
        timer->control.mode =1;
        timer->control.enable_inverted_output =1;
        timer->auto_reload = 0x10000 - offset;
        timer->count_16 = timer->auto_reload;
        __init_buffer(uart);
        uart->control.rx_enabled = 1;
        timer->control.timer_running = 1;

    }
    else
    {
        uart->control.rx_interrupt_enabled = 0;
        uart->control.tx_interrupt_enabled = 0;
        uart->control.tx_buffer_empty_interrupt_enabled = 0;
        uart->control.double_baud_rate = 0;
        uart->control.rx_enabled = 0;
    }
}

void UART0_Handler(void){
    if(HC32_UART0->interrupt_flags.rx_complete_flag){
        buffer_append_byte(UART00_RX_BUFFER, HC32_UART0->buffer);
        HC32_UART0->interrupt_clear.rx_complete_flag = 0;
    }
    

nvic_clear_interrupt(UART0_IRQn);
}
void UART1_Handler(void){
nvic_clear_interrupt(UART1_IRQn);
}
void LPUART_Handler(void){
nvic_clear_interrupt(LPUART_IRQn);
}