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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2020.02.12 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/logic/SN74LV166A.h>
#include <yss/malloc.h>

#if !defined(SPI_NOT_DEFINED)

namespace mod
{
namespace logic
{
	static config::spi::Config gConfig =
	{
		define::spi::mode::MODE0,
		4500000
	};

	SN74LV166A::SN74LV166A(void)
	{
        mData = 0;
		reset();
	}

	void SN74LV166A::reset(void)
	{
		mShLd.port = 0;
		mClkInh.port = 0;
		mClr.port = 0;
		mPeri = 0;
        mDepth = 0;
		if(mData)
#if YSS_L_HEAP_USE == true
			lfree(mData);
#elif YSS_C_HEAP_USE == true
			cfree(mData);
#else
			hfree(mData);
#endif
        mData = 0;
	}

	void SN74LV166A::setShLd(bool en)
	{
		if(mShLd.port)
			mShLd.port->setOutput(mShLd.pin, en);
	}

	void SN74LV166A::setClkInh(bool en)
	{
		if(mClkInh.port)
			mClkInh.port->setOutput(mClkInh.pin, en);
	}

	void SN74LV166A::setClr(bool en)
	{
		if(mClr.port)
			mClr.port->setOutput(mClr.pin, en);
	}

	bool SN74LV166A::init(drv::Spi &spi, unsigned char depth, config::gpio::Set &clkInh, config::gpio::Set &shLd, config::gpio::Set &clr)
	{
		if(depth == 0)
		{	
			reset();
			return false;
		}

#if YSS_L_HEAP_USE == true
		mData = (unsigned char*)lmalloc(depth);
#elif YSS_C_HEAP_USE == true
		mData = (unsigned char*)cmalloc(depth);
#else
		mData = (unsigned char*)hmalloc(depth);
#endif
		if(mData == 0)
		{
			reset();
			return false;
		}
		
		mPeri = &spi;
		mDepth = depth;
		mShLd = shLd;
		mClkInh = clkInh;
		mClr = clr;

		setClkInh(true);
        setShLd(true);
		setClr(false);
		setClr(true);

		return true;
	}

	bool SN74LV166A::refresh(void)
	{
		mPeri->lock();
		mPeri->setConfig(gConfig);

		setClkInh(false);
        setShLd(false);
        mPeri->exchange(0);
		setShLd(true);

		for(unsigned char i=0;i<mDepth;i++)
			mData[i] = mPeri->exchange(mData[i]);

		setClkInh(true);
		mPeri->unlock();

		return true;
	}

	unsigned char SN74LV166A::get(unsigned char index)
	{
		if(index < mDepth)
			return mData[index];
		else
			return 0;
	}
}
}

#endif
