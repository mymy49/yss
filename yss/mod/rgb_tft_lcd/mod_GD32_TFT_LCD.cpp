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

#include <drv/mcu.h>

#if defined(LTDC) || defined(TLI)

#include <mod/rgb_tft_lcd/GD32_RGB_LCD.h>
#include <yss/stdlib.h>

static const drv::Ltdc::Specification gLtdcSpec =
	{
		320,                         // width
		480,                         // height
		10,                           // hsyncWidth
		2,                           // vsyncWidth
		30,                           // hbp
		2,                           // vbp
		5,                           // hfp
		4,                           // vfp
		define::ltdc::format::RGB565 // pixelFormat
};

GD32_RGB_LCD::GD32_RGB_LCD(void)
{
}

error GD32_RGB_LCD::init(void)
{
	if(mRstPin.port)
	{
		mRstPin.port->setOutput(mRstPin.pin, false);
		thread::delay(100);
		mRstPin.port->setOutput(mRstPin.pin, true);
	}
	else
		sendCmd(SOFTWARE_RESET);

	thread::delay(100);
	
	const unsigned char pgamma[] = {0xE0, 0x00, 0x10, 0x14, 0x03, 0x0E, 0x04, 0x36, 0x56, 0x4B, 0x04, 0x0C, 0x0A, 0x30, 0x34, 0x0F};
	sendCmd(POS_GAMMA, (void*)pgamma, sizeof(pgamma));

	const unsigned char ngamma[] = {0xE1, 0x00, 0x0E, 0x13, 0x03, 0x10, 0x06, 0x3E, 0x34, 0x55, 0x05, 0x0F, 0x0E, 0x3A, 0x3E, 0x0F};
	sendCmd(NEG_GAMMA, (void*)ngamma, sizeof(ngamma));

	const unsigned char powerCon1[] = {0x0F, 0x0C};
	sendCmd(POWER_CTRL1, (void*)powerCon1, sizeof(powerCon1));

	const unsigned char powerCon2[] = {0x41};
	sendCmd(POWER_CTRL2, (void*)powerCon2, sizeof(powerCon2));

	const unsigned char powerCon3[] = {0x00, 0x21, 0x80};
	sendCmd(VCOM_CTRL1, (void*)powerCon3, sizeof(powerCon3));

	const unsigned char pixelWidth[] = {0x00, 0x00, 320 >> 8, 320 & 0xFF};
	sendCmd(COLUMN_ADDRESS_SET, (void*)pixelWidth, sizeof(pixelWidth));

	const unsigned char pixelHeight[] = {0x00, 0x00, 480 >> 8, 480 & 0xFF};
	sendCmd(PAGE_ADDRESS_SET, (void*)pixelHeight, sizeof(pixelHeight));

	const unsigned char memoryAcess[] = {0x48};
	sendCmd(MEMORY_ACCESS_CONTROL, (void*)memoryAcess, sizeof(memoryAcess));

	const unsigned char format[] = {0x55};
	sendCmd(COLMOD_PIXEL_FORMAT_SET, (void*)format, sizeof(format));

	const unsigned char interface[] = {0x00};
	sendCmd(INTERFACE_MODE_CTRL, (void*)interface, sizeof(interface));

	const unsigned char frameRate[] = {0xA0};
	sendCmd(FRAME_RATE, (void*)frameRate, sizeof(frameRate));

	const unsigned char displayCon1[] = {0x02};
	sendCmd(DISPLAY_INVERSION_CTRL, (void*)displayCon1, sizeof(displayCon1));

	const unsigned char displayCon2[] = {0x22, 0x02};
	sendCmd(DISPLAY_CTRL, (void*)displayCon2, sizeof(displayCon2));

	const unsigned char image[] = {0x00};
	sendCmd(SET_IMAGE_FUNC, (void*)image, sizeof(image));

	const unsigned char adjust[] = {0xF7, 0xA9, 0x51, 0x2C, 0x82};
	sendCmd(ADJUST_CTRL3, (void*)adjust, sizeof(adjust));

	sendCmd(DISP_INVERSION_ON);

	sendCmd(SLEEP_OUT);

	thread::delay(120);

	sendCmd(DISPLAY_ON);

	return Error::NONE;
}

void GD32_RGB_LCD::setConfig(const Config &config)
{
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;
	mSckPin = config.sck;
	mMosiPin = config.mosi;
}

void GD32_RGB_LCD::sendCmd(unsigned char cmd)
{
	mCsPin.port->setOutput(mCsPin.pin, false);
	mMosiPin.port->setOutput(mMosiPin.pin, false);
	mSckPin.port->setOutput(mSckPin.pin, false);
	mSckPin.port->setOutput(mSckPin.pin, true);
	for(int i=0;i<8;i++)
	{
		if(cmd & 0x80)
			mMosiPin.port->setOutput(mMosiPin.pin, true);
		else
			mMosiPin.port->setOutput(mMosiPin.pin, false);
		mSckPin.port->setOutput(mSckPin.pin, false);
		mSckPin.port->setOutput(mSckPin.pin, true);
		cmd <<= 1;
	}
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void GD32_RGB_LCD::sendData(unsigned char data)
{
	mCsPin.port->setOutput(mCsPin.pin, false);
	mMosiPin.port->setOutput(mMosiPin.pin, true);
	mSckPin.port->setOutput(mSckPin.pin, false);
	mSckPin.port->setOutput(mSckPin.pin, true);
	for(int i=0;i<8;i++)
	{
		if(data & 0x80)
			mMosiPin.port->setOutput(mMosiPin.pin, true);
		else
			mMosiPin.port->setOutput(mMosiPin.pin, false);
		mSckPin.port->setOutput(mSckPin.pin, false);
		mSckPin.port->setOutput(mSckPin.pin, true);
		data <<= 1;
	}
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void GD32_RGB_LCD::sendCmd(unsigned char cmd, void *data, unsigned short len)
{
	unsigned char *src = (unsigned char *)data;
	sendCmd(cmd);
	for(int i=0;i<len;i++)
	{
		sendData(src[i]);
	}
}

void GD32_RGB_LCD::enable(void)
{
}

void GD32_RGB_LCD::disable(void)
{
}

const drv::Ltdc::Specification* GD32_RGB_LCD::getSpecification(void)
{
	return &gLtdcSpec;
}

#endif