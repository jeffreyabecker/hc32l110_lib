/**
 *******************************************************************************
 * @file  hc32l110_crc.h
 * @brief This file contains all the functions prototypes of the DDL crc calculation module.
 */
#ifndef __hc32l110_CRC_H__
#define __hc32l110_CRC_H__
#if defined(DDL_USE_ALL) || ( defined(DDL_USE_CORE) && defined(DDL_USE_CRC))
#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"

    typedef enum
    {
        crc_word_size_8 = 0,
        crc_word_size_16 = 1,
        crc_word_size_32 = 2,
    } crc_word_size_t;

    uint16_t crc_calculate(crc_word_size_t word_size, uint16_t word_count, const void *data)
    {
        uint32_t i = 0;
        M0P_CRC->RESULT = 0xFFFF;
        if (word_size == crc_word_size_8)
        {
            for (uint32_t i = 0; i < word_count; i++)
            {
                M0P_CRC->DATA8 = ((uint8_t *)data)[i];
            }
        }
        if (word_size == crc_word_size_16)
        {
            for (i = 0; i < word_count; i++)
            {
                M0P_CRC->DATA16 = ((uint16_t *)data)[i];
            }
        }
        if (word_size == crc_word_size_32)
        {
            for (i = 0; i < word_count; i++)
            {
                M0P_CRC->DATA32 = ((uint32_t *)data)[i];
            }
        }
        return M0P_CRC->RESULT;
    }


#ifdef __cplusplus
}
#endif

#endif
#endif