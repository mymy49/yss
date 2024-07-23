/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include "../../inc/drv/mcu.h"

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC)
	.thumb_func
	.syntax unified
	.func copyRgb888DotPattern
	.type copyRgb888DotPattern, %function
	.global copyRgb888DotPattern
	.section .text, "ax"
copyRgb888DotPattern:
	push {r3-r7}
	bic r1, #0xff000000
	mov r5, r1
	mov r6, #0
	mov r7, #0
	lsl r3, r1, #24
	orr r5, r3
	lsr r6, r1, #8
	lsl r3, r1, #16
	orr r6, r3
	lsr r7, r1, #16
	lsl r3, r1, #8
	orr r7, r3
	ands r3, r0, #3
	bne unalignedRepeat
repeat:
	subs r3, r2, #64
	bge greater
	mov r3, #64
	and r4, r2, #0xFFFFFFFC
	subs r4, r3, r4
	lsr r4, #1
	bic r2, #0xFFFFFFFC
	add pc, pc, r4
greater:
	subs r2, #64
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
	stmia   R0!,{R5-R7}
remain:
	subs r3, r2, #4
	bhi repeat
	movs r2, r2
	beq finish
	strb r5, [r0], #1
	strb r6, [r0], #1
	strb r7, [r0], #1
	sub r2, #1
	movs r2, r2
	beq finish
	strb r5, [r0], #1
	strb r6, [r0], #1
	strb r7, [r0], #1
	sub r2, #1
	movs r2, r2
	beq finish
	strb r5, [r0], #1
	strb r6, [r0], #1
	strb r7, [r0], #1
finish:
	pop {r3-r7}
	bx lr

unalignedRepeat:
	subs r3, r2, #64
	bge unalignedGreater
	mov r3, #64
	and r4, r2, #0xFFFFFFFC
	subs r4, r3, r4
	mov r3, #3
	mul r4, r4, r3
	bic r2, #0xFFFFFFFC
	add pc, pc, r4
unalignedGreater:
	subs r2, #64
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	str R5, [R0], #4
	str R6, [R0], #4
	str R7, [R0], #4
	subs r3, r2, #4
	bhi unalignedRepeat
	b remain
#endif
