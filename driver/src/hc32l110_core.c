/**
 *******************************************************************************
 * @file  hc32l110_utility.c
 * @brief This file provides utility functions for DDL.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-20       Yangjp          First version
   2020-01-08       Wuze            Added function '_write' for printf in GCC compiler.
   2020-12-03       Yangjp          Fixed systick_delay function overflow handling
   2022-03-05       jbecker         adapted for hc32l110 series   
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2016, Huada Semiconductor Co., Ltd. All rights reserved.
 *
 * This software is owned and published by:
 * Huada Semiconductor Co., Ltd. ("HDSC").
 *
 * BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
 * BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
 *
 * This software contains source code for use with HDSC
 * components. This software is licensed by HDSC to be adapted only
 * for use in systems utilizing HDSC components. HDSC shall not be
 * responsible for misuse or illegal use of this software for devices not
 * supported herein. HDSC is providing this software "AS IS" and will
 * not be responsible for issues arising from incorrect user implementation
 * of the software.
 *
 * Disclaimer:
 * HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
 * REGARDING THE SOFTWARE (INCLUDING ANY ACCOMPANYING WRITTEN MATERIALS),
 * ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
 * WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
 * WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
 * WARRANTY OF NONINFRINGEMENT.
 * HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
 * NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
 * LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
 * INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
 * SAVINGS OR PROFITS,
 * EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
 * INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
 * FROM, THE SOFTWARE.
 *
 * This software may be replicated in part or whole for the licensed use,
 * with the restriction that this Disclaimer and Copyright notice must be
 * included with each copy of this software, whether used in part or whole,
 * at all times.
 *******************************************************************************
 */

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32l110_core.h"
#include "hc32l110_system.h"
/**
 * @addtogroup hc32l110_DDL_Driver
 * @{
 */

/**
 * @defgroup DDL_UTILITY UTILITY
 * @brief DDL Utility Driver
 * @{
 */



/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/


/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

static uint32_t tick_increment_step = 0ul;
__IO static uint32_t current_tick_count = 0ul;



/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/


/**
 * @brief Delay function, delay 1ms approximately
 * @param [in] u32Cnt                   ms
 * @retval None
 */
void ddl_inaccurate_spin_delay(uint32_t approx_milliseconds)
{
    __IO uint32_t i = 0ul;
    uint32_t spin_counter = 0ul;

    spin_counter = core_system_clock_frequency;
    spin_counter = spin_counter / 10000ul;
    while (approx_milliseconds-- > 0ul)
    {
        i = spin_counter;
        while (i-- > 0ul)
        {
            ;
        }
    }
}

/**
 * @brief This function Initializes the interrupt frequency of the SysTick.
 * @param [in] tick_frequency                  SysTick interrupt frequency (1 to 1000).
 * @retval An en_result_t enumeration value:
 *           - Ok: SysTick Initializes succeed
 *           - Error: SysTick Initializes failed
 */
__WEAKDEF en_result_t systick_init(uint32_t tick_frequency)
{
    if ((0ul != tick_frequency) && (tick_frequency <= 1000ul))
    {
        tick_increment_step = 1000ul / tick_frequency;
        /* Configure the SysTick interrupt */
        if (0ul == SysTick_Config(core_system_clock_frequency / tick_frequency))
        {
            return Ok;
        }
    }

    return Error;
}

/**
 * @brief This function provides minimum delay (in milliseconds).
 * @param [in] delay_ticks                 Delay specifies the delay time.
 * @retval None
 */
__WEAKDEF void systick_delay(uint32_t delay_ticks)
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
__WEAKDEF void systick_increment_ticks(void)
{
    current_tick_count += tick_increment_step;
}

/**
 * @brief Provides a tick value in millisecond.
 * @param None
 * @retval Tick value
 */
__WEAKDEF uint32_t systick_get_tick(void)
{
    return current_tick_count;
}

/**
 * @brief Suspend SysTick increment.
 * @param None
 * @retval None
 */
__WEAKDEF void systick_disable(void)
{
    /* Disable SysTick Interrupt */
    SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
}

/**
 * @brief Resume SysTick increment.
 * @param None
 * @retval None
 */
__WEAKDEF void systick_enable(void)
{
    /* Enable SysTick Interrupt */
    SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
}





/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
