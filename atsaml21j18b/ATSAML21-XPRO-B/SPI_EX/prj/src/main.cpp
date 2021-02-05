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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.01.20 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <string.h>
#include <yss/yss.h>

config::spi::Config gSpiDevice1 =
    {
        define::spi::mode::MODE0, // 장치1 SPI 모드
        1000000                   // 장치1 최대 클럭
};

config::spi::Config gSpiDevice2 =
    {
        define::spi::mode::MODE2, // 장치2 SPI 모드
        500000                    // 장치1 최대 클럭
};

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

    while (1)
    {
        // 장치1에 1바이트 보내기
        spi5.lock();
        spi5.setConfig(gSpiDevice1);
        spi5.enable(true);
        // CS 선택 코드 추가
        spi5.send(sendData);
        // CS 해제 코드 추가
        spi5.enable(false);
        spi5.unlock();

        // 장치1에 1바이트 보내면서 받기
        spi5.lock();
        spi5.setConfig(gSpiDevice1);
        spi5.enable(true);
        // CS 선택 코드 추가
        rcvData = spi5.exchange(sendData);
        // CS 해제 코드 추가
        spi5.enable(false);
        spi5.unlock();

        // 장치2에 복합적으로 사용하기
        spi5.lock();
        spi5.setConfig(gSpiDevice2);
        spi5.enable(true);
        // CS 선택 코드 추가
        spi5.send(sendData);
        rcvData = spi5.exchange(sendData);
        // CS 해제 코드 추가
        spi5.enable(false);
        spi5.unlock();
    }
    return 0;
}