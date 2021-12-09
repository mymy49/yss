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
#include <mod/wiznet/W5100S.h>
#include <mod/wiznet/WiznetSocket.h>
#include <dev/led.h>

W5100S w5100S;
WiznetSocket socket;

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
	unsigned char buf[6];

	using namespace define::gpio;

	//UART1 Init
	gpioA.setAsAltFunc(9, altfunc::PA9_USART1_TX, ospeed::LOW, otype::PUSH_PULL);
	gpioA.setAsAltFunc(10, altfunc::PA10_USART1_RX, ospeed::LOW, otype::PUSH_PULL);

	uart1.setClockEn(true);
	uart1.setIntEn(true);
	uart1.init(9600, 256);
	uart1.setIntEn(true);
	
	// SPI2 초기화
	gpioB.setAsAltFunc(13, altfunc::PB13_SPI2_SCK);
	gpioB.setAsAltFunc(14, altfunc::PB14_SPI2_MISO);
	gpioB.setAsAltFunc(15, altfunc::PB15_SPI2_MOSI);

	spi2.setClockEn(true);
	spi2.init();
	spi2.setInterruptEn(true);
	
	// W5100S 초기화
	gpioD.setAsOutput(7);
	gpioD.setAsOutput(8);
	gpioD.setAsOutput(9);

	W5100S::Config w5100sConfig =
	{
		spi2, //drv::Spi &peri;
		{&gpioD, 8},				//config::gpio::Set RSTn;
		{&gpioD, 9},				//config::gpio::Set INTn;
		{&gpioD, 7},				//config::gpio::Set CSn;
		true,						//bool PPPoE;
		true,						//bool pingResponse;
		5000,						//unsigned short retransmissionTime;
		8,							//unsigned char retransmissionCount;
		{2048, 2048, 2048, 2048},	//unsigned int txSocketBufferSize[4];
		{2048, 2048, 2048, 2048},	//unsigned int rxSocketBufferSize[4];
	};
	
	w5100S.lock();
	if(w5100S.init(w5100sConfig))
	{
		debug_printf("W5100S initialization Ok!!\n");

		buf[0] = 0x12;
		buf[1] = 0x34;
		buf[2] = 0x56;
		buf[3] = 0x78;
		buf[4] = 0x9A;
		buf[5] = 0xBC;
		w5100S.setMacAddress(buf);

		buf[0] = 192;
		buf[1] = 168;
		buf[2] = 0;
		buf[3] = 1;
		w5100S.setGatewayIpAddress(buf);

		buf[0] = 255;
		buf[1] = 255;
		buf[2] = 255;
		buf[3] = 0;
		w5100S.setSubnetMaskAddress(buf);

		buf[0] = 192;
		buf[1] = 168;
		buf[2] = 0;
		buf[3] = 100;
		w5100S.setIpAddress(buf);
	}
	else
	{
		debug_printf("W5100S initialization Failed!!\n");
		while(1);
	}
	w5100S.unlock();

	
	socket.init(w5100S);

	Led::init();

	thread::add(thread_led, 128);

	while (1)
	{
		thread::yield();
	}
	return 0;
}