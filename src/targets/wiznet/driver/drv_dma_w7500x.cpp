////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(W7500)

#include <drv/peripheral.h>
#include <drv/Dma.h>
#include <util/ElapsedTime.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/wiznet/bitfield_w7500x.h>

Dma::Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup) : Drv(drvSetup)
{
	mDma = dmaSetup.dma;
	mChannelNumber = dmaSetup.channelNumber;
	mPrimary = dmaSetup.primary;
	mAlternate = dmaSetup.alternate;
}

void Dma::initialize(void)
{
}

error_t Dma::ready(dmaInfo_t &dmaInfo, void *buffer, int32_t  size)
{
	return error_t::ERROR_NONE;
}

error_t Dma::transfer(dmaInfo_t &dmaInfo, void *src, int32_t  count)
{
	mPrimary->des = src;
	mPrimary->src = dmaInfo.dataRegister;
	mPrimary->control = dmaInfo.controlRegister1;
	return error_t::ERROR_NONE;
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

DmaChannel1::DmaChannel1(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
	DMA->CFG = 0;
	DMA->CTRL_BASE_PTR = (uint32_t)mPrimary;
	DMA->CHNL_ENABLE_CLR = 0x3F;
	DMA->CFG = 1;
}

void DmaChannel1::isr(void)
{
}

DmaChannel2::DmaChannel2(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
}

void DmaChannel2::isr(void)
{
}

DmaChannel3::DmaChannel3(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
}

void DmaChannel3::isr(void)
{
}

DmaChannel4::DmaChannel4(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
}

void DmaChannel4::isr(void)
{
}

DmaChannel5::DmaChannel5(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
}

void DmaChannel5::isr(void)
{
}

DmaChannel6::DmaChannel6(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup) : Dma(drvSetup, dmaSetup)
{
}

void DmaChannel6::isr(void)
{
}

#endif

