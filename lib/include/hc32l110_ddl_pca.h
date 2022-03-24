#ifndef __SYSTEM_HC32L110_DDL_PCA_H__
#define __SYSTEM_HC32L110_DDL_PCA_H__
#include "hc32l110_cmsis.h"
#include "hc32l110_system.h"
#include "hc32l110_registers_pca.h"

void pca_configure_source();
typedef enum{
    pca_module_0 = 0,
    pca_module_1 = 1,
    pca_module_2 = 2,
    pca_module_3 = 3,
    pca_module_4 = 4,
} pca_module_t;

uint8_t pca_flag_is_set(pca_module_t module);
#endif