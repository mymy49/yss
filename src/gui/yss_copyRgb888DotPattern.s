////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
