#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_gpio.h"
#include "hc32l110_registers_bt.h"
volatile static uint32_t blink_state;
void TIM0_Handler(){
    
    blink_state = blink_state == 1? 0 : 1;
    gpio_digital_write(gpio_port_p02, blink_state);
    nvic_clear_interrupt(TIM0_IRQn);
}
void blink_once(const gpio_port_descriptor_t *port)
{
    systick_delay(500);
    gpio_digital_write(port, 1);

    systick_delay(500);
    gpio_digital_write(port, 0);
}
int main()
{
    blink_state = 1;
    enable_systick(KHz_1);
    peripheral_enable_gpio();
    peripheral_set_enabled(peripheral_get_enabled() | peripheral_basetim);

    gpio_configure(gpio_port_p01, gpio_digital_output);
    gpio_configure(gpio_port_p02, gpio_digital_output);

    gpio_digital_write(gpio_port_p01, blink_state);
    gpio_digital_write(gpio_port_p02, blink_state);

    M0P_BT0->CR_f.TR = 0;
    M0P_BT0->ICLR = 0;
    M0P_BT0->CR_f.MD = 1;
    M0P_BT0->CR_f.CT = 0;
    M0P_BT0->CR_f.TOG_EN = 0;
    M0P_BT0->CR_f.PRS = 5;
    M0P_BT0->CR_f.GATE = 0;
    M0P_BT0->CR_f.GATE_P = 0;
    M0P_BT0->CR_f.IE = 1;
    M0P_BT0->CNT = 0;
    M0P_BT0->ARR = 0;
    M0P_BT0->CR_f.TR = 1;

    while (1)
    {
        blink_once(gpio_port_p01);
    }
}
