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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32G4)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <util/ElapsedTime.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/st/bitfield.h>

#define checkError(sr) (sr & 0x08)
#define checkComplete(sr) (sr & 0x03)

static Mutex gMutex;

Dma::Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup) : Drv(drvSetup)
{
	mDma = dmaSetup.dma;
	mChannel = dmaSetup.channel;
	mDmaMux = dmaSetup.dmamux;
	mCompleteFlag = false;
	mErrorFlag = false;
	mAddr = 0;
	mRemainSize = 0;
}

void Dma::initialize(void)
{
}

error Dma::ready(DmaInfo &dmaInfo, void *buffer, int32_t  size)
{
	if(size == 0)
		return error::ERROR_NONE;

	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadId();

	if (size > 0xF000)
	{
		mChannel->CPAR = (uint32_t)dmaInfo.cpar;
		mChannel->CNDTR = 0xF000;
		mChannel->CMAR = (uint32_t)buffer;
		mAddr = (uint32_t)buffer;
		mRemainSize = size - 0xF000;
		mChannel->CCR = dmaInfo.ccr;
	}
	else
	{
		mChannel->CPAR = (uint32_t)dmaInfo.cpar;
		mChannel->CNDTR = size;
		mChannel->CMAR = (uint32_t)buffer;
		mRemainSize = 0;
		mChannel->CCR = dmaInfo.ccr;
	}

	return error::ERROR_NONE;
}

error Dma::transfer(DmaInfo &dmaInfo, void *src, int32_t  size)
{
	uint32_t addr = (uint32_t)src;

	if(size == 0)
		return error::ERROR_NONE;

	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadId();
	
	if (size > 0xF000)
	{
		mChannel->CPAR = (uint32_t)dmaInfo.cpar;
		mChannel->CNDTR = 0xF000;
		mChannel->CMAR = addr;
		mAddr = addr;
		mRemainSize = size - 0xF000;
		mChannel->CCR = dmaInfo.ccr;
		mDmaMux->CCR = dmaInfo.muxccr;
	}
	else
	{
		mChannel->CPAR = (uint32_t)dmaInfo.cpar;
		mChannel->CNDTR = size;
		mChannel->CMAR = addr;
		mRemainSize = 0;
		mChannel->CCR = dmaInfo.ccr;
		mDmaMux->CCR = dmaInfo.muxccr;
	}

	mChannel->CCR |= DMA_CCR_EN_Msk;

	while (!mCompleteFlag && !mErrorFlag && mChannel->CNDTR)
	{
		thread::yield();
	}
	
	mChannel->CCR &= ~DMA_CCR_EN_Msk;

	if(mErrorFlag)
		return error::DMA;
	else
		return error::ERROR_NONE;
}

void Dma::transferAsCircularMode(const DmaInfo *dmaInfo, void *src, uint16_t  size)
{
	mChannel->CNDTR = size;
	mChannel->CPAR = (uint32_t)dmaInfo->cpar;
	mChannel->CMAR = (uint32_t)src;
	mRemainSize = 0;
	mThreadId = -1;
	
	mChannel->CCR = dmaInfo->ccr;
	mDmaMux->CCR = dmaInfo->muxccr;
	mChannel->CCR |= DMA_CCR_EN_Msk;
}

uint16_t Dma::getCurrentTransferBufferCount(void)
{
	return mChannel->CNDTR;
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
	register uint32_t sr = getFieldData(mDma->ISR, 0xF << 28, 28);
	setFieldData(mDma->IFCR, 0xF << 28, sr, 28);

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



DmaChannel10::DmaChannel10(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel10::isr(void)
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



DmaChannel11::DmaChannel11(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel11::isr(void)
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



DmaChannel12::DmaChannel12(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel12::isr(void)
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



DmaChannel13::DmaChannel13(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel13::isr(void)
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



DmaChannel14::DmaChannel14(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel14::isr(void)
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



DmaChannel15::DmaChannel15(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel15::isr(void)
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



DmaChannel16::DmaChannel16(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel16::isr(void)
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

#endif

