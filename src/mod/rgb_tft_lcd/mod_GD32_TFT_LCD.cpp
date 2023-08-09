////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI == true

#include <mod/rgb_tft_lcd/GD32_RGB_LCD.h>

#if !defined(YSS_DRV_LTDC_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

#include <drv/peripheral.h>
#include <std_ext/stdlib.h>
#include <yss/thread.h>

static const Ltdc::Specification gLtdcSpec =
	{
		320,                         // width
		480,                         // height
		3,                           // hsyncWidth
		1,                           // vsyncWidth
		3,                           // hbp
		2,                           // vbp
		3,                           // hfp
		2,                           // vfp
		define::ltdc::format::RGB565 // pixelFormat
};

GD32_RGB_LCD::GD32_RGB_LCD(void)
{
}

error GD32_RGB_LCD::initialize(void)
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
	
	const uint8_t powerCon1[] = {0x0F, 0x0C};
	sendCmd(POWER_CTRL1, (void*)powerCon1, sizeof(powerCon1));

	const uint8_t powerCon2[] = {0x41};
	sendCmd(POWER_CTRL2, (void*)powerCon2, sizeof(powerCon2));

	const uint8_t powerCon3[] = {0x00, 0x21, 0x80};
	sendCmd(VCOM_CTRL1, (void*)powerCon3, sizeof(powerCon3));

	const uint8_t pixelWidth[] = {0x00, 0x00, 320 >> 8, 320 & 0xFF};
	sendCmd(COLUMN_ADDRESS_SET, (void*)pixelWidth, sizeof(pixelWidth));

	const uint8_t pixelHeight[] = {0x00, 0x00, 480 >> 8, 480 & 0xFF};
	sendCmd(PAGE_ADDRESS_SET, (void*)pixelHeight, sizeof(pixelHeight));

	const uint8_t memoryAcess[] = {0x48};
	sendCmd(MEMORY_ACCESS_CONTROL, (void*)memoryAcess, sizeof(memoryAcess));

	const uint8_t format[] = {0x55};
	sendCmd(COLMOD_PIXEL_FORMAT_SET, (void*)format, sizeof(format));

	const uint8_t interface[] = {0x00};
	sendCmd(INTERFACE_MODE_CTRL, (void*)interface, sizeof(interface));

	const uint8_t frameRate[] = {0xA0};
	sendCmd(FRAME_RATE, (void*)frameRate, sizeof(frameRate));

	const uint8_t displayCon1[] = {0x02};
	sendCmd(DISPLAY_INVERSION_CTRL, (void*)displayCon1, sizeof(displayCon1));

	const uint8_t displayCon2[] = {0x22, 0x02};
	sendCmd(DISPLAY_CTRL, (void*)displayCon2, sizeof(displayCon2));

	const uint8_t image[] = {0x00};
	sendCmd(SET_IMAGE_FUNC, (void*)image, sizeof(image));

	const uint8_t adjust[] = {0xF7, 0xA9, 0x51, 0x2C, 0x82};
	sendCmd(ADJUST_CTRL3, (void*)adjust, sizeof(adjust));

	sendCmd(DISP_INVERSION_ON);

	sendCmd(SLEEP_OUT);

	thread::delay(120);

	sendCmd(DISPLAY_ON);

	return error::ERROR_NONE;
}

void GD32_RGB_LCD::setConfig(const Config &config)
{
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;
	mSckPin = config.sck;
	mMosiPin = config.mosi;
}

void GD32_RGB_LCD::sendCmd(uint8_t cmd)
{
	mCsPin.port->setOutput(mCsPin.pin, false);
	mMosiPin.port->setOutput(mMosiPin.pin, false);
	mSckPin.port->setOutput(mSckPin.pin, false);
	mSckPin.port->setOutput(mSckPin.pin, true);
	for(int32_t  i=0;i<8;i++)
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

void GD32_RGB_LCD::sendData(uint8_t data)
{
	mCsPin.port->setOutput(mCsPin.pin, false);
	mMosiPin.port->setOutput(mMosiPin.pin, true);
	mSckPin.port->setOutput(mSckPin.pin, false);
	mSckPin.port->setOutput(mSckPin.pin, true);
	for(int32_t  i=0;i<8;i++)
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

void GD32_RGB_LCD::sendCmd(uint8_t cmd, void *data, uint32_t len)
{
	uint8_t *src = (uint8_t *)data;
	sendCmd(cmd);
	for(int32_t  i=0;i<len;i++)
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

void GD32_RGB_LCD::reset(void)
{

}

const Ltdc::Specification* GD32_RGB_LCD::getSpecification(void)
{
	return &gLtdcSpec;
}

#endif

#endif

