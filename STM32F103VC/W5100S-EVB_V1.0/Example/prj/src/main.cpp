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
#include <mod/wiznet/W5100S.h>
#include <mod/wiznet/WiznetSocket.h>
#include <dev/led.h>

W5100S w5100s;
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
	gpioD.setAsInput(9);

	W5100S::Config w5100sConfig =
	{
		spi2, //drv::Spi &peri;
		{&gpioD, 8},				//config::gpio::Set RSTn;
		{&gpioD, 9},				//config::gpio::Set INTn;
		{&gpioD, 7},				//config::gpio::Set CSn;
		false,						//bool PPPoE;
		false,						//bool pingBlock;
		5000,						//unsigned short retransmissionTime;
		8,							//unsigned char retransmissionCount;
		{							//unsigned int txSocketBufferSize[4];
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB
		},	
		{							//unsigned int rxSocketBufferSize[4];
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB
		},	
	};
	
	w5100s.lock();
	if(w5100s.init(w5100sConfig))
	{
		debug_printf("W5100S initialization Ok!!\n");

		buf[0] = 0x12;
		buf[1] = 0x34;
		buf[2] = 0x56;
		buf[3] = 0x78;
		buf[4] = 0x9A;
		buf[5] = 0xBC;
		w5100s.setMacAddress(buf);

		buf[0] = 192;
		buf[1] = 168;
		buf[2] = 0;
		buf[3] = 1;
		w5100s.setGatewayIpAddress(buf);

		buf[0] = 255;
		buf[1] = 255;
		buf[2] = 255;
		buf[3] = 0;
		w5100s.setSubnetMaskAddress(buf);

		buf[0] = 192;
		buf[1] = 168;
		buf[2] = 0;
		buf[3] = 100;
		w5100s.setIpAddress(buf);
	}
	else
	{
		debug_printf("W5100S initialization Failed!!\n");
		while(1);
	}
	w5100s.unlock();
	
	socket.init(w5100s, 0);

	socket.open(WiznetSocket::TCP, 0);

	buf[0] = 192;
	buf[1] = 168;
	buf[2] = 0;
	buf[3] = 101;
	socket.connect(buf, 1000);

	Led::init();

	thread::add(thread_led, 128);

	while (1)
	{
		thread::yield();
	}
	return 0;
}