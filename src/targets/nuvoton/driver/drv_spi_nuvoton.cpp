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

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m48x.h>

Spi::Spi(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mLastSpec = nullptr;
	mTxDma = nullptr;
	mRxDma = nullptr;
}

error_t Spi::setSpecification(const specification_t &spec)
{
	if (mLastSpec == &spec)
		return error_t::ERROR_NONE;
	mLastSpec = &spec;

	uint32_t reg;
	uint32_t div, clk = Drv::getClockFrequency();
	
	div = clk / spec.maxFreq;
	if(clk % spec.maxFreq == 0 && div > 0)
		div--;

	if(div > 0x1FF)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	reg = mDev->CTL;
	reg &= ~(SPI_CTL_DWIDTH_Msk);
	reg |= spec.bit << SPI_CTL_DWIDTH_Pos;
	mDev->CTL = reg;

	mDev->CLKDIV = div;

	return error_t::ERROR_NONE;
}

error_t Spi::initializeAsMain(void)
{
	mDev->CTL = 0x00000034;	// Reset Value
	mDev->PDMACTL = SPI_PDMACTL_RXPDMAEN_Msk | SPI_PDMACTL_TXPDMAEN_Msk;

	mTxDma = allocateDma();
	if(mTxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mRxDma = allocateDma();
	if(mRxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mTxDma->setSource(mTxDmaInfo.src);
	mRxDma->setSource(mRxDmaInfo.src);

	return error_t::ERROR_NONE;
}

error_t Spi::initializeAsSub(void)
{

	return error_t::ERROR_NONE;
}

void Spi::enable(bool en)
{
	setBitData(mDev->CTL, en, SPI_CTL_SPIEN_Pos);
}

error_t Spi::send(void *src, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;
	
	mRxDma->ready(mRxDmaInfo, src, size);
	mTxDma->transfer(mTxDmaInfo, src, size);

	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t Spi::exchange(void *des, int32_t  size)
{
	return error_t::ERROR_NONE;
}

void Spi::receiveAsCircularMode(void *src, uint16_t count)
{

}

int8_t Spi::exchange(uint8_t data)
{
	*(uint8_t*)&mDev->TX = data;

	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();

	return mDev->RX;
}

void Spi::send(uint8_t data)
{
	*(int8_t*)&mDev->TX = data;
	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();
}

void Spi::isr(void)
{

	thread::signal(mThreadId);
}

#endif
