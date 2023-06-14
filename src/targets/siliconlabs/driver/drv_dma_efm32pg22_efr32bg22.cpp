////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(EFM32PG22) || defined(EFR32BG22)

#include <drv/Dma.h>
#include <yss/reg.h>
#include <yss/thread.h>

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_ldma.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_ldma.h>
#endif

Dma::Dma(const Drv::Config drvConfig, const Config dmaConfig) : Drv(drvConfig)
{
	mDma = dmaConfig.dma;
	mPeri = dmaConfig.peri;
	mSrc = dmaConfig.src;
	mCompleteFlag = false;
	mErrorFlag = false;
	mAddr = 0;
	mRemainSize = 0;
	mChannelNumber = dmaConfig.channelNumber;
}

void Dma::initialize(void)
{
	mDma->EN_SET = _LDMA_EN_EN_MASK;
	mDma->IEN_SET = _LDMA_IEN_MASK;
}

error Dma::transfer(DmaInfo &dmaInfo, void *data, int32_t count)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadId();
	
	mSrc->REQSEL = dmaInfo.controlRegister3 & 0x7FFFFFFF;

	if(dmaInfo.controlRegister3 & 0x80000000) // Memory -> Peripheral
	{
		mPeri->DST = (uint32_t)dmaInfo.dataRegister;
		mPeri->SRC = (uint32_t)data;
	}
	else // Peripheral -> Memory
	{
		mPeri->SRC = (uint32_t)dmaInfo.dataRegister;
		mPeri->DST = (uint32_t)data;
	}

	if (count > 2047)
	{
		mRemainSize = count - 2047;
		mPeri->CTRL = dmaInfo.controlRegister1 | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
	}
	else
	{
		mRemainSize = 0;
		mPeri->CTRL = dmaInfo.controlRegister1 | count << _LDMA_CH_CTRL_XFERCNT_SHIFT;
	}
	
	mPeri->CFG = dmaInfo.controlRegister2;
	mDma->CHEN_SET = 1 << mChannelNumber;

	while (!mCompleteFlag && !mErrorFlag)
		thread::yield();

	if(mErrorFlag)
		return error::DMA;
	else
		return error::ERROR_NONE;
}

DmaChannel1::DmaChannel1(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel1::isr(void)
{
	mDma->IF_CLR = 1 << mChannelNumber;
	mDma->CHDONE_CLR = 1 << mChannelNumber;

	if (mRemainSize)
	{
		if (mRemainSize > 2047)
		{
			mPeri->CTRL = mPeri->CTRL | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize -= 2047;
		}
		else
		{
			mPeri->CTRL = mPeri->CTRL | mRemainSize << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize = 0;
		}

		mDma->CHEN_SET = 1 << mChannelNumber;
	}
	else
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
}


DmaChannel2::DmaChannel2(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel2::isr(void)
{
	mDma->IF_CLR = 1 << mChannelNumber;
	mDma->CHDONE_CLR = 1 << mChannelNumber;

	if (mRemainSize)
	{
		if (mRemainSize > 2047)
		{
			mPeri->CTRL = mPeri->CTRL | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize -= 2047;
		}
		else
		{
			mPeri->CTRL = mPeri->CTRL | mRemainSize << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize = 0;
		}

		mDma->CHEN_SET = 1 << mChannelNumber;
	}
	else
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
}



DmaChannel3::DmaChannel3(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel3::isr(void)
{
	mDma->IF_CLR = 1 << mChannelNumber;
	mDma->CHDONE_CLR = 1 << mChannelNumber;

	if (mRemainSize)
	{
		if (mRemainSize > 2047)
		{
			mPeri->CTRL = mPeri->CTRL | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize -= 2047;
		}
		else
		{
			mPeri->CTRL = mPeri->CTRL | mRemainSize << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize = 0;
		}

		mDma->CHEN_SET = 1 << mChannelNumber;
	}
	else
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
}



DmaChannel4::DmaChannel4(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel4::isr(void)
{
	mDma->IF_CLR = 1 << mChannelNumber;
	mDma->CHDONE_CLR = 1 << mChannelNumber;

	if (mRemainSize)
	{
		if (mRemainSize > 2047)
		{
			mPeri->CTRL = mPeri->CTRL | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize -= 2047;
		}
		else
		{
			mPeri->CTRL = mPeri->CTRL | mRemainSize << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize = 0;
		}

		mDma->CHEN_SET = 1 << mChannelNumber;
	}
	else
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
}



DmaChannel5::DmaChannel5(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel5::isr(void)
{
	mDma->IF_CLR = 1 << mChannelNumber;
	mDma->CHDONE_CLR = 1 << mChannelNumber;

	if (mRemainSize)
	{
		if (mRemainSize > 2047)
		{
			mPeri->CTRL = mPeri->CTRL | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize -= 2047;
		}
		else
		{
			mPeri->CTRL = mPeri->CTRL | mRemainSize << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize = 0;
		}

		mDma->CHEN_SET = 1 << mChannelNumber;
	}
	else
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
}



DmaChannel6::DmaChannel6(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel6::isr(void)
{
	mDma->IF_CLR = 1 << mChannelNumber;
	mDma->CHDONE_CLR = 1 << mChannelNumber;

	if (mRemainSize)
	{
		if (mRemainSize > 2047)
		{
			mPeri->CTRL = mPeri->CTRL | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize -= 2047;
		}
		else
		{
			mPeri->CTRL = mPeri->CTRL | mRemainSize << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize = 0;
		}

		mDma->CHEN_SET = 1 << mChannelNumber;
	}
	else
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
}



DmaChannel7::DmaChannel7(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel7::isr(void)
{
	mDma->IF_CLR = 1 << mChannelNumber;
	mDma->CHDONE_CLR = 1 << mChannelNumber;

	if (mRemainSize)
	{
		if (mRemainSize > 2047)
		{
			mPeri->CTRL = mPeri->CTRL | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize -= 2047;
		}
		else
		{
			mPeri->CTRL = mPeri->CTRL | mRemainSize << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize = 0;
		}

		mDma->CHEN_SET = 1 << mChannelNumber;
	}
	else
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
}



DmaChannel8::DmaChannel8(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel8::isr(void)
{
	mDma->IF_CLR = 1 << mChannelNumber;
	mDma->CHDONE_CLR = 1 << mChannelNumber;

	if (mRemainSize)
	{
		if (mRemainSize > 2047)
		{
			mPeri->CTRL = mPeri->CTRL | 2047 << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize -= 2047;
		}
		else
		{
			mPeri->CTRL = mPeri->CTRL | mRemainSize << _LDMA_CH_CTRL_XFERCNT_SHIFT;
			mRemainSize = 0;
		}

		mDma->CHEN_SET = 1 << mChannelNumber;
	}
	else
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
}

#endif

