/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F7)

#include <drv/Dma.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/st/bitfield.h>

Dma::Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup) : Drv(drvSetup)
{
	mDma = dmaSetup.dma;
	mChannel = dmaSetup.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mAddr = 0;
	mRemainSize = 0;
	mThreadId = -1;
}

void Dma::initialize(void)
{
}

error_t Dma::ready(dmaInfo_t &dmaInfo, void *data, int32_t  size)
{
	mCompleteFlag = false;
	mErrorFlag = false;

	if (size > 0xF000)
	{
		mChannel->NDTR = 0xF000;
		mChannel->PAR = (uint32_t)dmaInfo.dataRegister;
		mChannel->M0AR = (uint32_t)data;
		mChannel->M1AR = (uint32_t)data;
		mAddr = (uint32_t)data;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mChannel->NDTR = size;
		mChannel->PAR = (uint32_t)dmaInfo.dataRegister;
		mChannel->M0AR = (uint32_t)data;
		mRemainSize = 0;
	}
	
	mChannel->FCR = dmaInfo.controlRegister2;
	mChannel->CR = dmaInfo.controlRegister1;

	return error_t::ERROR_NONE;
}

error_t Dma::transfer(dmaInfo_t &dmaInfo, void *data, int32_t  size)
{
	mCompleteFlag = false;
	mErrorFlag = false;

	mThreadId = thread::getCurrentThreadId();

	if(dmaInfo.controlRegister1 & DMA_SxCR_CIRC_Msk)
	{
		mChannel->NDTR = size;
		mChannel->PAR = (uint32_t)dmaInfo.dataRegister;
		mChannel->M0AR = (uint32_t)data;
		mRemainSize = 0;
		mThreadId = -1;
	
		mChannel->FCR = dmaInfo.controlRegister2;
		mChannel->CR= dmaInfo.controlRegister1;
	}
	else
	{
		if (size > 0xF000)
		{
			mChannel->NDTR = 0xF000;
			mChannel->PAR = (uint32_t)dmaInfo.dataRegister;
			mChannel->M0AR = (uint32_t)data;
			mChannel->M1AR = (uint32_t)data;
			mAddr = (uint32_t)data;
			mRemainSize = size - 0xF000;
		}
		else
		{
			mChannel->NDTR = size;
			mChannel->PAR = (uint32_t)dmaInfo.dataRegister;
			mChannel->M0AR = (uint32_t)data;
			mRemainSize = 0;
		}
	
		mChannel->FCR = dmaInfo.controlRegister2;
		mChannel->CR= dmaInfo.controlRegister1;

		while (!mCompleteFlag && !mErrorFlag)
			thread::yield();
	
		mThreadId = -1;
	}

	if(mErrorFlag)
		return error_t::DMA_ERROR;
	else
		return error_t::ERROR_NONE;
}					

uint16_t Dma::getRemainingTransferCount(void)
{
	return mChannel->NDTR;
}

void Dma::stop(void)
{
	mChannel->CR= 0;
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

DmaChannel1::DmaChannel1(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel1::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 0, 0);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel2::DmaChannel2(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel2::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 6, 6);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel3::DmaChannel3(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel3::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 16, 16);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel4::DmaChannel4(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel4::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 22, 22);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel5::DmaChannel5(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel5::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 0, 0);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel6::DmaChannel6(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel6::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 6, 6);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel7::DmaChannel7(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel7::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 16, 16);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel8::DmaChannel8(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel8::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 22, 22);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel9::DmaChannel9(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel9::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 0, 0);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel10::DmaChannel10(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel10::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 6, 6);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel11::DmaChannel11(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel11::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 16, 16);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel12::DmaChannel12(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel12::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << 22, 22);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel13::DmaChannel13(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel13::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 0, 0);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel14::DmaChannel14(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel14::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 6, 6);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel15::DmaChannel15(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel15::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 16, 16);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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



DmaChannel16::DmaChannel16(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	
}

void DmaChannel16::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << 22, 22);
	volatile uint32_t *reg = &mChannel->NDTR;

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
		mChannel->CR |= DMA_SxCR_EN_Msk;
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

