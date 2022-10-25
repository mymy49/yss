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

#if defined(STM32F7)

#if defined(GPIOA)
static void setGpioAClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN_Msk;
}

static void resetGpioA(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOARST;
}

Gpio gpioA(GPIOA, setGpioAClockEn, resetGpioA, define::gpio::exti::PORTA);
#endif



#if defined(GPIOB)
static void setGpioBClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN_Msk;
}

static void resetGpioB(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOBRST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOBRST;
}

Gpio gpioB(GPIOB, setGpioBClockEn, resetGpioB, define::gpio::exti::PORTB);
#endif



#if defined(GPIOC)
static void setGpioCClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN_Msk;
}

static void resetGpioC(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOCRST;
}

Gpio gpioC(GPIOC, setGpioBClockEn, resetGpioC, define::gpio::exti::PORTC);
#endif



#if defined(GPIOD)
static void setGpioDClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN_Msk;
}

static void resetGpioD(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIODRST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIODRST;
}

Gpio gpioD(GPIOD, setGpioDClockEn, resetGpioD, define::gpio::exti::PORTD);
#endif



#if defined(GPIOE)
static void setGpioEClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN_Msk;
}

static void resetGpioE(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOERST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOERST;
}

Gpio gpioE(GPIOE, setGpioEClockEn, resetGpioE, define::gpio::exti::PORTE);
#endif



#if defined(GPIOF)
static void setGpioFClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN_Msk;
}

static void resetGpioF(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOFRST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOFRST;
}

Gpio gpioF(GPIOF, setGpioFClockEn, resetGpioF, define::gpio::exti::PORTF);
#endif



#if defined(GPIOG)
static void setGpioGClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN_Msk;
}

static void resetGpioG(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOGRST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOGRST;
}

Gpio gpioG(GPIOG, setGpioGClockEn, resetGpioG, define::gpio::exti::PORTG);
#endif



#if defined(GPIOH)
static void setGpioHClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN_Msk;
}

static void resetGpioH(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOHRST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOHRST;
}

Gpio gpioH(GPIOH, setGpioHClockEn, resetGpioH, define::gpio::exti::PORTH);
#endif



#if defined(GPIOI)
static void setGpioIClockEn(bool en)
{
	if(en)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOIEN_Msk;
}

static void resetGpioI(void)
{
	RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOIRST;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOIRST;
}

Gpio gpioI(GPIOI, setGpioIClockEn, resetGpioI, define::gpio::exti::PORTI);
#endif

#endif

