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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.12.06 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <string.h>
#include <yss/yss.h>

#include <dev/led.h>

void thread_led(void)
{
	while(1)
	{
		Led::setRgb(255, 0, 0);
		thread::delay(333);

		Led::setRgb(0, 255, 0);
		thread::delay(333);

		Led::setRgb(0, 0, 255);
		thread::delay(333);
	}
}

int main(void)
{
	yss::init();

	using namespace define::gpio;

	//UART1 Init
	gpioA.setAsAltFunc(9, altfunc::PA9_USART1_TX, ospeed::LOW, otype::PUSH_PULL);
	gpioA.setAsAltFunc(10, altfunc::PA10_USART1_RX, ospeed::LOW, otype::PUSH_PULL);

	uart1.setClockEn(true);
	uart1.setIntEn(true);
	uart1.init(9600, 256);
	uart1.setIntEn(true);

	Led::init();

	thread::add(thread_led, 128);

	while (1)
	{
		thread::yield();
	}
	return 0;
}