#ifndef __HC32L110_REGISTERS_LVD_H__
#define __HC32L110_REGISTERS_LVD_H__
#ifdef __cplusplus
#define __I volatile /*!< Defines 'read only' permissions */
#else
#define __I volatile const /*!< Defines 'read only' permissions */
#endif
#define __O volatile  /*!< Defines 'write only' permissions */
#define __IO volatile /*!< Defines 'read / write' permissions */
#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif
#define __read_only_data __attribute__((section(".rodata"))) const

/* following defines should be used for structure members */
#define __IM volatile const /*! Defines 'read only' structure member permissions */
#define __OM volatile       /*! Defines 'write only' structure member permissions */
#define __IOM volatile      /*! Defines 'read / write' structure member permissions */
    typedef enum 
    {
        irq_nmi = -14,        /*  2 Non Maskable*/
        irq_hard_fault = -13, /*  3 Hard Fault*/
        irq_svc = -5,         /* 11 SV Call*/
        irq_pend_sv = -2,     /* 14 Pend SV*/
        irq_sys_tick = -1,    /* 15 System Tick*/
        irq_port_0 = 0,
        irq_port_1 = 1,
        irq_port_2 = 2,
        irq_port_3 = 3,
        irq_user_0 = 4,
        irq_user_1 = 5,
        irq_uart_0 = 6,
        irq_uart_1 = 7,
        irq_lpuart = 8,
        irq_user_2 = 9,
        irq_spi = 10,
        irq_user_3 = 11,
        irq_i2c = 12,
        irq_user_4 = 13,
        irq_timer_0 = 14,
        irq_timer_1 = 15,
        irq_timer_2 = 16,
        irq_low_power_timer = 17,
        irq_timer_4 = 18,
        irq_timer_5 = 19,
        irq_timer_6 = 20,
        irq_pca = 21,
        irq_watchdog_timer = 22,
        irq_realtime_clock = 23,
        irq_analog_digital_converter = 24,
        irq_user_5 = 25,
        irq_voltage_comparitor_0 = 26,
        irq_voltage_comparitor_1 = 27,
        irq_low_voltage = 28,
        irq_ef_ram = 30,
        irq_clock_trim = 31,
    } nivc_irq_number_t;
    typedef union
    {
        struct
        {
            uint32_t _reserved0 : 28; /*!< bit:  0..27  Reserved */
            uint32_t V : 1;           /*!< bit:     28  Overflow condition code flag */
            uint32_t C : 1;           /*!< bit:     29  Carry condition code flag */
            uint32_t Z : 1;           /*!< bit:     30  Zero condition code flag */
            uint32_t N : 1;           /*!< bit:     31  Negative condition code flag */
        } b;                          /*!< Structure used for bit  access */
        uint32_t w;                   /*!< Type      used for word access */
    } APSR_Type;
    typedef union
    {
        struct
        {
            uint32_t ISR : 9;         /*!< bit:  0.. 8  Exception number */
            uint32_t _reserved0 : 23; /*!< bit:  9..31  Reserved */
        } b;                          /*!< Structure used for bit  access */
        uint32_t w;                   /*!< Type      used for word access */
    } IPSR_Type;
    typedef union
    {
        struct
        {
            uint32_t ISR : 9;         /*!< bit:  0.. 8  Exception number */
            uint32_t _reserved0 : 15; /*!< bit:  9..23  Reserved */
            uint32_t T : 1;           /*!< bit:     24  Thumb bit        (read 0) */
            uint32_t _reserved1 : 3;  /*!< bit: 25..27  Reserved */
            uint32_t V : 1;           /*!< bit:     28  Overflow condition code flag */
            uint32_t C : 1;           /*!< bit:     29  Carry condition code flag */
            uint32_t Z : 1;           /*!< bit:     30  Zero condition code flag */
            uint32_t N : 1;           /*!< bit:     31  Negative condition code flag */
        } b;                          /*!< Structure used for bit  access */
        uint32_t w;                   /*!< Type      used for word access */
    } xPSR_Type;
    typedef union
    {
        struct
        {
            uint32_t nPRIV : 1;       /*!< bit:      0  Execution privilege in Thread mode */
            uint32_t SPSEL : 1;       /*!< bit:      1  Stack to be used */
            uint32_t _reserved1 : 30; /*!< bit:  2..31  Reserved */
        } b;                          /*!< Structure used for bit  access */
        uint32_t w;                   /*!< Type      used for word access */
    } CONTROL_Type;
    typedef struct
    {
        __IOM uint32_t ISER[1U]; /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[31U];
        __IOM uint32_t ICER[1U]; /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[31U];
        __IOM uint32_t ISPR[1U]; /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[31U];
        __IOM uint32_t ICPR[1U]; /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
        __IOM uint32_t IP[8U]; /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
    } nvic_register_t;

    typedef struct
    {
        __IOM uint8_t enable : 1;
        __IOM uint8_t interrupt_enable : 1;
        __IOM uint8_t clock_source : 1;
        __IOM uint16_t reserved1 : 13;
        __IOM uint8_t overflow : 1;
        __IOM uint16_t reserved2 : 15;
    } systick_cr_register_flags_t;
    /**
      \brief  Structure type to access the System Control Block (SCB).
     */
    typedef struct
    {
        __IM uint32_t CPUID; /*!< Offset: 0x000 (R/ )  CPUID Base Register */
        __IOM uint32_t ICSR; /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
        uint32_t RESERVED0;
        __IOM uint32_t AIRCR; /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
        __IOM uint32_t SCR;   /*!< Offset: 0x010 (R/W)  System Control Register */
        __IOM uint32_t CCR;   /*!< Offset: 0x014 (R/W)  Configuration Control Register */
        uint32_t RESERVED1;
        __IOM uint32_t SHP[2U]; /*!< Offset: 0x01C (R/W)  System Handlers Priority Registers. [0] is RESERVED */
        __IOM uint32_t SHCSR;   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
    } scb_register_t;
    typedef struct
    {
        union
        {
            __IOM uint32_t CTRL; /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
            __IOM systick_cr_register_flags_t CTRL_f;
        };
        __IOM uint32_t LOAD; /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
        __IOM uint32_t VAL;  /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
        __IM uint32_t CALIB; /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
    } systick_register_t;
/* Memory mapping of Core Hardware */
#define SCS_BASE (0xE000E000UL)            /*!< System Control Space Base Address */
#define SysTick_BASE (SCS_BASE + 0x0010UL) /*!< SysTick Base Address */
#define NVIC_BASE (SCS_BASE + 0x0100UL)    /*!< NVIC Base Address */
#define SCB_BASE (SCS_BASE + 0x0D00UL)     /*!< System Control Block Base Address */

#define SCB ((scb_register_t *)SCB_BASE)             /*!< SCB configuration struct */
#define SysTick ((systick_register_t *)SysTick_BASE) /*!< SysTick configuration struct */
#define NVIC ((nvic_register_t *)NVIC_BASE)          /*!< NVIC configuration struct */

/**
  \brief   Instruction Synchronization Barrier
  \details Instruction Synchronization Barrier flushes the pipeline in the processor,
           so that all instructions following the ISB are fetched from cache or memory,
           after the instruction has been completed.
 */
#define __ISB() __asm volatile("isb 0xF" :: \
                                   : "memory")

/**
  \brief   Data Synchronization Barrier
  \details Acts as a special kind of Data Memory Barrier.
           It completes when all explicit memory accesses before this instruction complete.
 */
#define __DSB() __asm volatile("dsb 0xF" :: \
                                   : "memory")

/**
  \brief   Data Memory Barrier
  \details Ensures the apparent order of the explicit memory operations before
           and after the instruction, without ensuring their completion.
 */
#define _DMB() __asm volatile("dmb 0xF" :: \
                                  : "memory")

/**
  \brief   No Operation
  \details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
#define __NOP() __asm volatile("nop")

/**
  \brief   Wait For Interrupt
  \details Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.
 */
#define __WFI() __asm volatile("wfi")

/**
  \brief   Wait For Event
  \details Wait For Event is a hint instruction that permits the processor to enter
           a low-power state until one of a number of events occurs.
 */
#define __WFE() __asm volatile("wfe")

/**
  \brief   Send Event
  \details Send Event is a hint instruction. It causes an event to be signaled to the CPU.
 */
#define __SEV() __asm volatile("sev")

#define __FORCE_INLINE __attribute__((always_inline)) inline 

#ifdef __cplusplus
}
#endif

#endif
