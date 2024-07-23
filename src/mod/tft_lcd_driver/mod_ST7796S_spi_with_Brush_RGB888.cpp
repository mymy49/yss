/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <mod/tft_lcd_driver/ST7796S_spi_with_Brush_RGB888.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

static const Spi::specification_t gLcdSpec =
{
	Spi::MODE_MODE0,	//uint8_t mode;
	500000,					//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
};

ST7796S_spi_with_Brush_RGB888::ST7796S_spi_with_Brush_RGB888(void)
{

}

void ST7796S_spi_with_Brush_RGB888::setConfig(const Config &config)
{
	mPeri = &config.peri;
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;

	if(mRstPin.port)
		mRstPin.port->setOutput(mRstPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST7796S_spi_with_Brush_RGB888::sendCmd(uint8_t cmd)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST7796S_spi_with_Brush_RGB888::sendCmd(uint8_t cmd, void *data, uint32_t len)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mDcPin.port->setOutput(mDcPin.pin, true);
	mPeri->send((int8_t *)data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST7796S_spi_with_Brush_RGB888::enable(void)
{
	mPeri->lock();
	mPeri->setSpecification(gLcdSpec);
	mPeri->enable(true);
}

void ST7796S_spi_with_Brush_RGB888::disable(void)
{
	mPeri->enable(false);
	mPeri->unlock();
}

void ST7796S_spi_with_Brush_RGB888::reset(void)
{
	if(mRstPin.port)
	{
		mRstPin.port->setOutput(mRstPin.pin, false);
		thread::delay(10);
		mRstPin.port->setOutput(mRstPin.pin, true);
	}
	else
	{
		enable();
		sendCmd(SOFTWARE_RESET);
		disable();
	}
}

#endif

#endif

