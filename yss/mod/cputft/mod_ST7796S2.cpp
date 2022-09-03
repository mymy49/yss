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

#include <mod/cputft/ST7796S.h>
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
	INTERFACE_MODE_CON = 0xB0,
	FRAME_RATE = 0xB1,
	DISPLAY_INVERSION_CON = 0xB4,
	BLANKING_PORCH_CON = 0xB5,
	DISPLAY_CTRL = 0xB6,
	ENTRY_MODE_SET = 0xB7,
	POWER_CTRL1 = 0xC0,
	POWER_CTRL2 = 0xC1,
	POWER_CTRL3 = 0xC2,
	VCOM_CTRL1 = 0xC5,
	VCOM_CTRL2 = 0xc7,
	POWER_A = 0xcb,
	POWER_B = 0xcf,
	CMD_READ_ID1 = 0xDA,
	READ_ID2 = 0xDB,
	CMD_READ_ID3 = 0xDC,
	POS_GAMMA = 0xE0,
	NEG_GAMMA = 0xE1,
	DTCA = 0xE8,
	DTCB = 0xea,
	POWER_SEQ = 0xed,
	CMD_SET_CONFIG = 0xF0,
	GAMMA3_FUNC_DIS = 0xf2,
	PRC = 0xf7
};
}
/*
const drv::Spi::Specification gLcdConfig =
	{
		define::spi::mode::MODE0
		, //uint8_t mode;
		50000000,                 //uint32_t maxFreq;
		define::spi::bit::BIT8};  //uint8_t bit;

ST7796S::ST7796S(void)
{
	mCs.port = 0;
	mDc.port = 0;
	mRst.port = 0;
	mPeri = 0;
	mLineBuffer = 0;
}

bool ST7796S::init(const Config config)
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

	thread::delay(10);
	if(mRst.port)
		mRst.port->setOutput(mRst.pin, true);
	
	thread::delay(500);

	mPeri->lock();
	mPeri->setSpecification(gLcdConfig);
	mPeri->enable(true);

	const int8_t cscon1[] = {0xC3};
	sendCmd(CMD::CMD_SET_CONFIG, (int8_t *)cscon1, sizeof(cscon1));

	const int8_t cscon2[] = {0x96};
	sendCmd(CMD::CMD_SET_CONFIG, (int8_t *)cscon2, sizeof(cscon2));

	int8_t memAccCtrl[] = {0x08};
	memAccCtrl[0] |= config.madctl;
	sendCmd(CMD::MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));

	const int8_t fixelFormat[] = {0x06};
	sendCmd(CMD::COLMOD_PIXEL_FORMAT_SET, (int8_t *)fixelFormat, sizeof(fixelFormat));

	const int8_t interfaceModeCon[] = {0x80};
	sendCmd(CMD::INTERFACE_MODE_CON, (int8_t *)interfaceModeCon, sizeof(interfaceModeCon));

	const int8_t displayCtrl[] = {0x00, 0x02};
	sendCmd(CMD::DISPLAY_CTRL, (int8_t *)displayCtrl, sizeof(displayCtrl));
	
	const int8_t blankingPorchCon[] = {0x02, 0x03, 0x00, 0x04};
	sendCmd(CMD::BLANKING_PORCH_CON, (int8_t *)blankingPorchCon, sizeof(blankingPorchCon));

	const int8_t frameRate[] = {0x80, 0x10};
	sendCmd(CMD::FRAME_RATE, (int8_t *)frameRate, sizeof(frameRate));

	const int8_t displayInvCon[] = {0x00};
	sendCmd(CMD::DISPLAY_INVERSION_CON, (int8_t *)displayInvCon, sizeof(displayInvCon));

	const int8_t entryModeSet[] = {0xC6};
	sendCmd(CMD::ENTRY_MODE_SET, (int8_t *)entryModeSet, sizeof(entryModeSet));
	
	const int8_t vcomCtrl1[] = {0x24};
	sendCmd(CMD::VCOM_CTRL1, (int8_t *)vcomCtrl1, sizeof(vcomCtrl1));

	const int8_t unknown[] = {0x31};
	sendCmd(0xE4, (int8_t *)unknown, sizeof(unknown));

	const int8_t dtca[] = {0x40, 0x8A, 0x00, 0x00, 0x29, 0x19, 0xA5, 0x33};
	sendCmd(CMD::DTCA, (int8_t *)dtca, sizeof(dtca));

	const int8_t posGamma[] = {0xF0, 0x09, 0x13, 0x12, 0x12, 0x2B, 0x3C, 0x44, 0x4B, 0x1B, 0x18, 0x17, 0x1D, 0x21};
	sendCmd(CMD::POS_GAMMA, (int8_t *)posGamma, sizeof(posGamma));

	const int8_t negGamma[] = {0xF0, 0x09, 0x13, 0x0C, 0x0D, 0x27, 0x3B, 0x44, 0x4D, 0x0B, 0x17, 0x17, 0x1D, 0x21};
	sendCmd(CMD::NEG_GAMMA, (int8_t *)negGamma, sizeof(negGamma));

	//const int8_t cscon3[] = {0xC3};
	//sendCmd(CMD::CMD_SET_CONFIG, (int8_t *)cscon3, sizeof(cscon3));

	//const int8_t cscon4[] = {0x69};
	//sendCmd(CMD::CMD_SET_CONFIG, (int8_t *)cscon4, sizeof(cscon4));
	
	sendCmd(CMD::NORMAL_DISP_MODE_ON);
	
	sendCmd(CMD::SLEEP_OUT);
	thread::delay(100);

	sendCmd(CMD::DISPLAY_ON);
	thread::delay(50);

	mPeri->enable(false);
	mPeri->unlock();

	return true;
}

void ST7796S::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	uint8_t buf;

	mBrushColor.color.red = red >> 3;
	mBrushColor.color.green = green >> 2;
	mBrushColor.color.blue = blue >> 3;
}

void ST7796S::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColor.setFontColor(red, green, blue);
	mFontColor.calculate();
}

void ST7796S::setBgColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;

	mFontColor.setBgColor(red, green, blue);
	mFontColor.calculate();
}

void ST7796S::test(uint32_t len)
{
	mPeri->lock();
	mPeri->setSpecification(gLcdConfig);
	mPeri->enable(true);
	
	uint8_t data[3] = {0xFF, 0xFF, 0xFF};
	setWindows(0, 0, 100, 100);

	sendCmd(CMD::MEMORY_WRITE);

	for(int32_t  i=0;i<len;i++)
		sendData(data, 2);

	mPeri->enable(false);
	mPeri->unlock();
}

void ST7796S::sendData(void *data, uint32_t len)
{
	mDc.port->setOutput(mDc.pin, true);
	mCs.port->setOutput(mCs.pin, false);
	mPeri->send((int8_t *)data, len);
	mCs.port->setOutput(mCs.pin, true);
}
*/
#endif

