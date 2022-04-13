////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined (STM32F746xx) || defined(STM32F745xx) || \
	defined (STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined (STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined (STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined (STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined (STM32F429xx) ||	defined(STM32F439xx) || \
	defined (STM32F100xB) || defined(STM32F100xE) || \
	defined (STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
	defined (STM32F102x6) || defined(STM32F102xB) || \
	defined (STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
	defined (STM32F105xC) || \
	defined (STM32F107xC) || \
	defined (STM32L151xB) || \
	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB) || \
	defined (GD32F10X_XD) || \
	defined(GD32F10X_XD) || defined(GD32F10X_HD)

#define __CORE_CM3_CM4_CM7_H_GENERIC
#else
#define __CORE_CM0PLUS_H_GENERIC
#endif

#if defined(__CORE_CM3_CM4_CM7_H_GENERIC)
	.thumb_func
	.syntax unified
	.func memset
	.type memset, %function
	.global memset
	.section .text, "ax"
memset:
	push {r3-r7}
	bic r1, #0xffffff00
	lsl r3, r1, #8
	orr r1, r3
	lsl r3, r1, #16
	orr r1, r3
	mov r3, r0
	ands r3, 0x3
	bne unalignedRepeat
	mov r4, r1
	mov r5, r4
	mov r6, r4
	mov r7, r4
repeat:
	movs r1, #256
	subs r3, r2, r1
	bge greater
	ands r3, r2, #0xf
	bic r2, #0xf
	subs r1, r1, r2 
	lsr r1, r1, #3
	adds r1, r1, #2
	movs r2, r3
	add pc, pc, r1
greater:
	subs r2, #256
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
	subs r3, r2, #2
	blt sub1
	strh r4, [r0], #2
	subs r2, #2
sub1:
	movs r2, r2
	beq finish
	strb r4, [r0], #1
finish:
	pop {r3-r7}
	bx lr

unalignedRepeat :
	movs r4, #128
	subs r3, r2, r4
	bge greaterUnaligned
	ands r3, r2, #0x3
	bic r2, #0x3
	subs r4, r4, r2 
//	lsls r4, r4, #1
	movs r2, r3
	add pc, pc, r4
greaterUnaligned:
	subs r2, #128
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	str r1, [r0], #4
	subs r3, r2, #4
	bhi unalignedRepeat
	b sub2	
	.endfunc
#endif
