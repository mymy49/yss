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

#if defined(STM32F746xx) || defined(STM32F745xx) || \
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
	defined (XMC4300_F100x256) || \
	defined (MAX32660) || \
	defined (GD32F10X_XD) || defined (GD32F450)

#define __CORE_CM3_CM4_CM7_H_GENERIC

#elif defined (STM32F030x6) || defined (STM32F030x8) || \
	defined (STM32F031x6) || defined (STM32F038xx) || \
	defined (STM32F042x6) || defined (STM32F048xx) || defined (STM32F070x6) || \
	defined (STM32F051x8) || defined (STM32F058xx) || \
	defined (STM32F071xB) || defined (STM32F072xB) || defined (STM32F078xx) || defined (STM32F070xB) || \
	defined (STM32F091xC) || defined (STM32F098xx) || defined (STM32F030xC)

#define __CORE_CM0_H_GENERIC

#else

#define __CORE_CM0PLUS_H_GENERIC

#endif

#if defined (STM32F030x6) || defined (STM32F030x8) || defined (STM32F070x6)

#define __MCU_SMALL_SRAM_NO_SCHEDULE

#endif

	.thumb_func
	.syntax unified
	.type SysTick_Handler, %function
	.global SysTick_Handler
	.section .text, "ax"
SysTick_Handler:
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(__CORE_CM3_CM4_CM7_H_GENERIC)
	movw r0, 0xED04
	movt r0, 0xE000
	ldr r1, [r0]
	orrs r1, r1, #(1 << 28)
	str r1, [r0]
	bx lr
#elif defined(__CORE_CM0PLUS_H_GENERIC)
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
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(__CORE_CM3_CM4_CM7_H_GENERIC)
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
#elif defined(__CORE_CM0PLUS_H_GENERIC)
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
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(__CORE_CM3_CM4_CM7_H_GENERIC)
	push {r0-r1}
	movw r0, 0xED04
	movt r0, 0xE000
	ldr r1, [r0]
	orrs r1, r1, #(1 << 28)
	str r1, [r0]
	pop {r0-r1}
	bx lr
#elif defined(__CORE_CM0PLUS_H_GENERIC)
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