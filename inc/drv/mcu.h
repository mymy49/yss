////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MCU__H_
#define YSS_MCU__H_

#include <yss/reg.h>

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
	defined(STM32F10X_MD)
#ifndef STM32F1
#define STM32F1
#define DEFAULT_CLOCK_SPEED 8000000
#endif

#elif defined(STM32F411xE) || defined(STM32F429xx)

#ifndef STM32F4
#define STM32F4
#define DEFAULT_CLOCK_SPEED 16000000
#endif

#elif defined(STM32F746xx)

#ifndef STM32F7
#define STM32F7
#endif

#elif defined(STM32G431xx) || defined(STM32G441xx) || \
	defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#ifndef STM32G4
#define STM32G4
#endif

#elif defined(GD32F10X_HD) || defined(GD32F10X_XD)

#define GD32F1
#define DEFAULT_CLOCK_SPEED 8000000

#elif defined(GD32F450)

#define GD32F4
#define DEFAULT_CLOCK_SPEED 16000000

#elif defined(NRF52840_XXAA)

#elif defined (STM32L100xB) || defined (STM32L100xBA) || defined (STM32L100xC) || \
    defined (STM32L151xB) || defined (STM32L151xBA) || defined (STM32L151xC) || defined (STM32L151xCA) || defined (STM32L151xD) || defined (STM32L151xDX) || defined (STM32L151xE) || \
    defined (STM32L152xB) || defined (STM32L152xBA) || defined (STM32L152xC) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L152xDX) || defined (STM32L152xE) || \
    defined (STM32L162xC) || defined (STM32L162xCA) || defined (STM32L162xD) || defined (STM32L162xDX) || defined (STM32L162xE)

#define STM32L1
#define DEFAULT_CLOCK_SPEED 8000000

#elif defined(STM32F030xC)

#define STM32F0
#define DEFAULT_CLOCK_SPEED 8000000
#define YSS__CORE_CM0_H_GENERIC

#else

#define ERROR_MCU_NOT_ABLE

#endif

#endif