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

#if defined(GD32F4) && defined(IPA)

#include <drv/Dma2d.h>

enum
{
	CTL = 0, INTF, INTC, FMADDR, FLOFF, BMADDR, BLOFF, FPCTL, FPV, BPCTL, BPV, 
	FLMADDR, BLMADDR, DPCTL, DPV, DMADDR, DLOFF, IMS, LM, ITCTL
};

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
		return Error::NONE;
	else
		return Error::WRONG_CONFIG;
}

void Dma2d::fill(FillConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadNum();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri[DPCTL] = config.colorMode;
	mPeri[DPV] = config.color;
	mPeri[DMADDR] = (uint32_t)config.address;
	mPeri[IMS] = config.size.width << 16 | config.size.height;
	mPeri[DLOFF] = 0;
	mPeri[CTL] = mode::REG_TO_MEM << 16 | IPA_CTL_FTFIE | IPA_CTL_TEN;
}

void Dma2d::copy(CopyConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadNum();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri[FPCTL] = config.sourceColorMode;
	mPeri[FMADDR] = (uint32_t)config.sourceAddress;
	mPeri[FLOFF] = config.sourceOffset;

	mPeri[DPCTL] = config.destinationColorMode;
	mPeri[DMADDR] = (uint32_t)config.destinationAddress;
	mPeri[IMS] = config.size.width << 16 | config.size.height;
	mPeri[DLOFF] = config.destinationOffset;

	mPeri[CTL] = mode::MEM_TO_MEM << 16 | IPA_CTL_FTFIE | IPA_CTL_TEN;
}

void Dma2d::drawCharacter(DrawCharConfig &config)
{
	using namespace define::dma2d;

	mThreadId = thread::getCurrentThreadNum();
	mCompleteFlag = false;
	mErrorFlag = false;

	mPeri[FPCTL] = config.sourceColorMode;
	mPeri[FMADDR] = (uint32_t)config.sourceAddress;
	mPeri[FLOFF] = config.sourceOffset;

	mPeri[BPCTL] = config.destinationColorMode;
	mPeri[BMADDR] = (uint32_t)config.destinationAddress;
	mPeri[BLOFF] = config.destinationOffset;

	mPeri[DPCTL] = config.destinationColorMode;
	mPeri[DMADDR] = (uint32_t)config.destinationAddress;
	mPeri[IMS] = config.size.width << 16 | config.size.height;
	mPeri[DLOFF] = config.destinationOffset;

	mPeri[CTL] = mode::MEM_TO_MEM_BLENDING << 16 | IPA_CTL_FTFIE | IPA_CTL_TEN;
}

void Dma2d::isr(void)
{
	uint32_t intf = mPeri[INTF];

	if(intf & IPA_INTF_FTFIF)
		mCompleteFlag = true;
	if(intf & IPA_INTF_TAEIF)
		mErrorFlag = true;
	
	mPeri[INTC] = intf;
	thread::signal(mThreadId);
}

#endif