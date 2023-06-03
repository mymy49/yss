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

#include <yss/instance.h>
#include <targets/st_gigadevice/rcc_stm32_gd32f1.h>

#if defined(STM32F1)

#if defined(GPIOA)
static void setGpioAClockEn(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_IOPAEN_Msk, en);
	clock.unlock();
}

static void resetGpioA(void)
{
	clock.lock();
	clock.resetApb2(RCC_APB2RSTR_IOPARST_Pos);
	clock.unlock();
}

Gpio gpioA((uint32_t*)GPIOA, setGpioAClockEn, resetGpioA, define::gpio::exti::PORTA);
#endif

#if defined(GPIOB)
static void setGpioBClockEn(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_IOPBEN_Msk, en);
	clock.unlock();
}

static void resetGpioB(void)
{
	clock.lock();
	clock.resetApb2(RCC_APB2RSTR_IOPBRST_Pos);
	clock.unlock();
}

Gpio gpioB((uint32_t*)GPIOB, setGpioBClockEn, resetGpioB, define::gpio::exti::PORTB);
#endif

#if defined(GPIOC)
static void setGpioCClockEn(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_IOPCEN_Msk, en);
	clock.unlock();
}

static void resetGpioC(void)
{
	clock.lock();
	clock.resetApb2(RCC_APB2RSTR_IOPCRST_Pos);
	clock.unlock();
}

Gpio gpioC((uint32_t*)GPIOC, setGpioBClockEn, resetGpioC, define::gpio::exti::PORTC);
#endif

#if defined(GPIOD)
static void setGpioDClockEn(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_IOPDEN_Msk, en);
	clock.unlock();
}

static void resetGpioD(void)
{
	clock.lock();
	clock.resetApb2(RCC_APB2RSTR_IOPDRST_Pos);
	clock.unlock();
}

Gpio gpioD((uint32_t*)GPIOD, setGpioDClockEn, resetGpioD, define::gpio::exti::PORTD);
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
*/
#endif

