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

#include <yss/instance.h>

#if defined(GD32F1)

#if defined(GPIOA)
static void setGpioAClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_PAEN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_PAEN;
}

static void resetGpioA(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_PARST;
	RCC->APB2RCR &= ~RCC_APB2RCR_PARST;
}

Gpio gpioA((uint32_t*)GPIOA, setGpioAClockEn, resetGpioA, define::gpio::exti::PORTA);
#endif

#if defined(GPIOB)
static void setGpioBClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_PBEN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_PBEN;
}

static void resetGpioB(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_PBRST;
	RCC->APB2RCR &= ~RCC_APB2RCR_PBRST;
}

Gpio gpioB((uint32_t*)GPIOB, setGpioBClockEn, resetGpioB, define::gpio::exti::PORTB);
#endif

#if defined(GPIOC)
static void setGpioCClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_PCEN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_PCEN;
}

static void resetGpioC(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_PCRST;
	RCC->APB2RCR &= ~RCC_APB2RCR_PCRST;
}

Gpio gpioC((uint32_t*)GPIOC, setGpioBClockEn, resetGpioC, define::gpio::exti::PORTC);
#endif

#if defined(GPIOD)
static void setGpioDClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_PDEN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_PDEN;
}

static void resetGpioD(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_PDRST;
	RCC->APB2RCR &= ~RCC_APB2RCR_PDRST;
}

Gpio gpioD((uint32_t*)GPIOD, setGpioDClockEn, resetGpioD, define::gpio::exti::PORTD);
#endif

#if defined(GPIOE)
static void setGpioEClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_PEEN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_PEEN;
}

static void resetGpioE(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_PERST;
	RCC->APB2RCR &= ~RCC_APB2RCR_PERST;
}

Gpio gpioE((uint32_t*)GPIOE, setGpioEClockEn, resetGpioE, define::gpio::exti::PORTE);
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

Gpio gpioF((uint32_t*)GPIOF, setGpioFClockEn, resetGpioF, define::gpio::exti::PORTF);
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

Gpio gpioG((uint32_t*)GPIOG, setGpioGClockEn, resetGpioG, define::gpio::exti::PORTG);
#endif

#endif
