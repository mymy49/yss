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

#include <mod/cputft/ILI9341.h>
#include <stdlib.h>
#include <string.h>
#include <yss/malloc.h>
#include <yss/stdlib.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

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

const Spi::Specification gLcdConfig =
	{
		define::spi::mode::MODE0, //uint8_t mode;
		50000000,                 //uint32_t maxFreq;
		define::spi::bit::BIT8};  //uint8_t bit;

ILI9341::ILI9341(void)
{
	mCs.port = 0;
	mDc.port = 0;
	mRst.port = 0;
	mPeri = 0;
	mLineBuffer = 0;
}

bool ILI9341::init(const Config config)
{
	Brush::setSize(config.displayResolution);

	mLineBuffer = new uint16_t[mSize.width];
	if (mLineBuffer)
		mLineBufferSize = mSize.width * sizeof(uint16_t);

	mPeri = &config.peri;
	mCs = config.chipSelect;
	mDc = config.dataCommand;
	mRst = config.reset;

	if(mRst.port)
		mRst.port->setOutput(mRst.pin, false);
	mCs.port->setOutput(mCs.pin, true);

	thread::delay(300);
	if(mRst.port)
		mRst.port->setOutput(mRst.pin, true);

	mPeri->lock();
	mPeri->setSpecification(gLcdConfig);
	mPeri->enable(true);

	sendCmd(CMD::DISPLAY_OFF);

	const uint8_t powerA[5] = {0x39, 0x2c, 0x00, 0x34, 0x02};
	sendCmd(CMD::POWER_A, (int8_t *)powerA, sizeof(powerA));

	const uint8_t powerB[3] = {0x00, 0xc1, 0x30};
	sendCmd(CMD::POWER_B, (int8_t *)powerB, sizeof(powerB));

	const uint8_t dtca[3] = {0x85, 0x00, 0x78};
	sendCmd(CMD::DTCA, (int8_t *)dtca, sizeof(dtca));

	const uint8_t dtcb[2] = {0x00, 0x00};
	sendCmd(CMD::DTCB, (int8_t *)dtcb, sizeof(dtcb));

	const uint8_t powerSeq[4] = {0x64, 0x03, 0x12, 0x81};
	sendCmd(CMD::POWER_SEQ, (int8_t *)powerSeq, sizeof(powerSeq));

	const uint8_t prc[1] = {0x20};
	sendCmd(CMD::PRC, (int8_t *)prc, sizeof(prc));

	const uint8_t powerCtrl1[1] = {0x23};
	sendCmd(CMD::POWER_CTRL1, (int8_t *)powerCtrl1, sizeof(powerCtrl1));

	const uint8_t powerCtrl2[1] = {0x10};
	sendCmd(CMD::POWER_CTRL2, (int8_t *)powerCtrl2, sizeof(powerCtrl2));

	const uint8_t vcomCtrl1[2] = {0x3e, 0x28};
	sendCmd(CMD::VCOM_CTRL1, (int8_t *)vcomCtrl1, sizeof(vcomCtrl1));

	const uint8_t vcomCtrl2[1] = {0x86};
	sendCmd(CMD::VCOM_CTRL2, (int8_t *)vcomCtrl2, sizeof(vcomCtrl2));

	uint8_t memAccCtrl[1] = {0x08};
	memAccCtrl[0] |= config.madctl;
	sendCmd(CMD::MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));

	const uint8_t fixelFormat[1] = {0x55};
	sendCmd(CMD::COLMOD_PIXEL_FORMAT_SET, (int8_t *)fixelFormat, sizeof(fixelFormat));

	const uint8_t frameRate[2] = {0x00, 0x18};
	sendCmd(CMD::FRAME_RATE, (int8_t *)frameRate, sizeof(frameRate));

	const uint8_t gammaFuncDis[1] = {0x00};
	sendCmd(CMD::GAMMA3_FUNC_DIS, (int8_t *)gammaFuncDis, sizeof(gammaFuncDis));

	const uint8_t gammaSet4[1] = {0x01};
	sendCmd(CMD::GAMMA_SET, (int8_t *)gammaSet4, sizeof(gammaSet4));

	const uint8_t posGamma[15] = {0x0f, 0x31, 0x2b, 0x0c, 0x0e, 0x08, 0x4e, 0xf1, 0x37, 0x07, 0x10, 0x03, 0x0e, 0x09, 0x00};
	sendCmd(CMD::POS_GAMMA, (int8_t *)posGamma, sizeof(posGamma));

	const uint8_t negGamma[15] = {0x00, 0x0e, 0x14, 0x03, 0x11, 0x07, 0x31, 0xc1, 0x48, 0x08, 0x0f, 0x0c, 0x31, 0x36, 0x0f};
	sendCmd(CMD::NEG_GAMMA, (int8_t *)negGamma, sizeof(negGamma));

	const uint8_t displayCtrl[4] = {0x08, 0x82, 0x27};
	sendCmd(CMD::DISPLAY_CTRL, (int8_t *)displayCtrl, sizeof(displayCtrl));

	sendCmd(CMD::SLEEP_OUT);
	thread::delay(500);

	sendCmd(CMD::DISPLAY_ON);
	thread::delay(100);

	sendCmd(CMD::MEMORY_WRITE);

	mPeri->enable(false);
	mPeri->unlock();

	return true;
}

void ILI9341::sendCmd(uint8_t cmd)
{
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->send(cmd);
	mCs.port->setOutput(mCs.pin, true);
}

void ILI9341::sendCmd(uint8_t cmd, void *data, uint16_t len)
{
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->send(cmd);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send((int8_t *)data, len);
	mCs.port->setOutput(mCs.pin, true);
}

void ILI9341::setWindows(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
	uint8_t data[4];
	uint16_t end;

	end = x + width - 1;
	data[0] = x >> 8;
	data[1] = x & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(CMD::COLUMN_ADDRESS_SET, data, 4);
	
	end = y + height - 1;
	data[0] = y >> 8;
	data[1] = y & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(CMD::PAGE_ADDRESS_SET, data, 4);
}

void ILI9341::drawDot(int16_t x, int16_t y)
{
	if (y < mSize.height && x < mSize.width)
	{
		mPeri->lock();
		mPeri->setSpecification(gLcdConfig);
		mPeri->enable(true);

		setWindows(x, y);

		sendCmd(CMD::MEMORY_WRITE, &mBrushColor, 2);

		mPeri->enable(false);
		mPeri->unlock();
	}
}

void ILI9341::drawDots(uint16_t x, uint16_t y, uint16_t color, uint16_t size)
{
	if (mLineBuffer == 0)
		return;

	mPeri->lock();
	mPeri->setSpecification(gLcdConfig);
	mPeri->enable(true);

	setWindows(x, y, size, 1);

	size *= sizeof(uint16_t);
//	size *= 3;
	memsethw(mLineBuffer, color, size);

	sendCmd(CMD::MEMORY_WRITE, mLineBuffer, size);

	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9341::drawDots(uint16_t x, uint16_t y, uint16_t *src, uint16_t size)
{
	if (mLineBuffer == 0)
		return;

	mPeri->lock();
	mPeri->setSpecification(gLcdConfig);
	mPeri->enable(true);

	setWindows(x, y, size, 2);

	size *= sizeof(uint16_t);
	sendCmd(CMD::MEMORY_WRITE, mLineBuffer, size);

	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9341::drawDot(int16_t x, int16_t y, uint16_t color)
{
	if (y < mSize.height && x < mSize.width)
	{
		mPeri->lock();
		mPeri->setSpecification(gLcdConfig);
		mPeri->enable(true);

		setWindows(x, y);

		sendCmd(CMD::MEMORY_WRITE, &color, 2);

		mPeri->enable(false);
		mPeri->unlock();
	}
}

void ILI9341::drawDot(int16_t x, int16_t y, uint32_t color)
{
}

void ILI9341::drawFontDot(int16_t x, int16_t y, uint8_t color)
{
}

void ILI9341::eraseDot(Position pos)
{
}

void ILI9341::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	uint8_t buf;

	mBrushColor.color.red = red >> 3;
	mBrushColor.color.green = green >> 2;
	mBrushColor.color.blue = blue >> 3;

	buf = mBrushColor.byte[0];
	mBrushColor.byte[0] = mBrushColor.byte[1];
	mBrushColor.byte[1] = buf;
}

void ILI9341::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColor.setFontColor(red, green, blue);
	mFontColor.calculateSwappedByte();
}

void ILI9341::setBgColor(uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t buf;

	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;

	buf = mBgColor.byte[0];
	mBgColor.byte[0] = mBgColor.byte[1];
	mBgColor.byte[1] = buf;

	mFontColor.setBgColor(red, green, blue);
	mFontColor.calculateSwappedByte();
}

void ILI9341::drawBmp(Position pos, const Bmp565 *image)
{
	uint8_t *src = image->data;
	uint16_t width = image->width, height = image->height;
	uint32_t size = width * height * 2;
	int16_t x = pos.x, y = pos.y;

	// RGB565가 아니면 리턴
	if (image->type != 0)
		return;

	mPeri->lock();
	mPeri->setSpecification(gLcdConfig);
	mPeri->enable(true);

	setWindows(x, y, width, height);

	sendCmd(CMD::MEMORY_WRITE, src, size);

	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9341::drawBmp(Position pos, const Bmp565 &image)
{
	drawBmp(pos, &image);
}
#endif