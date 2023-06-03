////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(GD32F1)

#include <config.h>
#include <yss/instance.h>
#include <yss.h>

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if defined(PWM1_ENABLE) && defined(TIM1)
#if defined(TIM1_ENABLE) || defined(CAPTURE1_ENABLE)
#error "CAPTURE1, PWM1, TIMER1은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm1ClockEn(bool en)
{
	clock.lock();
    clock.enableApb2Clock(11, en);
	clock.unlock();
}

static void setPwm1InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER1_UP_TIMER10_IRQn, en);
	nvic.unlock();
}

static void resetPwm1(void)
{
	clock.lock();
    clock.resetApb2(11);
	clock.unlock();
}

static const Drv::Config gPwm1DrvConfig = 
{
	setPwm1ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm1InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm1,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm1Ch1((YSS_PWM_Peri*)TIMER1, gPwm1DrvConfig);
PwmCh2 pwm1Ch2((YSS_PWM_Peri*)TIMER1, gPwm1DrvConfig);
PwmCh3 pwm1Ch3((YSS_PWM_Peri*)TIMER1, gPwm1DrvConfig);
PwmCh4 pwm1Ch4((YSS_PWM_Peri*)TIMER1, gPwm1DrvConfig);
#endif



#if defined(PWM2_ENABLE) && defined(TIM2)
#if defined(TIM2_ENABLE) || defined(CAPTURE2_ENABLE)
#error "CAPTURE2, PWM2, TIMER2은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm2ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(0, en);
	clock.unlock();
}

static void setPwm2InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER2_IRQn, en);
	nvic.unlock();
}

static void resetPwm2(void)
{
	clock.lock();
    clock.resetApb1(0);
	clock.unlock();
}

static const Drv::Config gPwm2DrvConfig = 
{
	setPwm2ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm2InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm2,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm2Ch1((YSS_PWM_Peri*)TIMER2, gPwm2DrvConfig);
PwmCh2 pwm2Ch2((YSS_PWM_Peri*)TIMER2, gPwm2DrvConfig);
PwmCh3 pwm2Ch3((YSS_PWM_Peri*)TIMER2, gPwm2DrvConfig);
PwmCh4 pwm2Ch4((YSS_PWM_Peri*)TIMER2, gPwm2DrvConfig);
#endif



#if defined(PWM3_ENABLE) && defined(TIM3)
#if defined(TIM3_ENABLE) || defined(CAPTURE3_ENABLE)
#error "CAPTURE3, PWM3, TIMER3은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm3ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(1, en);
	clock.unlock();
}

static void setPwm3InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM3_IRQn, en);
	nvic.unlock();
}

static void resetPwm3(void)
{
	clock.lock();
    clock.resetApb1(1);
	clock.unlock();
}

static const Drv::Config gPwm3DrvConfig = 
{
	setPwm3ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm3InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm3,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm3Ch1((YSS_PWM_Peri*)TIM3, gPwm3DrvConfig);
PwmCh2 pwm3Ch2((YSS_PWM_Peri*)TIM3, gPwm3DrvConfig);
PwmCh3 pwm3Ch3((YSS_PWM_Peri*)TIM3, gPwm3DrvConfig);
PwmCh4 pwm3Ch4((YSS_PWM_Peri*)TIM3, gPwm3DrvConfig);
#endif



#if defined(PWM4_ENABLE) && defined(TIM4)
#if defined(TIM4_ENABLE) || defined(CAPTURE4_ENABLE)
#error "CAPTURE4, PWM4, TIMER4은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm4ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(2, en);
	clock.unlock();
}

static void setPwm4InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER4_IRQn, en);
	nvic.unlock();
}

static void resetPwm4(void)
{
	clock.lock();
    clock.resetApb1(2);
	clock.unlock();
}

static const Drv::Config gPwm4DrvConfig = 
{
	setPwm4ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm4InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm4,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm4Ch1((YSS_PWM_Peri*)TIMER4, gPwm4DrvConfig);
PwmCh2 pwm4Ch2((YSS_PWM_Peri*)TIMER4, gPwm4DrvConfig);
PwmCh3 pwm4Ch3((YSS_PWM_Peri*)TIMER4, gPwm4DrvConfig);
PwmCh4 pwm4Ch4((YSS_PWM_Peri*)TIMER4, gPwm4DrvConfig);
#endif



#if defined(PWM5_ENABLE) && defined(TIM5)
#if defined(TIM5_ENABLE) || defined(CAPTURE5_ENABLE)
#error "CAPTURE5, PWM5, TIMER5은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm5ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(3, en);
	clock.unlock();
}

static void setPwm5InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER5_IRQn, en);
	nvic.unlock();
}

static void resetPwm5(void)
{
	clock.lock();
    clock.resetApb1(3);
	clock.unlock();
}

static const Drv::Config gPwm5DrvConfig = 
{
	setPwm5ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm5InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm5,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm5Ch1((YSS_PWM_Peri*)TIMER5, gPwm4DrvConfig);
PwmCh2 pwm5Ch2((YSS_PWM_Peri*)TIMER5, gPwm4DrvConfig);
PwmCh3 pwm5Ch3((YSS_PWM_Peri*)TIMER5, gPwm4DrvConfig);
PwmCh4 pwm5Ch4((YSS_PWM_Peri*)TIMER5, gPwm4DrvConfig);
#endif



#if defined(PWM6_ENABLE)
#error "Timer6은 PWM을 지원하지 않습니다."
#endif



#if defined(PWM7_ENABLE)
#error "Timer7은 PWM을 지원하지 않습니다."
#endif



#if defined(PWM8_ENABLE) && defined(TIM8)
#if defined(TIM8_ENABLE) || defined(CAPTURE8_ENABLE)
#error "CAPTURE8, PWM8, TIMER8은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm8ClockEn(bool en)
{
	clock.lock();
    clock.enableApb2Clock(13, en);
	clock.unlock();
}

static void setPwm8InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER8_UP_TIMER13_IRQn, en);
	nvic.unlock();
}

static void resetPwm8(void)
{
	clock.lock();
    clock.resetApb2(13);
	clock.unlock();
}

static const Drv::Config gPwm8DrvConfig = 
{
	setPwm8ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm8InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm8,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm8Ch1((YSS_PWM_Peri*)TIMER8, gPwm8DrvConfig);
PwmCh2 pwm8Ch2((YSS_PWM_Peri*)TIMER8, gPwm8DrvConfig);
PwmCh3 pwm8Ch3((YSS_PWM_Peri*)TIMER8, gPwm8DrvConfig);
PwmCh4 pwm8Ch4((YSS_PWM_Peri*)TIMER8, gPwm8DrvConfig);
#endif



#if defined(PWM9_ENABLE) && defined(TIM9)
#if defined(TIM9_ENABLE) || defined(CAPTURE9_ENABLE)
#error "CAPTURE9, PWM9, TIMER9은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm9ClockEn(bool en)
{
	clock.lock();
    clock.enableApb2Clock(19, en);
	clock.unlock();
}

static void setPwm9InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER1_BRK_TIMER9_IRQn, en);
	nvic.unlock();
}

static void resetPwm9(void)
{
	clock.lock();
    clock.resetApb2(19);
	clock.unlock();
}

static const Drv::Config gPwm9DrvConfig = 
{
	setPwm9ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm9InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm9,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm9Ch1((YSS_PWM_Peri*)TIMER9, gPwm9DrvConfig);
PwmCh2 pwm9Ch2((YSS_PWM_Peri*)TIMER9, gPwm9DrvConfig);
#endif



#if defined(PWM10_ENABLE) && defined(TIM10)
#if defined(TIM10_ENABLE) || defined(CAPTURE10_ENABLE)
#error "CAPTURE10, PWM10, TIMER10은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm10ClockEn(bool en)
{
	clock.lock();
    clock.enableApb2Clock(20, en);
	clock.unlock();
}

static void setPwm10InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER1_UP_TIMER10_IRQn, en);
	nvic.unlock();
}

static void resetPwm10(void)
{
	clock.lock();
    clock.resetApb2(20);
	clock.unlock();
}

static const Drv::Config gPwm10DrvConfig = 
{
	setPwm10ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm10InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm10,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm10Ch1((YSS_PWM_Peri*)TIMER10, gPwm10DrvConfig);
#endif



#if defined(PWM11_ENABLE) && defined(TIM11)
#if defined(TIM11_ENABLE) || defined(CAPTURE11_ENABLE)
#error "CAPTURE11, PWM11, TIMER11은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm11ClockEn(bool en)
{
	clock.lock();
    clock.enableApb2Clock(21, en);
	clock.unlock();
}

static void setPwm11InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER1_TRG_COM_TIMER11_IRQn, en);
	nvic.unlock();
}

static void resetPwm11(void)
{
	clock.lock();
    clock.resetApb2(21);
	clock.unlock();
}

static const Drv::Config gPwm11DrvConfig = 
{
	setPwm11ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm11InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm11,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);

};

PwmCh1 pwm11Ch1((YSS_PWM_Peri*)TIMER11, gPwm11DrvConfig);
#endif



#if defined(PWM12_ENABLE) && defined(TIM12)
#if defined(TIM12_ENABLE) || defined(CAPTURE12_ENABLE)
#error "CAPTURE12, PWM12, TIMER12은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm12ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(6, en);
	clock.unlock();
}

static void setPwm12InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER8_BRK_TIMER12_IRQn, en);
	nvic.unlock();
}

static void resetPwm12(void)
{
	clock.lock();
    clock.resetApb1(6);
	clock.unlock();
}

static const Drv::Config gPwm12DrvConfig = 
{
	setPwm12ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm12InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm12,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm12Ch1((YSS_PWM_Peri*)TIMER12, gPwm12DrvConfig);
PwmCh2 pwm12Ch2((YSS_PWM_Peri*)TIMER12, gPwm12DrvConfig);
#endif



#if defined(PWM13_ENABLE) && defined(TIM13)
#if defined(TIM13_ENABLE) || defined(CAPTURE13_ENABLE)
#error "CAPTURE13, PWM13, TIMER13은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm13ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(7, en);
	clock.unlock();
}

static void setPwm13InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER8_UP_TIMER13_IRQn, en);
	nvic.unlock();
}

static void resetPwm13(void)
{
	clock.lock();
    clock.resetApb1(7);
	clock.unlock();
}

static const Drv::Config gPwm13DrvConfig = 
{
	setPwm13ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm13InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm13,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm13Ch1((YSS_PWM_Peri*)TIMER13, gPwm13DrvConfig);
#endif



#if defined(PWM14_ENABLE) && defined(TIM14)
#if defined(TIM14_ENABLE) || defined(CAPTURE14_ENABLE)
#error "CAPTURE14, PWM14, TIMER14은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm14ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(8, en);
	clock.unlock();
}

static void setPwm14InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER8_TRG_COM_TIMER14_IRQn, en);
	nvic.unlock();
}

static void resetPwm14(void)
{
	clock.lock();
    clock.resetApb1(8);
	clock.unlock();
}

static const Drv::Config gPwm14DrvConfig = 
{
	setPwm14ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm14InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm14,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm14Ch1((YSS_PWM_Peri*)TIMER14, gPwm14DrvConfig);
#endif

#endif

