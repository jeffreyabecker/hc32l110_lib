#include "hc32l110_ddl_debug.h"
#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_uart.h"
#include "hc32l110_registers_basic_timers.h"

void debug_init_uart(){
    uint32_t u32Pclk1 =  0;
    volatile uint32_t u32ReloadVal = 0;

    // UART0_TXD/P35, 19200bps
    HC32_GPIO_PORT3->ADS &= ~(1 <<6);
    HC32_GPIO_PORT3->DIR &= ~(1 <<6);
    *HC32_GPIO_P35_SEL = 3;

    HC32_TIMER0->control.timer_running = 0;
    HC32_TIMER0->control.tick_source = 0;
    HC32_TIMER0->control.mode = 1;
    HC32_TIMER0->control.enable_inverted_output;
    HC32_TIMER0->auto_reload = 65536 - PeripheralCoreClock * 2 / 19200 / 32;
    HC32_TIMER0->count_16 = HC32_TIMER0->auto_reload;
    HC32_TIMER0->control.timer_running = 0;
    HC32_UART0->control.double_baud_rate =  1;
    HC32_UART0->control.mode = 1;
}