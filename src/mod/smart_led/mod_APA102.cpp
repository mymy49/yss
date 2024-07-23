/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/smart_led/APA102.h>
#include <util/ElapsedTime.h>
#include <yss/thread.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

static const Spi::specification_t ledSpec = 
{
	Spi::MODE_MODE0,	//int8_t mode;
	1000000,					//int32_t  maxFreq;
	Spi::BIT_BIT8		//int8_t bit;
};

APA102::APA102(void)
{
	mPeri = 0;
	mData = 0;
	mLedCount = 0;
	mDataCount = 0;
}

error_t APA102::initialize(Config config)
{
	uint32_t *des;

	mDataCount = 8 * config.ledCount + 4;
	mData = new uint8_t[mDataCount];

	if(mData == 0)
		return error_t::MALLOC_FAILED;
	
	mLedCount = config.ledCount;
	
	des = (uint32_t*)mData;
	*des++ = 0x00000000;

	des = (uint32_t*)&mData[4 + 4 * config.ledCount];
	for(uint32_t i=0;i<config.ledCount;i++)
		*des++ = 0xFFFFFFFF;

	mPeri = &config.spi;

	for(uint16_t i=0;i<mLedCount;i++)
	{
		setRgb(i, 0, 0, 0);
		setBrightness(i, 31);
	}

	refresh();

	return error_t::ERROR_NONE;
}

error_t APA102::setRgb(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
{
	if(index >= mLedCount)
		return error_t::OUT_OF_RANGE;
	
	uint8_t *des = &mData[4 + index * 4 + 1];

	*des++ = b;
	*des++ = g;
	*des++ = r;

	return error_t::ERROR_NONE;
}

error_t APA102::setRgb(uint8_t r, uint8_t g, uint8_t b)
{
	for(uint16_t i=0;i<mLedCount;i++)
		setRgb(i, r, g, b);

	return error_t::ERROR_NONE;
}

error_t APA102::setBrightness(uint16_t index, uint8_t brightness)
{
	if(index >= mLedCount)
		return error_t::OUT_OF_RANGE;
	
	mData[4 + index * 4] = (brightness & 0x1F) | 0xE0;

	return error_t::ERROR_NONE;
}

error_t APA102::setBrightness(uint8_t brightness)
{
	for(uint16_t i=0;i<mLedCount;i++)
		setBrightness(i, brightness);

	return error_t::ERROR_NONE;
}

void APA102::refresh(void)
{
	mPeri->lock();
	mPeri->setSpecification(ledSpec);
	mPeri->enable(true);
	mPeri->send(mData, mDataCount);
	mPeri->enable(false);
	mPeri->unlock();
}

#endif

