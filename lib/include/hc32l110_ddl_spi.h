#ifndef __HC32L110_DDL_SPI_H__
#define __HC32L110_DDL_SPI_H__
#include <stdint.h>
#include "hc32l110_registers_spi.h"
#include "hc32l110_ddl_core.h"
void peripheral_enable_spi();
// this file is still a work in progess. specifically I need to figure out how bi-directional data transfer works
// since the chip only has a one-byte buffer thats used for both reads and writes
// typedef enum
// {
//     spi_participant_mode_peripheral = 0,
//     spi_participant_mode_controller = 1,
// } spi_participant_mode_t;
// typedef enum
// {
//     spi_clock_mode_0 = 0, // low polarity, latched rising (1st)
//     spi_clock_mode_1 = 1, // low polarity, latched falling (2nd)
//     spi_clock_mode_2 = 2, // high polarity, latched falling (1st)
//     spi_clock_mode_3 = 3, // high polarity, latched rising (2nd)
// } spi_clock_mode_t;
// typedef enum
// {
//     spi_clock_divider_2 = 0,
//     spi_clock_divider_4 = 1,
//     spi_clock_divider_8 = 2,
//     spi_clock_divider_16 = 3,
//     spi_clock_divider_32 = 4,
//     spi_clock_divider_64 = 5,
//     spi_clock_divider_128 = 6
// } spi_clock_divider_t;

// typedef struct 
// {
//     spi_participant_mode_t participant_mode :1;
//     spi_clock_mode_t clock_mode :2;
//     spi_clock_divider_t clock_divider : 3;
//     uint8_t enable_interrupt : 1;
// }spi_config_t;
// typedef void (*spi_interrupt_handler_t)(void);
// void spi_config(const spi_config_t* cfg, const spi_interrupt_handler_t handler);


// uint8_t spi_data_transfer_complete();
// uint8_t spi_write(const uint8_t* data, const uint8_t length, uint32_t timeout_ticks);
// uint8_t spi_read( uint8_t* data, const uint8_t length, uint32_t timeout_ticks);


#endif
