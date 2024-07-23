/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/logic/SN74LV595A.h>
#include <std_ext/malloc.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

static const Spi::specification_t gConfig =
	{
		Spi::MODE_MODE0,
		40000000,
		Spi::BIT_BIT8
	};

SN74LV595A::SN74LV595A(void)
{
	reset();
}

void SN74LV595A::reset(void)
{
	mOe.port = 0;
	mRclk.port = 0;
	mSrclr.port = 0;
	mPeri = 0;
}

bool SN74LV595A::initialize(Config config)
{
	mPeri = &config.spi;
	mOe = config.OE;
	mRclk = config.RCLK;
	mSrclr = config.SRCLR;

	if(mOe.port)
		mOe.port->setOutput(mOe.pin, false);

	if(mRclk.port)
		mRclk.port->setOutput(mRclk.pin, false);

	if (mSrclr.port)
	{
		mSrclr.port->setOutput(mSrclr.pin, false);
		mSrclr.port->setOutput(mSrclr.pin, true);
	}

	return true;
}

void SN74LV595A::set(uint8_t data)
{
	mPeri->lock();
	mPeri->setSpecification(gConfig);
	mPeri->enable(true);
	mPeri->send(data);
	if(mRclk.port)
	{
		mRclk.port->setOutput(mRclk.pin, false);
		mRclk.port->setOutput(mRclk.pin, true);
	}
	mPeri->enable(false);
	mPeri->unlock();
}

void SN74LV595A::set(uint8_t *data, uint8_t size)
{
	mPeri->lock();
	mPeri->setSpecification(gConfig);
	mPeri->enable(true);
	mPeri->send((int8_t *)data, size);
	if(mRclk.port)
	{
		mRclk.port->setOutput(mRclk.pin, false);
		mRclk.port->setOutput(mRclk.pin, true);
	}
	mPeri->enable(false);
	mPeri->unlock();
}

void SN74LV595A::setOutputEn(bool en)
{
	if (mRclk.port)
		mRclk.port->setOutput(mRclk.pin, !en);
}

#endif