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

#include <mod/cputft/ILI9320.h>
#include <stdlib.h>
#include <string.h>
#include <yss/malloc.h>
#include <yss/stdlib.h>

/*
#ifndef YSS_DRV_SPI_UNSUPPORTED

namespace CMD
{
enum
{
	START_OSC = 0x00,
	DRV_OUTPUT_CTRL = 0x01,
	LCD_DRV_WAVE_CTRL = 0x02,
	ENTRY_MODE = 0x03,
	RESIZING_CTRL = 0x04,
	DSP_CTRL1 = 0x07,
	DSP_CTRL2 = 0x08,
	DSP_CTRL3 = 0x09,
	DSP_CTRL4 = 0x0A,
	RGB_DSP_IF_CTRL1 = 0x0C,
	FRAME_MARKER_POS = 0x0D,
	RGB_DSP_IF_CTRL2 = 0x0F,
	PWR_CTRL1 = 0x10,
	PWR_CTRL2 = 0x11,
	PWR_CTRL3 = 0x12,
	PWR_CTRL4 = 0x13,
	GRAM_H_ADDR_SET = 0x20,
	GRAM_V_ADDR_SET = 0x21,
	WRITE_DATA_TO_GRAM = 0x22,
	READ_DATA_FROM_GRAM = 0x22,
	PWR_CTRL7 = 0x29,
	FRAME_RATE_COLOR_CTRL = 0x2B,
	GAMMA_CTRL = 0x30,
	H_RAM_ADDR_START_POS = 0x50,
	H_RAM_ADDR_END_POS = 0x51,
	V_RAM_ADDR_START_POS = 0x52,
	V_RAM_ADDR_END_POS = 0x53,
	GATE_SCAN_CTRL1 = 0x60,
	GATE_SCAN_CTRL2 = 0x61,
	GATE_SCAN_CTRL3 = 0x6A,
	PARTIAL_IMG1_DSP_POS = 0x80,
	PARTIAL_IMG1_RAM_START_ADDR = 0x81,
	PARTIAL_IMG1_RAM_END_ADDR = 0x82,
	PARTIAL_IMG2_DSP_POS = 0x83,
	PARTIAL_IMG2_RAM_START_ADDR = 0x84,
	PARTIAL_IMG2_RAM_END_ADDR = 0x85,
	PANEL_IF_CTRL1 = 0x90,
	PANEL_IF_CTRL2 = 0x92,
	PANEL_IF_CTRL3 = 0x93,
	PANEL_IF_CTRL4 = 0x95,
	PANEL_IF_CTRL5 = 0x97,
	PANEL_IF_CTRL6 = 0x98
};
}

config::spi::Config gLcdConfig =
	{
		define::spi::mode::MODE0, //uint8_t mode;
		12500000,                 //uint32_t maxFreq;
		define::spi::bit::BIT8};  //uint8_t bit;

ILI9320::ILI9320(void)
{
	mCs.port = 0;
	mDc.port = 0;
	mRst.port = 0;
	mPeri = 0;
	mLineBuffer = 0;
}

bool ILI9320::init(const Config config)
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
	
	uint8_t reg;

	mPeri->lock();
	mPeri->setConfig(gLcdConfig);
	mPeri->enable(true);
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
	reg = 0x70;
	mPeri->exchange(reg);
	mDc.port->setOutput(mDc.pin, true);
	reg = mPeri->exchange(reg);
	debug_printf("0x%02X\n", reg);
	reg = mPeri->exchange(reg);
	debug_printf("0x%02X\n", reg);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();

	sendCmd(CMD::START_OSC, 0x0000);
	sendCmd(CMD::DRV_OUTPUT_CTRL, 0x0100);
	sendCmd(CMD::LCD_DRV_WAVE_CTRL, 0x0700);
	sendCmd(CMD::ENTRY_MODE, 0x1030);
	sendCmd(CMD::RESIZING_CTRL, 0x0000);
	sendCmd(CMD::DSP_CTRL2, 0x0202);
	sendCmd(CMD::DSP_CTRL3, 0x0000);
	sendCmd(CMD::DSP_CTRL4, 0x0000);
	sendCmd(CMD::RGB_DSP_IF_CTRL1, 0x0001);
	sendCmd(CMD::FRAME_MARKER_POS, 0x0000);
	sendCmd(CMD::RGB_DSP_IF_CTRL2, 0x0000);

	thread::delay(50);

	sendCmd(CMD::DSP_CTRL1, 0x0101);

	thread::delay(50);

	sendCmd(CMD::PWR_CTRL1, (1<<12)|(0<<8)|(1<<7)|(1<<6)|(0<<4));
	sendCmd(CMD::PWR_CTRL2, 0x0007);
	sendCmd(CMD::PWR_CTRL3, (1<<8)|(1<<4)|(0<<0));
	sendCmd(CMD::PWR_CTRL4, 0x0B00);
	sendCmd(CMD::PWR_CTRL7, 0x0000);
	sendCmd(CMD::FRAME_RATE_COLOR_CTRL, (1<<14)|(1<<4));
	
	sendCmd(CMD::H_RAM_ADDR_START_POS, 0);
	sendCmd(CMD::H_RAM_ADDR_END_POS, 239);
	sendCmd(CMD::V_RAM_ADDR_START_POS, 0);
	sendCmd(CMD::V_RAM_ADDR_END_POS, 319);
	
	thread::delay(50);

	sendCmd(CMD::GATE_SCAN_CTRL1, 0x2700);
	sendCmd(CMD::GATE_SCAN_CTRL2, 0x0001);
	sendCmd(CMD::GATE_SCAN_CTRL3, 0x0000);
	
	sendCmd(CMD::PARTIAL_IMG1_DSP_POS, 0x0000);
	sendCmd(CMD::PARTIAL_IMG1_RAM_START_ADDR, 0x0000);
	sendCmd(CMD::PARTIAL_IMG1_RAM_END_ADDR, 0x0000);
	sendCmd(CMD::PARTIAL_IMG2_DSP_POS, 0x0000);
	sendCmd(CMD::PARTIAL_IMG2_RAM_START_ADDR, 0x0000);
	sendCmd(CMD::PARTIAL_IMG2_RAM_END_ADDR, 0x0000);

	sendCmd(CMD::PANEL_IF_CTRL1, (0<<7)|(16<<0));
	sendCmd(CMD::PANEL_IF_CTRL2, 0x0000);
	sendCmd(CMD::PANEL_IF_CTRL3, 0x0001);
	sendCmd(CMD::PANEL_IF_CTRL4, 0x0110);
	sendCmd(CMD::PANEL_IF_CTRL5, (0<<8));
	sendCmd(CMD::PANEL_IF_CTRL6, 0x0000);
	sendCmd(CMD::DSP_CTRL1, 0x0133);

	return true;
}

void ILI9320::sendCmd(uint8_t cmd)
{
	mPeri->lock();
	mPeri->setConfig(gLcdConfig);
	mPeri->enable(true);
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->exchange(cmd);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9320::sendCmd(uint8_t cmd, uint16_t data)
{
	mPeri->lock();
	mPeri->setConfig(gLcdConfig);
	mPeri->enable(true);
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->exchange(cmd);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send((int8_t *)&data, 2);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9320::drawDot(int16_t x, int16_t y)
{
	uint8_t data[4];

	if (y < mSize.height && x < mSize.width)
	{
		data[0] = x >> 8;
		data[1] = x & 0xff;
		data[2] = data[0];
		data[3] = data[1];

		mPeri->lock();
		mPeri->setConfig(gLcdConfig);
		mPeri->enable(true);
		mDc.port->setOutput(mDc.pin, false);
		mCs.port->setOutput(mCs.pin, false);
//		mPeri->exchange(CMD::COLUMN_ADDRESS_SET);
		mDc.port->setOutput(mDc.pin, true);
		mPeri->send((int8_t *)data, 4);

		data[0] = y >> 8;
		data[1] = y & 0xff;
		data[2] = data[0];
		data[3] = data[1];

		mDc.port->setOutput(mDc.pin, false);
//		mPeri->exchange(CMD::PAGE_ADDRESS_SET);
		mDc.port->setOutput(mDc.pin, true);
		mPeri->send((int8_t *)data, 4);

		mDc.port->setOutput(mDc.pin, false);
//		mPeri->exchange(CMD::MEMORY_WRITE);

		mDc.port->setOutput(mDc.pin, true);
		mPeri->send(&mBrushColor, 2);
		mCs.port->setOutput(mCs.pin, true);
		mPeri->enable(false);
		mPeri->unlock();
	}
}

void ILI9320::drawDots(uint16_t x, uint16_t y, uint16_t color, uint16_t size)
{
	uint8_t data[4];
	int16_t end;

	if (mLineBuffer == 0)
		return;

	end = x + size - 1;
	data[0] = x >> 8;
	data[1] = x & 0xff;
	data[2] = end >> 8;
	data[3] = end & 0xff;

	mPeri->lock();
	mPeri->setConfig(gLcdConfig);
	mPeri->enable(true);
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
//	mPeri->exchange(CMD::COLUMN_ADDRESS_SET);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send((int8_t *)data, 4);

	data[0] = y >> 8;
	data[1] = y & 0xff;
	data[2] = y + 1 >> 8;
	data[3] = y + 1 & 0xff;

	mDc.port->setOutput(mDc.pin, false);
//	mPeri->exchange(CMD::PAGE_ADDRESS_SET);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send((int8_t *)data, 4);

	mDc.port->setOutput(mDc.pin, false);
//	mPeri->exchange(CMD::MEMORY_WRITE);

	size *= sizeof(uint16_t);
	memsethw(mLineBuffer, color, size);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send(mLineBuffer, size);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9320::drawDots(uint16_t x, uint16_t y, uint16_t *src, uint16_t size)
{
	uint8_t data[4];
	int16_t end;

	if (mLineBuffer == 0)
		return;

	end = x + size - 1;
	data[0] = x >> 8;
	data[1] = x & 0xff;
	data[2] = end >> 8;
	data[3] = end & 0xff;

	mPeri->lock();
	mPeri->setConfig(gLcdConfig);
	mPeri->enable(true);
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
//	mPeri->exchange(CMD::COLUMN_ADDRESS_SET);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send((int8_t *)data, 4);

	data[0] = y >> 8;
	data[1] = y & 0xff;
	data[2] = y + 1 >> 8;
	data[3] = y + 1 & 0xff;

	mDc.port->setOutput(mDc.pin, false);
//	mPeri->exchange(CMD::PAGE_ADDRESS_SET);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send((int8_t *)data, 4);

	mDc.port->setOutput(mDc.pin, false);
//	mPeri->exchange(CMD::MEMORY_WRITE);

	size *= sizeof(uint16_t);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send(mLineBuffer, size);
	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9320::drawDot(int16_t x, int16_t y, uint16_t color)
{
	uint8_t data[4];

	if (y < mSize.height && x < mSize.width)
	{
		data[0] = x >> 8;
		data[1] = x & 0xff;
		data[2] = data[0];
		data[3] = data[1];

		mPeri->lock();
		mPeri->setConfig(gLcdConfig);
		mPeri->enable(true);
		mDc.port->setOutput(mDc.pin, false);
		mCs.port->setOutput(mCs.pin, false);
//		mPeri->exchange(CMD::COLUMN_ADDRESS_SET);
		mDc.port->setOutput(mDc.pin, true);
		mPeri->send((int8_t *)data, 4);

		data[0] = y >> 8;
		data[1] = y & 0xff;
		data[2] = data[0];
		data[3] = data[1];

		mDc.port->setOutput(mDc.pin, false);
//		mPeri->exchange(CMD::PAGE_ADDRESS_SET);
		mDc.port->setOutput(mDc.pin, true);
		mPeri->send((int8_t *)data, 4);

		mDc.port->setOutput(mDc.pin, false);
//		mPeri->exchange(CMD::MEMORY_WRITE);

		mDc.port->setOutput(mDc.pin, true);
		mPeri->send(&color, 2);
		mCs.port->setOutput(mCs.pin, true);
		mPeri->enable(false);
		mPeri->unlock();
	}
}

void ILI9320::drawDot(int16_t x, int16_t y, uint32_t color)
{
}

void ILI9320::drawFontDot(int16_t x, int16_t y, uint8_t color)
{
}

void ILI9320::eraseDot(Pos pos)
{
}

void ILI9320::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	uint8_t buf;

	mBrushColor.color.red = red >> 3;
	mBrushColor.color.green = green >> 2;
	mBrushColor.color.blue = blue >> 3;

	buf = mBrushColor.byte[0];
	mBrushColor.byte[0] = mBrushColor.byte[1];
	mBrushColor.byte[1] = buf;
}

void ILI9320::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColor.setFontColor(red, green, blue);
	mFontColor.calculateSwappedByte();
}

void ILI9320::setBgColor(uint8_t red, uint8_t green, uint8_t blue)
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

void ILI9320::drawBmp(Pos pos, const Bmp565 *image)
{
	uint8_t *src = image->data;
	uint8_t data[4];
	int16_t end;
	uint16_t width = image->width, height = image->height;
	uint32_t size = width * height * 2;
	int16_t x = pos.x, y = pos.y;

	// RGB565가 아니면 리턴
	if (image->type != 0)
		return;

	end = x + width - 1;
	data[0] = x >> 8;
	data[1] = x & 0xff;
	data[2] = end >> 8;
	data[3] = end & 0xff;
	mPeri->lock();
	mPeri->setConfig(gLcdConfig);
	mPeri->enable(true);
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
//	mPeri->exchange(CMD::COLUMN_ADDRESS_SET);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send((int8_t *)data, 4);
	mCs.port->setOutput(mCs.pin, true);

	end = y + height - 1;
	data[0] = y >> 8;
	data[1] = y & 0xff;
	data[2] = end >> 8;
	data[3] = end & 0xff;
	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
//	mPeri->exchange(CMD::PAGE_ADDRESS_SET);
	mDc.port->setOutput(mDc.pin, true);
	mPeri->send((int8_t *)data, 4);
	mCs.port->setOutput(mCs.pin, true);

	mDc.port->setOutput(mDc.pin, false);
	mCs.port->setOutput(mCs.pin, false);
//	mPeri->exchange(CMD::MEMORY_WRITE);
	mCs.port->setOutput(mCs.pin, true);

	mDc.port->setOutput(mDc.pin, true);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->send(src, size);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9320::drawBmp(Pos pos, const Bmp565 &image)
{
	drawBmp(pos, &image);
}
#endif
*/