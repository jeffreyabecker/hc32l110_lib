#include "hc32l110_registers.h"
#include "hc32l110_rtc.h"

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
#define LOW_DIGIT(x) (((((x) / 10U) << 4U) + ((x) % 10U))) % 10
#define HIGH_DIGIT(x) (((((x) / 10U) << 4U) + ((x) % 10U))) / 10

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