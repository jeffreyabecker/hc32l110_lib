#include <stdint.h>
#include <stddef.h>
#include "hc32l110_ddl_pca.h"

uint8_t pca_get_module_flag(pca_module_t module)
{
    return HC32_PCA->CCON & (0x01 << module) > 0 ? 1 : 0;
}
void pca_clear_module_flag(pca_module_t module)
{
    HC32_PCA->ICLR &= ~(0x01 << module);
}

uint8_t pca_get_counter_flag()
{
    return HC32_PCA->CCON_f.CF;
}
void pca_clear_counter_flag()
{
    HC32_PCA->ICLR_f.CF = 0;
}

static pca_overflow_handler_t __overflow_handler = NULL;
static pca_match_handler_t __match_handlers[5] = {NULL, NULL, NULL, NULL, NULL};
void pca_configure(const pca_config_t *cfg, const pca_overflow_handler_t overflow_handler)
{
    HC32_PCA->CMOD_f.CIDL = cfg->run_during_sleep;
    HC32_PCA->CMOD_f.CPS = cfg->clock_source;
    HC32_PCA->CMOD_f.CFIE = cfg->enable_interrupts;
    __overflow_handler = overflow_handler;
    if (cfg->enable_interrupts)
    {
        nvic_enable_irq(PCA_IRQn);
    }
    else
    {
        nvic_disable_irq(PCA_IRQn);
    }
}
void pca_set_running(uint8_t running)
{
    if (HC32_PCA->CCON_f.CR != running)
    {
        HC32_PCA->ICLR = 0x00;
        HC32_PCA->CNT = 0x00;
        HC32_PCA->CCON_f.CR = running;
    }
}

void pca_configure_module(const pca_module_config_t *cfg, const pca_match_handler_t match_handler)
{
    pca_clear_module_flag(cfg->module);
    __match_handlers[cfg->module] = match_handler;
    if (cfg->mode == pca_module_mode_compare)
    {
        HC32_PCA_MODULE_MODES[cfg->module]->CCIE = cfg->settings.compare.enable_interrupt;
        HC32_PCA_MODULE_MODES[cfg->module]->MAT = 1;
        HC32_PCA_MODULE_MODES[cfg->module]->CAPP = cfg->settings.compare.capture_rising_edge;
        HC32_PCA_MODULE_MODES[cfg->module]->CAPN = cfg->settings.compare.capture_falling_edge;
        HC32_PCA_MODULE_MODES[cfg->module]->TOG = cfg->settings.compare.enable_output_toggle;
        HC32_PCA_MODULE_MODES[cfg->module]->PWM = 0;
        HC32_PCA_CAPTURE_HIGH_LOW[cfg->module]->L = cfg->settings.compare.value & 0xFF;
        HC32_PCA_CAPTURE_HIGH_LOW[cfg->module]->H = (cfg->settings.compare.value >> 8) & 0xFF;
    }
    else
    {
        HC32_PCA_MODULE_MODES[cfg->module]->CCIE = 0;
        HC32_PCA_MODULE_MODES[cfg->module]->MAT = 1;
        HC32_PCA_MODULE_MODES[cfg->module]->CAPP = 0;
        HC32_PCA_MODULE_MODES[cfg->module]->CAPN = 0;
        HC32_PCA_MODULE_MODES[cfg->module]->TOG = 0;
        HC32_PCA_MODULE_MODES[cfg->module]->PWM = 1;
        uint8_t duty_cycle_value = (255 - ((cfg->settings.pwm.duty_cycle_percent * 255) / 100));
        HC32_PCA_CAPTURE_HIGH_LOW[cfg->module]->L = duty_cycle_value;
        HC32_PCA_CAPTURE_HIGH_LOW[cfg->module]->H = duty_cycle_value;
    }
}

void PCA_Handler(void)
{
    if (pca_get_counter_flag && __overflow_handler != NULL)
    {
        __overflow_handler();
    }
    for (uint8_t i = 0; i < 6; i++)
    {
        if (__match_handlers[i] != 0 && (HC32_PCA->CCON & (1 << i)) > 0)
        {
            __match_handlers[i](i);
        }
    }
    HC32_PCA->ICLR = 0x00;
}