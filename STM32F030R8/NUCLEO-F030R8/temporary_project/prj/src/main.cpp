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
//  주담당자 : 아이구 (mymy49@nate.com) 2019.12.22 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <string.h>
#include <util/ElapsedTime.h>
#include <util/time.h>
#include <yss/yss.h>

unsigned char gUart2RcvBuff[256];
unsigned char gI2c1RcvBuff[32];

int main(void)
{
    signed short rcvData;

    // 이순신 os 초기화
    yss::init();

    //UART 초기화 9600 baudrate, 수신 링버퍼 크기는 256 바이트
    using namespace define::gpio;
    gpioA.setAsAltFunc(2, altfunc::PA2_USART2_TX);
    gpioA.setAsAltFunc(3, altfunc::PA3_USART2_RX);

    //uart2.setClockEn(true);
    //uart2.init(9600, gUart2RcvBuff, 256);
    //uart2.setIntEn(true);

	// I2C1 초기화
	i2c1.setClockEn(true);
	i2c1.initAsSlave(gI2c1RcvBuff, 32, 0xA8);


    const char *str = "hello world!!\n\r";

    while (1)
    {
        // uart2로 str 전송
        uart2.send(str, strlen(str), 1000);

        // 수신 데이터가 없을 경우 -1을 반환
        rcvData = uart2.get();
        if (rcvData >= 0)
        {
            debug_printf("input = 0x%02x[%c]\n", rcvData, rcvData);
        }
    }
    return 0;
}