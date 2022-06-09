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
#include <util/ElapsedTime.h>
#include <yss/reg.h>

#define checkError(sr) (sr & 0x08)
#define checkComplete(sr) (sr & 0x03)

drv::Dma::Dma(const Drv::Config drvConfig, const Config dmaConfig) : Drv(drvConfig)
{
	mDma = dmaConfig.dma;
	mPeri = dmaConfig.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mAddr = 0;
	mRemainSize = 0;
}

void drv::Dma::init(void)
{
}

void drv::Dma::ready(DmaInfo &dmaInfo, void *buffer, unsigned int size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	
	mPeri->PBAR = (unsigned int)dmaInfo.dataRegister;
	mPeri->MBAR = (unsigned int)buffer;
	mPeri->RCNT = size;
	mPeri->CTLR = dmaInfo.controlRegister1;
}

bool drv::Dma::send(DmaInfo &dmaInfo, void *src, unsigned int size, unsigned int timeout)
{
	unsigned int addr = (unsigned int)src;
	ElapsedTime time;

	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->PBAR = (unsigned int)dmaInfo.dataRegister;
	mPeri->RCNT = size;
	mPeri->MBAR = addr;
	mPeri->CTLR = dmaInfo.controlRegister1;

	time.reset();
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (time.getMsec() >= timeout)
		{
			mPeri->CTLR &= ~DMA_CTLR_CHEN;
			return false;
		}
		thread::yield();
	}
	
	mPeri->CTLR &= ~DMA_CTLR_CHEN;

	return !mErrorFlag;
}

bool drv::Dma::receive(DmaInfo &dmaInfo, void *des, unsigned int size, unsigned int timeout)
{
	ElapsedTime time;

	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->PBAR = (unsigned int)dmaInfo.dataRegister;
	mPeri->RCNT = size;
	mPeri->MBAR = (unsigned int)des;
	mPeri->CTLR = dmaInfo.controlRegister1;

	time.reset();
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (time.getMsec() >= timeout)
		{
			mPeri->CTLR &= ~DMA_CTLR_CHEN;
			return false;
		}
		thread::yield();
	}

	mPeri->CTLR &= ~DMA_CTLR_CHEN;

	if (mErrorFlag)
		return false;
	else
		return true;
}

void drv::Dma::stop(void)
{
	mPeri->CTLR &= ~DMA_CTLR_CHEN;
}

bool drv::Dma::isError(void)
{
	return mErrorFlag;
}

bool drv::Dma::isComplete(void)
{
	return mCompleteFlag;
}

drv::DmaChannel1::DmaChannel1(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel1::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 0, 0);
	setFieldData(mDma->ICR, 0xF << 0, sr, 0);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

drv::DmaChannel2::DmaChannel2(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel2::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 4, 4);
	setFieldData(mDma->ICR, 0xF << 4, sr, 4);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel3::DmaChannel3(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel3::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 8, 8);
	setFieldData(mDma->ICR, 0xF << 8, sr, 8);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel4::DmaChannel4(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel4::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 12, 12);
	setFieldData(mDma->ICR, 0xF << 12, sr, 12);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel5::DmaChannel5(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel5::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 16, 16);
	setFieldData(mDma->ICR, 0xF << 16, sr, 16);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel6::DmaChannel6(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel6::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 20, 20);
	setFieldData(mDma->ICR, 0xF << 20, sr, 20);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel7::DmaChannel7(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel7::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 24, 24);
	setFieldData(mDma->ICR, 0xF << 24, sr, 24);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel8::DmaChannel8(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
}

void drv::DmaChannel8::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 0, 0);
	setFieldData(mDma->ICR, 0xF << 0, sr, 0);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel9::DmaChannel9(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel9::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 4, 4);
	setFieldData(mDma->ICR, 0xF << 4, sr, 4);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel10::DmaChannel10(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel10::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 8, 8);
	setFieldData(mDma->ICR, 0xF << 8, sr, 8);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel11::DmaChannel11(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel11::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 12, 12);
	setFieldData(mDma->ICR, 0xF << 12, sr, 12);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}



drv::DmaChannel12::DmaChannel12(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel12::isr(void)
{
	register unsigned int sr = getFieldData(mDma->IFR, 0xF << 16, 16);
	setFieldData(mDma->ICR, 0xF << 16, sr, 16);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;
}

#endif