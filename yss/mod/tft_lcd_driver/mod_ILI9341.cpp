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

#include <mod/tft_lcd_driver/ILI9341.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

static const Spi::Specification gLcdSpec =
{
	define::spi::mode::MODE0,	//uint8_t mode;
	30000000,					//uint32_t maxFreq;
	define::spi::bit::BIT8		//uint8_t bit;
};

ILI9341::ILI9341(void)
{

}

error ILI9341::init(void)
{
	if(mRstPin.port)
		mRstPin.port->setOutput(mRstPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, true);

	thread::delay(300);

	enable();
	reset();
	
	thread::delay(500);

	sendCmd(DISPLAY_OFF);

	const uint8_t powerA[5] = {0x39, 0x2c, 0x00, 0x34, 0x02};
	sendCmd(POWER_A, (int8_t *)powerA, sizeof(powerA));

	const uint8_t powerB[3] = {0x00, 0xc1, 0x30};
	sendCmd(POWER_B, (int8_t *)powerB, sizeof(powerB));

	const uint8_t dtca[3] = {0x85, 0x00, 0x78};
	sendCmd(DTCA, (int8_t *)dtca, sizeof(dtca));

	const uint8_t dtcb[2] = {0x00, 0x00};
	sendCmd(DTCB, (int8_t *)dtcb, sizeof(dtcb));

	const uint8_t powerSeq[4] = {0x64, 0x03, 0x12, 0x81};
	sendCmd(POWER_SEQ, (int8_t *)powerSeq, sizeof(powerSeq));

	const uint8_t prc[1] = {0x20};
	sendCmd(ADJUST_CTRL3, (int8_t *)prc, sizeof(prc));

	const uint8_t powerCtrl1[1] = {0x23};
	sendCmd(POWER_CTRL1, (int8_t *)powerCtrl1, sizeof(powerCtrl1));

	const uint8_t powerCtrl2[1] = {0x10};
	sendCmd(POWER_CTRL2, (int8_t *)powerCtrl2, sizeof(powerCtrl2));

	const uint8_t vcomCtrl1[2] = {0x3e, 0x28};
	sendCmd(VCOM_CTRL1, (int8_t *)vcomCtrl1, sizeof(vcomCtrl1));

	const uint8_t vcomCtrl2[1] = {0x86};
	sendCmd(VCOM_CTRL2, (int8_t *)vcomCtrl2, sizeof(vcomCtrl2));

	uint8_t memAccCtrl[] = {0x00};
	sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));

	const uint8_t fixelFormat[1] = {0x55};
	sendCmd(COLMOD_PIXEL_FORMAT_SET, (int8_t *)fixelFormat, sizeof(fixelFormat));

	const uint8_t frameRate[2] = {0x00, 0x18};
	sendCmd(FRAME_RATE, (int8_t *)frameRate, sizeof(frameRate));

	const uint8_t gammaFuncDis[1] = {0x00};
	sendCmd(GAMMA3_FUNC_DIS, (int8_t *)gammaFuncDis, sizeof(gammaFuncDis));

	const uint8_t gammaSet4[1] = {0x01};
	sendCmd(GAMMA_SET, (int8_t *)gammaSet4, sizeof(gammaSet4));

	const uint8_t posGamma[15] = {0x0f, 0x31, 0x2b, 0x0c, 0x0e, 0x08, 0x4e, 0xf1, 0x37, 0x07, 0x10, 0x03, 0x0e, 0x09, 0x00};
	sendCmd(POS_GAMMA, (int8_t *)posGamma, sizeof(posGamma));

	const uint8_t negGamma[15] = {0x00, 0x0e, 0x14, 0x03, 0x11, 0x07, 0x31, 0xc1, 0x48, 0x08, 0x0f, 0x0c, 0x31, 0x36, 0x0f};
	sendCmd(NEG_GAMMA, (int8_t *)negGamma, sizeof(negGamma));

	const uint8_t displayCtrl[4] = {0x08, 0x82, 0x27};
	sendCmd(DISPLAY_CTRL, (int8_t *)displayCtrl, sizeof(displayCtrl));

	sendCmd(SLEEP_OUT);
	thread::delay(500);

	sendCmd(DISPLAY_ON);
	thread::delay(100);

	sendCmd(MEMORY_WRITE);

	disable();

	return Error::NONE;
}

void ILI9341::setConfig(const Config &config)
{
	mPeri = &config.peri;
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;
}

void ILI9341::sendCmd(uint8_t cmd)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9341::sendCmd(uint8_t cmd, void *data, uint32_t len)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mDcPin.port->setOutput(mDcPin.pin, true);
	mPeri->send((int8_t *)data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9341::enable(void)
{
	mPeri->lock();
	mPeri->setSpecification(gLcdSpec);
	mPeri->enable(true);
}

void ILI9341::disable(void)
{
	mPeri->enable(false);
	mPeri->unlock();
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

	sendCmd(COLUMN_ADDRESS_SET, data, 4);
	
	end = y + height - 1;
	data[0] = y >> 8;
	data[1] = y & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(PAGE_ADDRESS_SET, data, 4);
}

void ILI9341::setDirection(bool xMirror, bool yMirror, bool rotate)
{
	enable();
	int8_t memAccCtrl[] = {0x00};
	if(xMirror)
		memAccCtrl[0] |= 0x80;
	if(yMirror)
		memAccCtrl[0] |= 0x40;
	if(rotate)
		memAccCtrl[0] |= 0x20;

	mRotateFlag = rotate;

	sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));
	disable();
}

void ILI9341::reset(void)
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

#endif
