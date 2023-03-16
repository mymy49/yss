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

	.thumb_func
	.syntax unified
	.type SysTick_Handler, %function
	.global SysTick_Handler
	.section .text, "ax"
SysTick_Handler:
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
	movw r0, 0xED04
	movt r0, 0xE000
	ldr r1, [r0]
	orrs r1, r1, #(1 << 28)
	str r1, [r0]
	bx lr
#elif defined(YSS__CORE_CM0PLUS_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC)
	ldr r0, =0xe000ed04
	ldr r1, [r0]
	movs r2, #1
	lsls r2, r2, 28
	orrs r1, r1, r2
	str r1, [r0]
	bx lr
#endif
#else
	bx lr
#endif

	.thumb_func
	.type PendSV_Handler, %function
	.global PendSV_Handler
	.global getNextContext
	.section .text, "ax"
PendSV_Handler:
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
	mrs r0, psp
	movw r3, 0xE010
	movt r3, 0xE000
	mov r1, #0
	str r1, [r3]

#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
	vstmdb r0!,{s16-s31}
	vmrs r1, fpscr
	mov r3, lr
	stmdb r0!, {r1-r11}
#else
	mov r3, lr
	stmdb r0!, {r3-r11}
#endif
	bl getNextContext
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
	ldm  r0!, {r1-r11}
	vldm r0!,{s16-s31}
	vmsr fpscr, r1
popSkip:
#else
	ldm  r0!, {r3-r11}
#endif
	msr psp, r0
	movw r12, 0xE010
	movt r12, 0xE000
	mov r1, #7
	str r1, [r12]
	mov r1, #0
	str r1, [r12, #8]
	push {r3}
	pop {pc}
	nop
#elif defined(YSS__CORE_CM0PLUS_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC)
	mrs r0, psp
	ldr r3, =0xe000e010
	movs r1, #0
	str r1, [r3]
	mov r3, lr
	subs r0, r0, #36
	stm r0!, {r3-r7}
	mov r3, r8
	mov r4, r9
	mov r5, r10
	mov r6, r11
	stm r0!, {r3-r6}
	subs r0, r0, #36
	bl getNextContext
	adds r0, r0, #20
	ldm  r0!, {r3-r6}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	mov r11, r6
	ldr r3, =0xe000e010
	movs r1, #7
	str r1, [r3]
	movs r1, #0
	str r1, [r3, #8]
	subs r0, r0, #36
	ldm  r0!, {r3-r7}
	adds r0, r0, #16
	msr psp, r0
	push {r3}
	pop {pc}
	nop
#endif
#else
	bx lr
#endif

	.thumb_func
	.type yield, %function
	.global yield
	.section .text, "ax"
yield:
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
	push {r0-r1}
	movw r0, 0xED04
	movt r0, 0xE000
	ldr r1, [r0]
	orrs r1, r1, #(1 << 28)
	str r1, [r0]
	pop {r0-r1}
	bx lr
#elif defined(YSS__CORE_CM0PLUS_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC)
	ldr r0, =0xE000ED04
	ldr r1, [r0]
	movs r2, #1
	lsls r2, #28
	orrs r1, r1, r2
	str r1, [r0]
	bx lr
#endif
#else
	bx lr
#endif

