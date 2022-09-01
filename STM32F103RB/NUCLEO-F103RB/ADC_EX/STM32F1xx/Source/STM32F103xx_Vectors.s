/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*            (c) 2014 - 2020 SEGGER Microcontroller GmbH             *
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

File      : STM32F103xx_Vectors.s
Purpose   : Exception and interrupt vectors for STM32F103xx devices.

Additional information:
  Preprocessor Definitions
    __NO_EXTERNAL_INTERRUPTS
      If defined,
        the vector table will contain only the internal exceptions
        and interrupts.
    __VECTORS_IN_RAM
      If defined,
        an area of RAM, large enough to store the vector table, 
        will be reserved.

    __OPTIMIZATION_SMALL
      If defined,
        all weak definitions of interrupt handlers will share the 
        same implementation.
      If not defined,
        all weak definitions of interrupt handlers will be defined
        with their own implementation.
*/
        .syntax unified

/*********************************************************************
*
*       Macros
*
**********************************************************************
*/

//
// Directly place a vector (word) in the vector table
//
.macro VECTOR Name=
        .section .vectors, "ax"
        .code 16
        .word \Name
.endm

//
// Declare an exception handler with a weak definition
//
.macro EXC_HANDLER Name=
        //
        // Insert vector in vector table
        //
        .section .vectors, "ax"
        .word \Name
        //
        // Insert dummy handler in init section
        //
        .section .init.\Name, "ax"
        .thumb_func
        .weak \Name
\Name:
        1: b 1b   // Endless loop
.endm

//
// Declare an interrupt handler with a weak definition
//
.macro ISR_HANDLER Name=
        //
        // Insert vector in vector table
        //
        .section .vectors, "ax"
        .word \Name
        //
        // Insert dummy handler in init section
        //
#if defined(__OPTIMIZATION_SMALL)
        .section .init, "ax"
        .weak \Name
        .thumb_set \Name,Dummy_Handler
#else
        .section .init.\Name, "ax"
        .thumb_func
        .weak \Name
\Name:
        1: b 1b   // Endless loop
#endif
.endm

//
// Place a reserved vector in vector table
//
.macro ISR_RESERVED
        .section .vectors, "ax"
        .word 0
.endm

//
// Place a reserved vector in vector table
//
.macro ISR_RESERVED_DUMMY
        .section .vectors, "ax"
        .word Dummy_Handler
.endm

/*********************************************************************
*
*       Externals
*
**********************************************************************
*/
        .extern __stack_end__
        .extern Reset_Handler
        .extern HardFault_Handler

/*********************************************************************
*
*       Global functions
*
**********************************************************************
*/

/*********************************************************************
*
*  Setup of the vector table and weak definition of interrupt handlers
*
*/
        .section .vectors, "ax"
        .code 16
        .balign 512
        .global _vectors
_vectors:
        //
        // Internal exceptions and interrupts
        //
        VECTOR __stack_end__
        VECTOR Reset_Handler
        EXC_HANDLER NMI_Handler
        VECTOR HardFault_Handler
        ISR_RESERVED
        ISR_RESERVED
        ISR_RESERVED
        ISR_RESERVED
        ISR_RESERVED
        ISR_RESERVED
        ISR_RESERVED
        EXC_HANDLER SVC_Handler
        ISR_RESERVED
        ISR_RESERVED
        EXC_HANDLER PendSV_Handler
        EXC_HANDLER SysTick_Handler
        //
        // External interrupts
        //
#ifndef __NO_EXTERNAL_INTERRUPTS
        ISR_HANDLER WWDG_IRQHandler
        ISR_HANDLER PVD_IRQHandler
        ISR_HANDLER TAMPER_IRQHandler
        ISR_HANDLER RTC_IRQHandler
        ISR_HANDLER FLASH_IRQHandler
        ISR_HANDLER RCC_IRQHandler
        ISR_HANDLER EXTI0_IRQHandler
        ISR_HANDLER EXTI1_IRQHandler
        ISR_HANDLER EXTI2_IRQHandler
        ISR_HANDLER EXTI3_IRQHandler
        ISR_HANDLER EXTI4_IRQHandler
        ISR_HANDLER DMA1_Channel1_IRQHandler
        ISR_HANDLER DMA1_Channel2_IRQHandler
        ISR_HANDLER DMA1_Channel3_IRQHandler
        ISR_HANDLER DMA1_Channel4_IRQHandler
        ISR_HANDLER DMA1_Channel5_IRQHandler
        ISR_HANDLER DMA1_Channel6_IRQHandler
        ISR_HANDLER DMA1_Channel7_IRQHandler
        ISR_HANDLER ADC_IRQHandler
        ISR_HANDLER CAN1_TX_IRQHandler
        ISR_HANDLER CAN1_RX0_IRQHandler
        ISR_HANDLER CAN1_RX1_IRQHandler
        ISR_HANDLER CAN1_SCE_IRQHandler
        ISR_HANDLER EXTI9_5_IRQHandler
        ISR_HANDLER TIM1_BRK_TIM9_IRQHandler
        ISR_HANDLER TIM1_UP_TIM10_IRQHandler
        ISR_HANDLER TIM1_TRG_COM_TIM11_IRQHandler
        ISR_HANDLER TIM1_CC_IRQHandler
        ISR_HANDLER TIM2_IRQHandler
        ISR_HANDLER TIM3_IRQHandler
        ISR_HANDLER TIM4_IRQHandler
        ISR_HANDLER I2C1_EV_IRQHandler
        ISR_HANDLER I2C1_ER_IRQHandler
        ISR_HANDLER I2C2_EV_IRQHandler
        ISR_HANDLER I2C2_ER_IRQHandler
        ISR_HANDLER SPI1_IRQHandler
        ISR_HANDLER SPI2_IRQHandler
        ISR_HANDLER USART1_IRQHandler
        ISR_HANDLER USART2_IRQHandler
        ISR_HANDLER USART3_IRQHandler
        ISR_HANDLER EXTI15_10_IRQHandler
        ISR_HANDLER RTCAlarm_IRQHandler
        ISR_HANDLER USB_FS_WKUP_IRQHandler
        ISR_HANDLER TIM8_BRK_TIM12_IRQHandler
        ISR_HANDLER TIM8_UP_TIM13_IRQHandler
        ISR_HANDLER TIM8_TRG_COM_TIM14_IRQHandler
        ISR_HANDLER TIM8_CC_IRQHandler
        ISR_HANDLER ADC3_IRQHandler
        ISR_HANDLER FSMC_IRQHandler
        ISR_HANDLER SDIO_IRQHandler
        ISR_HANDLER TIM5_IRQHandler
        ISR_HANDLER SPI3_IRQHandler
        ISR_HANDLER UART4_IRQHandler
        ISR_HANDLER UART5_IRQHandler
        ISR_HANDLER TIM6_IRQHandler
        ISR_HANDLER TIM7_IRQHandler
        ISR_HANDLER DMA2_Channel1_IRQHandler
        ISR_HANDLER DMA2_Channel2_IRQHandler
        ISR_HANDLER DMA2_Channel3_IRQHandler
        ISR_HANDLER DMA2_Channel4_5_IRQHandler
#endif
        //
        .section .vectors, "ax"
_vectors_end:

#ifdef __VECTORS_IN_RAM
        //
        // Reserve space with the size of the vector table
        // in the designated RAM section.
        //
        .section .vectors_ram, "ax"
        .balign 512
        .global _vectors_ram

_vectors_ram:
        .space _vectors_end - _vectors, 0
#endif

/*********************************************************************
*
*  Dummy handler to be used for reserved interrupt vectors
*  and weak implementation of interrupts.
*
*/
        .section .init.Dummy_Handler, "ax"
        .thumb_func
        .weak Dummy_Handler
Dummy_Handler:
        1: b 1b   // Endless loop


/*************************** End of file ****************************/
