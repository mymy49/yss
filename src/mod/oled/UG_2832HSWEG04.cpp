////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI

#include <yss/instance.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

#include <mod/oled/UG_2832HSWEG04.h>
#include <stdlib.h>
#include <string.h>
#include <util/ElapsedTime.h>
#include <std_ext/string.h>

static const Spi::Specification gSpiConfig =
{
	define::spi::mode::MODE1, // 장치1 SPI 모드
	10000000,                  // 장치1 최대 클럭
	define::spi::bit::BIT8
};

#define CMD false
#define DATA true

namespace mod
{
namespace oled
{
const Spi::Specification gLcdConfig =
{
	define::spi::mode::MODE0,
	10000000,
	define::spi::bit::BIT8
};

UG_2832HSWEG04::UG_2832HSWEG04(void)
{
	mCs.port = 0;
	mDc.port = 0;
	mRst.port = 0;
	mPeri = 0;
	setSize(128, 32);
}

bool UG_2832HSWEG04::initialize(Spi &spi, Gpio::Pin &cs, Gpio::Pin &dc, Gpio::Pin &rst)
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

