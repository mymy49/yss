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
#include <util/ElapsedTime.h>
#include <yss/reg.h>

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
	//setBitData(mPeri->FCR , false, DMA_SxFCR_DMDIS_Pos);				// 다이렉트 모드 비활성화
	//setFieldData(mPeri->FCR, DMA_SxFCR_FTH_Msk, 0, DMA_SxFCR_FTH_Pos);	// 1/4 Full FIFO
}

bool drv::Dma::send(DmaInfo &dmaInfo, void *src, unsigned int size, unsigned int timeout)
{
	unsigned int addr = (unsigned int)src;
	ElapsedTime time;

	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->PAR = (unsigned int)dmaInfo.dataRegister;

	if (size > 0xF000)
	{
		mAddr = addr;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
		//mPeri->CR = (	dmaInfo.channelNumber << DMA_SxCR_CHSEL_Pos) | 
		//				(dmaInfo.priority << DMA_SxCR_PL_Pos) |
		//				(dmaInfo.peripheralDataSize << DMA_SxCR_PSIZE_Pos) |
		//				(dmaInfo.memoryDataSize << DMA_SxCR_MSIZE_Pos) |
		//				(DMA_SxCR_MINC_Msk | 
		//				(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
		//				DMA_SxCR_TCIE_Msk | 
		//				DMA_SxCR_TEIE_Msk | 
		//				DMA_SxCR_EN_Msk);
	}
	else
	{
		mPeri->NDTR = size;
		mRemainSize = 0;
		//mPeri->CR = mPeri->CR = (	dmaInfo.channelNumber << DMA_SxCR_CHSEL_Pos) | 
		//				(dmaInfo.priority << DMA_SxCR_PL_Pos) |
		//				(dmaInfo.peripheralDataSize << DMA_SxCR_PSIZE_Pos) |
		//				(dmaInfo.memoryDataSize << DMA_SxCR_MSIZE_Pos) |
		//				(DMA_SxCR_MINC_Msk | 
		//				(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
		//				DMA_SxCR_TCIE_Msk | 
		//				DMA_SxCR_TEIE_Msk | 
		//				DMA_SxCR_EN_Msk);
	}

	mPeri->M0AR = addr;
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR = dmaInfo.controlRegister1;
	
	time.reset();
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (time.getMsec() >= timeout)
		{
			stop();
			return false;
		}
		thread::yield();
	}

	if (mErrorFlag)
		return false;
	else
		return true;
}

void drv::Dma::readyRx(DmaInfo &dmaInfo, void *des, unsigned int size)
{
	mCompleteFlag = false;
	mErrorFlag = false;
	unsigned int burst;
	
	if (size > 0xF000)
	{
		mAddr = (unsigned int)des;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
	}
	else
	{
		mPeri->NDTR = size;
		mRemainSize = 0;
	}

	mPeri->PAR = (unsigned int)dmaInfo.dataRegister;
	mPeri->M0AR = (unsigned int)des;
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR = dmaInfo.controlRegister1;
}

bool drv::Dma::receive(DmaInfo &dmaInfo, void *des, unsigned int size, unsigned int timeout)
{
	ElapsedTime time;

	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->PAR = (unsigned int)dmaInfo.dataRegister;

	if (size > 0xF000)
	{
		mAddr = (unsigned int)des;
		mPeri->M1AR = mAddr;
		mPeri->NDTR = 0xF000;
		mRemainSize = size - 0xF000;
		//mPeri->CR = mPeri->CR = (	dmaInfo.channelNumber << DMA_SxCR_CHSEL_Pos) | 
		//				(dmaInfo.priority << DMA_SxCR_PL_Pos) |
		//				(dmaInfo.peripheralDataSize << DMA_SxCR_PSIZE_Pos) |
		//				(dmaInfo.memoryDataSize << DMA_SxCR_MSIZE_Pos) |
		//				(DMA_SxCR_MINC_Msk | 
		//				(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
		//				DMA_SxCR_TCIE_Msk | 
		//				DMA_SxCR_TEIE_Msk | 
		//				DMA_SxCR_EN_Msk);
	}
	else
	{
		mPeri->NDTR = size;
		mRemainSize = 0;
		//mPeri->CR = mPeri->CR = (	dmaInfo.channelNumber << DMA_SxCR_CHSEL_Pos) | 
		//				(dmaInfo.priority << DMA_SxCR_PL_Pos) |
		//				(dmaInfo.peripheralDataSize << DMA_SxCR_PSIZE_Pos) |
		//				(dmaInfo.memoryDataSize << DMA_SxCR_MSIZE_Pos) |
		//				(DMA_SxCR_MINC_Msk | 
		//				(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
		//				DMA_SxCR_TCIE_Msk | 
		//				DMA_SxCR_TEIE_Msk | 
		//				DMA_SxCR_EN_Msk);
	}

	mPeri->M0AR = (unsigned int)des;
	mPeri->FCR = dmaInfo.controlRegister2;
	mPeri->CR = dmaInfo.controlRegister1;

	time.reset();
	while (!mCompleteFlag && !mErrorFlag)
	{
		if (time.getMsec() >= timeout)
		{
			stop();
			return false;
		}
		thread::yield();
	}

	if (mErrorFlag)
		return false;
	else
		return true;
}

void drv::Dma::stop(void)
{
	setBitData(mPeri->CR, false, DMA_SxCR_EN_Pos);
}

bool drv::Dma::isError(void)
{
	return mErrorFlag;
}

bool drv::Dma::isComplete(void)
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

drv::DmaChannel1::DmaChannel1(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel1::isr(void)
{
	unsigned int sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF0_Pos, DMA_LISR_FEIF0_Pos);
	
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



drv::DmaChannel2::DmaChannel2(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel2::isr(void)
{
	unsigned int sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF1_Pos, DMA_LISR_FEIF1_Pos);
	
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



drv::DmaChannel3::DmaChannel3(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel3::isr(void)
{
	unsigned int sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF2_Pos, DMA_LISR_FEIF2_Pos);
	
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



drv::DmaChannel4::DmaChannel4(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel4::isr(void)
{
	unsigned int sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF3_Pos, DMA_LISR_FEIF3_Pos);
	
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



drv::DmaChannel5::DmaChannel5(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel5::isr(void)
{
	unsigned int sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF4_Pos, DMA_HISR_FEIF4_Pos);
	
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



drv::DmaChannel6::DmaChannel6(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel6::isr(void)
{
	unsigned int sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF5_Pos, DMA_HISR_FEIF5_Pos);
	
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



drv::DmaChannel7::DmaChannel7(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel7::isr(void)
{
	unsigned int sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF6_Pos, DMA_HISR_FEIF6_Pos);
	
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



drv::DmaChannel8::DmaChannel8(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel8::isr(void)
{
	unsigned int sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF7_Pos, DMA_HISR_FEIF7_Pos);
	
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



drv::DmaChannel9::DmaChannel9(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel9::isr(void)
{
	unsigned int sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF0_Pos, DMA_LISR_FEIF0_Pos);
	
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



drv::DmaChannel10::DmaChannel10(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel10::isr(void)
{
	unsigned int sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF1_Pos, DMA_LISR_FEIF1_Pos);
	
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



drv::DmaChannel11::DmaChannel11(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel11::isr(void)
{
	unsigned int sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF2_Pos, DMA_LISR_FEIF2_Pos);
	
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



drv::DmaChannel12::DmaChannel12(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel12::isr(void)
{
	unsigned int sr = getFieldData(mDma->LISR, 0x3F << DMA_LISR_FEIF3_Pos, DMA_LISR_FEIF3_Pos);
	
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



drv::DmaChannel13::DmaChannel13(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel13::isr(void)
{
	unsigned int sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF4_Pos, DMA_HISR_FEIF4_Pos);
	
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



drv::DmaChannel14::DmaChannel14(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel14::isr(void)
{
	unsigned int sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF5_Pos, DMA_HISR_FEIF5_Pos);
	
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



drv::DmaChannel15::DmaChannel15(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel15::isr(void)
{
	unsigned int sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF6_Pos, DMA_HISR_FEIF6_Pos);
	
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



drv::DmaChannel16::DmaChannel16(const Drv::Config drvConfig, const Dma::Config dmaConfig, const Config config) : Dma(drvConfig, dmaConfig)
{
	
}

void drv::DmaChannel16::isr(void)
{
	unsigned int sr = getFieldData(mDma->HISR, 0x3F << DMA_HISR_FEIF7_Pos, DMA_HISR_FEIF7_Pos);
	
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