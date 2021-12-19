////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2020.02.12 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/logic/SN74LV166A.h>
#include <yss/malloc.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

static config::spi::Config gConfig =
	{
		define::spi::mode::MODE0,
		4500000};

SN74LV166A::SN74LV166A(void)
{
	mData = 0;
	mShLd.port = 0;
	mClkInh.port = 0;
	mClr.port = 0;
	mPeri = 0;
	mDepth = 0;
}

bool SN74LV166A::init(const Config config)
{
	if (config.depth == 0)
		return false;

#if YSS_L_HEAP_USE == true
	mData = (unsigned char *)lmalloc(depth);
#elif YSS_C_HEAP_USE == true
	mData = (unsigned char *)cmalloc(depth);
#elif YSS_H_HEAP_USE == true
	mData = (unsigned char *)hmalloc(config.depth);
#endif
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
	mPeri->setConfig(gConfig);

	if (mClkInh.port)
		mClkInh.port->setOutput(mClkInh.pin, false);
	if (mShLd.port)
		mShLd.port->setOutput(mShLd.pin, false);
	mPeri->exchange(0);
	if (mShLd.port)
		mShLd.port->setOutput(mShLd.pin, true);

	for (unsigned char i = 0; i < mDepth; i++)
		mData[i] = mPeri->exchange(mData[i]);

	if (mClkInh.port)
		mClkInh.port->setOutput(mClkInh.pin, true);
	mPeri->unlock();

	return true;
}

unsigned char SN74LV166A::get(unsigned char index)
{
	if (index < mDepth)
		return mData[index];
	else
		return 0;
}

#endif