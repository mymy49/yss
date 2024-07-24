/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(DMA2D) && (defined(STM32F7) || defined(STM32F4))

#include <drv/Dma2d.h>
#include <yss/thread.h>
#include <targets/st/bitfield.h>

Dma2d::Dma2d(const Drv::setup_t drvConfig, const setup_t config) : Drv(drvConfig)
{
	mPeri = (YSS_DMA2D_Peri*)config.peri;
}

void Dma2d::initialize(void)
{

}

error_t Dma2d::waitUntilComplete(void)
{
	while(!mCompleteFlag && !mErrorFlag)
		thread::yield();

	if(mCompleteFlag)
		return error_t::ERROR_NONE;
	else
		return error_t::WRONG_CONFIG;
}

void Dma2d::fill(FillConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadId();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->OPFCCR = config.colorMode;
	mPeri->OCOLR = config.color;
	mPeri->OMAR = (uint32_t)config.address;
	mPeri->NLR = config.size.width << 16 | config.size.height;
	mPeri->OOR = config.destinationOffset;
	mPeri->CR = mode::REG_TO_MEM << 16 | (DMA2D_CR_TEIE | DMA2D_CR_TCIE | DMA2D_CR_START);
}

void Dma2d::copy(CopyConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadId();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->FGPFCCR = config.sourceColorMode;
	mPeri->FGMAR = (uint32_t)config.sourceAddress;
	mPeri->FGOR = config.sourceOffset;

	mPeri->OPFCCR = config.destinationColorMode;
	mPeri->OMAR = (uint32_t)config.destinationAddress;
	mPeri->NLR = config.size.width << 16 | config.size.height;
	mPeri->OOR = config.destinationOffset;

	mPeri->CR = mode::MEM_TO_MEM << 16 | (DMA2D_CR_TEIE | DMA2D_CR_TCIE | DMA2D_CR_START);
}

void Dma2d::blend(BlendConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadId();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->FGPFCCR = config.sourceColorMode;
	mPeri->FGMAR = (uint32_t)config.sourceAddress;
	mPeri->FGOR = config.sourceOffset;

	mPeri->BGPFCCR = config.destinationColorMode;
	mPeri->BGMAR = (uint32_t)config.destinationAddress;
	mPeri->BGOR = config.destinationOffset;

	mPeri->OPFCCR = config.destinationColorMode;
	mPeri->OMAR = (uint32_t)config.destinationAddress;
	mPeri->NLR = config.size.width << 16 | config.size.height;
	mPeri->OOR = config.destinationOffset;

	mPeri->CR = mode::MEM_TO_MEM_BLENDING << 16 | (DMA2D_CR_TEIE | DMA2D_CR_TCIE | DMA2D_CR_START);
}

void Dma2d::drawCharacter(DrawCharConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadId();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri->FGPFCCR = config.sourceColorMode;
	mPeri->FGMAR = (uint32_t)config.sourceAddress;
	mPeri->FGOR = config.sourceOffset;
	mPeri->FGCOLR = config.color & 0x00FFFFFF;

	mPeri->BGPFCCR = config.destinationColorMode;
	mPeri->BGMAR = (uint32_t)config.destinationAddress;
	mPeri->BGOR = config.destinationOffset;

	mPeri->OPFCCR = config.destinationColorMode;
	mPeri->OMAR = (uint32_t)config.destinationAddress;
	mPeri->NLR = config.size.width << 16 | config.size.height;
	mPeri->OOR = config.destinationOffset;

	mPeri->CR = mode::MEM_TO_MEM_BLENDING << 16 | (DMA2D_CR_TEIE | DMA2D_CR_TCIE | DMA2D_CR_START);
}

void Dma2d::isr(void)
{
	uint32_t intf = mPeri->ISR;

	if(intf & DMA2D_ISR_TCIF)
		mCompleteFlag = true;
	if(intf & DMA2D_ISR_TEIF)
		mErrorFlag = true;
	
	mPeri->IFCR = intf;
	thread::signal(mThreadId);
}

#endif
