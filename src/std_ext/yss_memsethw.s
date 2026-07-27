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
	.func memsethw
	.type memsethw, %function
	.global memsethw
	.section .text, "ax"

/**
 * @fn memsethw
 * @brief High-performance halfword-wise memory fill routine optimized for ARM Cortex-M3/M4/M7.
 *
 * @details
 * Fills a memory block with a specified 16-bit value. The function duplicates the
 * 16-bit value into a 32-bit word, aligns the target address to a 4-byte boundary if needed
 * by writing a single halfword, and then writes memory in 512-byte blocks.
 *
 * Register Map:
 *   r0 : Destination pointer (advanced as memory is written)
 *   r1 : Value to fill (lower 16 bits contain the fill halfword)
 *   r2 : Size of memory to fill, in bytes (must be a multiple of 2)
 *   r3 : Temp register for duplication and alignment checks
 *   r4-r7 : Registers holding the duplicated 32-bit pattern
 */
memsethw:
	push {r4-r7}
	ands r2, r2
	beq finish               // Exit if size is 0
	
	// Duplicate 16-bit value in r1 across both halves of the 32-bit register
	mov r4, #0xffff
	lsl r4, #16
	bic r1, r4               // Clear upper 16 bits of r1
	lsl r3, r1, #16          // Shift lower 16 bits to upper 16 bits
	orr r4, r1, r3           // Combine (r4 now holds duplicated 32-bit pattern)
	
	// Copy pattern to registers r5-r7 for fast block storage
	mov r5, r4
	mov r6, r4
	mov r7, r4

	// Check if destination pointer (r0) is 4-byte aligned
	ands r1, r0, #3
	beq repeat               // Jump to block fill if already 4-byte aligned
	
	// Target is 2-byte aligned but not 4-byte aligned. Write 1 halfword to align it.
	strh r4, [R0]
	adds r0, #2
	subs r2, #2

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
	bic r2, #1               // Align remainder to 2 bytes
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
	// Fill 4-byte word if possible
	subs r3, r2, #4
	blt sub2
	str r4, [r0], #4
	subs r2, #4

sub2:
	// Fill final 2-byte halfword if possible
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

/**
 * @fn memsethw
 * @brief Halfword-wise memory fill routine optimized for ARM Cortex-M0.
 *
 * @details
 * Cortex-M0 version. Since Cortex-M0 has fewer registers and registers must be used carefully,
 * this version pushes {r4-r5}. It duplicates the 16-bit fill value to a 32-bit register pattern,
 * aligns the destination address to a 4-byte boundary, and then unrolls the loop to fill 128 bytes at a time.
 */
memsethw:
	push {r4-r5}
	ands r2, r2
	beq finish               // Exit if size is 0
	
	// Duplicate 16-bit value in r1 across both halves of the 32-bit register
	ldr r4, =0xFFFF0000
	bics r1, r4              // Clear upper 16 bits of r1
	lsls r3, r1, #16         // Shift lower 16 bits to upper 16 bits
	mov r4, r1
	orrs r4, r3              // Combine (r4 now holds duplicated 32-bit pattern)
	
	// Enforce 2-byte alignment on the count (clear LSB of r2)
	movs r5, #1
	bics r2, r5

	// Check if destination pointer (r0) is 4-byte aligned
	movs r5, #3
	ands r5, r0, r5
	beq repeat               // Jump to block fill if already 4-byte aligned
	
	// Target is 2-byte aligned but not 4-byte aligned. Write 1 halfword to align it.
	strh r4, [R0]
	adds r0, #2
	subs r2, #2

repeat:
	// Process block fills (128-byte chunks)
	ldr r1, =128
	subs r3, r2, r1
	bge greater              // Jump to fill 128 bytes if size >= 128

	// Branch table jumping trick for sizes < 128
	movs r5, #0x03
	ands r3, r3, r5          // Save remainder modulo 4 (aligned to word)
	bics r2, r5              // Clear lower bits of size
	subs r1, r1, r2          // Calculate instruction offset
	movs r2, r3              // Restore remainder
	add pc, pc, r1           // Branch into the middle of the unrolled store sequence

greater:
	subs r2, #128
	// Unrolled block store: 32 STR instructions write 128 bytes (4 bytes per instruction)
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
	bge repeat               // Repeat block fill if size >= 4
	movs r2, r2
	beq finish               // Done if exactly 0 bytes remaining
	
	// Write final 2-byte halfword if remaining count is 2
	strh r4, [r0]

finish:
	pop {r4-r5}
	bx lr
#endif
