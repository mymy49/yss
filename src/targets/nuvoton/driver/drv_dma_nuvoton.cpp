/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <util/ElapsedTime.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/nuvoton/bitfield_m4xx.h>

Dma::Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup) : Drv(drvSetup)
{
	mDma = dmaSetup.dma;
	mPeri = dmaSetup.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mAddr = 0;
	mRemainSize = 0;
	mSrcNum = 0;
	mChNum = 0;
}

void Dma::initialize(void)
{
	mDma->CHCTL = 0xFFFF;
	for(uint32_t i = 0; i < 16; i++)
		mPeri[i].CTL = 0;

	mDma->INTEN = 0xFFFF;
}

error_t Dma::transfer(dmaInfo_t &dmaInfo, void *src, int32_t count)
{
	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14));

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mThreadId = thread::getCurrentThreadId();

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mPeri->DA = (uint32_t)dmaInfo.cpar;
		mPeri->SA = (uint32_t)src;
	}
	else // Peripheral -> Memory
	{
		mPeri->SA = (uint32_t)dmaInfo.cpar;
		mPeri->DA = (uint32_t)src;
	}

	if (count > 0xFFFF)
	{
		ctl |= (0xFFFF - 1) << 16;
		mAddr = (uint32_t)src;
		mRemainSize = count - 0xFFFF;
	}
	else
	{
		ctl |= (count - 1) << 16;
		mRemainSize = 0;
	}

	mPeri->CTL = ctl;

	mDma->SWREQ |= 1 << mChNum;

	while(!mCompleteFlag)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t Dma::ready(dmaInfo_t &dmaInfo, void *src, int32_t  count)
{
	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14));

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mThreadId = thread::getCurrentThreadId();

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mPeri->DA = (uint32_t)dmaInfo.cpar;
		mPeri->SA = (uint32_t)src;
	}
	else // Peripheral -> Memory
	{
		mPeri->SA = (uint32_t)dmaInfo.cpar;
		mPeri->DA = (uint32_t)src;
	}

	if (count > 0xFFFF)
	{
		ctl |= (0xFFFF - 1) << 16;
		mAddr = (uint32_t)src;
		mRemainSize = count - 0xFFFF;
	}
	else
	{
		ctl |= (count - 1) << 16;
		mRemainSize = 0;
	}

	mPeri->CTL = ctl;

//	if(mSrcNum == 0)
//		mDma->SWREQ |= 1 << mChNum;

	return error_t::ERROR_NONE;
}

error_t Dma::transferAsCircularMode(const dmaInfo_t &dmaInfo, void *src, uint16_t count)
{
	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14));

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = true;
	mThreadId = thread::getCurrentThreadId();

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mPeri->DA = (uint32_t)dmaInfo.cpar;
		mPeri->SA = (uint32_t)src;
	}
	else // Peripheral -> Memory
	{
		mPeri->SA = (uint32_t)dmaInfo.cpar;
		mPeri->DA = (uint32_t)src;
	}

	ctl |= (count - 1) << 16;
	mRemainSize = count;

	mPeri->CTL = ctl;

	mDma->SWREQ |= 1 << mChNum;

	return error_t::ERROR_NONE;
}

uint16_t Dma::getCurrentTransferBufferCount(void)
{
	return mPeri->CTL >> 16;
}

void Dma::stop(void)
{

}

bool Dma::isError(void)
{
	return mErrorFlag;
}

bool Dma::isComplete(void)
{
	return mCompleteFlag;
}

// Nuvoton의 DMA는 일시적으로 done 관련 처리만 할 예정
// 운영간 문제가 생기면 관련 예외처리가 추가될 예정
void Dma::isr(void)
{
	uint32_t ctl = mPeri->CTL & 0x0000FFFF;
	
	if(mCircularModeFlag)
	{
		ctl |= ((mRemainSize - 1) << 16) | PDMA_OP_BASIC;
		mPeri->CTL = ctl;

		mDma->SWREQ |= 1 << mChNum;
	}
	else if(mRemainSize)
	{
		if (mRemainSize > 0xFFFF)
		{
			ctl |= ((0xFFFF - 1) << 16) | PDMA_OP_BASIC;
			mRemainSize = mRemainSize - 0xFFFF;
		}
		else
		{
			ctl |= ((mRemainSize - 1) << 16) | PDMA_OP_BASIC;
			mRemainSize = 0;
		}
		
		mPeri->SA += 0xFFFF;
		mPeri->DA += 0xFFFF;
		mPeri->CTL = ctl;

		mDma->SWREQ |= 1 << mChNum;
	}
	else
	{
		mCompleteFlag = true;
	}
	
	thread::signal(mThreadId);
}

DmaChannel1::DmaChannel1(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 0;
}

void DmaChannel1::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC0_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC0_Pos;
	__enable_irq();
}

DmaChannel2::DmaChannel2(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 1;
}

void DmaChannel2::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC1_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC1_Pos;
	__enable_irq();
}

DmaChannel3::DmaChannel3(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 2;
}

void DmaChannel3::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC2_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC2_Pos;
	__enable_irq();
}

DmaChannel4::DmaChannel4(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 3;
}

void DmaChannel4::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC3_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC3_Pos;
	__enable_irq();
}

#endif

