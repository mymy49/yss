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
#include <util/ElapsedTime.h>
#include <yss/reg.h>

#define checkError(sr) (sr & 0x08)
#define checkComplete(sr) (sr & 0x03)

Dma::Dma(const Drv::Config drvConfig, const Config dmaConfig) : Drv(drvConfig)
{
	mDma = dmaConfig.dma;
	mPeri = dmaConfig.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mAddr = 0;
	mRemainSize = 0;
}

void Dma::init(void)
{
}

void Dma::ready(DmaInfo &dmaInfo, void *buffer, int size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadNum();

	mPeri->CPAR = (int)dmaInfo.dataRegister;
	mPeri->CMAR = (int)buffer;
	mPeri->CNDTR = size;
	mPeri->CCR = dmaInfo.controlRegister1;
}

error Dma::send(DmaInfo &dmaInfo, void *src, int size)
{
	int addr = (int)src;
	mThreadId = thread::getCurrentThreadNum();

	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->CPAR = (int)dmaInfo.dataRegister;
	mPeri->CNDTR = size;
	mPeri->CMAR = addr;
	mPeri->CCR = dmaInfo.controlRegister1;

	while (!mCompleteFlag && !mErrorFlag)
		thread::yield();

	stop();

	if(mErrorFlag)
		return Error::DMA;
	else
		return Error::NONE;
}

error Dma::receive(DmaInfo &dmaInfo, void *des, int size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadNum();

	mPeri->CPAR = (int)dmaInfo.dataRegister;
	mPeri->CNDTR = size;
	mPeri->CMAR = (int)des;
	mPeri->CCR = dmaInfo.controlRegister1;

	while (!mCompleteFlag && !mErrorFlag)
		thread::yield();

	if (mErrorFlag)
		return Error::DMA;
	else
		return Error::NONE;
}

void Dma::stop(void)
{
#if defined(__SEGGER_LINKER)
	mPeri->CCR &= ~DMA_CCR1_EN;
#else
	mPeri->CCR &= ~DMA_CCR_EN;
#endif
}

bool Dma::isError(void)
{
	return mErrorFlag;
}

bool Dma::isComplete(void)
{
	return mCompleteFlag;
}

DmaChannel1::DmaChannel1(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel1::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 0, 0);
	setFieldData(mDma->IFCR, 0xF << 0, sr, 0);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}

DmaChannel2::DmaChannel2(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel2::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 4, 4);
	setFieldData(mDma->IFCR, 0xF << 4, sr, 4);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel3::DmaChannel3(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel3::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 8, 8);
	setFieldData(mDma->IFCR, 0xF << 8, sr, 8);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel4::DmaChannel4(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel4::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 12, 12);
	setFieldData(mDma->IFCR, 0xF << 12, sr, 12);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel5::DmaChannel5(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel5::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 16, 16);
	setFieldData(mDma->IFCR, 0xF << 16, sr, 16);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel6::DmaChannel6(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel6::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 20, 20);
	setFieldData(mDma->IFCR, 0xF << 20, sr, 20);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel7::DmaChannel7(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel7::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 24, 24);
	setFieldData(mDma->IFCR, 0xF << 24, sr, 24);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel8::DmaChannel8(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
}

void DmaChannel8::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 0, 0);
	setFieldData(mDma->IFCR, 0xF << 0, sr, 0);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel9::DmaChannel9(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel9::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 4, 4);
	setFieldData(mDma->IFCR, 0xF << 4, sr, 4);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel10::DmaChannel10(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel10::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 8, 8);
	setFieldData(mDma->IFCR, 0xF << 8, sr, 8);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel11::DmaChannel11(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel11::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 12, 12);
	setFieldData(mDma->IFCR, 0xF << 12, sr, 12);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}



DmaChannel12::DmaChannel12(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel12::isr(void)
{
	register int sr = getFieldData(mDma->ISR, 0xF << 16, 16);
	setFieldData(mDma->IFCR, 0xF << 16, sr, 16);

	if (checkError(sr))
		mErrorFlag = true;
	if (checkComplete(sr))
		mCompleteFlag = true;

	thread::signal(mThreadId);
}

#endif