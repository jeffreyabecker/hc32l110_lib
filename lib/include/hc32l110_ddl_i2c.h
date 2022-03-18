/**
 *******************************************************************************
 * @file  hc32l110_crc.h
 * @brief This file contains all the functions prototypes of the DDL crc calculation module.
 */
#ifndef __hc32l110_DDL_I2C_H__
#define __hc32l110_DDL_I2C_H__
#include <stdint.h>
#include "hc32l110_registers.h"


#include <stdint.h>
typedef enum {

} i2c_status_t;
typedef struct{
    uint8_t success:1;
    i2c_status_t status_code;
} i2c_operation_result_t;
typedef struct
{
    i2c_participant_t mode : 1;
    uint8_t peripheral_address:7;
    uint8_t reply_to_broadcast : 1;
    uint16_t frequency_khz : 8;
} i2c_config_t;
typedef enum
{
    i2c_participant_controller = 0,
    i2c_participant_peripheral = 1,
} i2c_participant_t;
i2c_participant_t __i2c_mode;
i2c_operation_result_t i2c_configure(i2c_config_t config);
i2c_operation_result_t i2c_send_start();
i2c_operation_result_t i2c_send_stop();

void i2c_send_ack();
void i2c_send_nak();


i2c_operation_result_t i2c_send_start()
{
    i2c_operation_result_t result;
    M0P_I2C->CR.SI = 0;
    M0P_I2C->CR.STA = 0;
    M0P_I2C->CR.STA = 1;
    while(M0P_I2C->CR.SI != 1){}
    M0P_I2C->CR.SI = 0;
    result.status_code = (i2c_status_t)M0P_I2C->STAT;
    result.success = (M0P_I2C->STAT == 0x10 || M0P_I2C->STAT == 0x08) ? 1 : 0;
    return result;
}
i2c_operation_result_t i2c_send_stop(){
        i2c_operation_result_t result;
    M0P_I2C->CR.SI = 0;
    M0P_I2C->CR.STO = 0;
    M0P_I2C->CR.STO = 1;
    while(M0P_I2C->CR.SI != 1){}
    M0P_I2C->CR.SI = 0;
    result.status_code = (i2c_status_t)M0P_I2C->STAT;
    result.success = (M0P_I2C->STAT == 0x10 || M0P_I2C->STAT == 0x08) ? 1 : 0;
    return result;
}

#if defined(DDL_USE_ALL) || (defined(DDL_USE_CORE) && defined(DDL_USE_I2C))
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif