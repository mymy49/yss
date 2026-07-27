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
	.func memset
	.type memset, %function
	.global memset
	.section .text, "ax"

/**
 * @fn memset
 * @brief High-performance memory block set routine optimized for ARM Cortex-M.
 *
 * @details
 * Fills a memory block with a specified 8-bit byte value. The function duplicates the
 * 8-bit value into a 32-bit word, then checks target alignment.
 * For aligned addresses, it fills the memory in blocks of up to 256 bytes using STMIA.
 * For unaligned addresses, it uses unaligned word writes in blocks of up to 128 bytes.
 *
 * Register Map:
 *   r0 : Destination pointer (advanced as memory is written)
 *   r1 : Value to fill (lower 8 bits contain the fill byte)
 *   r2 : Size of memory to fill, in bytes
 *   r3 : Temp register for address and alignment checks
 *   r4-r7 : Registers populated with the 32-bit duplicated value pattern
 */
memset:
	push {r3-r7}
	
	// Duplicate 8-bit value in r1 across all 4 bytes of the register
	bic r1, #0xffffff00      // Clear upper 24 bits
	lsl r3, r1, #8           // Shift byte to second byte position
	orr r1, r3               // Combine
	lsl r3, r1, #16          // Shift 16-bit halfword to upper 16 bits
	orr r1, r3               // Combine (r1 now holds duplicated 32-bit pattern)

	// Check if destination pointer (r0) is 4-byte aligned
	mov r3, r0
	ands r3, 0x3
	bne unalignedRepeat      // Jump to unaligned handler if not 4-byte aligned

	// Duplicate patterns to registers r4-r7 for fast block storage
	mov r4, r1
	mov r5, r4
	mov r6, r4
	mov r7, r4

repeat:
	// Process large block fills (256-byte chunks)
	movs r1, #256
	subs r3, r2, r1
	bge greater              // Jump to fill 256 bytes if size >= 256

	// Branch table jumping trick for sizes < 256
	ands r3, r2, #0xf        // Save remaining bytes modulo 16
	bic r2, #0xf             // Align size to 16-byte boundary
	subs r1, r1, r2          // Calculate instruction offset: offset = 256 - (size & ~15)
	lsr r1, r1, #3           // Divide offset by 8 (each stmia instruction takes 4 bytes, 2 instructions per 32 bytes)
	adds r1, r1, #2          // Adjust PC target offset
	movs r2, r3              // Restore remaining bytes modulo 16 to r2
	add pc, pc, r1           // Branch into the middle of the greater loop block fill

greater:
	subs r2, #256
	// Unrolled block store: 16 STMIA instructions write 256 bytes (16 bytes per instruction)
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
	// Fill 4-byte word if possible
	subs r3, r2, #4
	blt sub2
	str r4, [r0], #4
	subs r2, #4

sub2:
	// Fill 2-byte halfword if possible
	subs r3, r2, #2
	blt sub1
	strh r4, [r0], #2
	subs r2, #2

sub1:
	// Fill final 1-byte character if possible
	movs r2, r2
	beq finish
	strb r4, [r0], #1

finish:
	pop {r3-r7}
	bx lr

unalignedRepeat:
	// Unaligned memory fill handler using LDR/STR instructions
	movs r4, #128
	subs r3, r2, r4
	bge greaterUnaligned     // Jump to fill 128 bytes if size >= 128

	// Branch table jumping trick for unaligned sizes < 128
	ands r3, r2, #0x3        // Save remaining bytes modulo 4
	bic r2, #0x3             // Align size to 4-byte boundary
	subs r4, r4, r2          // Calculate instruction offset: offset = 128 - (size & ~3)
	movs r2, r3              // Restore remaining bytes modulo 4 to r2
	add pc, pc, r4           // Branch into the middle of greaterUnaligned loop

greaterUnaligned:
	subs r2, #128
	// Unrolled unaligned word store: 32 STR instructions write 128 bytes
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
	bhi unalignedRepeat      // Loop back if size > 4 bytes
	subs r3, r2, #2
	blt unalignedSub1
	strh r1, [r0], #2
	subs r2, #2

unalignedSub1:
	movs r2, r2
	beq finish
	strb r1, [r0], #1
	b finish

	.endfunc
#endif
