/**
 *******************************************************************************
 * @file  hc32l110_ports.h
 * @brief This file contains all the functions prototypes of the DDL port function selection module.
 */
#ifndef __hc32l110_PORTS_H__
#define __hc32l110_PORTS_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hc32l110_registers.h"

    typedef enum
    {
        port_p01 = 1,
        port_p02 = 2,
        port_p03 = 3,
        port_p14 = 14,
        port_p15 = 15,
        port_p23 = 23,
        port_p24 = 24,
        port_p25 = 25,
        port_p26 = 26,
        port_p27 = 27,
        port_p31 = 31,
        port_p32 = 32,
        port_p33 = 33,
        port_p34 = 34,
        port_p35 = 35,
        port_p36 = 36,
    } port_number_t;

    void ports_set_function(port_number_t port, uint8_t function);
    typedef struct
    {
        uint8_t p01 : 3;
        uint8_t p02 : 3;
        uint8_t p03 : 3;
        uint8_t p14 : 3;
        uint8_t p15 : 3;
        uint8_t p23 : 3;
        uint8_t p24 : 3;
        uint8_t p25 : 3;
        uint8_t p26 : 3;
        uint8_t p27 : 3;
        uint8_t p31 : 3;
        uint8_t p32 : 3;
        uint8_t p33 : 3;
        uint8_t p34 : 3;
        uint8_t p35 : 3;
        uint8_t p36 : 3;
    } port_configuration_t;
    void ports_configure(port_configuration_t cfg);
    uint8_t ports_get_function(port_number_t port);

#ifdef __cplusplus
}
#endif

#endif
