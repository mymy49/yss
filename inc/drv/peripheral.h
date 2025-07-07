/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
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

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <targets/nuvoton/M4xx.h>

#elif defined(__M2xx_FAMILY)

#include <targets/nuvoton/M2xx.h>

#else

typedef volatile int IRQn_Type;

#define PendSV_IRQn 0
#define SysTick_CTRL_CLKSOURCE_Pos 0
#define SysTick_CTRL_TICKINT_Pos 0
#define SysTick_CTRL_ENABLE_Pos 0

#define SysTick ((SysTick_Type *)0) // !< SysTick configuration struct

#define NVIC_DisableIRQ
#define NVIC_EnableIRQ

#endif

#endif