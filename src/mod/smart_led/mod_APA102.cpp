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

#include <mod/smart_led/APA102.h>
#include <util/ElapsedTime.h>
#include <yss/thread.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

static const Spi::Specification ledSpec = 
{
	define::spi::mode::MODE0,	//int8_t mode;
	1000000,					//int32_t  maxFreq;
	define::spi::bit::BIT8		//int8_t bit;
};

APA102::APA102(void)
{
	mPeri = 0;
	mData = 0;
	mLedCount = 0;
	mDataCount = 0;
}

error APA102::initialize(Config config)
{
	uint32_t *des;

	mDataCount = 8 * config.ledCount + 4;
	mData = new uint8_t[mDataCount];

	if(mData == 0)
		return error::MALLOC_FAILED;
	
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

	return error::ERROR_NONE;
}

error APA102::setRgb(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
{
	if(index >= mLedCount)
		return error::OUT_OF_RANGE;
	
	uint8_t *des = &mData[4 + index * 4 + 1];

	*des++ = b;
	*des++ = g;
	*des++ = r;

	return error::ERROR_NONE;
}

error APA102::setRgb(uint8_t r, uint8_t g, uint8_t b)
{
	for(uint16_t i=0;i<mLedCount;i++)
		setRgb(i, r, g, b);

	return error::ERROR_NONE;
}

error APA102::setBrightness(uint16_t index, uint8_t brightness)
{
	if(index >= mLedCount)
		return error::OUT_OF_RANGE;
	
	mData[4 + index * 4] = (brightness & 0x1F) | 0xE0;

	return error::ERROR_NONE;
}

error APA102::setBrightness(uint8_t brightness)
{
	for(uint16_t i=0;i<mLedCount;i++)
		setBrightness(i, brightness);

	return error::ERROR_NONE;
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

