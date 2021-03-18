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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CLOCK_ST_TYPE_D_EC__H_
#define YSS_DRV_CLOCK_ST_TYPE_D_EC__H_

#if defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

namespace ec
{
namespace clock
{
namespace sysclk
{
enum
{
    RANGE1_NORMAL_MAX_FREQ = 150000000,
    RANGE1_BOOST_MAX_FREQ = 170000000,
    RANGE2_MAX_FREQ = 26000000,
};
}

namespace apb1
{
enum
{
    RANGE1_NORMAL_MAX_FREQ = 150000000,
    RANGE1_BOOST_MAX_FREQ = 170000000,
    RANGE2_MAX_FREQ = 26000000,
};
}

namespace apb2
{
enum
{
    RANGE1_NORMAL_MAX_FREQ = 150000000,
    RANGE1_BOOST_MAX_FREQ = 170000000,
    RANGE2_MAX_FREQ = 26000000,
};
}

namespace hsi
{
enum
{
    FREQ = 16000000,
};
}

namespace lsi
{
enum
{
    FREQ = 32000,
};
}

namespace hse
{
enum
{
    HSE_MIN_FREQ = 1000000,
    HSE_MAX_FREQ = 50000000,
};
}

namespace pll
{
enum
{
    RANGE1_NORMAL_VCO_MIN_FREQ = 96000000,
    RANGE1_NORMAL_VCO_MAX_FREQ = 344000000,
    RANGE1_BOOST_VCO_MIN_FREQ = 96000000,
    RANGE1_BOOST_VCO_MAX_FREQ = 344000000,
    RANGE2_VCO_MIN_FREQ = 96000000,
    RANGE2_VCO_MAX_FREQ = 128000000,
    RANGE1_NORMAL_PLLP_MIN_FREQ = 2064500,
    RANGE1_NORMAL_PLLP_MAX_FREQ = 150000000,
    RANGE1_BOOST_PLLP_MIN_FREQ = 2064500,
    RANGE1_BOOST_PLLP_MAX_FREQ = 170000000,
    RANGE2_PLLP_MIN_FREQ = 2064500,
    RANGE2_PLLP_MAX_FREQ = 26000000,
    RANGE1_NORMAL_PLLQ_MIN_FREQ = 8000000,
    RANGE1_NORMAL_PLLQ_MAX_FREQ = 150000000,
    RANGE1_BOOST_PLLQ_MIN_FREQ = 8000000,
    RANGE1_BOOST_PLLQ_MAX_FREQ = 170000000,
    RANGE2_PLLQ_MIN_FREQ = 8000000,
    RANGE2_PLLQ_MAX_FREQ = 26000000,
    RANGE1_NORMAL_PLLR_MIN_FREQ = 8000000,
    RANGE1_NORMAL_PLLR_MAX_FREQ = 150000000,
    RANGE1_BOOST_PLLR_MIN_FREQ = 8000000,
    RANGE1_BOOST_PLLR_MAX_FREQ = 170000000,
    RANGE2_PLLR_MIN_FREQ = 8000000,
    RANGE2_PLLR_MAX_FREQ = 26000000,
    USB48_MAX_FREQ = 75000000,
    VCO_IN_MIN_FREQ = 2660000,
    VCO_IN_MAX_FREQ = 16000000,
    M_MIN = 0,
    M_MAX = 15,
    N_MIN = 8,
    N_MAX = 127,
    P_MIN = 2,
    P_MAX = 31,
    Q_R_MAX = 3,
};
}

namespace saipll
{
enum
{
    VCO_MIN_FREQ = 100000000,
    VCO_MAX_FREQ = 432000000,
    SAI_MAX_FREQ = 216000000,
    LCD_MAX_FREQ = 42000000,
    N_MIN = 2,
    N_MAX = 432,
    Q_MIN = 2,
    Q_MAX = 15,
    R_MIN = 2,
    R_MAX = 7
};
}

}
}
#endif

#endif