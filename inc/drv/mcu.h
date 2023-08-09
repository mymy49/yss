////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////
#ifndef YSS_MCU__H_
#define YSS_MCU__H_

#include <yss/reg.h>

#if defined(STM32F103xB) || defined(STM32F103xE)

#ifndef STM32F1_N
#define STM32F1_N
#define DEFAULT_CLOCK_SPEED 8000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#endif

#elif defined(STM32F103x6) || defined(STM32F103xG) || \
	defined(STM32F10X_MD)
#ifndef STM32F1
#define STM32F1
#define DEFAULT_CLOCK_SPEED 8000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#endif

#elif defined(STM32F411xE)

#ifndef STM32F4
#define STM32F4
#define DEFAULT_CLOCK_SPEED 16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#endif

#elif defined(STM32F446xx) || defined(STM32F429xx)

#ifndef STM32F4_N
#define STM32F4_N
#define DEFAULT_CLOCK_SPEED 16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#endif

#elif defined(STM32F767xx) || defined(STM32F746xx)

#ifndef STM32F7_N
#define DEFAULT_CLOCK_SPEED 16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#define STM32F7_N
#endif

#elif defined(STM32G431xx) || defined(STM32G441xx) || \
	defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#ifndef STM32G4
#define STM32G4
#define DEFAULT_CLOCK_SPEED 16000000
#define YSS__CORE_CM3_CM4_CM7_H_GENERIC
#endif

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

#define STM32F0_N
#define DEFAULT_CLOCK_SPEED 8000000
#define YSS__CORE_CM0_H_GENERIC

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

#else

#define ERROR_MCU_NOT_ABLE

#endif

#endif