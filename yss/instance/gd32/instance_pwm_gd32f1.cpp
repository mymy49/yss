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

#if defined(GD32F1)

static unsigned int getTimerApb2ClkFreq(void)
{
	return clock.getTimerApb2ClkFreq();
}

static unsigned int getTimerApb1ClkFreq(void)
{
	return clock.getTimerApb1ClkFreq();
}



#if defined(PWM1_ENABLE) && defined(TIMER1)
#if defined(TIM1_ENABLE) || defined(CAPTURE1_ENABLE)
#error "CAPTURE1, PWM1, TIMER1은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm1ClockEn(bool en)
{
	clock.peripheral.setTimer1En(en);
}

static void setPwm1InterruptEn(bool en)
{
	nvic.setTimer1En(en);
}

static void resetPwm1(void)
{
	clock.peripheral.resetTimer1();
}

static const Drv::Config gPwm1DrvConfig = 
{
	setPwm1ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm1InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm1			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm1Config = 
{
	(volatile unsigned int*)TIMER1,	//YSS_PWM_Peri *peri;
	getTimerApb2ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm1Ch1(gPwm1DrvConfig, gPwm1Config);
PwmCh2 pwm1Ch2(gPwm1DrvConfig, gPwm1Config);
PwmCh3 pwm1Ch3(gPwm1DrvConfig, gPwm1Config);
PwmCh4 pwm1Ch4(gPwm1DrvConfig, gPwm1Config);
#endif



#if defined(PWM2_ENABLE) && defined(TIMER2)
#if defined(TIM2_ENABLE) || defined(CAPTURE2_ENABLE)
#error "CAPTURE2, PWM2, TIMER2은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm2ClockEn(bool en)
{
	clock.peripheral.setTimer2En(en);
}

static void setPwm2InterruptEn(bool en)
{
	nvic.setTimer2En(en);
}

static void resetPwm2(void)
{
	clock.peripheral.resetTimer2();
}

static const Drv::Config gPwm2DrvConfig = 
{
	setPwm2ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm2InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm2			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm2Config = 
{
	(volatile unsigned int*)TIMER2,	//YSS_PWM_Peri *peri;
	getTimerApb1ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm2Ch1(gPwm2DrvConfig, gPwm2Config);
PwmCh2 pwm2Ch2(gPwm2DrvConfig, gPwm2Config);
PwmCh3 pwm2Ch3(gPwm2DrvConfig, gPwm2Config);
PwmCh4 pwm2Ch4(gPwm2DrvConfig, gPwm2Config);
#endif



#if defined(PWM3_ENABLE) && defined(TIMER3)
#if defined(TIM3_ENABLE) || defined(CAPTURE3_ENABLE)
#error "CAPTURE3, PWM3, TIMER3은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm3ClockEn(bool en)
{
	clock.peripheral.setTimer3En(en);
}

static void setPwm3InterruptEn(bool en)
{
	nvic.setTimer3En(en);
}

static void resetPwm3(void)
{
	clock.peripheral.resetTimer3();
}

static const Drv::Config gPwm3DrvConfig = 
{
	setPwm3ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm3InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm3			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm3Config = 
{
	(volatile unsigned int*)TIMER3,	//YSS_PWM_Peri *peri;
	getTimerApb1ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm3Ch1(gPwm3DrvConfig, gPwm3Config);
PwmCh2 pwm3Ch2(gPwm3DrvConfig, gPwm3Config);
PwmCh3 pwm3Ch3(gPwm3DrvConfig, gPwm3Config);
PwmCh4 pwm3Ch4(gPwm3DrvConfig, gPwm3Config);
#endif



#if defined(PWM4_ENABLE) && defined(TIMER4)
#if defined(TIM4_ENABLE) || defined(CAPTURE4_ENABLE)
#error "CAPTURE4, PWM4, TIMER4은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm4ClockEn(bool en)
{
	clock.peripheral.setTimer4En(en);
}

static void setPwm4InterruptEn(bool en)
{
	nvic.setTimer4En(en);
}

static void resetPwm4(void)
{
	clock.peripheral.resetTimer4();
}

static const Drv::Config gPwm4DrvConfig = 
{
	setPwm4ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm4InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm4			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm4Config = 
{
	(volatile unsigned int*)TIMER4,	//YSS_PWM_Peri *peri;
	getTimerApb1ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm4Ch1(gPwm4DrvConfig, gPwm4Config);
PwmCh2 pwm4Ch2(gPwm4DrvConfig, gPwm4Config);
PwmCh3 pwm4Ch3(gPwm4DrvConfig, gPwm4Config);
PwmCh4 pwm4Ch4(gPwm4DrvConfig, gPwm4Config);
#endif



#if defined(PWM5_ENABLE) && defined(TIMER5)
#if defined(TIM5_ENABLE) || defined(CAPTURE5_ENABLE)
#error "CAPTURE5, PWM5, TIMER5은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm5ClockEn(bool en)
{
	clock.peripheral.setTimer5En(en);
}

static void setPwm5InterruptEn(bool en)
{
	nvic.setTimer5En(en);
}

static void resetPwm5(void)
{
	clock.peripheral.resetTimer5();
}

static const Drv::Config gPwm5DrvConfig = 
{
	setPwm5ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm5InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm5			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm5Config = 
{
	(volatile unsigned int*)TIMER5,	//YSS_PWM_Peri *peri;
	getTimerApb1ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm5Ch1(gPwm4DrvConfig, gPwm5Config);
PwmCh2 pwm5Ch2(gPwm4DrvConfig, gPwm5Config);
PwmCh3 pwm5Ch3(gPwm4DrvConfig, gPwm5Config);
PwmCh4 pwm5Ch4(gPwm4DrvConfig, gPwm5Config);
#endif



#if defined(PWM6_ENABLE)
#error "Timer6은 PWM을 지원하지 않습니다."
#endif



#if defined(PWM7_ENABLE)
#error "Timer7은 PWM을 지원하지 않습니다."
#endif



#if defined(PWM8_ENABLE) && defined(TIMER8)
#if defined(TIM8_ENABLE) || defined(CAPTURE8_ENABLE)
#error "CAPTURE8, PWM8, TIMER8은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm8ClockEn(bool en)
{
	clock.peripheral.setTimer8En(en);
}

static void setPwm8InterruptEn(bool en)
{
	nvic.setTimer8En(en);
}

static void resetPwm8(void)
{
	clock.peripheral.resetTimer8();
}

static const Drv::Config gPwm8DrvConfig = 
{
	setPwm8ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm8InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm8			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm8Config = 
{
	(volatile unsigned int*)TIMER8,	//YSS_PWM_Peri *peri;
	getTimerApb2ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm8Ch1(gPwm8DrvConfig, gPwm8Config);
PwmCh2 pwm8Ch2(gPwm8DrvConfig, gPwm8Config);
PwmCh3 pwm8Ch3(gPwm8DrvConfig, gPwm8Config);
PwmCh4 pwm8Ch4(gPwm8DrvConfig, gPwm8Config);
#endif



#if defined(PWM9_ENABLE) && defined(TIMER9)
#if defined(TIM9_ENABLE) || defined(CAPTURE9_ENABLE)
#error "CAPTURE9, PWM9, TIMER9은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm9ClockEn(bool en)
{
	clock.peripheral.setTimer9En(en);
}

static void setPwm9InterruptEn(bool en)
{
	nvic.setTimer9En(en);
}

static void resetPwm9(void)
{
	clock.peripheral.resetTimer9();
}

static const Drv::Config gPwm9DrvConfig = 
{
	setPwm9ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm9InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm9			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm9Config = 
{
	(volatile unsigned int*)TIMER9,	//YSS_PWM_Peri *peri;
	getTimerApb2ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm9Ch1(gPwm9DrvConfig, gPwm9Config);
PwmCh2 pwm9Ch2(gPwm9DrvConfig, gPwm9Config);
#endif



#if defined(PWM10_ENABLE) && defined(TIMER10)
#if defined(TIM10_ENABLE) || defined(CAPTURE10_ENABLE)
#error "CAPTURE10, PWM10, TIMER10은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm10ClockEn(bool en)
{
	clock.peripheral.setTimer10En(en);
}

static void setPwm10InterruptEn(bool en)
{
	nvic.setTimer10En(en);
}

static void resetPwm10(void)
{
	clock.peripheral.resetTimer10();
}

static const Drv::Config gPwm10DrvConfig = 
{
	setPwm10ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm10InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm10			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm10Config = 
{
	(volatile unsigned int*)TIMER10,	//YSS_PWM_Peri *peri;
	getTimerApb2ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm10Ch1(gPwm10DrvConfig, gPwm10Config);
#endif



#if defined(PWM11_ENABLE) && defined(TIMER11)
#if defined(TIM11_ENABLE) || defined(CAPTURE11_ENABLE)
#error "CAPTURE11, PWM11, TIMER11은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm11ClockEn(bool en)
{
	clock.peripheral.setTimer11En(en);
}

static void setPwm11InterruptEn(bool en)
{
	nvic.setTimer11En(en);
}

static void resetPwm11(void)
{
	clock.peripheral.resetTimer11();
}

static const Drv::Config gPwm11DrvConfig = 
{
	setPwm11ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm11InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm11			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm11Config = 
{
	(volatile unsigned int*)TIMER11,	//YSS_PWM_Peri *peri;
	getTimerApb2ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm11Ch1(gPwm11DrvConfig, gPwm11Config);
#endif



#if defined(PWM12_ENABLE) && defined(TIMER12)
#if defined(TIM12_ENABLE) || defined(CAPTURE12_ENABLE)
#error "CAPTURE12, PWM12, TIMER12은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm12ClockEn(bool en)
{
	clock.peripheral.setTimer12En(en);
}

static void setPwm12InterruptEn(bool en)
{
	nvic.setTimer12En(en);
}

static void resetPwm12(void)
{
	clock.peripheral.resetTimer12();
}

static const Drv::Config gPwm12DrvConfig = 
{
	setPwm12ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm12InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm12			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm12Config = 
{
	(volatile unsigned int*)TIMER12,	//YSS_PWM_Peri *peri;
	getTimerApb1ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm12Ch1(gPwm12DrvConfig, gPwm12Config);
PwmCh2 pwm12Ch2(gPwm12DrvConfig, gPwm12Config);
#endif



#if defined(PWM13_ENABLE) && defined(TIMER13)
#if defined(TIM13_ENABLE) || defined(CAPTURE13_ENABLE)
#error "CAPTURE13, PWM13, TIMER13은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm13ClockEn(bool en)
{
	clock.peripheral.setTimer13En(en);
}

static void setPwm13InterruptEn(bool en)
{
	nvic.setTimer13En(en);
}

static void resetPwm13(void)
{
	clock.peripheral.resetTimer13();
}

static const Drv::Config gPwm13DrvConfig = 
{
	setPwm13ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm13InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm13			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm13Config = 
{
	(volatile unsigned int*)TIMER13,	//YSS_PWM_Peri *peri;
	getTimerApb1ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm13Ch1(gPwm13DrvConfig, gPwm13Config);
#endif



#if defined(PWM14_ENABLE) && defined(TIMER14)
#if defined(TIM14_ENABLE) || defined(CAPTURE14_ENABLE)
#error "CAPTURE14, PWM14, TIMER14은 동시에 활성화 될 수 없습니다."
#endif
static void setPwm14ClockEn(bool en)
{
	clock.peripheral.setTimer14En(en);
}

static void setPwm14InterruptEn(bool en)
{
	nvic.setTimer14En(en);
}

static void resetPwm14(void)
{
	clock.peripheral.resetTimer14();
}

static const Drv::Config gPwm14DrvConfig = 
{
	setPwm14ClockEn,		//void (*clockFunc)(bool en) = 0;
	setPwm14InterruptEn,	//void (*nvicFunc)(bool en) = 0;
	resetPwm14			//void (*resetFunc)(void) = 0;
};

static const Pwm::Config gPwm14Config = 
{
	(volatile unsigned int*)TIMER14,	//YSS_PWM_Peri *peri;
	getTimerApb1ClkFreq	//unsigned int (*getClockFreq)(void);
};

PwmCh1 pwm14Ch1(gPwm14DrvConfig, gPwm14Config);
#endif

#endif

