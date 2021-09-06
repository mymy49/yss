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
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2020.08.26 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MOD_ADC_ADC121C021__H_
#define YSS_MOD_ADC_ADC121C021__H_

#include <yss/instance.h>

namespace mod
{
namespace adc
{
class ADC121C021
{
    drv::I2c *mPeri;
    unsigned char mConfigReg;
    bool mInitFlag;

    void sendResistor(unsigned char addr, unsigned char data);

  public:
    struct Config
    {
        drv::I2c &peri;
    };

    enum // setConversionTime(cycleTime)
    {
        CYCLE_TIME_0_KSPS = 0,
        CYCLE_TIME_27_KSPS = 1,
        CYCLE_TIME_13_5_KSPS = 2,
        CYCLE_TIME_6_7_KSPS = 3,
        CYCLE_TIME_3_4_KSPS = 4,
        CYCLE_TIME_1_7_KSPS = 5,
        CYCLE_TIME_0_9_KSPS = 6,
        CYCLE_TIME_0_4_KSPS = 7
    };

    ADC121C021(void);
    bool init(const Config config);
    void setConversionTime(unsigned char cycleTime);
    unsigned short getResult(void);
    void setAddr(unsigned char addr);
};
}
}

#endif