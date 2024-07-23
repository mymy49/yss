/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/logic/SN74LV166A.h>
#include <std_ext/malloc.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

static const Spi::specification_t gConfig =
{
	Spi::MODE_MODE0,
	35000000,
	Spi::BIT_BIT8
};

SN74LV166A::SN74LV166A(void)
{
	mData = 0;
	mShLd.port = 0;
	mClkInh.port = 0;
	mClr.port = 0;
	mPeri = 0;
	mDepth = 0;
}

bool SN74LV166A::initialize(const Config config)
{
	if (config.depth == 0)
		return false;
	
	if(mData)
		delete mData;

	mData = new uint8_t[config.depth];
	if (mData == 0)
		return false;

	mPeri = &config.spi;
	mDepth = config.depth;
	mShLd = config.SH_LD;
	mClkInh = config.CLK_INH;
	mClr = config.CLR;

	if (mShLd.port)
		mShLd.port->setOutput(mShLd.pin, true);
	if (mClkInh.port)
		mClkInh.port->setOutput(mClkInh.pin, true);
	if (mClr.port)
	{
		mClr.port->setOutput(mClr.pin, false);
		mClr.port->setOutput(mClr.pin, true);
	}

	return true;
}

bool SN74LV166A::refresh(void)
{
	mPeri->lock();
	mPeri->setSpecification(gConfig);
	mPeri->enable(true);

	if (mClkInh.port)
		mClkInh.port->setOutput(mClkInh.pin, false);
	if (mShLd.port)
		mShLd.port->setOutput(mShLd.pin, false);
	mPeri->exchange(0);
	if (mShLd.port)
		mShLd.port->setOutput(mShLd.pin, true);

	for (uint8_t i = 0; i < mDepth; i++)
		mData[i] = mPeri->exchange(mData[i]);

	if (mClkInh.port)
		mClkInh.port->setOutput(mClkInh.pin, true);
	mPeri->enable(false);
	mPeri->unlock();

	return true;
}

uint8_t SN74LV166A::get(uint8_t index)
{
	if (index < mDepth)
		return mData[index];
	else
		return 0;
}

#endif