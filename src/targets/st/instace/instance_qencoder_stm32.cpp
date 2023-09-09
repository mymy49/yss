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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F4_N)

#include <config.h>
#include <drv/Qencoder.h>
#include <yss.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#endif

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if QENCODER3_ENABLE && defined(TIM3)
static void setClock3En(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM3EN_Pos, en);
	clock.unlock();
}

static void setInterrupt3En(bool en)
{
	nvic.lock();
#if defined(STM32F446xx)
	nvic.enableInterrupt(TIM3_IRQn, en);
#endif
	nvic.unlock();
}

static void reset3(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_TIM3RST_Pos);
	clock.unlock();
}

static const Drv::Setup gDrv3Setup = 
{
	setClock3En,				//void (*clockFunc)(bool en) = 0;
	setInterrupt3En,			//void (*nvicFunc)(bool en) = 0;
	reset3,						//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static const Qencoder::Setup gSetup3 = 
{
	TIM3,				//YSS_QENCODER_Peri *peri;
};

Qencoder qencoder3(gDrv3Setup, gSetup3);
#endif



#if QENCODER8_ENABLE && defined(TIM8)
static void setClock8En(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM8EN_Pos, en);
	clock.unlock();
}

static void setInterrupt8En(bool en)
{
	nvic.lock();
#if defined(STM32F446xx)
	nvic.enableInterrupt(TIM8_UP_TIM13_IRQn, en);
#endif
	nvic.unlock();
}

static void reset8(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB2RSTR_TIM8RST_Pos);
	clock.unlock();
}

static const Drv::Setup gDrv8Setup = 
{
	setClock8En,				//void (*clockFunc)(bool en) = 0;
	setInterrupt8En,			//void (*nvicFunc)(bool en) = 0;
	reset8,						//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static const Qencoder::Setup gSetup8 = 
{
	TIM8,				//YSS_QENCODER_Peri *peri;
};

Qencoder qencoder8(gDrv8Setup, gSetup8);
#endif

#endif

