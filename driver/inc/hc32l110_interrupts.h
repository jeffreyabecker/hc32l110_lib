/**
 *******************************************************************************
 * @file  hc32l110_interrupts.h
 * @brief This file contains all the functions prototypes of the interrupt vector drivers

 *******************************************************************************
Copyright 2022 Jeffrey Becker

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.
 *******************************************************************************
 */
#ifndef __hc32l110_INTERRUPTS_H__
#define __hc32l110_INTERRUPTS_H__

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
 * @addtogroup DDL_INTERRUPTS
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
 * @addtogroup INTERRUPTS_Global_Functions INTERRUPTS Functions
 * @{
 */
typedef enum 
{
    non_maskable_interrupt              = 0,
    hard_fault                          = 1, 
    sv_call                             = 2, 
    pend_sv                             = 3, 
    systick                             = 4, 
    port_0                              = 5 ,
    port_1                              = 6 ,
    port_2                              = 7 ,
    port_3                              = 8 ,
    uart_0                              = 9 ,
    uart_1                              = 10 ,
    low_power_uart                      = 11,
    spi                                 = 12,
    i2c                                 = 13,
    timer_0                             = 14,
    timer_1                             = 15,
    timer_2                             = 16,
    low_power_timer                     = 17,
    timer_4                             = 18,
    timer_5                             = 19,
    timer_6                             = 20,
    pca                                 = 21,
    watchdog_timer                      = 22,
    realtime_clock                      = 23,
    analog_digital_converter            = 24,
    vc_0                                = 26,
    vc_1                                = 27,
    lvd                                 = 28,
    flash_ram                           = 30,
    clock_trim                          = 31,
    ram_control                         = 32
} nivc_irq_number_t;

typedef void (*nvic_interrupt_handler_t)(nivc_irq_number_t irq_number, void* data);
typedef struct{
    nivc_irq_number_t irq_number;
    uint8_t priority;
    nvic_interrupt_handler_t handler;
    void* data;
} nvic_interrupt_cfg_t;

en_result_t nvic_interrupt_cfg(nvic_interrupt_cfg_t cfg);
en_result_t nvic_interrupt_set_enabled(nivc_irq_number_t irq_number, uint8_t enabled);
en_result_t nvic_interrupt_set_priority(nivc_irq_number_t irq_number, uint8_t priority);


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

#endif /* __hc32l110_INTERRUPTS_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
