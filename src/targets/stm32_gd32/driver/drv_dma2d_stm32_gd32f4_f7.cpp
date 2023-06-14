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

#if defined(STM32F4) || defined(GD32F4) || defined(STM32F7) && defined(DMA2D)

#include <drv/Dma2d.h>
#include <yss/thread.h>
#include <targets/st_gigadevice/dma2d_stm32_gd32f4_f7.h>

Dma2d::Dma2d(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mFontInfo.size = 0;
	mFontInfo.yPos = 0;
	mFontInfo.pointer = 0;
	mFontInfo.base = 0;

	mPeri = (YSS_DMA2D_Peri*)config.peri;
}

void Dma2d::init(void)
{

}

error Dma2d::waitUntilComplete(void)
{
	while(!mCompleteFlag && !mErrorFlag)
		thread::yield();

	if(mCompleteFlag)
		return error::ERROR_NONE;
	else
		return error::WRONG_CONFIG;
}

void Dma2d::fill(FillConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadId();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri[DMA2D_REG::OPFCCR] = config.colorMode;
	mPeri[DMA2D_REG::OCOLR] = config.color;
	mPeri[DMA2D_REG::OMAR] = (uint32_t)config.address;
	mPeri[DMA2D_REG::NLR] = config.size.width << 16 | config.size.height;
	mPeri[DMA2D_REG::OOR] = config.destinationOffset;
	mPeri[DMA2D_REG::CR] = mode::REG_TO_MEM << 16 | (DMA2D_CR_TEIE | DMA2D_CR_TCIE | DMA2D_CR_START);
}

void Dma2d::copy(CopyConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadId();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri[DMA2D_REG::FGPFCCR] = config.sourceColorMode;
	mPeri[DMA2D_REG::FGMAR] = (uint32_t)config.sourceAddress;
	mPeri[DMA2D_REG::FGOR] = config.sourceOffset;

	mPeri[DMA2D_REG::OPFCCR] = config.destinationColorMode;
	mPeri[DMA2D_REG::OMAR] = (uint32_t)config.destinationAddress;
	mPeri[DMA2D_REG::NLR] = config.size.width << 16 | config.size.height;
	mPeri[DMA2D_REG::OOR] = config.destinationOffset;

	mPeri[DMA2D_REG::CR] = mode::MEM_TO_MEM << 16 | (DMA2D_CR_TEIE | DMA2D_CR_TCIE | DMA2D_CR_START);
}

void Dma2d::blend(BlendConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadId();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri[DMA2D_REG::FGPFCCR] = config.sourceColorMode;
	mPeri[DMA2D_REG::FGMAR] = (uint32_t)config.sourceAddress;
	mPeri[DMA2D_REG::FGOR] = config.sourceOffset;

	mPeri[DMA2D_REG::BGPFCCR] = config.destinationColorMode;
	mPeri[DMA2D_REG::BGMAR] = (uint32_t)config.destinationAddress;
	mPeri[DMA2D_REG::BGOR] = config.destinationOffset;

	mPeri[DMA2D_REG::OPFCCR] = config.destinationColorMode;
	mPeri[DMA2D_REG::OMAR] = (uint32_t)config.destinationAddress;
	mPeri[DMA2D_REG::NLR] = config.size.width << 16 | config.size.height;
	mPeri[DMA2D_REG::OOR] = config.destinationOffset;

	mPeri[DMA2D_REG::CR] = mode::MEM_TO_MEM_BLENDING << 16 | (DMA2D_CR_TEIE | DMA2D_CR_TCIE | DMA2D_CR_START);
}

void Dma2d::drawCharacter(DrawCharConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadId();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri[DMA2D_REG::FGPFCCR] = config.sourceColorMode;
	mPeri[DMA2D_REG::FGMAR] = (uint32_t)config.sourceAddress;
	mPeri[DMA2D_REG::FGOR] = config.sourceOffset;

	mPeri[DMA2D_REG::BGPFCCR] = config.destinationColorMode;
	mPeri[DMA2D_REG::BGMAR] = (uint32_t)config.destinationAddress;
	mPeri[DMA2D_REG::BGOR] = config.destinationOffset;

	mPeri[DMA2D_REG::OPFCCR] = config.destinationColorMode;
	mPeri[DMA2D_REG::OMAR] = (uint32_t)config.destinationAddress;
	mPeri[DMA2D_REG::NLR] = config.size.width << 16 | config.size.height;
	mPeri[DMA2D_REG::OOR] = config.destinationOffset;

	mPeri[DMA2D_REG::CR] = mode::MEM_TO_MEM_BLENDING << 16 | (DMA2D_CR_TEIE | DMA2D_CR_TCIE | DMA2D_CR_START);
}

void Dma2d::isr(void)
{
	uint32_t intf = mPeri[DMA2D_REG::ISR];

	if(intf & DMA2D_ISR_TCIF)
		mCompleteFlag = true;
	if(intf & DMA2D_ISR_TEIF)
		mErrorFlag = true;
	
	mPeri[DMA2D_REG::IFCR] = intf;
	thread::signal(mThreadId);
}

#endif
