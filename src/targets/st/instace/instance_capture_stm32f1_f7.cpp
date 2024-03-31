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

#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)

#include <config.h>
#include <drv/Capture.h>
#include <yss.h>
#include <targets/st/bitfield.h>

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if CAPTURE1_ENABLE && defined(TIM1)
#if YSS_TIMER == RUNTIME_TIM1
#error "현재 TIM1는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM1_ENABLE + PWM1_ENABLE + QENCODER1_ENABLE + CAPTURE1_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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
#if defined(STM32F746xx) || defined(STM32F446xx)
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
static const Capture::setup_t gCapture11Setup = 
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
#if YSS_TIMER == RUNTIME_TIM2
#error "현재 TIM2는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM2_ENABLE + PWM2_ENABLE + QENCODER2_ENABLE + CAPTURE2_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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
#if defined(STM32F746xx) || defined(STM32F1)
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
static const Capture::setup_t gCapture2Setup = 
{
	TIM2,				//YSS_PWM_Peri *peri;
	&gCapture2UpdateCnt	//uint64_t *updateCnt;
};

CaptureCh1 capture2Ch1(gCapture2DrvSetup, gCapture2Setup);
CaptureCh2 capture2Ch2(gCapture2DrvSetup, gCapture2Setup);
CaptureCh3 capture2Ch3(gCapture2DrvSetup, gCapture2Setup);
CaptureCh4 capture2Ch4(gCapture2DrvSetup, gCapture2Setup);

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



#if CAPTURE5_ENABLE && defined(TIM5)
#if YSS_TIMER == RUNTIME_TIM5
#error "현재 TIM5는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM5_ENABLE + PWM5_ENABLE + QENCODER5_ENABLE + CAPTURE5_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void setCapture5ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM5EN_Pos, en);
	clock.unlock();
}

static void setCapture5InterruptEn(bool en)
{
	nvic.lock();
#if defined(STM32F746xx) || defined(STM32F1) || defined(STM32F4)
	nvic.enableInterrupt(TIM5_IRQn, en);
#endif
	nvic.unlock();
}

static void resetCapture5(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_TIM5RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gCapture5DrvSetup = 
{
	setCapture5ClockEn,				//void (*clockFunc)(bool en) = 0;
	setCapture5InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetCapture5,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static uint64_t gCapture5UpdateCnt;
static const Capture::setup_t gCapture5Setup = 
{
	TIM5,				//YSS_PWM_Peri *peri;
	&gCapture5UpdateCnt	//uint64_t *updateCnt;
};

CaptureCh1 capture5Ch1(gCapture5DrvSetup, gCapture5Setup);
CaptureCh2 capture5Ch2(gCapture5DrvSetup, gCapture5Setup);
CaptureCh3 capture5Ch3(gCapture5DrvSetup, gCapture5Setup);
CaptureCh4 capture5Ch4(gCapture5DrvSetup, gCapture5Setup);

extern "C"
{
void TIM5_IRQHandler(void)
{
	bool event = false;
	uint32_t dier = TIM5->DIER, sr = TIM5->SR;

	TIM5->SR = ~sr;

	if (dier & TIM_DIER_UIE && sr & TIM_SR_UIF_Msk)
	{
		capture5Ch1.isrUpdate();
		event = true;
	}

	if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
	{
		capture5Ch1.isrCapture(event);
	}

	if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
	{
		capture5Ch2.isrCapture(event);
	}

	if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
	{
		capture5Ch3.isrCapture(event);
	}

	if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
	{
		capture5Ch4.isrCapture(event);
	}
}
}

#endif



#if CAPTURE12_ENABLE && defined(TIM12)
#if YSS_TIMER == RUNTIME_TIM12
#error "현재 TIM12는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM12_ENABLE + PWM12_ENABLE + QENCODER12_ENABLE + CAPTURE12_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

