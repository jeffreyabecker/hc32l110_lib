#include "hc32l110_ddl_uart.h"
#include "hc32l110_ddl_buffers.h"
#include "hc32l110_ddl_basic_timers.h"
#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"

#ifndef DDL_UART_0_BUFFER_SIZE
#define DDL_UART_0_BUFFER_SIZE 16
#endif
#ifndef DDL_UART_1_BUFFER_SIZE
#define DDL_UART_1_BUFFER_SIZE 16
#endif
#ifndef DDL_LPUART_BUFFER_SIZE
#define DDL_LPUART_BUFFER_SIZE 16
#endif

void peripheral_enable_uart(use_which_uart_t which_uarts)
{
    peripheral_t enabled = peripheral_get_enabled();
    if( which_uarts & use_uart_0 > 0){
        enabled = enabled | peripheral_uart0| peripheral_base_timer;
    }
    if( which_uarts & use_uart_1 > 0){
        enabled = enabled | peripheral_uart1| peripheral_base_timer;
    }
    if( which_uarts & use_lpuart > 0){
        enabled = enabled | peripheral_lptimer| peripheral_lpuart;
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
static uint16_t __uart_calculate_timer_prescaler(uart_config_t *config)
{
    if (config->mode == 0 || config->mode == 2)
    {
        return 0;
    }
    else
    {
        return 0x10000 - ((core_get_peripheral_clock_frequency() * (config->double_baud_rate + 1)) / (config->baud_rate * 32));
    }
}
void uart_configure(hc32_uart_register_t *uart, const uart_config_t *config)
{
    if (config->enabled)
    {
        uart->control.rx_interrupt_enabled = config->interrupt & uart_interrupt_enabled_recieve > 0 ? 1 : 0;
        uart->control.tx_interrupt_enabled = config->interrupt & uart_interrupt_enabled_transmit > 0 ? 1 : 0;
        uart->control.tx_buffer_empty_interrupt_enabled = config->interrupt & uart_interrupt_enabled_transmit_empty > 0 ? 1 : 0;
        uart->control.double_baud_rate = config->double_baud_rate;
        uart->control.rx_enabled = config->recieve_enabled;
        if (config->mode == 1 || config->mode == 3)
        {
            hc32_basic_timer_register_t *timer = __uart_get_timer(uart);

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