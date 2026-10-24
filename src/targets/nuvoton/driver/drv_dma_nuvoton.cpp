/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

/**
 * @file drv_dma_nuvoton.cpp
 * @brief DMA (Direct Memory Access) target-specific driver source file for Nuvoton.
 */

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY) || defined(__MA35H0_FAMILY)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <util/Timeout.h>
#include <yss/reg.h>
#include <yss/scheduler.h>
#include <util/runtime.h>

#if defined(__MA35H0_FAMILY)
/*---------------------------------------------------------------------------------------------------------*/
/*  Operation Mode Constant Definitions                                                                    */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_OP_STOP        0x00000000UL            /*!<DMA Stop Mode  \hideinitializer */
#define PDMA_OP_BASIC       0x00000001UL            /*!<DMA Basic Mode  \hideinitializer */
#define PDMA_OP_SCATTER     0x00000002UL            /*!<DMA Scatter-gather Mode  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Data Width Constant Definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_WIDTH_8        0x00000000UL            /*!<DMA Transfer Width 8-bit  \hideinitializer */
#define PDMA_WIDTH_16       0x00001000UL            /*!<DMA Transfer Width 16-bit  \hideinitializer */
#define PDMA_WIDTH_32       0x00002000UL            /*!<DMA Transfer Width 32-bit  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Address Attribute Constant Definitions                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_SAR_INC        0x00000000UL            /*!<DMA SAR increment  \hideinitializer */
#define PDMA_SAR_FIX        0x00000300UL            /*!<DMA SAR fix address  \hideinitializer */
#define PDMA_DAR_INC        0x00000000UL            /*!<DMA DAR increment  \hideinitializer */
#define PDMA_DAR_FIX        0x00000C00UL            /*!<DMA DAR fix address  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Burst Mode Constant Definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_REQ_SINGLE     0x00000004UL            /*!<DMA Single Request  \hideinitializer */
#define PDMA_REQ_BURST      0x00000000UL            /*!<DMA Burst Request  \hideinitializer */

#define PDMA_BURST_128      0x00000000UL            /*!<DMA Burst 128 Transfers  \hideinitializer */
#define PDMA_BURST_64       0x00000010UL            /*!<DMA Burst 64 Transfers  \hideinitializer */
#define PDMA_BURST_32       0x00000020UL            /*!<DMA Burst 32 Transfers  \hideinitializer */
#define PDMA_BURST_16       0x00000030UL            /*!<DMA Burst 16 Transfers  \hideinitializer */
#define PDMA_BURST_8        0x00000040UL            /*!<DMA Burst 8 Transfers  \hideinitializer */
#define PDMA_BURST_4        0x00000050UL            /*!<DMA Burst 4 Transfers  \hideinitializer */
#define PDMA_BURST_2        0x00000060UL            /*!<DMA Burst 2 Transfers  \hideinitializer */
#define PDMA_BURST_1        0x00000070UL            /*!<DMA Burst 1 Transfers  \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  Table Interrupt Disable Constant Definitions                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_TBINTDIS_ENABLE  (0x0UL<<PDMA_DSCT_CTL_TBINTDIS_Pos)  /*!<DMA Table Interrupt Enabled   \hideinitializer */
#define PDMA_TBINTDIS_DISABLE (0x1UL<<PDMA_DSCT_CTL_TBINTDIS_Pos)  /*!<DMA Table Interrupt Disabled  \hideinitializer */
#endif

#pragma GCC optimize("O1")

Dma::Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup) : Drv(drvSetup)
{
	mDma = dmaSetup.dma;
	mChannel = dmaSetup.peri;
	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mAddr = 0;
	mRemainSize = 0;
	mSrcNum = 0;
	mChNum = 0;
	mMainChannel.NEXT = (uint32_t)(uint64_t)&mSubChannel;
	mSubChannel.NEXT = (uint32_t)(uint64_t)&mMainChannel;
}

void Dma::initialize(void)
{
	mDma->CHCTL = 0xFFFF;
	for(uint32_t i = 0; i < YSS__NUM_OF_DMA_CH; i++)
		mChannel[i].CTL = 0;

	mDma->INTEN = 0xFFFF;
}

error_t Dma::transfer(dmaInfo_t &dmaInfo, void *src, int32_t count, uint32_t timeout)
{
	Timeout tout(timeout);

	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14));
	bool timeoutFlag;

	ctl |= PDMA_OP_BASIC;
	ctl &= ~PDMA_OP_SCATTER;

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mSignalFlag = true;
	mThreadId = thread::getCurrentThreadId();

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mChannel->DA = (uint32_t)(uint64_t)dmaInfo.cpar;
		mChannel->SA = (uint32_t)(uint64_t)src;
		mDirFlag = true;
	}
	else // Peripheral -> Memory
	{
		mChannel->SA = (uint32_t)(uint64_t)dmaInfo.cpar;
		mChannel->DA = (uint32_t)(uint64_t)src;
		mDirFlag = false;
	}

	if (count > 0x2000)
	{
		ctl |= 0x2000 << 16;
		mAddr = (uint32_t)(uint64_t)src;
		mRemainSize = count - 0x2000;
	}
	else
	{
		ctl |= (count - 1) << 16;
		mRemainSize = 0;
	}

	mChannel->CTL = ctl;

	mDma->SWREQ |= 1 << mChNum;
	mThreadId = thread::getCurrentThreadId();

	thread::waitForSignal(timeout);
	
	while(1)
	{
		timeoutFlag = tout.isTimeout();
		if(mCompleteFlag || timeoutFlag)
			break;

		thread::yield();
	}
	
	if(timeoutFlag)
		return error_t::TIMEOUT;
	else
		return error_t::ERROR_NONE;
}

void Dma::trigger(void)
{
	mDma->SWREQ |= 1 << mChNum;
}

error_t Dma::ready(dmaInfo_t &dmaInfo, void *buf, int32_t count, bool signal)
{
	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14));

	ctl |= PDMA_OP_BASIC;
	ctl &= ~PDMA_OP_SCATTER;

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = false;
	mSignalFlag = signal;
	mThreadId = thread::getCurrentThreadId();

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mChannel->DA = (uint32_t)(uint64_t)dmaInfo.cpar;
		mChannel->SA = (uint32_t)(uint64_t)buf;
		mDirFlag = true;
	}
	else // Peripheral -> Memory
	{
		mChannel->SA = (uint32_t)(uint64_t)dmaInfo.cpar;
		mChannel->DA = (uint32_t)(uint64_t)buf;
		mDirFlag = false;
	}

	if (count > 0x2000)
	{
		ctl |= (0x2000 - 1) << 16;
		mAddr = (uint32_t)(uint64_t)buf;
		mRemainSize = count - 0x2000;
	}
	else
	{
		ctl |= (count - 1) << 16;
		mRemainSize = 0;
	}

	mChannel->CTL = ctl;

	return error_t::ERROR_NONE;
}

error_t Dma::transferAsCircularMode(const dmaInfo_t &dmaInfo, void *src, uint16_t count)
{
	if(count == 0)
		return error_t::NO_DATA;
	
	uint32_t ctl = dmaInfo.ctl & ~(0xFFFF0000 | (1 << 14)), src1, src2;

	ctl &= ~PDMA_OP_BASIC;
	ctl |= PDMA_OP_SCATTER;

	mCompleteFlag = false;
	mErrorFlag = false;
	mCircularModeFlag = true;
	mThreadId = thread::getCurrentThreadId();

	switch(dmaInfo.ctl & (PDMA_WIDTH_16 | PDMA_WIDTH_32))
	{
	case PDMA_WIDTH_8 :
		src1 = (uint32_t)(uint64_t)src;
		src2 = (uint32_t)(uint64_t)&((uint8_t*)src)[count / 2];
		break;
	case PDMA_WIDTH_16 : 
		src1 = (uint32_t)(uint64_t)src;
		src2 = (uint32_t)(uint64_t)&((uint16_t*)src)[count / 2];
		break;
	case PDMA_WIDTH_32 :
		src1 = (uint32_t)(uint64_t)src;
		src2 = (uint32_t)(uint64_t)&((uint32_t*)src)[count / 2];
		break;
	default :
		return error_t::WRONG_CONFIG;
	}

	if(dmaInfo.ctl & 1 << 14) // Memory -> Peripheral
	{
		mMainChannel.DA = (uint32_t)(uint64_t)dmaInfo.cpar;
		mSubChannel.DA = (uint32_t)(uint64_t)dmaInfo.cpar;
		mMainChannel.SA = src1;
		mSubChannel.SA = src2;
		mDirFlag = true;
	}
	else // Peripheral -> Memory
	{
		mMainChannel.SA = (uint32_t)(uint64_t)dmaInfo.cpar;
		mSubChannel.SA = (uint32_t)(uint64_t)dmaInfo.cpar;
		mMainChannel.DA = src1;
		mSubChannel.DA = src2;
		mDirFlag = false;
	}

	mMainChannel.CTL = ctl | (count / 2 - 1) << 16;
	mSubChannel.CTL = ctl | (count / 2 - 1) << 16;
	*mChannel = mMainChannel;

	mDma->SWREQ |= 1 << mChNum;

	return error_t::ERROR_NONE;
}

uint16_t Dma::getRemainingTransferCount(void)
{
	return mChannel->CTL >> 16;
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

uint16_t Dma::getCircularModeSentCount(void)
{
	return mCircularSentCnt;
}

void* Dma::getCircularModePreviouslyTransmittedDataBuffer(void)
{
	if(mMainChannel.CTL & 1 << 14)
	{
		switch(mCircularSentCnt % 2)
		{
		case 0 :
			return (void*)mSubChannel.DA;
		case 1 :
			return (void*)mMainChannel.DA;
		}
	}
	else
	{
		switch(mCircularSentCnt % 2)
		{
		case 0 :
			return (void*)mSubChannel.SA;
		case 1 :
			return (void*)mMainChannel.SA;
		}
	}

	return 0;
}

	// Nuvoton DMA currently only processes transfer completion (Done).
	// Exception handling and error management will be expanded if operational issues arise.
void Dma::isr(void)
{
	uint32_t ctl = mChannel->CTL & 0x0000FFFF;
	
	if(mCircularModeFlag)
	{
		mCircularSentCnt++;
	}
	else if(mRemainSize)
	{
		switch(ctl & (PDMA_WIDTH_16 | PDMA_WIDTH_32))
		{
		case 0 :
			mAddr += 0x2000;
			break;
		
		case PDMA_WIDTH_16 :
			mAddr += 0x4000;
			break;

		case PDMA_WIDTH_32 :
			mAddr += 0x8000;
			break;
		}

		if(mDirFlag) // Memory -> Peripheral
			mChannel->SA = (uint32_t)mAddr;
		else // Peripheral -> Memory
			mChannel->DA = (uint32_t)mAddr;

		if (mRemainSize > 0x2000)
		{
			ctl |= ((0x2000 - 1) << 16) | PDMA_OP_BASIC;
			mRemainSize = mRemainSize - 0x2000;
		}
		else
		{
			ctl |= ((mRemainSize - 1) << 16) | PDMA_OP_BASIC;
			mRemainSize = 0;
		}

		mChannel->CTL = ctl;
	}
	else
	{
		mCompleteFlag = true;
	}
	if(mSignalFlag)
		thread::signal(mThreadId);
}

DmaChannel1::DmaChannel1(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 0;
}

void DmaChannel1::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC0_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC0_Pos;
	__enable_irq();
}

DmaChannel2::DmaChannel2(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 1;
}

void DmaChannel2::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC1_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC1_Pos;
	__enable_irq();
}

DmaChannel3::DmaChannel3(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 2;
}

void DmaChannel3::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC2_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC2_Pos;
	__enable_irq();
}

DmaChannel4::DmaChannel4(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 3;
}

void DmaChannel4::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC3_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC3_Pos;
	__enable_irq();
}

DmaChannel5::DmaChannel5(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 4;
}

void DmaChannel5::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC4_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC4_Pos;
	__enable_irq();
}

DmaChannel6::DmaChannel6(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 5;
}

void DmaChannel6::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC5_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC5_Pos;
	__enable_irq();
}

DmaChannel7::DmaChannel7(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 6;
}

void DmaChannel7::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC6_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC6_Pos;
	__enable_irq();
}

DmaChannel8::DmaChannel8(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 7;
}

void DmaChannel8::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC7_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC7_Pos;
	__enable_irq();
}

#if defined(PDMA_REQSEL8_11_REQSRC8_Msk)
DmaChannel9::DmaChannel9(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 8;
}

void DmaChannel9::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC8_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC8_Pos;
	__enable_irq();
}
#endif


#if defined(PDMA_REQSEL8_11_REQSRC9_Msk)
DmaChannel10::DmaChannel10(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 9;
}

void DmaChannel10::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC9_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC9_Pos;
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL8_11_REQSRC10_Msk) || defined(__MA35H0_FAMILY)
DmaChannel11::DmaChannel11(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
#if defined(__MA35H0_FAMILY)
	mChNum = 0;
#else
	mChNum = 10;
#endif
}

void DmaChannel11::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC0_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC0_Pos;
#else
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC10_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC10_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL8_11_REQSRC11_Msk) || defined(__MA35H0_FAMILY)
DmaChannel12::DmaChannel12(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
#if defined(__MA35H0_FAMILY)
	mChNum = 1;
#else
	mChNum = 11;
#endif
}

void DmaChannel12::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC1_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC1_Pos;
#else
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC11_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC11_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL12_15_REQSRC12_Msk) || defined(__MA35H0_FAMILY)
DmaChannel13::DmaChannel13(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
#if defined(__MA35H0_FAMILY)
	mChNum = 2;
#else
	mChNum = 12;
#endif
}

void DmaChannel13::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC2_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC2_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC12_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC12_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL12_15_REQSRC13_Msk) || defined(__MA35H0_FAMILY)
DmaChannel14::DmaChannel14(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
#if defined(__MA35H0_FAMILY)
	mChNum = 3;
#else
	mChNum = 13;
#endif
}

void DmaChannel14::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC3_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC3_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC13_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC13_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL12_15_REQSRC14_Msk) || defined(__MA35H0_FAMILY)
DmaChannel15::DmaChannel15(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
#if defined(__MA35H0_FAMILY)
	mChNum = 4;
#else
	mChNum = 14;
#endif
}

void DmaChannel15::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC4_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC4_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC14_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC14_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(PDMA_REQSEL12_15_REQSRC15_Msk) || defined(__MA35H0_FAMILY)
DmaChannel16::DmaChannel16(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
#if defined(__MA35H0_FAMILY)
	mChNum = 5;
#else
	mChNum = 15;
#endif
}

void DmaChannel16::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC5_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC5_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel17::DmaChannel17(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 6;
}

void DmaChannel17::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC6_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC6_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel18::DmaChannel18(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 7;
}

void DmaChannel18::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC7_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC7_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel19::DmaChannel19(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 8;
}

void DmaChannel19::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC8_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC8_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel20::DmaChannel20(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 9;
}

void DmaChannel20::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC9_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC9_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel21::DmaChannel21(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 0;
}

void DmaChannel21::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC0_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC0_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel22::DmaChannel22(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 1;
}

void DmaChannel22::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC1_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC1_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel23::DmaChannel23(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 2;
}

void DmaChannel23::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC2_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC2_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel24::DmaChannel24(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 3;
}

void DmaChannel24::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC3_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC3_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel25::DmaChannel25(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 4;
}

void DmaChannel25::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC4_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC4_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel26::DmaChannel26(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 5;
}

void DmaChannel26::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC5_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC5_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel27::DmaChannel27(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 6;
}

void DmaChannel27::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC6_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC6_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel28::DmaChannel28(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 7;
}

void DmaChannel28::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC7_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC7_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel29::DmaChannel29(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 8;
}

void DmaChannel29::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC8_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC8_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel30::DmaChannel30(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 9;
}

void DmaChannel30::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC9_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC9_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel31::DmaChannel31(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 0;
}

void DmaChannel31::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC0_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC0_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel32::DmaChannel32(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 1;
}

void DmaChannel32::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC1_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC1_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel33::DmaChannel33(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 2;
}

void DmaChannel33::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC2_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC2_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel34::DmaChannel34(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 3;
}

void DmaChannel34::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL0_3 &= ~PDMA_REQSEL0_3_REQSRC3_Msk;
	mDma->REQSEL0_3 |= src << PDMA_REQSEL0_3_REQSRC3_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel35::DmaChannel35(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 4;
}

void DmaChannel35::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC4_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC4_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel36::DmaChannel36(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 5;
}

void DmaChannel36::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC5_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC5_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel37::DmaChannel37(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 6;
}

void DmaChannel37::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC6_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC6_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel38::DmaChannel38(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 7;
}

void DmaChannel38::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL4_7 &= ~PDMA_REQSEL4_7_REQSRC7_Msk;
	mDma->REQSEL4_7 |= src << PDMA_REQSEL4_7_REQSRC7_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel39::DmaChannel39(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 8;
}

void DmaChannel39::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC8_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC8_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#if defined(__MA35H0_FAMILY)
DmaChannel40::DmaChannel40(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	mChNum = 9;
}

void DmaChannel40::setSource(uint8_t src)
{
	mSrcNum = src;

	__disable_irq();
#if defined(__MA35H0_FAMILY)
	mDma->REQSEL8_11 &= ~PDMA_REQSEL8_11_REQSRC9_Msk;
	mDma->REQSEL8_11 |= src << PDMA_REQSEL8_11_REQSRC9_Pos;
#else
	mDma->REQSEL12_15 &= ~PDMA_REQSEL12_15_REQSRC15_Msk;
	mDma->REQSEL12_15 |= src << PDMA_REQSEL12_15_REQSRC15_Pos;
#endif
	__enable_irq();
}
#endif

#endif

