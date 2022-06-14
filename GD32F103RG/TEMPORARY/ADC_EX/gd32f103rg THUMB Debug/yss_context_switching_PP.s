# 1 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
# 61 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
 .thumb_func
 .syntax unified
 .type SysTick_Handler, %function
 .global SysTick_Handler
 .section .text, "ax"
SysTick_Handler:
# 76 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
 ldr r0, =0xe000ed04
 ldr r1, [r0]
 movs r2, #1
 lsls r2, r2, 28
 orrs r1, r1, r2
 str r1, [r0]
 bx lr





 .thumb_func
 .type PendSV_Handler, %function
 .global PendSV_Handler
 .global getNextContext
 .section .text, "ax"
PendSV_Handler:
# 131 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
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
 ldm r0!, {r3-r6}
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
 ldm r0!, {r3-r7}
 adds r0, r0, #16
 msr psp, r0
 push {r3}
 pop {pc}
 nop





 .thumb_func
 .type yield, %function
 .global yield
 .section .text, "ax"
yield:
# 184 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
 ldr r0, =0xE000ED04
 ldr r1, [r0]
 movs r2, #1
 lsls r2, #28
 orrs r1, r1, r2
 str r1, [r0]
 bx lr
