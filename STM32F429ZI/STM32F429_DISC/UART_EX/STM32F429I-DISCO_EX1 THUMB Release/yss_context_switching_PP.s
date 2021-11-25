# 1 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
# 63 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
 .thumb_func
 .syntax unified
 .type SysTick_Handler, %function
 .global SysTick_Handler
 .section .text, "ax"
SysTick_Handler:


 movw r0, 0xED04
 movt r0, 0xE000
 ldr r1, [r0]
 orrs r1, r1, #(1 << 28)
 str r1, [r0]
 bx lr
# 90 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
 .thumb_func
 .type PendSV_Handler, %function
 .global PendSV_Handler
 .global getNextContext
 .section .text, "ax"
PendSV_Handler:


 mrs r0, psp
 movw r3, 0xE010
 movt r3, 0xE000
 mov r1, #0
 str r1, [r3]







 mov r3, lr
 stmdb r0!, {r3-r11}

 bl getNextContext






 ldm r0!, {r3-r11}

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
# 170 "/home/mymy49/library/yss/yss/scheduler/yss_context_switching.s"
 .thumb_func
 .type yield, %function
 .global yield
 .section .text, "ax"
yield:


 push {r0-r1}
 movw r0, 0xED04
 movt r0, 0xE000
 ldr r1, [r0]
 orrs r1, r1, #(1 << 28)
 str r1, [r0]
 pop {r0-r1}
 bx lr
