/**
 *******************************************************************************
 * @file  hc32l110_rtc.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_RTC_H__
#define __hc32l110_RTC_H__
#if defined(DDL_USE_ALL) || ( defined(DDL_USE_CORE) && defined(DDL_USE_RTC))
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
        M0P_RTC->control.START = enabled;
    }
    __INLINE void rtc_alarm_interrupt_enable(rtc_enabled_t enabled)
    {
        M0P_RTC->control.alarm_interrupt_enabled = enabled;
    }
    uint32_t rtc_now_bcd();
    uint32_t rtc_now_seconds();

    void rtc_alarm_set(uint8_t hour, uint8_t minute, stc_rtc_almweek_field_t days_of_week);
    void rtc_time_set(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);
    void rtc_configure(rtc_configuration_t cfg)
    {
        if (rtc_periodic_interrupt_granular == cfg.interrupt_mode)
        {
            M0P_RTC->control.PRDS = 0;
            M0P_RTC->control.PRDX = cfg.interrupt_period.granular;
            M0P_RTC->control.PRDSEL = 1;
        }
        if (rtc_periodic_interrupt_defined == cfg.interrupt_mode)
        {
            M0P_RTC->control.PRDS = 0;
            M0P_RTC->control.PRDX = cfg.interrupt_period.granular;
            M0P_RTC->control.PRDSEL = 0;
        }
        else
        {
            M0P_RTC->control.PRDSEL = 0;
            M0P_RTC->control.PRDS = 0;
        }
        M0P_RTC->control.HZ1OE = cfg.enable_output;
        M0P_RTC->control.HZ1SEL = cfg.output_mode;
        M0P_RTC->control.AMPM = cfg.format;
        M0P_RTC->control.clock_divisor_exponent = cfg.source;
        M0P_RTC->control.alarm_enabled = cfg.enable_alarm;
    }
#define __rtc2dec(x) (x.low_digit + (x.high_digit * 10))
    uint32_t rtc_now_bcd()
    {
        M0P_RTC->control.WAIT = 1;
        uint32_t result = __rtc2dec(M0P_RTC->second) + (__rtc2dec(M0P_RTC->minute) * 100) + (__rtc2dec(M0P_RTC->hour) * 10000) + (__rtc2dec(M0P_RTC->day) * 1000000) + (M0P_RTC->month * 100000000) + (__rtc2dec(M0P_RTC->year) * 10000000000);

        M0P_RTC->control.WAIT = 0;
        return result;
    }
    uint32_t month_seconds_lookup[12] = {0UL, 2678400UL, 5097600UL, 7776000UL, 10368000UL, 13046400UL, 15638400UL, 18316800UL, 20995200UL, 23587200UL, 26265600UL, 28857600UL};
    uint32_t rtc_now_seconds()
    {
        M0P_RTC->control.WAIT = 1;
        uint32_t result = __rtc2dec(M0P_RTC->second) + (__rtc2dec(M0P_RTC->minute) * 60) + (__rtc2dec(M0P_RTC->hour) * 3600) + (__rtc2dec(M0P_RTC->day) * 86400) + (month_seconds_lookup[M0P_RTC->month]) + (__rtc2dec(M0P_RTC->year) * 31536000);

        M0P_RTC->control.WAIT = 0;
        return result;
    }
    __STATIC_FORCEINLINE uint8_t LOW_DIGIT(uint8_t x){ return (((((x) / 10U) << 4U) + ((x) % 10U))) % 10; }
    __STATIC_FORCEINLINE uint8_t HIGH_DIGIT(uint8_t x){ return (((((x) / 10U) << 4U) + ((x) % 10U))) / 10; }

    void rtc_time_set(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
    {
        M0P_RTC->control.WAIT = 1;
        M0P_RTC->year.high_digit = HIGH_DIGIT(year);
        M0P_RTC->year.low_digit = LOW_DIGIT(year);
        M0P_RTC->month = month;
        M0P_RTC->day.high_digit = HIGH_DIGIT(day);
        M0P_RTC->day.low_digit = LOW_DIGIT(day);
        M0P_RTC->hour.high_digit = HIGH_DIGIT(hour);
        M0P_RTC->hour.low_digit = LOW_DIGIT(hour);
        M0P_RTC->minute.high_digit = HIGH_DIGIT(minute);
        M0P_RTC->minute.low_digit = LOW_DIGIT(minute);
        M0P_RTC->second.high_digit = HIGH_DIGIT(second);
        M0P_RTC->second.low_digit = LOW_DIGIT(second);
        M0P_RTC->control.WAIT = 0;
    }
    void rtc_alarm_set(uint8_t hour, uint8_t minute, stc_rtc_almweek_field_t days)
    {

        M0P_RTC->alarm_hour.high_digit = HIGH_DIGIT(hour);
        M0P_RTC->alarm_hour.low_digit = LOW_DIGIT(hour);
        M0P_RTC->alarm_minute.high_digit = HIGH_DIGIT(minute);
        M0P_RTC->alarm_minute.low_digit = LOW_DIGIT(minute);
        M0P_RTC->alarm_day_of_week = days;
    }
#ifdef __cplusplus
}
#endif

#endif
#endif