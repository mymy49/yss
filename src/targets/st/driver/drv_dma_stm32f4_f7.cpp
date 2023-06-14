////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32F4_N) || defined(STM32F7_N)

#include <drv/Dma.h>
#include <yss/reg.h>
#include <yss/thread.h>
#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#endif

Dma::Dma(const Drv::Config drvConfig, const Config dmaConfig) : Drv(drvConfig)
{
	mDma = dmaConfig.dma;
	mPeri = dmaConfig.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mAddr = 0;
	mRemainSize = 0;
}

void Dma::initialize(void)
{
}

error Dma::ready(DmaInfo &dmaInfo, void *data, int32_t  size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	
	if (size > 0xF000)
	{
		mPeri->NDTR = 0xF000;
		mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
		mPeri->M0AR = (uint32_t)data;
		mPeri->M1AR = (uint32_t)data;
		mAddr = (uint32_t)data;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mPeri->NDTR = size;
		mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
		mPeri->M0AR = (uint32_t)data;
		mRemainSize = 0;
	}
	
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR= dmaInfo.controlRegister1;

	return error::ERROR_NONE;
}

error Dma::transfer(DmaInfo &dmaInfo, void *data, int32_t  size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadId();
	
	if (size > 0xF000)
	{
		mPeri->NDTR = 0xF000;
		mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
		mPeri->M0AR = (uint32_t)data;
		mPeri->M1AR = (uint32_t)data;
		mAddr = (uint32_t)data;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mPeri->NDTR = size;
		mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
		mPeri->M0AR = (uint32_t)data;
		mRemainSize = 0;
	}
	
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR= dmaInfo.controlRegister1;

	while (!mCompleteFlag && !mErrorFlag)
		thread::yield();
	
	if(mErrorFlag)
		return error::DMA;
	else
		return error::ERROR_NONE;
}					

error Dma::send(DmaInfo &dmaInfo, void *src, int32_t  size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	mThreadId = thread::getCurrentThreadId();
	
	if (size > 0xF000)
	{
		mPeri->NDTR = 0xF000;
		mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
		mPeri->M0AR = (uint32_t)src;
		mPeri->M1AR = (uint32_t)src;
		mAddr = (uint32_t)src;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mPeri->NDTR = size;
		mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
		mPeri->M0AR = (uint32_t)src;
		mRemainSize = 0;
	}
	
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR= dmaInfo.controlRegister1;

	while (!mCompleteFlag && !mErrorFlag)
		thread::yield();

	if(mErrorFlag)
		return error::DMA;
	else
		return error::ERROR_NONE;
}

error Dma::receive(DmaInfo &dmaInfo, void *des, int32_t  size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	
	if (size > 0xF000)
	{
		mPeri->NDTR = 0xF000;
		mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
		mPeri->M0AR = (uint32_t)des;
		mPeri->M1AR = (uint32_t)des;
		mAddr = (uint32_t)des;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mPeri->NDTR = size;
		mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
		mPeri->M0AR = (uint32_t)des;
		mRemainSize = 0;
	}
	
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR= dmaInfo.controlRegister1;

	while (!mCompleteFlag && !mErrorFlag)
		thread::yield();

	if (mErrorFlag)
		return error::DMA;
	else
		return error::ERROR_NONE;
}

void Dma::transferAsCircularMode(const DmaInfo *dmaInfo, void *src, uint16_t  size)
{
	mPeri->NDTR = size;
	mPeri->PAR = (uint32_t)dmaInfo->dataRegister;
	mPeri->M0AR = (uint32_t)src;
	mRemainSize = 0;
	
	mPeri->FCR = dmaInfo->controlRegister2;
	mPeri->CR= dmaInfo->controlRegister1 | DMA_SxCR_CIRC_Msk;
}

void Dma::setThreadIdOfTransferCircularDataHandler(void)
{
	mThreadId = thread::getCurrentThreadId();
}

uint16_t Dma::getCurrentTransferBufferCount(void)
{
	return mPeri->NDTR;
}

void Dma::stop(void)
{
	mPeri->CR= 0;
}

bool Dma::isError(void)
{
	return mErrorFlag;
}

bool Dma::isComplete(void)
{
	return mCompleteFlag;
}

#define checkError(sr) (sr & 0x0c)
#define checkTransferFinish(sr) (sr & 0x20)
#define checkHalfTransferFinish(sr) (sr & 0x10)

DmaChannel1::DmaChannel1(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel1::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 0, 0);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->LIFCR = (sr & 0x3F) << 0;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;								// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;							// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel2::DmaChannel2(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel2::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 6, 6);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->LIFCR = (sr & 0x3F) << 6;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel3::DmaChannel3(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel3::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 16, 16);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->LIFCR = (sr & 0x3F) << 16;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;				// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;			// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;			// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel4::DmaChannel4(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel4::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 22, 22);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->LIFCR = (sr & 0x3F) << 22;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;				// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;			// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;			// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel5::DmaChannel5(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel5::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 0, 0);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->HIFCR = (sr & 0x3F) << 0;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;				// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;			// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;			// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel6::DmaChannel6(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel6::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 6, 6);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->HIFCR = (sr & 0x3F) << 6;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;				// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;			// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;			// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel7::DmaChannel7(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel7::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 16, 16);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->HIFCR = (sr & 0x3F) << 16;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel8::DmaChannel8(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel8::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 22, 22);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->HIFCR = (sr & 0x3F) << 22;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel9::DmaChannel9(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel9::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 0, 0);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->LIFCR = (sr & 0x3F) << 0;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel10::DmaChannel10(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel10::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 6, 6);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->LIFCR = (sr & 0x3F) << 6;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel11::DmaChannel11(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel11::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 16, 16);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->LIFCR = (sr & 0x3F) << 16;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel12::DmaChannel12(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel12::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 22, 22);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->LIFCR = (sr & 0x3F) << 22;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel13::DmaChannel13(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel13::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 0, 0);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->HIFCR = (sr & 0x3F) << 0;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel14::DmaChannel14(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel14::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 6, 6);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->HIFCR = (sr & 0x3F) << 6;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel15::DmaChannel15(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel15::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 16, 16);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->HIFCR = (sr & 0x3F) << 16;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}



DmaChannel16::DmaChannel16(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel16::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 22, 22);
	volatile uint32_t *reg = &mPeri->NDTR;

	mDma->HIFCR = (sr & 0x3F) << 22;	// 인터럽트 플래그 클리어

	if (checkError(sr))
		mErrorFlag = true;

	if (mRemainSize)
	{
		mAddr += 0xF000;
		if (mRemainSize > 0xF000)
		{
			*reg = 0xF000;			// CNT
			reg += 2;
			mRemainSize -= 0xF000;
		}
		else
		{
			*reg = mRemainSize;		// CNT
			reg += 2;
			mRemainSize = 0;
		}

		*reg = (uint32_t)mAddr;		// M0ADDR
		mPeri->CR |= DMA_SxCR_EN_Msk;
	}
	else if (checkTransferFinish(sr))
	{
		thread::signal(mThreadId);
		mCompleteFlag = true;
	}
	else if (checkHalfTransferFinish(sr))
	{
		thread::signal(mThreadId);
	}
}

#endif
