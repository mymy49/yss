////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F1)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <drv/dma/register_dma_stm32f1.h>
#include <util/time.h>

namespace drv
{
Stream::Stream(YSS_DMA_Peri *dma, YSS_DMA_Channel_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned char ch) : Drv(clockFunc, nvicFunc)
{
	mDma = dma;
	mPeri = peri;
}

void Stream::init(void)
{
	setDmaStreamTcie(mPeri, true);
	setDmaStreamTeie(mPeri, true);
}

bool Stream::send(sac::Comm *obj, void *src, unsigned int size, unsigned int timeout)
{
	unsigned long long endTime;

	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();

	setDmaStreamPar(mPeri, (unsigned int)(info->txDr));
	setDmaStreamDir(mPeri, define::dma::dir::MEM_TO_PERI);
	setDmaStreamPinc(mPeri, define::dma::addr::FIXED);
	setDmaStreamMinc(mPeri, define::dma::addr::ADDR_INC);
	setDmaStreamMsize(mPeri, define::dma::size::BYTE);
	setDmaStreamPsize(mPeri, define::dma::size::BYTE);
	setDmaStreamPriorityLevel(mPeri, info->priority);
	setDmaStreamMar(mPeri, (unsigned int)src);
	setDmaStreamNdtr(mPeri, size);
	setDmaStreamEn(mPeri, true);

	endTime = time::getRunningMsec() + timeout;
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (endTime <= time::getRunningMsec())
		{
			setDmaStreamEn(mPeri, false);
			return false;
		}
		thread::yield();
	}

	setDmaStreamEn(mPeri, false);

	if (mErrorFlag)
		return false;
	else
		return true;
}

void Stream::pendTx(sac::Comm *obj, void *src, unsigned int size)
{
	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();

	setDmaStreamPar(mPeri, (unsigned int)(info->txDr));
	setDmaStreamDir(mPeri, define::dma::dir::MEM_TO_PERI);
	setDmaStreamPinc(mPeri, define::dma::addr::FIXED);
	setDmaStreamMinc(mPeri, define::dma::addr::ADDR_INC);
	setDmaStreamMsize(mPeri, define::dma::size::BYTE);
	setDmaStreamPsize(mPeri, define::dma::size::BYTE);
	setDmaStreamPriorityLevel(mPeri, info->priority);
	setDmaStreamMar(mPeri, (unsigned int)src);
	setDmaStreamNdtr(mPeri, size);
	setDmaStreamEn(mPeri, true);
}

void Stream::pendRx(sac::Comm *obj, void *des, unsigned int size)
{
	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();

	setDmaStreamPar(mPeri, (unsigned int)(info->rxDr));
	setDmaStreamDir(mPeri, define::dma::dir::PERI_TO_MEM);
	setDmaStreamPinc(mPeri, define::dma::addr::FIXED);
	setDmaStreamMinc(mPeri, define::dma::addr::ADDR_INC);
	setDmaStreamMsize(mPeri, define::dma::size::BYTE);
	setDmaStreamPsize(mPeri, define::dma::size::BYTE);
	setDmaStreamPriorityLevel(mPeri, info->priority);
	setDmaStreamMar(mPeri, (unsigned int)des);
	setDmaStreamNdtr(mPeri, size);
	setDmaStreamEn(mPeri, true);
}

void Stream::stop(void)
{
	setDmaStreamEn(mPeri, false);
}

bool Stream::wait(unsigned long long timeout)
{
	unsigned long long endTime = time::getRunningMsec() + timeout;
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (endTime <= time::getRunningMsec())
		{
			setDmaStreamEn(mPeri, false);
			return false;
		}
		thread::yield();
	}

	setDmaStreamEn(mPeri, false);

	if (mErrorFlag)
		return false;
	else
		return true;
}

bool Stream::receive(sac::Comm *obj, void *des, unsigned int size, unsigned int timeout)
{
	unsigned long long endTime;

	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();

	setDmaStreamPar(mPeri, (unsigned int)(info->rxDr));
	setDmaStreamDir(mPeri, define::dma::dir::PERI_TO_MEM);
	setDmaStreamPinc(mPeri, define::dma::addr::FIXED);
	setDmaStreamMinc(mPeri, define::dma::addr::ADDR_INC);
	setDmaStreamMsize(mPeri, define::dma::size::BYTE);
	setDmaStreamPsize(mPeri, define::dma::size::BYTE);
	setDmaStreamPriorityLevel(mPeri, info->priority);
	setDmaStreamMar(mPeri, (unsigned int)des);
	setDmaStreamNdtr(mPeri, size);
	setDmaStreamEn(mPeri, true);

	endTime = time::getRunningMsec() + timeout;
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (endTime <= time::getRunningMsec())
		{
			setDmaStreamEn(mPeri, false);
			return false;
		}
		thread::yield();
	}

	return true;
}

#define checkError(sr) (sr & 0x08)
#define checkComplete(sr) (sr & 0x03)

void Stream::isr1(void)
{
	register unsigned int sr = getDmaStream1Sr(mDma);
	clrDmaStream1Sr(mDma, sr);
	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr2(void)
{
	register unsigned int sr = getDmaStream2Sr(mDma);
	clrDmaStream2Sr(mDma, sr);
	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr3(void)
{
	register unsigned int sr = getDmaStream3Sr(mDma);
	clrDmaStream3Sr(mDma, sr);
	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr4(void)
{
	register unsigned int sr = getDmaStream4Sr(mDma);
	clrDmaStream4Sr(mDma, sr);
	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr5(void)
{
	register unsigned int sr = getDmaStream5Sr(mDma);
	clrDmaStream5Sr(mDma, sr);
	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr6(void)
{
	register unsigned int sr = getDmaStream6Sr(mDma);
	clrDmaStream6Sr(mDma, sr);
	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr7(void)
{
	register unsigned int sr = getDmaStream7Sr(mDma);
	clrDmaStream7Sr(mDma, sr);
	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

}

#endif