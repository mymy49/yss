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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.01.20 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <mod/oled/UG_2832HSWEG04.h>
#include <string.h>
#include <util/TimeLapse.h>
#include <yss/yss.h>

#include "../font/Ubuntu_14.h"

mod::oled::UG_2832HSWEG04 oled;

int main(void)
{
    unsigned char rcvData, sendData = 0xAA;

    // 이순신 os 초기화
    yss::init();

    // SPI5 초기화
    gpioB.setToAltFunc(22, define::gpio::altfunc::SERCOM_ALT_D);
    gpioB.setToAltFunc(23, define::gpio::altfunc::SERCOM_ALT_D);
    gpioB.setToAltFunc(16, define::gpio::altfunc::SERCOM_ALT_D);

    spi5.setClockEn(true);
    spi5.setPad(define::spi::txPad::DO2_SCK3_SS1, define::spi::rxPad::DI0);
    spi5.init();
    spi5.setIntEn(true);

    gpioA.setToOutput(27);
    gpioB.setToOutput(17);
    gpioB.setToOutput(30);

    config::gpio::Set oledCs = {&gpioB, 17};
    config::gpio::Set oledRst = {&gpioA, 27};
    config::gpio::Set oledCd = {&gpioB, 30};

    oled.init(spi5, oledCs, oledCd, oledRst);

    oled.clear();
    oled.refresh();
    thread::delay(1000);
    int delay = 1;
    for (int x = 0; x < 128; x++)
    {
        oled.drawLine(Pos{63, 16}, Pos{x, 0}, true);
        oled.refresh();
        thread::delay(delay);
    }

    for (int y = 0; y < 32; y++)
    {
        oled.drawLine(Pos{63, 16}, Pos{127, y}, true);
        oled.refresh();
        thread::delay(delay);
    }

    for (int x = 127; x >= 0; x--)
    {
        oled.drawLine(Pos{63, 16}, Pos{x, 31}, true);
        oled.refresh();
        thread::delay(delay);
    }

    for (int y = 31; y >= 0; y--)
    {
        oled.drawLine(Pos{63, 16}, Pos{0, y}, true);
        oled.refresh();
        thread::delay(delay);
    }

    oled.clear();
    oled.drawRect(Pos{5, 5}, Size{100, 10});
    oled.drawCircle(Pos{50, 15}, 10, true);
    oled.fillRect(Pos{10, 10}, Pos{30, 30});
    oled.refresh();

    thread::delay(1000);

    oled.clear();
    oled.setFont(Font_Ubuntu_14);
    oled.drawString(Pos{0, 0}, "yss os");
    oled.drawString(Pos{0, 15}, "한글 테스트");
    oled.refresh();

    while (1)
        thread::yield();
}