/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MCU__H_
#define YSS_MCU__H_

#include <yss/reg.h>

#if defined(STM32F103xB) || defined(STM32F103xE)

#ifndef STM32F1
#define STM32F1
#endif

#define DEFAULT_CLOCK_SPEED 8000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC

#elif defined(STM32F407xx)

#ifndef STM32F4
#define STM32F4
#endif

#define DEFAULT_CLOCK_SPEED	16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC

#elif defined(STM32F446xx) || defined(STM32F429xx)

#ifndef STM32F4
#define STM32F4
#endif

#define DEFAULT_CLOCK_SPEED 16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC

#elif defined(STM32F767xx) || defined(STM32F746xx)

#ifndef STM32F7
#define STM32F7
#endif

#define DEFAULT_CLOCK_SPEED 16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#define YSS_MEMDMA_SUPPORT

#elif defined(STM32G431xx) || defined(STM32G441xx) || \
	defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#ifndef STM32G4
#define STM32G4
#endif

#define DEFAULT_CLOCK_SPEED 16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#define YSS__UART_RX_DMA

#elif defined(GD32F10X_HD) || defined(GD32F10X_XD) || defined(GD32F10X_MD)

#define GD32F1
#define DEFAULT_CLOCK_SPEED 8000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC

#elif defined(GD32F450)

#define GD32F4
#define DEFAULT_CLOCK_SPEED 16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC

#elif defined(NRF52840_XXAA)

#define DEFAULT_CLOCK_SPEED 64000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC

#elif defined (STM32L100xB) || defined (STM32L100xBA) || defined (STM32L100xC) || \
    defined (STM32L151xB) || defined (STM32L151xBA) || defined (STM32L151xC) || defined (STM32L151xCA) || defined (STM32L151xD) || defined (STM32L151xDX) || defined (STM32L151xE) || \
    defined (STM32L152xB) || defined (STM32L152xBA) || defined (STM32L152xC) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L152xDX) || defined (STM32L152xE) || \
    defined (STM32L162xC) || defined (STM32L162xCA) || defined (STM32L162xD) || defined (STM32L162xDX) || defined (STM32L162xE)

#define STM32L1
#define DEFAULT_CLOCK_SPEED 8000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC

#elif defined(STM32F030xC)

#ifndef STM32F0
#define STM32F0
#endif

#define DEFAULT_CLOCK_SPEED 8000000
#define YSS__CORE_CM0_H_GENERIC
#define YSS_MEMDMA_SUPPORT

#elif defined(EFM32PG22C200F512IM40)

#define EFM32PG22
#define DEFAULT_CLOCK_SPEED 20000000
#define YSS__CORE_CM33_H_GENERIC

#elif defined(EFR32BG22C224F512IM40)

#define EFR32BG22
#define DEFAULT_CLOCK_SPEED 20000000
#define YSS__CORE_CM33_H_GENERIC

#elif defined(MAX32672)

#define DEFAULT_CLOCK_SPEED 100000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC

#elif defined(W7500)

#define DEFAULT_CLOCK_SPEED 100000000
#define YSS__CORE_CM0_H_GENERIC
#define YSS__RUNTIME_SUPPORT

#elif defined(CPU_MIMXRT1011DAE5A)
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
//#define YSS__RUNTIME_SUPPORT

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#define YSS__RUNTIME_SUPPORT
#define YSS__DMA_ALLOCATION

#if defined(__M480_FAMILY)
#define YSS__NUM_OF_DMA_CH		16
#elif defined(__M4xx_FAMILY)
#define YSS__NUM_OF_DMA_CH		9
#endif

#elif defined(__M2xx_FAMILY)
#define YSS__CORE_CM0_H_GENERIC
#define YSS__RUNTIME_SUPPORT
#define YSS__DMA_ALLOCATION

#if defined(__M25x_SUBFAMILY)
#define YSS__NUM_OF_DMA_CH		8
#endif

#else

#define ERROR_MCU_NOT_ABLE

#endif

#endif
