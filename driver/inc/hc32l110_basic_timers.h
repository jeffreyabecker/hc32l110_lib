/**
 *******************************************************************************
 * @file  hc32l110_BASIC_TIMERS.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_BASIC_TIMERS_H__
#define __hc32l110_BASIC_TIMERS_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_core.h"
#include "hc32l110_interrupts.h"
typedef enum
{
    Ok                       = 0U,   /*!< No error */
    Error                    = 1U,   /*!< Non-specific error code */
    // ErrorAddressAlignment    = 2U,   /*!< Address alignment does not match */
    // ErrorAccessRights        = 3U,   /*!< Wrong mode (e.g. user/system) mode is set */
    // ErrorInvalidParameter    = 4U,   /*!< Provided parameter is not valid */
    // ErrorOperationInProgress = 5U,   /*!< A conflicting or requested operation is still in progress */
    // ErrorInvalidMode         = 6U,   /*!< Operation not allowed in current mode */
    // ErrorUninitialized       = 7U,   /*!< Module (or part of it) was not initialized properly */
    // ErrorBufferFull          = 8U,   /*!< Circular buffer can not be written because the buffer is full */
    // ErrorTimeout             = 9U,   /*!< Time Out error occurred (e.g. I2C arbitration lost, Flash time-out, etc.) */
    // ErrorNotReady            = 10U,  /*!< A requested final state is not reached */
    // OperationInProgress      = 11U,  /*!< Indicator for operation in progress (e.g. ADC conversion not finished, DMA channel used, etc.) */
} timer_result_t;

typedef enum{
    basic_timer_32_bit_counter = 0,
    basic_timer_16_bit_autoreload = 1
} basic_timer_mode_t;

typedef enum {
    basic_timer_count_pclk = 0,
    basic_timer_count_external = 1,
} basic_timer_count_function_t;
typedef enum{
    lp_timer_source_pclk = 0,
    lp_timer_source_xtl = 2,
    lp_timer_source_rcl = 3
} lp_timer_source_clock_t;

typedef struct{
    uint8_t running :1;
    basic_timer_mode_t mode :1;
    basic_timer_count_function_t counter_function: 1;
    uint8_t toggle_output_enable : 1;
    stc_basic_timer_prescaler_t : 3;
    uint8_t enable_gate:1;
    uint8_t invert_gate:1;
    uint8_t enable_interrupt : 1;
    lp_timer_source_clock_t : 2;
} timer_config_t;

timer_result_t basic_timer_set_config(void* timer);
timer_config_t basic_timer_get_config(void* timer);
timer_result_t basic_timer_set_reload(void* timer, uint16_t reload_value);


__STATIC_INLINE void basic_timer_set_enabled(void* timer, uint8_t enabled){
   if(((uint32_t)timer) == LPTIMER_ADDRESS){
        (((M0P_LPTIMER_TypeDef*)timer)->CR_f).TR = enabled;
    }
    else{
        (((M0P_BasicTimer_TypeDef*)timer)->CR_f).TR = enabled;
    } 
}
__STATIC_INLINE uint8_t basic_timer_get_enabled(void* timer){
   if(((uint32_t)timer) == LPTIMER_ADDRESS){
        return (((M0P_LPTIMER_TypeDef*)timer)->CR_f).TR;
    }
    else{
        return (((M0P_BasicTimer_TypeDef*)timer)->CR_f).TR;
    } 
}
void basic_timer_clear_interrupt(void* timer);
uint8_t basic_timer_get_interrupt(void* timer);


#ifdef __cplusplus
}
#endif

#endif
