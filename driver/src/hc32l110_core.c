/*********************************************************************************
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

void ports_set_function(port_number_t port, uint8_t function){
    switch (port)
    {

        case port_p01: M0P_GPIO->P01_SEL = function; return;
        case port_p02: M0P_GPIO->P02_SEL = function; return;
        case port_p03: M0P_GPIO->P03_SEL = function; return;
        case port_p14: M0P_GPIO->P14_SEL = function; return;
        case port_p15: M0P_GPIO->P15_SEL = function; return;
        case port_p23: M0P_GPIO->P23_SEL = function; return;
        case port_p24: M0P_GPIO->P24_SEL = function; return;
        case port_p25: M0P_GPIO->P25_SEL = function; return;
        case port_p26: M0P_GPIO->P26_SEL = function; return;
        case port_p27: M0P_GPIO->P27_SEL = function; return;
        case port_p31: M0P_GPIO->P31_SEL = function; return;
        case port_p32: M0P_GPIO->P32_SEL = function; return;
        case port_p33: M0P_GPIO->P33_SEL = function; return;
        case port_p34: M0P_GPIO->P34_SEL = function; return;
        case port_p35: M0P_GPIO->P35_SEL = function; return;
        case port_p36: M0P_GPIO->P36_SEL = function; return;
    default:
        break;
    }
}
void ports_configure(port_configuration_t cfg);
uint8_t ports_get_function(port_number_t port){
    switch (port)
    {
        case port_p01: return M0P_GPIO->P01_SEL;
        case port_p02: return M0P_GPIO->P02_SEL;
        case port_p03: return M0P_GPIO->P03_SEL;
        case port_p14: return M0P_GPIO->P14_SEL;
        case port_p15: return M0P_GPIO->P15_SEL;
        case port_p23: return M0P_GPIO->P23_SEL;
        case port_p24: return M0P_GPIO->P24_SEL;
        case port_p25: return M0P_GPIO->P25_SEL;
        case port_p26: return M0P_GPIO->P26_SEL;
        case port_p27: return M0P_GPIO->P27_SEL;
        case port_p31: return M0P_GPIO->P31_SEL;
        case port_p32: return M0P_GPIO->P32_SEL;
        case port_p33: return M0P_GPIO->P33_SEL;
        case port_p34: return M0P_GPIO->P34_SEL;
        case port_p35: return M0P_GPIO->P35_SEL;
        case port_p36: return M0P_GPIO->P36_SEL;
    default:
        return 0;
    }
}

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

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
