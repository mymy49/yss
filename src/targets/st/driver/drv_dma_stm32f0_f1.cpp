/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F030xC) || defined(GD32F1) || defined (STM32F1)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <util/ElapsedTime.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/st/bitfield.h>

#define checkError(sr) (sr & 0x08)
#define checkComplete(sr) (sr & 0x03)

#if defined(STM32F030xC)
static Mutex gMutex;
#endif

Dma::Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup) : Drv(drvSetup)
{
	mDma = dmaSetup.dma;
	mChannel = dmaSetup.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mAddr = 0;
	mRemainSize = 0;
}

void Dma::initialize(void)
{
}

error_t Dma::ready(dmaInfo_t &dmaInfo, void *buffer, int32_t  size)
{
	if(size == 0)
		return error_t::NO_DATA;

	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadId();

	if (size > 0xF000)
	{
		mChannel->CPAR = (uint32_t)dmaInfo.dataRegister;
		mChannel->CNDTR = 0xF000;
		mChannel->CMAR = (uint32_t)buffer;
		mAddr = (uint32_t)buffer;
		mRemainSize = size - 0xF000;
#if defined(STM32F030xC)
		gMutex.lock();
		mDma->CSELR &= ~dmaInfo.controlRegister2;
		mDma->CSELR |= dmaInfo.controlRegister3;
		gMutex.unlock();
#endif
		mChannel->CCR = dmaInfo.controlRegister1;
	}
	else
	{
		mChannel->CPAR = (uint32_t)dmaInfo.dataRegister;
		mChannel->CNDTR = size;
		mChannel->CMAR = (uint32_t)buffer;
		mRemainSize = 0;
#if defined(STM32F030xC)
		gMutex.lock();
		mDma->CSELR &= ~dmaInfo.controlRegister2;
		mDma->CSELR |= dmaInfo.controlRegister3;
		gMutex.unlock();
#endif
		mChannel->CCR = dmaInfo.controlRegister1;
	}

	return error_t::ERROR_NONE;
}

error_t Dma::transfer(dmaInfo_t &dmaInfo, void *src, int32_t  size)
{
	uint32_t addr = (uint32_t)src;

	if(size == 0)
		return error_t::NO_DATA;

	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadId();
	
	if (size > 0xF000)
	{
		mChannel->CPAR = (uint32_t)dmaInfo.dataRegister;
		mChannel->CNDTR = 0xF000;
		mChannel->CMAR = addr;
		mAddr = addr;
		mRemainSize = size - 0xF000;
#if defined(STM32F030xC)
		gMutex.lock();
		mDma->CSELR &= ~dmaInfo.controlRegister2;
		mDma->CSELR |= dmaInfo.controlRegister3;
		gMutex.unlock();
#endif
		mChannel->CCR = dmaInfo.controlRegister1;
	}
	else
	{
		mChannel->CPAR = (uint32_t)dmaInfo.dataRegister;
		mChannel->CNDTR = size;
		mChannel->CMAR = addr;
		mRemainSize = 0;
#if defined(STM32F030xC)
		gMutex.lock();
		mDma->CSELR &= ~dmaInfo.controlRegister2;
		mDma->CSELR |= dmaInfo.controlRegister3;
		gMutex.unlock();
#endif
		mChannel->CCR = dmaInfo.controlRegister1;
	}

	while (!mCompleteFlag && !mErrorFlag && mChannel->CNDTR)
	{
		thread::yield();
	}
	
	mChannel->CCR &= ~DMA_CCR_EN_Msk;

	if(mErrorFlag)
		return error_t::DMA_ERROR;
	else
		return error_t::ERROR_NONE;
}

void Dma::stop(void)
{
	mChannel->CCR &= ~DMA_CCR_EN_Msk;
}

bool Dma::isError(void)
{
	return mErrorFlag;
}

bool Dma::isComplete(void)
{
	return mCompleteFlag;
}

DmaChannel1::DmaChannel1(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel1::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 0, 0);
	setFieldData(mDma->IFCR, 0xF << 0, sr, 0);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
	
	thread::signal(mThreadId);
}

DmaChannel2::DmaChannel2(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel2::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 4, 4);
	setFieldData(mDma->IFCR, 0xF << 4, sr, 4);

	if (checkError(sr))
		mErrorFlag = true;
	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel3::DmaChannel3(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel3::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 8, 8);
	setFieldData(mDma->IFCR, 0xF << 8, sr, 8);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mChannel->CCR &= ~DMA_CCR_EN_Msk;
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel4::DmaChannel4(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel4::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 12, 12);
	mDma->IFCR = sr << 12;

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel5::DmaChannel5(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel5::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 16, 16);
	mDma->IFCR = sr << 16;

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel6::DmaChannel6(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel6::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 20, 20);
	setFieldData(mDma->IFCR, 0xF << 20, sr, 20);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel7::DmaChannel7(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel7::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 24, 24);
	setFieldData(mDma->IFCR, 0xF << 24, sr, 24);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel8::DmaChannel8(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel8::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 0, 0);
	setFieldData(mDma->IFCR, 0xF << 0, sr, 0);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel9::DmaChannel9(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel9::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 4, 4);
	setFieldData(mDma->IFCR, 0xF << 4, sr, 4);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel10::DmaChannel10(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel10::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 8, 8);
	setFieldData(mDma->IFCR, 0xF << 8, sr, 8);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel11::DmaChannel11(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel11::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 12, 12);
	setFieldData(mDma->IFCR, 0xF << 12, sr, 12);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel12::DmaChannel12(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel12::isr(void)
{
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 16, 16);
	setFieldData(mDma->IFCR, 0xF << 16, sr, 16);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mChannel->CNDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mChannel->CNDTR = mRemainSize;
			mRemainSize = 0;
		}

		mChannel->CMAR = mAddr;
		mChannel->CCR |= DMA_CCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}

#endif

