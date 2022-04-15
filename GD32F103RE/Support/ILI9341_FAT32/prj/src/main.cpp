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

#include <yss/yss.h>
#include "board.h"

void init(void);
void test(void);

int main(void)
{
	CanFrame rcvBuf;

	yss::init();
	init();

	test();

	while (true)
	{
		while(can1.isReceived())
		{
			rcvBuf = can1.getPacket();

			switch(rcvBuf.id)
			{
			case 0x1234 :
				debug_printf("0x1234!!\n");
				break;

			case 0x2345 :
				debug_printf("0x2345!!\n");
				break;
			}

			can1.releaseFifo();
		}
		thread::yield();
	}

	return 0;
}

void init(void)
{
	using namespace define::gpio;
	
	// SPI1 초기화
	gpioA.setAsAltFunc(5, altfunc::PA5_SPI1_SCK, ospeed::FAST);
	gpioA.setAsAltFunc(6, altfunc::PA6_SPI1_MISO, ospeed::FAST);
	gpioA.setAsAltFunc(7, altfunc::PA7_SPI1_MOSI, ospeed::FAST);
	gpioC.setAsOutput(0, ospeed::FAST);
	gpioC.setAsOutput(1, ospeed::FAST);
	
	spi1.setClockEn(true);
	spi1.init();
	spi1.setInterruptEn(true);
	
	// ILI9341 초기화
	ILI9341::Config lcdConfig
	{
		spi1,				//drv::Spi &peri;
		{240, 320},			//Size displayResolution;
		{&gpioC, 0},		//config::gpio::Set chipSelect;
		{&gpioC, 1},		//config::gpio::Set dataCommand;
		{0, 0},				//config::gpio::Set reset;
		0					//unsigned char madctl;
	};

	lcd.init(lcdConfig);
	lcd.setBgColor(0, 0, 0);
	lcd.clear();

	// I2C2 초기화
	gpioB.setAsAltFunc(10, altfunc::PB10_I2C2_SCL);
	gpioB.setAsAltFunc(11, altfunc::PB11_I2C2_SDA);

	i2c2.setClockEn(true);
	i2c2.init(define::i2c::speed::STANDARD);
	i2c2.setInterruptEn(true);

	// EEPROM 초기화
	CAT24C256::Config eepromConfig
	{
		i2c2,	//drv::I2c &peri;
		{0, 0},	//config::gpio::Set writeProtectPin;
		0		//unsigned char addr;
	};

	eeprom.init(eepromConfig);

	// CAN 초기화
	gpioA.setAsInput(11);	// CAN_RX
	gpioA.setAsAltFunc(12, altfunc::PA12_CAN_TX);
	
	can1.setClockEn(true);
	can1.init(250000, 64);	// 250kbps, 수신 패킷 버퍼 64개
	can1.setExtendedMaskFilter(0, 0, 0); // 필터 전체 수신 설정
	can1.setInterruptEn(true);
}

void test(void)
{
	unsigned int data;
	CanFrame sendBuf = {0,};

	// LCD 테스트
	lcd.lock();
	lcd.setBgColor(255, 0, 0);
	lcd.clear();
	lcd.unlock();
	thread::delay(1000);

	lcd.lock();
	lcd.setBgColor(0, 255, 0);
	lcd.clear();
	lcd.unlock();
	thread::delay(1000);

	lcd.lock();
	lcd.setBgColor(0, 0, 255);
	lcd.clear();
	lcd.unlock();
	thread::delay(1000);

	// EEPROM 테스트
	data = 0x12345678;
	eeprom.write(0, data);
	data = 0;
	eeprom.read(0, data);
	debug_printf("EEPROM[0] = 0x%08X\n", data);
	
	sendBuf.dataLength = 8;
	sendBuf.extension = true;
	sendBuf.id = 0x1234;

	// CAN 테스트
	for(int i=0;i<10;i++)
	{
		can1.lock();
		can1.send(sendBuf);
		can1.unlock();
	}
}
