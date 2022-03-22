#ifndef __HC32L110_REGISTERS_PORTS_H__
#define __HC32L110_REGISTERS_PORTS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#if defined(__CC_ARM)
#pragma anon_unions
#endif
#include <stdint.h>
#include "hc32l110_registers_platform.h"
  typedef enum
  {
    port_p01_gpio = 0,
    port_p01_uart0_rxd = 1,
    port_p01_i2c_sda = 2,
    port_p01_uart1_txd = 3,
    port_p01_tim0_tog = 4,
    port_p01_tim5_chb = 5,
    port_p01_spi_sck = 6,
    port_p01_tim2_ext = 7,
  } stc_port_01_function_t;

  typedef enum
  {
    port_p02_gpio = 0,
    port_p02_uart0_txd = 1,
    port_p02_i2c_scl = 2,
    port_p02_uart1_rxd = 3,
    port_p02_tim0_togn = 4,
    port_p02_tim6_cha = 5,
    port_p02_spi_cs = 6,
    port_p02_tim2_gate = 7,
  } stc_port_02_function_t;

  typedef enum
  {
    port_p03_gpio = 0,
    port_p03_pca_ch3 = 1,
    port_p03_spi_cs = 2,
    port_p03_tim6_chb = 3,
    port_p03_lptim_ext = 4,
    port_p03_rtc_1hz = 5,
    port_p03_pca_eci = 6,
    port_p03_vc0_out = 7,
  } stc_port_03_function_t;

  typedef enum
  {
    port_p14_gpio = 0,
    port_p14_i2c_scl = 1,
    port_p14_tim2_togn = 2,
    port_p14_pca_eci = 3,
    port_p14_adc_rdy = 4,
    port_p14_spi_cs = 5,
    port_p14_uart0_txd = 6,
    port_p14_unused = 7,
  } stc_port_14_function_t;

  typedef enum
  {
    port_p15_gpio = 0,
    port_p15_i2c_sda = 1,
    port_p15_tim2_tog = 2,
    port_p15_tim4_chb = 3,
    port_p15_lptimer_gate = 4,
    port_p15_spi_sck = 5,
    port_p15_uart0_rxd = 6,
    port_p15_lvd_out = 7,
  } stc_port_15_function_t;

  typedef enum
  {
    port_p23_gpio = 0,
    port_p23_tim6_cha = 1,
    port_p23_tim4_chb = 2,
    port_p23_tim4_cha = 3,
    port_p23_pca_ch0 = 4,
    port_p23_spi_cipo = 5,
    port_p23_uart1_txd = 6,
    port_p23_ir_out = 7,
  } stc_port_23_function_t;

  typedef enum
  {
    port_p24_gpio = 0,
    port_p24_tim4_chb = 1,
    port_p24_tim5_chb = 2,
    port_p24_hclk_out = 3,
    port_p24_pca_ch1 = 4,
    port_p24_spi_copi = 5,
    port_p24_uart1_rxd = 6,
    port_p24_vc1_out = 7,
  } stc_port_24_function_t;

  typedef enum
  {
    port_p25_gpio = 0,
    port_p25_spi_sck = 1,
    port_p25_pca_ch0 = 2,
    port_p25_tim5_cha = 3,
    port_p25_lvd_out = 4,
    port_p25_luuart_rxd = 5,
    port_p25_i2c_sda = 6,
    port_p25_tim1_gate = 7,
  } stc_port_25_function_t;

  typedef enum
  {
    port_p26_gpio = 0,
    port_p26_spi_copi = 1,
    port_p26_tim4_cha = 2,
    port_p26_tim4_chb = 3,
    port_p26_pca_ch2 = 4,
    port_p26_lpuart_txd = 5,
    port_p26_i2c_scl = 6,
    port_p26_tim1_ext = 7,
  } stc_port_26_function_t;

  typedef enum
  {
    port_p27_gpio = 0,
    port_p27_spi_cipo = 1,
    port_p27_tim5_cha = 2,
    port_p27_tim6_cha = 3,
    port_p27_pca_ch3 = 4,
    port_p27_uart0_rxd = 5,
    port_p27_rch_out = 6,
    port_p27_xth_out = 7,
  } stc_port_27_function_t;

  typedef enum
  {
    port_p31_gpio = 0,
    port_p31_lptim_tog = 1,
    port_p31_pca_eci = 2,
    port_p31_pclk_out = 3,
    port_p31_vc0_out = 4,
    port_p31_uart0_txd = 5,
    port_p31_rcl_out = 6,
    port_p31_hclk_out = 7,
  } stc_port_31_function_t;

  typedef enum
  {
    port_p32_gpio = 0,
    port_p32_lptim_togn = 1,
    port_p32_pca_ch2 = 2,
    port_p32_tim6_chb = 3,
    port_p32_vc1_out = 4,
    port_p32_uart1_txd = 5,
    port_p32_hca_ch4 = 6,
    port_p32_rtc_1hz = 7,
  } stc_port_32_function_t;

  typedef enum
  {
    port_p33_gpio = 0,
    port_p33_lpuart_rxd = 1,
    port_p33_pca_ch1 = 2,
    port_p33_tim5_chb = 3,
    port_p33_pca_eci = 4,
    port_p33_uart1_rxd = 5,
    port_p33_xtl_out = 6,
    port_p33_tim1_togn = 7,
  } stc_port_33_function_t;

  typedef enum
  {
    port_p34_gpio = 0,
    port_p34_pca_ch0 = 1,
    port_p34_lpuart_txd = 2,
    port_p34_tim5_cha = 3,
    port_p34_tim0_ext = 4,
    port_p34_tim4_cha = 5,
    port_p34_rtc_1hz = 6,
    port_p34_tim1_tog = 7,
  } stc_port_34_function_t;

  typedef enum
  {
    port_p35_gpio = 0,
    port_p35_uart1_txd = 1,
    port_p35_tim6_chb = 2,
    port_p35_uart0_txd = 3,
    port_p35_tim0_gate = 4,
    port_p35_tim4_chb = 5,
    port_p35_spi_cipo = 6,
    port_p35_i2c_sda = 7,
  } stc_port_35_function_t;

  typedef enum
  {
    port_p36_gpio = 0,
    port_p36_uart1_rxd = 1,
    port_p36_tim6_cha = 2,
    port_p36_uart0_rxd = 3,
    port_p36_pca_ch4 = 4,
    port_p36_tim5_cha = 5,
    port_p36_spi_copi = 6,
    port_p36_i2c_scl = 7,
  } stc_port_36_function_t;

  typedef enum
  {
    gpio_output = 0,
    gpio_input = 1
  } gpio_direction_t;
  typedef enum
  {
    gpio_digital = 0,
    gpio_analog = 1
  } gpio_analog_digital_t;
  typedef enum
  {
    gpio_drive_high = 0,
    gpio_drive_low = 1
  } gpio_drive_capability_t;
  typedef enum
  {
    gpio_pullup_disable = 0,
    gpio_pullup_enable = 1
  } gpio_internal_pullup_t;

  typedef enum
  {
    gpio_pulldown_disable = 0,
    gpio_pulldown_enable = 1
  } gpio_internal_pulldown_t;
  typedef enum
  {
    gpio_mode_push_pull = 0,
    gpio_open_drain = 1
  } gpio_mode_t;
  typedef enum
  {
    gpio_interrupt_high_disable = 0,
    gpio_interrupt_high_enable = 1,
  } gpio_interrupt_high_t;
  typedef enum
  {
    gpio_interrupt_low_disable = 0,
    gpio_interrupt_low_enable = 1,
  } gpio_interrupt_low_t;

  typedef enum
  {
    gpio_interrupt_rising_disable = 0,
    gpio_interrupt_rising_enable = 1,
  } gpio_interrupt_rising_t;

  typedef enum
  {
    gpio_interrupt_falling_disable = 0,
    gpio_interrupt_falling_enable = 1,
  } gpio_interrupt_falling_t;

  typedef struct
  {
    volatile uint32_t IESEL : 1;
  } stc_gpio_ctrl0_field_t;

  typedef struct
  {
    volatile uint32_t EXT_CLK_SEL : 4;
    volatile uint32_t SSN_SEL : 4;
    volatile uint32_t PCLK_SEL : 2;
    volatile uint32_t HCLK_SEL : 2;
    volatile uint32_t PCLK_EN : 1;
    volatile uint32_t HCLK_EN : 1;
    volatile uint32_t IR_POL : 1;
  } stc_gpio_ctrl1_field_t;

  typedef struct
  {
    volatile uint32_t PCA_CAP0_SEL : 2;
    volatile uint32_t PCA_CAP1_SEL : 2;
    volatile uint32_t PCA_CAP2_SEL : 2;
    volatile uint32_t PCA_CAP3_SEL : 2;
    volatile uint32_t PCA_CAP4_SEL : 2;
  } stc_gpio_ctrl2_field_t;

  typedef struct
  {
    volatile uint32_t TM4_B_SEL : 2;
    volatile uint32_t TM5_B_SEL : 2;
    volatile uint32_t TM6_B_SEL : 2;
    volatile uint32_t TM4_A_SEL : 2;
    volatile uint32_t TM5_A_SEL : 2;
    volatile uint32_t TM6_A_SEL : 2;
  } stc_gpio_ctrl3_field_t;

  typedef struct
  {
    volatile uint32_t TM0_GATE_SEL : 2;
    volatile uint32_t TM1_GATE_SEL : 2;
    volatile uint32_t TM2_GATE_SEL : 2;
    volatile uint32_t TM3_GATE_SEL : 2;
  } stc_gpio_ctrl4_field_t;

  typedef struct
  {
    volatile uint32_t DIR;
    volatile uint32_t IN;
    volatile uint32_t OUT;
    volatile uint32_t ADS;
    uint8_t RESERVED20[12];
    volatile uint32_t DR;
    volatile uint32_t PU;
    volatile uint32_t PD;
    uint8_t RESERVED23[4];
    volatile uint32_t OD;
    volatile uint32_t HIE;
    volatile uint32_t LIE;
    volatile uint32_t RIE;
    volatile uint32_t FIE;
  } port_ctl_t;

  typedef struct
  {
    volatile uint32_t STAT;
    uint8_t RESERVED0[12];
    volatile uint32_t ICLR;
    uint8_t RESERVED1[44];
  } port_interrupt_t;

  typedef struct
  {
    //0x40020C00
    uint32_t RESERVED0[4];
    //0x40020C04
    volatile uint32_t P01_SEL;
    volatile uint32_t P02_SEL;
    volatile uint32_t P03_SEL;
    uint8_t RESERVED3[64];
    //0x40020C50
    volatile uint32_t P14_SEL;
    volatile uint32_t P15_SEL;
    uint8_t RESERVED5[52];
    //0x40020C8C
    volatile uint32_t P23_SEL;
    volatile uint32_t P24_SEL;
    volatile uint32_t P25_SEL;
    volatile uint32_t P26_SEL;
    volatile uint32_t P27_SEL;
    uint8_t RESERVED10[36];
    //0x40020CC4
    volatile uint32_t P31_SEL;
    volatile uint32_t P32_SEL;
    volatile uint32_t P33_SEL;
    volatile uint32_t P34_SEL;
    volatile uint32_t P35_SEL;
    volatile uint32_t P36_SEL;
    uint8_t RESERVED16[36];
    //0x40020CD0
    port_ctl_t PORT0;
    //0x40020D10
    port_ctl_t PORT1;
    //0x40020D50
    port_ctl_t PORT2;
    //0x40020D90
    port_ctl_t PORT3;
    //0x40020DD0
    port_interrupt_t INTERRUPT_P0;
    //0x40020E10
    port_interrupt_t INTERRUPT_P1;
    //0x40020E50
    port_interrupt_t INTERRUPT_P2;
    //0x40020E90
    port_interrupt_t INTERRUPT_P3;

    stc_gpio_ctrl0_field_t CTRL0;
    stc_gpio_ctrl1_field_t CTRL1;
    stc_gpio_ctrl2_field_t CTRL2;
    stc_gpio_ctrl3_field_t CTRL3;
    stc_gpio_ctrl4_field_t CTRL4;
  } M0P_GPIO_TypeDef;

#define M0P_GPIO ((M0P_GPIO_TypeDef *)0x40020C00UL)
#ifdef __cplusplus
}
#endif

#endif