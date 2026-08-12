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

/**
 * @fn memcpy
 * @brief High-performance memory block copy routine optimized for ARM Cortex-M.
 *
 * @details
 * This function copies a block of memory. It checks the 4-byte alignment of the source
 * and destination pointers. If aligned, it copies in large blocks (up to 256 bytes) using LDMIA/STMIA.
 * Otherwise, it uses unaligned word accesses in blocks of up to 128 bytes.
 *
 * Note: Unlike standard memcpy, this function returns the updated (advanced) destination address
 * in register r0.
 *
 * Register Map:
 *   r0 : Destination pointer (advanced as copy progresses)
 *   r1 : Source pointer (advanced as copy progresses)
 *   r2 : Number of bytes remaining to be copied
 *   r3-r6 : Temp registers used for block copies
 */
memcpy:
	push {r3-r6}
	// Check word alignment (lower 2 bits of source OR destination)
	orr r3, r0, r1
	ands r3, 0x3
	bne unalignedHanler      // Branch if either address is not 4-byte aligned

repeat:
	// Process large block copies (256-byte chunks)
	movs r4, #256
	subs r3, r2, r4
	bge greater              // Jump to copy 256 bytes if size >= 256
	
	// Duff's Device-like branch table jumping trick for sizes < 256
	ands r3, r2, #0xf        // Save remaining bytes modulo 16
	bic r2, #0xf             // Align size to 16-byte boundary
	subs r4, r4, r2          // Calculate instruction offset: offset = 256 - (size & ~15)
	lsrs r4, r4, #2          // Divide offset by 4 (each ldmia/stmia pair takes 8 bytes, so 2 instructions)
	adds r4, r4, #2          // Adjust PC target offset
	movs r2, r3              // Restore remaining bytes modulo 16 to r2
	add pc, pc, r4           // Branch into the middle of the greater loop block copy

greater:
	subs r2, #256
	// Unrolled block copy: 16 pairs of LDMIA/STMIA copy 256 bytes (16 bytes per pair)
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
	bge repeat               // If remaining size >= 16 bytes, repeat aligned copy
	movs r2, r2
	beq finish               // Done if exactly 0 bytes remaining

	// Copy 8-byte chunk if possible
	subs r3, r2, #8
	blt sub4
	ldmia   R1!,{R3-R4}
	stmia   R0!,{R3-R4}
	subs r2, #8

sub4:
	// Copy 4-byte word if possible
	subs r3, r2, #4
	blt sub2
	ldr r3, [r1], #4
	str r3, [r0], #4
	subs r2, #4

sub2:
	// Copy 2-byte halfword if possible
	subs r3, r2, #2
	blt sub1
	ldrh r3, [r1], #2
	strh r3, [r0], #2
	subs r2, #2

sub1:
	// Copy final 1-byte character if possible
	movs r2, r2
	beq finish
	ldrb r3, [r1], #1
	strb r3, [r0], #1

finish:
	pop {r3-r6}
	bx lr

unalignedHanler:
	// Unaligned copy handler using unaligned LDR/STR instructions
	movs r4, #128
	subs r3, r2, r4
	bge greaterUnaligned     // Jump to copy 128 bytes if size >= 128

	// Branch table jumping trick for unaligned sizes < 128
	ands r3, r2, #0x3        // Save remaining bytes modulo 4
	bic r2, #0x3             // Align size to 4-byte boundary
	subs r4, r4, r2          // Calculate instruction offset: offset = 128 - (size & ~3)
	lsls r4, r4, #1          // Multiply offset by 2 (each LDR/STR pair takes 4 instructions/8 bytes)
	movs r2, r3              // Restore remaining bytes modulo 4 to r2
	add pc, pc, r4           // Branch into the middle of greaterUnaligned copy loop

greaterUnaligned:
	subs r2, #128
	// Unrolled unaligned word copies (32 LDR/STR instruction pairs)
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
	bhi unalignedHanler      // Loop back to copy another 128/4 bytes
	b sub4                   // Process remaining <4 bytes

	.endfunc
#endif
