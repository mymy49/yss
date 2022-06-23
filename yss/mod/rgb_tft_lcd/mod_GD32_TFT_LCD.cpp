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

#include <mod/rgb_tft_lcd/GD32_RGB_LCD.h>
#include <yss/stdlib.h>

namespace CMD
{
enum
{
	NOP = 0x00,
	SOFTWARE_RESET = 0x01,
	READ_DISP_ID = 0x04,
	READ_DISP_STATUS = 0x09,
	READ_DISP_MADCTRL = 0x0B,
	READ_DISP_PIXEL_FORMAT = 0x0C,
	READ_DISP_IMAGE_FORMAT = 0x0D,
	READ_DISP_SIGNAL_MODE = 0x0E,
	READ_DISP_SELF_DIAGNOSTIC = 0x0F,
	ENTER_SLEEP_MODE = 0x10,
	SLEEP_OUT = 0x11,
	PARTIAL_MODE_ON = 0x12,
	NORMAL_DISP_MODE_ON = 0x13,
	DISP_INVERSION_OFF = 0x20,
	DISP_INVERSION_ON = 0x21,
	GAMMA_SET = 0x26,
	DISPLAY_OFF = 0x28,
	DISPLAY_ON = 0x29,
	COLUMN_ADDRESS_SET = 0x2A,
	PAGE_ADDRESS_SET = 0x2B,
	MEMORY_WRITE = 0x2C,
	COLOR_SET = 0x2D,
	MEMORY_READ = 0x2E,
	PARTIAL_AREA = 0x30,
	VERT_SCROLL_DEFINITION = 0x33,
	TEARING_EFFECT_LINE_OFF = 0x34,
	TEARING_EFFECT_LINE_ON = 0x35,
	MEMORY_ACCESS_CONTROL = 0x36,
	VERT_SCROLL_START_ADDRESS = 0x37,
	IDLE_MODE_OFF = 0x38,
	IDLE_MODE_ON = 0x39,
	COLMOD_PIXEL_FORMAT_SET = 0x3A,
	WRITE_MEMORY_CONTINUE = 0x3C,
	READ_MEMORY_CONTINUE = 0x3E,
	SET_TEAR_SCANLINE = 0x44,
	GET_SCANLINE = 0x45,
	WRITE_DISPLAY_BRIGHTNESS = 0x51,
	READ_DISPLAY_BRIGHTNESS = 0x52,
	WRITE_CTRL_DISPLAY = 0x53,
	READ_CTRL_DISPLAY = 0x54,
	WRITE_CONTENT_ADAPT_BRIGHTNESS = 0x55,
	READ_CONTENT_ADAPT_BRIGHTNESS = 0x56,
	WRITE_MIN_CAB_LEVEL = 0x5E,
	READ_MIN_CAB_LEVEL = 0x5F,
	FRAME_RATE = 0xb1,
	DISPLAY_CTRL = 0xb6,
	POWER_CTRL1 = 0xc0,
	POWER_CTRL2 = 0xc1,
	VCOM_CTRL1 = 0xc5,
	VCOM_CTRL2 = 0xc7,
	POWER_A = 0xcb,
	POWER_B = 0xcf,
	CMD_READ_ID1 = 0xDA,
	READ_ID2 = 0xDB,
	CMD_READ_ID3 = 0xDC,
	POS_GAMMA = 0xe0,
	NEG_GAMMA = 0xe1,
	DTCA = 0xe8,
	DTCB = 0xea,
	POWER_SEQ = 0xed,
	GAMMA3_FUNC_DIS = 0xf2,
	PRC = 0xf7
};
}

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
		reset();

	thread::delay(100);
	
	const unsigned char pgamma[] = {0xE0, 0x00, 0x10, 0x14, 0x03, 0x0E, 0x04, 0x36, 0x56, 0x4B, 0x04, 0x0C, 0x0A, 0x30, 0x34, 0x0F};
	sendCmd(0xE0, (void*)pgamma, sizeof(pgamma));

	const unsigned char ngamma[] = {0xE1, 0x00, 0x0E, 0x13, 0x03, 0x10, 0x06, 0x3E, 0x34, 0x55, 0x05, 0x0F, 0x0E, 0x3A, 0x3E, 0x0F};
	sendCmd(0xE1, (void*)ngamma, sizeof(ngamma));

	const unsigned char powerCon1[] = {0x0F, 0x0C};
	sendCmd(0xC0, (void*)powerCon1, sizeof(powerCon1));

	const unsigned char powerCon2[] = {0x41};
	sendCmd(0xC1, (void*)powerCon2, sizeof(powerCon2));

	const unsigned char powerCon3[] = {0x00, 0x21, 0x80};
	sendCmd(0xC5, (void*)powerCon3, sizeof(powerCon3));

	const unsigned char pixelWidth[] = {0x00, 0x00, 320 >> 8, 320 & 0xFF};
	sendCmd(0x2A, (void*)pixelWidth, sizeof(pixelWidth));

	const unsigned char pixelHeight[] = {0x00, 0x00, 480 >> 8, 480 & 0xFF};
	sendCmd(0x2B, (void*)pixelHeight, sizeof(pixelHeight));

	const unsigned char memoryAcess[] = {0x48};
	sendCmd(0x36, (void*)memoryAcess, sizeof(memoryAcess));

	const unsigned char format[] = {0x55};
	sendCmd(0x3A, (void*)format, sizeof(format));

	const unsigned char interface[] = {0x00};
	sendCmd(0xB0, (void*)interface, sizeof(interface));

	const unsigned char frameRate[] = {0xA0};
	sendCmd(0xB1, (void*)frameRate, sizeof(frameRate));

	const unsigned char displayCon1[] = {0x02};
	sendCmd(0xB4, (void*)displayCon1, sizeof(displayCon1));

	const unsigned char displayCon2[] = {0x22, 0x02};
	sendCmd(0xB6, (void*)displayCon2, sizeof(displayCon2));

	const unsigned char image[] = {0x00};
	sendCmd(0xE9, (void*)image, sizeof(image));

	const unsigned char adjust[] = {0xF7, 0xA9, 0x51, 0x2C, 0x82};
	sendCmd(0xF7, (void*)adjust, sizeof(adjust));

	sendCmd(0x21);

	sendCmd(0x11);

	thread::delay(120);

	sendCmd(0x29);

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

