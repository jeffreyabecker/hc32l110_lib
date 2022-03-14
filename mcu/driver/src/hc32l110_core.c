#include "hc32l110_core.h"
#include "hc32l110_system.h"

static uint32_t tick_increment_step = 0ul;
__IO static uint32_t current_tick_count = 0ul;


/**
 * @brief This function Initializes the interrupt frequency of the SysTick.
 * @details Initializes the systick frequency to (1/tick_frequency)s
 * @param [in] tick_frequency                  SysTick interrupt frequency (1 to 0xFFFFFF).
 * @retval An uint8_t e:
 *           - Ok: SysTick Initializes succeed
 *           - Error: SysTick Initializes failed
 */
uint8_t systick_init(uint32_t tick_frequency)
{
    if ((1UL <= tick_frequency) && (tick_frequency <= 0XFFFFFFUL))
    {
        peripheral_set_enabled( peripheral_get_enabled() | peripheral_systick);
        tick_increment_step = 1000UL / tick_frequency;
        SysTick_Config(SystemCoreClock / tick_frequency);
        return 1;
    }
    return 0;
}

/**
 * @brief This function provides minimum delay (in milliseconds).
 * @param [in] delay_ticks                 Delay specifies the delay time.
 * @retval None
 */
void systick_delay(uint32_t delay_ticks)
{
    const uint32_t tick_start = systick_get_tick();
    uint32_t tick_end;
    uint32_t tickMax;

    if (tick_increment_step != 0ul)
    {
        tickMax = (0xFFFFFFFFul / tick_increment_step) * tick_increment_step;
        /* Add a freq to guarantee minimum wait */
        if ((delay_ticks >= tickMax) || ((tickMax - delay_ticks) < tick_increment_step))
        {
            tick_end = tickMax;
        }
        else
        {
            tick_end = delay_ticks + tick_increment_step;
        }

        while ((systick_get_tick() - tick_start) < tick_end)
        {
        }
    }
}

/**
 * @brief This function is called to increment a global variable "u32TickCount".
 * @note  This variable is incremented in SysTick ISR.
 * @param None
 * @retval None
 */
void systick_increment_ticks(void)
{
    current_tick_count += tick_increment_step;
}

/**
 * @brief Provides a tick value 
 * @param None
 * @retval Tick value
 */
uint32_t systick_get_tick(void)
{
    return current_tick_count;
}

/**
 * @brief Suspend SysTick increment.
 * @param None
 * @retval None
 */
void systick_disable(void)
{
    /* Disable SysTick Interrupt */
    CLEAR_REG32_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Pos);
}

/**
 * @brief Resume SysTick increment.
 * @param None
 * @retval None
 */
void systick_enable(void)
{
     SET_REG32_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Pos);
}
void ports_set_function(port_number_t port, uint8_t function)
{
    switch (port)
    {
    case port_p01:
        M0P_GPIO->P01_SEL = function;
        return;
    case port_p02:
        M0P_GPIO->P02_SEL = function;
        return;
    case port_p03:
        M0P_GPIO->P03_SEL = function;
        return;
    case port_p14:
        M0P_GPIO->P14_SEL = function;
        return;
    case port_p15:
        M0P_GPIO->P15_SEL = function;
        return;
    case port_p23:
        M0P_GPIO->P23_SEL = function;
        return;
    case port_p24:
        M0P_GPIO->P24_SEL = function;
        return;
    case port_p25:
        M0P_GPIO->P25_SEL = function;
        return;
    case port_p26:
        M0P_GPIO->P26_SEL = function;
        return;
    case port_p27:
        M0P_GPIO->P27_SEL = function;
        return;
    case port_p31:
        M0P_GPIO->P31_SEL = function;
        return;
    case port_p32:
        M0P_GPIO->P32_SEL = function;
        return;
    case port_p33:
        M0P_GPIO->P33_SEL = function;
        return;
    case port_p34:
        M0P_GPIO->P34_SEL = function;
        return;
    case port_p35:
        M0P_GPIO->P35_SEL = function;
        return;
    case port_p36:
        M0P_GPIO->P36_SEL = function;
        return;
    default:
        break;
    }
}

uint8_t ports_get_function(port_number_t port)
{
    switch (port)
    {
    case port_p01:
        return M0P_GPIO->P01_SEL;
    case port_p02:
        return M0P_GPIO->P02_SEL;
    case port_p03:
        return M0P_GPIO->P03_SEL;
    case port_p14:
        return M0P_GPIO->P14_SEL;
    case port_p15:
        return M0P_GPIO->P15_SEL;
    case port_p23:
        return M0P_GPIO->P23_SEL;
    case port_p24:
        return M0P_GPIO->P24_SEL;
    case port_p25:
        return M0P_GPIO->P25_SEL;
    case port_p26:
        return M0P_GPIO->P26_SEL;
    case port_p27:
        return M0P_GPIO->P27_SEL;
    case port_p31:
        return M0P_GPIO->P31_SEL;
    case port_p32:
        return M0P_GPIO->P32_SEL;
    case port_p33:
        return M0P_GPIO->P33_SEL;
    case port_p34:
        return M0P_GPIO->P34_SEL;
    case port_p35:
        return M0P_GPIO->P35_SEL;
    case port_p36:
        return M0P_GPIO->P36_SEL;
    default:
        return 0;
    }
}
