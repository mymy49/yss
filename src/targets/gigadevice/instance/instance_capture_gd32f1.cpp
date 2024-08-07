/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(GD32F1)

#include <config.h>
#include <drv/Capture.h>
#include <yss.h>

#if defined(GD32F10X_MD)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if defined(CAPTURE1_ENABLE) && defined(TIM1)
#if defined(TIM1_ENABLE) || defined(PWM1_ENABLE)
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
#if defined(STM32F746xx) || defined(GD32F10X_MD)
	nvic.enableInterrupt(TIM1_UP_TIM10_IRQn, en);
	nvic.enableInterrupt(TIM1_CC_IRQn, en);
#endif
	nvic.unlock();
}

static void resetCapture1(void)
{
	clock.lock();
    clock.resetApb2(11);
	clock.unlock();
}

static const Drv::setup_t gCapture1DrvSetup = 
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
void TIMER1_UP_IRQHandler(void)
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

void TIMER1_CC_IRQHandler(void)
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



#if defined(CAPTURE2_ENABLE) && defined(TIM2)
#if defined(TIM2_ENABLE) || defined(PWM2_ENABLE)
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

static const Drv::setup_t gCapture2DrvSetup = 
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
void TIMER2_IRQHandler(void)
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



#if defined(CAPTURE12_ENABLE) && defined(TIM12)
#if defined(TIM2_ENABLE) || defined(PWM2_ENABLE)
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

static const Drv::setup_t gCapture12DrvSetup = 
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

