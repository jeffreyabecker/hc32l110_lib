
#include "hc32l110_interrupts.h"


typedef struct
{
    nvic_interrupt_handler_t handler;
    void *data;
} nvic_interrupt_table_entry_t;

static nvic_interrupt_table_entry_t nvic_indirection_table[36] = {NULL};
uint32_t __nvic_table_index(nivc_irq_number_t irq_number)
{
    if ((int32_t)irq_number >= 0)
    {
        return (int32_t)irq_number + 5;
    }
    else if (irq_number == irq_sys_tick)
    {
        return 4;
    }
    else if (irq_number == irq_pend_sv)
    {
        return 3;
    }
    else if (irq_number == irq_svc)
    {
        return 2;
    }
    else if (irq_number == irq_hard_fault)
    {
        return 1;
    }
    else
        return 0;
}

void nvic_interrupt_cfg(nivc_irq_number_t irq_number, nvic_interrupt_handler_t handler, void *data)
{
    uint32_t index = __nvic_table_index(irq_number);
    nvic_indirection_table[index].handler = handler;
    nvic_indirection_table[index].data = data;
}
void nvic_interrupt_set_enabled(nivc_irq_number_t irq_number, uint8_t enabled){
    if(enabled == 0){
        NVIC_DisableIRQ(irq_number);
    }
    else{
        NVIC_EnableIRQ(irq_number);
    }
}
void nvic_interrupt_set_priority(nivc_irq_number_t irq_number, uint8_t priority)
{
    NVIC_SetPriority(irq_number, priority);
}
uint8_t nvic_interrupt_get_priority(nivc_irq_number_t irq_number){
    return (uint8_t) NVIC_GetPriority(irq_number);
}
void nvic_interrupt_raise(nivc_irq_number_t irq_number){
    NVIC_SetPendingIRQ(irq_number);
}
void nvic_interrupt_clear(nivc_irq_number_t irq_number){
    NVIC_ClearPendingIRQ(irq_number);
}

void NMI_Handler(void)
{
    if (nvic_indirection_table[0].handler != NULL)
    {
        nvic_indirection_table[0].handler(irq_nmi, nvic_indirection_table[0].data);
    }
    NVIC_ClearPendingIRQ(irq_nmi);
}
void HardFault_Handler(void)
{
    if (nvic_indirection_table[1].handler != NULL)
    {
        nvic_indirection_table[1].handler(irq_hard_fault, nvic_indirection_table[1].data);
    }
    NVIC_ClearPendingIRQ(irq_hard_fault);
}
void SVC_Handler(void)
{
    if (nvic_indirection_table[2].handler != NULL)
    {
        nvic_indirection_table[2].handler(irq_svc, nvic_indirection_table[2].data);
    }
    NVIC_ClearPendingIRQ(irq_svc);
}
void PendSV_Handler(void)
{
    if (nvic_indirection_table[3].handler != NULL)
    {
        nvic_indirection_table[3].handler(irq_pend_sv, nvic_indirection_table[3].data);
    }
    NVIC_ClearPendingIRQ(irq_pend_sv);
}
void SysTick_Handler(void)
{
    systick_increment_ticks();
    if (nvic_indirection_table[4].handler != NULL)
    {
        nvic_indirection_table[4].handler(irq_sys_tick, nvic_indirection_table[4].data);
    }
    NVIC_ClearPendingIRQ(irq_sys_tick);
}
void GpioPort0_Handler(void)
{
    if (nvic_indirection_table[5].handler != NULL)
    {
        nvic_indirection_table[5].handler(irq_port_0, nvic_indirection_table[5].data);
    }
    NVIC_ClearPendingIRQ(irq_port_0);
}
void GpioPort1_Handler(void)
{
    if (nvic_indirection_table[6].handler != NULL)
    {
        nvic_indirection_table[6].handler(irq_port_1, nvic_indirection_table[6].data);
    }
    NVIC_ClearPendingIRQ(irq_port_1);
}
void GpioPort2_Handler(void)
{
    if (nvic_indirection_table[7].handler != NULL)
    {
        nvic_indirection_table[7].handler(irq_port_2, nvic_indirection_table[7].data);
    }
    NVIC_ClearPendingIRQ(irq_port_2);
}
void GpioPort3_Handler(void)
{
    if (nvic_indirection_table[8].handler != NULL)
    {
        nvic_indirection_table[8].handler(irq_port_3, nvic_indirection_table[8].data);
    }
    NVIC_ClearPendingIRQ(irq_port_3);
}
void UserInterrupt0_Handler(void)
{
    if (nvic_indirection_table[9].handler != NULL)
    {
        nvic_indirection_table[9].handler(irq_user_0, nvic_indirection_table[9].data);
    }
    NVIC_ClearPendingIRQ(irq_user_0);
}
void UserInterrupt1_Handler(void)
{
    if (nvic_indirection_table[10].handler != NULL)
    {
        nvic_indirection_table[10].handler(irq_user_1, nvic_indirection_table[10].data);
    }
    NVIC_ClearPendingIRQ(irq_user_1);
}
void Uart0_Handler(void)
{
    if (nvic_indirection_table[11].handler != NULL)
    {
        nvic_indirection_table[11].handler(irq_uart_0, nvic_indirection_table[11].data);
    }
    NVIC_ClearPendingIRQ(irq_uart_0);    
}
void Uart1_Handler(void)
{
    if (nvic_indirection_table[12].handler != NULL)
    {
        nvic_indirection_table[12].handler(irq_uart_1, nvic_indirection_table[12].data);
    }
    NVIC_ClearPendingIRQ(irq_uart_1);
}
void LpUart_Handler(void)
{
    if (nvic_indirection_table[13].handler != NULL)
    {
        nvic_indirection_table[13].handler(irq_lpuart, nvic_indirection_table[13].data);
    }
    NVIC_ClearPendingIRQ(irq_lpuart);
}
void UserInterrupt2_Handler(void)
{
    if (nvic_indirection_table[14].handler != NULL)
    {
        nvic_indirection_table[14].handler(irq_user_2, nvic_indirection_table[14].data);
    }
    NVIC_ClearPendingIRQ(irq_user_2);
}
void SPI_Handler(void)
{
    if (nvic_indirection_table[15].handler != NULL)
    {
        nvic_indirection_table[15].handler(irq_spi, nvic_indirection_table[15].data);
    }
    NVIC_ClearPendingIRQ(irq_spi);
}
void UserInterrupt3_Handler(void)
{
    if (nvic_indirection_table[16].handler != NULL)
    {
        nvic_indirection_table[16].handler(irq_user_3, nvic_indirection_table[16].data);
    }
    NVIC_ClearPendingIRQ(irq_user_3);
}
void I2C_Handler(void)
{
    if (nvic_indirection_table[17].handler != NULL)
    {
        nvic_indirection_table[17].handler(irq_i2c, nvic_indirection_table[17].data);
    }
    NVIC_ClearPendingIRQ(irq_i2c);
}
void UserInterrupt4_Handler(void)
{
    if (nvic_indirection_table[18].handler != NULL)
    {
        nvic_indirection_table[18].handler(irq_user_4, nvic_indirection_table[18].data);
    }
    NVIC_ClearPendingIRQ(irq_user_4);
}
void Timer0_Handler(void)
{
    if (nvic_indirection_table[19].handler != NULL)
    {
        nvic_indirection_table[19].handler(irq_timer_0, nvic_indirection_table[19].data);
    }
    NVIC_ClearPendingIRQ(irq_timer_0);
}
void Timer1_Handler(void)
{
    if (nvic_indirection_table[20].handler != NULL)
    {
        nvic_indirection_table[20].handler(irq_timer_1, nvic_indirection_table[20].data);
    }
    NVIC_ClearPendingIRQ(irq_timer_1);
}
void Timer2_Handler(void)
{
    if (nvic_indirection_table[21].handler != NULL)
    {
        nvic_indirection_table[21].handler(irq_timer_2, nvic_indirection_table[21].data);
    }
    NVIC_ClearPendingIRQ(irq_timer_2);
}
void LpTimer_Handler(void)
{
    if (nvic_indirection_table[22].handler != NULL)
    {
        nvic_indirection_table[22].handler(irq_low_power_timer, nvic_indirection_table[22].data);
    }
    NVIC_ClearPendingIRQ(irq_low_power_timer);
}
void Timer4_Handler(void)
{
    if (nvic_indirection_table[23].handler != NULL)
    {
        nvic_indirection_table[23].handler(irq_timer_4, nvic_indirection_table[23].data);
    }
    NVIC_ClearPendingIRQ(irq_timer_4);
}
void Timer5_Handler(void)
{
    if (nvic_indirection_table[24].handler != NULL)
    {
        nvic_indirection_table[24].handler(irq_timer_5, nvic_indirection_table[24].data);
    }
    NVIC_ClearPendingIRQ(irq_timer_5);
}
void Timer6_Handler(void)
{
    if (nvic_indirection_table[25].handler != NULL)
    {
        nvic_indirection_table[25].handler(irq_timer_6, nvic_indirection_table[25].data);
    }
    NVIC_ClearPendingIRQ(irq_timer_6);
}
void PCA_Handler(void)
{
    if (nvic_indirection_table[26].handler != NULL)
    {
        nvic_indirection_table[26].handler(irq_pca, nvic_indirection_table[26].data);
    }
    NVIC_ClearPendingIRQ(irq_pca);
}
void WatchDogTimer_Handler(void)
{
    if (nvic_indirection_table[27].handler != NULL)
    {
        nvic_indirection_table[27].handler(irq_watchdog_timer, nvic_indirection_table[27].data);
    }
    NVIC_ClearPendingIRQ(irq_watchdog_timer);
}
void RTC_Handler(void)
{
    if (nvic_indirection_table[28].handler != NULL)
    {
        nvic_indirection_table[28].handler(irq_realtime_clock, nvic_indirection_table[28].data);
    }
    NVIC_ClearPendingIRQ(irq_realtime_clock);
}
void ADC_Handler(void)
{
    if (nvic_indirection_table[29].handler != NULL)
    {
        nvic_indirection_table[29].handler(irq_analog_digital_converter, nvic_indirection_table[29].data);
    }
    NVIC_ClearPendingIRQ(irq_analog_digital_converter);
}
void UserInterrupt5_Handler(void)
{
    if (nvic_indirection_table[30].handler != NULL)
    {
        nvic_indirection_table[30].handler(irq_user_5, nvic_indirection_table[30].data);
    }
    NVIC_ClearPendingIRQ(irq_user_5);
}
void VC0_Handler(void)
{
    if (nvic_indirection_table[31].handler != NULL)
    {
        nvic_indirection_table[31].handler(irq_voltage_comparitor_0, nvic_indirection_table[31].data);
    }
    NVIC_ClearPendingIRQ(irq_voltage_comparitor_0);
}
void VC1_Handler(void)
{
    if (nvic_indirection_table[32].handler != NULL)
    {
        nvic_indirection_table[32].handler(irq_voltage_comparitor_1, nvic_indirection_table[32].data);
    }
    NVIC_ClearPendingIRQ(irq_voltage_comparitor_1);
}
void LVD_Handler(void)
{
    if (nvic_indirection_table[33].handler != NULL)
    {
        nvic_indirection_table[33].handler(irq_low_voltage, nvic_indirection_table[33].data);
    }
    NVIC_ClearPendingIRQ(irq_low_voltage);
}
void EfRam_Handler(void)
{
    if (nvic_indirection_table[34].handler != NULL)
    {
        nvic_indirection_table[34].handler(irq_ef_ram, nvic_indirection_table[34].data);
    }
    NVIC_ClearPendingIRQ(irq_ef_ram);
}
void ClockTrim_Handler(void)
{
    if (nvic_indirection_table[35].handler != NULL)
    {
        nvic_indirection_table[35].handler(irq_clock_trim, nvic_indirection_table[35].data);
    }
    NVIC_ClearPendingIRQ(irq_clock_trim);
}
