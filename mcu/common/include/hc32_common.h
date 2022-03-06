/**
 *******************************************************************************
 * @file  hc32_common.h
 * @brief This file contains the common part of the HC32 series.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-04       Yangjp          First version
   2020-01-08       Wuze            Added compiler macro definitions for GCC.
   2020-01-20       Yangjp          Modify the macro definition of CLEAR_REG.
   2020-02-14       Zhangxl         Sync 'Compiler Macro Definitions' with other
                                    series.
   2020-02-17       Yangjp          Merge hc32l110, HC32F4A0, HC32M120, HC32M423
                                    series chips.
   2020-09-07       Yangjp          Add the precompiled configuration of ARM compiler V6
   2022-03-05       jbecker         adapted for hc32l110 series
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2016, Huada Semiconductor Co., Ltd. All rights reserved.
 *
 * This software is owned and published by:
 * Huada Semiconductor Co., Ltd. ("HDSC").
 *
 * BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
 * BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
 *
 * This software contains source code for use with HDSC
 * components. This software is licensed by HDSC to be adapted only
 * for use in systems utilizing HDSC components. HDSC shall not be
 * responsible for misuse or illegal use of this software for devices not
 * supported herein. HDSC is providing this software "AS IS" and will
 * not be responsible for issues arising from incorrect user implementation
 * of the software.common part.
 *
 * Disclaimer:
 * HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
 * REGARDING THE SOFTWARE (INCLUDING ANY ACCOMPANYING WRITTEN MATERIALS),
 * ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
 * WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
 * WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
 * WARRANTY OF NONINFRINGEMENT.
 * HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
 * NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
 * LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
 * INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
 * SAVINGS OR PROFITS,
 * EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
 * INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
 * FROM, THE SOFTWARE.
 *
 * This software may be replicated in part or whole for the licensed use,
 * with the restriction that this Disclaimer and Copyright notice must be
 * included with each copy of this software, whether used in part or whole,
 * at all times.
 *******************************************************************************
 */
#ifndef __HC32_COMMON_H__
#define __HC32_COMMON_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include <stddef.h>

#include <stdint.h>
/**
 * @addtogroup CMSIS
 * @{
 */

/**
 * @addtogroup HC32_Common_Part
 * @{
 */



/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup HC32_Common_Global_Types HC32 Common Global Types
 * @{
 */



/**
 * @brief Functional state
 */
typedef enum
{
    Disable = 0U,
    Enable  = 1U,
} en_functional_state_t;

/* Check if it is a functional state */
#define IS_FUNCTIONAL_STATE(state)      (((state) == Disable) || ((state) == Enable))

/**
 * @brief Flag status
 */
typedef enum
{
    Reset = 0U,
    Set   = 1U,
} en_flag_status_t, en_int_status_t;

/**
 * @brief Generic error codes
 */
typedef enum
{
    Ok                       = 0U,   /*!< No error */
    Error                    = 1U,   /*!< Non-specific error code */
    ErrorAddressAlignment    = 2U,   /*!< Address alignment does not match */
    ErrorAccessRights        = 3U,   /*!< Wrong mode (e.g. user/system) mode is set */
    ErrorInvalidParameter    = 4U,   /*!< Provided parameter is not valid */
    ErrorOperationInProgress = 5U,   /*!< A conflicting or requested operation is still in progress */
    ErrorInvalidMode         = 6U,   /*!< Operation not allowed in current mode */
    ErrorUninitialized       = 7U,   /*!< Module (or part of it) was not initialized properly */
    ErrorBufferFull          = 8U,   /*!< Circular buffer can not be written because the buffer is full */
    ErrorTimeout             = 9U,   /*!< Time Out error occurred (e.g. I2C arbitration lost, Flash time-out, etc.) */
    ErrorNotReady            = 10U,  /*!< A requested final state is not reached */
    OperationInProgress      = 11U,  /*!< Indicator for operation in progress (e.g. ADC conversion not finished, DMA channel used, etc.) */
} en_result_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup HC32_Common_Global_Macros HC32 Common Global Macros
 * @{
 */

/**
 * @brief Compiler Macro Definitions
 */
#ifndef __UNUSED
  #define __UNUSED                      __attribute__((unused))
#endif /* __UNUSED */

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #ifndef __WEAKDEF
    #define __WEAKDEF                   __attribute__((weak))
  #endif /* __WEAKDEF */
  #ifndef __ALIGN_BEGIN
    #define __ALIGN_BEGIN               __attribute__((aligned(4)))
  #endif /* __ALIGN_BEGIN */
  #ifndef __NOINLINE
    #define __NOINLINE                  __attribute__((noinline))
  #endif /* __NOINLINE */
  #ifndef __RAM_FUNC
    #define __RAM_FUNC                  __attribute__((long_call, section(".ramfunc")))
    /* Usage: void __RAM_FUNC foo(void) */
  #endif /* __RAM_FUNC */
  #ifndef __NO_INIT
    #define __NO_INIT
  #endif /* __NO_INIT */
#elif defined ( __GNUC__ ) && !defined (__CC_ARM) /*!< GNU Compiler */
  #ifndef __WEAKDEF
    #define __WEAKDEF                   __attribute__((weak))
  #endif /* __WEAKDEF */
  #ifndef __ALIGN_BEGIN
    #define __ALIGN_BEGIN               __attribute__((aligned (4)))
  #endif /* __ALIGN_BEGIN */
  #ifndef __NOINLINE
    #define __NOINLINE                  __attribute__((noinline))
  #endif /* __NOINLINE */
  #ifndef __RAM_FUNC
    #define __RAM_FUNC                  __attribute__((long_call, section(".ramfunc")))
    /* Usage: void __RAM_FUNC foo(void) */
  #endif /* __RAM_FUNC */
  #ifndef __NO_INIT
    #define __NO_INIT                   __attribute__((section(".noinit")))
  #endif /* __NO_INIT */
#elif defined (__ICCARM__)                /*!< IAR Compiler */
  #ifndef __WEAKDEF
    #define __WEAKDEF                   __weak
  #endif /* __WEAKDEF */
  #ifndef __ALIGN_BEGIN
    #define __ALIGN_BEGIN               _Pragma("data_alignment=4")
  #endif /* __ALIGN_BEGIN */
  #ifndef __NOINLINE
    #define __NOINLINE                  _Pragma("optimize = no_inline")
  #endif /* __NOINLINE */
  #ifndef __RAM_FUNC
    #define __RAM_FUNC                  __ramfunc
  #endif /* __RAM_FUNC */
#ifndef __NO_INIT
    #define __NO_INIT                   __no_init
#endif /* __NO_INIT */
#elif defined (__CC_ARM)                /*!< ARM Compiler */
  #ifndef __WEAKDEF
    #define __WEAKDEF                   __attribute__((weak))
  #endif /* __WEAKDEF */
  #ifndef __ALIGN_BEGIN
    #define __ALIGN_BEGIN               __align(4)
  #endif /* __ALIGN_BEGIN */
  #ifndef __NOINLINE
    #define __NOINLINE                  __attribute__((noinline))
  #endif /* __NOINLINE */
    /* RAM functions are defined using the toolchain options.
    Functions that are executed in RAM should reside in a separate source module.
    Using the 'Options for File' dialog you can simply change the 'Code / Const'
    area of a module to a memory space in physical RAM. */
    #define __RAM_FUNC
#else
    #error  "unsupported compiler!!"
#endif

/**
 * @defgroup Extend_Macro_Definitions Extend Macro Definitions
 * @{
 */
/* Decimal to BCD */
#define DEC2BCD(x)                      ((((x) / 10U) << 4U) + ((x) % 10U))

/* BCD to decimal */
#define BCD2DEC(x)                      ((((x) >> 4U) * 10U) + ((x) & 0x0FU))

/* Returns the dimension of an array */
#define ARRAY_SZ(x)                     ((sizeof(x)) / (sizeof((x)[0])))
/**
 * @}
 */

/**
 * @defgroup Address_Align Address Align
 * @{
 */
#define IS_ADDRESS_ALIGN(addr, align)   (0UL == (((uint32_t)(addr)) & (((uint32_t)(align)) - 1UL)))
#define IS_ADDRESS_ALIGN_HALFWORD(addr) (0UL == (((uint32_t)(addr)) & 0x1UL))
#define IS_ADDRESS_ALIGN_WORD(addr)     (0UL == (((uint32_t)(addr)) & 0x3UL))
/**
 * @}
 */

/**
 * @defgroup Register_Macro_Definitions Register Macro Definitions
 * @{
 */
#define RW_MEM8(addr)                   (*(volatile uint8_t *)(addr))
#define RW_MEM16(addr)                  (*(volatile uint16_t *)(addr))
#define RW_MEM32(addr)                  (*(volatile uint32_t *)(addr))

#define SET_REG8_BIT(REG, BIT)          ((REG) |= ((uint8_t)(BIT)))
#define SET_REG16_BIT(REG, BIT)         ((REG) |= ((uint16_t)(BIT)))
#define SET_REG32_BIT(REG, BIT)         ((REG) |= ((uint32_t)(BIT)))

#define CLEAR_REG8_BIT(REG, BIT)        ((REG) &= ((uint8_t)(~((uint8_t)(BIT)))))
#define CLEAR_REG16_BIT(REG, BIT)       ((REG) &= ((uint16_t)(~((uint16_t)(BIT)))))
#define CLEAR_REG32_BIT(REG, BIT)       ((REG) &= ((uint32_t)(~((uint32_t)(BIT)))))

#define READ_REG8_BIT(REG, BIT)         ((REG) & ((uint8_t)(BIT)))
#define READ_REG16_BIT(REG, BIT)        ((REG) & ((uint16_t)(BIT)))
#define READ_REG32_BIT(REG, BIT)        ((REG) & ((uint32_t)(BIT)))

#define CLEAR_REG8(REG)                 ((REG) = ((uint8_t)(0U)))
#define CLEAR_REG16(REG)                ((REG) = ((uint16_t)(0U)))
#define CLEAR_REG32(REG)                ((REG) = ((uint32_t)(0UL)))

#define WRITE_REG8(REG, VAL)            ((REG) = ((uint8_t)(VAL)))
#define WRITE_REG16(REG, VAL)           ((REG) = ((uint16_t)(VAL)))
#define WRITE_REG32(REG, VAL)           ((REG) = ((uint32_t)(VAL)))

#define READ_REG8(REG)                  (REG)
#define READ_REG16(REG)                 (REG)
#define READ_REG32(REG)                 (REG)

#define MODIFY_REG8(REGS, CLEARMASK, SETMASK)   (WRITE_REG8((REGS), (((READ_REG8((REGS))) & ((uint8_t)(~((uint8_t)(CLEARMASK))))) | ((uint8_t)(SETMASK) & (uint8_t)(CLEARMASK)))))
#define MODIFY_REG16(REGS, CLEARMASK, SETMASK)  (WRITE_REG16((REGS), (((READ_REG16((REGS))) & ((uint16_t)(~((uint16_t)(CLEARMASK))))) | ((uint16_t)(SETMASK) & (uint16_t)(CLEARMASK)))))
#define MODIFY_REG32(REGS, CLEARMASK, SETMASK)  (WRITE_REG32((REGS), (((READ_REG32((REGS))) & ((uint32_t)(~((uint32_t)(CLEARMASK))))) | ((uint32_t)(SETMASK) & (uint32_t)(CLEARMASK)))))


/**
 * @}
 */

/**
 * @defgroup Ddl_Config_Macro_Definitions Device Driver Library Config Macro definitions
 * @{
 */
/* Midware module on-off define */
#define MW_ON                                       (1u)
#define MW_OFF                                      (0u)
/* Chip module on-off define */
#define DDL_ON                                      (1u)
#define DDL_OFF                                     (0u)
/**
 * @}
 */
/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HC32_COMMON_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
