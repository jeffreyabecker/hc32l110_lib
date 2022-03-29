#include "hc32l110_ddl_debug.h"
#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_uart.h"
#include "hc32l110_registers_basic_timers.h"
#include <stddef.h>
void debug_init_uart()
{

    // UART0_TXD/P35, 9600bps
    HC32_GPIO_PORT3->ADS &= ~(1 << 6);
    HC32_GPIO_PORT3->DIR &= ~(1 << 6);
    *HC32_GPIO_P35_SEL = port_p35_uart0_txd;

    HC32_TIMER0->control.timer_running = 0;
    HC32_TIMER0->control.tick_source = 0;
    HC32_TIMER0->control.mode = 1;
    HC32_TIMER0->control.enable_inverted_output;
    HC32_TIMER0->auto_reload = 65536 - PeripheralCoreClock * 2 / 9600 / 32;
    HC32_TIMER0->count_16 = HC32_TIMER0->auto_reload;
    HC32_TIMER0->control.timer_running = 1;
    HC32_UART0->control.double_baud_rate = 1;
    HC32_UART0->control.mode = 1;
}

void debug_print(uint8_t *str)
{
    HC32_UART0->control.rx_enabled = 0;
    while(*str != NULL){
        HC32_UART0->interrupt_clear.tx_complete_flag = 0;
        HC32_UART0->buffer = *str;
        while(!HC32_UART0->interrupt_flags.tx_complete_flag){
            __NOP();
        }
        str++;
    }
    HC32_UART0->interrupt_clear.tx_complete_flag = 0;
}