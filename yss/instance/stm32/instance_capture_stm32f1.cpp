////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>
#include <yss/instance.h>
#include <config.h>

#if defined(STM32F1)

static uint32_t getTimerApb2ClkFreq(void)
{
	return clock.getTimerApb2ClkFreq();
}

static uint32_t getTimerApb1ClkFreq(void)
{
	return clock.getTimerApb1ClkFreq();
}

#if defined(CAPTURE1_ENABLE) && defined(TIM1)
static void setCapture1ClockEn(bool en)
{
	clock.peripheral.setTimer1En(en);
}

static void setCapture1IntEn(bool en)
{
	nvic.setTimer1En(en);
}

static void resetCapture1(void)
{
	clock.peripheral.resetTimer1();
}

static const Drv::Config gDrvCapture1Config
{
	setCapture1ClockEn,		//void (*clockFunc)(bool en);
	setCapture1IntEn,		//void (*nvicFunc)(bool en);
	resetCapture1,			//void (*resetFunc)(void);
	getTimerApb2ClkFreq		//uint32_t (*getClockFunc)(void);
};
static uint64_t gCapture1UpdateCnt;
static const drv::Capture::Config gCapture1Config
{
	TIM1,				//YSS_PWM_Peri *peri;
	&gCapture1UpdateCnt	//uint64_t *updateCnt;
};

drv::CaptureCh1 capture1Ch1(gDrvCapture1Config, gCapture1Config);
drv::CaptureCh2 capture1Ch2(gDrvCapture1Config, gCapture1Config);
drv::CaptureCh3 capture1Ch3(gDrvCapture1Config, gCapture1Config);
drv::CaptureCh4 capture1Ch4(gDrvCapture1Config, gCapture1Config);

extern "C"
{
	void TIM1_UP_TIM10_IRQHandler(void)
	{
		bool event1 = false;
		uint32_t dier = TIM1->DIER, sr = TIM1->SR;

		if (dier & TIM_DIER_UIE_Msk && sr & TIM_SR_UIF_Msk)
		{
			TIM1->SR = ~TIM_SR_UIF_Msk;
			capture1Ch1.isrUpdate();
			event1 = true;
		}

		if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
		{
			TIM1->SR = ~TIM_SR_CC1IF_Msk;
			capture1Ch1.isrCapture(event1);
		}

		if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
		{
			TIM1->SR = ~TIM_SR_CC2IF_Msk;
			capture1Ch2.isrCapture(event1);
		}

		if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
		{
			TIM1->SR = ~TIM_SR_CC3IF_Msk;
			capture1Ch3.isrCapture(event1);
		}

		if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
		{
			TIM1->SR = ~TIM_SR_CC4IF_Msk;
			capture1Ch4.isrCapture(event1);
		}
	}

	void TIM1_CC_IRQHandler(void)
	{
		bool event1 = false;
		uint32_t dier = TIM1->DIER, sr = TIM1->SR;

		if (TIM1->DIER & TIM_DIER_UIE_Msk && TIM1->SR & TIM_SR_UIF_Msk)
		{
			TIM1->SR = ~TIM_SR_UIF_Msk;
			capture1Ch1.isrUpdate();
			event1 = true;
		}

		if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
		{
			TIM1->SR = ~TIM_SR_CC1IF_Msk;
			capture1Ch1.isrCapture(event1);
		}

		if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
		{
			TIM1->SR = ~TIM_SR_CC2IF_Msk;
			capture1Ch2.isrCapture(event1);
		}

		if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
		{
			TIM1->SR = ~TIM_SR_CC3IF_Msk;
			capture1Ch3.isrCapture(event1);
		}

		if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
		{
			TIM1->SR = ~TIM_SR_CC4IF_Msk;
			capture1Ch4.isrCapture(event1);
		}
	}
}
#endif



#if defined(CAPTURE2_ENABLE) && defined(TIM2)
static void setCapture2ClockEn(bool en)
{
	clock.peripheral.setTimer2En(en);
}

static void setCapture2IntEn(bool en)
{
	nvic.setTimer2En(en);
}

static void resetCapture2(void)
{
	clock.peripheral.resetTimer2();
}

static const Drv::Config gCapture2DrvConfig = 
{
	setCapture2ClockEn,	//void (*clockFunc)(bool en) = 0;
	setCapture2IntEn,	//void (*nvicFunc)(bool en) = 0;
	resetCapture2,		//void (*resetFunc)(void) = 0;
	getTimerApb1ClkFreq	//uint32_t (*getClockFunc)(void);
};

static uint64_t gCapture2UpdateCnt;
static const drv::Capture::Config gCapture2Config = 
{
	TIM2,				//YSS_PWM_Peri *peri;
	&gCapture2UpdateCnt	//uint32_t (*getClockFreq)(void);
};

drv::CaptureCh1 capture2Ch1(gCapture2DrvConfig, gCapture2Config);
drv::CaptureCh2 capture2Ch2(gCapture2DrvConfig, gCapture2Config);
drv::CaptureCh3 capture2Ch3(gCapture2DrvConfig, gCapture2Config);
drv::CaptureCh4 capture2Ch4(gCapture2DrvConfig, gCapture2Config);

extern "C"
{
	void TIM2_IRQHandler(void)
	{
		bool event = false;
		uint32_t dier = TIM2->DIER, sr = TIM2->SR;

		if (dier & TIM_DIER_UIE_Msk && sr & TIM_SR_UIF_Msk)
		{
			TIM2->SR = ~TIM_SR_UIF_Msk;
			capture2Ch1.isrUpdate();
			event = true;
		}

		if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
		{
			TIM2->SR = ~TIM_SR_CC1IF_Msk;
			capture2Ch1.isrCapture(event);
		}

		if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
		{
			TIM2->SR = ~TIM_SR_CC2IF_Msk;
			capture2Ch2.isrCapture(event);
		}

		if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
		{
			TIM2->SR = ~TIM_SR_CC3IF_Msk;
			capture2Ch3.isrCapture(event);
		}

		if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
		{
			TIM2->SR = ~TIM_SR_CC4IF_Msk;
			capture2Ch4.isrCapture(event);
		}
	}
}
#endif



#if defined(CAPTURE3_ENABLE) && defined(TIM3)
static void setCapture3ClockEn(bool en)
{
	clock.peripheral.setTimer3En(en);
}

static void setCapture3IntEn(bool en)
{
	nvic.setTimer3En(en);
}

static void resetCapture3(void)
{
	clock.peripheral.resetTimer3();
}

static const Drv::Config gCapture3DrvConfig = 
{
	setCapture3ClockEn,	//void (*clockFunc)(bool en) = 0;
	setCapture3IntEn,	//void (*nvicFunc)(bool en) = 0;
	resetCapture3,		//void (*resetFunc)(void) = 0;
	getTimerApb1ClkFreq	//uint32_t (*getClockFunc)(void);
};

static uint64_t gCapture3UpdateCnt;
static const drv::Capture::Config gCapture3Config = 
{
	TIM3,				//YSS_PWM_Peri *peri;
	&gCapture3UpdateCnt	//uint32_t (*getClockFreq)(void);
};

drv::CaptureCh1 capture3Ch1(gCapture3DrvConfig, gCapture3Config);
drv::CaptureCh2 capture3Ch2(gCapture3DrvConfig, gCapture3Config);
drv::CaptureCh3 capture3Ch3(gCapture3DrvConfig, gCapture3Config);
drv::CaptureCh4 capture3Ch4(gCapture3DrvConfig, gCapture3Config);

extern "C"
{
	void TIM3_IRQHandler(void)
	{
		bool event = false;
		uint32_t dier = TIM3->DIER, sr = TIM3->SR;

		if (dier & TIM_DIER_UIE_Msk && sr & TIM_SR_UIF_Msk)
		{
			TIM3->SR = ~TIM_SR_UIF_Msk;
			capture3Ch1.isrUpdate();
			event = true;
		}

		if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
		{
			TIM3->SR = ~TIM_SR_CC1IF_Msk;
			capture3Ch1.isrCapture(event);
		}

		if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
		{
			TIM3->SR = ~TIM_SR_CC2IF_Msk;
			capture3Ch2.isrCapture(event);
		}

		if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
		{
			TIM3->SR = ~TIM_SR_CC3IF_Msk;
			capture3Ch3.isrCapture(event);
		}

		if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
		{
			TIM3->SR = ~TIM_SR_CC4IF_Msk;
			capture3Ch4.isrCapture(event);
		}
	}
}
#endif



#if defined(CAPTURE4_ENABLE) && defined(TIM4)
static void setCapture4ClockEn(bool en)
{
	clock.peripheral.setTimer4En(en);
}

static void setCapture4IntEn(bool en)
{
	nvic.setTimer4En(en);
}

static void resetCapture4(void)
{
	clock.peripheral.resetTimer4();
}

static const Drv::Config gCapture4DrvConfig = 
{
	setCapture4ClockEn,	//void (*clockFunc)(bool en) = 0;
	setCapture4IntEn,	//void (*nvicFunc)(bool en) = 0;
	resetCapture4,		//void (*resetFunc)(void) = 0;
	getTimerApb1ClkFreq	//uint32_t (*getClockFunc)(void);
};

static uint64_t gCapture4UpdateCnt;
static const drv::Capture::Config gCapture4Config = 
{
	TIM4,				//YSS_PWM_Peri *peri;
	&gCapture4UpdateCnt	//uint32_t (*getClockFreq)(void);
};

drv::CaptureCh1 capture4Ch1(gCapture4DrvConfig, gCapture4Config);
drv::CaptureCh2 capture4Ch2(gCapture4DrvConfig, gCapture4Config);
drv::CaptureCh3 capture4Ch3(gCapture4DrvConfig, gCapture4Config);
drv::CaptureCh4 capture4Ch4(gCapture4DrvConfig, gCapture4Config);

extern "C"
{
	void TIM4_IRQHandler(void)
	{
		bool event = false;
		uint32_t dier = TIM4->DIER, sr = TIM4->SR;

		if (dier & TIM_DIER_UIE_Msk && sr & TIM_SR_UIF_Msk)
		{
			TIM4->SR = ~TIM_SR_UIF_Msk;
			capture4Ch1.isrUpdate();
			event = true;
		}

		if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
		{
			TIM4->SR = ~TIM_SR_CC1IF_Msk;
			capture4Ch1.isrCapture(event);
		}

		if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
		{
			TIM4->SR = ~TIM_SR_CC2IF_Msk;
			capture4Ch2.isrCapture(event);
		}

		if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
		{
			TIM4->SR = ~TIM_SR_CC3IF_Msk;
			capture4Ch3.isrCapture(event);
		}

		if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
		{
			TIM4->SR = ~TIM_SR_CC4IF_Msk;
			capture4Ch4.isrCapture(event);
		}
	}
}
#endif



#if defined(CAPTURE5_ENABLE) && defined(TIM5)
static void setCapture5ClockEn(bool en)
{
	clock.peripheral.setTimer5En(en);
}

static void setCapture5IntEn(bool en)
{
	nvic.setTimer5En(en);
}

static void resetCapture5(void)
{
	clock.peripheral.resetTimer5();
}

static const Drv::Config gCapture5DrvConfig = 
{
	setCapture5ClockEn,	//void (*clockFunc)(bool en) = 0;
	setCapture5IntEn,	//void (*nvicFunc)(bool en) = 0;
	resetCapture5,		//void (*resetFunc)(void) = 0;
	getTimerApb1ClkFreq	//uint32_t (*getClockFunc)(void);
};

static uint64_t gCapture5UpdateCnt;
static const drv::Capture::Config gCapture5Config = 
{
	TIM5,				//YSS_PWM_Peri *peri;
	&gCapture5UpdateCnt	//uint32_t (*getClockFreq)(void);
};

drv::CaptureCh1 capture5Ch1(gCapture5DrvConfig, gCapture5Config);
drv::CaptureCh2 capture5Ch2(gCapture5DrvConfig, gCapture5Config);
drv::CaptureCh3 capture5Ch3(gCapture5DrvConfig, gCapture5Config);
drv::CaptureCh4 capture5Ch4(gCapture5DrvConfig, gCapture5Config);

extern "C"
{
	void TIM5_IRQHandler(void)
	{
		bool event = false;
		uint32_t dier = TIM5->DIER, sr = TIM5->SR;

		if (dier & TIM_DIER_UIE_Msk && sr & TIM_SR_UIF_Msk)
		{
			TIM5->SR = ~TIM_SR_UIF_Msk;
			capture5Ch1.isrUpdate();
			event = true;
		}

		if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
		{
			TIM5->SR = ~TIM_SR_CC1IF_Msk;
			capture5Ch1.isrCapture(event);
		}

		if (dier & TIM_DIER_CC2IE_Msk && sr & TIM_SR_CC2IF_Msk)
		{
			TIM5->SR = ~TIM_SR_CC2IF_Msk;
			capture5Ch2.isrCapture(event);
		}

		if (dier & TIM_DIER_CC3IE_Msk && sr & TIM_SR_CC3IF_Msk)
		{
			TIM5->SR = ~TIM_SR_CC3IF_Msk;
			capture5Ch3.isrCapture(event);
		}

		if (dier & TIM_DIER_CC4IE_Msk && sr & TIM_SR_CC4IF_Msk)
		{
			TIM5->SR = ~TIM_SR_CC4IF_Msk;
			capture5Ch4.isrCapture(event);
		}
	}
}
#endif

#endif
