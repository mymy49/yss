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

#ifndef YSS_DRV_QUADSPI_ST_TYPE_A_DEFINE__H_
#define YSS_DRV_QUADSPI_ST_TYPE_A_DEFINE__H_

#if defined(STM32F746xx) || defined(STM32F745xx) || \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx)

namespace define
{
namespace quadspi
{
namespace flashSize
{
enum
{
    B2 = 0,
    B4 = 1,
    B8 = 2,
    B16 = 3,
    B32 = 4,
    B64 = 5,
    B128 = 6,
    B256 = 7,
    B512 = 8,
    KB1 = 9,
    KB2 = 10,
    KB4 = 11,
    KB8 = 12,
    KB16 = 13,
    KB32 = 14,
    KB64 = 15,
    KB128 = 16,
    KB256 = 17,
    KB512 = 18,
    MB1 = 19,
    MB2 = 20,
    MB4 = 21,
    MB8 = 22,
    MB16 = 23,
    MB32 = 24,
    MB64 = 25,
    MB128 = 26,
    MB256 = 27,
    MB512 = 28,
    GB1 = 29,
    GB2 = 30,
    GB4 = 31
};
}

namespace clockMode
{
enum
{
    MODE0 = false,
    MODE3 = true,
};
}

namespace pmm
{
enum
{
    AND = false,
    OR = true
};
}

namespace flash
{
enum
{
    FLASH1 = 0,
    FLASH2 = 1
};
}

namespace mode
{
enum
{
    NO = 0,
    SINGLE = 1,
    DOUBLE = 2,
    QUAD = 3,
};
}

namespace size
{
enum
{
    BIT8 = 0,
    BIT16 = 1,
    BIT24 = 2,
    BIT32 = 3,
};
}

}
}

#endif

#endif