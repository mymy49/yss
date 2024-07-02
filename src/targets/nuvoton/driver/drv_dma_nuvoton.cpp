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

#if defined(__M480_FAMILY)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <util/ElapsedTime.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/nuvoton/bitfield_m48x.h>

Dma::Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup) : Drv(drvSetup)
{
	mDma = dmaSetup.dma;
	mPeri = dmaSetup.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mAddr = 0;
	mRemainSize = 0;
	mSrcNum = 0;
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

	if(mSrcNum == 0)
		mDma->SWREQ |= 0x01;

	while(!mCompleteFlag)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t Dma::ready(dmaInfo_t &dmaInfo, void *buffer, int32_t  size)
{
	return error_t::ERROR_NONE;
}

error_t Dma::send(dmaInfo_t &dmaInfo, void *src, int32_t  size)
{
	if(mErrorFlag)
		return error_t::DMA_ERROR;
	else
		return error_t::ERROR_NONE;
}

error_t Dma::receive(dmaInfo_t &dmaInfo, void *des, int32_t  size)
{
	if (mErrorFlag)
		return error_t::DMA_ERROR;
	else
		return error_t::ERROR_NONE;
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

DmaChannel1::DmaChannel1(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{

}

void DmaChannel1::setSource(uint8_t src)
{
	mSrcNum = src;
}

// Nuvoton의 DMA는 일시적으로 done 관련 처리만 할 예정
// 운영간 문제가 생기면 관련 예외처리가 추가될 예정
void DmaChannel1::isr(void)
{
	uint32_t ctl = mPeri->CTL & 0x0000FFFF;

	if(mRemainSize)
	{
		if (mRemainSize > 0xFFFF)
		{
			ctl |= (0xFFFF - 1) << 16;
			mRemainSize = mRemainSize - 0xFFFF;
		}
		else
		{
			ctl |= (mRemainSize - 1) << 16;
			mRemainSize = 0;
		}
		
		mPeri->SA += 0xFFFF;
		mPeri->DA += 0xFFFF;
		mPeri->CTL = ctl;

		if(mSrcNum == 0)
			mDma->SWREQ |= 0x01;
	}
	else
	{
		mCompleteFlag = true;
	}
	
	thread::signal(mThreadId);
}

#endif

