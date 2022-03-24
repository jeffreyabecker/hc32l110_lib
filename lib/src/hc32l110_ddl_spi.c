#include <stdint.h>
#include <stddef.h>
#include "hc32l110_ddl_core.h"
#include "hc32l110_ddl_spi.h"

spi_interrupt_handler_t __handler = NULL;
void spi_config(const spi_config_t *cfg, const spi_interrupt_handler_t handler)
{
    __handler = handler;
    HC32_SPI->CR_f.SPEN = 0;
    HC32_SPI->CR_f.SPR0 = cfg->clock_divider & 0x01;
    HC32_SPI->CR_f.SPR1 = (cfg->clock_divider >> 1) & 0x01;
    HC32_SPI->CR_f.SPR2 = (cfg->clock_divider >> 2) & 0x01;
    HC32_SPI->CR_f.CPOL = (cfg->clock_mode) >> 1 & 0x01;
    HC32_SPI->CR_f.CPHA = (cfg->clock_mode) & 0x01;
    HC32_SPI->CR_f.MODE = cfg->participant_mode;
    HC32_SPI->STAT = 0x00;
    nvic_configure_interrupt(SPI_IRQn, nvic_default_irq_priority, cfg->enable_interrupt);
    HC32_SPI->CR_f.SPEN = 1;
}

#define break_if_timeout_exceeded()                  \
    if (systick_time_stince(start) >= timeout_ticks) \
    {                                                \
        return bytes_processed;                      \
    }
uint8_t spi_write(const uint8_t *data, const uint8_t length, uint32_t timeout_ticks)
{
    uint8_t bytes_processed = 0;
    uint8_t scratch = 0;
    uint32_t start = systick_current_value();

    if (HC32_SPI->CR_f.MODE == spi_participant_mode_controller)
    {
        HC32_SPI->SSN = 0;
    }
    else
    {
        while (HC32_SPI->SSN > 0)
        {
            break_if_timeout_exceeded();
        }
    }

    for (uint8_t i = 0; i < length; i++)
    {
        break_if_timeout_exceeded();
        HC32_SPI->DATA = data[i];
        while (!spi_data_transfer_complete())
        {
            break_if_timeout_exceeded();
        }
        scratch = HC32_SPI->DATA;
        bytes_processed++;
    }
    if (HC32_SPI->CR_f.MODE == spi_participant_mode_controller)
    {
        HC32_SPI->SSN = 1;
    }
    return bytes_processed;
}
uint8_t spi_read(uint8_t *data, const uint8_t length, uint32_t timeout_ticks)
{
    uint8_t bytes_processed = 0;
    uint8_t scratch = 0;
    uint32_t start = systick_current_value();

    if (HC32_SPI->CR_f.MODE == spi_participant_mode_controller)
    {
        HC32_SPI->SSN = 0;
    }
    else
    {
        while (HC32_SPI->SSN > 0)
        {
            break_if_timeout_exceeded();
        }
    }
    for (uint8_t i = 0; i < length; i++)
    {
        break_if_timeout_exceeded();
        HC32_SPI->DATA = 0x00;
        while (!spi_data_transfer_complete())
        {
            break_if_timeout_exceeded();
        }
        data[i] = HC32_SPI->DATA;
        bytes_processed++;
    }
    if (HC32_SPI->CR_f.MODE == spi_participant_mode_controller)
    {
        HC32_SPI->SSN = 1;
    }
    return bytes_processed;
}
uint8_t spi_data_transfer_complete()
{
    return HC32_SPI->STAT_f.SPIF;
}

void SPI_Handler(void)
{
    if (__handler)
    {
        __handler();
    }
    NVIC_ClearPendingIRQ(SPI_IRQn);
}