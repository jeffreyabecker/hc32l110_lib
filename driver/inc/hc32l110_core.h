/**
 *******************************************************************************
 * @file  hc32l110_CORE.h
 * @brief This file contains all the functions prototypes of the DDL CORE.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-20       Yangjp          First version
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
#ifndef __hc32l110_CORE_H__
#define __hc32l110_CORE_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/

#include "hc32l110_registers.h"

/**
 * @addtogroup hc32l110_DDL_Driver
 * @{
 */

/**
 * @addtogroup DDL_CORE
 * @{
 */



/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
/**
 * @addtogroup CORE_Global_Functions Core Functions
 * @{
 */

/* Imprecise delay */
void ddl_inaccurate_spin_delay(uint32_t approx_milliseconds);

/* Systick functions */
en_result_t systick_init(uint32_t tick_frequency);
void systick_delay(uint32_t delay_ticks);
void systick_increment_ticks(void);
uint32_t systick_get_tick(void);
void systick_disable(void);
void systick_enable(void);

/* You can add your own assert functions by implement the function DDL_AssertHandler
   definition follow the function DDL_AssertHandler declaration */
#ifdef __DEBUG
    #define DDL_ASSERT(x)                                                      \
    do{                                                                        \
        ((x) ? (void)0 : DDL_AssertHandler((uint8_t *)__FILE__, __LINE__));    \
    }while(0)
    /* Exported function */
    void DDL_AssertHandler(const uint8_t *file, int16_t line);
#else
    #define DDL_ASSERT(x)               ((void)0u)
#endif /* __DEBUG */

#if (DDL_PRINT_ENABLE == DDL_ON)
#include <stdio.h>

en_result_t ddl_uart_init(void);
#endif

/**
 * @}
 */


/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __hc32l110_CORE_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
