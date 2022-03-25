#include "hc32l110_ddl_i2c.h"
#include "hc32l110_ddl_buffers.h"
#include "hc32l110_ddl_core.h"

#define operation_result(STATUS, SUCCESS)  (i2c_operation_result_t)(((STATUS << 1) | ((SUCCESS)? ? 1 : 0)))
void peripheral_enable_i2c()
{
    peripheral_set_enabled(peripheral_get_enabled() | peripheral_i2c);
    nvic_enable_irq(I2C_IRQn);
    HC32_I2C->CR.ENS = 1;
}
uint8_t i2c_operation_complete()
{
    return HC32_I2C->CR.SI;
}
uint8_t i2c_get_status()
{
    return HC32_I2C->status;
}
uint16_t i2c_wait()
{
    while (!i2c_operation_complete())
    {
        __NOP();
    }
    return i2c_get_status();
}
typedef struct{
    uint8_t success:1;
    uint8_t recieved_ack:1;
    uint8_t status:8;
    
}i2c_controller_result_t;

i2c_operation_result_t i2c_controller_set_start(uint8_t enabled)
{
    HC32_I2C->CR.SI = 0;
    HC32_I2C->CR.STA = enabled;
    uint16_t status = i2c_wait();

}


void i2c_set_ack(uint8_t ack)
{
    HC32_I2C->CR.AA = ack;
}


uint8_t i2c_transmit_and_wait(uint8_t byte)
{
    HC32_I2C->CR.SI = 0;
    HC32_I2C->DATA = byte;
    return i2c_wait();
}

i2c_operation_result_t i2c_controller_send_address(uint8_t recipient, i2c_operation_t operation)
{
    uint16_t status = i2c_transmit_and_wait(recipient << 1 + operation);
    return operation_result(status, status == 0x18 );
}

uint8_t i2c_transmit_and_ack(uint8_t byte, uint8_t ack)
{
    i2c_set_ack(ack);
    HC32_I2C->CR.SI = 0;
    HC32_I2C->DATA = byte;
    return i2c_wait();
}
uint8_t i2c_read()
{
    return HC32_I2C->DATA;
}


void i2c_set_stop(uint8_t enabled)
{
    HC32_I2C->CR.STO = enabled;
}
