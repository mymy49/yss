/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*            (c) 2014 - 2026 SEGGER Microcontroller GmbH             *
*                                                                    *
*       www.segger.com     Support: support@segger.com               *
*                                                                    *
**********************************************************************
*                                                                    *
* All rights reserved.                                               *
*                                                                    *
* Redistribution and use in source and binary forms, with or         *
* without modification, are permitted provided that the following    *
* condition is met:                                                  *
*                                                                    *
* - Redistributions of source code must retain the above copyright   *
*   notice, this condition and the following disclaimer.             *
*                                                                    *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND             *
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,        *
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF           *
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           *
* DISCLAIMED. IN NO EVENT SHALL SEGGER Microcontroller BE LIABLE FOR *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR           *
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  *
* OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;    *
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF      *
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT          *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  *
* USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
* DAMAGE.                                                            *
*                                                                    *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File      : ARM64_Startup.s
Purpose   : Generic startup and exception handlers for ARM64 devices.

*/
        
/*********************************************************************
*
*       Macros
*
**********************************************************************
*/

// ---------------------------------------------------------
// SPSR_ELx (Saved Program Status Register) Bit Definitions
// ---------------------------------------------------------

// 1. 동작 모드 및 스택(Exception Level & SP Select) 정의 (M[4:0] 비트)
// M[4] = 0 (AArch64 상태 실행)
#define SPSR_MODE_EL0t      0x00    // EL0 Thread 모드 (비특권 유저 모드)
#define SPSR_MODE_EL1t      0x04    // EL1 권한 + SP_EL0 스택 사용 (Flat RTOS 태스크용)
#define SPSR_MODE_EL1h      0x05    // EL1 권한 + SP_EL1 스택 사용 (커널/핸들러용)
#define SPSR_MODE_EL2t      0x08    // EL2 권한 + SP_EL0 스택 사용
#define SPSR_MODE_EL2h      0x09    // EL2 권한 + SP_EL2 스택 사용
#define SPSR_MODE_EL3t      0x0C    // EL3 권한 + SP_EL0 스택 사용
#define SPSR_MODE_EL3h      0x0D    // EL3 권한 + SP_EL3 스택 사용

// 2. 인터럽트 마스크(Mask) 비트 정의
// 비트를 1로 셋(Set)하면 해당 예외를 무시(Mask)함
#define SPSR_FIQ_MASK       (1 << 6)    // Bit 6: FIQ (Fast Interrupt) 마스크
#define SPSR_IRQ_MASK       (1 << 7)    // Bit 7: IRQ (일반 인터럽트) 마스크
#define SPSR_SERROR_MASK    (1 << 8)    // Bit 8: SError (System Error, 비동기 폴트) 마스크
#define SPSR_DEBUG_MASK     (1 << 9)    // Bit 9: Debug Exception 마스크

#if defined(__aarch64__)

//
// Mark the end of a function and calculate its size
//
.macro END_FUNC name
        .size \name,.-\name
.endm

/*********************************************************************
*
*       Global data
*
**********************************************************************
*/

/*********************************************************************
*
*       Global functions
*
**********************************************************************
*/

/*********************************************************************
*
*       Reset_Handler
*
*  Function description
*    Exception handler for reset.
*    Generic bringup of a system.
*/

	.arch armv8-a

	.global Debug_Start_Here
	.global Reset_Handler
	.global reset_handler
	.global SystemInit
	.global SystemInit1
	.global main1
	.type Reset_Handler, function
	.equ reset_handler, Reset_Handler
	.section .init, "ax"

Reset_Handler:
	// MMU, D-cache, I-cache 끄기
	mrs     x0, sctlr_el3
	bic     x0, x0, #(1<<0)          // M
	bic     x0, x0, #(1<<2)          // C
	bic     x0, x0, #(1<<12)         // I
	msr     sctlr_el3, x0
	isb

	// SMPEN 비트 설정 (하드웨어 캐시 일관성 및 코어 간 통신 활성화)
	mrs     x0, S3_1_c15_c2_1
	orr     x0, x0, #(1 << 6)
	msr     S3_1_c15_c2_1, x0
	isb

	// SCR_EL3 및 CPTR_EL3 초기화 (하위 EL 설정) ===
	mov     x0, #0
	orr     x0, x0, #(1 << 11)  // ST 비트: 하위 EL에서 Secure Timer 접근 허용
	orr     x0, x0, #(1 << 10)  // RW 비트: 하위 EL(EL1, EL0)을 64비트(AArch64) 상태로 실행 (가장 중요)
	// 참고: bit 1(IRQ)과 bit 2(FIQ)를 0으로 두어, EL0에서 발생한 인터럽트가 EL3가 아닌 EL1으로 향하도록 라우팅합니다.
	msr     scr_el3, x0
	mov     x0, #0              // CPTR_EL3의 모든 비트를 0으로 초기화
	msr     cptr_el3, x0        // FPU(부동소수점) 명령어가 EL3로 트랩(예외)되는 것을 방지
	isb
	
	// 벡터 설정
	adr x0, _vectors
	msr vbar_el3, x0
	msr vbar_el1, x0

	// I-cache, TLB 무효화
 	ic      iallu
	tlbi    alle3
	dsb     sy
	isb

	mov x0, #(0x3 << 20) // FPEN disables trapping to EL1.
	msr cpacr_el1, x0

	// Core 번호 확인
	mrs     x1, mpidr_el1
	and     x1, x1, #3
	cbz     x1, 0f    
	b       core1_init
0:

	// D-cache를 set/way 방식으로 무효화 (L1, L2)
	// 이전 실행의 dirty 데이터는 버립니다(clean하지 않음).
	mrs     x0, clidr_el1
	ubfx    x3, x0, #24, #3          // LoC
	lsl     x3, x3, #1               // LoC * 2
	cbz     x3, 5f
	mov     x10, #0                  // x10 = level * 2
1:
	add     x2, x10, x10, lsr #1     // level * 3
	lsr     x1, x0, x2
	and     x1, x1, #7               // 이 level의 cache type
	cmp     x1, #2
	b.lt    4f                       // 데이터 캐시 없음
	msr     csselr_el1, x10
	isb
	mrs     x1, ccsidr_el1
	and     x2, x1, #7
	add     x2, x2, #4               // log2(line bytes)
	ubfx    x4, x1, #3, #10          // max way
	clz     w5, w4                   // way 필드 shift
	ubfx    x7, x1, #13, #15         // max set
2:
	mov     x9, x4
3:
	lsl     x6, x9, x5
	orr     x11, x10, x6
	lsl     x6, x7, x2
	orr     x11, x11, x6
	dc      isw, x11
	subs    x9, x9, #1
	b.ge    3b
	subs    x7, x7, #1
	b.ge    2b
4:
	add     x10, x10, #2
	cmp     x3, x10
	b.gt    1b
5:
	dsb     sy
	isb
	
	// SystemInit Call
	bl SystemInit

	b _start
	
core1_init :
	// L1 D-cache만 set/way 방식으로 무효화 (Core 1 전용)
	// csselr_el1 = 0 (Level 1 Data cache 선택)
	mov     x10, #0
	msr     csselr_el1, x10
	isb
	mrs     x1, ccsidr_el1
	and     x2, x1, #7
	add     x2, x2, #4               // x2 = log2(line bytes)
	ubfx    x4, x1, #3, #10          // x4 = max way
	clz     w5, w4                   // w5 = way 필드 bit shift 위치
	ubfx    x7, x1, #13, #15         // x7 = max set
2:                                   // Set 루프
	mov     x9, x4                   // x9 = way 카운터 초기화
3:                                   // Way 루프
	lsl     x6, x9, x5               // way 번호 시프트
	lsl     x11, x7, x2              // set 번호 시프트 (Level이 0이므로 x10을 OR할 필요 없음)
	orr     x11, x11, x6             // set + way 결합
	dc      isw, x11                 // 해당 Set/Way 캐시 라인 무효화
	subs    x9, x9, #1
	b.ge    3b
	subs    x7, x7, #1
	b.ge    2b
	dsb     sy
	isb

	ldr x5, =__stack_core1_el3_end__
	mov sp, x5

	ldr x0, =__stack_core1_el1_end__
	msr sp_el1, x0

	ldr x0, =__stack_core1_el0_end__
	msr sp_el0, x0

	ldr x5, =__tbss_start__-0x10
	msr tpidr_el0, x5

	bl SystemInit1

	ldr x0, =(SPSR_MODE_EL1t | SPSR_IRQ_MASK | SPSR_FIQ_MASK)
	msr spsr_el3, x0

	mov x0, #0
	mov x1, #0

	ldr x2, =main1
	msr elr_el3, x2
	eret

END_FUNC Reset_Handler

.weak synchronousExceptionHandler
.weak irqExceptionHandler
.weak fiqExceptionHandler
.weak sErrorExceptionHandler
.global yss_switchContext

.section .init, "ax"
	.balign 0x800
	.global _vectors
_vectors:
current_el_sp0_sync:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl synchronousExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
current_el_sp0_irq:
	stp x0, x1, [sp, #-16]!
	movz x1, #0x2000
	movk x1, #0x5080, lsl #16
	ldr w0, [x1, #0xc]
	and w0, w0, #0x3FF
	str w0, [x1, #0x10]
	cbz w0, pendsv

	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl irqExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
current_el_sp0_fiq:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl fiqExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
current_el_sp0_serror:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl sErrorExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
current_el_spx_sync:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl synchronousExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
current_el_spx_irq:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl irqExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
current_el_spx_fiq:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl fiqExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
current_el_spx_serror:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl sErrorExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

lower_el_aarch64_sync:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl synchronousExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
lower_el_aarch64_irq:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl irqExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
lower_el_aarch64_fiq:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl fiqExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
lower_el_aarch64_serror:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl sErrorExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
lower_el_aarch32_sync:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl synchronousExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
lower_el_aarch32_irq:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl irqExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
lower_el_aarch32_fiq:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl fiqExceptionHandler
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

	.balign 0x80
lower_el_aarch32_serror:
	stp x0, x1, [sp, #-16]!
	stp x2, x3, [sp, #-16]!
	stp x4, x5, [sp, #-16]!
	stp x6, x7, [sp, #-16]!
	stp x8, x9, [sp, #-16]!
	stp x10, x11, [sp, #-16]!
	stp x12, x13, [sp, #-16]!
	stp x14, x15, [sp, #-16]!
	stp x16, x17, [sp, #-16]!
	stp x18, x30, [sp, #-16]!
	bl sErrorExceptionHandler 
	ldp x18, x30, [sp], #16	
	ldp x16, x17, [sp], #16
	ldp x14, x15, [sp], #16
	ldp x12, x13, [sp], #16
	ldp x10, x11, [sp], #16
	ldp x8, x9, [sp], #16
	ldp x6, x7, [sp], #16
	ldp x4, x5, [sp], #16
	ldp x2, x3, [sp], #16
	ldp x0, x1, [sp], #16
	eret

pendsv :
	ldp x0, x1, [sp], #16
	str x30, [sp, #-16]!
	mrs x30, sp_el0
	
	stp x0, x1, [x30, #-16]!
	mov x0, x30	
	stp x2, x3, [x0, #-16]!
	stp x4, x5, [x0, #-16]!
	stp x6, x7, [x0, #-16]!
	stp x8, x9, [x0, #-16]!
	stp x10, x11, [x0, #-16]!
	stp x12, x13, [x0, #-16]!
	stp x14, x15, [x0, #-16]!
	stp x16, x17, [x0, #-16]!
	stp x18, x19, [x0, #-16]!
	stp x20, x21, [x0, #-16]!
	stp x22, x23, [x0, #-16]!
	stp x24, x25, [x0, #-16]!
	stp x26, x27, [x0, #-16]!
	stp x28, x29, [x0, #-16]!
	ldr x30, [sp], #16
	str x30, [x0, #-16]!

	mrs x1, spsr_el1
	mrs x2, elr_el1
	stp x1, x2, [x0, #-16]!

	stp q0, q1, [x0, #-32]!
	stp q2, q3, [x0, #-32]!
	stp q4, q5, [x0, #-32]!
	stp q6, q7, [x0, #-32]!
	stp q8, q9, [x0, #-32]!
	stp q10, q11, [x0, #-32]!
	stp q12, q13, [x0, #-32]!
	stp q14, q15, [x0, #-32]!
	stp q16, q17, [x0, #-32]!
	stp q18, q19, [x0, #-32]!
	stp q20, q21, [x0, #-32]!
	stp q22, q23, [x0, #-32]!
	stp q24, q25, [x0, #-32]!
	stp q26, q27, [x0, #-32]!
	stp q28, q29, [x0, #-32]!
	stp q30, q31, [x0, #-32]!
    mrs x1, fpsr
    mrs x2, fpcr
    stp x1, x2, [x0, #-16]!
 	bl yss_switchContext
    ldp x1, x2, [x0], #16
	msr fpcr, x2
	msr fpsr, x1
	ldp q30, q31, [x0], #32
	ldp q28, q29, [x0], #32
	ldp q26, q27, [x0], #32
	ldp q24, q25, [x0], #32
	ldp q22, q23, [x0], #32
	ldp q20, q21, [x0], #32
	ldp q18, q19, [x0], #32
	ldp q16, q17, [x0], #32
	ldp q14, q15, [x0], #32
	ldp q12, q13, [x0], #32
	ldp q10, q11, [x0], #32
	ldp q8, q9, [x0], #32
	ldp q6, q7, [x0], #32
	ldp q4, q5, [x0], #32
	ldp q2, q3, [x0], #32
	ldp q0, q1, [x0], #32

	ldp x1, x2, [x0], #16
	msr spsr_el1, x1
	msr elr_el1, x2

	ldr x30, [x0], #16
	ldp x28, x29, [x0], #16	
	ldp x26, x27, [x0], #16	
	ldp x24, x25, [x0], #16	
	ldp x22, x23, [x0], #16	
	ldp x20, x21, [x0], #16	
	ldp x18, x19, [x0], #16	
	ldp x16, x17, [x0], #16
	ldp x14, x15, [x0], #16
	ldp x12, x13, [x0], #16
	ldp x10, x11, [x0], #16
	ldp x8, x9, [x0], #16
	ldp x6, x7, [x0], #16
	ldp x4, x5, [x0], #16
	ldp x2, x3, [x0], #16
	
	str x30, [sp, #-16]!
	mov x30, x0
	ldp x0, x1, [x30], #16
	msr sp_el0, x30
	ldr x30, [sp], #16
	eret

#endif

/*************************** End of file ****************************/
