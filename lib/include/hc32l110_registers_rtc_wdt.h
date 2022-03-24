#ifndef __HC32L110_REGISTERS_RTC_WDT_H__
#define __HC32L110_REGISTERS_RTC_WDT_H__

#include <stdint.h>

typedef struct
{
    volatile uint32_t PRDS : 3;
    volatile uint32_t AMPM : 1;
    uint32_t RESERVED1 : 1;
    volatile uint32_t HZ1OE : 1;
    volatile uint32_t HZ1SEL : 1;
    volatile uint32_t START : 1;
    volatile uint32_t PRDX : 6;
    volatile uint32_t PRDSEL : 1;
    uint32_t RESERVED2 : 17;
    volatile uint32_t WAIT : 1;
    volatile uint32_t WAITF : 1;
    uint32_t RESERVED3 : 1;
    volatile uint32_t PRDF : 1;
    volatile uint32_t ALMF : 1;
    uint32_t RESERVED4 : 1;
    volatile uint32_t alarm_interrupt_enabled : 1;
    volatile uint32_t alarm_enabled : 1;
    volatile uint32_t clock_divisor_exponent : 3;
    uint32_t RESERVED5 : 21;
} rtc_cr_field_t;

typedef struct
{
    volatile uint32_t low_digit : 4;
    volatile uint32_t high_digit : 3;
} rtc_4_3_field_t;

typedef struct
{
    volatile uint32_t low_digit : 4;
    volatile uint32_t high_digit : 2;
} rtc_4_2_field_t;

typedef struct
{
    volatile uint32_t low_digit : 4;
    volatile uint32_t high_digit : 4;
} rtc_year_field_t;

typedef enum
{
    sunday = 1,
    monday = 2,
    tuesday = 4,
    wednesday = 8,
    thursday = 16,
    friday = 32,
    saturday = 64
} rtc_day_of_week_t;

typedef struct
{
    volatile uint32_t CR : 9;
    uint32_t RESERVED9 : 6;
    volatile uint32_t EN : 1;
} rtc_compen_field_t;

typedef struct
{
    rtc_cr_field_t control;
    rtc_4_3_field_t second;
    rtc_4_3_field_t minute;
    rtc_4_2_field_t hour;
    volatile uint32_t week;
    rtc_4_2_field_t day;
    volatile uint32_t month;
    rtc_year_field_t year;
    rtc_4_3_field_t alarm_minute;
    rtc_4_2_field_t alarm_hour;
    rtc_day_of_week_t alarm_day_of_week;
} HC32_RTC_TypeDef;

typedef struct
{
    volatile uint32_t WOV : 4;
    volatile uint32_t WDTR : 1;
    volatile uint32_t WINT_EN : 1;
    uint32_t RESERVED6 : 1;
    volatile uint32_t WDINT : 1;
    volatile uint32_t WCNTL : 8;
} wdt_con_field_t;

typedef struct
{
    uint8_t RESERVED0[128];
    volatile uint32_t RST;
    wdt_con_field_t CON;
} HC32_WDT_TypeDef;

typedef struct
{
    uint8_t RESERVED0[4];
    volatile uint32_t RESULT;
    uint8_t RESERVED1[120];
    union
    {
        volatile uint32_t DATA32;
        volatile uint16_t DATA16;
        volatile uint8_t DATA8;
    };
} HC32_CRC_TypeDef;

#define HC32_CRC ((HC32_CRC_TypeDef *)0x40020900UL)
#define HC32_RTC ((HC32_RTC_TypeDef *)0x40001400UL)
#define HC32_WDT ((HC32_WDT_TypeDef *)0x40000C00UL)

#endif
