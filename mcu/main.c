
#include "hc32l110_system.h"
#include "hc32l110_registers_gpio.h"
#include "hc32l110_registers_clock.h"
#include "hc32l110_cmsis.h"

uint8_t state = 0;

void SysTick_Handler(void)
{
    if (state > 0)
    {
        M0P_GPIO->P2OUT = 248;
        M0P_GPIO->P3OUT = 126;
    }
    else
    {
        M0P_GPIO->P2OUT = 0;
        M0P_GPIO->P3OUT = 0;
    }
    state = !state;
}

int main()
{
    M0P_CLOCK->peripheral_clock_enable_f.GPIO = 1;
    M0P_CLOCK->peripheral_clock_enable_f.TICK = 1;

    M0P_GPIO->P0DIR = 0x00;
    M0P_GPIO->P1DIR = 0x00;
    M0P_GPIO->P2DIR = 0x00;
    M0P_GPIO->P3DIR = 0x00;
    M0P_GPIO->P0OUT = 14;
    M0P_GPIO->P1OUT = 48;
    M0P_CLOCK->SYSTICK_CR.CLK_SEL = systick_clock_source_internal_high;
    M0P_CLOCK->SYSTICK_CR.NOREF = 1;
    
    SysTick->LOAD = 0x00200000;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;  
    while (1)
    {
        __NOP();
    }
}