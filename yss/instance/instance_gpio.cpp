////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
// 주담당자 : 아이구 (mymy49@nate.com) 2021.02.11 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/nvic/nvic.h>
#include <instance/instance_gpio.h>
#include <yss/instance.h>

#if defined(GPIOA) || defined(PORT_PA00)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioAClockEn(bool en)
{
	clock.peripheral.setGpioAEn(en);
}
#endif
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioA(void)
{
	clock.peripheral.resetGpioA();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioA(GPIOA, setGpioAClockEn, resetGpioA, define::gpio::exti::PORTA);
#elif defined(__SAM_L21_SUBFAMILY)
drv::Gpio gpioA(&PORT->Group[0], 0, 0, 0);
#endif
#endif

#if defined(GPIOB) || defined(PORT_PB00)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioBClockEn(bool en)
{
	clock.peripheral.setGpioBEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioB(void)
{
	clock.peripheral.resetGpioB();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioB(GPIOB, setGpioBClockEn, resetGpioB, define::gpio::exti::PORTB);
#elif defined(__SAM_L21_SUBFAMILY)
drv::Gpio gpioB(&PORT->Group[1], 0, 0, 1);
#endif
#endif

#if defined(GPIOC)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioCClockEn(bool en)
{
	clock.peripheral.setGpioCEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioC(void)
{
	clock.peripheral.resetGpioC();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioC(GPIOC, setGpioBClockEn, resetGpioC, define::gpio::exti::PORTC);
#endif
#endif

#if defined(GPIOD)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioDClockEn(bool en)
{
	clock.peripheral.setGpioDEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioD(void)
{
	clock.peripheral.resetGpioD();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioD(GPIOD, setGpioDClockEn, resetGpioD, define::gpio::exti::PORTD);
#endif
#endif

#if defined(GPIOE)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioEClockEn(bool en)
{
	clock.peripheral.setGpioEEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioE(void)
{
	clock.peripheral.resetGpioE();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioE(GPIOE, setGpioEClockEn, resetGpioE, define::gpio::exti::PORTE);
#endif
#endif

#if defined(GPIOF)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioFClockEn(bool en)
{
	clock.peripheral.setGpioFEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioF(void)
{
	clock.peripheral.resetGpioF();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioF(GPIOF, setGpioFClockEn, resetGpioF, define::gpio::exti::PORTF);
#endif
#endif

#if defined(GPIOG)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioGClockEn(bool en)
{
	clock.peripheral.setGpioGEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioG(void)
{
	clock.peripheral.resetGpioG();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioG(GPIOG, setGpioGClockEn, resetGpioG, define::gpio::exti::PORTG);
#endif
#endif

#if defined(GPIOH)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioHClockEn(bool en)
{
	clock.peripheral.setGpioHEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioH(void)
{
	clock.peripheral.resetGpioH();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioH(GPIOH, setGpioHClockEn, resetGpioH, define::gpio::exti::PORTH);
#endif
#endif

#if defined(GPIOI)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioIClockEn(bool en)
{
	clock.peripheral.setGpioIEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioI(void)
{
	clock.peripheral.resetGpioI();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioI(GPIOI, setGpioIClockEn, resetGpioI, define::gpio::exti::PORTI);
#endif
#endif

#if defined(GPIOJ)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioJClockEn(bool en)
{
	clock.peripheral.setGpioJEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioJ(void)
{
	clock.peripheral.resetGpioJ();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioJ(GPIOJ, setGpioJClockEn, resetGpioJ, define::gpio::exti::PORTJ);
#endif
#endif

#if defined(GPIOK)
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void setGpioKClockEn(bool en)
{
	clock.peripheral.setGpioKEn(en);
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static void resetGpioK(void)
{
	clock.peripheral.resetGpioK();
}
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
drv::Gpio gpioK(GPIOK, setGpioKClockEn, resetGpioK, define::gpio::exti::PORTK);
#endif
#endif
