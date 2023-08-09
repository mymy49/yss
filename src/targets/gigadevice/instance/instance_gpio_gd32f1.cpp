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

#include <yss/instance.h>

#if defined(GD32F1)

#include <config.h>
#include <yss/instance.h>
#include <yss.h>
#include <targets/st/bitfield_stm32f103xx.h>

using namespace define::gpio;

const static Drv::Setup gDrvSetupGpio =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

#if defined(GPIOA)
const static Gpio::Setup gConfigGpioA =
{
	GPIOA,		//YSS_GPIO_Peri *dev;
	Exti::PORTA	//uint8_t port;
};

Gpio gpioA(gDrvSetupGpio, gConfigGpioA);
#endif

#if defined(GPIOB)
const static Gpio::Setup gConfigGpioB =
{
	GPIOB,		//YSS_GPIO_Peri *dev;
	Exti::PORTB	//uint8_t port;
};

Gpio gpioB(gDrvSetupGpio, gConfigGpioB);
#endif

#if defined(GPIOC)
const static Gpio::Setup gConfigGpioC =
{
	GPIOC,		//YSS_GPIO_Peri *dev;
	Exti::PORTC	//uint8_t port;
};

Gpio gpioC(gDrvSetupGpio, gConfigGpioC);
#endif

#if defined(GPIOD)
const static Gpio::Setup gConfigGpioD =
{
	GPIOD,		//YSS_GPIO_Peri *dev;
	Exti::PORTD	//uint8_t port;
};

Gpio gpioD(gDrvSetupGpio, gConfigGpioD);
#endif
/*
#if defined(GPIOE)
static void setGpioEClockEn(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_IOPEEN_Msk, en);
	clock.unlock();
}

static void resetGpioE(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_PERST;
	RCC->APB2RCR &= ~RCC_APB2RCR_PERST;
}

Gpio gpioE((uint32_t*)GPIOE, setGpioEClockEn, resetGpioE, define::gpio::Exti::PORTE);
#endif

#if defined(GPIOF)
static void setGpioFClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_PFEN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_PFEN;
}

static void resetGpioF(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_PFRST;
	RCC->APB2RCR &= ~RCC_APB2RCR_PFRST;
}

Gpio gpioF((uint32_t*)GPIOF, setGpioFClockEn, resetGpioF, define::gpio::Exti::PORTF);
#endif

#if defined(GPIOG)
static void setGpioGClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_PGEN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_PGEN;
}

static void resetGpioG(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_PGRST;
	RCC->APB2RCR &= ~RCC_APB2RCR_PGRST;
}

Gpio gpioG((uint32_t*)GPIOG, setGpioGClockEn, resetGpioG, define::gpio::Exti::PORTG);
#endif
*/
#endif

