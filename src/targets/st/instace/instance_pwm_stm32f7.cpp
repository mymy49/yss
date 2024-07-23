/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)

#include <config.h>
#include <yss/instance.h>
#include <yss.h>
#include <targets/st/bitfield.h>

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if PWM1_ENABLE && defined(TIM1)
#if (1 < TIM1_ENABLE + PWM1_ENABLE + QENCODER1_ENABLE + CAPTURE1_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm1DrvSetup = 
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
#if YSS_TIMER == RUNTIME_TIM2
#error "현재 TIM2는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM2_ENABLE + PWM2_ENABLE + QENCODER2_ENABLE + CAPTURE2_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm2DrvSetup = 
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
#if YSS_TIMER == RUNTIME_TIM3
#error "현재 TIM3는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM3_ENABLE + PWM3_ENABLE + QENCODER3_ENABLE + CAPTURE3_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm3DrvSetup = 
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
#if YSS_TIMER == RUNTIME_TIM4
#error "현재 TIM4는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM4_ENABLE + PWM4_ENABLE + QENCODER4_ENABLE + CAPTURE4_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm4DrvSetup = 
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
#if YSS_TIMER == RUNTIME_TIM5
#error "현재 TIM5는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM5_ENABLE + PWM1_ENABLE + QENCODER1_ENABLE + CAPTURE1_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm5DrvSetup = 
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



#if PWM8_ENABLE && defined(TIM8)
#if (1 < TIM8_ENABLE + PWM8_ENABLE + QENCODER8_ENABLE + CAPTURE8_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm8DrvSetup = 
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
#if YSS_TIMER == RUNTIME_TIM9
#error "현재 TIM9는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM9_ENABLE + PWM9_ENABLE + QENCODER9_ENABLE + CAPTURE9_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm9DrvSetup = 
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
#if (1 < TIM10_ENABLE + PWM10_ENABLE + QENCODER10_ENABLE + CAPTURE10_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm10DrvSetup = 
{
	setPwm10ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm10InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm10,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm10Ch1((YSS_PWM_Peri*)TIM10, gPwm10DrvSetup);
#endif



#if PWM11_ENABLE && defined(TIM11)
#if YSS_TIMER == RUNTIME_TIM11
#error "현재 TIM11는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM11_ENABLE + PWM11_ENABLE + QENCODER11_ENABLE + CAPTURE11_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm11DrvSetup = 
{
	setPwm11ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm11InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm11,					//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);

};

PwmCh1 pwm11Ch1((YSS_PWM_Peri*)TIM11, gPwm11DrvSetup);
#endif



#if PWM12_ENABLE && defined(TIM12)
#if YSS_TIMER == RUNTIME_TIM12
#error "현재 TIM12는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM12_ENABLE + PWM12_ENABLE + QENCODER12_ENABLE + CAPTURE12_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm12DrvSetup = 
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
#if (1 < TIM13_ENABLE + PWM13_ENABLE + QENCODER13_ENABLE + CAPTURE13_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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
	nvic.enableInterrupt(TIM8_UP_TIM13_IRQn, en);
	nvic.unlock();
}

static void resetPwm13(void)
{
	clock.lock();
    clock.resetApb1(7);
	clock.unlock();
}

static const Drv::setup_t gPwm13DrvSetup = 
{
	setPwm13ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm13InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm13,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm13Ch1((YSS_PWM_Peri*)TIM13, gPwm13DrvSetup);
#endif



#if PWM14_ENABLE && defined(TIM14)
#if YSS_TIMER == RUNTIME_TIM14
#error "현재 TIM14는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#elif (1 < TIM14_ENABLE + PWM14_ENABLE + QENCODER14_ENABLE + CAPTURE14_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
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

static const Drv::setup_t gPwm14DrvSetup = 
{
	setPwm14ClockEn,			//void (*clockFunc)(bool en) = 0;
	setPwm14InterruptEn,		//void (*nvicFunc)(bool en) = 0;
	resetPwm14,					//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

PwmCh1 pwm14Ch1((YSS_PWM_Peri*)TIM14, gPwm14DrvSetup);
#endif

#endif

