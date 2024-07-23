/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC)
	.thumb_func
	.syntax unified
	.func memcpy
	.type memcpy, %function
	.global memcpy
	.section .text, "ax"
memcpy:
	push {r3-r6}
	orr r3, r0, r1
	ands r3, 0x3
	bne unalignedHanler
repeat:
	movs r4, #256
	subs r3, r2, r4
	bge greater
	ands r3, r2, #0xf
	bic r2, #0xf
	subs r4, r4, r2 
	lsrs r4, r4, #2
	adds r4, r4, #2
	movs r2, r3
	add pc, pc, r4
greater:
	subs r2, #256
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	ldmia   R1!,{R3-R6}
	stmia   R0!,{R3-R6}
	movs r4, #16
	subs r3, r2, r4
	bge repeat
	movs r2, r2
	beq finish
	subs r3, r2, #8
	blt sub4
	ldmia   R1!,{R3-R4}
	stmia   R0!,{R3-R4}
	subs r2, #8
sub4:
	subs r3, r2, #4
	blt sub2
	ldr r3, [r1], #4
	str r3, [r0], #4
	subs r2, #4
sub2:
	subs r3, r2, #2
	blt sub1
	ldrh r3, [r1], #2
	strh r3, [r0], #2
	subs r2, #2
sub1:
	movs r2, r2
	beq finish
	ldrb r3, [r1], #1
	strb r3, [r0], #1
finish:
	pop {r3-r6}
	bx lr

unalignedHanler:
	movs r4, #128
	subs r3, r2, r4
	bge greaterUnaligned
	ands r3, r2, #0x3
	bic r2, #0x3
	subs r4, r4, r2 
	lsls r4, r4, #1
	movs r2, r3
	add pc, pc, r4
greaterUnaligned:
	subs r2, #128
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	ldr r3, [r1], #4
	str r3, [r0], #4
	movs r4, #4
	subs r3, r2, r4
	bhi unalignedHanler
	b sub4
	.endfunc

#endif
