/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <mod/tft_lcd_driver/ILI9341_spi.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

static const Spi::specification_t gLcdSpec =
{
	Spi::MODE_MODE0,	//uint8_t mode;
	30000000,					//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
};

ILI9341_spi::ILI9341_spi(void)
{
}

void ILI9341_spi::setConfig(const Config &config)
{
	mPeri = &config.peri;
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;
	mCsPin.port->setOutput(mCsPin.pin, true);
	
	// CS 핀이 10ms 정도 High로 고정될 수 있도록 대기
	thread::delay(10);
}

void ILI9341_spi::sendCmd(uint8_t cmd)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9341_spi::sendCmd(uint8_t cmd, void *data, uint32_t len)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mDcPin.port->setOutput(mDcPin.pin, true);
	mPeri->send((int8_t *)data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9341_spi::enable(void)
{
	mPeri->lock();
	mPeri->setSpecification(gLcdSpec);
	mPeri->enable(true);
}

void ILI9341_spi::disable(void)
{
	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9341_spi::reset(void)
{
	if(mRstPin.port)
	{
		mRstPin.port->setOutput(mRstPin.pin, false);
		thread::delay(10);
		mRstPin.port->setOutput(mRstPin.pin, true);
	}
	else
		sendCmd(SOFTWARE_RESET);
	
	thread::delay(200);
}

#endif

#endif

