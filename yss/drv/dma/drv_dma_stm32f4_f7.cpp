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

#include <drv/peripheral.h>

#if defined(STM32F7) || defined(STM32F4)

#include <drv/Dma.h>
#include <drv/dma/register_dma_stm32f4_f7.h>
#include <util/ElapsedTime.h>
#include <yss/reg.h>

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

void Dma::ready(DmaInfo &dmaInfo, void *buffer, int32_t  size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	
	if (size > 0xF000)
	{
		mAddr = (uint32_t)buffer;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mPeri->NDTR = size;
		mRemainSize = 0;
	}

	mPeri->PAR = (uint32_t)dmaInfo.dataRegister;
	mPeri->M0AR = (uint32_t)buffer;
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR = dmaInfo.controlRegister1;
}

error Dma::send(DmaInfo &dmaInfo, void *src, int32_t  size)
{
	uint32_t addr = (uint32_t)src;

	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->PAR = (uint32_t)dmaInfo.dataRegister;

	if (size > 0xF000)
	{
		mAddr = addr;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mPeri->NDTR = size;
		mRemainSize = 0;
	}

	mPeri->M0AR = addr;
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR = dmaInfo.controlRegister1;
	
	while (!mCompleteFlag && !mErrorFlag)
	{
		thread::yield();
	}

	return !mErrorFlag;
}

error Dma::receive(DmaInfo &dmaInfo, void *des, int32_t  size)
{
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->PAR = (uint32_t)dmaInfo.dataRegister;

	if (size > 0xF000)
	{
		mAddr = (uint32_t)des;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mPeri->NDTR = size;
		mRemainSize = 0;
	}

	mPeri->M0AR = (uint32_t)des;
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR = dmaInfo.controlRegister1;

	while (!mCompleteFlag && !mErrorFlag)
	{
		thread::yield();
	}

	if (mErrorFlag)
		return false;
	else
		return true;
}

void Dma::stop(void)
{
	setBitData(mPeri->CR, false, DMA_SxCR_EN_Pos);
}

bool Dma::isError(void)
{
	return mErrorFlag;
}

bool Dma::isComplete(void)
{
	return mCompleteFlag;
}


#define getDmaStream0Sr(addr) getRegField(addr->LISR, 0x3FUL, 0)
#define clrDmaStream0Sr(addr, x) setRegField(addr->LIFCR, 0x3FUL, x, 0)
#define getDmaStream1Sr(addr) getRegField(addr->LISR, 0x3FUL, 6)
#define clrDmaStream1Sr(addr, x) setRegField(addr->LIFCR, 0x3FUL, x, 6)
#define getDmaStream2Sr(addr) getRegField(addr->LISR, 0x3FUL, 16)
#define clrDmaStream2Sr(addr, x) setRegField(addr->LIFCR, 0x3FUL, x, 16)
#define getDmaStream3Sr(addr) getRegField(addr->LISR, 0x3FUL, 22)
#define clrDmaStream3Sr(addr, x) setRegField(addr->LIFCR, 0x3FUL, x, 22)
#define getDmaStream4Sr(addr) getRegField(addr->HISR, 0x3FUL, 0)
#define clrDmaStream4Sr(addr, x) setRegField(addr->HIFCR, 0x3FUL, x, 0)
#define getDmaStream5Sr(addr) getRegField(addr->HISR, 0x3FUL, 6)
#define clrDmaStream5Sr(addr, x) setRegField(addr->HIFCR, 0x3FUL, x, 6)
#define getDmaStream6Sr(addr) getRegField(addr->HISR, 0x3FUL, 16)
#define clrDmaStream6Sr(addr, x) setRegField(addr->HIFCR, 0x3FUL, x, 16)
#define getDmaStream7Sr(addr) getRegField(addr->HISR, 0x3FUL, 22)
#define clrDmaStream7Sr(addr, x) setRegField(addr->HIFCR, 0x3FUL, x, 22)

#define checkError(sr) (sr & 0x0c)
#define checkComplete(sr) (sr & 0x20)

DmaChannel1::DmaChannel1(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel1::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF0_Pos, DMA_LISR_FEIF0_Pos);
	
	mDma->LIFCR = sr << DMA_LISR_FEIF0_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel2::DmaChannel2(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel2::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF1_Pos, DMA_LISR_FEIF1_Pos);
	
	mDma->LIFCR = sr << DMA_LISR_FEIF1_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel3::DmaChannel3(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel3::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF2_Pos, DMA_LISR_FEIF2_Pos);
	
	mDma->LIFCR = sr << DMA_LISR_FEIF2_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel4::DmaChannel4(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel4::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF3_Pos, DMA_LISR_FEIF3_Pos);
	
	mDma->LIFCR = sr << DMA_LISR_FEIF3_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel5::DmaChannel5(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel5::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF4_Pos, DMA_HISR_FEIF4_Pos);
	
	mDma->HIFCR = sr << DMA_HISR_FEIF4_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel6::DmaChannel6(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel6::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF5_Pos, DMA_HISR_FEIF5_Pos);
	
	mDma->HIFCR = sr << DMA_HISR_FEIF5_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel7::DmaChannel7(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel7::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF6_Pos, DMA_HISR_FEIF6_Pos);
	
	mDma->HIFCR = sr << DMA_HISR_FEIF6_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel8::DmaChannel8(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel8::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF7_Pos, DMA_HISR_FEIF7_Pos);
	
	mDma->HIFCR = sr << DMA_HISR_FEIF7_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel9::DmaChannel9(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel9::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF0_Pos, DMA_LISR_FEIF0_Pos);
	
	mDma->LIFCR = sr << DMA_LISR_FEIF0_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel10::DmaChannel10(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel10::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF1_Pos, DMA_LISR_FEIF1_Pos);
	
	mDma->LIFCR = sr << DMA_LISR_FEIF1_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel11::DmaChannel11(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel11::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF2_Pos, DMA_LISR_FEIF2_Pos);
	
	mDma->LIFCR = sr << DMA_LISR_FEIF2_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel12::DmaChannel12(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel12::isr(void)
{
	uint32_t sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF3_Pos, DMA_LISR_FEIF3_Pos);
	
	mDma->LIFCR = sr << DMA_LISR_FEIF3_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel13::DmaChannel13(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel13::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF4_Pos, DMA_HISR_FEIF4_Pos);
	
	mDma->HIFCR = sr << DMA_HISR_FEIF4_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel14::DmaChannel14(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel14::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF5_Pos, DMA_HISR_FEIF5_Pos);
	
	mDma->HIFCR = sr << DMA_HISR_FEIF5_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel15::DmaChannel15(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel15::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF6_Pos, DMA_HISR_FEIF6_Pos);
	
	mDma->HIFCR = sr << DMA_HISR_FEIF6_Pos;	// 인터럽트 플래그 클리어

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



DmaChannel16::DmaChannel16(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void DmaChannel16::isr(void)
{
	uint32_t sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF7_Pos, DMA_HISR_FEIF7_Pos);
	
	mDma->HIFCR = sr << DMA_HISR_FEIF7_Pos;	// 인터럽트 플래그 클리어

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


#endif