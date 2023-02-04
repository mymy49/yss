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

#ifndef YSS_DRV_CLOCK_EC_GD_GD32F4__H_
#define YSS_DRV_CLOCK_EC_GD_GD32F4__H_

namespace ec
{
namespace clock
{
namespace sysclk
{
enum
{
	MAX_FREQ = 240000000,
};
}

namespace apb1
{
enum
{
	MAX_FREQ = 60000000,
};
}

namespace apb2
{
enum
{
	MAX_FREQ = 120000000,
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
	HSE_MIN_FREQ = 3000000,
	HSE_MAX_FREQ = 32000000,
};
}

#define PLL_P_USE
#define PLL_Q_USE
namespace pll
{
enum
{
	VCO_MIN_FREQ = 100000000,
	VCO_MAX_FREQ = 500000000,
	P_MAX_FREQ = 344000000,
	Q_MAX_FREQ = 75000000,
	M_MIN = 2,
	M_MAX = 63,
	N_MIN = 2,
	N_MAX = 500,
	P_MAX = 3,
	Q_MIN = 2,
	Q_MAX = 15
};
}

#define SAIPLL_P_USE
#define SAIPLL_R_USE
namespace saipll
{
enum
{
	VCO_MIN_FREQ = 96000000,
	VCO_MAX_FREQ = 500000000,
	P_MAX_FREQ = 75000000,
	R_MAX_FREQ = 42000000,
	N_MIN = 2,
	N_MAX = 500,
	P_MAX = 3,
	Q_MIN = 2,
	Q_MAX = 15,
	R_MIN = 2,
	R_MAX = 7
};
}

namespace i2spll
{
enum
{
	VCO_MIN_FREQ = 100000000,
	VCO_MAX_FREQ = 500000000,
	I2S_MAX_FREQ = 240000000,
	N_MIN = 2,
	N_MAX = 500,
	R_MIN = 2,
	R_MAX = 7
};
}

}
}

#endif