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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if	defined (__SAML21E15A__) || defined (__SAML21E15B__) || defined (__SAML21E16A__) || defined (__SAML21E16B__) || \
	defined (__SAML21E17A__) || defined (__SAML21E17B__) || defined (__SAML21E18B__) || defined (__SAML21G16A__) || \
	defined (__SAML21G16B__) || defined (__SAML21G17A__) || defined (__SAML21G17B__) || defined (__SAML21G18A__) || \
	defined (__SAML21G18B__) || defined (__SAML21J16A__) || defined (__SAML21J16B__) || defined (__SAML21J17A__) || \
	defined (__SAML21J17B__) || defined (__SAML21J18A__) || defined (__SAML21J18B__)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/peripherals.h>

#if	defined(SPI1_ENABLE) && defined(SERCOM0)
static void setSpi1ClockEn(bool en)
{
//	clock.peripheral.setSerCom0En(true);
} 

//drv::Spi spi1(SERCOM0, setSpi1ClockEn, 0, YSS_DMA_MAP_SPI1_TX_STREAM, YSS_DMA_MAP_SPI1_RX_STREAM, YSS_DMA_MAP_SPI1_TX_CHANNEL, YSS_DMA_MAP_SPI1_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);
drv::Spi spi1(&SERCOM0->SPI, setSpi1ClockEn);
//drv::Spi spi1(0, setSpi1ClockEn);
#endif

#if	defined(SPI2_ENABLE) && defined(SPI2)
static void setSpi2ClockEn(bool en)
{
	clock.peripheral.setSpi2En(en);
} 

drv::Spi spi2(SPI2, setSpi2ClockEn, 0, YSS_DMA_MAP_SPI2_TX_STREAM, YSS_DMA_MAP_SPI2_RX_STREAM, YSS_DMA_MAP_SPI2_TX_CHANNEL, YSS_DMA_MAP_SPI2_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);
#endif

#if	defined(SPI3_ENABLE) && defined(SPI3)
static void setSpi3ClockEn(bool en)
{
	clock.peripheral.setSpi3En(en);
} 

drv::Spi spi3(SPI3, setSpi3ClockEn, 0, YSS_DMA_MAP_SPI3_TX_STREAM, YSS_DMA_MAP_SPI3_RX_STREAM, YSS_DMA_MAP_SPI3_TX_CHANNEL, YSS_DMA_MAP_SPI3_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);
#endif

#if	defined(SPI4_ENABLE) && defined(SPI4)
static void setSpi4ClockEn(bool en)
{
	clock.peripheral.setSpi4En(en);
} 

drv::Spi spi4(SPI4, setSpi4ClockEn, 0, YSS_DMA_MAP_SPI4_TX_STREAM, YSS_DMA_MAP_SPI4_RX_STREAM, YSS_DMA_MAP_SPI4_TX_CHANNEL, YSS_DMA_MAP_SPI4_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);
#endif

#if	defined(SPI5_ENABLE) && defined(SPI5)
static void setSpi5ClockEn(bool en)
{
	clock.peripheral.setSpi5En(en);
} 

drv::Spi spi5(SPI5, setSpi5ClockEn, 0, YSS_DMA_MAP_SPI5_TX_STREAM, YSS_DMA_MAP_SPI5_RX_STREAM, YSS_DMA_MAP_SPI5_TX_CHANNEL, YSS_DMA_MAP_SPI5_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);
#endif

#if	defined(SPI6_ENABLE) && defined(SPI6)
static void setSpi6ClockEn(bool en)
{
	clock.peripheral.setSpi6En(en);
} 

drv::Spi spi6(SPI6, setSpi6ClockEn, 0, YSS_DMA_MAP_SPI6_TX_STREAM, YSS_DMA_MAP_SPI6_RX_STREAM, YSS_DMA_MAP_SPI6_TX_CHANNEL, YSS_DMA_MAP_SPI6_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);
#endif

namespace drv
{
//	Spi::Spi(SercomSpi *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChannel, unsigned short priority, unsigned long (*getClockFreq)(void)) :  Drv(clockFunc, nvicFunc)
	Spi::Spi(SercomSpi *peri, void (*clockFunc)(bool en)) :  Drv(0, 0)
	{
		mPeri = peri;
		
		//this->set(txChannel, rxChannel, (void*)&(peri->DR), (void*)&(peri->DR), priority);
		
//		mGetClockFreq = getClockFreq;
		//mTxStream = txStream;
		//mRxStream = rxStream;
		mLastConfig = 0;
	}

	bool Spi::setConfig(config::spi::Config &config)
	{
		if(mLastConfig == &config)
			return true;
		mLastConfig = &config;

		unsigned long mod;
		unsigned long div, clk = mGetClockFreq();
		
		div = clk / config.maxFreq;
		if(clk % config.maxFreq)
			div++;
		
		if(div <= 2)
			div = 0;
		else if(div <= 4)
			div = 1;
		else if(div <= 8)
			div = 2;
		else if(div <= 16)
			div = 3;
		else if(div <= 32)
			div = 4;
		else if(div <= 64)
			div = 5;
		else if(div <= 128)
			div = 6;
		else if(div <= 256)
			div = 7;
		else
			return false;

		//setSPiMode(mPeri, config.mode);
		//setSpiBaudrate(mPeri, div);

		return true;
	}

	bool Spi::init(void)
	{
//		mPeri->CTRLA.reg = (0x3 << SERCOM_SPI_CTRLA_MODE_Pos) | ;
		//setSpiEn(mPeri, false);
		//setSpiDff(mPeri, false);
		//setSpiMsbfirst(mPeri);
		//setSpiSsi(mPeri, true);
		//setSpiSsm(mPeri, true);
		//setSpiMstr(mPeri, true);
		//setSpiTxeie(mPeri, true);
		//setSpiRxneie(mPeri, true);
		//setSpiDmaTxEn(mPeri, true);

		return true;
	}

	void Spi::enable(bool en)
	{
//		setSpiEn(mPeri, en);
	}

	bool Spi::send(void *src, unsigned long size, unsigned long timeout)
	{
		bool rt = false;

		//setSpiDmaRxEn(mPeri, false);
		//setSpiDmaTxEn(mPeri, true);

		//if(mTxStream)
		//	rt = mTxStream->send(this, src, size, timeout);
		//if(rt)
		//{
		//	while(getSpiBusy(mPeri))
		//		thread::switchContext();
		//}

		//while(getSpiRxne(mPeri))
		//	mPeri->DR;

		return rt;
	}

	bool Spi::exchange(void *des, unsigned long size, unsigned long timeout)
	{
		bool rt = false;

		//setSpiDmaRxEn(mPeri, true);
		//setSpiDmaTxEn(mPeri, true);
		
  //      if(mRxStream)
		//	mRxStream->pendRx(this, des, size);
			
		//if(mTxStream)
		//	rt = mTxStream->send(this, des, size, timeout);
		//if(rt)
		//{
		//	while(getSpiBusy(mPeri))
		//		thread::switchContext();
		//}

		//while(getSpiRxne(mPeri))
		//	mPeri->DR;

		//mRxStream->stop();
		return rt;
	}

	unsigned char Spi::exchange(unsigned char data)
	{
		//while(!getSpiTxe(mPeri))
		//	thread::switchContext();
		//setSpiDr(mPeri, data);
		//while(!getSpiRxne(mPeri))
		//	thread::switchContext();
		
		//return getSpiDr(mPeri);

		return 0;
	}

	void Spi::send(char data)
	{
		//while(!getSpiTxe(mPeri))
		//	thread::switchContext();
		//setSpiDr(mPeri, data);
		//while(!getSpiRxne(mPeri))
		//	thread::switchContext();
	}

	void Spi::send(unsigned char data)
	{
		//while(!getSpiTxe(mPeri))
		//	thread::switchContext();
		//setSpiDr(mPeri, data);
		//while(!getSpiRxne(mPeri))
		//	thread::switchContext();
	}

}

#endif
