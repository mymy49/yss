/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <util/ElapsedTime.h>
#include <yss/reg.h>
#include <yss/thread.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include <targets/nuvoton/bitfield_m4xx.h>
#elif defined(__M2xx_FAMILY)
#include <targets/nuvoton/bitfield_m2xx.h>
#endif

Dma::Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup) : Drv(drvSetup)
{
	mDma = dmaSetup.dma;
	mChannel = dmaSetup.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mAddr = 0;
	mRemainSize = 0;
	mSrcNum = 0;
	mChNum = 0;
	mMainChannel.NEXT = (uint32_t)&mSubChannel;
	mSubChannel.NEXT = (uint32_t)&mMainChannel;
}

void Dma::initialize(void)
{
	mDma->CHCTL = 0xFFFF;
	for(uint32_t i = 0; i < 16; i++)
		mChannel[i].CTL = 0;

	mDma->INTEN = 0xFFFF;
}

error_t Dma::transfer(dmaInfo_t &dmaInfo, void *src, int32_t count)
{
	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14));

	ctl |= PDMA_OP_BASIC;
	ctl &= ~PDMA_OP_SCATTER;

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mThreadId = thread::getCurrentThreadId();

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mChannel->DA = (uint32_t)dmaInfo.cpar;
		mChannel->SA = (uint32_t)src;
	}
	else // Peripheral -> Memory
	{
		mChannel->SA = (uint32_t)dmaInfo.cpar;
		mChannel->DA = (uint32_t)src;
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

	mChannel->CTL = ctl;

	mDma->SWREQ |= 1 << mChNum;

	while(!mCompleteFlag)
		thread::yield();

	return error_t::ERROR_NONE;
}

void Dma::trigger(void)
{
	mDma->SWREQ |= 1 << mChNum;
}

error_t Dma::ready(dmaInfo_t &dmaInfo, void *src, int32_t count)
{
	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14));

	ctl |= PDMA_OP_BASIC;
	ctl &= ~PDMA_OP_SCATTER;

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mThreadId = thread::getCurrentThreadId();

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mChannel->DA = (uint32_t)dmaInfo.cpar;
		mChannel->SA = (uint32_t)src;
	}
	else // Peripheral -> Memory
	{
		mChannel->SA = (uint32_t)dmaInfo.cpar;
		mChannel->DA = (uint32_t)src;
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

	mChannel->CTL = ctl;

	return error_t::ERROR_NONE;
}

error_t Dma::transferAsCircularMode(const dmaInfo_t &dmaInfo, void *src, uint16_t count)
{
	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14)), src1, src2;

	ctl &= ~PDMA_OP_BASIC;
	ctl |= PDMA_OP_SCATTER;

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = true;
	mThreadId = thread::getCurrentThreadId();

	switch(dmaInfo.ctl & (PDMA_WIDTH_16 | PDMA_WIDTH_32))
	{
	case PDMA_WIDTH_8 :
		src1 = (uint32_t)src;
		src2 = (uint32_t)&((uint8_t*)src)[count / 2];
		break;
	case PDMA_WIDTH_16 : 
		src1 = (uint32_t)src;
		src2 = (uint32_t)&((uint16_t*)src)[count / 2];
		break;
	case PDMA_WIDTH_32 :
		src1 = (uint32_t)src;
		src2 = (uint32_t)&((uint32_t*)src)[count / 2];
		break;
	default :
		return error_t::WRONG_CONFIG;
	}

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mMainChannel.DA = (uint32_t)dmaInfo.cpar;
		mSubChannel.DA = (uint32_t)dmaInfo.cpar;
		mMainChannel.SA = src1;
		mSubChannel.SA = src2;
	}
	else // Peripheral -> Memory
	{
		mMainChannel.SA = (uint32_t)dmaInfo.cpar;
		mSubChannel.SA = (uint32_t)dmaInfo.cpar;
		mMainChannel.DA = src1;
		mSubChannel.DA = src2;
	}

	mMainChannel.CTL = ctl | (count / 2 - 1) << 16;
	mSubChannel.CTL = ctl | (count / 2 - 1) << 16;
	*mChannel = mMainChannel;

	mDma->SWREQ |= 1 << mChNum;

	return error_t::ERROR_NONE;
}

uint16_t Dma::getRemainingTransferCount(void)
{
	return mChannel->CTL >> 16;
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

uint16_t Dma::getCircularModeSentCount(void)
{
	return mCircularSentCnt;
}

void* Dma::getCircularModePreviouslyTransmittedDataBuffer(void)
{
	if(mMainChannel.CTL & 1 << 14)
	{
		switch(mCircularSentCnt % 2)
		{
		case 0 :
			return (void*)mSubChannel.DA;
		case 1 :
			return (void*)mMainChannel.DA;
		}
	}
	else
	{
		switch(mCircularSentCnt % 2)
		{
		case 0 :
			return (void*)mSubChannel.SA;
		case 1 :
			return (void*)mMainChannel.SA;
		}
	}

	return 0;
}

// Nuvoton의 DMA는 일시적으로 done 관련 처리만 할 예정
// 운영간 문제가 생기면 관련 예외처리가 추가될 예정
void Dma::isr(void)
{
	uint32_t ctl = mChannel->CTL & 0x0000FFFF;
	
	if(mCircularModeFlag)
	{
		mCircularSentCnt++;
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
		
		mChannel->SA += 0xFFFF;
		mChannel->DA += 0xFFFF;
		mChannel->CTL = ctl;
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

DmaChannel5::DmaChannel5(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 4;
}

void DmaChannel5::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC4_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC4_Pos;
	__enable_irq();
}

DmaChannel6::DmaChannel6(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 5;
}

void DmaChannel6::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC5_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC5_Pos;
	__enable_irq();
}

DmaChannel7::DmaChannel7(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 6;
}

void DmaChannel7::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC6_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC6_Pos;
	__enable_irq();
}

DmaChannel8::DmaChannel8(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 7;
}

void DmaChannel8::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC7_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC7_Pos;
	__enable_irq();
}

#if defined(PDMA_REQSEL8_11_REQSRC8_Msk)
DmaChannel9::DmaChannel9(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 8;
}

void DmaChannel9::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC8_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC8_Pos;
	__enable_irq();
}
#endif


#if defined(PDMA_REQSEL8_11_REQSRC9_Msk)
DmaChannel10::DmaChannel10(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 9;
}

void DmaChannel10::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC9_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC9_Pos;
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL8_11_REQSRC10_Msk)
DmaChannel11::DmaChannel11(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 10;
}

void DmaChannel11::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC10_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC10_Pos;
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL8_11_REQSRC11_Msk)
DmaChannel12::DmaChannel12(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 11;
}

void DmaChannel12::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC11_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC11_Pos;
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL12_15_REQSRC12_Msk)
DmaChannel13::DmaChannel13(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 12;
}

void DmaChannel13::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC12_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC12_Pos;
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL12_15_REQSRC13_Msk)
DmaChannel14::DmaChannel14(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 13;
}

void DmaChannel14::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC13_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC13_Pos;
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL12_15_REQSRC14_Msk)
DmaChannel15::DmaChannel15(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 14;
}

void DmaChannel15::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC14_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC14_Pos;
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL12_15_REQSRC15_Msk)
DmaChannel16::DmaChannel16(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 15;
}

void DmaChannel16::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
	__enable_irq();
}
#endif

#endif

