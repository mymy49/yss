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

#include <mod/logic/SN74LV166A.h>
#include <std_ext/malloc.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

static const Spi::Specification gConfig =
{
	define::spi::mode::MODE0,
	35000000,
	define::spi::bit::BIT8
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