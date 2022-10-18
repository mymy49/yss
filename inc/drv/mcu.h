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

#if defined(STM32F100xB) || defined(STM32F100xE) ||													\
	defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
	defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
	defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
	defined(STM32F105xC) ||                                                                         \
	defined(STM32F107xC) ||																			\
	defined(STM32F10X_MD)

#ifndef STM32F1
#define STM32F1
#define DEFAULT_CLOCK_SPEED 8000000
#endif

#elif defined(STM32F405xx) || defined(STM32F415xx) || \
	defined(STM32F407xx) || defined(STM32F417xx) ||   \
	defined(STM32F427xx) || defined(STM32F437xx) ||   \
	defined(STM32F429xx) || defined(STM32F439xx)

#ifndef STM32F4
#define STM32F4
#endif

#elif defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx)

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

#else

#define ERROR_MCU_NOT_ABLE

#endif

#endif