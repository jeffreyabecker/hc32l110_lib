/*******************************************************************************
* Copyright (C) 2017, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd ("HDSC").
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
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
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
*/
/******************************************************************************/
/** \\file HC32L110.h
**
** Auto generate.
** Headerfile for HC32L110 series MCU
**
** History:
**
**   - 2017-10-25  1.0  Lux First version
**
******************************************************************************/

#ifndef __HC32L110_H__
#define __HC32L110_H__


/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_common.h"


/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* Defined use Device Driver Library */




#ifndef DDL_ENABLE
  #define DDL_ENABLE 0u
#endif
#ifndef DDL_PRINT_ENABLE
  #define DDL_PRINT_ENABLE 0u
#endif
#ifndef DDL_INTERRUPTS_ENABLE
  #define DDL_INTERRUPTS_ENABLE 0u
#endif
// #ifndef DDL_ADC_ENABLE
//   #define DDL_ADC_ENABLE 0u
// #endif
// #ifndef DDL_CLK_ENABLE
//   #define DDL_CLK_ENABLE 0u
// #endif
// #ifndef DDL_CRC_ENABLE
//   #define DDL_CRC_ENABLE 0u
// #endif
// #ifndef DDL_CTC_ENABLE
//   #define DDL_CTC_ENABLE 0u
// #endif
// #ifndef DDL_EFM_ENABLE
//   #define DDL_EFM_ENABLE 0u
// #endif
// #ifndef DDL_EKEY_ENABLE
//   #define DDL_EKEY_ENABLE 0u
// #endif
// #ifndef DDL_EXINT_NMI_ENABLE
//   #define DDL_EXINT_NMI_ENABLE 0u
// #endif
// #ifndef DDL_GPIO_ENABLE
//   #define DDL_GPIO_ENABLE 0u
// #endif
// #ifndef DDL_I2C_ENABLE
//   #define DDL_I2C_ENABLE 0u
// #endif

// #ifndef DDL_PWC_ENABLE
//   #define DDL_PWC_ENABLE 0u
// #endif
// #ifndef DDL_RMU_ENABLE
//   #define DDL_RMU_ENABLE 0u
// #endif
// #ifndef DDL_RTC_ENABLE
//   #define DDL_RTC_ENABLE 0u
// #endif
// #ifndef DDL_SPI_ENABLE
//   #define DDL_SPI_ENABLE 0u
// #endif
// #ifndef DDL_SWDT_ENABLE
//   #define DDL_SWDT_ENABLE 0u
// #endif
// #ifndef DDL_TIMER0_ENABLE
//   #define DDL_TIMER0_ENABLE 0u
// #endif
// #ifndef DDL_TIMERB_ENABLE
//   #define DDL_TIMERB_ENABLE 0u
// #endif
// #ifndef DDL_USART_ENABLE
//   #define DDL_USART_ENABLE 0u
// #endif


/**
 * @brief Include module's header file
 */
// #if (DDL_ADC_ENABLE == DDL_ON)
//     #include "hc32l110_adc.h"
// #endif /* DDL_ADC_ENABLE */

// #if (DDL_CLK_ENABLE == DDL_ON)
//     #include "hc32l110_clk.h"
// #endif /* DDL_CLK_ENABLE */

// #if (DDL_CRC_ENABLE == DDL_ON)
//     #include "hc32l110_crc.h"
// #endif /* DDL_CRC_ENABLE */

// #if (DDL_CTC_ENABLE == DDL_ON)
//     #include "hc32l110_ctc.h"
// #endif /* DDL_CTC_ENABLE */

// #if (DDL_EFM_ENABLE == DDL_ON)
//     #include "hc32l110_efm.h"
// #endif /* DDL_EFM_ENABLE */

// #if (DDL_GPIO_ENABLE == DDL_ON)
//     #include "hc32l110_gpio.h"
// #endif /* DDL_GPIO_ENABLE */

// #if (DDL_I2C_ENABLE == DDL_ON)
//     #include "hc32l110_i2c.h"
// #endif /* DDL_I2C_ENABLE */

// #if (DDL_ICG_ENABLE == DDL_ON)
//     #include "hc32l110_icg.h"
// #endif /* DDL_ICG_ENABLE */

// #if ((DDL_INTERRUPTS_ENABLE == DDL_ON)  ||                                      \
//     (DDL_EXINT_NMI_ENABLE == DDL_ON)    ||                                      \
//     (DDL_EKEY_ENABLE == DDL_ON))
//     #include "hc32l110_interrupts.h"
// #endif /* DDL_INTERRUPTS_ENABLE || DDL_EXINT_NMI_ENABLE || DDL_EKEY_ENABLE */

// #if (DDL_PWC_ENABLE == DDL_ON)
//     #include "hc32l110_pwc.h"
// #endif /* DDL_PWC_ENABLE */

// #if (DDL_RMU_ENABLE == DDL_ON)
//     #include "hc32l110_rmu.h"
// #endif /* DDL_RMU_ENABLE */

// #if (DDL_RTC_ENABLE == DDL_ON)
//     #include "hc32l110_rtc.h"
// #endif /* DDL_RTC_ENABLE */

// #if (DDL_SPI_ENABLE == DDL_ON)
//     #include "hc32l110_spi.h"
// #endif /* DDL_SPI_ENABLE */

// #if (DDL_SWDT_ENABLE == DDL_ON)
//     #include "hc32l110_swdt.h"
// #endif /* DDL_SWDT_ENABLE */

// #if (DDL_TIMER0_ENABLE == DDL_ON)
//     #include "hc32l110_timer0.h"
// #endif /* DDL_TIMER0_ENABLE */

// #if (DDL_TIMER0_ENABLE == DDL_ON)
//     #include "hc32l110_timer0.h"
// #endif /* DDL_TIMER0_ENABLE */

// #if (DDL_TIMERB_ENABLE == DDL_ON)
//     #include "hc32l110_timerb.h"
// #endif /* DDL_TIMERB_ENABLE */

// #if (DDL_USART_ENABLE == DDL_ON)
//     #include "hc32l110_usart.h"
// #endif /* DDL_USART_ENABLE */

#if (DDL_ENABLE == DDL_ON)
    #include "hc32l110_utility.h"
#endif /* DDL_ENABLE */



/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __HC32L110_H__ */
