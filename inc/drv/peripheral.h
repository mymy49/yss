/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file peripheral.h
 * @brief Target-specific hardware register and peripheral mapping wrapper.
 */

#ifndef YSS_PERIPHERAL__H_
#define YSS_PERIPHERAL__H_

#include "mcu.h"
#include <stdint.h>

#if defined(STM32F1)

#include <targets/st/stm32f1xx.h>

#elif defined(STM32G4)

#include <targets/st/stm32g4xx.h>

#elif defined(STM32F4)

#include <targets/st/stm32f4xx.h>

#elif defined(STM32F7)

#include <targets/st/stm32f7xx.h>

#elif defined(GD32F10X_XD)

#include <targets/st/stm32f103xg.h>
#include <targets/st/define_stm32f103xx.h>

#elif defined(GD32F10X_MD)

#include <targets/st/stm32f103xb.h>
#include <targets/st/define_stm32f103xx.h>

#elif defined(GD32F4)

#include <targets/st_gigadevice/gd32f4xx.h>

#elif defined(NRF52840_XXAA)

#include <targets/nordic/nrf52840.h>

#elif defined(STM32L1)

#include <targets/st_gigadevice/stm32l1xx.h>

#elif defined(STM32F0)

#include <targets/st/stm32f0xx.h>

#elif defined(EFM32PG22) || defined(EFR32BG22)

#include <targets/siliconlabs/em_device.h>

#elif defined(MAX32672)

#include <targets/maxim/max32672/max32672.h>
#include <targets/maxim/max32672/define_max32672.h>

#elif defined(W7500)

#include <targets/wiznet/w7500x.h>
#include <targets/wiznet/define_w7500x.h>

#elif defined(CPU_MIMXRT1011DAE5A)

#include <targets/nxp/MIMXRT1011.h>
//#include <targets/nxp/define_w7500x.h>

#elif defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <NuMicro.h>

#elif defined(__MAX32665_FAMILY)

#include <gpio_regs.h>
#include <sema_regs.h>
#include <icc_regs.h>
#include <flc_regs.h>
#include <htmr_regs.h>
#include <tmr_regs.h>
#include <gcr_regs.h>
#include <max32665.h>

#else

/* Configuration of the Cortex-M4 Processor and Core Peripherals */
#define __CM4_REV                 0x0201UL    /*!< Core Revision r2p1                               */
#define __NVIC_PRIO_BITS          4UL         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0UL         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT             1UL         /*!< MPU present or not                               */
#ifdef __FPU_PRESENT
#undef __FPU_PRESENT
#define __FPU_PRESENT             1UL         /*!< FPU present or not                               */
#else
#define __FPU_PRESENT             1UL         /*!< FPU present or not                               */
#endif

/*@}*/ /* end of group CMSIS_Device */

/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup CMSIS_Device Device CMSIS Definitions
  Configuration of the Cortex-M4 Processor and Core Peripherals
  @{
*/

/**
 * @details  Interrupt Number Definition.
 */
typedef enum IRQn
{
    /******  Cortex-M4 Processor Exceptions Numbers ***************************************************/
    NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                        */
    MemoryManagement_IRQn         = -12,      /*!<  4 Memory Management Interrupt                   */
    BusFault_IRQn                 = -11,      /*!<  5 Bus Fault Interrupt                           */
    UsageFault_IRQn               = -10,      /*!<  6 Usage Fault Interrupt                         */
    SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                             */
    DebugMonitor_IRQn             = -4,       /*!< 12 Debug Monitor Interrupt                       */
    PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                             */
    SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                         */

} IRQn_Type;

#include <cmsis_gcc.h>
#include <core_cm4.h>

#endif

#endif