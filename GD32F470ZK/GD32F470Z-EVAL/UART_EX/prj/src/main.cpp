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

#include <__cross_studio_io.h>
#include <string.h>
#include <yss/yss.h>
#include <util/time.h>
#include <util/Period.h>

void init(void);
void thread_handleLed1(void);
void thread_handleLed2(void);
void thread_handleLed3(void);

void thread_uart1Rx(void)
{
	unsigned char data;
	while (1)
	{
//		data = uart1.getWaitUntilReceive();
		debug_printf("0x%02x\n", data);
	}
}

int main(void)
{
	yss::init();
	init();

	TIMER1;

//	thread::add(thread_uart1Rx, 1024);
	thread::add(thread_handleLed1, 1024);
	thread::add(thread_handleLed2, 1024);
	thread::add(thread_handleLed3, 1024);

	const char *str = "hello world!!\n\r";

	while (1)
	{
		debug_printf("%d\r", time::getRunningMsec());
		uart0.send(str, strlen(str));
	}
	return 0;
}

void init(void)
{
	using namespace define::gpio;

	//UART 초기화 9600 baudrate, 수신 링버퍼 크기는 512 바이트
	gpioA.setAsAltFunc(9, altfunc::PA9_USART0_TX);
	gpioA.setAsAltFunc(10, altfunc::PA10_USART0_RX);
	
	uart0.setClockEn(true);
	uart0.init(9600, 512);
	uart0.setInterruptEn(true);

	// LED 초기화
	gpioD.setAsOutput(4);
	gpioD.setAsOutput(5);
	gpioG.setAsOutput(3);
}

void thread_handleLed1(void)
{
	Period period(250000);
	
	while(1)
	{
		period.wait();
		gpioD.setOutput(4, true);

		period.wait();
		gpioD.setOutput(4, false);
	}
}

void thread_handleLed2(void)
{
	Period period(500000);
	
	while(1)
	{
		period.wait();
		gpioD.setOutput(5, true);

		period.wait();
		gpioD.setOutput(5, false);
	}
}

void thread_handleLed3(void)
{
	Period period(1000000);
	
	while(1)
	{
		period.wait();
		gpioG.setOutput(3, true);

		period.wait();
		gpioG.setOutput(3, false);
	}
}
