/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <yss/instance.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

#include <mod/oled/UG_2832HSWEG04.h>
#include <stdlib.h>
#include <string.h>
#include <util/ElapsedTime.h>
#include <std_ext/string.h>

static const Spi::specification_t gSpiConfig =
{
	Spi::MODE_MODE1, // 장치1 SPI 모드
	10000000,                  // 장치1 최대 클럭
	Spi::BIT_BIT8
};

#define CMD false
#define DATA true

namespace mod
{
namespace oled
{
const Spi::specification_t gLcdConfig =
{
	Spi::MODE_MODE0,
	10000000,
	Spi::BIT_BIT8
};

UG_2832HSWEG04::UG_2832HSWEG04(void)
{
	mCs.port = 0;
	mDc.port = 0;
	mRst.port = 0;
	mPeri = 0;
	setSize(128, 32);
}

bool UG_2832HSWEG04::initialize(Spi &spi, pin_t &cs, pin_t &dc, pin_t &rst)
{
	mPeri = &spi;
	mCs.port = cs.port;
	mCs.pin = cs.pin;
	mDc.port = dc.port;
	mDc.pin = dc.pin;
	mRst.port = rst.port;
	mRst.pin = rst.pin;

	mCs.port->setOutput(mCs.pin, true);
	if (mRst.port)
		mRst.port->setOutput(mRst.pin, false);
	thread::delay(100);
	if (mRst.port)
		mRst.port->setOutput(mRst.pin, true);

	sendCmd(0x8D);
	sendCmd(0x14);

	sendCmd(0xD9);
	sendCmd(0xF1);

	thread::delay(100);

	sendCmd(0x81);
	sendCmd(0x8F);

	sendCmd(0xA1);
	sendCmd(0xC8);

	sendCmd(0xDA);
	sendCmd(0x20);

	sendCmd(0xAF);

	return true;
}

void UG_2832HSWEG04::sendCmd(uint8_t cmd)
{
	mPeri->lock();
	mDc.port->setOutput(mDc.pin, CMD);
	mPeri->setSpecification(gSpiConfig);
	mPeri->enable(true);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->send(cmd);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();
}

void UG_2832HSWEG04::sendData(void *data, uint32_t size)
{
	mPeri->lock();
	mDc.port->setOutput(mDc.pin, DATA);
	mPeri->setSpecification(gSpiConfig);
	mPeri->enable(true);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->send(data, size);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();
}

void UG_2832HSWEG04::clear(void)
{
	memset(mFrameBuffer, 0x00, 128 * 32 / 8);
}

void UG_2832HSWEG04::fill(void)
{
	memset(mFrameBuffer, 0xff, 128 * 32 / 8);
}

void UG_2832HSWEG04::refresh(void)
{
	uint8_t *des = mFrameBuffer;

	for (int32_t  i = 0; i < 4; i++)
	{
		sendCmd(0x22);
		sendCmd(i);

		sendCmd(0x00);
		sendCmd(0x10);

		sendData(des, 128);
		des += 128;
	}
}

void UG_2832HSWEG04::drawDot(uint16_t x, uint16_t y, bool data)
{
	if (x < 128 && y < 32)
	{
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

