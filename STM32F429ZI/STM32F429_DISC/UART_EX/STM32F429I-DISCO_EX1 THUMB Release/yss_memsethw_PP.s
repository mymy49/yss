# 1 "/home/mymy49/library/yss/yss/stdlib/yss_memsethw.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/mymy49/library/yss/yss/stdlib/yss_memsethw.s"
# 43 "/home/mymy49/library/yss/yss/stdlib/yss_memsethw.s"
 .thumb_func
 .syntax unified
 .func memsethw
 .type memsethw, %function
 .global memsethw
 .section .text, "ax"
memsethw:
 push {r3-r7}
 mov r4, #0xffff
 lsl r4, #16
 bic r1, r4
 lsl r3, r1, #16
 orr r4, r1, r3
 mov r5, r4
 mov r6, r4
 mov r7, r4
repeat:
    movs r1, #512
 subs r3, r2, r1
 bge greater
 ands r3, r2, #0xf
 bic r2, #0xf
 subs r1, r1, r2
 lsr r1, r1, #3
 adds r1, r1, #2
 movs r2, r3
 bic r2, #1
 add pc, pc, r1
greater:
 subs r2, #512
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
    stmia R0!,{R4-R7}
 subs r3, r2, #16
 bhi repeat
 movs r2, r2
 beq finish
 subs r3, r2, #8
 blt sub4
    stmia R0!,{R4-R5}
 subs r2, #8
sub4:
 subs r3, r2, #4
 blt sub2
 str r4, [r0], #4
 subs r2, #4
sub2:
 movs r2, r2
 beq finish
 strh r4, [r0], #2
finish:
 pop {r3-r7}
 bx lr
