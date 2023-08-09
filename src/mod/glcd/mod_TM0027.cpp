////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI

#include <mod/glcd/TM0027.h>
#include <string.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

#define CMD false
#define DATA true

namespace mod
{
namespace glcd
{
const Spi::Specification gLcdConfig =
{
	define::spi::mode::MODE3,
	10000000,
	define::spi::bit::BIT8
};

TM0027::TM0027(void)
{
	mCs.port = 0;
	mA0.port = 0;
	mRst.port = 0;
	mPeri = 0;
	setSize(128, 64);
}

bool TM0027::initialize(Spi &spi, Gpio::Pin &cs, Gpio::Pin &A0, Gpio::Pin &rst)
{
	mPeri = &spi;
	mCs = cs;
	mA0 = A0;
	mRst = rst;

	mCs.port->setOutput(mCs.pin, true);
	if (mRst.port)
		mRst.port->setOutput(mRst.pin, false);
	thread::delay(100);
	if (mRst.port)
		mRst.port->setOutput(mRst.pin, true);
	thread::delay(100);

	sendCmd(0xaf);
	thread::delay(10);
	sendCmd(0xa4);
	thread::delay(10);
	sendCmd(0xa0);
	thread::delay(10);
	sendCmd(0xc0);
	thread::delay(10);
	sendCmd(0x24);
	thread::delay(10);
	sendCmd(0x81);
	thread::delay(10);
	sendCmd(0x27);
	thread::delay(10);
	sendCmd(0x2f);

	return true;
}

void TM0027::sendCmd(uint8_t cmd)
{
	mPeri->lock();
	mA0.port->setOutput(mA0.pin, CMD);
	mPeri->setSpecification(gLcdConfig);
	mPeri->enable(true);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->send(cmd);
	mCs.port->setOutput(mCs.pin, true);
	//    mPeri->enable(false);
	mPeri->unlock();
}

void TM0027::sendData(void *data, uint32_t size)
{
	mPeri->lock();
	mA0.port->setOutput(mA0.pin, DATA);
	mPeri->setSpecification(gLcdConfig);
	mPeri->enable(true);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->send(data, size);
	mCs.port->setOutput(mCs.pin, true);
	//    mPeri->enable(false);
	mPeri->unlock();
}

void TM0027::clear(void)
{
	memset(mFrameBuffer, 0x00, 128 * 64 / 8);
}

void TM0027::fill(void)
{
	memset(mFrameBuffer, 0xff, 128 * 64 / 8);
}

void TM0027::refresh(void)
{
	uint8_t *des = mFrameBuffer;

	for (int32_t  i = 0; i < 8; i++)
	{
		sendCmd(0x40);     // Display start line set
		sendCmd(0xb0 | i); // Page address set
		sendCmd(0x10);     // Column address set upper bit
		sendCmd(0x00);     // Column address set lower bit

		sendData(des, 128);
		des += 128;
//		thread::delay(5);
	}
}

void TM0027::drawDot(uint16_t x, uint16_t y, bool data)
{
	if (x < 128 && y < 64)
	{
		x = 127 - x;
		if (data)
			mFrameBuffer[y / 8 * 128 + x] |= 1 << (y % 8);
		else
			mFrameBuffer[y / 8 * 128 + x] &= ~(1 << (y % 8));
	}
}
}
}

#endif

#endif

