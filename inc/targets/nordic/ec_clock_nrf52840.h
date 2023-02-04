////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CLOCK_EC_NORDIC_NRF52840__H_
#define YSS_DRV_CLOCK_EC_NORDIC_NRF52840__H_

namespace ec
{
namespace clock
{
namespace sysclk
{
enum
{
	MAX_FREQ = 108000000,
};
}

namespace apb1
{
enum
{
	MAX_FREQ = 56000000,
};
}

namespace apb2
{
enum
{
	MAX_FREQ = 108000000,
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
	FREQ = 8000000,
};
}

namespace hse
{
enum
{
	HSE_FREQ = 32000000,
};
}

namespace pll
{
enum
{
	PLL_IN_MIN_FREQ = 1000000,
	PLL_IN_MAX_FREQ = 25000000,
	PLL_OUT_MIN_FREQ = 16000000,
	PLL_OUT_MAX_FREQ = 108000000,
	PLL_SRC_MAX = 1,
	PLL_MUL_MAX = 27,
	PLL_XTPRE_MAX = 1
};
}
}
}

#endif