#ifndef __HC32L110_SYSTEM_REGISTERS_H__
#define __HC32L110_SYSTEM_REGISTERS_H__
#include <stdint.h>
typedef struct
{
    volatile uint32_t ISER[1U]; /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
    uint32_t RESERVED0[31U];
    volatile uint32_t ICER[1U]; /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
    uint32_t RESERVED1[31U];
    volatile uint32_t ISPR[1U]; /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
    uint32_t RESERVED2[31U];
    volatile uint32_t ICPR[1U]; /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
    uint32_t RESERVED3[31U];
    uint32_t RESERVED4[64U];
    volatile uint32_t IP[8U]; /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
} hc32_nvic_register_t;

typedef struct
{
    volatile const uint32_t CPUID; /*!< Offset: 0x000 (R/ )  CPUID Base Register */
    volatile uint32_t ICSR;        /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
    uint32_t RESERVED0;
    volatile uint32_t AIRCR; /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
    volatile uint32_t SCR;   /*!< Offset: 0x010 (R/W)  System Control Register */
    volatile uint32_t CCR;   /*!< Offset: 0x014 (R/W)  Configuration Control Register */
    uint32_t RESERVED1;
    volatile uint32_t SHP[2U]; /*!< Offset: 0x01C (R/W)  System Handlers Priority Registers. [0] is RESERVED */
    volatile uint32_t SHCSR;   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
} hc32_control_block_register_t;

typedef struct
{
  volatile uint8_t enabled : 1;
  volatile uint8_t interrupt_enabled : 1;
  volatile uint8_t clock_source : 2;
  uint16_t reserved1 : 12;
  volatile uint8_t counter_overflow : 1;
  uint16_t reserved2 : 16;
} systick_ctrl_flags_t;


typedef struct
{
  volatile uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  volatile uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  volatile const  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} hc32_systick_register_t;



#define NVIC_ADDRESS 0xE000E100UL
#define SYSTICK_ADDRESS 0xE000E010UL
#define CONTROL_BLOCK_ADDRESS 0xE000ED00UL 

#define HC32_CONTROL_BLOCK ((hc32_control_block_register_t *)CONTROL_BLOCK_ADDRESS) /*!< SCB configuration struct */
#define HC32_NVIC ((hc32_nvic_register_t *)NVIC_ADDRESS)
#define HC32_SYSTICK ((hc32_systick_register_t *)SYSTICK_ADDRESS)

#define __nop() __asm volatile ("nop")
#define __wfi() __asm volatile ("wfi":::"memory")
#define data_barrier() __asm volatile ("dsb 0xF":::"memory")
#define instruction_barrier() __asm volatile ("isb 0xF":::"memory")
#define __weak __attribute__((weak))
#endif