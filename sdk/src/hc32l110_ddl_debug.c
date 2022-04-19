#include "hc32l110_ddl_debug.h"
#include "hc32l110_system.h"
#include "hc32l110_registers.h"
#include <stdarg.h>
#include <stddef.h>
void debug_init_uart()
{
    HC32_CLOCK->peripheral_clock_enable = HC32_CLOCK->peripheral_clock_enable | peripheral_uart0 | peripheral_basetim;
    // UART0_TXD/P35, 19200bps
    HC32_GPIO_PORT3->ADS &= 0xCF;
    HC32_GPIO_PORT3->DIR &= 0xCF;
    *HC32_GPIO_P35_SEL = port_p35_uart0_txd;
    *HC32_GPIO_P36_SEL = port_p36_uart0_rxd;

    HC32_TIMER0->control_flags.timer_running = 0;
    HC32_TIMER0->control_flags.clock_source = 0;
    HC32_TIMER0->control_flags.mode = 1;
    HC32_TIMER0->control_flags.toggle_enabled = 1;
    HC32_TIMER0->auto_reload = 65536 - (PeripheralCoreClock / (9600 * 32));
    HC32_TIMER0->count16 = HC32_TIMER0->auto_reload;
    HC32_TIMER0->control_flags.timer_running = 1;
    HC32_UART0->control.double_baud_rate = 0;
    HC32_UART0->control.mode = 1;
}
void debug_putchar(char c)
{
    HC32_UART0->control.rx_enabled = 0;
    HC32_UART0->interrupt_clear.tx_complete_flag = 0;
    HC32_UART0->buffer = c;
    while (!HC32_UART0->interrupt_flags.tx_complete_flag)
    {
        __nop();
    }
    HC32_UART0->interrupt_clear.tx_complete_flag = 0;
}

void debug_print(const char *str)
{
    HC32_UART1->control.rx_enabled = 0;
    while ((*str) != '\0')
    {
        HC32_UART0->interrupt_clear.tx_complete_flag = 0;
        HC32_UART0->buffer = *str;
        while (!HC32_UART0->interrupt_flags.tx_complete_flag)
        {
            __nop();
        }
        str++;
    }
    HC32_UART0->interrupt_clear.tx_complete_flag = 0;
}
void debug_printstr(const char *str)
{
    HC32_UART1->control.rx_enabled = 0;
    while ((*str) != '\0')
    {
        HC32_UART0->interrupt_clear.tx_complete_flag = 0;
        HC32_UART0->buffer = *str;
        while (!HC32_UART0->interrupt_flags.tx_complete_flag)
        {
            __nop();
        }
        str++;
    }
    HC32_UART0->interrupt_clear.tx_complete_flag = 0;
}


__read_only_data char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
void debug_print_uint32(uint32_t val)
{
    char formatted[11] = {'0', 'x', '0', '0', '0', '0', '0', '0', '0', '0','\0'};

    for (uint8_t i = 32; i > 0; i -= 4)
    {
        formatted[(8 - (i >> 2)) + 2] = digits[((val >> (i - 4)) & 0xF)];
    }
    debug_print(&(formatted[0]));
}

