/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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
const Spi::specification_t gLcdConfig =
{
	Spi::MODE_MODE3,
	10000000,
	Spi::BIT_BIT8
};

TM0027::TM0027(void)
{
	mCs.port = 0;
	mA0.port = 0;
	mRst.port = 0;
	mPeri = 0;
	setSize(128, 64);
}

bool TM0027::initialize(Spi &spi, pin_t &cs, pin_t &A0, pin_t &rst)
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

