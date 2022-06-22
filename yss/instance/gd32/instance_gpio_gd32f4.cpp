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

#if defined(GD32F4)

#if defined(GPIOA)
static void setGpioAClockEn(bool en)
{
	clock.peripheral.setGpioAEn(en);
}

static void resetGpioA(void)
{
	clock.peripheral.resetGpioA();
}

drv::Gpio gpioA((YSS_GPIO_Peri*)GPIOA, setGpioAClockEn, resetGpioA, define::gpio::exti::PORTA);
#endif



#if defined(GPIOB)
static void setGpioBClockEn(bool en)
{
	clock.peripheral.setGpioBEn(en);
}

static void resetGpioB(void)
{
	clock.peripheral.resetGpioB();
}

drv::Gpio gpioB((YSS_GPIO_Peri*)GPIOB, setGpioBClockEn, resetGpioB, define::gpio::exti::PORTB);
#endif



#if defined(GPIOC)
static void setGpioCClockEn(bool en)
{
	clock.peripheral.setGpioCEn(en);
}

static void resetGpioC(void)
{
	clock.peripheral.resetGpioC();
}

drv::Gpio gpioC((YSS_GPIO_Peri*)GPIOC, setGpioBClockEn, resetGpioC, define::gpio::exti::PORTC);
#endif



#if defined(GPIOD)
static void setGpioDClockEn(bool en)
{
	clock.peripheral.setGpioDEn(en);
}

static void resetGpioD(void)
{
	clock.peripheral.resetGpioD();
}

drv::Gpio gpioD((YSS_GPIO_Peri*)GPIOD, setGpioDClockEn, resetGpioD, define::gpio::exti::PORTD);
#endif



#if defined(GPIOE)
static void setGpioEClockEn(bool en)
{
	clock.peripheral.setGpioEEn(en);
}

static void resetGpioE(void)
{
	clock.peripheral.resetGpioE();
}

drv::Gpio gpioE((YSS_GPIO_Peri*)GPIOE, setGpioEClockEn, resetGpioE, define::gpio::exti::PORTE);
#endif



#if defined(GPIOF)
static void setGpioFClockEn(bool en)
{
	clock.peripheral.setGpioFEn(en);
}

static void resetGpioF(void)
{
	clock.peripheral.resetGpioF();
}

drv::Gpio gpioF((YSS_GPIO_Peri*)GPIOF, setGpioFClockEn, resetGpioF, define::gpio::exti::PORTF);
#endif



#if defined(GPIOG)
static void setGpioGClockEn(bool en)
{
	clock.peripheral.setGpioGEn(en);
}

static void resetGpioG(void)
{
	clock.peripheral.resetGpioG();
}

drv::Gpio gpioG((YSS_GPIO_Peri*)GPIOG, setGpioGClockEn, resetGpioG, define::gpio::exti::PORTG);
#endif



#if defined(GPIOH)
static void setGpioHClockEn(bool en)
{
	clock.peripheral.setGpioHEn(en);
}

static void resetGpioH(void)
{
	clock.peripheral.resetGpioH();
}

drv::Gpio gpioH((YSS_GPIO_Peri*)GPIOH, setGpioHClockEn, resetGpioH, define::gpio::exti::PORTH);
#endif



#if defined(GPIOI)
static void setGpioIClockEn(bool en)
{
	clock.peripheral.setGpioIEn(en);
}

static void resetGpioI(void)
{
	clock.peripheral.resetGpioI();
}

drv::Gpio gpioI((YSS_GPIO_Peri*)GPIOI, setGpioIClockEn, resetGpioI, define::gpio::exti::PORTI);
#endif

#endif

