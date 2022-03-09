#include "hc32l110_registers.h"
#include "hc32l110_rtc.h"
__INLINE uint8_t __rtc_decode_bcd(uint32_t bcd_value, uint8_t low_bits, uint8_t high_bits)
{
    return ((bcd_value & ((0xFFFFFFFF >> (32 - high_bits)) << low_bits)) >> low_bits) + (bcd_value & (0xFFFFFFFF >> (32 - high_bits)));
}

void rtc_configure(rtc_configuration_t cfg)
{
    if (rtc_periodic_interrupt_granular == cfg.interrupt_mode)
    {
        M0P_RTC->CR0_f.PRDS = 0;
        M0P_RTC->CR0_f.PRDX = cfg.interrupt_period.granular;
        M0P_RTC->CR0_f.PRDSEL = 1;
    }
    if (rtc_periodic_interrupt_defined == cfg.interrupt_mode)
    {
        M0P_RTC->CR0_f.PRDS = 0;
        M0P_RTC->CR0_f.PRDX = cfg.interrupt_period.granular;
        M0P_RTC->CR0_f.PRDSEL = 0;
    }
    else
    {
        M0P_RTC->CR0_f.PRDSEL = 0;
        M0P_RTC->CR0_f.PRDS = 0;
    }
    M0P_RTC->CR0_f.HZ1OE = cfg.enable_output;
    M0P_RTC->CR0_f.HZ1SEL = cfg.output_mode;
    M0P_RTC->CR0_f.AMPM = cfg.format;
    M0P_RTC->CR1_f.CKSEL = cfg.source;
    M0P_RTC->CR1_f.ALMEN = cfg.enable_alarm;
}
uint32_t rtc_now_bcd()
{
    return 0 + (M0P_RTC->SEC_f.SECL * 1) + (M0P_RTC->SEC_f.SECH * 10) + (M0P_RTC->MIN_f.MINL * 100) + (M0P_RTC->MIN_f.MINH * 1000) + (M0P_RTC->HOUR_f.HOURL * 10000) + (M0P_RTC->HOUR_f.HOURH * 100000) + (M0P_RTC->DAY_f.DAYL * 1000000) + (M0P_RTC->DAY_f.DAYH * 10000000) + (M0P_RTC->MON_f.MON * 1000000000) + (M0P_RTC->YEAR_f.YEARL * 10000000000) + (M0P_RTC->YEAR_f.YEARH * 100000000000);
}
uint32_t month_seconds_lookup[12] = {0UL, 2678400UL, 5097600UL, 7776000UL, 10368000UL, 13046400UL, 15638400UL, 18316800UL, 20995200UL, 23587200UL, 26265600UL, 28857600UL};
uint32_t rtc_now_seconds()
{
    return 0 + (M0P_RTC->SEC_f.SECL * 1) + (M0P_RTC->SEC_f.SECH * 10) + (M0P_RTC->MIN_f.MINL * 60) + (M0P_RTC->MIN_f.MINH * 600) + (M0P_RTC->HOUR_f.HOURL * 3600) + (M0P_RTC->HOUR_f.HOURH * 36000) + (M0P_RTC->DAY_f.DAYL * 86400) + (M0P_RTC->DAY_f.DAYH * 864000) + month_seconds_lookup[M0P_RTC->MON_f.MON] + (M0P_RTC->YEAR_f.YEARL * 31536000) + (M0P_RTC->YEAR_f.YEARH * 315360000);
}

void rtc_alarm_set(uint8_t hour, uint8_t minute, stc_rtc_almweek_field_t days)
{
    M0P_RTC->ALMHOUR_f.ALMHOURH = DEC2BCD(hour) / 10;
    M0P_RTC->ALMHOUR_f.ALMHOURL = DEC2BCD(hour) % 10;
    M0P_RTC->ALMMIN_f.ALMMINH = DEC2BCD(minute) / 10;
    M0P_RTC->ALMMIN_f.ALMMINL = DEC2BCD(minute) % 10;
    M0P_RTC->ALMWEEK_f = days;
}