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

#include <__cross_studio_io.h>
#include <string.h>
#include <util/ElapsedTime.h>
#include <yss/yss.h>

int gId;
ElapsedTime gElapsedTime;
unsigned int gSpendTimeMin = 999999999, gSpendTimeMax = 0;

void isr_timer2(void)
{
    trigger::run(gId);
}

void trigger_timer2(void)
{
    gElapsedTime.reset();

    char data[10];
    char addr[2];
    int spendTime;

    memset(data, 0, 10);
    memset(addr, 0, 2);

    i2c2.send(0xA0, addr, 2, 10000000);
    i2c2.receive(0xA0, data, 4, 10000000);
    i2c2.stop();

    i2c2.send(0xA0, addr, 2, 1000);
    i2c2.receive(0xA0, data, 4, 1000);
    i2c2.stop();

    spendTime = gElapsedTime.getUsec();

    if (spendTime < gSpendTimeMin)
        gSpendTimeMin = spendTime;
    else if (spendTime > gSpendTimeMax)
        gSpendTimeMax = spendTime;
}

int main(int argc, char *argv[])
{
    yss::init();

    using namespace define::gpio;

    gId = trigger::add(trigger_timer2, 1024);

    // I2C2 init
    gpioB.setAsAltFunc(10, define::gpio::altfunc::PB10_I2C2_SCL, define::gpio::ospeed::LOW, define::gpio::otype::OPEN_DRAIN);
    gpioB.setAsAltFunc(11, define::gpio::altfunc::PB11_I2C2_SDA, define::gpio::ospeed::LOW, define::gpio::otype::OPEN_DRAIN);
    i2c2.setClockEn(true);
    i2c2.init(define::i2c::speed::STANDARD);
    i2c2.setIntEn(true);

    // Timer2 init
    timer2.setClockEn(true);
    timer2.init(500);
    timer2.setUpdateIsr(isr_timer2);
    timer2.setUpdateIntEn(true);
    timer2.setIntEn(true);
    timer2.start();

    while (1)
    {
        thread::yield();
    }
    return 0;
}