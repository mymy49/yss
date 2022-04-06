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

#if defined(GD32F10X_XD) || defined(GD32F10X_HD)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <util/time.h>
#include <yss/reg.h>

namespace drv
{
Stream::Stream(YSS_DMA_Peri *dma, YSS_DMA_Channel_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned char ch) : Drv(clockFunc, nvicFunc)
{
	mDma = dma;
	mPeri = peri;
}

void Stream::init(void)
{
}

bool Stream::send(sac::Comm *obj, void *src, unsigned int size, unsigned int timeout)
{
	unsigned long long endTime;
	unsigned int reg;

	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();
	
	mPeri->PBAR = (unsigned int)info->txDr;
	mPeri->MBAR = (unsigned int)src;
	mPeri->RCNT = size;
	// mem to peri, peri fixed, mem inc, byte
	mPeri->CTLR = 0x9B | (info->priority & 0x3) << 12;

	endTime = time::getRunningMsec() + timeout;
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (endTime <= time::getRunningMsec())
		{
			// DMA 비활성화
			setBitData(mPeri->CTLR, false, 0);
			return false;
		}
		thread::yield();
	}

	// DMA 비활성화
	setBitData(mPeri->CTLR, false, 0);

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

	mPeri->PBAR = (unsigned int)info->txDr;
	mPeri->MBAR = (unsigned int)src;
	mPeri->RCNT = size;
	// mem to peri, peri fixed, mem inc, byte
	mPeri->CTLR = 0x9B | (info->priority & 0x3) << 12;
}

void Stream::pendRx(sac::Comm *obj, void *des, unsigned int size)
{
	mCompleteFlag = false;
	mErrorFlag = false;

	sac::DmaInfo *info = obj->getDmaInfo();

	mPeri->PBAR = (unsigned int)info->rxDr;
	mPeri->MBAR = (unsigned int)des;
	mPeri->RCNT = size;
	// peri to mem, peri fixed, mem inc, byte
	mPeri->CTLR = 0x8B | (info->priority & 0x3) << 12;
}

void Stream::stop(void)
{
	// DMA 비활성화
	setBitData(mPeri->CTLR, false, 0);
}

bool Stream::wait(unsigned long long timeout)
{
	unsigned long long endTime = time::getRunningMsec() + timeout;
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (endTime <= time::getRunningMsec())
		{
			// DMA 비활성화
			setBitData(mPeri->CTLR, false, 0);
			return false;
		}
		thread::yield();
	}

	// DMA 비활성화
	setBitData(mPeri->CTLR, false, 0);

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

	mPeri->PBAR = (unsigned int)info->rxDr;
	mPeri->MBAR = (unsigned int)des;
	mPeri->RCNT = size;
	// peri to mem, peri fixed, mem inc, byte
	mPeri->CTLR = 0x8B | (info->priority & 0x3) << 12;

	endTime = time::getRunningMsec() + timeout;
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (endTime <= time::getRunningMsec())
		{
			// DMA 비활성화
			setBitData(mPeri->CTLR, false, 0);
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
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 0, 0);
	setFieldData(mDma->ICR, 0xF << 0, sr, 0);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr2(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 4, 4);
	setFieldData(mDma->ICR, 0xF << 4, sr, 4);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr3(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 8, 8);
	setFieldData(mDma->ICR, 0xF << 8, sr, 8);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr4(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 12, 12);
	setFieldData(mDma->ICR, 0xF << 12, sr, 12);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr5(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 16, 16);
	setFieldData(mDma->ICR, 0xF << 16, sr, 16);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr6(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 20, 20);
	setFieldData(mDma->ICR, 0xF << 20, sr, 20);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

void Stream::isr7(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 24, 24);
	setFieldData(mDma->ICR, 0xF << 24, sr, 24);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

}

#endif