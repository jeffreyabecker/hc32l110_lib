/**
 *******************************************************************************
 * @file  hc32l110_crc.h
 * @brief This file contains all the functions prototypes of the DDL crc calculation module.
 */
#ifndef __hc32l110_DDL_PCA_H__
#define __hc32l110_DDL_PCA_H__
//#if defined(DDL_USE_ALL) || (defined(DDL_USE_CORE) && defined(DDL_USE_PCA))
#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"

    typedef enum
    {
        pca_clock_source_peripheral_clock_over_32 = 0,
        pca_clock_source_peripheral_clock_over_16 = 1,
        pca_clock_source_peripheral_clock_over_08 = 2,
        pca_clock_source_peripheral_clock_over_04 = 3,
        pca_clock_source_peripheral_clock_over_02 = 4,
        pca_clock_source_timer_0_overflow = 5,
        pca_clock_source_timer_1_overflow = 6,
        pca_clock_source_timer_external_clock_in = 7,
    } pca_clock_source_t;
    typedef enum
    {
        pca_channel_0 = 1,
        pca_channel_1 = 2,
        pca_channel_2 = 4,
        pca_channel_3 = 8,
        pca_channel_4 = 16
    } pca_channel_t;

    void pca_set_running(uint8_t running)
    {
        M0P_PCA->CCON_f.CR = running;
    }
    uint8_t pca_channel_interrupt_is_set(pca_channel_t channel)
    {
        return M0P_PCA->CCON & channel > 0 ? 1 : 0;
    }
    void pca_channel_interrupt_clear(pca_channel_t channel)
    {
        M0P_PCA->ICLR &= ~(channel);
    }
    void pca_interrupt_set_enabled(uint8_t enabled)
    {
        M0P_PCA->CMOD_f.CFIE = enabled;
    }

#ifdef __cplusplus
}
#endif

#endif
//#endif