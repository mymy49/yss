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

#if defined(STM32F7_N) || defined(STM32F1_N)

#include <config.h>
#include <drv/Capture.h>
#include <yss.h>

#if defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#endif

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if CAPTURE1_ENABLE && defined(TIM1)
#if TIM1_ENABLE || PWM1_ENABLE
#error "CAPTURE1, PWM1, TIM1은 동시에 활성화 될 수 없습니다."
#endif
static void setCapture1ClockEn(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM1EN_Pos, en);
	clock.unlock();
}

static void setCapture1InterruptEn(bool en)
{
	nvic.lock();
#if defined(STM32F746xx)
	nvic.enableInterrupt(TIM1_UP_TIM10_IRQn, en);
#endif
	nvic.unlock();
}

static void resetCapture1(void)
{
	clock.lock();
    clock.resetApb2(11);
	clock.unlock();
}

static const Drv::Setup gCapture1DrvSetup = 
{
	setCapture1ClockEn,				//void (*clockFunc)(bool en) = 0;
	setCapture1InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetCapture1,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static uint64_t gCapture1UpdateCnt;
static const Capture::Setup gCapture11Setup = 
{
	TIM1,				//YSS_PWM_Peri *peri;
	&gCapture1UpdateCnt	//uint64_t *updateCnt;
};

CaptureCh1 capture1Ch1(gCapture1DrvSetup, gCapture11Setup);
CaptureCh2 capture1Ch2(gCapture1DrvSetup, gCapture11Setup);
CaptureCh3 capture1Ch3(gCapture1DrvSetup, gCapture11Setup);
CaptureCh4 capture1Ch4(gCapture1DrvSetup, gCapture11Setup);

extern "C"
{
void TIM1_UP_TIM10_IRQHandler(void)
{
	bool event = false;
	uint32_t dier = TIM1->DIER, sr = TIM1->SR;

	if (dier & TIM_DIER_UIE && sr & TIM_SR_UIF_Msk)
	{
		capture1Ch1.isrUpdate();
		event = true;
	}

	if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
	{
		capture1Ch1.isrCapture(event);
	}

	if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
	{
		capture1Ch2.isrCapture(event);
	}

	if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
	{
		capture1Ch3.isrCapture(event);
	}

	if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
	{
		capture1Ch4.isrCapture(event);
	}

	TIM1->SR = ~sr;
}

void TIM1_CC_IRQHandler(void)
{
	bool event = false;
	uint32_t dier = TIM1->DIER, sr = TIM1->SR;

	TIM1->SR = ~sr;

	if (dier & TIM_DIER_UIE && sr & TIM_SR_UIF_Msk)
	{
		capture1Ch1.isrUpdate();
		event = true;
	}

	if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
	{
		capture1Ch1.isrCapture(event);
	}

	if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
	{
		capture1Ch2.isrCapture(event);
	}

	if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
	{
		capture1Ch3.isrCapture(event);
	}

	if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
	{
		capture1Ch4.isrCapture(event);
	}
}
}

#endif



#if CAPTURE2_ENABLE && defined(TIM2)
#if TIM2_ENABLE || PWM2_ENABLE
#error "CAPTURE2, PWM2, TIM2은 동시에 활성화 될 수 없습니다."
#endif
static void setCapture2ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM2EN_Pos, en);
	clock.unlock();
}

static void setCapture2InterruptEn(bool en)
{
	nvic.lock();
#if defined(STM32F746xx)
	nvic.enableInterrupt(TIM2_IRQn, en);
#endif
	nvic.unlock();
}

static void resetCapture2(void)
{
	clock.lock();
    clock.resetApb2(11);
	clock.unlock();
}

static const Drv::Setup gCapture2DrvSetup = 
{
	setCapture2ClockEn,				//void (*clockFunc)(bool en) = 0;
	setCapture2InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetCapture2,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static uint64_t gCapture2UpdateCnt;
static const Capture::Setup gCapture21Setup = 
{
	TIM2,				//YSS_PWM_Peri *peri;
	&gCapture2UpdateCnt	//uint64_t *updateCnt;
};

CaptureCh1 capture2Ch1(gCapture2DrvSetup, gCapture21Setup);
CaptureCh2 capture2Ch2(gCapture2DrvSetup, gCapture21Setup);
CaptureCh3 capture2Ch3(gCapture2DrvSetup, gCapture21Setup);
CaptureCh4 capture2Ch4(gCapture2DrvSetup, gCapture21Setup);

extern "C"
{
void TIM2_IRQHandler(void)
{
	bool event = false;
	uint32_t dier = TIM2->DIER, sr = TIM2->SR;

	TIM2->SR = ~sr;

	if (dier & TIM_DIER_UIE && sr & TIM_SR_UIF_Msk)
	{
		capture2Ch1.isrUpdate();
		event = true;
	}

	if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
	{
		capture2Ch1.isrCapture(event);
	}

	if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
	{
		capture2Ch2.isrCapture(event);
	}

	if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
	{
		capture2Ch3.isrCapture(event);
	}

	if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
	{
		capture2Ch4.isrCapture(event);
	}
}
}

#endif



#if CAPTURE12_ENABLE && defined(TIM12)
#if TIM2_ENABLE || PWM2_ENABLE
#error "CAPTURE2, PWM2, TIM2은 동시에 활성화 될 수 없습니다."
#endif
static void setCapture12ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM12EN_Pos, en);
	clock.unlock();
}

static void setCapture12InterruptEn(bool en)
{
	nvic.lock();
#if defined(STM32F746xx)
	nvic.enableInterrupt(TIM8_BRK_TIM12_IRQn, en);
#endif
	nvic.unlock();
}

static void resetCapture12(void)
{
	clock.lock();
    clock.resetApb2(11);
	clock.unlock();
}

static const Drv::Setup gCapture12DrvSetup = 
{
	setCapture12ClockEn,				//void (*clockFunc)(bool en) = 0;
	setCapture12InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetCapture12,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static uint64_t gCapture12UpdateCnt;
static const Capture::Setup gCapture121Setup = 
{
	TIM12,				//YSS_PWM_Peri *peri;
	&gCapture12UpdateCnt	//uint64_t *updateCnt;
};

CaptureCh1 capture12Ch1(gCapture12DrvSetup, gCapture121Setup);
CaptureCh2 capture12Ch2(gCapture12DrvSetup, gCapture121Setup);

extern "C"
{
void TIM8_BRK_TIM12_IRQHandler(void)
{
	bool event = false;
	uint32_t dier = TIM12->DIER, sr = TIM12->SR;

	TIM12->SR = ~sr;

	if (dier & TIM_DIER_UIE && sr & TIM_SR_UIF_Msk)
	{
		capture12Ch1.isrUpdate();
		event = true;
	}

	if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
	{
		capture12Ch1.isrCapture(event);
	}

	if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
	{
		capture12Ch2.isrCapture(event);
	}
}
}

#endif

#endif

