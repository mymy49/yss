/******************************************************************************
 * @file:    system_stm32f10x_cl.h
 * @purpose: CMSIS Cortex-M3 Device Peripheral Access Layer Header File for the
 *           ST STM32 Connectivity Line Device Series
 * @version: V1.01
 * @date:    22. Jul. 2009
 *----------------------------------------------------------------------------
 *
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * ARM Limited (ARM) is supplying this software for use with Cortex-Mx 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/


#ifndef __SYSTEM_STM32F10x_CL_H
#define __SYSTEM_STM32F10x_CL_H

#ifdef __cplusplus
 extern "C" {
#endif 

extern uint32_t SystemFrequency;    /*!< System Clock Frequency (Core Clock)  */


/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system
 *         Initialize the Embedded Flash Interface,  initialize the PLL and update the SystemFrequency variable
 */
extern void SystemInit (void);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_STM32F10x_CL_H */
