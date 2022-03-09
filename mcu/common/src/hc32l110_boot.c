#include <stdint.h>
#include <cmsis_compiler.h>
#ifdef __cplusplus
extern "C"
{
#endif
    typedef void (*irq_handler_t)();
    extern uint32_t __INITIAL_SP;
    extern void main();

    void Reset_Handler(void) __WEAK __NO_RETURN;
    void NMI_Handler(void) __WEAK;
    void HardFault_Handler(void) __WEAK;
    void SVC_Handler(void) __WEAK;
    void PendSV_Handler(void) __WEAK;
    void SysTick_Handler(void) __WEAK;
    void GpioPort0_Handler(void) __WEAK;
    void GpioPort1_Handler(void) __WEAK;
    void GpioPort2_Handler(void) __WEAK;
    void GpioPort3_Handler(void) __WEAK;
    void UserInterrupt0_Handler(void) __WEAK;
    void UserInterrupt1_Handler(void) __WEAK;
    void Uart0_Handler(void) __WEAK;
    void Uart1_Handler(void) __WEAK;
    void LpUart_Handler(void) __WEAK;
    void UserInterrupt2_Handler(void) __WEAK;
    void SPI_Handler(void) __WEAK;
    void UserInterrupt3_Handler(void) __WEAK;
    void I2C_Handler(void) __WEAK;
    void UserInterrupt4_Handler(void) __WEAK;
    void Timer0_Handler(void) __WEAK;
    void Timer1_Handler(void) __WEAK;
    void Timer2_Handler(void) __WEAK;
    void LpTimer_Handler(void) __WEAK;
    void Timer4_Handler(void) __WEAK;
    void Timer5_Handler(void) __WEAK;
    void Timer6_Handler(void) __WEAK;
    void PCA_Handler(void) __WEAK;
    void WatchDogTimer_Handler(void) __WEAK;
    void RTC_Handler(void) __WEAK;
    void ADC_Handler(void) __WEAK;
    void UserInterrupt5_Handler(void) __WEAK;
    void VC0_Handler(void) __WEAK;
    void VC1_Handler(void) __WEAK;
    void LVD_Handler(void) __WEAK;
    void UserInterrupt6_Handler(void) __WEAK;
    void EfRam_Handler(void) __WEAK;
    void ClockTrim_Handler(void) __WEAK;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"

    extern const irq_handler_t __VECTOR_TABLE[48];
    const irq_handler_t __VECTOR_TABLE[48] __attribute__((used, section(".vectors"))) = {
        (irq_handler_t)(&__INITIAL_SP), /*     Initial Stack Pointer */
        Reset_Handler,
        NMI_Handler,
        HardFault_Handler,
        0, // Reserved
        0, // Reserved
        0, // Reserved
        0, // Reserved
        0, // Reserved
        0, // Reserved
        0, // Reserved
        SVC_Handler,
        0, // Reserved
        0, // Reserved
        PendSV_Handler,
        SysTick_Handler,
        GpioPort0_Handler,
        GpioPort1_Handler,
        GpioPort2_Handler,
        GpioPort3_Handler,
        UserInterrupt0_Handler,
        UserInterrupt1_Handler,
        Uart0_Handler,
        Uart1_Handler,
        LpUart_Handler,
        UserInterrupt2_Handler,
        SPI_Handler,
        UserInterrupt3_Handler,
        I2C_Handler,
        UserInterrupt4_Handler,
        Timer0_Handler,
        Timer1_Handler,
        Timer2_Handler,
        LpTimer_Handler,
        Timer4_Handler,
        Timer5_Handler,
        Timer6_Handler,
        PCA_Handler,
        WatchDogTimer_Handler,
        RTC_Handler,
        ADC_Handler,
        UserInterrupt5_Handler,
        VC0_Handler,
        VC1_Handler,
        LVD_Handler,
        UserInterrupt6_Handler,
        EfRam_Handler,
        ClockTrim_Handler,
    };

#pragma GCC diagnostic pop

    __WEAK void SystemInit();

    typedef struct
    {
        uint32_t const *src;
        uint32_t *dest;
        uint32_t wlen;
    } __copy_table_t;

    typedef struct
    {
        uint32_t *dest;
        uint32_t wlen;
    } __zero_table_t;

    extern const __copy_table_t __copy_table_start__;
    extern const __copy_table_t __copy_table_end__;
    extern const __zero_table_t __zero_table_start__;
    extern const __zero_table_t __zero_table_end__;
    /*----------------------------------------------------------------------------
    Reset Handler called on controller reset
    *----------------------------------------------------------------------------*/

    __WEAK void Reset_Handler(void)
    {
        SystemInit(); /* CMSIS System Initialization */

        for (__copy_table_t const *pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable)
        {
            for (uint32_t i = 0u; i < pTable->wlen; ++i)
            {
                pTable->dest[i] = pTable->src[i];
            }
        }

        for (__zero_table_t const *pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable)
        {
            for (uint32_t i = 0u; i < pTable->wlen; ++i)
            {
                pTable->dest[i] = 0u;
            }
        }

        main();
        while (1)
        {
            __WFI();
        }
    }
    __WEAK void NMI_Handler(void)
    {
        // this interrupt isnt actually implemented in the chip and will never be called
    }
    __WEAK void HardFault_Handler(void)
    {
        while (1)
        {
            __WFI();
        }
    }
    __WEAK void SVC_Handler(void) {}
    __WEAK void PendSV_Handler(void) {}
    __WEAK void SysTick_Handler(void) {}
    __WEAK void GpioPort0_Handler(void) {}
    __WEAK void GpioPort1_Handler(void) {}
    __WEAK void GpioPort2_Handler(void) {}
    __WEAK void GpioPort3_Handler(void) {}
    __WEAK void UserInterrupt0_Handler(void) {}
    __WEAK void UserInterrupt1_Handler(void) {}
    __WEAK void Uart0_Handler(void) {}
    __WEAK void Uart1_Handler(void) {}
    __WEAK void LpUart_Handler(void) {}
    __WEAK void UserInterrupt2_Handler(void) {}
    __WEAK void SPI_Handler(void) {}
    __WEAK void UserInterrupt3_Handler(void) {}
    __WEAK void I2C_Handler(void) {}
    __WEAK void UserInterrupt4_Handler(void) {}
    __WEAK void Timer0_Handler(void) {}
    __WEAK void Timer1_Handler(void) {}
    __WEAK void Timer2_Handler(void) {}
    __WEAK void LpTimer_Handler(void) {}
    __WEAK void Timer4_Handler(void) {}
    __WEAK void Timer5_Handler(void) {}
    __WEAK void Timer6_Handler(void) {}
    __WEAK void PCA_Handler(void) {}
    __WEAK void WatchDogTimer_Handler(void) {}
    __WEAK void RTC_Handler(void) {}
    __WEAK void ADC_Handler(void) {}
    __WEAK void UserInterrupt5_Handler(void) {}
    __WEAK void VC0_Handler(void) {}
    __WEAK void VC1_Handler(void) {}
    __WEAK void LVD_Handler(void) {}
    __WEAK void UserInterrupt6_Handler(void) {}
    __WEAK void EfRam_Handler(void) {}
    __WEAK void ClockTrim_Handler(void) {}

    uint32_t SystemCoreClock;

    __WEAK void SystemCoreClockUpdate(void) // Update core_system_clock_frequency variable
    {
        SystemCoreClock = 4000000;
    }

    __WEAK void SystemInit(void)
    {
        (*((volatile uint32_t *)(0x4000200Cul))) = (*((volatile uint16_t *)(0x00100C08ul))); // Load 4MHz Trimming value into M0P_CLOCK_RCH
        SystemCoreClockUpdate();
    }
#ifdef __cplusplus
}
#endif