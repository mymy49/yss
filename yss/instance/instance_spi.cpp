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
// 주담당자 : 아이구 (mymy49@nate.com) 2021.03.10 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>
#include <yss/instance.h>
#include <config.h>

#if defined(STM32F7)

static unsigned int getApb2ClkFreq(void)
{
	return clock.getApb2ClkFreq();
}

static unsigned int getApb1ClkFreq(void)
{
	return clock.getApb1ClkFreq();
}

#if defined(SPI1_ENABLE) && defined(SPI1)
static void setSpi1ClockEn(bool en)
{
	clock.peripheral.setSpi1En(en);
}

static void resetSpi1(void)
{
	clock.peripheral.resetSpi1();
}

drv::Spi spi1(SPI1, setSpi1ClockEn, 0, resetSpi1, YSS_DMA_MAP_SPI1_TX_STREAM, YSS_DMA_MAP_SPI1_RX_STREAM, YSS_DMA_MAP_SPI1_TX_CHANNEL, YSS_DMA_MAP_SPI1_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);
#endif

#if defined(SPI2_ENABLE) && defined(SPI2)
static void setSpi2ClockEn(bool en)
{
	clock.peripheral.setSpi2En(en);
}

static void resetSpi2(void)
{
	clock.peripheral.resetSpi2();
}

drv::Spi spi2(SPI2, setSpi2ClockEn, 0, resetSpi2, YSS_DMA_MAP_SPI2_TX_STREAM, YSS_DMA_MAP_SPI2_RX_STREAM, YSS_DMA_MAP_SPI2_TX_CHANNEL, YSS_DMA_MAP_SPI2_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);
#endif

#if defined(SPI3_ENABLE) && defined(SPI3)
static void setSpi3ClockEn(bool en)
{
	clock.peripheral.setSpi3En(en);
}

static void resetSpi3(void)
{
	clock.peripheral.resetSpi3();
}

drv::Spi spi3(SPI3, setSpi3ClockEn, 0, resetSpi3, YSS_DMA_MAP_SPI3_TX_STREAM, YSS_DMA_MAP_SPI3_RX_STREAM, YSS_DMA_MAP_SPI3_TX_CHANNEL, YSS_DMA_MAP_SPI3_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);
#endif

#if defined(SPI4_ENABLE) && defined(SPI4)
static void setSpi4ClockEn(bool en)
{
	clock.peripheral.setSpi4En(en);
}

static void resetSpi4(void)
{
	clock.peripheral.resetSpi4();
}

drv::Spi spi4(SPI4, setSpi4ClockEn, 0, resetSpi4, YSS_DMA_MAP_SPI4_TX_STREAM, YSS_DMA_MAP_SPI4_RX_STREAM, YSS_DMA_MAP_SPI4_TX_CHANNEL, YSS_DMA_MAP_SPI4_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);
#endif

#if defined(SPI5_ENABLE) && defined(SPI5)
static void setSpi5ClockEn(bool en)
{
	clock.peripheral.setSpi5En(en);
}

static void resetSpi5(void)
{
	clock.peripheral.resetSpi5();
}

drv::Spi spi5(SPI5, setSpi5ClockEn, 0, resetSpi5, YSS_DMA_MAP_SPI5_TX_STREAM, YSS_DMA_MAP_SPI5_RX_STREAM, YSS_DMA_MAP_SPI5_TX_CHANNEL, YSS_DMA_MAP_SPI5_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);
#endif

#if defined(SPI6_ENABLE) && defined(SPI6)
static void setSpi6ClockEn(bool en)
{
	clock.peripheral.setSpi6En(en);
}

static void resetSpi6(void)
{
	clock.peripheral.resetSpi6();
}

drv::Spi spi6(SPI6, setSpi6ClockEn, 0, resetSpi6, YSS_DMA_MAP_SPI6_TX_STREAM, YSS_DMA_MAP_SPI6_RX_STREAM, YSS_DMA_MAP_SPI6_TX_CHANNEL, YSS_DMA_MAP_SPI6_RX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);
#endif

#endif

