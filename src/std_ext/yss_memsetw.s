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
	.func memsetw
	.type memsetw, %function
	.global memsetw
	.section .text, "ax"

/**
 * @fn memsetw
 * @brief High-performance word-wise memory fill routine optimized for ARM Cortex-M.
 *
 * @details
 * Fills a memory block with a specified 32-bit value. The function assumes the destination
 * address is already 4-byte aligned. It writes memory in 512-byte blocks.
 *
 * Register Map:
 *   r0 : Destination pointer (advanced as memory is written)
 *   r1 : Value to fill (32-bit pattern)
 *   r2 : Size of memory to fill, in bytes (must be a multiple of 4)
 *   r3 : Temp register for size checking
 *   r4-r7 : Registers holding the 32-bit pattern for block storage
 */
memsetw:
	push {r3-r7}
	
	// Copy 32-bit pattern to registers r4-r7 for fast block storage
	mov r4, r1
	mov r5, r1
	mov r6, r1
	mov r7, r1

repeat:
	// Process large block fills (512-byte chunks)
	movs r1, #512
	subs r3, r2, r1
	bge greater              // Jump to fill 512 bytes if size >= 512

	// Branch table jumping trick for sizes < 512
	ands r3, r2, #0xf        // Save remaining bytes modulo 16
	bic r2, #0xf             // Align size to 16-byte boundary
	subs r1, r1, r2          // Calculate instruction offset: offset = 512 - (size & ~15)
	lsr r1, r1, #3           // Divide offset by 8 (each stmia instruction takes 4 bytes, 2 instructions per 32 bytes)
	adds r1, r1, #2          // Adjust PC target offset
	movs r2, r3              // Restore remaining bytes modulo 16 to r2
	bic r2, #0x3             // Align remainder to 4 bytes
	add pc, pc, r1           // Branch into the middle of the greater loop block fill

greater:
	subs r2, #512
	// Unrolled block store: 32 STMIA instructions write 512 bytes (16 bytes per instruction)
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
	bhi repeat               // Repeat block fill if remaining size > 16 bytes
	movs r2, r2
	beq finish               // Done if exactly 0 bytes remaining

	// Fill 8-byte chunk if possible
	subs r3, r2, #8
	blt sub4
	stmia   R0!,{R4-R5}
	subs r2, #8

sub4:
	// Fill final 4-byte word if remaining count is 4
	movs r2, r2
	beq finish
	str r4, [r0], #4

finish:
	pop {r3-r7}
	bx lr

#endif