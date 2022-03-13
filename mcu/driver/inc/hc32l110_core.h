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



/* Systick functions */
uint8_t systick_init(uint32_t tick_frequency);
void systick_delay(uint32_t delay_ticks);
void systick_increment_ticks(void);
uint32_t systick_get_tick(void);
void systick_disable(void);
void systick_enable(void);
typedef enum
{
    port_p01 = 1,
    port_p02 = 2,
    port_p03 = 3,
    port_p14 = 14,
    port_p15 = 15,
    port_p23 = 23,
    port_p24 = 24,
    port_p25 = 25,
    port_p26 = 26,
    port_p27 = 27,

    port_p31 = 31,
    port_p32 = 32,
    port_p33 = 33,
    port_p34 = 34,
    port_p35 = 35,
    port_p36 = 36,
} port_number_t;


void ports_set_function(port_number_t port, uint8_t function);
typedef struct
{
    uint8_t p01 :3;
    uint8_t p02 :3;
    uint8_t p03 :3;
    uint8_t p14 :3;
    uint8_t p15 :3;
    uint8_t p23 :3;
    uint8_t p24 :3;
    uint8_t p25 :3;
    uint8_t p26 :3;
    uint8_t p27 :3;

    uint8_t p31 :3;
    uint8_t p32 :3;
    uint8_t p33 :3;
    uint8_t p34 :3;
    uint8_t p35 :3;
    uint8_t p36 :3;
} port_configuration_t;
void ports_configure(port_configuration_t cfg);
uint8_t ports_get_function(port_number_t port);



#ifdef __cplusplus
}
#endif

#endif /* __hc32l110_CORE_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
