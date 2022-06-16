////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <nrf52840.h>
#include <nrf52840_peripherals.h>
#include <util/Period.h>
#include <yss/yss.h>

void init(void);
void thread_handleLed1(void);
void thread_handleLed2(void);
void thread_handleLed3(void);
void thread_handleLed4(void);

int main(void)
{
	yss::init();
	init();

	thread::add(thread_handleLed1, 512);
	thread::add(thread_handleLed2, 512);
	thread::add(thread_handleLed3, 512);
	thread::add(thread_handleLed4, 512);
	
	while(1)
	return 0;
}

void thread_handleLed1(void)
{
	Period period(250000);

	while(1)
	{
		period.wait();
		gpioA.setOutput(13, true);

		period.wait();
		gpioA.setOutput(13, false);
	}
}

void thread_handleLed2(void)
{
	Period period(250000);

	while(1)
	{
		period.wait();
		gpioA.setOutput(13, true);

		period.wait();
		gpioA.setOutput(13, false);
	}
}

void thread_handleLed3(void)
{
	Period period(250000);

	while(1)
	{
		period.wait();
		gpioA.setOutput(13, true);

		period.wait();
		gpioA.setOutput(13, false);
	}
}

void thread_handleLed4(void)
{
	Period period(250000);

	while(1)
	{
		period.wait();
		gpioA.setOutput(13, true);

		period.wait();
		gpioA.setOutput(13, false);
	}
}

void init(void)
{
	// UART0 초기화
	using namespace define::gpio::altfunc;
	gpioA.setAsAltFunc(8, UART0_RXD);
	gpioA.setAsAltFunc(6, UART0_TXD);
	gpioA.setAsAltFunc(5, UART0_RTS);
	gpioA.setAsAltFunc(7, UART0_CTS);

	// LED 초기화
	gpioA.setAsOutput(13);
	gpioA.setAsOutput(14);
	gpioA.setAsOutput(15);
	gpioA.setAsOutput(16);
	
	gpioA.setOutput(13, true);
	gpioA.setOutput(14, true);
	gpioA.setOutput(15, true);
	gpioA.setOutput(16, true);
}

