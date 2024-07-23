/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

Dma::Dma(const Drv::setup_t drvConfig, const Config dmaConfig) : Drv(drvConfig)
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

error Dma::transfer(dmaInfo_t &dmaInfo, void *data, int32_t count)
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

DmaChannel1::DmaChannel1(const Drv::setup_t drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
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


DmaChannel2::DmaChannel2(const Drv::setup_t drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
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



DmaChannel3::DmaChannel3(const Drv::setup_t drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
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



DmaChannel4::DmaChannel4(const Drv::setup_t drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
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



DmaChannel5::DmaChannel5(const Drv::setup_t drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
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



DmaChannel6::DmaChannel6(const Drv::setup_t drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
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



DmaChannel7::DmaChannel7(const Drv::setup_t drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
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



DmaChannel8::DmaChannel8(const Drv::setup_t drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
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

