#include <stdint.h>
#include "hc32l110_ddl_rtc.h"
void rtc_configure(rtc_configuration_t cfg)
{
    if (rtc_periodic_interrupt_granular == cfg.interrupt_mode)
    {
        HC32_RTC->control.PRDS = 0;
        HC32_RTC->control.PRDX = cfg.interrupt_period.granular;
        HC32_RTC->control.PRDSEL = 1;
    }
    if (rtc_periodic_interrupt_defined == cfg.interrupt_mode)
    {
        HC32_RTC->control.PRDS = 0;
        HC32_RTC->control.PRDX = cfg.interrupt_period.granular;
        HC32_RTC->control.PRDSEL = 0;
    }
    else
    {
        HC32_RTC->control.PRDSEL = 0;
        HC32_RTC->control.PRDS = 0;
    }
    HC32_RTC->control.HZ1OE = cfg.enable_output;
    HC32_RTC->control.HZ1SEL = cfg.output_mode;
    HC32_RTC->control.AMPM = cfg.format;
    HC32_RTC->control.clock_divisor_exponent = cfg.source;
    HC32_RTC->control.alarm_enabled = cfg.enable_alarm;
}
#define __rtc2dec(x) (x.low_digit + (x.high_digit * 10))
uint32_t rtc_now_bcd()
{
    HC32_RTC->control.WAIT = 1;
    uint32_t result = __rtc2dec(HC32_RTC->second) + (__rtc2dec(HC32_RTC->minute) * 100) + (__rtc2dec(HC32_RTC->hour) * 10000) + (__rtc2dec(HC32_RTC->day) * 1000000) + (HC32_RTC->month * 100000000) + (__rtc2dec(HC32_RTC->year) * 10000000000);

    HC32_RTC->control.WAIT = 0;
    return result;
}
uint32_t month_seconds_lookup[12] = {0UL, 2678400UL, 5097600UL, 7776000UL, 10368000UL, 13046400UL, 15638400UL, 18316800UL, 20995200UL, 23587200UL, 26265600UL, 28857600UL};
uint32_t rtc_now_seconds()
{
    HC32_RTC->control.WAIT = 1;
    uint32_t result = __rtc2dec(HC32_RTC->second) + (__rtc2dec(HC32_RTC->minute) * 60) + (__rtc2dec(HC32_RTC->hour) * 3600) + (__rtc2dec(HC32_RTC->day) * 86400) + (month_seconds_lookup[HC32_RTC->month]) + (__rtc2dec(HC32_RTC->year) * 31536000);

    HC32_RTC->control.WAIT = 0;
    return result;
}
static uint8_t LOW_DIGIT(uint8_t x) { return (((((x) / 10U) << 4U) + ((x) % 10U))) % 10; }
static uint8_t HIGH_DIGIT(uint8_t x) { return (((((x) / 10U) << 4U) + ((x) % 10U))) / 10; }

void rtc_time_set(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
    HC32_RTC->control.WAIT = 1;
    HC32_RTC->year.high_digit = HIGH_DIGIT(year);
    HC32_RTC->year.low_digit = LOW_DIGIT(year);
    HC32_RTC->month = month;
    HC32_RTC->day.high_digit = HIGH_DIGIT(day);
    HC32_RTC->day.low_digit = LOW_DIGIT(day);
    HC32_RTC->hour.high_digit = HIGH_DIGIT(hour);
    HC32_RTC->hour.low_digit = LOW_DIGIT(hour);
    HC32_RTC->minute.high_digit = HIGH_DIGIT(minute);
    HC32_RTC->minute.low_digit = LOW_DIGIT(minute);
    HC32_RTC->second.high_digit = HIGH_DIGIT(second);
    HC32_RTC->second.low_digit = LOW_DIGIT(second);
    HC32_RTC->control.WAIT = 0;
}
void rtc_alarm_set(uint8_t hour, uint8_t minute, rtc_day_of_week_t days)
{
    HC32_RTC->alarm_hour.high_digit = HIGH_DIGIT(hour);
    HC32_RTC->alarm_hour.low_digit = LOW_DIGIT(hour);
    HC32_RTC->alarm_minute.high_digit = HIGH_DIGIT(minute);
    HC32_RTC->alarm_minute.low_digit = LOW_DIGIT(minute);
    HC32_RTC->alarm_day_of_week = days;
}