/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(GD32F1)

#include <config.h>
#include <yss/instance.h>
#include <yss.h>
#include <targets/st/bitfield_stm32f103xx.h>

using namespace define::gpio;

const static Drv::setup_t gDrvSetupGpio =
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

