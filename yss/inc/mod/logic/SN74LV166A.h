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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.02.12 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MOD_LOGIC_SN74LV166A__H_
#define YSS_MOD_LOGIC_SN74LV166A__H_

#include <yss/instance.h>

#if !defined(SPI_NOT_DEFINED)

namespace mod
{
namespace logic
{

class SN74LV166A
{
    drv::Spi *mPeri;
    config::gpio::Set mShLd, mClkInh, mClr;
    unsigned char mDepth;
    unsigned char *mData;

    void reset(void);
    void setShLd(bool en);
    void setClkInh(bool en);
    void setClr(bool en);

  public:
    SN74LV166A(void);
    bool init(drv::Spi &spi, unsigned char depth, config::gpio::Set &clkInh, config::gpio::Set &shLd, config::gpio::Set &clr);
    bool refresh(void);
    unsigned char get(unsigned char index);
};
}
}

#endif

#endif