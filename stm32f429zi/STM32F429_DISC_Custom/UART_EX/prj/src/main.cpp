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
#include <yss/yss.h>
#include <bsp.h>

Bmp565Brush gBrush(100 * 100);

void thread_uart1Rx(void)
{
    unsigned char data;
    while (1)
    {
        data = uart1.getWaitUntilReceive();
        debug_printf("0x%02x\n", data);
    }
}

int main(void)
{
    yss::init();
	bsp::init();

    using namespace bsp;
		
	lcd2.setBgColor(0, 255, 0);
	lcd2.clear();
	thread::delay(500);

	lcd2.setBgColor(255, 0, 0);
	lcd2.clear();
	thread::delay(500);

	lcd2.setBgColor(0, 0, 255);
	lcd2.clear();
	thread::delay(500);

	gBrush.setSize(240, 40);
	gBrush.setBgColor(255, 255, 255);
	gBrush.setColor(255, 0, 0);
	gBrush.clear();
	gBrush.drawLine(Pos{0, 0}, Pos{239, 39});
	lcd2.drawBmp(Pos{0, 0}, gBrush.getBmp565());
	lcd2.drawBmp(Pos{0, 40}, gBrush.getBmp565());
	lcd2.drawBmp(Pos{0, 80}, gBrush.getBmp565());
	lcd2.drawBmp(Pos{0, 120}, gBrush.getBmp565());
	lcd2.drawBmp(Pos{0, 160}, gBrush.getBmp565());
	lcd2.drawBmp(Pos{0, 200}, gBrush.getBmp565());
	lcd2.drawBmp(Pos{0, 240}, gBrush.getBmp565());
	lcd2.drawBmp(Pos{0, 280}, gBrush.getBmp565());

    while (1)
    {
		thread::yield();
    }
    return 0;
}
