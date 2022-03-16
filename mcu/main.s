	.cpu cortex-m0
	.arch armv6s-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.global	default_system_config
	.section	.rodata,"a"
	.align	2
	.type	default_system_config, %object
	.size	default_system_config, 12
default_system_config:
	.byte	128
	.space	3
	.word	4000000
	.word	100000
	.text
	.align	1
	.syntax unified
	.code	16
	.thumb_func
	.type	core_peripheral_set_enabled, %function
core_peripheral_set_enabled:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	str	r0, [r7, #4]
	ldr	r3, .L2
	ldr	r2, [r7, #4]
	str	r2, [r3, #32]
	nop
	mov	sp, r7
	add	sp, sp, #8
	@ sp needed
	pop	{r7, pc}
.L3:
	.align	2
.L2:
	.word	1073750016
	.size	core_peripheral_set_enabled, .-core_peripheral_set_enabled
	.align	1
	.syntax unified
	.code	16
	.thumb_func
	.type	core_peripheral_get_enabled, %function
core_peripheral_get_enabled:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r3, .L6
	ldr	r3, [r3, #32]
	movs	r0, r3
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L7:
	.align	2
.L6:
	.word	1073750016
	.size	core_peripheral_get_enabled, .-core_peripheral_get_enabled
	.bss
	.align	2
tick_increment_step:
	.space	4
	.size	tick_increment_step, 4
	.align	2
current_tick_count:
	.space	4
	.size	current_tick_count, 4
	.text
	.align	1
	.global	core_system_reset
	.syntax unified
	.code	16
	.thumb_func
	.type	core_system_reset, %function
core_system_reset:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	.syntax divided
@ 240 "C:\ode\hc32l110\lib\include/hc32l110_ddl_core.h" 1
	dsb 0xF
@ 0 "" 2
	.thumb
	.syntax unified
	ldr	r3, .L10
	ldr	r2, .L10+4
	str	r2, [r3, #12]
	.syntax divided
@ 243 "C:\ode\hc32l110\lib\include/hc32l110_ddl_core.h" 1
	dsb 0xF
@ 0 "" 2
	.thumb
	.syntax unified
.L9:
	.syntax divided
@ 247 "C:\ode\hc32l110\lib\include/hc32l110_ddl_core.h" 1
	nop
@ 0 "" 2
	.thumb
	.syntax unified
	b	.L9
.L11:
	.align	2
.L10:
	.word	-536810240
	.word	100270084
	.size	core_system_reset, .-core_system_reset
	.global	__aeabi_uidiv
	.align	1
	.global	__core_calculate_clock_trim
	.syntax unified
	.code	16
	.thumb_func
	.type	__core_calculate_clock_trim, %function
__core_calculate_clock_trim:
	@ args = 0, pretend = 0, frame = 120
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, r7, lr}
	sub	sp, sp, #124
	add	r7, sp, #0
	adds	r3, r7, #4
	str	r0, [r3]
	str	r1, [r3, #4]
	str	r2, [r3, #8]
	adds	r3, r7, #4
	ldrb	r3, [r3]
	movs	r2, #3
	ands	r3, r2
	uxtb	r3, r3
	cmp	r3, #0
	beq	.LCB93
	b	.L13	@long jump
.LCB93:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32
	cmp	r3, r2
	bhi	.L14
	ldr	r3, .L32+4
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, #250
	lsls	r2, r2, #2
	muls	r3, r2
	uxth	r2, r3
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	uxth	r3, r3
	adds	r1, r3, #0
	lsls	r1, r1, #3
	subs	r1, r1, r3
	lsls	r1, r1, #2
	adds	r3, r1, r3
	adds	r1, r3, #0
	lsls	r1, r1, #5
	subs	r3, r1, r3
	lsls	r3, r3, #6
	uxth	r3, r3
	subs	r3, r2, r3
	uxth	r3, r3
	ldr	r2, .L32+8
	mov	ip, r2
	add	r3, r3, ip
	uxth	r3, r3
	b	.L15
.L14:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32
	cmp	r3, r2
	bhi	.LCB133
	b	.L16	@long jump
.LCB133:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+12
	cmp	r3, r2
	bls	.LCB138
	b	.L16	@long jump
.LCB138:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+16
	cmp	r3, r2
	bne	.L17
	ldr	r3, .L32+4
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, #250
	lsls	r2, r2, #2
	muls	r3, r2
	uxth	r3, r3
	b	.L15
.L17:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+20
	cmp	r3, r2
	bhi	.L18
	adds	r3, r7, #4
	ldr	r1, [r3, #4]
	ldr	r3, .L32+4
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r0, r3
	ldr	r3, .L32+24
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r2, r3
	str	r1, [r7, #116]
	ldr	r3, .L32+16
	str	r3, [r7, #112]
	ldr	r3, .L32+28
	str	r3, [r7, #108]
	str	r0, [r7, #104]
	str	r2, [r7, #100]
	ldr	r2, [r7, #116]
	ldr	r3, [r7, #112]
	subs	r4, r2, r3
	ldr	r2, [r7, #100]
	ldr	r3, [r7, #104]
	subs	r0, r2, r3
	ldr	r2, [r7, #108]
	ldr	r3, [r7, #112]
	subs	r3, r2, r3
	movs	r1, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	muls	r3, r4
	movs	r2, r3
	ldr	r3, [r7, #104]
	adds	r3, r2, r3
	movs	r2, #250
	lsls	r1, r2, #2
	movs	r0, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	uxth	r3, r3
	b	.L15
.L18:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+28
	cmp	r3, r2
	bne	.L20
	ldr	r3, .L32+24
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, #250
	lsls	r2, r2, #2
	muls	r3, r2
	uxth	r3, r3
	b	.L15
.L20:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+32
	cmp	r3, r2
	bhi	.L21
	adds	r3, r7, #4
	ldr	r1, [r3, #4]
	ldr	r3, .L32+24
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r0, r3
	ldr	r3, .L32+36
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r2, r3
	str	r1, [r7, #96]
	ldr	r3, .L32+28
	str	r3, [r7, #92]
	ldr	r3, .L32+40
	str	r3, [r7, #88]
	str	r0, [r7, #84]
	str	r2, [r7, #80]
	ldr	r2, [r7, #96]
	ldr	r3, [r7, #92]
	subs	r4, r2, r3
	ldr	r2, [r7, #80]
	ldr	r3, [r7, #84]
	subs	r0, r2, r3
	ldr	r2, [r7, #88]
	ldr	r3, [r7, #92]
	subs	r3, r2, r3
	movs	r1, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	muls	r3, r4
	movs	r2, r3
	ldr	r3, [r7, #84]
	adds	r3, r2, r3
	movs	r2, #250
	lsls	r1, r2, #2
	movs	r0, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	uxth	r3, r3
	b	.L15
.L21:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+40
	cmp	r3, r2
	bne	.L23
	ldr	r3, .L32+36
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, #250
	lsls	r2, r2, #2
	muls	r3, r2
	uxth	r3, r3
	b	.L15
.L23:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+44
	cmp	r3, r2
	bhi	.L24
	adds	r3, r7, #4
	ldr	r1, [r3, #4]
	ldr	r3, .L32+36
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r0, r3
	ldr	r3, .L32+48
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r2, r3
	str	r1, [r7, #76]
	ldr	r3, .L32+40
	str	r3, [r7, #72]
	ldr	r3, .L32+52
	str	r3, [r7, #68]
	str	r0, [r7, #64]
	str	r2, [r7, #60]
	ldr	r2, [r7, #76]
	ldr	r3, [r7, #72]
	subs	r4, r2, r3
	ldr	r2, [r7, #60]
	ldr	r3, [r7, #64]
	subs	r0, r2, r3
	ldr	r2, [r7, #68]
	ldr	r3, [r7, #72]
	subs	r3, r2, r3
	movs	r1, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	muls	r3, r4
	movs	r2, r3
	ldr	r3, [r7, #64]
	adds	r3, r2, r3
	movs	r2, #250
	lsls	r1, r2, #2
	movs	r0, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	uxth	r3, r3
	b	.L15
.L24:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+52
	cmp	r3, r2
	bne	.L26
	ldr	r3, .L32+48
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, #250
	lsls	r2, r2, #2
	muls	r3, r2
	uxth	r3, r3
	b	.L15
.L26:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+56
	cmp	r3, r2
	bhi	.L27
	adds	r3, r7, #4
	ldr	r1, [r3, #4]
	ldr	r3, .L32+48
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r0, r3
	ldr	r3, .L32+60
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r2, r3
	str	r1, [r7, #56]
	ldr	r3, .L32+52
	str	r3, [r7, #52]
	ldr	r3, .L32+12
	str	r3, [r7, #48]
	str	r0, [r7, #44]
	str	r2, [r7, #40]
	ldr	r2, [r7, #56]
	ldr	r3, [r7, #52]
	subs	r4, r2, r3
	ldr	r2, [r7, #40]
	ldr	r3, [r7, #44]
	subs	r0, r2, r3
	ldr	r2, [r7, #48]
	ldr	r3, [r7, #52]
	subs	r3, r2, r3
	movs	r1, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	muls	r3, r4
	movs	r2, r3
	ldr	r3, [r7, #44]
	adds	r3, r2, r3
	movs	r2, #250
	lsls	r1, r2, #2
	movs	r0, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	uxth	r3, r3
	b	.L15
.L27:
	ldr	r3, .L32+48
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, #250
	lsls	r2, r2, #2
	muls	r3, r2
	uxth	r3, r3
	b	.L15
.L13:
	adds	r3, r7, #4
	ldrb	r3, [r3]
	movs	r2, #3
	ands	r3, r2
	uxtb	r3, r3
	cmp	r3, #2
	beq	.LCB468
	b	.L16	@long jump
.LCB468:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L32+64
	cmp	r3, r2
	bne	.L29
	ldr	r3, .L32+68
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, #250
	lsls	r2, r2, #2
	muls	r3, r2
	uxth	r3, r3
	b	.L15
.L29:
	adds	r3, r7, #4
	ldr	r2, [r3, #4]
	movs	r3, #150
	lsls	r3, r3, #8
	cmp	r2, r3
	bne	.L30
	ldr	r3, .L32+72
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, #250
	lsls	r2, r2, #2
	muls	r3, r2
	uxth	r3, r3
	b	.L15
.L33:
	.align	2
.L32:
	.word	3999999
	.word	1051656
	.word	-16384
	.word	24000000
	.word	4000000
	.word	7999999
	.word	1051654
	.word	8000000
	.word	15999999
	.word	1051652
	.word	16000000
	.word	22119999
	.word	1051650
	.word	22120000
	.word	23999999
	.word	1051648
	.word	32800
	.word	1051682
	.word	1051680
.L30:
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	ldr	r2, .L34
	cmp	r3, r2
	bls	.L16
	adds	r3, r7, #4
	ldr	r2, [r3, #4]
	movs	r3, #150
	lsls	r3, r3, #8
	cmp	r2, r3
	bcs	.L16
	adds	r3, r7, #4
	ldr	r1, [r3, #4]
	ldr	r3, .L34+4
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r0, r3
	ldr	r3, .L34+4
	ldrh	r3, [r3]
	uxth	r3, r3
	movs	r2, r3
	movs	r3, r2
	lsls	r3, r3, #5
	subs	r3, r3, r2
	lsls	r3, r3, #2
	adds	r3, r3, r2
	lsls	r3, r3, #3
	movs	r2, r3
	str	r1, [r7, #36]
	ldr	r3, .L34
	str	r3, [r7, #32]
	movs	r3, #150
	lsls	r3, r3, #8
	str	r3, [r7, #28]
	str	r0, [r7, #24]
	str	r2, [r7, #20]
	ldr	r2, [r7, #36]
	ldr	r3, [r7, #32]
	subs	r4, r2, r3
	ldr	r2, [r7, #20]
	ldr	r3, [r7, #24]
	subs	r0, r2, r3
	ldr	r2, [r7, #28]
	ldr	r3, [r7, #32]
	subs	r3, r2, r3
	movs	r1, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	muls	r3, r4
	movs	r2, r3
	ldr	r3, [r7, #24]
	adds	r3, r2, r3
	movs	r2, #250
	lsls	r1, r2, #2
	movs	r0, r3
	bl	__aeabi_uidiv
	movs	r3, r0
	uxth	r3, r3
	b	.L15
.L16:
	movs	r3, #0
.L15:
	movs	r0, r3
	mov	sp, r7
	add	sp, sp, #124
	@ sp needed
	pop	{r4, r7, pc}
.L35:
	.align	2
.L34:
	.word	32800
	.word	1051682
	.size	__core_calculate_clock_trim, .-__core_calculate_clock_trim
	.align	1
	.global	core_system_clock_config
	.syntax unified
	.code	16
	.thumb_func
	.type	core_system_clock_config, %function
core_system_clock_config:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, r7, lr}
	sub	sp, sp, #28
	add	r7, sp, #0
	adds	r3, r7, #4
	str	r0, [r3]
	str	r1, [r3, #4]
	str	r2, [r3, #8]
	movs	r3, #22
	adds	r4, r7, r3
	adds	r3, r7, #4
	ldr	r0, [r3]
	ldr	r1, [r3, #4]
	ldr	r2, [r3, #8]
	bl	__core_calculate_clock_trim
	movs	r3, r0
	strh	r3, [r4]
	ldr	r3, .L50
	ldr	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #30
	uxtb	r2, r3
	adds	r3, r7, #4
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #30
	uxtb	r3, r3
	cmp	r2, r3
	bne	.LCB648
	b	.L37	@long jump
.LCB648:
	adds	r3, r7, #4
	ldrb	r3, [r3]
	movs	r2, #3
	ands	r3, r2
	uxtb	r3, r3
	cmp	r3, #3
	bne	.L38
	ldr	r1, .L50+4
	movs	r3, #160
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r0, #16
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L50+4
	movs	r3, #160
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r0, #32
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrb	r2, [r3, #24]
	movs	r1, #48
	orrs	r2, r1
	strb	r2, [r3, #24]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #8
	orrs	r2, r1
	strh	r2, [r3]
	nop
.L39:
	ldr	r3, .L50
	ldr	r3, [r3, #24]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r3, r3
	cmp	r3, #1
	bne	.L39
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	adds	r2, r7, #4
	ldrb	r2, [r2]
	lsls	r2, r2, #30
	lsrs	r2, r2, #30
	uxtb	r2, r2
	adds	r1, r2, #0
	movs	r2, #3
	ands	r2, r1
	lsls	r0, r2, #4
	ldrh	r2, [r3]
	movs	r1, #48
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	strh	r2, [r3]
.L38:
	adds	r3, r7, #4
	ldrb	r3, [r3]
	movs	r2, #3
	ands	r3, r2
	uxtb	r3, r3
	cmp	r3, #1
	bne	.L40
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrb	r2, [r3, #16]
	movs	r1, #48
	orrs	r2, r1
	strb	r2, [r3, #16]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #2
	orrs	r2, r1
	strh	r2, [r3]
	nop
.L41:
	ldr	r3, .L50
	ldr	r3, [r3, #16]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r3, r3
	cmp	r3, #1
	bne	.L41
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	adds	r2, r7, #4
	ldrb	r2, [r2]
	lsls	r2, r2, #30
	lsrs	r2, r2, #30
	uxtb	r2, r2
	adds	r1, r2, #0
	movs	r2, #3
	ands	r2, r1
	lsls	r0, r2, #4
	ldrh	r2, [r3]
	movs	r1, #48
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	strh	r2, [r3]
.L40:
	adds	r3, r7, #4
	ldrb	r3, [r3]
	movs	r2, #3
	ands	r3, r2
	uxtb	r3, r3
	cmp	r3, #2
	bne	.L42
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	movs	r2, #22
	adds	r2, r7, r2
	ldrh	r2, [r2]
	lsls	r2, r2, #22
	lsrs	r2, r2, #22
	uxth	r2, r2
	lsls	r2, r2, #22
	lsrs	r0, r2, #22
	ldrh	r2, [r3, #20]
	lsrs	r2, r2, #10
	lsls	r2, r2, #10
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3, #20]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3, #20]
	movs	r1, #192
	lsls	r1, r1, #4
	orrs	r2, r1
	strh	r2, [r3, #20]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #4
	orrs	r2, r1
	strh	r2, [r3]
	nop
.L43:
	ldr	r3, .L50
	ldr	r3, [r3, #20]
	lsls	r3, r3, #19
	lsrs	r3, r3, #31
	uxtb	r3, r3
	cmp	r3, #1
	bne	.L43
	ldr	r3, .L50
	adds	r2, r7, #4
	ldrb	r2, [r2]
	lsls	r2, r2, #30
	lsrs	r2, r2, #30
	uxtb	r2, r2
	adds	r1, r2, #0
	movs	r2, #3
	ands	r2, r1
	lsls	r0, r2, #4
	ldrh	r2, [r3]
	movs	r1, #48
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	strh	r2, [r3]
.L42:
	adds	r3, r7, #4
	ldrb	r3, [r3]
	movs	r2, #3
	ands	r3, r2
	uxtb	r3, r3
	cmp	r3, #0
	bne	.L37
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	movs	r2, #22
	adds	r2, r7, r2
	ldrh	r2, [r2]
	lsls	r2, r2, #21
	lsrs	r2, r2, #21
	uxth	r2, r2
	lsls	r2, r2, #21
	lsrs	r0, r2, #21
	ldrh	r2, [r3, #12]
	lsrs	r2, r2, #11
	lsls	r2, r2, #11
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3, #12]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #1
	orrs	r2, r1
	strh	r2, [r3]
	nop
.L44:
	ldr	r3, .L50
	ldr	r3, [r3, #12]
	lsls	r3, r3, #20
	lsrs	r3, r3, #31
	uxtb	r3, r3
	cmp	r3, #1
	bne	.L44
	ldr	r3, .L50
	adds	r2, r7, #4
	ldrb	r2, [r2]
	lsls	r2, r2, #30
	lsrs	r2, r2, #30
	uxtb	r2, r2
	adds	r1, r2, #0
	movs	r2, #3
	ands	r2, r1
	lsls	r0, r2, #4
	ldrh	r2, [r3]
	movs	r1, #48
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	strh	r2, [r3]
	ldr	r3, .L50
	ldr	r2, .L50+8
	str	r2, [r3, #8]
	ldr	r3, .L50
	ldr	r2, .L50+12
	str	r2, [r3, #8]
	nop
	ldr	r3, .L50
	ldrh	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	strh	r2, [r3]
.L37:
	ldr	r3, .L50
	ldr	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L45
	ldr	r3, .L50
	ldr	r3, [r3, #12]
	lsls	r3, r3, #21
	lsrs	r3, r3, #21
	uxth	r3, r3
	movs	r2, r3
	movs	r1, #22
	adds	r3, r7, r1
	ldrh	r3, [r3]
	b	.L51
.L52:
	.align	2
.L50:
	.word	1073750016
	.word	1073875968
	.word	23130
	.word	42405
.L51:
	cmp	r3, r2
	beq	.L45
	ldr	r3, .L53
	ldr	r2, .L53+4
	str	r2, [r3, #8]
	ldr	r3, .L53
	ldr	r2, .L53+8
	str	r2, [r3, #8]
	nop
	ldr	r3, .L53
	adds	r2, r7, r1
	ldrh	r2, [r2]
	lsls	r2, r2, #21
	lsrs	r2, r2, #21
	uxth	r2, r2
	lsls	r2, r2, #21
	lsrs	r0, r2, #21
	ldrh	r2, [r3, #12]
	lsrs	r2, r2, #11
	lsls	r2, r2, #11
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3, #12]
.L45:
	ldr	r3, .L53
	ldr	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L46
	ldr	r3, .L53
	ldr	r3, [r3, #20]
	lsls	r3, r3, #22
	lsrs	r3, r3, #22
	uxth	r3, r3
	movs	r2, r3
	movs	r1, #22
	adds	r3, r7, r1
	ldrh	r3, [r3]
	cmp	r3, r2
	beq	.L46
	ldr	r3, .L53
	ldr	r2, .L53+4
	str	r2, [r3, #8]
	ldr	r3, .L53
	ldr	r2, .L53+8
	str	r2, [r3, #8]
	nop
	ldr	r3, .L53
	adds	r2, r7, r1
	ldrh	r2, [r2]
	lsls	r2, r2, #22
	lsrs	r2, r2, #22
	uxth	r2, r2
	lsls	r2, r2, #22
	lsrs	r0, r2, #22
	ldrh	r2, [r3, #20]
	lsrs	r2, r2, #10
	lsls	r2, r2, #10
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3, #20]
.L46:
	ldr	r3, .L53
	ldr	r2, .L53+4
	str	r2, [r3, #8]
	ldr	r3, .L53
	ldr	r2, .L53+8
	str	r2, [r3, #8]
	nop
	ldr	r3, .L53
	adds	r2, r7, #4
	ldrb	r2, [r2]
	lsls	r2, r2, #27
	lsrs	r2, r2, #29
	uxtb	r2, r2
	adds	r1, r2, #0
	movs	r2, #7
	ands	r2, r1
	lsls	r0, r2, #6
	ldrh	r2, [r3]
	ldr	r1, .L53+12
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3]
	ldr	r3, .L53
	ldr	r2, .L53+4
	str	r2, [r3, #8]
	ldr	r3, .L53
	ldr	r2, .L53+8
	str	r2, [r3, #8]
	nop
	ldr	r3, .L53
	adds	r2, r7, #4
	ldrb	r2, [r2]
	lsls	r2, r2, #25
	lsrs	r2, r2, #30
	uxtb	r2, r2
	adds	r1, r2, #0
	movs	r2, #3
	ands	r2, r1
	lsls	r0, r2, #9
	ldrh	r2, [r3]
	ldr	r1, .L53+16
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strh	r2, [r3]
	adds	r3, r7, #4
	ldr	r3, [r3, #4]
	adds	r2, r7, #4
	ldrb	r2, [r2]
	lsls	r2, r2, #27
	lsrs	r2, r2, #29
	uxtb	r2, r2
	lsrs	r3, r3, r2
	movs	r2, r3
	ldr	r3, .L53+20
	str	r2, [r3]
	ldr	r3, .L53+20
	ldr	r3, [r3]
	adds	r2, r7, #4
	ldrb	r2, [r2]
	lsls	r2, r2, #25
	lsrs	r2, r2, #30
	uxtb	r2, r2
	lsrs	r3, r3, r2
	movs	r2, r3
	ldr	r3, .L53+24
	str	r2, [r3]
	adds	r3, r7, #4
	ldrb	r3, [r3]
	movs	r2, #127
	bics	r3, r2
	uxtb	r3, r3
	cmp	r3, #0
	beq	.L36
	bl	core_peripheral_get_enabled
	movs	r2, r0
	movs	r3, #128
	lsls	r3, r3, #17
	orrs	r3, r2
	movs	r0, r3
	bl	core_peripheral_set_enabled
	ldr	r3, .L53+24
	ldr	r2, [r3]
	adds	r3, r7, #4
	ldr	r3, [r3, #8]
	movs	r1, r3
	movs	r0, r2
	bl	__aeabi_uidiv
	movs	r3, r0
	str	r3, [r7, #16]
	ldr	r3, [r7, #16]
	subs	r2, r3, #1
	movs	r3, #128
	lsls	r3, r3, #17
	cmp	r2, r3
	bcs	.L49
	ldr	r3, .L53+28
	ldr	r2, [r7, #16]
	subs	r2, r2, #1
	str	r2, [r3, #4]
	ldr	r3, .L53+28
	movs	r2, #0
	str	r2, [r3, #8]
	ldr	r2, .L53+28
	ldrb	r3, [r2]
	movs	r1, #4
	orrs	r3, r1
	strb	r3, [r2]
	ldr	r2, .L53+28
	ldrb	r3, [r2]
	movs	r1, #2
	orrs	r3, r1
	strb	r3, [r2]
	ldr	r2, .L53+28
	ldrb	r3, [r2]
	movs	r1, #1
	orrs	r3, r1
	strb	r3, [r2]
	b	.L36
.L49:
	nop
.L36:
	mov	sp, r7
	add	sp, sp, #28
	@ sp needed
	pop	{r4, r7, pc}
.L54:
	.align	2
.L53:
	.word	1073750016
	.word	23130
	.word	42405
	.word	-449
	.word	-1537
	.word	SystemCoreClock
	.word	PeripheralCoreClock
	.word	-536813552
	.size	core_system_clock_config, .-core_system_clock_config
	.align	1
	.global	core_systick_delay
	.syntax unified
	.code	16
	.thumb_func
	.type	core_systick_delay, %function
core_systick_delay:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #24
	add	r7, sp, #0
	str	r0, [r7, #4]
	ldr	r3, .L64
	ldr	r3, [r3]
	str	r3, [r7, #16]
	ldr	r3, .L64+4
	ldr	r3, [r3]
	cmp	r3, #0
	beq	.L63
	ldr	r3, .L64+4
	ldr	r3, [r3]
	movs	r1, r3
	movs	r3, #1
	rsbs	r0, r3, #0
	bl	__aeabi_uidiv
	movs	r3, r0
	movs	r2, r3
	ldr	r3, .L64+4
	ldr	r3, [r3]
	muls	r3, r2
	str	r3, [r7, #12]
	ldr	r2, [r7, #4]
	ldr	r3, [r7, #12]
	cmp	r2, r3
	bcs	.L58
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #4]
	subs	r2, r2, r3
	ldr	r3, .L64+4
	ldr	r3, [r3]
	cmp	r2, r3
	bcs	.L59
.L58:
	ldr	r3, [r7, #12]
	str	r3, [r7, #20]
	b	.L60
.L59:
	ldr	r3, .L64+4
	ldr	r3, [r3]
	ldr	r2, [r7, #4]
	adds	r3, r2, r3
	str	r3, [r7, #20]
.L60:
	nop
.L62:
	ldr	r3, .L64
	ldr	r2, [r3]
	ldr	r3, [r7, #16]
	subs	r3, r2, r3
	ldr	r2, [r7, #20]
	cmp	r2, r3
	bhi	.L62
.L63:
	nop
	mov	sp, r7
	add	sp, sp, #24
	@ sp needed
	pop	{r7, pc}
.L65:
	.align	2
.L64:
	.word	current_tick_count
	.word	tick_increment_step
	.size	core_systick_delay, .-core_systick_delay
	.align	1
	.global	core_systick_increment_ticks
	.syntax unified
	.code	16
	.thumb_func
	.type	core_systick_increment_ticks, %function
core_systick_increment_ticks:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r3, .L67
	ldr	r2, [r3]
	ldr	r3, .L67+4
	ldr	r3, [r3]
	adds	r2, r2, r3
	ldr	r3, .L67
	str	r2, [r3]
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L68:
	.align	2
.L67:
	.word	current_tick_count
	.word	tick_increment_step
	.size	core_systick_increment_ticks, .-core_systick_increment_ticks
	.align	1
	.global	core_systick_get_tick
	.syntax unified
	.code	16
	.thumb_func
	.type	core_systick_get_tick, %function
core_systick_get_tick:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r3, .L71
	ldr	r3, [r3]
	movs	r0, r3
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L72:
	.align	2
.L71:
	.word	current_tick_count
	.size	core_systick_get_tick, .-core_systick_get_tick
	.align	1
	.global	core_systick_disable
	.syntax unified
	.code	16
	.thumb_func
	.type	core_systick_disable, %function
core_systick_disable:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r2, .L74
	ldrb	r3, [r2]
	movs	r1, #2
	bics	r3, r1
	strb	r3, [r2]
	ldr	r2, .L74
	ldrb	r3, [r2]
	movs	r1, #1
	bics	r3, r1
	strb	r3, [r2]
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L75:
	.align	2
.L74:
	.word	-536813552
	.size	core_systick_disable, .-core_systick_disable
	.align	1
	.global	core_systick_enable
	.syntax unified
	.code	16
	.thumb_func
	.type	core_systick_enable, %function
core_systick_enable:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r2, .L77
	ldrb	r3, [r2]
	movs	r1, #2
	orrs	r3, r1
	strb	r3, [r2]
	ldr	r2, .L77
	ldrb	r3, [r2]
	movs	r1, #1
	orrs	r3, r1
	strb	r3, [r2]
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L78:
	.align	2
.L77:
	.word	-536813552
	.size	core_systick_enable, .-core_systick_enable
	.align	1
	.global	core_ports_set_function
	.syntax unified
	.code	16
	.thumb_func
	.type	core_ports_set_function, %function
core_ports_set_function:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	movs	r2, r0
	adds	r3, r7, #7
	strb	r2, [r3]
	adds	r3, r7, #6
	adds	r2, r1, #0
	strb	r2, [r3]
	adds	r3, r7, #7
	ldrb	r3, [r3]
	cmp	r3, #36
	bhi	.L99
	lsls	r2, r3, #2
	ldr	r3, .L100
	adds	r3, r2, r3
	ldr	r3, [r3]
	mov	pc, r3
	.section	.rodata
	.align	2
.L82:
	.word	.L99
	.word	.L97
	.word	.L96
	.word	.L95
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L94
	.word	.L93
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L92
	.word	.L91
	.word	.L90
	.word	.L89
	.word	.L88
	.word	.L99
	.word	.L99
	.word	.L99
	.word	.L87
	.word	.L86
	.word	.L85
	.word	.L84
	.word	.L83
	.word	.L81
	.text
.L97:
	ldr	r3, .L100+4
	adds	r2, r7, #6
	ldrb	r2, [r2]
	str	r2, [r3, #4]
	b	.L79
.L96:
	ldr	r3, .L100+4
	adds	r2, r7, #6
	ldrb	r2, [r2]
	str	r2, [r3, #8]
	b	.L79
.L95:
	ldr	r3, .L100+4
	adds	r2, r7, #6
	ldrb	r2, [r2]
	str	r2, [r3, #12]
	b	.L79
.L94:
	ldr	r3, .L100+4
	adds	r2, r7, #6
	ldrb	r2, [r2]
	str	r2, [r3, #80]
	b	.L79
.L93:
	ldr	r3, .L100+4
	adds	r2, r7, #6
	ldrb	r2, [r2]
	str	r2, [r3, #84]
	b	.L79
.L92:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #140
	str	r3, [r1, r2]
	b	.L79
.L91:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #144
	str	r3, [r1, r2]
	b	.L79
.L90:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #148
	str	r3, [r1, r2]
	b	.L79
.L89:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #152
	str	r3, [r1, r2]
	b	.L79
.L88:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #156
	str	r3, [r1, r2]
	b	.L79
.L87:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #196
	str	r3, [r1, r2]
	b	.L79
.L86:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #200
	str	r3, [r1, r2]
	b	.L79
.L85:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #204
	str	r3, [r1, r2]
	b	.L79
.L84:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #208
	str	r3, [r1, r2]
	b	.L79
.L83:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #212
	str	r3, [r1, r2]
	b	.L79
.L81:
	ldr	r1, .L100+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r2, #216
	str	r3, [r1, r2]
	b	.L79
.L99:
	nop
.L79:
	mov	sp, r7
	add	sp, sp, #8
	@ sp needed
	pop	{r7, pc}
.L101:
	.align	2
.L100:
	.word	.L82
	.word	1073875968
	.size	core_ports_set_function, .-core_ports_set_function
	.align	1
	.global	core_ports_get_function
	.syntax unified
	.code	16
	.thumb_func
	.type	core_ports_get_function, %function
core_ports_get_function:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	movs	r2, r0
	adds	r3, r7, #7
	strb	r2, [r3]
	adds	r3, r7, #7
	ldrb	r3, [r3]
	cmp	r3, #36
	bhi	.L103
	lsls	r2, r3, #2
	ldr	r3, .L122
	adds	r3, r2, r3
	ldr	r3, [r3]
	mov	pc, r3
	.section	.rodata
	.align	2
.L105:
	.word	.L103
	.word	.L120
	.word	.L119
	.word	.L118
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L117
	.word	.L116
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L115
	.word	.L114
	.word	.L113
	.word	.L112
	.word	.L111
	.word	.L103
	.word	.L103
	.word	.L103
	.word	.L110
	.word	.L109
	.word	.L108
	.word	.L107
	.word	.L106
	.word	.L104
	.text
.L120:
	ldr	r3, .L122+4
	ldr	r3, [r3, #4]
	uxtb	r3, r3
	b	.L121
.L119:
	ldr	r3, .L122+4
	ldr	r3, [r3, #8]
	uxtb	r3, r3
	b	.L121
.L118:
	ldr	r3, .L122+4
	ldr	r3, [r3, #12]
	uxtb	r3, r3
	b	.L121
.L117:
	ldr	r3, .L122+4
	ldr	r3, [r3, #80]
	uxtb	r3, r3
	b	.L121
.L116:
	ldr	r3, .L122+4
	ldr	r3, [r3, #84]
	uxtb	r3, r3
	b	.L121
.L115:
	ldr	r2, .L122+4
	movs	r3, #140
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L114:
	ldr	r2, .L122+4
	movs	r3, #144
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L113:
	ldr	r2, .L122+4
	movs	r3, #148
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L112:
	ldr	r2, .L122+4
	movs	r3, #152
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L111:
	ldr	r2, .L122+4
	movs	r3, #156
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L110:
	ldr	r2, .L122+4
	movs	r3, #196
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L109:
	ldr	r2, .L122+4
	movs	r3, #200
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L108:
	ldr	r2, .L122+4
	movs	r3, #204
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L107:
	ldr	r2, .L122+4
	movs	r3, #208
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L106:
	ldr	r2, .L122+4
	movs	r3, #212
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L104:
	ldr	r2, .L122+4
	movs	r3, #216
	ldr	r3, [r2, r3]
	uxtb	r3, r3
	b	.L121
.L103:
	movs	r3, #0
.L121:
	movs	r0, r3
	mov	sp, r7
	add	sp, sp, #8
	@ sp needed
	pop	{r7, pc}
.L123:
	.align	2
.L122:
	.word	.L105
	.word	1073875968
	.size	core_ports_get_function, .-core_ports_get_function
	.align	1
	.global	SysTick_Handler
	.syntax unified
	.code	16
	.thumb_func
	.type	SysTick_Handler, %function
SysTick_Handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r3, .L125
	ldr	r2, [r3]
	ldr	r3, .L125+4
	ldr	r3, [r3]
	adds	r2, r2, r3
	ldr	r3, .L125
	str	r2, [r3]
	nop
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L126:
	.align	2
.L125:
	.word	current_tick_count
	.word	tick_increment_step
	.size	SysTick_Handler, .-SysTick_Handler
	.align	1
	.global	gpio_set_config
	.syntax unified
	.code	16
	.thumb_func
	.type	gpio_set_config, %function
gpio_set_config:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, r7, lr}
	sub	sp, sp, #12
	add	r7, sp, #0
	movs	r2, r0
	movs	r3, r7
	strh	r1, [r3]
	adds	r3, r7, #7
	strb	r2, [r3]
	adds	r3, r7, #7
	ldrb	r3, [r3]
	cmp	r3, #36
	bls	.LCB1942
	bl	.L147	@far jump
.LCB1942:
	lsls	r2, r3, #2
	ldr	r3, .L148
	adds	r3, r2, r3
	ldr	r3, [r3]
	mov	pc, r3
	.section	.rodata
	.align	2
.L130:
	.word	.L147
	.word	.L145
	.word	.L144
	.word	.L143
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L142
	.word	.L141
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L140
	.word	.L139
	.word	.L138
	.word	.L137
	.word	.L136
	.word	.L147
	.word	.L147
	.word	.L147
	.word	.L135
	.word	.L134
	.word	.L133
	.word	.L132
	.word	.L131
	.word	.L129
	.text
.L145:
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #128
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #134
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #142
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #144
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #146
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #150
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #152
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #50
	adds	r3, r3, #255
	movs	r2, r3
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #153
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #52
	adds	r3, r3, #255
	movs	r2, r3
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r2, r3
	ldr	r3, .L148+4
	str	r2, [r3, #4]
	bl	.L127	@ far jump
.L144:
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #128
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #134
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #142
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #144
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #146
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #150
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #152
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #50
	adds	r3, r3, #255
	movs	r2, r3
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #153
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L148+4
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #52
	adds	r3, r3, #255
	movs	r2, r3
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r2, r3
	ldr	r3, .L148+4
	str	r2, [r3, #8]
	bl	.L127	@ far jump
.L149:
	.align	2
.L148:
	.word	.L130
	.word	1073875968
.L143:
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #128
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #134
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #142
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #144
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #146
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #150
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #152
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #50
	adds	r3, r3, #255
	movs	r2, r3
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #153
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #52
	adds	r3, r3, #255
	movs	r2, r3
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r2, r3
	ldr	r3, .L150
	str	r2, [r3, #12]
	bl	.L127	@ far jump
.L142:
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #154
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #160
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #168
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #170
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #172
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #176
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #178
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #180
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #182
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L150
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #184
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r2, r3
	ldr	r3, .L150
	str	r2, [r3, #80]
	bl	.L127	@ far jump
.L151:
	.align	2
.L150:
	.word	1073875968
.L141:
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #154
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #160
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #168
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #170
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #172
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #176
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #178
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #180
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #182
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #184
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r2, r3
	ldr	r3, .L152
	str	r2, [r3, #84]
	bl	.L127	@ far jump
.L140:
	ldr	r2, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #186
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #3
	ldrb	r1, [r2, r3]
	movs	r0, #8
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #192
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #200
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #202
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #204
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #208
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #210
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #212
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #214
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L152
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #216
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L152
	movs	r1, r3
	movs	r3, #140
	str	r1, [r2, r3]
	bl	.L127	@ far jump
.L153:
	.align	2
.L152:
	.word	1073875968
.L139:
	ldr	r2, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #186
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #4
	ldrb	r1, [r2, r3]
	movs	r0, #16
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #192
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #200
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #202
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #204
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #208
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #210
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #212
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #214
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #216
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L154
	movs	r1, r3
	movs	r3, #144
	str	r1, [r2, r3]
	bl	.L127	@ far jump
.L138:
	ldr	r2, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #186
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #5
	ldrb	r1, [r2, r3]
	movs	r0, #32
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #192
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #200
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #202
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #204
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #208
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #210
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #212
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #214
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L154
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #216
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L154
	movs	r1, r3
	movs	r3, #148
	str	r1, [r2, r3]
	bl	.L127	@ far jump
.L155:
	.align	2
.L154:
	.word	1073875968
.L137:
	ldr	r2, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #186
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #6
	ldrb	r1, [r2, r3]
	movs	r0, #64
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #192
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #200
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #202
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #204
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #208
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #210
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #212
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #214
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #216
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L156
	movs	r1, r3
	movs	r3, #152
	str	r1, [r2, r3]
	bl	.L127	@ far jump
.L136:
	ldr	r2, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #186
	lsls	r3, r3, #1
	lsls	r4, r1, #7
	ldrb	r1, [r2, r3]
	movs	r0, #127
	ands	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #192
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #200
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #202
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #204
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #208
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #210
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #212
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #214
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L156
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #216
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	lsls	r4, r0, #7
	movs	r0, #127
	ands	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L156
	movs	r1, r3
	movs	r3, #156
	str	r1, [r2, r3]
	bl	.L127	@ far jump
.L157:
	.align	2
.L156:
	.word	1073875968
.L135:
	ldr	r2, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #218
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	adds	r4, r1, r1
	ldrb	r1, [r2, r3]
	movs	r0, #2
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #224
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #232
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #234
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #236
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #240
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #242
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #244
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #246
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #248
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	adds	r4, r0, r0
	movs	r0, #2
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L158
	movs	r1, r3
	movs	r3, #196
	str	r1, [r2, r3]
	b	.L127
.L134:
	ldr	r2, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #218
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #2
	ldrb	r1, [r2, r3]
	movs	r0, #4
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #224
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #232
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #234
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #236
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #240
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #242
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #244
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #246
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L158
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #248
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #2
	movs	r0, #4
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L158
	movs	r1, r3
	movs	r3, #200
	str	r1, [r2, r3]
	b	.L127
.L159:
	.align	2
.L158:
	.word	1073875968
.L133:
	ldr	r2, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #218
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #3
	ldrb	r1, [r2, r3]
	movs	r0, #8
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #224
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #232
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #234
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #236
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #240
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #242
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #244
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #246
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #248
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #3
	movs	r0, #8
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L160
	movs	r1, r3
	movs	r3, #204
	str	r1, [r2, r3]
	b	.L127
.L132:
	ldr	r2, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #218
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #4
	ldrb	r1, [r2, r3]
	movs	r0, #16
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #224
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #232
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #234
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #236
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #240
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #242
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #244
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #246
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L160
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #248
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #4
	movs	r0, #16
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L160
	movs	r1, r3
	movs	r3, #208
	str	r1, [r2, r3]
	b	.L127
.L161:
	.align	2
.L160:
	.word	1073875968
.L131:
	ldr	r2, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #218
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #5
	ldrb	r1, [r2, r3]
	movs	r0, #32
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #224
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #232
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #234
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #236
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #240
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #242
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #244
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #246
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #248
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #5
	movs	r0, #32
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L162
	movs	r1, r3
	movs	r3, #212
	str	r1, [r2, r3]
	b	.L127
.L129:
	ldr	r2, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r1, r3
	movs	r3, #218
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #6
	ldrb	r1, [r2, r3]
	movs	r0, #64
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #224
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #232
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #234
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #236
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #240
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #242
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #244
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #31
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #246
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	ldr	r1, .L162
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r0, r3
	movs	r3, #248
	lsls	r2, r3, #1
	ldrb	r3, [r1, r2]
	movs	r4, #1
	ands	r0, r4
	lsls	r4, r0, #6
	movs	r0, #64
	bics	r3, r0
	adds	r0, r3, #0
	adds	r3, r4, #0
	orrs	r3, r0
	strb	r3, [r1, r2]
	movs	r3, r7
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #27
	lsrs	r3, r3, #29
	uxtb	r3, r3
	ldr	r2, .L162
	movs	r1, r3
	movs	r3, #216
	str	r1, [r2, r3]
	b	.L127
.L147:
	nop
.L127:
	mov	sp, r7
	add	sp, sp, #12
	@ sp needed
	pop	{r4, r7, pc}
.L163:
	.align	2
.L162:
	.word	1073875968
	.size	gpio_set_config, .-gpio_set_config
	.align	1
	.global	gpio_get_config
	.syntax unified
	.code	16
	.thumb_func
	.type	gpio_get_config, %function
gpio_get_config:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, r7, lr}
	sub	sp, sp, #20
	add	r7, sp, #0
	movs	r2, r0
	adds	r3, r7, #7
	strb	r2, [r3]
	adds	r3, r7, #7
	ldrb	r3, [r3]
	cmp	r3, #36
	bls	.LCB5104
	bl	.L165	@far jump
.LCB5104:
	lsls	r2, r3, #2
	ldr	r3, .L185
	adds	r3, r2, r3
	ldr	r3, [r3]
	mov	pc, r3
	.section	.rodata
	.align	2
.L167:
	.word	.L165
	.word	.L182
	.word	.L181
	.word	.L180
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L179
	.word	.L178
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L177
	.word	.L176
	.word	.L175
	.word	.L174
	.word	.L173
	.word	.L165
	.word	.L165
	.word	.L165
	.word	.L172
	.word	.L171
	.word	.L170
	.word	.L169
	.word	.L168
	.word	.L166
	.text
.L182:
	ldr	r2, .L185+4
	movs	r3, #128
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #134
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #142
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #144
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #146
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #150
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #152
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #50
	adds	r3, r3, #255
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #153
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L185+4
	movs	r3, #52
	adds	r3, r3, #255
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r3, .L185+4
	ldr	r3, [r3, #4]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L181:
	ldr	r2, .L185+4
	movs	r3, #128
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #134
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #142
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #144
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #146
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #150
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #152
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #50
	adds	r3, r3, #255
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L185+4
	movs	r3, #153
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L185+4
	movs	r3, #52
	adds	r3, r3, #255
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r3, .L185+4
	ldr	r3, [r3, #8]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L186:
	.align	2
.L185:
	.word	.L167
	.word	1073875968
.L180:
	ldr	r2, .L187
	movs	r3, #128
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #134
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #142
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #144
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #146
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #150
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #152
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #50
	adds	r3, r3, #255
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #153
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L187
	movs	r3, #52
	adds	r3, r3, #255
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r3, .L187
	ldr	r3, [r3, #12]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L179:
	ldr	r2, .L187
	movs	r3, #154
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #160
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #168
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #170
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #172
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #176
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #178
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #180
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L187
	movs	r3, #182
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L187
	movs	r3, #184
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r3, .L187
	ldr	r3, [r3, #80]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L188:
	.align	2
.L187:
	.word	1073875968
.L178:
	ldr	r2, .L189
	movs	r3, #154
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #160
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #168
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #170
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #172
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #176
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #178
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #180
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #182
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L189
	movs	r3, #184
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r3, .L189
	ldr	r3, [r3, #84]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L177:
	ldr	r2, .L189
	movs	r3, #186
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #192
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #200
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #202
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #204
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #208
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #210
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #212
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L189
	movs	r3, #214
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L189
	movs	r3, #216
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L189
	movs	r3, #140
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L190:
	.align	2
.L189:
	.word	1073875968
.L176:
	ldr	r2, .L191
	movs	r3, #186
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #192
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #200
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #202
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #204
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #208
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #210
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #212
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #214
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L191
	movs	r3, #216
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L191
	movs	r3, #144
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L175:
	ldr	r2, .L191
	movs	r3, #186
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #192
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #200
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #202
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #204
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #208
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #210
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #212
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L191
	movs	r3, #214
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L191
	movs	r3, #216
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L191
	movs	r3, #148
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L192:
	.align	2
.L191:
	.word	1073875968
.L174:
	ldr	r2, .L193
	movs	r3, #186
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #192
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #200
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #202
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #204
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #208
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #210
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #212
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #214
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L193
	movs	r3, #216
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L193
	movs	r3, #152
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L173:
	ldr	r2, .L193
	movs	r3, #186
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #192
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #200
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #202
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #204
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #208
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #210
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #212
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L193
	movs	r3, #214
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L193
	movs	r3, #216
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L193
	movs	r3, #156
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L194:
	.align	2
.L193:
	.word	1073875968
.L172:
	ldr	r2, .L195
	movs	r3, #218
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #224
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #232
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #234
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #236
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #240
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #242
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #244
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #246
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L195
	movs	r3, #248
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L195
	movs	r3, #196
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	bl	.L184	@ far jump
.L171:
	ldr	r2, .L195
	movs	r3, #218
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #224
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #232
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #234
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #236
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #240
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #242
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #244
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L195
	movs	r3, #246
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L195
	movs	r3, #248
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L195
	movs	r3, #200
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	b	.L184
.L196:
	.align	2
.L195:
	.word	1073875968
.L170:
	ldr	r2, .L197
	movs	r3, #218
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #224
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #232
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #234
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #236
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #240
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #242
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #244
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #246
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L197
	movs	r3, #248
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L197
	movs	r3, #204
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	b	.L184
.L169:
	ldr	r2, .L197
	movs	r3, #218
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #224
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #232
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #234
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #236
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #240
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #242
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #244
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L197
	movs	r3, #246
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L197
	movs	r3, #248
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L197
	movs	r3, #208
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	b	.L184
.L198:
	.align	2
.L197:
	.word	1073875968
.L168:
	ldr	r2, .L199
	movs	r3, #218
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #224
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #232
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #234
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #236
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #240
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #242
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #244
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #246
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L199
	movs	r3, #248
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L199
	movs	r3, #212
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	b	.L184
.L166:
	ldr	r2, .L199
	movs	r3, #218
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	movs	r4, #8
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #224
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #232
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3]
	movs	r1, #4
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #234
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #3
	ldrb	r2, [r3]
	movs	r1, #8
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #236
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #4
	ldrb	r2, [r3]
	movs	r1, #16
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #240
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #5
	ldrb	r2, [r3]
	movs	r1, #32
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #242
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	lsls	r0, r2, #6
	ldrb	r2, [r3]
	movs	r1, #64
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #244
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	lsls	r0, r2, #7
	ldrb	r2, [r3]
	movs	r1, #127
	ands	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3]
	ldr	r2, .L199
	movs	r3, #246
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	movs	r0, r2
	ldrb	r2, [r3, #1]
	movs	r1, #1
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L199
	movs	r3, #248
	lsls	r3, r3, #1
	ldrb	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #1
	ands	r2, r1
	adds	r0, r2, r2
	ldrb	r2, [r3, #1]
	movs	r1, #2
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	ldr	r2, .L199
	movs	r3, #216
	ldr	r3, [r2, r3]
	adds	r2, r3, #0
	movs	r3, #7
	ands	r3, r2
	uxtb	r2, r3
	adds	r3, r7, r4
	movs	r1, #7
	ands	r2, r1
	lsls	r0, r2, #2
	ldrb	r2, [r3, #1]
	movs	r1, #28
	bics	r2, r1
	adds	r1, r2, #0
	adds	r2, r0, #0
	orrs	r2, r1
	strb	r2, [r3, #1]
	movs	r3, #12
	adds	r3, r7, r3
	adds	r2, r7, r4
	ldrh	r2, [r2]
	strh	r2, [r3]
	b	.L184
.L165:
	movs	r3, #12
	adds	r3, r7, r3
	movs	r2, #8
	adds	r2, r7, r2
	ldrh	r2, [r2]
	strh	r2, [r3]
.L184:
	movs	r3, #12
	adds	r2, r7, r3
	movs	r3, #0
	ldrb	r1, [r2]
	movs	r0, #255
	ands	r1, r0
	movs	r0, #255
	bics	r3, r0
	orrs	r3, r1
	ldrb	r2, [r2, #1]
	movs	r1, #255
	ands	r2, r1
	lsls	r2, r2, #8
	ldr	r1, .L199+4
	ands	r3, r1
	orrs	r3, r2
	adds	r0, r3, #0
	mov	sp, r7
	add	sp, sp, #20
	@ sp needed
	pop	{r4, r7, pc}
.L200:
	.align	2
.L199:
	.word	1073875968
	.word	-65281
	.size	gpio_get_config, .-gpio_get_config
	.align	1
	.global	gpio_digital_read
	.syntax unified
	.code	16
	.thumb_func
	.type	gpio_digital_read, %function
gpio_digital_read:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	movs	r2, r0
	adds	r3, r7, #7
	strb	r2, [r3]
	adds	r3, r7, #7
	ldrb	r3, [r3]
	cmp	r3, #36
	bls	.LCB8683
	b	.L202	@long jump
.LCB8683:
	lsls	r2, r3, #2
	ldr	r3, .L221
	adds	r3, r2, r3
	ldr	r3, [r3]
	mov	pc, r3
	.section	.rodata
	.align	2
.L204:
	.word	.L202
	.word	.L219
	.word	.L218
	.word	.L217
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L216
	.word	.L215
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L214
	.word	.L213
	.word	.L212
	.word	.L211
	.word	.L210
	.word	.L202
	.word	.L202
	.word	.L202
	.word	.L209
	.word	.L208
	.word	.L207
	.word	.L206
	.word	.L205
	.word	.L203
	.text
.L219:
	ldr	r2, .L221+4
	movs	r3, #130
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L218:
	ldr	r2, .L221+4
	movs	r3, #130
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L217:
	ldr	r2, .L221+4
	movs	r3, #130
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L216:
	ldr	r2, .L221+4
	movs	r3, #156
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L215:
	ldr	r2, .L221+4
	movs	r3, #156
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L214:
	ldr	r2, .L221+4
	movs	r3, #188
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L213:
	ldr	r2, .L221+4
	movs	r3, #188
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L212:
	ldr	r2, .L221+4
	movs	r3, #188
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L211:
	ldr	r2, .L221+4
	movs	r3, #188
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L210:
	ldr	r2, .L221+4
	movs	r3, #188
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #24
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L209:
	ldr	r2, .L221+4
	movs	r3, #220
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #30
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L208:
	ldr	r2, .L221+4
	movs	r3, #220
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #29
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L207:
	ldr	r2, .L221+4
	movs	r3, #220
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #28
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L206:
	ldr	r2, .L221+4
	movs	r3, #220
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #27
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L205:
	ldr	r2, .L221+4
	movs	r3, #220
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #26
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L203:
	ldr	r2, .L221+4
	movs	r3, #220
	lsls	r3, r3, #1
	ldr	r3, [r2, r3]
	lsls	r3, r3, #25
	lsrs	r3, r3, #31
	uxtb	r3, r3
	b	.L220
.L202:
	movs	r3, #255
.L220:
	movs	r0, r3
	mov	sp, r7
	add	sp, sp, #8
	@ sp needed
	pop	{r7, pc}
.L222:
	.align	2
.L221:
	.word	.L204
	.word	1073875968
	.size	gpio_digital_read, .-gpio_digital_read
	.align	1
	.global	gpio_digital_write
	.syntax unified
	.code	16
	.thumb_func
	.type	gpio_digital_write, %function
gpio_digital_write:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, r7, lr}
	sub	sp, sp, #12
	add	r7, sp, #0
	movs	r2, r0
	adds	r3, r7, #7
	strb	r2, [r3]
	adds	r3, r7, #6
	adds	r2, r1, #0
	strb	r2, [r3]
	adds	r3, r7, #7
	ldrb	r3, [r3]
	cmp	r3, #36
	bls	.LCB8909
	b	.L243	@long jump
.LCB8909:
	lsls	r2, r3, #2
	ldr	r3, .L244
	adds	r3, r2, r3
	ldr	r3, [r3]
	mov	pc, r3
	.section	.rodata
	.align	2
.L226:
	.word	.L243
	.word	.L241
	.word	.L240
	.word	.L239
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L238
	.word	.L237
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L236
	.word	.L235
	.word	.L234
	.word	.L233
	.word	.L232
	.word	.L243
	.word	.L243
	.word	.L243
	.word	.L231
	.word	.L230
	.word	.L229
	.word	.L228
	.word	.L227
	.word	.L225
	.text
.L241:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #132
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	adds	r4, r1, r1
	ldrb	r1, [r2, r3]
	movs	r0, #2
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L240:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #132
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #2
	ldrb	r1, [r2, r3]
	movs	r0, #4
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L239:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #132
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #3
	ldrb	r1, [r2, r3]
	movs	r0, #8
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L238:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #158
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #4
	ldrb	r1, [r2, r3]
	movs	r0, #16
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L237:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #158
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #5
	ldrb	r1, [r2, r3]
	movs	r0, #32
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L236:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #190
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #3
	ldrb	r1, [r2, r3]
	movs	r0, #8
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L235:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #190
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #4
	ldrb	r1, [r2, r3]
	movs	r0, #16
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L234:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #190
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #5
	ldrb	r1, [r2, r3]
	movs	r0, #32
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L233:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #190
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #6
	ldrb	r1, [r2, r3]
	movs	r0, #64
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L232:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #190
	lsls	r3, r3, #1
	lsls	r4, r1, #7
	ldrb	r1, [r2, r3]
	movs	r0, #127
	ands	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L231:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #222
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	adds	r4, r1, r1
	ldrb	r1, [r2, r3]
	movs	r0, #2
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L230:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #222
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #2
	ldrb	r1, [r2, r3]
	movs	r0, #4
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L229:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #222
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #3
	ldrb	r1, [r2, r3]
	movs	r0, #8
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L228:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #222
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #4
	ldrb	r1, [r2, r3]
	movs	r0, #16
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L227:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #222
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #5
	ldrb	r1, [r2, r3]
	movs	r0, #32
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L225:
	ldr	r2, .L244+4
	adds	r3, r7, #6
	ldrb	r3, [r3]
	movs	r1, #1
	ands	r3, r1
	uxtb	r1, r3
	movs	r3, #222
	lsls	r3, r3, #1
	adds	r0, r1, #0
	movs	r1, #1
	ands	r1, r0
	lsls	r4, r1, #6
	ldrb	r1, [r2, r3]
	movs	r0, #64
	bics	r1, r0
	adds	r0, r1, #0
	adds	r1, r4, #0
	orrs	r1, r0
	strb	r1, [r2, r3]
.L243:
	nop
	nop
	mov	sp, r7
	add	sp, sp, #12
	@ sp needed
	pop	{r4, r7, pc}
.L245:
	.align	2
.L244:
	.word	.L226
	.word	1073875968
	.size	gpio_digital_write, .-gpio_digital_write
	.align	1
	.global	main
	.syntax unified
	.code	16
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r3, .L248
	ldr	r0, [r3]
	ldr	r1, [r3, #4]
	ldr	r2, [r3, #8]
	bl	core_system_clock_config
.L247:
	.syntax divided
@ 10 ".\mcu\main.c" 1
	wfi
@ 0 "" 2
	.thumb
	.syntax unified
	b	.L247
.L249:
	.align	2
.L248:
	.word	default_system_config
	.size	main, .-main
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
