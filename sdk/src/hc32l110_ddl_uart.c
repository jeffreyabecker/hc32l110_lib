#include "hc32l110_ddl_debug.h"
#include "hc32l110_system.h"
#include "hc32l110_registers.h"
#include "hc32l110_ddl_gpio.h"
#include "hc32l110_ddl_buffers.h"
#include "hc32l110_ddl_uart.h"
#include <stdarg.h>
#include <stddef.h>
#define UART_INDEX(UART) ((((uint32_t)UART) - UART00_ADDRESS) / 4 * 32)
#define UART_TIMER(INDEX) ((hc32_basic_timer_register_t *)(TIMER_0_ADDRESS + INDEX))

typedef struct
{
    const gpio_port_descriptor_t *tx_port;
    uint8_t tx_function;
    const gpio_port_descriptor_t *rx_port;
    uint8_t rx_function;
} uart_port_config_t;

__read_only_data static uart_port_config_t uart_port_configs[3] = {
    {.tx_port = gpio_port_p35,
     .tx_function = port_p35_uart0_txd,
     .rx_port = gpio_port_p36,
     .rx_function = port_p36_uart0_rxd},
    {.tx_port = gpio_port_p23,
     .tx_function = port_p23_uart1_txd,
     .rx_port = gpio_port_p24,
     .rx_function = port_p24_uart1_rxd},
    {.tx_port = gpio_port_p34,
     .tx_function = port_p34_lpuart_txd,
     .rx_port = gpio_port_p33,
     .rx_function = port_p33_lpuart_rxd},
};

void init_uart(hc32_uart_register_t *uart, uint32_t baud)
{
    uint32_t uart_index = UART_INDEX(uart);
    hc32_basic_timer_register_t *timer = UART_TIMER(uart_index);
    gpio_port_config_t cfg = {
        .direction = gpio_output,
        .resolution = 0,
        .drive_mode = 0,
        .pull_up = 1,
        .pull_down = 0,
        .gpio_mode = gpio_digital,
        .enable_interrupt = 0};
    cfg.function = uart_port_configs[uart_index].tx_function;
    gpio_configure(uart_port_configs[uart_index].tx_port, cfg);
    cfg.function = uart_port_configs[uart_index].rx_function;
    gpio_configure(uart_port_configs[uart_index].rx_port, cfg);

    timer->control_flags.timer_running = 0;
    timer->control_flags.clock_source = 0;
    timer->control_flags.mode = 1;
    timer->control_flags.toggle_enabled = 1;
    timer->auto_reload = 65536 - (PeripheralCoreClock / (baud * 32));
    timer->count16 = timer->auto_reload;
    timer->control_flags.timer_running = 1;
    uart->control.double_baud_rate = 0;
    uart->control.mode = 1;
}
void uart_put_byte(hc32_uart_register_t *uart, uint8_t byte)
{
    uart->control.rx_enabled = 0;
    uart->interrupt_clear.tx_complete_flag = 0;
    uart->buffer = byte;
    while (!uart->interrupt_flags.tx_complete_flag)
    {
        __nop();
    }
    uart->interrupt_clear.tx_complete_flag = 0;
}
void uart_send(hc32_uart_register_t *uart, uint8_t* data, uint8_t length)
{
    HC32_UART1->control.rx_enabled = 0;
    for(uint8_t i=0; i< length; i++){
        HC32_UART0->interrupt_clear.tx_complete_flag = 0;
        HC32_UART0->buffer =data[i];
        while (!HC32_UART0->interrupt_flags.tx_complete_flag)
        {
            __nop();
        }
    }
}
uint8_t uart_get_byte(hc32_uart_register_t *uart)
{
    uart->control.rx_enabled = 1;
    while (!uart->interrupt_clear.rx_complete_flag)
    {
        __nop();
    }
    uint8_t result = uart->buffer;
    uart->interrupt_flags.rx_complete_flag = 0;
    return result;
}

typedef struct
{
    uart_event_handler_t handler;
    buffer_t tx_buffer;
    buffer_t rx_buffer;
} uart_buffer_ref_t;
static uart_buffer_ref_t uart_buffers[3];

void uart_set_handler(hc32_uart_register_t *uart, uart_event_handler_t handler)
{
    uart_buffers[UART_INDEX(uart)].handler = handler;
}

void uart_set_buffer(hc32_uart_register_t *uart, buffer_t tx_buffer, uint8_t tx_length, buffer_t rx_buffer, uint8_t rx_length)
{
    if (tx_buffer != NULL)
    {
        buffer_init(tx_buffer, tx_length);
    }
    if (rx_buffer != NULL)
    {
        buffer_init(rx_buffer, rx_length);
    }
    uint32_t index = UART_INDEX(uart);
    uart_buffers[index].tx_buffer = tx_buffer;

    uart_buffers[index].rx_buffer = rx_buffer;
    uart->control.tx_interrupt_enabled = tx_buffer != NULL ? 1 : 0;
    uart->control.rx_interrupt_enabled = rx_buffer != NULL ? 1 : 0;
}
uint8_t uart_buffered_tx(hc32_uart_register_t *uart, const uint8_t *data, uint8_t length)
{
    uint32_t index = UART_INDEX(uart);
    uint8_t bytes_written = 0;

    if (uart_buffers[index].tx_buffer != NULL && length > 0)
    {
        uint8_t was_empty = buffer_length(uart_buffers[index].tx_buffer) == 0 ? 1 : 0;
        bytes_written = buffer_write(uart_buffers[index].tx_buffer, data, length);
        if (was_empty == 1)
        {
            uint8_t first_byte = 0;
            buffer_get_byte(uart_buffers[index].tx_buffer, &first_byte);
            uart->interrupt_clear.tx_complete_flag = 0;
            uart->buffer = first_byte;
        }
    }
    return bytes_written;
}
uint8_t uart_buffered_rx(hc32_uart_register_t *uart, uint8_t *data, uint8_t length)
{
    uint32_t index = UART_INDEX(uart);
    uint8_t bytes_read = 0;
    if (uart_buffers[index].tx_buffer != NULL && length > 0)
    {
        bytes_read = buffer_read(uart_buffers[index].tx_buffer, data, length);
    }
    return bytes_read;
}
static void __uart_process_interrupt(hc32_uart_register_t *uart)
{
    uart_event_t event = uart_event_none;
    uint32_t index = UART_INDEX(uart);
    if (uart->interrupt_flags.rx_complete_flag)
    {
        if (uart_buffers[index].rx_buffer != NULL)
        {
            buffer_append_byte(uart_buffers[index].rx_buffer, uart->buffer);
        }
        uart->interrupt_clear.rx_complete_flag = 0;
        event = event | uart_event_rx;
    }

    if (uart->interrupt_flags.tx_complete_flag)
    {
        event = event | uart_event_tx;
        uart->interrupt_clear.tx_complete_flag = 0;
        if (uart_buffers[index].tx_buffer != NULL && buffer_length(uart_buffers[index].tx_buffer) > 0)
        {
            uint8_t b = 0;
            buffer_get_byte(uart_buffers[index].tx_buffer, &b);
            uart->buffer = b;
        }
    }
    if (uart->interrupt_flags.frame_error_flag)
    {
        uart->interrupt_clear.frame_error_flag = 0;
        event = event | uart_event_err;
    }
    if (uart_buffers[index].handler != NULL)
    {
        (uart_buffers[index].handler)(uart, event, uart_buffers[index].tx_buffer, uart_buffers[index].rx_buffer);
    }
}

void IRQ06_Handler(void)
{
    __uart_process_interrupt(HC32_UART0);
    nvic_clear_interrupt(irq_uart_0);
}
void IRQ07_Handler(void)
{
    __uart_process_interrupt(HC32_UART1);
    nvic_clear_interrupt(irq_uart_1);
}
void IRQ08_Handler(void)
{
    __uart_process_interrupt(HC32_LPUART);
    nvic_clear_interrupt(irq_lp_uart);
}