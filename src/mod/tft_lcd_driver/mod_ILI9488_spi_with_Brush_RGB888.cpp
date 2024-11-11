/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <drv/Spi.h>

#if USE_GUI && !defined(YSS_DRV_SPI_UNSUPPORTED)

#include <mod/tft_lcd_driver/ILI9488_spi_with_Brush_RGB888.h>

static const Spi::specification_t gLcdSpec =
{
	Spi::MODE_MODE0,	//uint8_t mode;
	40000000,					//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
};

ILI9488_spi_with_Brush_RGB888::ILI9488_spi_with_Brush_RGB888(void)
{
	mSpec = &gLcdSpec;
}

void ILI9488_spi_with_Brush_RGB888::setConfig(const Config &config)
{
	mPeri = &config.peri;
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;
	mCsPin.port->setOutput(mCsPin.pin, true);
	
	// CS 핀이 10ms 정도 High로 고정될 수 있도록 대기
	thread::delay(10);
}

void ILI9488_spi_with_Brush_RGB888::sendCmd(uint8_t cmd)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9488_spi_with_Brush_RGB888::sendCmd(uint8_t cmd, void *data, uint32_t len)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mDcPin.port->setOutput(mDcPin.pin, true);
	mPeri->send((int8_t *)data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9488_spi_with_Brush_RGB888::sendCmd(uint8_t cmd, uint8_t data)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mDcPin.port->setOutput(mDcPin.pin, true);
	mPeri->send(data);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ILI9488_spi_with_Brush_RGB888::enable(void)
{
	mPeri->lock();
	mPeri->setSpecification(gLcdSpec);
	mPeri->enable(true);
}

void ILI9488_spi_with_Brush_RGB888::disable(void)
{
	mPeri->enable(false);
	mPeri->unlock();
}

void ILI9488_spi_with_Brush_RGB888::reset(void)
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

void ILI9488_spi_with_Brush_RGB888::setSpiSpecification(const Spi::specification_t &spec)
{
	mSpec = &spec;
}

#endif

