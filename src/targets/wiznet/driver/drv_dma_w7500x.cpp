/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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
	mDma->CHNL_ENABLE_SET = 1 << mChannelNumber;
	mDma->CHNL_SW_REQUEST = 1 << mChannelNumber;

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
	mDma->CFG = 0;
	mDma->CTRL_BASE_PTR = (uint32_t)mPrimary;
	mDma->CHNL_ENABLE_CLR = 0x3F;
	mDma->CFG = 1;
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

