////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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