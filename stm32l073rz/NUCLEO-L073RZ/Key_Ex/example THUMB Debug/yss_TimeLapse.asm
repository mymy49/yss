	.cpu cortex-m0plus
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"yss_TimeLapse.cpp"
	.text
.Ltext0:
	.section	.text._ZN9TimeLapseC2Ev,"ax",%progbits
	.align	1
	.global	_ZN9TimeLapseC2Ev
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	_ZN9TimeLapseC2Ev, %function
_ZN9TimeLapseC2Ev:
.LFB1:
	.file 1 "/home/mymy49/library/yss/yss/util/yss_TimeLapse.cpp"
	.loc 1 5 1
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{lr}
.LCFI0:
	sub	sp, sp, #12
.LCFI1:
	str	r0, [sp, #4]
.LBB2:
	.loc 1 7 35
	bl	_ZN4time14getRunningUsecEv
	movs	r2, r0
	movs	r3, r1
	.loc 1 7 13
	ldr	r1, [sp, #4]
	str	r2, [r1]
	str	r3, [r1, #4]
.LBE2:
	.loc 1 8 1
	ldr	r3, [sp, #4]
	movs	r0, r3
	add	sp, sp, #12
	@ sp needed
	pop	{pc}
.LFE1:
	.size	_ZN9TimeLapseC2Ev, .-_ZN9TimeLapseC2Ev
	.global	_ZN9TimeLapseC1Ev
	.thumb_set _ZN9TimeLapseC1Ev,_ZN9TimeLapseC2Ev
	.section	.text._ZN9TimeLapse5resetEv,"ax",%progbits
	.align	1
	.global	_ZN9TimeLapse5resetEv
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	_ZN9TimeLapse5resetEv, %function
_ZN9TimeLapse5resetEv:
.LFB3:
	.loc 1 11 1
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{lr}
.LCFI2:
	sub	sp, sp, #12
.LCFI3:
	str	r0, [sp, #4]
	.loc 1 12 35
	bl	_ZN4time14getRunningUsecEv
	movs	r2, r0
	movs	r3, r1
	.loc 1 12 13
	ldr	r1, [sp, #4]
	str	r2, [r1]
	str	r3, [r1, #4]
	.loc 1 13 1
	nop
	add	sp, sp, #12
	@ sp needed
	pop	{pc}
.LFE3:
	.size	_ZN9TimeLapse5resetEv, .-_ZN9TimeLapse5resetEv
	.section	.text._ZN9TimeLapse7getUsecEv,"ax",%progbits
	.align	1
	.global	_ZN9TimeLapse7getUsecEv
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	_ZN9TimeLapse7getUsecEv, %function
_ZN9TimeLapse7getUsecEv:
.LFB4:
	.loc 1 16 1
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{lr}
.LCFI4:
	sub	sp, sp, #12
.LCFI5:
	str	r0, [sp, #4]
	.loc 1 17 29
	bl	_ZN4time14getRunningUsecEv
	movs	r2, r0
	movs	r3, r1
	.loc 1 17 32
	movs	r1, r2
	.loc 1 17 34
	ldr	r3, [sp, #4]
	ldr	r2, [r3]
	ldr	r3, [r3, #4]
	.loc 1 17 32
	movs	r3, r2
	.loc 1 17 34
	subs	r3, r1, r3
	.loc 1 18 1
	movs	r0, r3
	add	sp, sp, #12
	@ sp needed
	pop	{pc}
.LFE4:
	.size	_ZN9TimeLapse7getUsecEv, .-_ZN9TimeLapse7getUsecEv
	.global	__aeabi_uldivmod
	.section	.text._ZN9TimeLapse7getMsecEv,"ax",%progbits
	.align	1
	.global	_ZN9TimeLapse7getMsecEv
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	_ZN9TimeLapse7getMsecEv, %function
_ZN9TimeLapse7getMsecEv:
.LFB5:
	.loc 1 21 1
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{lr}
.LCFI6:
	sub	sp, sp, #12
.LCFI7:
	str	r0, [sp, #4]
	.loc 1 22 30
	bl	_ZN4time14getRunningUsecEv
	.loc 1 22 35
	ldr	r3, [sp, #4]
	ldr	r2, [r3]
	ldr	r3, [r3, #4]
	.loc 1 22 33
	subs	r0, r0, r2
	sbcs	r1, r1, r3
	.loc 1 22 47
	movs	r2, #250
	lsls	r2, r2, #2
	movs	r3, #0
	bl	__aeabi_uldivmod
.LVL0:
	movs	r2, r0
	movs	r3, r1
	.loc 1 22 49
	movs	r3, r2
	.loc 1 23 1
	movs	r0, r3
	add	sp, sp, #12
	@ sp needed
	pop	{pc}
.LFE5:
	.size	_ZN9TimeLapse7getMsecEv, .-_ZN9TimeLapse7getMsecEv
	.section	.text._ZN9TimeLapse6getSecEv,"ax",%progbits
	.align	1
	.global	_ZN9TimeLapse6getSecEv
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	_ZN9TimeLapse6getSecEv, %function
_ZN9TimeLapse6getSecEv:
.LFB6:
	.loc 1 26 1
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{lr}
.LCFI8:
	sub	sp, sp, #12
.LCFI9:
	str	r0, [sp, #4]
	.loc 1 27 30
	bl	_ZN4time14getRunningUsecEv
	.loc 1 27 35
	ldr	r3, [sp, #4]
	ldr	r2, [r3]
	ldr	r3, [r3, #4]
	.loc 1 27 33
	subs	r0, r0, r2
	sbcs	r1, r1, r3
	.loc 1 27 47
	ldr	r2, .L10
	movs	r3, #0
	bl	__aeabi_uldivmod
.LVL1:
	movs	r2, r0
	movs	r3, r1
	.loc 1 27 49
	movs	r3, r2
	.loc 1 28 1
	movs	r0, r3
	add	sp, sp, #12
	@ sp needed
	pop	{pc}
.L11:
	.align	2
.L10:
	.word	1000000
.LFE6:
	.size	_ZN9TimeLapse6getSecEv, .-_ZN9TimeLapse6getSecEv
	.section	.debug_frame,"",%progbits
.Lframe0:
	.4byte	.LECIE0-.LSCIE0
.LSCIE0:
	.4byte	0xffffffff
	.byte	0x3
	.ascii	"\000"
	.uleb128 0x1
	.sleb128 -4
	.uleb128 0xe
	.byte	0xc
	.uleb128 0xd
	.uleb128 0
	.align	2
.LECIE0:
.LSFDE0:
	.4byte	.LEFDE0-.LASFDE0
.LASFDE0:
	.4byte	.Lframe0
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.byte	0x4
	.4byte	.LCFI0-.LFB1
	.byte	0xe
	.uleb128 0x4
	.byte	0x8e
	.uleb128 0x1
	.byte	0x4
	.4byte	.LCFI1-.LCFI0
	.byte	0xe
	.uleb128 0x10
	.align	2
.LEFDE0:
.LSFDE2:
	.4byte	.LEFDE2-.LASFDE2
.LASFDE2:
	.4byte	.Lframe0
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.byte	0x4
	.4byte	.LCFI2-.LFB3
	.byte	0xe
	.uleb128 0x4
	.byte	0x8e
	.uleb128 0x1
	.byte	0x4
	.4byte	.LCFI3-.LCFI2
	.byte	0xe
	.uleb128 0x10
	.align	2
.LEFDE2:
.LSFDE4:
	.4byte	.LEFDE4-.LASFDE4
.LASFDE4:
	.4byte	.Lframe0
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.byte	0x4
	.4byte	.LCFI4-.LFB4
	.byte	0xe
	.uleb128 0x4
	.byte	0x8e
	.uleb128 0x1
	.byte	0x4
	.4byte	.LCFI5-.LCFI4
	.byte	0xe
	.uleb128 0x10
	.align	2
.LEFDE4:
.LSFDE6:
	.4byte	.LEFDE6-.LASFDE6
.LASFDE6:
	.4byte	.Lframe0
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.byte	0x4
	.4byte	.LCFI6-.LFB5
	.byte	0xe
	.uleb128 0x4
	.byte	0x8e
	.uleb128 0x1
	.byte	0x4
	.4byte	.LCFI7-.LCFI6
	.byte	0xe
	.uleb128 0x10
	.align	2
.LEFDE6:
.LSFDE8:
	.4byte	.LEFDE8-.LASFDE8
.LASFDE8:
	.4byte	.Lframe0
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.byte	0x4
	.4byte	.LCFI8-.LFB6
	.byte	0xe
	.uleb128 0x4
	.byte	0x8e
	.uleb128 0x1
	.byte	0x4
	.4byte	.LCFI9-.LCFI8
	.byte	0xe
	.uleb128 0x10
	.align	2
.LEFDE8:
	.text
.Letext0:
	.file 2 "/home/mymy49/library/yss/yss/inc/util/TimeLapse.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x1d9
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF587
	.byte	0x4
	.4byte	.LASF588
	.4byte	.LASF589
	.4byte	.Ldebug_ranges0+0
	.4byte	0
	.4byte	.Ldebug_line0
	.4byte	.Ldebug_macro0
	.uleb128 0x2
	.4byte	.LASF571
	.byte	0x8
	.byte	0x2
	.byte	0x19
	.byte	0x7
	.4byte	0xd7
	.uleb128 0x3
	.4byte	.LASF590
	.byte	0x2
	.byte	0x1b
	.byte	0x15
	.4byte	0xd7
	.byte	0
	.uleb128 0x4
	.4byte	.LASF571
	.byte	0x2
	.byte	0x1d
	.byte	0x2
	.4byte	.LASF573
	.4byte	0xde
	.byte	0x1
	.4byte	0x5c
	.4byte	0x62
	.uleb128 0x5
	.4byte	0xde
	.byte	0
	.uleb128 0x6
	.4byte	.LASF577
	.byte	0x2
	.byte	0x1e
	.byte	0xa
	.4byte	.LASF579
	.byte	0x1
	.4byte	0x77
	.4byte	0x7d
	.uleb128 0x5
	.4byte	0xde
	.byte	0
	.uleb128 0x4
	.4byte	.LASF572
	.byte	0x2
	.byte	0x1f
	.byte	0xf
	.4byte	.LASF574
	.4byte	0xe9
	.byte	0x1
	.4byte	0x96
	.4byte	0x9c
	.uleb128 0x5
	.4byte	0xde
	.byte	0
	.uleb128 0x4
	.4byte	.LASF575
	.byte	0x2
	.byte	0x20
	.byte	0xf
	.4byte	.LASF576
	.4byte	0xe9
	.byte	0x1
	.4byte	0xb5
	.4byte	0xbb
	.uleb128 0x5
	.4byte	0xde
	.byte	0
	.uleb128 0x7
	.4byte	.LASF578
	.byte	0x2
	.byte	0x21
	.byte	0xf
	.4byte	.LASF580
	.4byte	0xe9
	.byte	0x1
	.4byte	0xd0
	.uleb128 0x5
	.4byte	0xde
	.byte	0
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.byte	0x7
	.4byte	.LASF581
	.uleb128 0x9
	.byte	0x4
	.4byte	0x29
	.uleb128 0xa
	.4byte	0xde
	.uleb128 0x8
	.byte	0x4
	.byte	0x7
	.4byte	.LASF582
	.uleb128 0x8
	.byte	0x4
	.byte	0x7
	.4byte	.LASF583
	.uleb128 0x8
	.byte	0x1
	.byte	0x2
	.4byte	.LASF584
	.uleb128 0x8
	.byte	0x2
	.byte	0x7
	.4byte	.LASF585
	.uleb128 0xb
	.4byte	0xbb
	.byte	0x1
	.byte	0x19
	.byte	0xe
	.4byte	0x11f
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x12c
	.uleb128 0xc
	.4byte	.LASF586
	.4byte	0xe4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xb
	.4byte	0x9c
	.byte	0x1
	.byte	0x14
	.byte	0xe
	.4byte	0x146
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x153
	.uleb128 0xc
	.4byte	.LASF586
	.4byte	0xe4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xb
	.4byte	0x7d
	.byte	0x1
	.byte	0xf
	.byte	0xe
	.4byte	0x16d
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x17a
	.uleb128 0xc
	.4byte	.LASF586
	.4byte	0xe4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xb
	.4byte	0x62
	.byte	0x1
	.byte	0xa
	.byte	0x6
	.4byte	0x194
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x1a1
	.uleb128 0xc
	.4byte	.LASF586
	.4byte	0xe4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xd
	.4byte	0x43
	.byte	0x1
	.byte	0x5
	.byte	0x1
	.4byte	0x1b2
	.byte	0
	.4byte	0x1bc
	.uleb128 0xe
	.4byte	.LASF586
	.4byte	0xe4
	.byte	0
	.uleb128 0xf
	.4byte	0x1a1
	.4byte	.LASF591
	.4byte	0x1d3
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x10
	.4byte	0x1b2
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x2134
	.uleb128 0x19
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.uleb128 0x2119
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x64
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x47
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x47
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_pubnames,"",%progbits
	.4byte	0x80
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x1dd
	.4byte	0x105
	.ascii	"TimeLapse::getSec\000"
	.4byte	0x12c
	.ascii	"TimeLapse::getMsec\000"
	.4byte	0x153
	.ascii	"TimeLapse::getUsec\000"
	.4byte	0x17a
	.ascii	"TimeLapse::reset\000"
	.4byte	0x1a1
	.ascii	"TimeLapse::TimeLapse\000"
	.4byte	0
	.section	.debug_pubtypes,"",%progbits
	.4byte	0x7e
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x1dd
	.4byte	0xd7
	.ascii	"long long unsigned int\000"
	.4byte	0xe9
	.ascii	"unsigned int\000"
	.4byte	0x29
	.ascii	"TimeLapse\000"
	.4byte	0xf0
	.ascii	"long unsigned int\000"
	.4byte	0xf7
	.ascii	"bool\000"
	.4byte	0xfe
	.ascii	"short unsigned int\000"
	.4byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x3c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.4byte	.LFB1
	.4byte	.LFE1
	.4byte	.LFB3
	.4byte	.LFE3
	.4byte	.LFB4
	.4byte	.LFE4
	.4byte	.LFB5
	.4byte	.LFE5
	.4byte	.LFB6
	.4byte	.LFE6
	.4byte	0
	.4byte	0
	.section	.debug_macro,"",%progbits
.Ldebug_macro0:
	.2byte	0x4
	.byte	0x2
	.4byte	.Ldebug_line0
	.byte	0x7
	.4byte	.Ldebug_macro2
	.byte	0x3
	.uleb128 0
	.uleb128 0x1
	.byte	0x3
	.uleb128 0x1
	.uleb128 0x2
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF484
	.byte	0x4
	.file 3 "/home/mymy49/library/yss/yss/inc/util/time.h"
	.byte	0x3
	.uleb128 0x2
	.uleb128 0x3
	.file 4 "/home/mymy49/library/yss/stm32l073rz/NUCLEO-L073RZ/Key_Ex/prj/inc/config.h"
	.byte	0x3
	.uleb128 0x16
	.uleb128 0x4
	.byte	0x7
	.4byte	.Ldebug_macro3
	.byte	0x4
	.byte	0x5
	.uleb128 0x19
	.4byte	.LASF567
	.byte	0x4
	.file 5 "/home/mymy49/library/yss/yss/inc/yss/thread.h"
	.byte	0x3
	.uleb128 0x3
	.uleb128 0x5
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF568
	.file 6 "/home/mymy49/library/yss/yss/inc/yss/Mutex.h"
	.byte	0x3
	.uleb128 0x19
	.uleb128 0x6
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF569
	.byte	0x4
	.byte	0x5
	.uleb128 0x2d
	.4byte	.LASF570
	.byte	0x4
	.byte	0x4
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.0.8dc5f9108d8a33ad381337f17c8974b1,comdat
.Ldebug_macro2:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0
	.4byte	.LASF0
	.byte	0x5
	.uleb128 0
	.4byte	.LASF1
	.byte	0x5
	.uleb128 0
	.4byte	.LASF2
	.byte	0x5
	.uleb128 0
	.4byte	.LASF3
	.byte	0x5
	.uleb128 0
	.4byte	.LASF4
	.byte	0x5
	.uleb128 0
	.4byte	.LASF5
	.byte	0x5
	.uleb128 0
	.4byte	.LASF6
	.byte	0x5
	.uleb128 0
	.4byte	.LASF7
	.byte	0x5
	.uleb128 0
	.4byte	.LASF8
	.byte	0x5
	.uleb128 0
	.4byte	.LASF9
	.byte	0x5
	.uleb128 0
	.4byte	.LASF10
	.byte	0x5
	.uleb128 0
	.4byte	.LASF11
	.byte	0x5
	.uleb128 0
	.4byte	.LASF12
	.byte	0x5
	.uleb128 0
	.4byte	.LASF13
	.byte	0x5
	.uleb128 0
	.4byte	.LASF14
	.byte	0x5
	.uleb128 0
	.4byte	.LASF15
	.byte	0x5
	.uleb128 0
	.4byte	.LASF16
	.byte	0x5
	.uleb128 0
	.4byte	.LASF17
	.byte	0x5
	.uleb128 0
	.4byte	.LASF18
	.byte	0x5
	.uleb128 0
	.4byte	.LASF19
	.byte	0x5
	.uleb128 0
	.4byte	.LASF20
	.byte	0x5
	.uleb128 0
	.4byte	.LASF21
	.byte	0x5
	.uleb128 0
	.4byte	.LASF22
	.byte	0x5
	.uleb128 0
	.4byte	.LASF23
	.byte	0x5
	.uleb128 0
	.4byte	.LASF24
	.byte	0x5
	.uleb128 0
	.4byte	.LASF25
	.byte	0x5
	.uleb128 0
	.4byte	.LASF26
	.byte	0x5
	.uleb128 0
	.4byte	.LASF27
	.byte	0x5
	.uleb128 0
	.4byte	.LASF28
	.byte	0x5
	.uleb128 0
	.4byte	.LASF29
	.byte	0x5
	.uleb128 0
	.4byte	.LASF30
	.byte	0x5
	.uleb128 0
	.4byte	.LASF31
	.byte	0x5
	.uleb128 0
	.4byte	.LASF32
	.byte	0x5
	.uleb128 0
	.4byte	.LASF33
	.byte	0x5
	.uleb128 0
	.4byte	.LASF34
	.byte	0x5
	.uleb128 0
	.4byte	.LASF35
	.byte	0x5
	.uleb128 0
	.4byte	.LASF36
	.byte	0x5
	.uleb128 0
	.4byte	.LASF37
	.byte	0x5
	.uleb128 0
	.4byte	.LASF38
	.byte	0x5
	.uleb128 0
	.4byte	.LASF39
	.byte	0x5
	.uleb128 0
	.4byte	.LASF40
	.byte	0x5
	.uleb128 0
	.4byte	.LASF41
	.byte	0x5
	.uleb128 0
	.4byte	.LASF42
	.byte	0x5
	.uleb128 0
	.4byte	.LASF43
	.byte	0x5
	.uleb128 0
	.4byte	.LASF44
	.byte	0x5
	.uleb128 0
	.4byte	.LASF45
	.byte	0x5
	.uleb128 0
	.4byte	.LASF46
	.byte	0x5
	.uleb128 0
	.4byte	.LASF47
	.byte	0x5
	.uleb128 0
	.4byte	.LASF48
	.byte	0x5
	.uleb128 0
	.4byte	.LASF49
	.byte	0x5
	.uleb128 0
	.4byte	.LASF50
	.byte	0x5
	.uleb128 0
	.4byte	.LASF51
	.byte	0x5
	.uleb128 0
	.4byte	.LASF52
	.byte	0x5
	.uleb128 0
	.4byte	.LASF53
	.byte	0x5
	.uleb128 0
	.4byte	.LASF54
	.byte	0x5
	.uleb128 0
	.4byte	.LASF55
	.byte	0x5
	.uleb128 0
	.4byte	.LASF56
	.byte	0x5
	.uleb128 0
	.4byte	.LASF57
	.byte	0x5
	.uleb128 0
	.4byte	.LASF58
	.byte	0x5
	.uleb128 0
	.4byte	.LASF59
	.byte	0x5
	.uleb128 0
	.4byte	.LASF60
	.byte	0x5
	.uleb128 0
	.4byte	.LASF61
	.byte	0x5
	.uleb128 0
	.4byte	.LASF62
	.byte	0x5
	.uleb128 0
	.4byte	.LASF63
	.byte	0x5
	.uleb128 0
	.4byte	.LASF64
	.byte	0x5
	.uleb128 0
	.4byte	.LASF65
	.byte	0x5
	.uleb128 0
	.4byte	.LASF66
	.byte	0x5
	.uleb128 0
	.4byte	.LASF67
	.byte	0x5
	.uleb128 0
	.4byte	.LASF68
	.byte	0x5
	.uleb128 0
	.4byte	.LASF69
	.byte	0x5
	.uleb128 0
	.4byte	.LASF70
	.byte	0x5
	.uleb128 0
	.4byte	.LASF71
	.byte	0x5
	.uleb128 0
	.4byte	.LASF72
	.byte	0x5
	.uleb128 0
	.4byte	.LASF73
	.byte	0x5
	.uleb128 0
	.4byte	.LASF74
	.byte	0x5
	.uleb128 0
	.4byte	.LASF75
	.byte	0x5
	.uleb128 0
	.4byte	.LASF76
	.byte	0x5
	.uleb128 0
	.4byte	.LASF77
	.byte	0x5
	.uleb128 0
	.4byte	.LASF78
	.byte	0x5
	.uleb128 0
	.4byte	.LASF79
	.byte	0x5
	.uleb128 0
	.4byte	.LASF80
	.byte	0x5
	.uleb128 0
	.4byte	.LASF81
	.byte	0x5
	.uleb128 0
	.4byte	.LASF82
	.byte	0x5
	.uleb128 0
	.4byte	.LASF83
	.byte	0x5
	.uleb128 0
	.4byte	.LASF84
	.byte	0x5
	.uleb128 0
	.4byte	.LASF85
	.byte	0x5
	.uleb128 0
	.4byte	.LASF86
	.byte	0x5
	.uleb128 0
	.4byte	.LASF87
	.byte	0x5
	.uleb128 0
	.4byte	.LASF88
	.byte	0x5
	.uleb128 0
	.4byte	.LASF89
	.byte	0x5
	.uleb128 0
	.4byte	.LASF90
	.byte	0x5
	.uleb128 0
	.4byte	.LASF91
	.byte	0x5
	.uleb128 0
	.4byte	.LASF92
	.byte	0x5
	.uleb128 0
	.4byte	.LASF93
	.byte	0x5
	.uleb128 0
	.4byte	.LASF94
	.byte	0x5
	.uleb128 0
	.4byte	.LASF95
	.byte	0x5
	.uleb128 0
	.4byte	.LASF96
	.byte	0x5
	.uleb128 0
	.4byte	.LASF97
	.byte	0x5
	.uleb128 0
	.4byte	.LASF98
	.byte	0x5
	.uleb128 0
	.4byte	.LASF99
	.byte	0x5
	.uleb128 0
	.4byte	.LASF100
	.byte	0x5
	.uleb128 0
	.4byte	.LASF101
	.byte	0x5
	.uleb128 0
	.4byte	.LASF102
	.byte	0x5
	.uleb128 0
	.4byte	.LASF103
	.byte	0x5
	.uleb128 0
	.4byte	.LASF104
	.byte	0x5
	.uleb128 0
	.4byte	.LASF105
	.byte	0x5
	.uleb128 0
	.4byte	.LASF106
	.byte	0x5
	.uleb128 0
	.4byte	.LASF107
	.byte	0x5
	.uleb128 0
	.4byte	.LASF108
	.byte	0x5
	.uleb128 0
	.4byte	.LASF109
	.byte	0x5
	.uleb128 0
	.4byte	.LASF110
	.byte	0x5
	.uleb128 0
	.4byte	.LASF111
	.byte	0x5
	.uleb128 0
	.4byte	.LASF112
	.byte	0x5
	.uleb128 0
	.4byte	.LASF113
	.byte	0x5
	.uleb128 0
	.4byte	.LASF114
	.byte	0x5
	.uleb128 0
	.4byte	.LASF115
	.byte	0x5
	.uleb128 0
	.4byte	.LASF116
	.byte	0x5
	.uleb128 0
	.4byte	.LASF117
	.byte	0x5
	.uleb128 0
	.4byte	.LASF118
	.byte	0x5
	.uleb128 0
	.4byte	.LASF119
	.byte	0x5
	.uleb128 0
	.4byte	.LASF120
	.byte	0x5
	.uleb128 0
	.4byte	.LASF121
	.byte	0x5
	.uleb128 0
	.4byte	.LASF122
	.byte	0x5
	.uleb128 0
	.4byte	.LASF123
	.byte	0x5
	.uleb128 0
	.4byte	.LASF124
	.byte	0x5
	.uleb128 0
	.4byte	.LASF125
	.byte	0x5
	.uleb128 0
	.4byte	.LASF126
	.byte	0x5
	.uleb128 0
	.4byte	.LASF127
	.byte	0x5
	.uleb128 0
	.4byte	.LASF128
	.byte	0x5
	.uleb128 0
	.4byte	.LASF129
	.byte	0x5
	.uleb128 0
	.4byte	.LASF130
	.byte	0x5
	.uleb128 0
	.4byte	.LASF131
	.byte	0x5
	.uleb128 0
	.4byte	.LASF132
	.byte	0x5
	.uleb128 0
	.4byte	.LASF133
	.byte	0x5
	.uleb128 0
	.4byte	.LASF134
	.byte	0x5
	.uleb128 0
	.4byte	.LASF135
	.byte	0x5
	.uleb128 0
	.4byte	.LASF136
	.byte	0x5
	.uleb128 0
	.4byte	.LASF137
	.byte	0x5
	.uleb128 0
	.4byte	.LASF138
	.byte	0x5
	.uleb128 0
	.4byte	.LASF139
	.byte	0x5
	.uleb128 0
	.4byte	.LASF140
	.byte	0x5
	.uleb128 0
	.4byte	.LASF141
	.byte	0x5
	.uleb128 0
	.4byte	.LASF142
	.byte	0x5
	.uleb128 0
	.4byte	.LASF143
	.byte	0x5
	.uleb128 0
	.4byte	.LASF144
	.byte	0x5
	.uleb128 0
	.4byte	.LASF145
	.byte	0x5
	.uleb128 0
	.4byte	.LASF146
	.byte	0x5
	.uleb128 0
	.4byte	.LASF147
	.byte	0x5
	.uleb128 0
	.4byte	.LASF148
	.byte	0x5
	.uleb128 0
	.4byte	.LASF149
	.byte	0x5
	.uleb128 0
	.4byte	.LASF150
	.byte	0x5
	.uleb128 0
	.4byte	.LASF151
	.byte	0x5
	.uleb128 0
	.4byte	.LASF152
	.byte	0x5
	.uleb128 0
	.4byte	.LASF153
	.byte	0x5
	.uleb128 0
	.4byte	.LASF154
	.byte	0x5
	.uleb128 0
	.4byte	.LASF155
	.byte	0x5
	.uleb128 0
	.4byte	.LASF156
	.byte	0x5
	.uleb128 0
	.4byte	.LASF157
	.byte	0x5
	.uleb128 0
	.4byte	.LASF158
	.byte	0x5
	.uleb128 0
	.4byte	.LASF159
	.byte	0x5
	.uleb128 0
	.4byte	.LASF160
	.byte	0x5
	.uleb128 0
	.4byte	.LASF161
	.byte	0x5
	.uleb128 0
	.4byte	.LASF162
	.byte	0x5
	.uleb128 0
	.4byte	.LASF163
	.byte	0x5
	.uleb128 0
	.4byte	.LASF164
	.byte	0x5
	.uleb128 0
	.4byte	.LASF165
	.byte	0x5
	.uleb128 0
	.4byte	.LASF166
	.byte	0x5
	.uleb128 0
	.4byte	.LASF167
	.byte	0x5
	.uleb128 0
	.4byte	.LASF168
	.byte	0x5
	.uleb128 0
	.4byte	.LASF169
	.byte	0x5
	.uleb128 0
	.4byte	.LASF170
	.byte	0x5
	.uleb128 0
	.4byte	.LASF171
	.byte	0x5
	.uleb128 0
	.4byte	.LASF172
	.byte	0x5
	.uleb128 0
	.4byte	.LASF173
	.byte	0x5
	.uleb128 0
	.4byte	.LASF174
	.byte	0x5
	.uleb128 0
	.4byte	.LASF175
	.byte	0x5
	.uleb128 0
	.4byte	.LASF176
	.byte	0x5
	.uleb128 0
	.4byte	.LASF177
	.byte	0x5
	.uleb128 0
	.4byte	.LASF178
	.byte	0x5
	.uleb128 0
	.4byte	.LASF179
	.byte	0x5
	.uleb128 0
	.4byte	.LASF180
	.byte	0x5
	.uleb128 0
	.4byte	.LASF181
	.byte	0x5
	.uleb128 0
	.4byte	.LASF182
	.byte	0x5
	.uleb128 0
	.4byte	.LASF183
	.byte	0x5
	.uleb128 0
	.4byte	.LASF184
	.byte	0x5
	.uleb128 0
	.4byte	.LASF185
	.byte	0x5
	.uleb128 0
	.4byte	.LASF186
	.byte	0x5
	.uleb128 0
	.4byte	.LASF187
	.byte	0x5
	.uleb128 0
	.4byte	.LASF188
	.byte	0x5
	.uleb128 0
	.4byte	.LASF189
	.byte	0x5
	.uleb128 0
	.4byte	.LASF190
	.byte	0x5
	.uleb128 0
	.4byte	.LASF191
	.byte	0x5
	.uleb128 0
	.4byte	.LASF192
	.byte	0x5
	.uleb128 0
	.4byte	.LASF193
	.byte	0x5
	.uleb128 0
	.4byte	.LASF194
	.byte	0x5
	.uleb128 0
	.4byte	.LASF195
	.byte	0x5
	.uleb128 0
	.4byte	.LASF196
	.byte	0x5
	.uleb128 0
	.4byte	.LASF197
	.byte	0x5
	.uleb128 0
	.4byte	.LASF198
	.byte	0x5
	.uleb128 0
	.4byte	.LASF199
	.byte	0x5
	.uleb128 0
	.4byte	.LASF200
	.byte	0x5
	.uleb128 0
	.4byte	.LASF201
	.byte	0x5
	.uleb128 0
	.4byte	.LASF202
	.byte	0x5
	.uleb128 0
	.4byte	.LASF203
	.byte	0x5
	.uleb128 0
	.4byte	.LASF204
	.byte	0x5
	.uleb128 0
	.4byte	.LASF205
	.byte	0x5
	.uleb128 0
	.4byte	.LASF206
	.byte	0x5
	.uleb128 0
	.4byte	.LASF207
	.byte	0x5
	.uleb128 0
	.4byte	.LASF208
	.byte	0x5
	.uleb128 0
	.4byte	.LASF209
	.byte	0x5
	.uleb128 0
	.4byte	.LASF210
	.byte	0x5
	.uleb128 0
	.4byte	.LASF211
	.byte	0x5
	.uleb128 0
	.4byte	.LASF212
	.byte	0x5
	.uleb128 0
	.4byte	.LASF213
	.byte	0x5
	.uleb128 0
	.4byte	.LASF214
	.byte	0x5
	.uleb128 0
	.4byte	.LASF215
	.byte	0x5
	.uleb128 0
	.4byte	.LASF216
	.byte	0x5
	.uleb128 0
	.4byte	.LASF217
	.byte	0x5
	.uleb128 0
	.4byte	.LASF218
	.byte	0x5
	.uleb128 0
	.4byte	.LASF219
	.byte	0x5
	.uleb128 0
	.4byte	.LASF220
	.byte	0x5
	.uleb128 0
	.4byte	.LASF221
	.byte	0x5
	.uleb128 0
	.4byte	.LASF222
	.byte	0x5
	.uleb128 0
	.4byte	.LASF223
	.byte	0x5
	.uleb128 0
	.4byte	.LASF224
	.byte	0x5
	.uleb128 0
	.4byte	.LASF225
	.byte	0x5
	.uleb128 0
	.4byte	.LASF226
	.byte	0x5
	.uleb128 0
	.4byte	.LASF227
	.byte	0x5
	.uleb128 0
	.4byte	.LASF228
	.byte	0x5
	.uleb128 0
	.4byte	.LASF229
	.byte	0x5
	.uleb128 0
	.4byte	.LASF230
	.byte	0x5
	.uleb128 0
	.4byte	.LASF231
	.byte	0x5
	.uleb128 0
	.4byte	.LASF232
	.byte	0x5
	.uleb128 0
	.4byte	.LASF233
	.byte	0x5
	.uleb128 0
	.4byte	.LASF234
	.byte	0x5
	.uleb128 0
	.4byte	.LASF235
	.byte	0x5
	.uleb128 0
	.4byte	.LASF236
	.byte	0x5
	.uleb128 0
	.4byte	.LASF237
	.byte	0x5
	.uleb128 0
	.4byte	.LASF238
	.byte	0x5
	.uleb128 0
	.4byte	.LASF239
	.byte	0x5
	.uleb128 0
	.4byte	.LASF240
	.byte	0x5
	.uleb128 0
	.4byte	.LASF241
	.byte	0x5
	.uleb128 0
	.4byte	.LASF242
	.byte	0x5
	.uleb128 0
	.4byte	.LASF243
	.byte	0x5
	.uleb128 0
	.4byte	.LASF244
	.byte	0x5
	.uleb128 0
	.4byte	.LASF245
	.byte	0x5
	.uleb128 0
	.4byte	.LASF246
	.byte	0x5
	.uleb128 0
	.4byte	.LASF247
	.byte	0x5
	.uleb128 0
	.4byte	.LASF248
	.byte	0x5
	.uleb128 0
	.4byte	.LASF249
	.byte	0x5
	.uleb128 0
	.4byte	.LASF250
	.byte	0x5
	.uleb128 0
	.4byte	.LASF251
	.byte	0x5
	.uleb128 0
	.4byte	.LASF252
	.byte	0x5
	.uleb128 0
	.4byte	.LASF253
	.byte	0x5
	.uleb128 0
	.4byte	.LASF254
	.byte	0x5
	.uleb128 0
	.4byte	.LASF255
	.byte	0x5
	.uleb128 0
	.4byte	.LASF256
	.byte	0x5
	.uleb128 0
	.4byte	.LASF257
	.byte	0x5
	.uleb128 0
	.4byte	.LASF258
	.byte	0x5
	.uleb128 0
	.4byte	.LASF259
	.byte	0x5
	.uleb128 0
	.4byte	.LASF260
	.byte	0x5
	.uleb128 0
	.4byte	.LASF261
	.byte	0x5
	.uleb128 0
	.4byte	.LASF262
	.byte	0x5
	.uleb128 0
	.4byte	.LASF263
	.byte	0x5
	.uleb128 0
	.4byte	.LASF264
	.byte	0x5
	.uleb128 0
	.4byte	.LASF265
	.byte	0x5
	.uleb128 0
	.4byte	.LASF266
	.byte	0x5
	.uleb128 0
	.4byte	.LASF267
	.byte	0x5
	.uleb128 0
	.4byte	.LASF268
	.byte	0x5
	.uleb128 0
	.4byte	.LASF269
	.byte	0x5
	.uleb128 0
	.4byte	.LASF270
	.byte	0x5
	.uleb128 0
	.4byte	.LASF271
	.byte	0x5
	.uleb128 0
	.4byte	.LASF272
	.byte	0x5
	.uleb128 0
	.4byte	.LASF273
	.byte	0x5
	.uleb128 0
	.4byte	.LASF274
	.byte	0x5
	.uleb128 0
	.4byte	.LASF275
	.byte	0x5
	.uleb128 0
	.4byte	.LASF276
	.byte	0x5
	.uleb128 0
	.4byte	.LASF277
	.byte	0x5
	.uleb128 0
	.4byte	.LASF278
	.byte	0x5
	.uleb128 0
	.4byte	.LASF279
	.byte	0x5
	.uleb128 0
	.4byte	.LASF280
	.byte	0x5
	.uleb128 0
	.4byte	.LASF281
	.byte	0x5
	.uleb128 0
	.4byte	.LASF282
	.byte	0x5
	.uleb128 0
	.4byte	.LASF283
	.byte	0x5
	.uleb128 0
	.4byte	.LASF284
	.byte	0x5
	.uleb128 0
	.4byte	.LASF285
	.byte	0x5
	.uleb128 0
	.4byte	.LASF286
	.byte	0x5
	.uleb128 0
	.4byte	.LASF287
	.byte	0x5
	.uleb128 0
	.4byte	.LASF288
	.byte	0x5
	.uleb128 0
	.4byte	.LASF289
	.byte	0x5
	.uleb128 0
	.4byte	.LASF290
	.byte	0x5
	.uleb128 0
	.4byte	.LASF291
	.byte	0x5
	.uleb128 0
	.4byte	.LASF292
	.byte	0x5
	.uleb128 0
	.4byte	.LASF293
	.byte	0x5
	.uleb128 0
	.4byte	.LASF294
	.byte	0x5
	.uleb128 0
	.4byte	.LASF295
	.byte	0x5
	.uleb128 0
	.4byte	.LASF296
	.byte	0x5
	.uleb128 0
	.4byte	.LASF297
	.byte	0x5
	.uleb128 0
	.4byte	.LASF298
	.byte	0x5
	.uleb128 0
	.4byte	.LASF299
	.byte	0x5
	.uleb128 0
	.4byte	.LASF300
	.byte	0x5
	.uleb128 0
	.4byte	.LASF301
	.byte	0x5
	.uleb128 0
	.4byte	.LASF302
	.byte	0x5
	.uleb128 0
	.4byte	.LASF303
	.byte	0x5
	.uleb128 0
	.4byte	.LASF304
	.byte	0x5
	.uleb128 0
	.4byte	.LASF305
	.byte	0x5
	.uleb128 0
	.4byte	.LASF306
	.byte	0x5
	.uleb128 0
	.4byte	.LASF307
	.byte	0x5
	.uleb128 0
	.4byte	.LASF308
	.byte	0x5
	.uleb128 0
	.4byte	.LASF309
	.byte	0x5
	.uleb128 0
	.4byte	.LASF310
	.byte	0x5
	.uleb128 0
	.4byte	.LASF311
	.byte	0x5
	.uleb128 0
	.4byte	.LASF312
	.byte	0x5
	.uleb128 0
	.4byte	.LASF313
	.byte	0x5
	.uleb128 0
	.4byte	.LASF314
	.byte	0x5
	.uleb128 0
	.4byte	.LASF315
	.byte	0x5
	.uleb128 0
	.4byte	.LASF316
	.byte	0x5
	.uleb128 0
	.4byte	.LASF317
	.byte	0x5
	.uleb128 0
	.4byte	.LASF318
	.byte	0x5
	.uleb128 0
	.4byte	.LASF319
	.byte	0x5
	.uleb128 0
	.4byte	.LASF320
	.byte	0x5
	.uleb128 0
	.4byte	.LASF321
	.byte	0x5
	.uleb128 0
	.4byte	.LASF322
	.byte	0x5
	.uleb128 0
	.4byte	.LASF323
	.byte	0x5
	.uleb128 0
	.4byte	.LASF324
	.byte	0x5
	.uleb128 0
	.4byte	.LASF325
	.byte	0x5
	.uleb128 0
	.4byte	.LASF326
	.byte	0x5
	.uleb128 0
	.4byte	.LASF327
	.byte	0x5
	.uleb128 0
	.4byte	.LASF328
	.byte	0x5
	.uleb128 0
	.4byte	.LASF329
	.byte	0x5
	.uleb128 0
	.4byte	.LASF330
	.byte	0x5
	.uleb128 0
	.4byte	.LASF331
	.byte	0x5
	.uleb128 0
	.4byte	.LASF332
	.byte	0x5
	.uleb128 0
	.4byte	.LASF333
	.byte	0x5
	.uleb128 0
	.4byte	.LASF334
	.byte	0x5
	.uleb128 0
	.4byte	.LASF335
	.byte	0x5
	.uleb128 0
	.4byte	.LASF336
	.byte	0x5
	.uleb128 0
	.4byte	.LASF337
	.byte	0x5
	.uleb128 0
	.4byte	.LASF338
	.byte	0x5
	.uleb128 0
	.4byte	.LASF339
	.byte	0x5
	.uleb128 0
	.4byte	.LASF340
	.byte	0x5
	.uleb128 0
	.4byte	.LASF341
	.byte	0x5
	.uleb128 0
	.4byte	.LASF342
	.byte	0x5
	.uleb128 0
	.4byte	.LASF343
	.byte	0x5
	.uleb128 0
	.4byte	.LASF344
	.byte	0x5
	.uleb128 0
	.4byte	.LASF345
	.byte	0x5
	.uleb128 0
	.4byte	.LASF346
	.byte	0x5
	.uleb128 0
	.4byte	.LASF347
	.byte	0x5
	.uleb128 0
	.4byte	.LASF348
	.byte	0x5
	.uleb128 0
	.4byte	.LASF349
	.byte	0x5
	.uleb128 0
	.4byte	.LASF350
	.byte	0x5
	.uleb128 0
	.4byte	.LASF351
	.byte	0x5
	.uleb128 0
	.4byte	.LASF352
	.byte	0x5
	.uleb128 0
	.4byte	.LASF353
	.byte	0x5
	.uleb128 0
	.4byte	.LASF354
	.byte	0x5
	.uleb128 0
	.4byte	.LASF355
	.byte	0x5
	.uleb128 0
	.4byte	.LASF356
	.byte	0x5
	.uleb128 0
	.4byte	.LASF357
	.byte	0x5
	.uleb128 0
	.4byte	.LASF358
	.byte	0x5
	.uleb128 0
	.4byte	.LASF359
	.byte	0x5
	.uleb128 0
	.4byte	.LASF360
	.byte	0x5
	.uleb128 0
	.4byte	.LASF361
	.byte	0x5
	.uleb128 0
	.4byte	.LASF362
	.byte	0x5
	.uleb128 0
	.4byte	.LASF363
	.byte	0x5
	.uleb128 0
	.4byte	.LASF364
	.byte	0x5
	.uleb128 0
	.4byte	.LASF365
	.byte	0x5
	.uleb128 0
	.4byte	.LASF366
	.byte	0x5
	.uleb128 0
	.4byte	.LASF367
	.byte	0x5
	.uleb128 0
	.4byte	.LASF368
	.byte	0x5
	.uleb128 0
	.4byte	.LASF369
	.byte	0x5
	.uleb128 0
	.4byte	.LASF370
	.byte	0x5
	.uleb128 0
	.4byte	.LASF371
	.byte	0x5
	.uleb128 0
	.4byte	.LASF372
	.byte	0x5
	.uleb128 0
	.4byte	.LASF373
	.byte	0x5
	.uleb128 0
	.4byte	.LASF374
	.byte	0x5
	.uleb128 0
	.4byte	.LASF375
	.byte	0x5
	.uleb128 0
	.4byte	.LASF376
	.byte	0x5
	.uleb128 0
	.4byte	.LASF377
	.byte	0x5
	.uleb128 0
	.4byte	.LASF378
	.byte	0x5
	.uleb128 0
	.4byte	.LASF379
	.byte	0x5
	.uleb128 0
	.4byte	.LASF380
	.byte	0x5
	.uleb128 0
	.4byte	.LASF381
	.byte	0x5
	.uleb128 0
	.4byte	.LASF382
	.byte	0x5
	.uleb128 0
	.4byte	.LASF383
	.byte	0x5
	.uleb128 0
	.4byte	.LASF384
	.byte	0x5
	.uleb128 0
	.4byte	.LASF385
	.byte	0x5
	.uleb128 0
	.4byte	.LASF386
	.byte	0x5
	.uleb128 0
	.4byte	.LASF387
	.byte	0x5
	.uleb128 0
	.4byte	.LASF388
	.byte	0x5
	.uleb128 0
	.4byte	.LASF389
	.byte	0x5
	.uleb128 0
	.4byte	.LASF390
	.byte	0x5
	.uleb128 0
	.4byte	.LASF391
	.byte	0x5
	.uleb128 0
	.4byte	.LASF392
	.byte	0x5
	.uleb128 0
	.4byte	.LASF393
	.byte	0x5
	.uleb128 0
	.4byte	.LASF394
	.byte	0x5
	.uleb128 0
	.4byte	.LASF395
	.byte	0x5
	.uleb128 0
	.4byte	.LASF396
	.byte	0x5
	.uleb128 0
	.4byte	.LASF397
	.byte	0x5
	.uleb128 0
	.4byte	.LASF398
	.byte	0x5
	.uleb128 0
	.4byte	.LASF399
	.byte	0x5
	.uleb128 0
	.4byte	.LASF400
	.byte	0x5
	.uleb128 0
	.4byte	.LASF401
	.byte	0x5
	.uleb128 0
	.4byte	.LASF402
	.byte	0x5
	.uleb128 0
	.4byte	.LASF403
	.byte	0x5
	.uleb128 0
	.4byte	.LASF404
	.byte	0x5
	.uleb128 0
	.4byte	.LASF405
	.byte	0x5
	.uleb128 0
	.4byte	.LASF406
	.byte	0x5
	.uleb128 0
	.4byte	.LASF407
	.byte	0x5
	.uleb128 0
	.4byte	.LASF408
	.byte	0x5
	.uleb128 0
	.4byte	.LASF409
	.byte	0x5
	.uleb128 0
	.4byte	.LASF410
	.byte	0x5
	.uleb128 0
	.4byte	.LASF411
	.byte	0x5
	.uleb128 0
	.4byte	.LASF412
	.byte	0x5
	.uleb128 0
	.4byte	.LASF413
	.byte	0x5
	.uleb128 0
	.4byte	.LASF414
	.byte	0x5
	.uleb128 0
	.4byte	.LASF415
	.byte	0x5
	.uleb128 0
	.4byte	.LASF416
	.byte	0x5
	.uleb128 0
	.4byte	.LASF417
	.byte	0x6
	.uleb128 0
	.4byte	.LASF418
	.byte	0x6
	.uleb128 0
	.4byte	.LASF419
	.byte	0x6
	.uleb128 0
	.4byte	.LASF420
	.byte	0x6
	.uleb128 0
	.4byte	.LASF421
	.byte	0x6
	.uleb128 0
	.4byte	.LASF422
	.byte	0x6
	.uleb128 0
	.4byte	.LASF423
	.byte	0x6
	.uleb128 0
	.4byte	.LASF424
	.byte	0x6
	.uleb128 0
	.4byte	.LASF425
	.byte	0x6
	.uleb128 0
	.4byte	.LASF426
	.byte	0x6
	.uleb128 0
	.4byte	.LASF427
	.byte	0x6
	.uleb128 0
	.4byte	.LASF428
	.byte	0x6
	.uleb128 0
	.4byte	.LASF429
	.byte	0x6
	.uleb128 0
	.4byte	.LASF430
	.byte	0x6
	.uleb128 0
	.4byte	.LASF431
	.byte	0x6
	.uleb128 0
	.4byte	.LASF432
	.byte	0x5
	.uleb128 0
	.4byte	.LASF433
	.byte	0x5
	.uleb128 0
	.4byte	.LASF434
	.byte	0x6
	.uleb128 0
	.4byte	.LASF435
	.byte	0x5
	.uleb128 0
	.4byte	.LASF436
	.byte	0x5
	.uleb128 0
	.4byte	.LASF437
	.byte	0x6
	.uleb128 0
	.4byte	.LASF438
	.byte	0x5
	.uleb128 0
	.4byte	.LASF439
	.byte	0x5
	.uleb128 0
	.4byte	.LASF440
	.byte	0x5
	.uleb128 0
	.4byte	.LASF441
	.byte	0x6
	.uleb128 0
	.4byte	.LASF442
	.byte	0x5
	.uleb128 0
	.4byte	.LASF443
	.byte	0x6
	.uleb128 0
	.4byte	.LASF444
	.byte	0x5
	.uleb128 0
	.4byte	.LASF445
	.byte	0x5
	.uleb128 0
	.4byte	.LASF446
	.byte	0x5
	.uleb128 0
	.4byte	.LASF447
	.byte	0x5
	.uleb128 0
	.4byte	.LASF448
	.byte	0x6
	.uleb128 0
	.4byte	.LASF449
	.byte	0x6
	.uleb128 0
	.4byte	.LASF450
	.byte	0x6
	.uleb128 0
	.4byte	.LASF451
	.byte	0x6
	.uleb128 0
	.4byte	.LASF452
	.byte	0x6
	.uleb128 0
	.4byte	.LASF453
	.byte	0x6
	.uleb128 0
	.4byte	.LASF454
	.byte	0x6
	.uleb128 0
	.4byte	.LASF455
	.byte	0x6
	.uleb128 0
	.4byte	.LASF456
	.byte	0x6
	.uleb128 0
	.4byte	.LASF457
	.byte	0x6
	.uleb128 0
	.4byte	.LASF458
	.byte	0x6
	.uleb128 0
	.4byte	.LASF459
	.byte	0x5
	.uleb128 0
	.4byte	.LASF460
	.byte	0x5
	.uleb128 0
	.4byte	.LASF461
	.byte	0x5
	.uleb128 0
	.4byte	.LASF462
	.byte	0x5
	.uleb128 0
	.4byte	.LASF463
	.byte	0x6
	.uleb128 0
	.4byte	.LASF464
	.byte	0x6
	.uleb128 0
	.4byte	.LASF465
	.byte	0x6
	.uleb128 0
	.4byte	.LASF466
	.byte	0x6
	.uleb128 0
	.4byte	.LASF467
	.byte	0x5
	.uleb128 0
	.4byte	.LASF468
	.byte	0x5
	.uleb128 0
	.4byte	.LASF469
	.byte	0x5
	.uleb128 0
	.4byte	.LASF470
	.byte	0x5
	.uleb128 0
	.4byte	.LASF461
	.byte	0x5
	.uleb128 0
	.4byte	.LASF471
	.byte	0x5
	.uleb128 0
	.4byte	.LASF472
	.byte	0x5
	.uleb128 0
	.4byte	.LASF473
	.byte	0x5
	.uleb128 0
	.4byte	.LASF474
	.byte	0x5
	.uleb128 0
	.4byte	.LASF475
	.byte	0x5
	.uleb128 0
	.4byte	.LASF476
	.byte	0x5
	.uleb128 0
	.4byte	.LASF477
	.byte	0x5
	.uleb128 0
	.4byte	.LASF478
	.byte	0x5
	.uleb128 0
	.4byte	.LASF479
	.byte	0x5
	.uleb128 0
	.4byte	.LASF480
	.byte	0x5
	.uleb128 0
	.4byte	.LASF481
	.byte	0x5
	.uleb128 0
	.4byte	.LASF482
	.byte	0x5
	.uleb128 0
	.4byte	.LASF483
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.config.h.23.3b5114974c72eef0c529c6c1d0018c93,comdat
.Ldebug_macro3:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF485
	.byte	0x5
	.uleb128 0x19
	.4byte	.LASF486
	.byte	0x5
	.uleb128 0x1b
	.4byte	.LASF487
	.byte	0x5
	.uleb128 0x20
	.4byte	.LASF488
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF489
	.byte	0x5
	.uleb128 0x26
	.4byte	.LASF490
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF491
	.byte	0x5
	.uleb128 0x2c
	.4byte	.LASF492
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF493
	.byte	0x5
	.uleb128 0x67
	.4byte	.LASF494
	.byte	0x5
	.uleb128 0x68
	.4byte	.LASF495
	.byte	0x5
	.uleb128 0x6e
	.4byte	.LASF496
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF497
	.byte	0x5
	.uleb128 0x7d
	.4byte	.LASF498
	.byte	0x5
	.uleb128 0x80
	.4byte	.LASF499
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF500
	.byte	0x5
	.uleb128 0x8d
	.4byte	.LASF501
	.byte	0x5
	.uleb128 0x90
	.4byte	.LASF502
	.byte	0x5
	.uleb128 0x93
	.4byte	.LASF503
	.byte	0x5
	.uleb128 0x96
	.4byte	.LASF504
	.byte	0x5
	.uleb128 0x99
	.4byte	.LASF505
	.byte	0x5
	.uleb128 0x9c
	.4byte	.LASF506
	.byte	0x5
	.uleb128 0xa0
	.4byte	.LASF507
	.byte	0x5
	.uleb128 0xa4
	.4byte	.LASF508
	.byte	0x5
	.uleb128 0xa5
	.4byte	.LASF509
	.byte	0x5
	.uleb128 0xa6
	.4byte	.LASF510
	.byte	0x5
	.uleb128 0xa7
	.4byte	.LASF511
	.byte	0x5
	.uleb128 0xa8
	.4byte	.LASF512
	.byte	0x5
	.uleb128 0xa9
	.4byte	.LASF513
	.byte	0x5
	.uleb128 0xaa
	.4byte	.LASF514
	.byte	0x5
	.uleb128 0xab
	.4byte	.LASF515
	.byte	0x5
	.uleb128 0xae
	.4byte	.LASF516
	.byte	0x5
	.uleb128 0xaf
	.4byte	.LASF517
	.byte	0x5
	.uleb128 0xb0
	.4byte	.LASF518
	.byte	0x5
	.uleb128 0xb1
	.4byte	.LASF519
	.byte	0x5
	.uleb128 0xb2
	.4byte	.LASF520
	.byte	0x5
	.uleb128 0xb3
	.4byte	.LASF521
	.byte	0x5
	.uleb128 0xb4
	.4byte	.LASF522
	.byte	0x5
	.uleb128 0xb5
	.4byte	.LASF523
	.byte	0x5
	.uleb128 0xb7
	.4byte	.LASF524
	.byte	0x5
	.uleb128 0xb8
	.4byte	.LASF525
	.byte	0x5
	.uleb128 0xb9
	.4byte	.LASF526
	.byte	0x5
	.uleb128 0xba
	.4byte	.LASF527
	.byte	0x5
	.uleb128 0xbb
	.4byte	.LASF528
	.byte	0x5
	.uleb128 0xbc
	.4byte	.LASF529
	.byte	0x5
	.uleb128 0xbd
	.4byte	.LASF530
	.byte	0x5
	.uleb128 0xbe
	.4byte	.LASF531
	.byte	0x5
	.uleb128 0xc1
	.4byte	.LASF532
	.byte	0x5
	.uleb128 0xc2
	.4byte	.LASF533
	.byte	0x5
	.uleb128 0xc3
	.4byte	.LASF534
	.byte	0x5
	.uleb128 0xc4
	.4byte	.LASF535
	.byte	0x5
	.uleb128 0xc5
	.4byte	.LASF536
	.byte	0x5
	.uleb128 0xc6
	.4byte	.LASF537
	.byte	0x5
	.uleb128 0xc7
	.4byte	.LASF538
	.byte	0x5
	.uleb128 0xc8
	.4byte	.LASF539
	.byte	0x5
	.uleb128 0xc9
	.4byte	.LASF540
	.byte	0x5
	.uleb128 0xca
	.4byte	.LASF541
	.byte	0x5
	.uleb128 0xcb
	.4byte	.LASF542
	.byte	0x5
	.uleb128 0xcc
	.4byte	.LASF543
	.byte	0x5
	.uleb128 0xcd
	.4byte	.LASF544
	.byte	0x5
	.uleb128 0xce
	.4byte	.LASF545
	.byte	0x5
	.uleb128 0xd1
	.4byte	.LASF546
	.byte	0x5
	.uleb128 0xd2
	.4byte	.LASF547
	.byte	0x5
	.uleb128 0xd3
	.4byte	.LASF548
	.byte	0x5
	.uleb128 0xd4
	.4byte	.LASF549
	.byte	0x5
	.uleb128 0xd7
	.4byte	.LASF550
	.byte	0x5
	.uleb128 0xda
	.4byte	.LASF551
	.byte	0x5
	.uleb128 0xdd
	.4byte	.LASF552
	.byte	0x5
	.uleb128 0xe0
	.4byte	.LASF553
	.byte	0x5
	.uleb128 0xe3
	.4byte	.LASF554
	.byte	0x5
	.uleb128 0xe4
	.4byte	.LASF555
	.byte	0x5
	.uleb128 0xe5
	.4byte	.LASF556
	.byte	0x5
	.uleb128 0xe6
	.4byte	.LASF557
	.byte	0x5
	.uleb128 0xe7
	.4byte	.LASF558
	.byte	0x5
	.uleb128 0xe8
	.4byte	.LASF559
	.byte	0x5
	.uleb128 0xeb
	.4byte	.LASF560
	.byte	0x5
	.uleb128 0xec
	.4byte	.LASF561
	.byte	0x5
	.uleb128 0xef
	.4byte	.LASF554
	.byte	0x5
	.uleb128 0xf0
	.4byte	.LASF555
	.byte	0x5
	.uleb128 0xf1
	.4byte	.LASF556
	.byte	0x5
	.uleb128 0xf2
	.4byte	.LASF557
	.byte	0x5
	.uleb128 0xf3
	.4byte	.LASF558
	.byte	0x5
	.uleb128 0xf4
	.4byte	.LASF559
	.byte	0x5
	.uleb128 0xf7
	.4byte	.LASF553
	.byte	0x5
	.uleb128 0xfa
	.4byte	.LASF562
	.byte	0x5
	.uleb128 0xfb
	.4byte	.LASF563
	.byte	0x5
	.uleb128 0xfc
	.4byte	.LASF564
	.byte	0x5
	.uleb128 0xff
	.4byte	.LASF565
	.byte	0x5
	.uleb128 0x102
	.4byte	.LASF566
	.byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF454:
	.ascii	"__ARM_FEATURE_FP16_VECTOR_ARITHMETIC\000"
.LASF122:
	.ascii	"__SIG_ATOMIC_MAX__ 0x7fffffff\000"
.LASF244:
	.ascii	"__FLT64_HAS_QUIET_NAN__ 1\000"
.LASF446:
	.ascii	"__ARMEL__ 1\000"
.LASF272:
	.ascii	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD\000"
.LASF296:
	.ascii	"__UFRACT_IBIT__ 0\000"
.LASF229:
	.ascii	"__FLT32_HAS_INFINITY__ 1\000"
.LASF445:
	.ascii	"__ARM_ARCH_ISA_THUMB 1\000"
.LASF62:
	.ascii	"__UINT_FAST8_TYPE__ unsigned int\000"
.LASF235:
	.ascii	"__FLT64_MAX_EXP__ 1024\000"
.LASF540:
	.ascii	"TIM9_ENABLE \000"
.LASF572:
	.ascii	"getUsec\000"
.LASF249:
	.ascii	"__FLT32X_MAX_EXP__ 1024\000"
.LASF156:
	.ascii	"__INT_FAST16_WIDTH__ 32\000"
.LASF411:
	.ascii	"__GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1\000"
.LASF552:
	.ascii	"SDRAM_ENABLE \000"
.LASF553:
	.ascii	"LTDC_ENABLE \000"
.LASF271:
	.ascii	"__DEC64_EPSILON__ 1E-15DD\000"
.LASF349:
	.ascii	"__ULACCUM_EPSILON__ 0x1P-32ULK\000"
.LASF224:
	.ascii	"__FLT32_MAX__ 1.1\000"
.LASF432:
	.ascii	"__ARM_FEATURE_SIMD32\000"
.LASF198:
	.ascii	"__DBL_DENORM_MIN__ double(1.1)\000"
.LASF217:
	.ascii	"__FLT32_MANT_DIG__ 24\000"
.LASF375:
	.ascii	"__USQ_IBIT__ 0\000"
.LASF146:
	.ascii	"__UINT8_C(c) c\000"
.LASF457:
	.ascii	"__ARM_NEON__\000"
.LASF416:
	.ascii	"__SIZEOF_WINT_T__ 4\000"
.LASF528:
	.ascii	"DMA2_STREAM4_ENABLE \000"
.LASF494:
	.ascii	"YSS_H_HEAP 1\000"
.LASF361:
	.ascii	"__QQ_IBIT__ 0\000"
.LASF377:
	.ascii	"__UDQ_IBIT__ 0\000"
.LASF565:
	.ascii	"DAC_ENABLE \000"
.LASF537:
	.ascii	"TIM6_ENABLE \000"
.LASF407:
	.ascii	"__GCC_ATOMIC_SHORT_LOCK_FREE 1\000"
.LASF251:
	.ascii	"__FLT32X_DECIMAL_DIG__ 17\000"
.LASF90:
	.ascii	"__cpp_delegating_constructors 200604\000"
.LASF190:
	.ascii	"__DBL_MIN_EXP__ (-1021)\000"
.LASF112:
	.ascii	"__LONG_LONG_WIDTH__ 64\000"
.LASF404:
	.ascii	"__GCC_ATOMIC_CHAR16_T_LOCK_FREE 1\000"
.LASF69:
	.ascii	"__has_include_next(STR) __has_include_next__(STR)\000"
.LASF434:
	.ascii	"__ARM_SIZEOF_WCHAR_T 4\000"
.LASF450:
	.ascii	"__ARM_FP16_FORMAT_IEEE\000"
.LASF426:
	.ascii	"__ARM_FEATURE_COMPLEX\000"
.LASF311:
	.ascii	"__LLFRACT_IBIT__ 0\000"
.LASF374:
	.ascii	"__USQ_FBIT__ 32\000"
.LASF588:
	.ascii	"/home/mymy49/library/yss/yss/util/yss_TimeLapse.cpp"
	.ascii	"\000"
.LASF105:
	.ascii	"__WINT_MIN__ 0U\000"
.LASF517:
	.ascii	"DMA1_STREAM1_ENABLE \000"
.LASF6:
	.ascii	"__GNUC_MINOR__ 3\000"
.LASF582:
	.ascii	"unsigned int\000"
.LASF85:
	.ascii	"__cpp_attributes 200809\000"
.LASF148:
	.ascii	"__UINT16_C(c) c\000"
.LASF23:
	.ascii	"__SIZEOF_SIZE_T__ 4\000"
.LASF39:
	.ascii	"__CHAR16_TYPE__ short unsigned int\000"
.LASF22:
	.ascii	"__SIZEOF_LONG_DOUBLE__ 8\000"
.LASF181:
	.ascii	"__FLT_MAX__ 1.1\000"
.LASF153:
	.ascii	"__INT_FAST8_MAX__ 0x7fffffff\000"
.LASF27:
	.ascii	"__ORDER_BIG_ENDIAN__ 4321\000"
.LASF318:
	.ascii	"__ULLFRACT_MAX__ 0XFFFFFFFFFFFFFFFFP-64ULLR\000"
.LASF5:
	.ascii	"__GNUC__ 9\000"
.LASF473:
	.ascii	"__CROSSWORKS_MAJOR_VERSION 4\000"
.LASF514:
	.ascii	"UART7_ENABLE \000"
.LASF394:
	.ascii	"__UTA_FBIT__ 64\000"
.LASF188:
	.ascii	"__DBL_MANT_DIG__ 53\000"
.LASF57:
	.ascii	"__UINT_LEAST64_TYPE__ long long unsigned int\000"
.LASF254:
	.ascii	"__FLT32X_EPSILON__ 1.1\000"
.LASF99:
	.ascii	"__INT_MAX__ 0x7fffffff\000"
.LASF12:
	.ascii	"__ATOMIC_RELEASE 3\000"
.LASF34:
	.ascii	"__PTRDIFF_TYPE__ int\000"
.LASF400:
	.ascii	"__CHAR_UNSIGNED__ 1\000"
.LASF43:
	.ascii	"__INT16_TYPE__ short int\000"
.LASF578:
	.ascii	"getSec\000"
.LASF423:
	.ascii	"__ARM_FEATURE_QRDMX\000"
.LASF203:
	.ascii	"__LDBL_DIG__ 15\000"
.LASF253:
	.ascii	"__FLT32X_MIN__ 1.1\000"
.LASF579:
	.ascii	"_ZN9TimeLapse5resetEv\000"
.LASF10:
	.ascii	"__ATOMIC_SEQ_CST 5\000"
.LASF19:
	.ascii	"__SIZEOF_SHORT__ 2\000"
.LASF94:
	.ascii	"__cpp_alias_templates 200704\000"
.LASF212:
	.ascii	"__LDBL_EPSILON__ 1.1\000"
.LASF50:
	.ascii	"__INT_LEAST8_TYPE__ signed char\000"
.LASF231:
	.ascii	"__FLT64_MANT_DIG__ 53\000"
.LASF120:
	.ascii	"__UINTMAX_C(c) c ## ULL\000"
.LASF414:
	.ascii	"__PRAGMA_REDEFINE_EXTNAME 1\000"
.LASF29:
	.ascii	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__\000"
.LASF265:
	.ascii	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF\000"
.LASF220:
	.ascii	"__FLT32_MIN_10_EXP__ (-37)\000"
.LASF301:
	.ascii	"__LFRACT_IBIT__ 0\000"
.LASF479:
	.ascii	"__SYSTEM_STM32L0XX 1\000"
.LASF439:
	.ascii	"__ARM_ARCH 6\000"
.LASF3:
	.ascii	"__STDC_UTF_32__ 1\000"
.LASF84:
	.ascii	"__cpp_decltype 200707\000"
.LASF97:
	.ascii	"__SCHAR_MAX__ 0x7f\000"
.LASF356:
	.ascii	"__ULLACCUM_IBIT__ 32\000"
.LASF279:
	.ascii	"__DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000"
	.ascii	"000000001E-6143DL\000"
.LASF316:
	.ascii	"__ULLFRACT_IBIT__ 0\000"
.LASF505:
	.ascii	"YSS_FRAME_BUFFER Rgb565\000"
.LASF232:
	.ascii	"__FLT64_DIG__ 15\000"
.LASF9:
	.ascii	"__ATOMIC_RELAXED 0\000"
.LASF52:
	.ascii	"__INT_LEAST32_TYPE__ long int\000"
.LASF455:
	.ascii	"__ARM_FEATURE_FP16_FML\000"
.LASF107:
	.ascii	"__SIZE_MAX__ 0xffffffffU\000"
.LASF569:
	.ascii	"YSS_MUTEX_H_ \000"
.LASF342:
	.ascii	"__LACCUM_MIN__ (-0X1P31LK-0X1P31LK)\000"
.LASF358:
	.ascii	"__ULLACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULLK\000"
.LASF347:
	.ascii	"__ULACCUM_MIN__ 0.0ULK\000"
.LASF83:
	.ascii	"__cpp_static_assert 200410\000"
.LASF186:
	.ascii	"__FLT_HAS_INFINITY__ 1\000"
.LASF421:
	.ascii	"__ARM_FEATURE_CRYPTO\000"
.LASF486:
	.ascii	"HSE_CLOCK_FREQ 8\000"
.LASF566:
	.ascii	"RTC_ENABLE \000"
.LASF77:
	.ascii	"__cpp_raw_strings 200710\000"
.LASF518:
	.ascii	"DMA1_STREAM2_ENABLE \000"
.LASF590:
	.ascii	"mStartTime\000"
.LASF393:
	.ascii	"__UDA_IBIT__ 32\000"
.LASF61:
	.ascii	"__INT_FAST64_TYPE__ long long int\000"
.LASF134:
	.ascii	"__INT8_C(c) c\000"
.LASF255:
	.ascii	"__FLT32X_DENORM_MIN__ 1.1\000"
.LASF138:
	.ascii	"__INT_LEAST16_WIDTH__ 16\000"
.LASF529:
	.ascii	"DMA2_STREAM5_ENABLE \000"
.LASF357:
	.ascii	"__ULLACCUM_MIN__ 0.0ULLK\000"
.LASF425:
	.ascii	"__ARM_FEATURE_DOTPROD\000"
.LASF428:
	.ascii	"__ARM_FEATURE_CMSE\000"
.LASF67:
	.ascii	"__UINTPTR_TYPE__ unsigned int\000"
.LASF183:
	.ascii	"__FLT_EPSILON__ 1.1\000"
.LASF228:
	.ascii	"__FLT32_HAS_DENORM__ 1\000"
.LASF526:
	.ascii	"DMA2_STREAM2_ENABLE \000"
.LASF580:
	.ascii	"_ZN9TimeLapse6getSecEv\000"
.LASF383:
	.ascii	"__SA_IBIT__ 16\000"
.LASF313:
	.ascii	"__LLFRACT_MAX__ 0X7FFFFFFFFFFFFFFFP-63LLR\000"
.LASF589:
	.ascii	"/home/mymy49/library/yss/stm32l073rz/NUCLEO-L073RZ/"
	.ascii	"Key_Ex\000"
.LASF453:
	.ascii	"__ARM_FEATURE_FP16_SCALAR_ARITHMETIC\000"
.LASF175:
	.ascii	"__FLT_DIG__ 6\000"
.LASF155:
	.ascii	"__INT_FAST16_MAX__ 0x7fffffff\000"
.LASF482:
	.ascii	"YSS_PERI_REPORT 1\000"
.LASF384:
	.ascii	"__DA_FBIT__ 31\000"
.LASF433:
	.ascii	"__ARM_SIZEOF_MINIMAL_ENUM 1\000"
.LASF35:
	.ascii	"__WCHAR_TYPE__ unsigned int\000"
.LASF262:
	.ascii	"__DEC32_MIN__ 1E-95DF\000"
.LASF168:
	.ascii	"__GCC_IEC_559 0\000"
.LASF501:
	.ascii	"USE_GUI true\000"
.LASF542:
	.ascii	"TIM11_ENABLE \000"
.LASF329:
	.ascii	"__USACCUM_EPSILON__ 0x1P-8UHK\000"
.LASF561:
	.ascii	"CAN2_ENABLE \000"
.LASF106:
	.ascii	"__PTRDIFF_MAX__ 0x7fffffff\000"
.LASF230:
	.ascii	"__FLT32_HAS_QUIET_NAN__ 1\000"
.LASF348:
	.ascii	"__ULACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULK\000"
.LASF298:
	.ascii	"__UFRACT_MAX__ 0XFFFFP-16UR\000"
.LASF283:
	.ascii	"__SFRACT_MAX__ 0X7FP-7HR\000"
.LASF65:
	.ascii	"__UINT_FAST64_TYPE__ long long unsigned int\000"
.LASF463:
	.ascii	"__ARM_EABI__ 1\000"
.LASF581:
	.ascii	"long long unsigned int\000"
.LASF128:
	.ascii	"__INT64_MAX__ 0x7fffffffffffffffLL\000"
.LASF125:
	.ascii	"__INT8_MAX__ 0x7f\000"
.LASF309:
	.ascii	"__ULFRACT_EPSILON__ 0x1P-32ULR\000"
.LASF278:
	.ascii	"__DEC128_EPSILON__ 1E-33DL\000"
.LASF306:
	.ascii	"__ULFRACT_IBIT__ 0\000"
.LASF350:
	.ascii	"__LLACCUM_FBIT__ 31\000"
.LASF431:
	.ascii	"__ARM_FEATURE_NUMERIC_MAXMIN\000"
.LASF151:
	.ascii	"__UINT_LEAST64_MAX__ 0xffffffffffffffffULL\000"
.LASF173:
	.ascii	"__FLT_RADIX__ 2\000"
.LASF159:
	.ascii	"__INT_FAST64_MAX__ 0x7fffffffffffffffLL\000"
.LASF195:
	.ascii	"__DBL_MAX__ double(1.1)\000"
.LASF317:
	.ascii	"__ULLFRACT_MIN__ 0.0ULLR\000"
.LASF201:
	.ascii	"__DBL_HAS_QUIET_NAN__ 1\000"
.LASF337:
	.ascii	"__UACCUM_MIN__ 0.0UK\000"
.LASF419:
	.ascii	"__ARM_FEATURE_QBIT\000"
.LASF304:
	.ascii	"__LFRACT_EPSILON__ 0x1P-31LR\000"
.LASF58:
	.ascii	"__INT_FAST8_TYPE__ int\000"
.LASF88:
	.ascii	"__cpp_variadic_templates 200704\000"
.LASF243:
	.ascii	"__FLT64_HAS_INFINITY__ 1\000"
.LASF227:
	.ascii	"__FLT32_DENORM_MIN__ 1.1\000"
.LASF320:
	.ascii	"__SACCUM_FBIT__ 7\000"
.LASF126:
	.ascii	"__INT16_MAX__ 0x7fff\000"
.LASF225:
	.ascii	"__FLT32_MIN__ 1.1\000"
.LASF436:
	.ascii	"__ARM_ARCH_PROFILE 77\000"
.LASF270:
	.ascii	"__DEC64_MAX__ 9.999999999999999E384DD\000"
.LASF292:
	.ascii	"__FRACT_MIN__ (-0.5R-0.5R)\000"
.LASF408:
	.ascii	"__GCC_ATOMIC_INT_LOCK_FREE 1\000"
.LASF87:
	.ascii	"__cpp_rvalue_references 200610\000"
.LASF117:
	.ascii	"__INTMAX_MAX__ 0x7fffffffffffffffLL\000"
.LASF497:
	.ascii	"YSS_TIMER timer3\000"
.LASF339:
	.ascii	"__UACCUM_EPSILON__ 0x1P-16UK\000"
.LASF331:
	.ascii	"__ACCUM_IBIT__ 16\000"
.LASF534:
	.ascii	"TIM3_ENABLE \000"
.LASF144:
	.ascii	"__INT_LEAST64_WIDTH__ 64\000"
.LASF325:
	.ascii	"__USACCUM_FBIT__ 8\000"
.LASF321:
	.ascii	"__SACCUM_IBIT__ 8\000"
.LASF417:
	.ascii	"__SIZEOF_PTRDIFF_T__ 4\000"
.LASF132:
	.ascii	"__UINT64_MAX__ 0xffffffffffffffffULL\000"
.LASF282:
	.ascii	"__SFRACT_MIN__ (-0.5HR-0.5HR)\000"
.LASF351:
	.ascii	"__LLACCUM_IBIT__ 32\000"
.LASF273:
	.ascii	"__DEC128_MANT_DIG__ 34\000"
.LASF483:
	.ascii	"__THUMB 1\000"
.LASF20:
	.ascii	"__SIZEOF_FLOAT__ 4\000"
.LASF472:
	.ascii	"__HEAP_SIZE__ 0\000"
.LASF515:
	.ascii	"UART8_ENABLE \000"
.LASF150:
	.ascii	"__UINT32_C(c) c ## UL\000"
.LASF261:
	.ascii	"__DEC32_MAX_EXP__ 97\000"
.LASF533:
	.ascii	"TIM2_ENABLE \000"
.LASF539:
	.ascii	"TIM8_ENABLE \000"
.LASF93:
	.ascii	"__cpp_ref_qualifiers 200710\000"
.LASF557:
	.ascii	"SPI4_ENABLE \000"
.LASF471:
	.ascii	"__CROSSWORKS_ARM 1\000"
.LASF558:
	.ascii	"SPI5_ENABLE \000"
.LASF422:
	.ascii	"__ARM_FEATURE_UNALIGNED\000"
.LASF503:
	.ascii	"TOUCH_EVENT_HANDLER_STACK_SIZE 4096\000"
.LASF500:
	.ascii	"THREAD_STACK_ALLOCATION_PLACE YSS_H_HEAP\000"
.LASF401:
	.ascii	"__WCHAR_UNSIGNED__ 1\000"
.LASF70:
	.ascii	"__GXX_WEAK__ 1\000"
.LASF443:
	.ascii	"__THUMBEL__ 1\000"
.LASF211:
	.ascii	"__LDBL_MIN__ 1.1\000"
.LASF385:
	.ascii	"__DA_IBIT__ 32\000"
.LASF25:
	.ascii	"__BIGGEST_ALIGNMENT__ 8\000"
.LASF341:
	.ascii	"__LACCUM_IBIT__ 32\000"
.LASF288:
	.ascii	"__USFRACT_MAX__ 0XFFP-8UHR\000"
.LASF161:
	.ascii	"__UINT_FAST8_MAX__ 0xffffffffU\000"
.LASF26:
	.ascii	"__ORDER_LITTLE_ENDIAN__ 1234\000"
.LASF413:
	.ascii	"__HAVE_SPECULATION_SAFE_VALUE 1\000"
.LASF352:
	.ascii	"__LLACCUM_MIN__ (-0X1P31LLK-0X1P31LLK)\000"
.LASF573:
	.ascii	"_ZN9TimeLapseC4Ev\000"
.LASF382:
	.ascii	"__SA_FBIT__ 15\000"
.LASF234:
	.ascii	"__FLT64_MIN_10_EXP__ (-307)\000"
.LASF548:
	.ascii	"I2C3_ENABLE \000"
.LASF554:
	.ascii	"SPI1_ENABLE \000"
.LASF91:
	.ascii	"__cpp_nsdmi 200809\000"
.LASF324:
	.ascii	"__SACCUM_EPSILON__ 0x1P-7HK\000"
.LASF563:
	.ascii	"ADC2_ENABLE \000"
.LASF59:
	.ascii	"__INT_FAST16_TYPE__ int\000"
.LASF223:
	.ascii	"__FLT32_DECIMAL_DIG__ 9\000"
.LASF568:
	.ascii	"YSS_THREAD__H_ \000"
.LASF47:
	.ascii	"__UINT16_TYPE__ short unsigned int\000"
.LASF560:
	.ascii	"CAN1_ENABLE \000"
.LASF485:
	.ascii	"YSS_CONFIG__H_ \000"
.LASF113:
	.ascii	"__WCHAR_WIDTH__ 32\000"
.LASF398:
	.ascii	"__GNUC_STDC_INLINE__ 1\000"
.LASF373:
	.ascii	"__UHQ_IBIT__ 0\000"
.LASF295:
	.ascii	"__UFRACT_FBIT__ 16\000"
.LASF101:
	.ascii	"__LONG_LONG_MAX__ 0x7fffffffffffffffLL\000"
.LASF567:
	.ascii	"YSS_TIME__H_ \000"
.LASF55:
	.ascii	"__UINT_LEAST16_TYPE__ short unsigned int\000"
.LASF179:
	.ascii	"__FLT_MAX_10_EXP__ 38\000"
.LASF1:
	.ascii	"__cplusplus 201103L\000"
.LASF354:
	.ascii	"__LLACCUM_EPSILON__ 0x1P-31LLK\000"
.LASF327:
	.ascii	"__USACCUM_MIN__ 0.0UHK\000"
.LASF467:
	.ascii	"__ARM_FEATURE_COPROC\000"
.LASF80:
	.ascii	"__cpp_lambdas 200907\000"
.LASF274:
	.ascii	"__DEC128_MIN_EXP__ (-6142)\000"
.LASF307:
	.ascii	"__ULFRACT_MIN__ 0.0ULR\000"
.LASF174:
	.ascii	"__FLT_MANT_DIG__ 24\000"
.LASF570:
	.ascii	"switchContext yield\000"
.LASF438:
	.ascii	"__ARM_ARCH\000"
.LASF237:
	.ascii	"__FLT64_DECIMAL_DIG__ 17\000"
.LASF396:
	.ascii	"__REGISTER_PREFIX__ \000"
.LASF75:
	.ascii	"__cpp_runtime_arrays 198712\000"
.LASF219:
	.ascii	"__FLT32_MIN_EXP__ (-125)\000"
.LASF575:
	.ascii	"getMsec\000"
.LASF336:
	.ascii	"__UACCUM_IBIT__ 16\000"
.LASF162:
	.ascii	"__UINT_FAST16_MAX__ 0xffffffffU\000"
.LASF63:
	.ascii	"__UINT_FAST16_TYPE__ unsigned int\000"
.LASF490:
	.ascii	"YSS_H_HEAP_CLUSTER_SIZE 64\000"
.LASF79:
	.ascii	"__cpp_user_defined_literals 200809\000"
.LASF191:
	.ascii	"__DBL_MIN_10_EXP__ (-307)\000"
.LASF326:
	.ascii	"__USACCUM_IBIT__ 8\000"
.LASF96:
	.ascii	"__GXX_ABI_VERSION 1013\000"
.LASF460:
	.ascii	"__THUMB_INTERWORK__ 1\000"
.LASF95:
	.ascii	"__cpp_threadsafe_static_init 200806\000"
.LASF218:
	.ascii	"__FLT32_DIG__ 6\000"
.LASF493:
	.ascii	"YSS_L_HEAP_USE false\000"
.LASF242:
	.ascii	"__FLT64_HAS_DENORM__ 1\000"
.LASF484:
	.ascii	"YSS_UTIL_TIME_LAPSE__H_ \000"
.LASF170:
	.ascii	"__FLT_EVAL_METHOD__ 0\000"
.LASF504:
	.ascii	"TOUCH_EVENT_MEMORY_DEPTH 128\000"
.LASF256:
	.ascii	"__FLT32X_HAS_DENORM__ 1\000"
.LASF462:
	.ascii	"__ARM_PCS 1\000"
.LASF142:
	.ascii	"__INT_LEAST64_MAX__ 0x7fffffffffffffffLL\000"
.LASF241:
	.ascii	"__FLT64_DENORM_MIN__ 1.1\000"
.LASF406:
	.ascii	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 1\000"
.LASF267:
	.ascii	"__DEC64_MIN_EXP__ (-382)\000"
.LASF346:
	.ascii	"__ULACCUM_IBIT__ 32\000"
.LASF310:
	.ascii	"__LLFRACT_FBIT__ 63\000"
.LASF135:
	.ascii	"__INT_LEAST8_WIDTH__ 8\000"
.LASF538:
	.ascii	"TIM7_ENABLE \000"
.LASF390:
	.ascii	"__USA_FBIT__ 16\000"
.LASF129:
	.ascii	"__UINT8_MAX__ 0xff\000"
.LASF465:
	.ascii	"__ARM_FEATURE_IDIV\000"
.LASF130:
	.ascii	"__UINT16_MAX__ 0xffff\000"
.LASF481:
	.ascii	"DEBUG 1\000"
.LASF182:
	.ascii	"__FLT_MIN__ 1.1\000"
.LASF456:
	.ascii	"__ARM_FEATURE_FMA\000"
.LASF429:
	.ascii	"__ARM_FEATURE_LDREX\000"
.LASF555:
	.ascii	"SPI2_ENABLE \000"
.LASF121:
	.ascii	"__INTMAX_WIDTH__ 64\000"
.LASF263:
	.ascii	"__DEC32_MAX__ 9.999999E96DF\000"
.LASF300:
	.ascii	"__LFRACT_FBIT__ 31\000"
.LASF549:
	.ascii	"I2C4_ENABLE \000"
.LASF522:
	.ascii	"DMA1_STREAM6_ENABLE \000"
.LASF51:
	.ascii	"__INT_LEAST16_TYPE__ short int\000"
.LASF221:
	.ascii	"__FLT32_MAX_EXP__ 128\000"
.LASF403:
	.ascii	"__GCC_ATOMIC_CHAR_LOCK_FREE 1\000"
.LASF564:
	.ascii	"ADC3_ENABLE \000"
.LASF189:
	.ascii	"__DBL_DIG__ 15\000"
.LASF133:
	.ascii	"__INT_LEAST8_MAX__ 0x7f\000"
.LASF444:
	.ascii	"__ARM_ARCH_ISA_THUMB\000"
.LASF340:
	.ascii	"__LACCUM_FBIT__ 31\000"
.LASF379:
	.ascii	"__UTQ_IBIT__ 0\000"
.LASF299:
	.ascii	"__UFRACT_EPSILON__ 0x1P-16UR\000"
.LASF240:
	.ascii	"__FLT64_EPSILON__ 1.1\000"
.LASF246:
	.ascii	"__FLT32X_DIG__ 15\000"
.LASF334:
	.ascii	"__ACCUM_EPSILON__ 0x1P-15K\000"
.LASF376:
	.ascii	"__UDQ_FBIT__ 64\000"
.LASF245:
	.ascii	"__FLT32X_MANT_DIG__ 53\000"
.LASF71:
	.ascii	"__DEPRECATED 1\000"
.LASF378:
	.ascii	"__UTQ_FBIT__ 128\000"
.LASF276:
	.ascii	"__DEC128_MIN__ 1E-6143DL\000"
.LASF24:
	.ascii	"__CHAR_BIT__ 8\000"
.LASF546:
	.ascii	"I2C1_ENABLE \000"
.LASF449:
	.ascii	"__ARM_FP\000"
.LASF545:
	.ascii	"TIM14_ENABLE \000"
.LASF166:
	.ascii	"__INTPTR_WIDTH__ 32\000"
.LASF330:
	.ascii	"__ACCUM_FBIT__ 15\000"
.LASF15:
	.ascii	"__FINITE_MATH_ONLY__ 0\000"
.LASF323:
	.ascii	"__SACCUM_MAX__ 0X7FFFP-7HK\000"
.LASF437:
	.ascii	"__arm__ 1\000"
.LASF521:
	.ascii	"DMA1_STREAM5_ENABLE \000"
.LASF89:
	.ascii	"__cpp_initializer_lists 200806\000"
.LASF202:
	.ascii	"__LDBL_MANT_DIG__ 53\000"
.LASF369:
	.ascii	"__TQ_IBIT__ 0\000"
.LASF388:
	.ascii	"__UHA_FBIT__ 8\000"
.LASF399:
	.ascii	"__NO_INLINE__ 1\000"
.LASF543:
	.ascii	"TIM12_ENABLE \000"
.LASF489:
	.ascii	"YSS_H_HEAP_SIZE (8 * 1024)\000"
.LASF469:
	.ascii	"__ELF__ 1\000"
.LASF435:
	.ascii	"__ARM_ARCH_PROFILE\000"
.LASF584:
	.ascii	"bool\000"
.LASF512:
	.ascii	"UART5_ENABLE \000"
.LASF137:
	.ascii	"__INT16_C(c) c\000"
.LASF136:
	.ascii	"__INT_LEAST16_MAX__ 0x7fff\000"
.LASF264:
	.ascii	"__DEC32_EPSILON__ 1E-6DF\000"
.LASF343:
	.ascii	"__LACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LK\000"
.LASF157:
	.ascii	"__INT_FAST32_MAX__ 0x7fffffff\000"
.LASF458:
	.ascii	"__ARM_NEON\000"
.LASF11:
	.ascii	"__ATOMIC_ACQUIRE 2\000"
.LASF550:
	.ascii	"QUADSPI_ENABLE \000"
.LASF488:
	.ascii	"YSS_H_HEAP_USE true\000"
.LASF574:
	.ascii	"_ZN9TimeLapse7getUsecEv\000"
.LASF0:
	.ascii	"__STDC__ 1\000"
.LASF335:
	.ascii	"__UACCUM_FBIT__ 16\000"
.LASF192:
	.ascii	"__DBL_MAX_EXP__ 1024\000"
.LASF14:
	.ascii	"__ATOMIC_CONSUME 1\000"
.LASF158:
	.ascii	"__INT_FAST32_WIDTH__ 32\000"
.LASF76:
	.ascii	"__cpp_unicode_characters 200704\000"
.LASF591:
	.ascii	"_ZN9TimeLapseC2Ev\000"
.LASF36:
	.ascii	"__WINT_TYPE__ unsigned int\000"
.LASF100:
	.ascii	"__LONG_MAX__ 0x7fffffffL\000"
.LASF81:
	.ascii	"__cpp_constexpr 200704\000"
.LASF305:
	.ascii	"__ULFRACT_FBIT__ 32\000"
.LASF108:
	.ascii	"__SCHAR_WIDTH__ 8\000"
.LASF332:
	.ascii	"__ACCUM_MIN__ (-0X1P15K-0X1P15K)\000"
.LASF21:
	.ascii	"__SIZEOF_DOUBLE__ 8\000"
.LASF7:
	.ascii	"__GNUC_PATCHLEVEL__ 1\000"
.LASF72:
	.ascii	"__GXX_EXPERIMENTAL_CXX0X__ 1\000"
.LASF464:
	.ascii	"__ARM_ARCH_EXT_IDIV__\000"
.LASF293:
	.ascii	"__FRACT_MAX__ 0X7FFFP-15R\000"
.LASF45:
	.ascii	"__INT64_TYPE__ long long int\000"
.LASF345:
	.ascii	"__ULACCUM_FBIT__ 32\000"
.LASF297:
	.ascii	"__UFRACT_MIN__ 0.0UR\000"
.LASF459:
	.ascii	"__ARM_NEON_FP\000"
.LASF2:
	.ascii	"__STDC_UTF_16__ 1\000"
.LASF562:
	.ascii	"ADC1_ENABLE \000"
.LASF291:
	.ascii	"__FRACT_IBIT__ 0\000"
.LASF386:
	.ascii	"__TA_FBIT__ 63\000"
.LASF511:
	.ascii	"UART4_ENABLE \000"
.LASF215:
	.ascii	"__LDBL_HAS_INFINITY__ 1\000"
.LASF169:
	.ascii	"__GCC_IEC_559_COMPLEX 0\000"
.LASF131:
	.ascii	"__UINT32_MAX__ 0xffffffffUL\000"
.LASF468:
	.ascii	"__GXX_TYPEINFO_EQUALITY_INLINE 0\000"
.LASF204:
	.ascii	"__LDBL_MIN_EXP__ (-1021)\000"
.LASF315:
	.ascii	"__ULLFRACT_FBIT__ 64\000"
.LASF415:
	.ascii	"__SIZEOF_WCHAR_T__ 4\000"
.LASF519:
	.ascii	"DMA1_STREAM3_ENABLE \000"
.LASF30:
	.ascii	"__FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__\000"
.LASF333:
	.ascii	"__ACCUM_MAX__ 0X7FFFFFFFP-15K\000"
.LASF116:
	.ascii	"__SIZE_WIDTH__ 32\000"
.LASF259:
	.ascii	"__DEC32_MANT_DIG__ 7\000"
.LASF197:
	.ascii	"__DBL_EPSILON__ double(1.1)\000"
.LASF123:
	.ascii	"__SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)\000"
.LASF314:
	.ascii	"__LLFRACT_EPSILON__ 0x1P-63LLR\000"
.LASF559:
	.ascii	"SPI6_ENABLE \000"
.LASF516:
	.ascii	"DMA1_STREAM0_ENABLE \000"
.LASF287:
	.ascii	"__USFRACT_MIN__ 0.0UHR\000"
.LASF111:
	.ascii	"__LONG_WIDTH__ 32\000"
.LASF280:
	.ascii	"__SFRACT_FBIT__ 7\000"
.LASF40:
	.ascii	"__CHAR32_TYPE__ long unsigned int\000"
.LASF281:
	.ascii	"__SFRACT_IBIT__ 0\000"
.LASF420:
	.ascii	"__ARM_FEATURE_SAT\000"
.LASF78:
	.ascii	"__cpp_unicode_literals 200710\000"
.LASF363:
	.ascii	"__HQ_IBIT__ 0\000"
.LASF397:
	.ascii	"__USER_LABEL_PREFIX__ \000"
.LASF513:
	.ascii	"UART6_ENABLE \000"
.LASF56:
	.ascii	"__UINT_LEAST32_TYPE__ long unsigned int\000"
.LASF366:
	.ascii	"__DQ_FBIT__ 63\000"
.LASF328:
	.ascii	"__USACCUM_MAX__ 0XFFFFP-8UHK\000"
.LASF586:
	.ascii	"this\000"
.LASF124:
	.ascii	"__SIG_ATOMIC_WIDTH__ 32\000"
.LASF576:
	.ascii	"_ZN9TimeLapse7getMsecEv\000"
.LASF98:
	.ascii	"__SHRT_MAX__ 0x7fff\000"
.LASF524:
	.ascii	"DMA2_STREAM0_ENABLE \000"
.LASF452:
	.ascii	"__ARM_FP16_ARGS\000"
.LASF28:
	.ascii	"__ORDER_PDP_ENDIAN__ 3412\000"
.LASF365:
	.ascii	"__SQ_IBIT__ 0\000"
.LASF466:
	.ascii	"__ARM_ASM_SYNTAX_UNIFIED__\000"
.LASF180:
	.ascii	"__FLT_DECIMAL_DIG__ 9\000"
.LASF236:
	.ascii	"__FLT64_MAX_10_EXP__ 308\000"
.LASF127:
	.ascii	"__INT32_MAX__ 0x7fffffffL\000"
.LASF114:
	.ascii	"__WINT_WIDTH__ 32\000"
.LASF509:
	.ascii	"UART2_ENABLE \000"
.LASF418:
	.ascii	"__ARM_FEATURE_DSP\000"
.LASF370:
	.ascii	"__UQQ_FBIT__ 8\000"
.LASF16:
	.ascii	"__SIZEOF_INT__ 4\000"
.LASF523:
	.ascii	"DMA1_STREAM7_ENABLE \000"
.LASF530:
	.ascii	"DMA2_STREAM6_ENABLE \000"
.LASF338:
	.ascii	"__UACCUM_MAX__ 0XFFFFFFFFP-16UK\000"
.LASF268:
	.ascii	"__DEC64_MAX_EXP__ 385\000"
.LASF372:
	.ascii	"__UHQ_FBIT__ 16\000"
.LASF44:
	.ascii	"__INT32_TYPE__ long int\000"
.LASF248:
	.ascii	"__FLT32X_MIN_10_EXP__ (-307)\000"
.LASF74:
	.ascii	"__cpp_hex_float 201603\000"
.LASF17:
	.ascii	"__SIZEOF_LONG__ 4\000"
.LASF442:
	.ascii	"__thumb2__\000"
.LASF206:
	.ascii	"__LDBL_MAX_EXP__ 1024\000"
.LASF364:
	.ascii	"__SQ_FBIT__ 31\000"
.LASF495:
	.ascii	"YSS_L_HEAP 2\000"
.LASF302:
	.ascii	"__LFRACT_MIN__ (-0.5LR-0.5LR)\000"
.LASF275:
	.ascii	"__DEC128_MAX_EXP__ 6145\000"
.LASF103:
	.ascii	"__WCHAR_MIN__ 0U\000"
.LASF32:
	.ascii	"__GNUG__ 9\000"
.LASF441:
	.ascii	"__thumb__ 1\000"
.LASF216:
	.ascii	"__LDBL_HAS_QUIET_NAN__ 1\000"
.LASF42:
	.ascii	"__INT8_TYPE__ signed char\000"
.LASF104:
	.ascii	"__WINT_MAX__ 0xffffffffU\000"
.LASF491:
	.ascii	"YSS_H_MAX_NUM_OF_MALLOC 256\000"
.LASF209:
	.ascii	"__LDBL_DECIMAL_DIG__ 17\000"
.LASF395:
	.ascii	"__UTA_IBIT__ 64\000"
.LASF196:
	.ascii	"__DBL_MIN__ double(1.1)\000"
.LASF510:
	.ascii	"UART3_ENABLE \000"
.LASF507:
	.ascii	"NUM_OF_YSS_KEY 0\000"
.LASF368:
	.ascii	"__TQ_FBIT__ 127\000"
.LASF289:
	.ascii	"__USFRACT_EPSILON__ 0x1P-8UHR\000"
.LASF391:
	.ascii	"__USA_IBIT__ 16\000"
.LASF498:
	.ascii	"THREAD_GIVEN_CLOCK 20000\000"
.LASF164:
	.ascii	"__UINT_FAST64_MAX__ 0xffffffffffffffffULL\000"
.LASF163:
	.ascii	"__UINT_FAST32_MAX__ 0xffffffffU\000"
.LASF285:
	.ascii	"__USFRACT_FBIT__ 8\000"
.LASF143:
	.ascii	"__INT64_C(c) c ## LL\000"
.LASF362:
	.ascii	"__HQ_FBIT__ 15\000"
.LASF238:
	.ascii	"__FLT64_MAX__ 1.1\000"
.LASF389:
	.ascii	"__UHA_IBIT__ 8\000"
.LASF102:
	.ascii	"__WCHAR_MAX__ 0xffffffffU\000"
.LASF577:
	.ascii	"reset\000"
.LASF18:
	.ascii	"__SIZEOF_LONG_LONG__ 8\000"
.LASF371:
	.ascii	"__UQQ_IBIT__ 0\000"
.LASF46:
	.ascii	"__UINT8_TYPE__ unsigned char\000"
.LASF109:
	.ascii	"__SHRT_WIDTH__ 16\000"
.LASF53:
	.ascii	"__INT_LEAST64_TYPE__ long long int\000"
.LASF48:
	.ascii	"__UINT32_TYPE__ long unsigned int\000"
.LASF205:
	.ascii	"__LDBL_MIN_10_EXP__ (-307)\000"
.LASF252:
	.ascii	"__FLT32X_MAX__ 1.1\000"
.LASF525:
	.ascii	"DMA2_STREAM1_ENABLE \000"
.LASF31:
	.ascii	"__SIZEOF_POINTER__ 4\000"
.LASF448:
	.ascii	"__VFP_FP__ 1\000"
.LASF308:
	.ascii	"__ULFRACT_MAX__ 0XFFFFFFFFP-32ULR\000"
.LASF544:
	.ascii	"TIM13_ENABLE \000"
.LASF380:
	.ascii	"__HA_FBIT__ 7\000"
.LASF115:
	.ascii	"__PTRDIFF_WIDTH__ 32\000"
.LASF487:
	.ascii	"YSS_USE_DEFAULT_MSP true\000"
.LASF322:
	.ascii	"__SACCUM_MIN__ (-0X1P7HK-0X1P7HK)\000"
.LASF110:
	.ascii	"__INT_WIDTH__ 32\000"
.LASF412:
	.ascii	"__GCC_ATOMIC_POINTER_LOCK_FREE 1\000"
.LASF152:
	.ascii	"__UINT64_C(c) c ## ULL\000"
.LASF8:
	.ascii	"__VERSION__ \"9.3.1 20200408 (release)\"\000"
.LASF344:
	.ascii	"__LACCUM_EPSILON__ 0x1P-31LK\000"
.LASF284:
	.ascii	"__SFRACT_EPSILON__ 0x1P-7HR\000"
.LASF547:
	.ascii	"I2C2_ENABLE \000"
.LASF73:
	.ascii	"__cpp_binary_literals 201304\000"
.LASF535:
	.ascii	"TIM4_ENABLE \000"
.LASF571:
	.ascii	"TimeLapse\000"
.LASF381:
	.ascii	"__HA_IBIT__ 8\000"
.LASF583:
	.ascii	"long unsigned int\000"
.LASF405:
	.ascii	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 1\000"
.LASF508:
	.ascii	"UART1_ENABLE \000"
.LASF496:
	.ascii	"YSS_NEW_DELETE_USING_HEAP YSS_H_HEAP\000"
.LASF551:
	.ascii	"SDMMC_ENABLE \000"
.LASF184:
	.ascii	"__FLT_DENORM_MIN__ 1.1\000"
.LASF294:
	.ascii	"__FRACT_EPSILON__ 0x1P-15R\000"
.LASF4:
	.ascii	"__STDC_HOSTED__ 1\000"
.LASF165:
	.ascii	"__INTPTR_MAX__ 0x7fffffff\000"
.LASF68:
	.ascii	"__has_include(STR) __has_include__(STR)\000"
.LASF447:
	.ascii	"__SOFTFP__ 1\000"
.LASF82:
	.ascii	"__cpp_range_based_for 200907\000"
.LASF470:
	.ascii	"__SIZEOF_WCHAR_T 4\000"
.LASF410:
	.ascii	"__GCC_ATOMIC_LLONG_LOCK_FREE 1\000"
.LASF178:
	.ascii	"__FLT_MAX_EXP__ 128\000"
.LASF13:
	.ascii	"__ATOMIC_ACQ_REL 4\000"
.LASF149:
	.ascii	"__UINT_LEAST32_MAX__ 0xffffffffUL\000"
.LASF427:
	.ascii	"__ARM_32BIT_STATE\000"
.LASF260:
	.ascii	"__DEC32_MIN_EXP__ (-94)\000"
.LASF38:
	.ascii	"__UINTMAX_TYPE__ long long unsigned int\000"
.LASF66:
	.ascii	"__INTPTR_TYPE__ int\000"
.LASF172:
	.ascii	"__DEC_EVAL_METHOD__ 2\000"
.LASF226:
	.ascii	"__FLT32_EPSILON__ 1.1\000"
.LASF86:
	.ascii	"__cpp_rvalue_reference 200610\000"
.LASF286:
	.ascii	"__USFRACT_IBIT__ 0\000"
.LASF499:
	.ascii	"MAX_THREAD 64\000"
.LASF141:
	.ascii	"__INT_LEAST32_WIDTH__ 32\000"
.LASF54:
	.ascii	"__UINT_LEAST8_TYPE__ unsigned char\000"
.LASF556:
	.ascii	"SPI3_ENABLE \000"
.LASF64:
	.ascii	"__UINT_FAST32_TYPE__ unsigned int\000"
.LASF213:
	.ascii	"__LDBL_DENORM_MIN__ 1.1\000"
.LASF367:
	.ascii	"__DQ_IBIT__ 0\000"
.LASF33:
	.ascii	"__SIZE_TYPE__ unsigned int\000"
.LASF480:
	.ascii	"__TARGET_PROCESSOR_STM32L073RZ 1\000"
.LASF531:
	.ascii	"DMA2_STREAM7_ENABLE \000"
.LASF355:
	.ascii	"__ULLACCUM_FBIT__ 32\000"
.LASF536:
	.ascii	"TIM5_ENABLE \000"
.LASF233:
	.ascii	"__FLT64_MIN_EXP__ (-1021)\000"
.LASF506:
	.ascii	"YSS_GUI_FRAME_BUFFER Rgb565\000"
.LASF290:
	.ascii	"__FRACT_FBIT__ 15\000"
.LASF92:
	.ascii	"__cpp_inheriting_constructors 201511\000"
.LASF177:
	.ascii	"__FLT_MIN_10_EXP__ (-37)\000"
.LASF247:
	.ascii	"__FLT32X_MIN_EXP__ (-1021)\000"
.LASF532:
	.ascii	"TIM1_ENABLE \000"
.LASF171:
	.ascii	"__FLT_EVAL_METHOD_TS_18661_3__ 0\000"
.LASF200:
	.ascii	"__DBL_HAS_INFINITY__ 1\000"
.LASF520:
	.ascii	"DMA1_STREAM4_ENABLE \000"
.LASF60:
	.ascii	"__INT_FAST32_TYPE__ int\000"
.LASF187:
	.ascii	"__FLT_HAS_QUIET_NAN__ 1\000"
.LASF145:
	.ascii	"__UINT_LEAST8_MAX__ 0xff\000"
.LASF502:
	.ascii	"USE_EVENT true\000"
.LASF37:
	.ascii	"__INTMAX_TYPE__ long long int\000"
.LASF118:
	.ascii	"__INTMAX_C(c) c ## LL\000"
.LASF476:
	.ascii	"__GNU_LINKER 1\000"
.LASF440:
	.ascii	"__APCS_32__ 1\000"
.LASF492:
	.ascii	"YSS_H_HEAP_TOTAL_CLUSTER_SIZE (YSS_H_HEAP_SIZE / YS"
	.ascii	"S_H_HEAP_CLUSTER_SIZE / 32)\000"
.LASF49:
	.ascii	"__UINT64_TYPE__ long long unsigned int\000"
.LASF258:
	.ascii	"__FLT32X_HAS_QUIET_NAN__ 1\000"
.LASF193:
	.ascii	"__DBL_MAX_10_EXP__ 308\000"
.LASF585:
	.ascii	"short unsigned int\000"
.LASF475:
	.ascii	"__CROSSWORKS_REVISION 3\000"
.LASF387:
	.ascii	"__TA_IBIT__ 64\000"
.LASF360:
	.ascii	"__QQ_FBIT__ 7\000"
.LASF257:
	.ascii	"__FLT32X_HAS_INFINITY__ 1\000"
.LASF154:
	.ascii	"__INT_FAST8_WIDTH__ 32\000"
.LASF176:
	.ascii	"__FLT_MIN_EXP__ (-125)\000"
.LASF402:
	.ascii	"__GCC_ATOMIC_BOOL_LOCK_FREE 1\000"
.LASF277:
	.ascii	"__DEC128_MAX__ 9.999999999999999999999999999999999E"
	.ascii	"6144DL\000"
.LASF208:
	.ascii	"__DECIMAL_DIG__ 17\000"
.LASF140:
	.ascii	"__INT32_C(c) c ## L\000"
.LASF541:
	.ascii	"TIM10_ENABLE \000"
.LASF587:
	.ascii	"GNU C++11 9.3.1 20200408 (release) -fmessage-length"
	.ascii	"=0 -fno-exceptions -fno-rtti -mcpu=cortex-m0plus -m"
	.ascii	"little-endian -mfloat-abi=soft -mthumb -mtp=soft -m"
	.ascii	"no-unaligned-access -std=gnu++11 -g3 -gpubnames -fo"
	.ascii	"mit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin "
	.ascii	"-ffunction-sections -fdata-sections -fshort-enums -"
	.ascii	"fno-common\000"
.LASF451:
	.ascii	"__ARM_FP16_FORMAT_ALTERNATIVE\000"
.LASF207:
	.ascii	"__LDBL_MAX_10_EXP__ 308\000"
.LASF250:
	.ascii	"__FLT32X_MAX_10_EXP__ 308\000"
.LASF167:
	.ascii	"__UINTPTR_MAX__ 0xffffffffU\000"
.LASF199:
	.ascii	"__DBL_HAS_DENORM__ 1\000"
.LASF477:
	.ascii	"STM32L073xx 1\000"
.LASF424:
	.ascii	"__ARM_FEATURE_CRC32\000"
.LASF222:
	.ascii	"__FLT32_MAX_10_EXP__ 38\000"
.LASF430:
	.ascii	"__ARM_FEATURE_CLZ\000"
.LASF303:
	.ascii	"__LFRACT_MAX__ 0X7FFFFFFFP-31LR\000"
.LASF392:
	.ascii	"__UDA_FBIT__ 32\000"
.LASF353:
	.ascii	"__LLACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LLK\000"
.LASF474:
	.ascii	"__CROSSWORKS_MINOR_VERSION 7\000"
.LASF139:
	.ascii	"__INT_LEAST32_MAX__ 0x7fffffffL\000"
.LASF210:
	.ascii	"__LDBL_MAX__ 1.1\000"
.LASF269:
	.ascii	"__DEC64_MIN__ 1E-383DD\000"
.LASF527:
	.ascii	"DMA2_STREAM3_ENABLE \000"
.LASF409:
	.ascii	"__GCC_ATOMIC_LONG_LOCK_FREE 1\000"
.LASF461:
	.ascii	"__ARM_ARCH_6M__ 1\000"
.LASF119:
	.ascii	"__UINTMAX_MAX__ 0xffffffffffffffffULL\000"
.LASF41:
	.ascii	"__SIG_ATOMIC_TYPE__ int\000"
.LASF312:
	.ascii	"__LLFRACT_MIN__ (-0.5LLR-0.5LLR)\000"
.LASF239:
	.ascii	"__FLT64_MIN__ 1.1\000"
.LASF319:
	.ascii	"__ULLFRACT_EPSILON__ 0x1P-64ULLR\000"
.LASF214:
	.ascii	"__LDBL_HAS_DENORM__ 1\000"
.LASF147:
	.ascii	"__UINT_LEAST16_MAX__ 0xffff\000"
.LASF478:
	.ascii	"__VECTORS \"STM32L073xx.vec\"\000"
.LASF359:
	.ascii	"__ULLACCUM_EPSILON__ 0x1P-32ULLK\000"
.LASF266:
	.ascii	"__DEC64_MANT_DIG__ 16\000"
.LASF185:
	.ascii	"__FLT_HAS_DENORM__ 1\000"
.LASF160:
	.ascii	"__INT_FAST64_WIDTH__ 64\000"
.LASF194:
	.ascii	"__DBL_DECIMAL_DIG__ 17\000"
	.ident	"GCC: (GNU) 9.3.1 20200408 (release)"
