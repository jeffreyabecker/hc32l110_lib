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
