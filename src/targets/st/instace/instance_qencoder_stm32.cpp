/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F7)

#include <config.h>
#include <drv/Qencoder.h>
#include <yss.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#endif

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if QENCODER1_ENABLE && defined(TIM1)
static void setClock1En(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM1EN_Pos, en);
	clock.unlock();
}

static void setInterrupt1En(bool en)
{
	nvic.lock();
#if defined(STM32F446xx) || defined(STM32F746xx)
	nvic.enableInterrupt(TIM1_UP_TIM10_IRQn, en);
#else
#warning "이 항목을 정상적으로 채우세요."
#endif
	nvic.unlock();
}

static void reset1(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB2RSTR_TIM1RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrv1Setup = 
{
	setClock1En,				//void (*clockFunc)(bool en) = 0;
	setInterrupt1En,			//void (*nvicFunc)(bool en) = 0;
	reset1,						//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static const Qencoder::setup_t gSetup1 = 
{
	TIM1,				//YSS_QENCODER_Peri *peri;
};

Qencoder qencoder1(gDrv1Setup, gSetup1);
#endif



#if QENCODER2_ENABLE && defined(TIM2)
static void setClock2En(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM2EN_Pos, en);
	clock.unlock();
}

static void setInterrupt2En(bool en)
{
	nvic.lock();
#if defined(STM32F446xx) || defined(STM32F746xx)
	nvic.enableInterrupt(TIM2_IRQn, en);
#else
#warning "이 항목을 정상적으로 채우세요."
#endif
	nvic.unlock();
}

static void reset2(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_TIM2RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrv2Setup = 
{
	setClock2En,				//void (*clockFunc)(bool en) = 0;
	setInterrupt2En,			//void (*nvicFunc)(bool en) = 0;
	reset2,						//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static const Qencoder::setup_t gSetup2 = 
{
	TIM2,				//YSS_QENCODER_Peri *peri;
};

Qencoder qencoder2(gDrv2Setup, gSetup2);
#endif



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
#if defined(STM32F446xx) || defined(STM32F746xx)
	nvic.enableInterrupt(TIM3_IRQn, en);
#else
#warning "이 항목을 정상적으로 채우세요."
#endif
	nvic.unlock();
}

static void reset3(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_TIM3RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrv3Setup = 
{
	setClock3En,				//void (*clockFunc)(bool en) = 0;
	setInterrupt3En,			//void (*nvicFunc)(bool en) = 0;
	reset3,						//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static const Qencoder::setup_t gSetup3 = 
{
	TIM3,				//YSS_QENCODER_Peri *peri;
};

Qencoder qencoder3(gDrv3Setup, gSetup3);
#endif



#if QENCODER4_ENABLE && defined(TIM4)
static void setClock4En(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM4EN_Pos, en);
	clock.unlock();
}

static void setInterrupt4En(bool en)
{
	nvic.lock();
#if defined(STM32F446xx) || defined(STM32F746xx)
	nvic.enableInterrupt(TIM4_IRQn, en);
#else
#warning "이 항목을 정상적으로 채우세요."
#endif
	nvic.unlock();
}

static void reset4(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_TIM4RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrv4Setup = 
{
	setClock4En,				//void (*clockFunc)(bool en) = 0;
	setInterrupt4En,			//void (*nvicFunc)(bool en) = 0;
	reset4,						//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static const Qencoder::setup_t gSetup4 = 
{
	TIM4,				//YSS_QENCODER_Peri *peri;
};

Qencoder qencoder4(gDrv4Setup, gSetup4);
#endif



#if QENCODER5_ENABLE && defined(TIM5)
static void setClock5En(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM5EN_Pos, en);
	clock.unlock();
}

static void setInterrupt5En(bool en)
{
	nvic.lock();
#if defined(STM32F446xx) || defined(STM32F746xx)
	nvic.enableInterrupt(TIM5_IRQn, en);
#else
#warning "이 항목을 정상적으로 채우세요."
#endif
	nvic.unlock();
}

static void reset5(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_TIM5RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrv5Setup = 
{
	setClock5En,				//void (*clockFunc)(bool en) = 0;
	setInterrupt5En,			//void (*nvicFunc)(bool en) = 0;
	reset5,						//void (*resetFunc)(void) = 0;
	getApb1TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static const Qencoder::setup_t gSetup5 = 
{
	TIM5,				//YSS_QENCODER_Peri *peri;
};

Qencoder qencoder5(gDrv5Setup, gSetup5);
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
#if defined(STM32F446xx) || defined(STM32F746xx)
	nvic.enableInterrupt(TIM8_UP_TIM13_IRQn, en);
#else
#warning "이 항목을 정상적으로 채우세요."
#endif
	nvic.unlock();
}

static void reset8(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB2RSTR_TIM8RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrv8Setup = 
{
	setClock8En,				//void (*clockFunc)(bool en) = 0;
	setInterrupt8En,			//void (*nvicFunc)(bool en) = 0;
	reset8,						//void (*resetFunc)(void) = 0;
	getApb2TimerClockFrequency, //uint32_t (*getClockFunc)(void);
};

static const Qencoder::setup_t gSetup8 = 
{
	TIM8,				//YSS_QENCODER_Peri *peri;
};

Qencoder qencoder8(gDrv8Setup, gSetup8);
#endif

#endif

