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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32F7) || defined(STM32F4)

#include <drv/Dma.h>
#include <drv/dma/register_dma_stm32f4_f7.h>
#include <util/time.h>

namespace drv
{
Stream::Stream(DMA_TypeDef *dma, DMA_Stream_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned char ch) : Drv(clockFunc, nvicFunc)
{
	mPeri = peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mDma = dma;
}

void Stream::init(void)
{
	setDmaStreamFifoEn(mPeri, false);
	setDmaStreamFth(mPeri, 0);
}

bool Stream::send(sac::Comm *obj, void *src, unsigned int size, unsigned int timeout)
{
	unsigned long long endTime;
	unsigned int addr = (unsigned int)src;

	mMutex.lock();
	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();

	mPeri->PAR = (unsigned int)info->txDr;

	if (size > 0xF000)
	{
		mAddr = addr;
		mPeri->M0AR = addr;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
		mPeri->CR = (info->txChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
	}
	else
	{
		mPeri->M0AR = addr;
		mPeri->NDTR = size;
		mRemainSize = 0;
		mPeri->CR = (info->txChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
	}

	endTime = time::getRunningMsec() + timeout;
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (endTime <= time::getRunningMsec())
		{
			mPeri->CR &= ~DMA_SxCR_EN_Msk;
			mMutex.unlock();
			return false;
		}
		thread::yield();
	}

	mMutex.unlock();

	if (mErrorFlag)
		return false;
	else
		return true;
}

void Stream::pendRx(sac::Comm *obj, void *des, unsigned int size)
{
	mMutex.lock();
	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();

	mPeri->PAR = (unsigned int)info->txDr;

	if (size > 0xF000)
	{
		mAddr = (unsigned int)des;
		mPeri->M0AR = (unsigned int)des;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
		mPeri->CR = (info->rxChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
	}
	else
	{
		mPeri->M0AR = (unsigned int)des;
		mPeri->NDTR = size;
		mRemainSize = 0;
		mPeri->CR = (info->rxChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
	}
}

void Stream::stop(void)
{
	setDmaStreamEn(mPeri, false);
	mMutex.unlock();
}

bool Stream::receive(sac::Comm *obj, void *des, unsigned int size, unsigned int timeout)
{
	unsigned long long endTime;

	mMutex.lock();
	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();

	mPeri->PAR = (unsigned int)info->rxDr;

	if (size > 0xF000)
	{
		mAddr = (unsigned int)des;
		mPeri->M0AR = (unsigned int)des;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
		mPeri->CR = (info->rxChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
	}
	else
	{
		mPeri->M0AR = (unsigned int)des;
		mPeri->NDTR = size;
		mRemainSize = 0;
		mPeri->CR = (info->rxChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
	}

	endTime = time::getRunningMsec() + timeout;
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (endTime <= time::getRunningMsec())
		{
			setDmaStreamEn(mPeri, false);
			mMutex.unlock();
			return false;
		}
		thread::yield();
	}

	mMutex.unlock();

	if (mErrorFlag)
		return false;
	else
		return true;
}

#define checkError(sr) (sr & 0x0c)
#define checkComplete(sr) (sr & 0x20)

void Stream::isr0(void)
{
	unsigned int sr = getDmaStream0Sr(mDma);

	clrDmaStream0Sr(mDma, sr);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mPeri->NDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mPeri->NDTR = mRemainSize;
			mRemainSize = 0;
		}
		mPeri->M0AR = mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr1(void)
{
	unsigned int sr = getDmaStream1Sr(mDma);

	clrDmaStream1Sr(mDma, sr);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mPeri->NDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mPeri->NDTR = mRemainSize;
			mRemainSize = 0;
		}
		mPeri->M0AR = mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr2(void)
{
	unsigned int sr = getDmaStream2Sr(mDma);

	clrDmaStream2Sr(mDma, sr);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mPeri->NDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mPeri->NDTR = mRemainSize;
			mRemainSize = 0;
		}
		mPeri->M0AR = mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr3(void)
{
	unsigned int sr = getDmaStream3Sr(mDma);

	clrDmaStream3Sr(mDma, sr);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mPeri->NDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mPeri->NDTR = mRemainSize;
			mRemainSize = 0;
		}
		mPeri->M0AR = mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr4(void)
{
	unsigned int sr = getDmaStream4Sr(mDma);

	clrDmaStream4Sr(mDma, sr);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mPeri->NDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mPeri->NDTR = mRemainSize;
			mRemainSize = 0;
		}
		mPeri->M0AR = mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr5(void)
{
	unsigned int sr = getDmaStream5Sr(mDma);

	clrDmaStream5Sr(mDma, sr);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mPeri->NDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mPeri->NDTR = mRemainSize;
			mRemainSize = 0;
		}
		mPeri->M0AR = mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr6(void)
{
	unsigned int sr = getDmaStream6Sr(mDma);

	clrDmaStream6Sr(mDma, sr);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mPeri->NDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mPeri->NDTR = mRemainSize;
			mRemainSize = 0;
		}
		mPeri->M0AR = mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr7(void)
{
	unsigned int sr = getDmaStream7Sr(mDma);

	clrDmaStream7Sr(mDma, sr);

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			mPeri->NDTR = 0xF000;
			mRemainSize -= 0xF000;
		}
		else
		{
			mPeri->NDTR = mRemainSize;
			mRemainSize = 0;
		}
		mPeri->M0AR = mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkComplete(sr))
		mCompleteFlag = true;
}
}

#endif