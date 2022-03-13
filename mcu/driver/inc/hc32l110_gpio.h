/**
 *******************************************************************************
 * @file  hc32l110_GPIO.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_GPIO_H__
#define __hc32l110_GPIO_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"
#include "hc32l110_ports.h"

    uint8_t gpio_digital_read(port_number_t port);
    void gpio_digital_write(port_number_t port, uint8_t value);

    typedef struct
    {
        gpio_direction_t direction : 1;
        gpio_analog_digital_t resolution : 1;
        gpio_drive_capability_t drive_mode : 1;
        gpio_internal_pullup_t pull_up : 1;
        gpio_internal_pulldown_t pull_down : 1;
        gpio_mode_t gpio_mode : 1;
        gpio_interrupt_high_t interrupt_high : 1;
        gpio_interrupt_low_t interrupt_low : 1;
        gpio_interrupt_rising_t interrupt_rising : 1;
        gpio_interrupt_falling_t interrupt_falling : 1;
        uint8_t function : 3;
    } gpio_port_config_t;
   
    void gpio_set_config(port_number_t port, gpio_port_config_t cfg);
    gpio_port_config_t gpio_get_config(port_number_t port);
#ifdef __cplusplus
}
#endif

#endif
//   typedef struct
//   {
//     uint8_t RESERVED0[4];

//     __IO uint32_t P01_SEL;
//     __IO uint32_t P02_SEL;
//     __IO uint32_t P03_SEL;
//     uint8_t RESERVED3[64];
//     __IO uint32_t P14_SEL;
//     __IO uint32_t P15_SEL;
//     uint8_t RESERVED5[52];
//     __IO uint32_t P23_SEL;
//     __IO uint32_t P24_SEL;
//     __IO uint32_t P25_SEL;
//     __IO uint32_t P26_SEL;
//     __IO uint32_t P27_SEL;
//     uint8_t RESERVED10[36];
//     __IO uint32_t P31_SEL;
//     __IO uint32_t P32_SEL;
//     __IO uint32_t P33_SEL;
//     __IO uint32_t P34_SEL;
//     __IO uint32_t P35_SEL;
//     __IO uint32_t P36_SEL;
//     uint8_t RESERVED16[36];
//     stc_gpio_p0dir_field_t P0DIR;
//     stc_gpio_p0in_field_t P0IN;
//     stc_gpio_p0out_field_t P0OUT;
//     stc_gpio_p0ads_field_t P0ADS;
//     uint8_t RESERVED20[12];
//     stc_gpio_p0dr_field_t P0DR;
//     stc_gpio_p0pu_field_t P0PU;
//     stc_gpio_p0pd_field_t P0PD;
//     uint8_t RESERVED23[4];
//     stc_gpio_p0od_field_t P0OD;
//     stc_gpio_p0hie_field_t P0HIE;
//     stc_gpio_p0lie_field_t P0LIE;
//     stc_gpio_p0rie_field_t P0RIE;
//     stc_gpio_p0fie_field_t P0FIE;
//     stc_gpio_p1dir_field_t P1DIR;
//     stc_gpio_p1in_field_t P1IN;
//     stc_gpio_p1out_field_t P1OUT;
//     stc_gpio_p1ads_field_t P1ADS;
//     uint8_t RESERVED32[12];
//     stc_gpio_p1dr_field_t P1DR;
//     stc_gpio_p1pu_field_t P1PU;
//     stc_gpio_p1pd_field_t P1PD;
//     uint8_t RESERVED35[4];
//     stc_gpio_p1od_field_t P1OD;
//     stc_gpio_p1hie_field_t P1HIE;
//     stc_gpio_p1lie_field_t P1LIE;
//     stc_gpio_p1rie_field_t P1RIE;
//     stc_gpio_p1fie_field_t P1FIE;
//     stc_gpio_p2dir_field_t P2DIR;
//     stc_gpio_p2in_field_t P2IN;
//     stc_gpio_p2out_field_t P2OUT;
//     stc_gpio_p2ads_field_t P2ADS;
//     uint8_t RESERVED44[12];
//     stc_gpio_p2dr_field_t P2DR;
//     stc_gpio_p2pu_field_t P2PU;
//     stc_gpio_p2pd_field_t P2PD;
//     uint8_t RESERVED47[4];
//     stc_gpio_p2od_field_t P2OD;
//     stc_gpio_p2hie_field_t P2HIE;
//     stc_gpio_p2lie_field_t P2LIE;
//     stc_gpio_p2rie_field_t P2RIE;
//     stc_gpio_p2fie_field_t P2FIE;
//     stc_gpio_p3dir_field_t P3DIR;
//     stc_gpio_p3in_field_t P3IN;
//     stc_gpio_p3out_field_t P3OUT;
//     stc_gpio_p3ads_field_t P3ADS;
//     uint8_t RESERVED56[12];
//     stc_gpio_p3dr_field_t P3DR;
//     stc_gpio_p3pu_field_t P3PU;
//     stc_gpio_p3pd_field_t P3PD;
//     uint8_t RESERVED59[4];
//     stc_gpio_p3od_field_t P3OD;
//     stc_gpio_p3hie_field_t P3HIE;
//     stc_gpio_p3lie_field_t P3LIE;
//     stc_gpio_p3rie_field_t P3RIE;
//     stc_gpio_p3fie_field_t P3FIE;
//     stc_gpio_p0stat_field_t P0STAT;
//     uint8_t RESERVED65[12];
//     stc_gpio_p0iclr_field_t P0ICLR;
//     uint8_t RESERVED66[44];
//     stc_gpio_p1stat_field_t P1STAT;
//     uint8_t RESERVED67[12];
//     stc_gpio_p1iclr_field_t P1ICLR;
//     uint8_t RESERVED68[44];
//     stc_gpio_p2stat_field_t P2STAT;
//     uint8_t RESERVED69[12];
//     stc_gpio_p2iclr_field_t P2ICLR;
//     uint8_t RESERVED70[44];
//     stc_gpio_p3stat_field_t P3STAT;
//     uint8_t RESERVED71[12];
//     stc_gpio_p3iclr_field_t P3ICLR;
//     uint8_t RESERVED72[44];
//     stc_gpio_ctrl0_field_t CTRL0;
//     stc_gpio_ctrl1_field_t CTRL1;
//     stc_gpio_ctrl2_field_t CTRL2;
//     stc_gpio_ctrl3_field_t CTRL3;
//     stc_gpio_ctrl4_field_t CTRL4;
//   } M0P_GPIO_TypeDef;