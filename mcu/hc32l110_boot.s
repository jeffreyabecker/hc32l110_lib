
    .syntax unified
    .arch armv6-m
    .section .stack
    .align 3    
    .section .vectors
    .align 2
    .global __isr_vector
__isr_vector:
    .long   __StackTop                  /* Top of Stack */
    .long Reset_Handler
    .long NMI_Handler
    .long HardFault_Handler
    .long 0 /* Reserved for higher ARM versions*/
    .long 0 /* Reserved for higher ARM versions*/
    .long 0 /* Reserved for higher ARM versions*/
    .long 0 /* Reserved for higher ARM versions*/
    .long 0 /* Reserved for higher ARM versions*/
    .long 0 /* Reserved for higher ARM versions*/
    .long 0 /* Reserved for higher ARM versions*/
    .long SVC_Handler
    .long 0 /* Reserved for higher ARM versions*/
    .long 0 /* Reserved for higher ARM versions*/
    .long PendSV_Handler
    .long SysTick_Handler
    .long GpioPort0_Handler
    .long GpioPort1_Handler
    .long GpioPort2_Handler
    .long GpioPort3_Handler
    .long UserInterrupt0_Handler
    .long UserInterrupt1_Handler
    .long Uart0_Handler
    .long Uart1_Handler
    .long LpUart_Handler
    .long UserInterrupt2_Handler
    .long SPI_Handler
    .long UserInterrupt3_Handler
    .long I2C_Handler
    .long UserInterrupt4_Handler
    .long Timer0_Handler
    .long Timer1_Handler
    .long Timer2_Handler
    .long LpTimer_Handler
    .long Timer4_Handler
    .long Timer5_Handler
    .long Timer6_Handler
    .long PCA_Handler
    .long WatchDogTimer_Handler
    .long RTC_Handler
    .long ADC_Handler
    .long UserInterrupt5_Handler
    .long VC0_Handler
    .long VC1_Handler
    .long LVD_Handler
    .long UserInterrupt6_Handler
    .long EfRam_Handler
    .long ClockTrim_Handler    
    .size __isr_vector, . - __isr_vector

/* Reset Handler */    
    .text
    .thumb
    .thumb_func
    .align 1
    .equ INITIAL_CLOCK_FREQUENCY, 0x003D0900 
    .equ INITIAL_CLOCK_TRIM_ADDRESS, 0x00100C08
    .equ HCL_CLOCK_TRIM_REGISTER_ADDRESS, 0x4000200C
    .global SystemCoreClock
    .size SystemCoreClock, 4
    .type SystemCoreClock, %object
    .global PeripheralCoreClock
    .size PeripheralCoreClock, 4
    .type PeripheralCoreClock, %object
    .global Reset_Handler
    .type Reset_Handler, %function
Reset_Handler:
    /*reset NVIC if in rom debug*/
    ldr     R0, =0x20000000
    ldr     R2, =0x0
    movs    R1, #0                 
    add     R1, PC,#0             
    cmp     R1, R0
    bls     RamCode

    /* ram code base address.*/  
    add     R2, R0,R2
RamCode: 
    /* ; reset Vector table address.*/
    ldr     R0, =0xE000ED08 
    str     R2, [R0]

    /* begin systeminit */
    /* at this point other boot code invokes SystemInit and __main to do the following */
    /* set a stable clock frequency */  
    ldr r0, =INITIAL_CLOCK_FREQUENCY
    ldr r1, =SystemCoreClock
    ldr r2, =PeripheralCoreClock
    str r0, [r1]
    str r0, [r2]
    ldr r0, =INITIAL_CLOCK_TRIM_ADDRESS
    ldr r1, =HCL_CLOCK_TRIM_REGISTER_ADDRESS
    ldr r2, [r0]
    str r2, [r1]
/* initialize static ram values */  
    ldr r1, =__etext
    ldr r2, =__data_start__
    ldr r3, =__data_end__

    subs r3, r3, r2
    ble .L_data_init_exit

.L_data_init:
    subs r3, r3, #4
    ldr r0, [r1,r3]
    str r0, [r2,r3]
    bgt .L_data_init

.L_data_init_exit:

    ldr r1, =__bss_start__
    ldr r2, =__bss_end__

    movs r0, 0

    subs r2, r2, r1 
    ble .L_zero_table_exit 

.L_zero_table:
    subs r2, r2, #4 
    str r0, [r1, r2] 
    bgt .L_zero_table

.L_zero_table_exit:    
/* end systeminit */

    ldr     R0, = main
    bx      R0

    .weak   NMI_Handler
    .type   NMI_Handler, %function
NMI_Handler:
    b       .
    .size   NMI_Handler, . - NMI_Handler

    .weak   HardFault_Handler
    .type   HardFault_Handler, %function
HardFault_Handler:
    b       .
    .size   HardFault_Handler, . - HardFault_Handler

SVC_Handler:
    b       .
    .size   SVC_Handler, . - SVC_Handler
    .weak   PendSV_Handler
    .type   PendSV_Handler, %function
PendSV_Handler:
    b       .
    .size   PendSV_Handler, . - PendSV_Handler
    .weak   SysTick_Handler
    .type   SysTick_Handler, %function
SysTick_Handler:
    b       .
    .size   SysTick_Handler, . - SysTick_Handler
    .weak   GpioPort0_Handler
    .type   GpioPort0_Handler, %function

    .global  Default_Handler
    .type   Default_Handler, %function
Default_Handler:
    b       .
    .size   Default_Handler, . - Default_Handler

    .weak GpioPort0_Handler
    .set GpioPort0_Handler, Default_Handler

    .weak GpioPort1_Handler
    .set GpioPort1_Handler, Default_Handler

    .weak GpioPort2_Handler
    .set GpioPort2_Handler, Default_Handler

    .weak GpioPort3_Handler
    .set GpioPort3_Handler, Default_Handler

    .weak UserInterrupt0_Handler
    .set UserInterrupt0_Handler, Default_Handler

    .weak UserInterrupt1_Handler
    .set UserInterrupt1_Handler, Default_Handler

    .weak Uart0_Handler
    .set Uart0_Handler, Default_Handler

    .weak Uart1_Handler
    .set Uart1_Handler, Default_Handler

    .weak LpUart_Handler
    .set LpUart_Handler, Default_Handler

    .weak UserInterrupt2_Handler
    .set UserInterrupt2_Handler, Default_Handler

    .weak SPI_Handler
    .set SPI_Handler, Default_Handler

    .weak UserInterrupt3_Handler
    .set UserInterrupt3_Handler, Default_Handler

    .weak I2C_Handler
    .set I2C_Handler, Default_Handler

    .weak UserInterrupt4_Handler
    .set UserInterrupt4_Handler, Default_Handler

    .weak Timer0_Handler
    .set Timer0_Handler, Default_Handler

    .weak Timer1_Handler
    .set Timer1_Handler, Default_Handler

    .weak Timer2_Handler
    .set Timer2_Handler, Default_Handler

    .weak LpTimer_Handler
    .set LpTimer_Handler, Default_Handler

    .weak Timer4_Handler
    .set Timer4_Handler, Default_Handler

    .weak Timer5_Handler
    .set Timer5_Handler, Default_Handler

    .weak Timer6_Handler
    .set Timer6_Handler, Default_Handler

    .weak PCA_Handler
    .set PCA_Handler, Default_Handler

    .weak WatchDogTimer_Handler
    .set WatchDogTimer_Handler, Default_Handler

    .weak RTC_Handler
    .set RTC_Handler, Default_Handler

    .weak ADC_Handler
    .set ADC_Handler, Default_Handler

    .weak UserInterrupt5_Handler
    .set UserInterrupt5_Handler, Default_Handler

    .weak VC0_Handler
    .set VC0_Handler, Default_Handler

    .weak VC1_Handler
    .set VC1_Handler, Default_Handler

    .weak LVD_Handler
    .set LVD_Handler, Default_Handler

    .weak UserInterrupt6_Handler
    .set UserInterrupt6_Handler, Default_Handler

    .weak EfRam_Handler
    .set EfRam_Handler, Default_Handler

    .weak ClockTrim_Handler
    .set ClockTrim_Handler, Default_Handler


/* Runtime ABI for the ARM Cortex-M0  
 * idivmod.S: signed 32 bit division (quotient and remainder)
 *
 * Copyright (c) 2012 Jörg Mische <bobbl@gmx.de>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


@ {int quotient:r0, int remainder:r1}
@ __aeabi_idivmod(int numerator:r0, int denominator:r1)
@
@ Divide r0 by r1 and return the quotient in r0 and the remainder in r1
@
	.thumb_func
        .global __aeabi_idivmod
__aeabi_idivmod:

	cmp	r0, #0
	bge	.Lnumerator_pos
	rsbs	r0, r0, #0		@ num = -num
	cmp	r1, #0
	bge	.Lboth_neg

	rsbs	r1, r1, #0		@ den = -den
	push	{lr}
	bl	__aeabi_uidivmod
	rsbs	r1, r1, #0		@ rem = -rem
	pop	{pc}

.Lboth_neg:
	push	{lr}
	bl	__aeabi_uidivmod
	rsbs	r0, r0, #0		@ quot = -quot
	rsbs	r1, r1, #0		@ rem = -rem
	pop	{pc}

.Lnumerator_pos:
	cmp	r1, #0
	bge	.Luidivmod

	rsbs	r1, r1, #0		@ den = -den
	push	{lr}
	bl	__aeabi_uidivmod
	rsbs	r0, r0, #0		@ quot = -quot
	pop	{pc}





@ unsigned __udivsi3(unsigned num, unsigned denom)
@
@ libgcc wrapper: just an alias for __aeabi_uidivmod(), the remainder is ignored
@
	.thumb_func
        .global __udivsi3
__udivsi3:



@ unsigned __aeabi_uidiv(unsigned num, unsigned denom)
@
@ Just an alias for __aeabi_uidivmod(), the remainder is ignored
@
	.thumb_func
        .global __aeabi_uidiv
__aeabi_uidiv:



@ {unsigned quotient:r0, unsigned remainder:r1}
@  __aeabi_uidivmod(unsigned numerator:r0, unsigned denominator:r1)
@
@ Divide r0 by r1 and return the quotient in r0 and the remainder in r1
@
	.thumb_func
        .global __aeabi_uidivmod
__aeabi_uidivmod:



.Luidivmod:
	cmp	r1, #0
	bne	1f
	b	__aeabi_idiv0
1:

	@ Shift left the denominator until it is greater than the numerator
	movs	r2, #1		@ counter
	movs	r3, #0		@ result
	cmp	r0, r1
	bls	.Lsub_loop
	adds	r1, #0		@ dont shift if denominator would overflow
	bmi	.Lsub_loop

.Ldenom_shift_loop:
	lsls	r2, #1
	lsls	r1, #1
	bmi	.Lsub_loop
	cmp	r0, r1
	bhi	.Ldenom_shift_loop

.Lsub_loop:	
	cmp	r0, r1
	bcc	.Ldont_sub	@ if (num>denom)

	subs	r0, r1		@ numerator -= denom
	orrs	r3, r2		@ result(r3) |= bitmask(r2)
.Ldont_sub:

	lsrs	r1, #1		@ denom(r1) >>= 1
	lsrs	r2, #1		@ bitmask(r2) >>= 1
	bne	.Lsub_loop

	mov	r1, r0		@ remainder(r1) = numerator(r0)
	mov	r0, r3		@ quotient(r0) = result(r3)
	bx	lr
