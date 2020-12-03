////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CLOCK_ST_TYPE_B_EC__H_
#define YSS_DRV_CLOCK_ST_TYPE_B_EC__H_

#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

namespace ec
{
namespace clock
{
namespace sysclk
{
enum
{
    MAX_FREQ = 72000000,
};
}

namespace apb1
{
enum
{
    MAX_FREQ = 36000000,
};
}

namespace apb2
{
enum
{
    MAX_FREQ = 72000000,
};
}

namespace adc
{
enum
{
    MAX_FREQ = 14000000,
};
}

namespace hsi
{
enum
{
    FREQ = 16000000,
};
}

namespace hse
{
enum
{
    HSE_MIN_FREQ = 1000000,
    HSE_MAX_FREQ = 25000000,
};
}

namespace pll
{
enum
{
	VCO_MAX_FREQ = 96000000,
    PLL_IN_MIN_FREQ = 2000000,
    PLL_IN_MAX_FREQ = 24000000,
    PLL_OUT_MIN_FREQ = 2000000,
    PLL_OUT_MAX_FREQ = 32000000,
    PLL_SRC_MAX = 1,
    PLL_MUL_MAX = 8,
    PLL_DIV_MIN = 1,
    PLL_DIV_MAX = 3
};
}

namespace saiPll
{
enum
{
    VCO_MIN_FREQ = 100000000,
    VCO_MAX_FREQ = 432000000,
    USB48_MAX_FREQ = 75000000,
    SAI_PLL_MAX_FREQ = 216000000,
    SAI_MAX_FREQ = 2100000,
    LCD_PLL_MAX_FREQ = 216000000,
    LCD_MAX_FREQ = 45000000,
    PLL_N_MIN = 2,
    PLL_N_MAX = 432,
    PLL_P_MAX = 3,
    PLL_Q_MIN = 2,
    PLL_Q_MAX = 15,
    SAI_Q_MAX = 31,
    PLL_R_MIN = 2,
    PLL_R_MAX = 7,
    LCD_R_MAX = 3
};
}
}
}
#endif

#endif