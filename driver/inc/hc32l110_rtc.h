/**
 *******************************************************************************
 * @file  hc32l110_rtc.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_RTC_H__
#define __hc32l110_RTC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
    typedef enum
    {
        rtc_period_half_second = 1,
        rtc_period_second = 2,
        rtc_period_minute = 3,
        rtc_period_hour = 4,
        rtc_period_day = 5,
        rtc_period_year = 6
    } rtc_period_interval_t;

    typedef enum
    {
        rtc_periodic_interrupt_disabled = 0,
        rtc_periodic_interrupt_defined = 1,
        rtc_periodic_interrupt_granular = 2
    } rtc_periodic_interrupt_mode_t;

    typedef enum
    {
        rtc_format_hours_12 = 0,
        rtc_format_hours_24 = 1,
    } rtc_format_t;

    typedef enum
    {
        rtc_enabled_on = 1,
        rtc_enabled_off = 0,
    } rtc_enabled_t;

    typedef enum
    {
        rtc_output_mode_normal = 0,
        rtc_output_mode_high_precision = 1,
    } rtc_output_mode_t;
    typedef enum
    {
        rtc_source_external_low = 0,
        rtc_source_internal = 1,
        rtc_source_external_4mHz = 4,
        rtc_source_external_8mHz = 5,
        rtc_source_external_16mHz = 6,
        rtc_source_external_32mHz = 7,
    } rtc_source_t;

    typedef struct
    {
        rtc_periodic_interrupt_mode_t interrupt_mode : 2;
        union
        {
            uint16_t granular : 6;
            rtc_period_interval_t defined : 6;
        } interrupt_period;
        uint8_t enable_output : 1;
        rtc_output_mode_t output_mode : 1;
        rtc_format_t format : 1;
        uint8_t enable_alarm : 1;
        rtc_source_t source : 3;

    } rtc_configuration_t;


    void rtc_configure(rtc_configuration_t cfg);
    __INLINE void rtc_set_enabled(rtc_enabled_t enabled)
    {
        M0P_RTC->CR0_f.START = enabled;
    }
    __INLINE void rtc_alarm_interrupt_enable(rtc_enabled_t enabled)
    {
        M0P_RTC->CR1_f.ALMIE = enabled;
    }
    uint32_t rtc_now_bcd();
    uint32_t rtc_now_seconds();

    void rtc_alarm_set(uint8_t hour, uint8_t minute, stc_rtc_almweek_field_t days_of_week);

#ifdef __cplusplus
}
#endif

#endif
