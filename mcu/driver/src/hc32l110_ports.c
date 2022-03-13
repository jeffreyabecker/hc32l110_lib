
#include "hc32l110_core.h"
#include "hc32l110_system.h"
#include "hc32l110_ports.h"

__INLINE void ports_set_function(port_number_t port, uint8_t function)
{
    switch (port)
    {
    case port_p01:
        M0P_GPIO->P01_SEL = function;
        return;
    case port_p02:
        M0P_GPIO->P02_SEL = function;
        return;
    case port_p03:
        M0P_GPIO->P03_SEL = function;
        return;
    case port_p14:
        M0P_GPIO->P14_SEL = function;
        return;
    case port_p15:
        M0P_GPIO->P15_SEL = function;
        return;
    case port_p23:
        M0P_GPIO->P23_SEL = function;
        return;
    case port_p24:
        M0P_GPIO->P24_SEL = function;
        return;
    case port_p25:
        M0P_GPIO->P25_SEL = function;
        return;
    case port_p26:
        M0P_GPIO->P26_SEL = function;
        return;
    case port_p27:
        M0P_GPIO->P27_SEL = function;
        return;
    case port_p31:
        M0P_GPIO->P31_SEL = function;
        return;
    case port_p32:
        M0P_GPIO->P32_SEL = function;
        return;
    case port_p33:
        M0P_GPIO->P33_SEL = function;
        return;
    case port_p34:
        M0P_GPIO->P34_SEL = function;
        return;
    case port_p35:
        M0P_GPIO->P35_SEL = function;
        return;
    case port_p36:
        M0P_GPIO->P36_SEL = function;
        return;
    default:
        break;
    }
}
__INLINE void ports_configure(port_configuration_t cfg)
{
    M0P_GPIO->P01_SEL = cfg.p01;
    M0P_GPIO->P02_SEL = cfg.p02;
    M0P_GPIO->P03_SEL = cfg.p03;
    M0P_GPIO->P14_SEL = cfg.p14;
    M0P_GPIO->P15_SEL = cfg.p15;
    M0P_GPIO->P23_SEL = cfg.p23;
    M0P_GPIO->P24_SEL = cfg.p24;
    M0P_GPIO->P25_SEL = cfg.p25;
    M0P_GPIO->P26_SEL = cfg.p26;
    M0P_GPIO->P27_SEL = cfg.p27;
    M0P_GPIO->P31_SEL = cfg.p31;
    M0P_GPIO->P32_SEL = cfg.p32;
    M0P_GPIO->P33_SEL = cfg.p33;
    M0P_GPIO->P34_SEL = cfg.p34;
    M0P_GPIO->P35_SEL = cfg.p35;
    M0P_GPIO->P36_SEL = cfg.p36;
}
__INLINE uint8_t ports_get_function(port_number_t port)
{
    switch (port)
    {
    case port_p01:
        return M0P_GPIO->P01_SEL;
    case port_p02:
        return M0P_GPIO->P02_SEL;
    case port_p03:
        return M0P_GPIO->P03_SEL;
    case port_p14:
        return M0P_GPIO->P14_SEL;
    case port_p15:
        return M0P_GPIO->P15_SEL;
    case port_p23:
        return M0P_GPIO->P23_SEL;
    case port_p24:
        return M0P_GPIO->P24_SEL;
    case port_p25:
        return M0P_GPIO->P25_SEL;
    case port_p26:
        return M0P_GPIO->P26_SEL;
    case port_p27:
        return M0P_GPIO->P27_SEL;
    case port_p31:
        return M0P_GPIO->P31_SEL;
    case port_p32:
        return M0P_GPIO->P32_SEL;
    case port_p33:
        return M0P_GPIO->P33_SEL;
    case port_p34:
        return M0P_GPIO->P34_SEL;
    case port_p35:
        return M0P_GPIO->P35_SEL;
    case port_p36:
        return M0P_GPIO->P36_SEL;
    default:
        return 0;
    }
}
