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
// 주담당자 : 아이구 (mymy49@nate.com) 2021.03.05 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>
#include <config.h>

#if defined(STM32F4) || defined(STM32F7)

#if defined(SAI1_ENABLE) & defined(SAI1)
static void setClock1En(bool en)
{
	clock.peripheral.setSai1En(en);
}

static void setInterrupt1En(bool en)
{
	nvic.setSai1En(en);
}

static unsigned int getSai1Clock(void)
{
#if defined(STM32F4) | defined(STM32F7)
	return clock.getApb2ClkFreq();
#else
	return 0;
#endif
}

static const Drv::Config gSai1DrvConfig
{
	setClock1En,		//void (*clockFunc)(bool en) = 0;
	setInterrupt1En,	//void (*nvicFunc)(bool en) = 0;
	0					//void (*resetFunc)(void) = 0;
};

static const drv::Sai::Config gSai1Config
{
	SAI1,								//YSS_SAI_Peri *peri;
	SAI1_Block_A,						//SAI_Block_TypeDef *blockA;
	SAI1_Block_B,							//SAI_Block_TypeDef *blockB;
	YSS_DMA_MAP_SAI1_A_STREAM,			//Stream *streamA;
	YSS_DMA_MAP_SAI1_A_CHANNEL,			//unsigned char channelA;
	YSS_DMA_MAP_SAI1_B_STREAM,			//Stream *streamB;
	YSS_DMA_MAP_SAI1_B_CHANNEL,			//unsigned char channelB;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	getSai1Clock,						//unsigned int (*getClockFreq)(void);
};

drv::Sai sai1(gSai1DrvConfig, gSai1Config);
#endif

#if defined(SAI2_ENABLE) & defined(SAI2)
static void setClock2En(bool en)
{
	clock.peripheral.setSai2En(en);
}

static void setInterrupt2En(bool en)
{
	nvic.setSai2En(en);
}

static unsigned int getSai2Clock(void)
{
#if defined(STM32F7)
	return clock.getApb2ClkFreq();
#else
	return 0;
#endif
}

static const Drv::Config gSai2DrvConfig
{
	setClock2En,		//void (*clockFunc)(bool en) = 0;
	setInterrupt2En,	//void (*nvicFunc)(bool en) = 0;
	0					//void (*resetFunc)(void) = 0;
};

static const drv::Sai::Config gSai2Config
{
	SAI2,								//YSS_SAI_Peri *peri;
	SAI2_Block_A,						//SAI_Block_TypeDef *blockA;
	SAI2_Block_B,							//SAI_Block_TypeDef *blockB;
	YSS_DMA_MAP_SAI2_A_STREAM,			//Stream *streamA;
	YSS_DMA_MAP_SAI2_A_CHANNEL,			//unsigned char channelA;
	YSS_DMA_MAP_SAI2_B_STREAM,			//Stream *streamB;
	YSS_DMA_MAP_SAI2_B_CHANNEL,			//unsigned char channelB;
	define::dma::priorityLevel::LOW,	//unsigned short priority;
	getSai2Clock,						//unsigned int (*getClockFreq)(void);
};

drv::Sai sai2(gSai2DrvConfig, gSai2Config);
#endif

#endif

