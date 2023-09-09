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

#if defined(STM32F7_N) || defined(STM32F1_N) || defined(STM32F4_N)

#include <config.h>
#include <yss/instance.h>
#include <yss.h>

#if defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(STM32F103xB)
#include <targets/st/bitfield_stm32f103xx.h>
#elif defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#endif

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if PWM1_ENABLE && defined(TIM1)
#if TIM1_ENABLE || CAPTURE1_ENABLE
#error "CAPTURE1, PWM1, TIMER1은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm1ClockEn(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM1EN_Pos, en);
	clock.unlock();
}

static void setPwm1InterruptEn(bool en)
{
	nvic.lock();
#if defined(STM32F767xx) || defined(STM32F746xx)
	nvic.enableInterrupt(TIM1_UP_TIM10_IRQn, en);
#endif
	nvic.unlock();
}

static void resetPwm1(void)
{
	clock.lock();
    clock.resetApb2(11);
	clock.unlock();
}

static const Drv::Setup gPwm1DrvSetup = 
{
	setPwm1ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm1InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm1,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm1Ch1((YSS_PWM_Peri*)TIM1, gPwm1DrvSetup);
PwmCh2 pwm1Ch2((YSS_PWM_Peri*)TIM1, gPwm1DrvSetup);
PwmCh3 pwm1Ch3((YSS_PWM_Peri*)TIM1, gPwm1DrvSetup);
PwmCh4 pwm1Ch4((YSS_PWM_Peri*)TIM1, gPwm1DrvSetup);
#endif



#if PWM2_ENABLE && defined(TIM2)
#if TIM2_ENABLE || CAPTURE2_ENABLE
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
	nvic.enableInterrupt(TIM2_IRQn, en);
	nvic.unlock();
}

static void resetPwm2(void)
{
	clock.lock();
    clock.resetApb1(0);
	clock.unlock();
}

static const Drv::Setup gPwm2DrvSetup = 
{
	setPwm2ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm2InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm2,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm2Ch1((YSS_PWM_Peri*)TIM2, gPwm2DrvSetup);
PwmCh2 pwm2Ch2((YSS_PWM_Peri*)TIM2, gPwm2DrvSetup);
PwmCh3 pwm2Ch3((YSS_PWM_Peri*)TIM2, gPwm2DrvSetup);
PwmCh4 pwm2Ch4((YSS_PWM_Peri*)TIM2, gPwm2DrvSetup);
#endif



#if PWM3_ENABLE && defined(TIM3)
#if TIM3_ENABLE || CAPTURE3_ENABLE
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

static const Drv::Setup gPwm3DrvSetup = 
{
	setPwm3ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm3InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm3,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm3Ch1((YSS_PWM_Peri*)TIM3, gPwm3DrvSetup);
PwmCh2 pwm3Ch2((YSS_PWM_Peri*)TIM3, gPwm3DrvSetup);
PwmCh3 pwm3Ch3((YSS_PWM_Peri*)TIM3, gPwm3DrvSetup);
PwmCh4 pwm3Ch4((YSS_PWM_Peri*)TIM3, gPwm3DrvSetup);
#endif



#if PWM4_ENABLE && defined(TIM4)
#if TIM4_ENABLE || CAPTURE4_ENABLE
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
	nvic.enableInterrupt(TIM4_IRQn, en);
	nvic.unlock();
}

static void resetPwm4(void)
{
	clock.lock();
    clock.resetApb1(2);
	clock.unlock();
}

static const Drv::Setup gPwm4DrvSetup = 
{
	setPwm4ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm4InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm4,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm4Ch1((YSS_PWM_Peri*)TIM4, gPwm4DrvSetup);
PwmCh2 pwm4Ch2((YSS_PWM_Peri*)TIM4, gPwm4DrvSetup);
PwmCh3 pwm4Ch3((YSS_PWM_Peri*)TIM4, gPwm4DrvSetup);
PwmCh4 pwm4Ch4((YSS_PWM_Peri*)TIM4, gPwm4DrvSetup);
#endif



#if PWM5_ENABLE && defined(TIM5)
#if TIM5_ENABLE || CAPTURE5_ENABLE
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
	nvic.enableInterrupt(TIM5_IRQn, en);
	nvic.unlock();
}

static void resetPwm5(void)
{
	clock.lock();
    clock.resetApb1(3);
	clock.unlock();
}

static const Drv::Setup gPwm5DrvSetup = 
{
	setPwm5ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm5InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm5,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm5Ch1((YSS_PWM_Peri*)TIM5, gPwm5DrvSetup);
PwmCh2 pwm5Ch2((YSS_PWM_Peri*)TIM5, gPwm5DrvSetup);
PwmCh3 pwm5Ch3((YSS_PWM_Peri*)TIM5, gPwm5DrvSetup);
PwmCh4 pwm5Ch4((YSS_PWM_Peri*)TIM5, gPwm5DrvSetup);
#endif



#if PWM6_ENABLE
#error "Timer6은 PWM을 지원하지 않습니다."
#endif



#if PWM7_ENABLE
#error "Timer7은 PWM을 지원하지 않습니다."
#endif



#if PWM8_ENABLE && defined(TIM8)
#if TIM8_ENABLE || CAPTURE8_ENABLE
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
	nvic.enableInterrupt(TIM8_UP_TIM13_IRQn, en);
	nvic.unlock();
}

static void resetPwm8(void)
{
	clock.lock();
    clock.resetApb2(13);
	clock.unlock();
}

static const Drv::Setup gPwm8DrvSetup = 
{
	setPwm8ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm8InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm8,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm8Ch1((YSS_PWM_Peri*)TIM8, gPwm8DrvSetup);
PwmCh2 pwm8Ch2((YSS_PWM_Peri*)TIM8, gPwm8DrvSetup);
PwmCh3 pwm8Ch3((YSS_PWM_Peri*)TIM8, gPwm8DrvSetup);
PwmCh4 pwm8Ch4((YSS_PWM_Peri*)TIM8, gPwm8DrvSetup);
#endif



#if PWM9_ENABLE && defined(TIM9)
#if TIM9_ENABLE || CAPTURE9_ENABLE
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
	nvic.enableInterrupt(TIM1_BRK_TIM9_IRQn, en);
	nvic.unlock();
}

static void resetPwm9(void)
{
	clock.lock();
    clock.resetApb2(19);
	clock.unlock();
}

static const Drv::Setup gPwm9DrvSetup = 
{
	setPwm9ClockEn,				//void (*clockFunc)(bool en) = 0;
	setPwm9InterruptEn,			//void (*nvicFunc)(bool en) = 0;
	resetPwm9,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm9Ch1((YSS_PWM_Peri*)TIM9, gPwm9DrvSetup);
PwmCh2 pwm9Ch2((YSS_PWM_Peri*)TIM9, gPwm9DrvSetup);
#endif


#if PWM10_ENABLE && defined(TIM10)
#if TIM10_ENABLE || CAPTURE10_ENABLE
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
	nvic.enableInterrupt(TIM1_UP_TIM10_IRQn, en);
	nvic.unlock();
}

static void resetPwm10(void)
{
	clock.lock();
    clock.resetApb2(20);
	clock.unlock();
}

static const Drv::Setup gPwm10DrvSetup = 
{
	setPwm10ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm10InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm10,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm10Ch1((YSS_PWM_Peri*)TIM10, gPwm10DrvSetup);
#endif



#if PWM11_ENABLE && defined(TIM11)
#if TIM11_ENABLE || CAPTURE11_ENABLE
#error "CAPTURE11, PWM11, TIMER11은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm11ClockEn(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM11EN_Pos, en);
	clock.unlock();
}

static void setPwm11InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM1_TRG_COM_TIM11_IRQn, en);
	nvic.unlock();
}

static void resetPwm11(void)
{
	clock.lock();
    clock.resetApb2(21);
	clock.unlock();
}

static const Drv::Setup gPwm11DrvSetup = 
{
	setPwm11ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm11InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm11,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);

};

PwmCh1 pwm11Ch1((YSS_PWM_Peri*)TIM11, gPwm11DrvSetup);
#endif



#if PWM12_ENABLE && defined(TIM12)
#if TIM12_ENABLE || CAPTURE12_ENABLE
#error "CAPTURE12, PWM12, TIMER12은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm12ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM12EN_Pos, en);
	clock.unlock();
}

static void setPwm12InterruptEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM8_BRK_TIM12_IRQn, en);
	nvic.unlock();
}

static void resetPwm12(void)
{
	clock.lock();
    clock.resetApb1(6);
	clock.unlock();
}

static const Drv::Setup gPwm12DrvSetup = 
{
	setPwm12ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm12InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm12,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm12Ch1((YSS_PWM_Peri*)TIM12, gPwm12DrvSetup);
PwmCh2 pwm12Ch2((YSS_PWM_Peri*)TIM12, gPwm12DrvSetup);
#endif



#if PWM13_ENABLE && defined(TIM13)
#if TIM13_ENABLE || CAPTURE13_ENABLE
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

static const Drv::Setup gPwm13DrvSetup = 
{
	setPwm13ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm13InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm13,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm13Ch1((YSS_PWM_Peri*)TIMER13, gPwm13DrvSetup);
#endif



#if PWM14_ENABLE && defined(TIM14)
#if TIM14_ENABLE || CAPTURE14_ENABLE
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
	nvic.enableInterrupt(TIM8_TRG_COM_TIM14_IRQn, en);
	nvic.unlock();
}

static void resetPwm14(void)
{
	clock.lock();
    clock.resetApb1(8);
	clock.unlock();
}

static const Drv::Setup gPwm14DrvSetup = 
{
	setPwm14ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm14InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm14,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm14Ch1((YSS_PWM_Peri*)TIM14, gPwm14DrvSetup);
#endif

#endif

