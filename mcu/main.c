#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"
#include "hc32l110_registers_bt.h"
// volatile static uint32_t blink_state;
// void handle_timer_fired(int32_t irq){
    
//     blink_state = blink_state == 1? 0 : 1;
//     gpio_digital_write(gpio_port_p02, blink_state);
//     nvic_clear_interrupt((IRQn_Type)irq);
//     M0P_BT0->ICLR = 0;
// }
// void IRQ00_Handler (void){ handle_timer_fired(0); }
// void IRQ01_Handler (void){ handle_timer_fired(1); }
// void IRQ02_Handler (void){ handle_timer_fired(2); }
// void IRQ03_Handler (void){ handle_timer_fired(3); }
// void IRQ04_Handler (void){ handle_timer_fired(4); }
// void IRQ05_Handler (void){ handle_timer_fired(5); }
// void IRQ06_Handler (void){ handle_timer_fired(6); }
// void IRQ07_Handler (void){ handle_timer_fired(7); }
// void IRQ08_Handler (void){ handle_timer_fired(8); }
// void IRQ09_Handler (void){ handle_timer_fired(9); }
// void IRQ10_Handler (void){ handle_timer_fired(10); }
// void IRQ11_Handler (void){ handle_timer_fired(11); }
// void IRQ12_Handler (void){ handle_timer_fired(12); }
// void IRQ13_Handler (void){ handle_timer_fired(13); }
// void IRQ14_Handler (void){ handle_timer_fired(14); }
// void IRQ15_Handler (void){ handle_timer_fired(15); }
// void IRQ16_Handler (void){ handle_timer_fired(16); }
// void IRQ17_Handler (void){ handle_timer_fired(17); }
// void IRQ18_Handler (void){ handle_timer_fired(18); }
// void IRQ19_Handler (void){ handle_timer_fired(19); }
// void IRQ20_Handler (void){ handle_timer_fired(20); }
// void IRQ21_Handler (void){ handle_timer_fired(21); }
// void IRQ22_Handler (void){ handle_timer_fired(22); }
// void IRQ23_Handler (void){ handle_timer_fired(23); }
// void IRQ24_Handler (void){ handle_timer_fired(24); }
// void IRQ25_Handler (void){ handle_timer_fired(25); }
// void IRQ26_Handler (void){ handle_timer_fired(26); }
// void IRQ27_Handler (void){ handle_timer_fired(27); }
// void IRQ28_Handler (void){ handle_timer_fired(28); }
// void IRQ29_Handler (void){ handle_timer_fired(29); }
// void IRQ30_Handler (void){ handle_timer_fired(30); }
// void IRQ31_Handler (void){ handle_timer_fired(31); }

int main()
{
    //blink_state = 1;
    enable_systick(KHz_1);
    peripheral_enable_gpio();
    // peripheral_set_enabled(peripheral_get_enabled() | peripheral_basetim);
    // nvic_configure_interrupt(TIM0_IRQn,nvic_default_irq_priority, 1);

    gpio_configure(gpio_port_p01, gpio_digital_output);
    gpio_configure(gpio_port_p02, gpio_digital_output);

    gpio_digital_write(gpio_port_p01, 1);
    gpio_digital_write(gpio_port_p02, 1);

    // M0P_BT0->CR_f.TR = 0;
    // M0P_BT0->ICLR = 0;
    // M0P_BT0->CR_f.MD = 0;
    // M0P_BT0->CR_f.CT = 0;
    // M0P_BT0->CR_f.TOG_EN = 0;
    // M0P_BT0->CR_f.PRS = 2;
    // M0P_BT0->CR_f.GATE = 0;
    // M0P_BT0->CR_f.GATE_P = 0;
    // M0P_BT0->CR_f.IE = 1;
    // M0P_BT0->CNT = 0;
    // M0P_BT0->CNT32 = 0xFFFF0000;
    // M0P_BT0->ARR = 0;
    // M0P_BT0->CR_f.TR = 1;

    while (1)
    {
    systick_delay(500);
    gpio_digital_write(gpio_port_p01, 1);

    systick_delay(500);
    gpio_digital_write(gpio_port_p01, 0);
    }
}
