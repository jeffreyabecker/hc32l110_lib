#ifndef __SYSTEM_HC32L110_DDL_PCA_H__
#define __SYSTEM_HC32L110_DDL_PCA_H__
#include "hc32l110_cmsis.h"
#include "hc32l110_system.h"
#include "hc32l110_registers_pca.h"

typedef enum
{
    pca_module_0 = 0,
    pca_module_1 = 1,
    pca_module_2 = 2,
    pca_module_3 = 3,
    pca_module_4 = 4,
} pca_module_t;

typedef enum
{
    pca_module_mode_compare = 0,
    pca_module_mode_pwm = 1,
} pca_module_mode_t;
typedef struct
{
    pca_module_t module : 3;
    pca_module_mode_t mode : 1;
    union
    {
        struct
        {
            uint8_t enable_interrupt : 1;
            uint8_t enable_output_toggle : 1;
            uint8_t capture_rising_edge : 1;
            uint8_t capture_falling_edge : 1;
            uint16_t value
        } compare;
        struct
        {
            uint16_t duty_cycle_percent;
        } pwm;
    } settings;

} pca_module_config_t;
typedef enum
{
    pca_clock_source_pclk_div_32 = 0,
    pca_clock_source_pclk_div_16 = 1,
    pca_clock_source_pclk_div_08 = 2,
    pca_clock_source_pclk_div_04 = 3,
    pca_clock_source_pclk_div_02 = 4,
    pca_clock_source_tim0_overflow = 5,
    pca_clock_source_tim1_overflow = 6,
    pca_clock_source_external_clock = 7,
} pca_clock_source_t;
typedef struct
{
    uint8_t run_during_sleep : 1;
    pca_clock_source_t clock_source : 3;
    uint8_t enable_interrupts : 1;
} pca_config_t;
typedef void (*pca_overflow_handler_t)();
typedef void (*pca_match_handler_t)(const pca_module_t module);
uint8_t pca_get_module_flag(pca_module_t module);
void pca_clear_module_flag(pca_module_t module);
uint8_t pca_get_counter_flag();
void pca_clear_counter_flag();
void pca_configure(const pca_config_t *cfg, const pca_overflow_handler_t overflow_handler);
void pca_set_running(uint8_t running);
void pca_configure_module(const pca_module_config_t *cfg, const pca_match_handler_t match_handler);

#define peripheral_enable_pca peripheral_set_enabled(peripheral_get_enabled() | peripheral_pca)
#endif