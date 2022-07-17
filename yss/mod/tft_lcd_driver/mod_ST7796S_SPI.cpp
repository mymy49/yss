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

#include <mod/tft_lcd_driver/ST7796S_SPI.h>

static const drv::Spi::Specification gLcdSpec =
{
	define::spi::mode::MODE0,	//unsigned char mode;
	30000000,					//unsigned int maxFreq;
	define::spi::bit::BIT8		//unsigned char bit;
};

ST7796S_SPI::ST7796S_SPI(void)
{

}

error ST7796S_SPI::init(void)
{
	if(mRstPin.port)
		mRstPin.port->setOutput(mRstPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, true);

	thread::delay(300);
	if(mRstPin.port)
		mRstPin.port->setOutput(mRstPin.pin, true);
	
	thread::delay(500);
	enable();

	const char cscon1[] = {0xC3};
	sendCmd(SET_CONFIG, (char *)cscon1, sizeof(cscon1));

	const char cscon2[] = {0x96};
	sendCmd(SET_CONFIG, (char *)cscon2, sizeof(cscon2));

	char memAccCtrl[] = {0x00};
	sendCmd(MEMORY_ACCESS_CONTROL, (char *)memAccCtrl, sizeof(memAccCtrl));

	const char fixelFormat[] = {0x06};
	sendCmd(COLMOD_PIXEL_FORMAT_SET, (char *)fixelFormat, sizeof(fixelFormat));

	const char interfaceModeCon[] = {0x80};
	sendCmd(INTERFACE_MODE_CON, (char *)interfaceModeCon, sizeof(interfaceModeCon));

	const char displayCtrl[] = {0x00, 0x02};
	sendCmd(DISPLAY_CTRL, (char *)displayCtrl, sizeof(displayCtrl));
	
	const char blankingPorchCon[] = {0x02, 0x03, 0x00, 0x04};
	sendCmd(BLANKING_PORCH_CON, (char *)blankingPorchCon, sizeof(blankingPorchCon));

	const char frameRate[] = {0x80, 0x10};
	sendCmd(FRAME_RATE, (char *)frameRate, sizeof(frameRate));

	const char displayInvCon[] = {0x00};
	sendCmd(DISPLAY_INVERSION_CON, (char *)displayInvCon, sizeof(displayInvCon));

	const char entryModeSet[] = {0xC6};
	sendCmd(ENTRY_MODE_SET, (char *)entryModeSet, sizeof(entryModeSet));
	
	const char vcomCtrl1[] = {0x24};
	sendCmd(VCOM_CTRL1, (char *)vcomCtrl1, sizeof(vcomCtrl1));

	const char unknown[] = {0x31};
	sendCmd(0xE4, (char *)unknown, sizeof(unknown));

	const char dtca[] = {0x40, 0x8A, 0x00, 0x00, 0x29, 0x19, 0xA5, 0x33};
	sendCmd(DTCA, (char *)dtca, sizeof(dtca));

	const char posGamma[] = {0xF0, 0x09, 0x13, 0x12, 0x12, 0x2B, 0x3C, 0x44, 0x4B, 0x1B, 0x18, 0x17, 0x1D, 0x21};
	sendCmd(POS_GAMMA, (char *)posGamma, sizeof(posGamma));

	const char negGamma[] = {0xF0, 0x09, 0x13, 0x0C, 0x0D, 0x27, 0x3B, 0x44, 0x4D, 0x0B, 0x17, 0x17, 0x1D, 0x21};
	sendCmd(NEG_GAMMA, (char *)negGamma, sizeof(negGamma));

	sendCmd(NORMAL_DISP_MODE_ON);
	
	sendCmd(SLEEP_OUT);
	thread::delay(100);

	sendCmd(DISPLAY_ON);
	thread::delay(50);

	disable();

	return Error::NONE;
}

void ST7796S_SPI::setConfig(const Config &config)
{
	mPeri = &config.peri;
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;
}

void ST7796S_SPI::sendCmd(unsigned char cmd)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST7796S_SPI::sendCmd(unsigned char cmd, void *data, unsigned int len)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mDcPin.port->setOutput(mDcPin.pin, true);
	mPeri->send((char *)data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST7796S_SPI::enable(void)
{
	mPeri->lock();
	mPeri->setSpecification(gLcdSpec);
	mPeri->enable(true);
}

void ST7796S_SPI::disable(void)
{
	mPeri->enable(false);
	mPeri->unlock();
}

void ST7796S_SPI::setWindows(unsigned short x, unsigned short y, unsigned short width, unsigned short height)
{
	unsigned char data[4];
	unsigned short end;

	end = x + width - 1;
	data[0] = x >> 8;
	data[1] = x & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(COLUMN_ADDRESS_SET, data, 4);
	
	end = y + height - 1;
	data[0] = y >> 8;
	data[1] = y & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(PAGE_ADDRESS_SET, data, 4);
}

void ST7796S_SPI::setDirection(bool xMirror, bool yMirror, bool rotate)
{
	enable();
	char memAccCtrl[] = {0x00};
	if(xMirror)
		memAccCtrl[0] |= 0x80;
	if(yMirror)
		memAccCtrl[0] |= 0x40;
	if(rotate)
		memAccCtrl[0] |= 0x20;

	mRotateFlag = rotate;

	sendCmd(MEMORY_ACCESS_CONTROL, (char *)memAccCtrl, sizeof(memAccCtrl));
	disable();
}

void ST7796S_SPI::reset(void)
{
	if(mRstPin.port)
	{
		mRstPin.port->setOutput(mRstPin.pin, false);
		thread::delay(10);
		mRstPin.port->setOutput(mRstPin.pin, true);
	}
	else
		sendCmd(SOFTWARE_RESET);
}


