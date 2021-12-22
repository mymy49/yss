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
// 주담당자 : 아이구 (mymy49@nate.com) 2021.02.11 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)

#include <config.h>

#if defined(I2C1) && defined(I2C1_ENABLE)
static void setI2c1ClockEn(bool en)
{
	clock.peripheral.setI2c1En(en);
}

static void resetI2c1(void)
{
	clock.peripheral.resetI2c1();
}

static unsigned int getI2c1ClockFrequency(void)
{
	return clock.getApb1ClkFreq();
}

drv::I2c i2c1(
	I2C1,
	setI2c1ClockEn,
	0,
	resetI2c1,
	YSS_DMA_MAP_I2C1_TX_STREAM,
	YSS_DMA_MAP_I2C1_RX_STREAM,
	YSS_DMA_MAP_I2C1_TX_CHANNEL,
	YSS_DMA_MAP_I2C1_RX_CHANNEL,
	getI2c1ClockFrequency,
	define::dma::priorityLevel::LOW);

#endif

#if defined(I2C2) && defined(I2C2_ENABLE)
static void setI2c2ClockEn(bool en)
{
	clock.peripheral.setI2c2En(en);
}

static void resetI2c2(void)
{
	clock.peripheral.resetI2c2();
}

static unsigned int getI2c2ClockFrequency(void)
{
	return clock.getApb1ClkFreq();
}

drv::I2c i2c2(
	I2C2,
	setI2c2ClockEn,
	0,
	resetI2c2,
	YSS_DMA_MAP_I2C2_TX_STREAM,
	YSS_DMA_MAP_I2C2_RX_STREAM,
	YSS_DMA_MAP_I2C2_TX_CHANNEL,
	YSS_DMA_MAP_I2C2_RX_CHANNEL,
	getI2c2ClockFrequency,
	define::dma::priorityLevel::LOW);

#endif

#if defined(I2C3) && defined(I2C3_ENABLE)
static void setI2c3ClockEn(bool en)
{
	clock.peripheral.setI2c3En(en);
}

static void resetI2c3(void)
{
	clock.peripheral.resetI2c3();
}

static unsigned int getI3c1ClockFrequency(void)
{
	return clock.getApb1ClkFreq();
}

drv::I2c i2c3(
	I2C3,
	setI2c3ClockEn,
	0,
	resetI2c3,
	YSS_DMA_MAP_I2C3_TX_STREAM,
	YSS_DMA_MAP_I2C3_RX_STREAM,
	YSS_DMA_MAP_I2C3_TX_CHANNEL,
	YSS_DMA_MAP_I2C3_RX_CHANNEL,
	getI3c1ClockFrequency,
	define::dma::priorityLevel::LOW);

#endif

#endif

