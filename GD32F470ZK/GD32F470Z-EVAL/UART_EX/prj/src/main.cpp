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
#include <mod/tft/RK043FN48H.h>

void init(void);
void thread_handleLed1(void);
void thread_handleLed2(void);
void thread_handleLed3(void);

RK043FN48H lcd;

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
	init();

	thread::add(thread_uart1Rx, 1024);
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

	// LCD 초기화
	gpioB.setAsAltFunc(0, altfunc::PB0_LCD_R3, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(11, altfunc::PA11_LCD_R4, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(12, altfunc::PA12_LCD_R5, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(8, altfunc::PA8_LCD_R6, ospeed::FAST, otype::PUSH_PULL);
	gpioG.setAsAltFunc(6, altfunc::PG6_LCD_R7, ospeed::FAST, otype::PUSH_PULL);

	gpioA.setAsAltFunc(6, altfunc::PA6_LCD_G2, ospeed::FAST, otype::PUSH_PULL);
	gpioG.setAsAltFunc(10, altfunc::PG10_LCD_G3, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(10, altfunc::PB10_LCD_G4, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(11, altfunc::PB11_LCD_G5, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsAltFunc(7, altfunc::PC7_LCD_G6, ospeed::FAST, otype::PUSH_PULL);
	gpioD.setAsAltFunc(3, altfunc::PD3_LCD_G7, ospeed::FAST, otype::PUSH_PULL);

	gpioG.setAsAltFunc(11, altfunc::PG11_LCD_B3, ospeed::FAST, otype::PUSH_PULL);
	gpioG.setAsAltFunc(12, altfunc::PG12_LCD_B4, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(3, altfunc::PA3_LCD_B5, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(8, altfunc::PB8_LCD_B6, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(9, altfunc::PB9_LCD_B7, ospeed::FAST, otype::PUSH_PULL);

	gpioA.setAsAltFunc(4, altfunc::PA4_LCD_VSYNC, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsAltFunc(6, altfunc::PC6_LCD_HSYNC, ospeed::FAST, otype::PUSH_PULL);
	gpioF.setAsAltFunc(10, altfunc::PF10_LCD_DE, ospeed::FAST, otype::PUSH_PULL);
	gpioG.setAsAltFunc(7, altfunc::PG7_LCD_CLK, ospeed::FAST, otype::PUSH_PULL);
	
	lcd.init();
	ltdc.setClockEn(true);
	ltdc.init(lcd.getSpec());
	ltdc.setInterruptEn(true);
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
