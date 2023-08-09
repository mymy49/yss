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

#include <drv/mcu.h>

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) 
	.thumb_func
	.syntax unified
	.func memsethw
	.type memsethw, %function
	.global memsethw
	.section .text, "ax"
memsethw:
	push {r4-r7}
	mov r4, #0xffff
	lsl r4, #16
	bic r1, r4
	lsl r3, r1, #16
	orr r4, r1, r3
	mov r5, r4
	mov r6, r4
	mov r7, r4
	ands r1, r0, #3
	beq repeat
	strh r4, [R0]
	adds r0, #2
	subs r2, #2
repeat:
	movs r1, #512
	subs r3, r2, r1
	bge greater
	ands r3, r2, #0xf
	bic r2, #0xf
	subs r1, r1, r2 
	lsr r1, r1, #3
	adds r1, r1, #2
	movs r2, r3
	bic r2, #1
	add pc, pc, r1
greater:
	subs r2, #512
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	stmia   R0!,{R4-R7}
	subs r3, r2, #16
	bhi repeat
	movs r2, r2
	beq finish
	subs r3, r2, #8
	blt sub4
	stmia   R0!,{R4-R5}
	subs r2, #8
sub4:
	subs r3, r2, #4
	blt sub2
	str r4, [r0], #4
	subs r2, #4
sub2:
	movs r2, r2
	beq finish
	strh r4, [r0], #2
finish:
	pop {r4-r7}
	bx lr
#elif defined(YSS__CORE_CM0_H_GENERIC)
	.thumb_func
	.syntax unified
	.func memsethw
	.type memsethw, %function
	.global memsethw
	.section .text, "ax"
memsethw:
	push {r4-r5}
	ldr r4, =0xFFFF0000
	bics r1, r4
	lsls r3, r1, #16
	mov r4, r1
	orrs r4, r3
	movs r5, #1
	bics r2, r5
	movs r5, #3
	ands r5, r0, r5
	beq repeat
	strh r4, [R0]
	adds r0, #2
	subs r2, #2
repeat:
	ldr r1, =128
	subs r3, r2, r1
	bge greater
	movs r5, #0x03
	ands r3, r3, r5
	bics r2, r5
	subs r1, r1, r2 
	movs r2, r3
	add pc, pc, r1
greater:
	subs r2, #128
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	str	r4, [R0]
	adds r0, #4
	movs r5, #4
	subs r3, r2, r5
	bge repeat
	movs r2, r2
	beq finish
	strh r4, [r0]
finish:
	pop {r4-r5}
	bx lr
#endif

