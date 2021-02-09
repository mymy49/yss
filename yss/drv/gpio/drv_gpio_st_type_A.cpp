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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) ||                                                 \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                                                                 \
    defined(STM32F429xx) || defined(STM32F439xx) ||                                                                                                 \
    defined(STM32G431xx) || defined(STM32G441xx) ||                                                                                                 \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB) || \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) ||                                                 \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                                                                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                                                                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                                                                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx) ||                                                                         \
    defined(STM32L412xx) || defined(STM32L422xx) ||                                                                                                 \
    defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx) ||                         \
    defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) ||                                                                         \
    defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) ||                         \
    defined(STM32L496xx) || defined(STM32L4A6xx) ||                                                                                                 \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx) ||                                                                                                 \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/gpio/drv_st_gpio_type_A_register.h>
#include <yss/stdlib.h>
#include <instance/instance_clock.h>

#if defined(GPIOA)
static void setGpioAClockEn(bool en)
{
    clock.peripheral.setGpioAEn(en);
}

drv::Gpio gpioA(GPIOA, setGpioAClockEn, 0, define::syscfg::exti::PORTA);
#endif

#if defined(GPIOB)
static void setGpioBClockEn(bool en)
{
    clock.peripheral.setGpioBEn(en);
}

drv::Gpio gpioB(GPIOB, setGpioBClockEn, 0, define::syscfg::exti::PORTB);
#endif

#if defined(GPIOC)
static void setGpioCClockEn(bool en)
{
    clock.peripheral.setGpioCEn(en);
}

drv::Gpio gpioC(GPIOC, setGpioBClockEn, 0, define::syscfg::exti::PORTC);
#endif

#if defined(GPIOD)
static void setGpioDClockEn(bool en)
{
    clock.peripheral.setGpioDEn(en);
}

drv::Gpio gpioD(GPIOD, setGpioDClockEn, 0, define::syscfg::exti::PORTD);
#endif

#if defined(GPIOE)
static void setGpioEClockEn(bool en)
{
    clock.peripheral.setGpioEEn(en);
}

drv::Gpio gpioE(GPIOE, setGpioEClockEn, 0, define::syscfg::exti::PORTE);
#endif

#if defined(GPIOF)
static void setGpioFClockEn(bool en)
{
    clock.peripheral.setGpioFEn(en);
}

drv::Gpio gpioF(GPIOF, setGpioFClockEn, 0, define::syscfg::exti::PORTF);
#endif

#if defined(GPIOG)
static void setGpioGClockEn(bool en)
{
    clock.peripheral.setGpioGEn(en);
}

drv::Gpio gpioG(GPIOG, setGpioGClockEn, 0, define::syscfg::exti::PORTG);
#endif

#if defined(GPIOH)
static void setGpioHClockEn(bool en)
{
    clock.peripheral.setGpioHEn(en);
}

drv::Gpio gpioH(GPIOH, setGpioHClockEn, 0, define::syscfg::exti::PORTH);
#endif

#if defined(GPIOI)
static void setGpioIClockEn(bool en)
{
    clock.peripheral.setGpioIEn(en);
}

drv::Gpio gpioI(GPIOI, setGpioIClockEn, 0, define::syscfg::exti::PORTI);
#endif

#if defined(GPIOJ)
static void setGpioJClockEn(bool en)
{
    clock.peripheral.setGpioJEn(en);
}

drv::Gpio gpioJ(GPIOJ, setGpioJClockEn, 0, define::syscfg::exti::PORTJ);
#endif

#if defined(GPIOK)
static void setGpioKClockEn(bool en)
{
    clock.peripheral.setGpioKEn(en);
}

drv::Gpio gpioK(GPIOK, setGpioKClockEn, 0, define::syscfg::exti::PORTK);
#endif

namespace drv
{
Gpio::Gpio(GPIO_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned char exti) : Drv(clockFunc, nvicFunc)
{
    mPeri = peri;
    mExti = exti;
}

void Gpio::setExti(unsigned char pin)
{
    syscfg.setExtiPort(pin, mExti);
}

void Gpio::setToAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, bool otype)
{
    setGpioMode(mPeri, pin, define::gpio::mode::ALT_FUNC);
    setGpioAltfunc(mPeri, pin, altFunc);
    setGpioOspeed(mPeri, pin, ospeed);
    setGpioOtype(mPeri, pin, otype);
}

void Gpio::setToInput(unsigned char pin, unsigned char pullUpDown)
{
    setGpioMode(mPeri, pin, define::gpio::mode::INPUT);
    setGpioPullUpDown(mPeri, pin, pullUpDown);
}

void Gpio::setToAltFunc(config::gpio::AltFunc *altport, unsigned char numOfPort, unsigned char ospeed, bool otype)
{
    GPIO_TypeDef *port;
    unsigned char pin;
    unsigned char func;

    for (unsigned char i = 0; i < numOfPort; i++)
    {
        port = altport[i].port;
        pin = altport[i].pin;
        func = altport[i].func;

        setGpioMode(port, pin, define::gpio::mode::ALT_FUNC);
        setGpioAltfunc(port, pin, func);
        setGpioOspeed(port, pin, ospeed);
        setGpioOtype(port, pin, otype);
    }
}

void Gpio::setToOutput(unsigned char pin, unsigned char ospeed, bool otype)
{
    setGpioMode(mPeri, pin, define::gpio::mode::OUTPUT);
    setGpioOspeed(mPeri, pin, ospeed);
    setGpioOtype(mPeri, pin, otype);
}

void Gpio::setOutput(unsigned char pin, bool data)
{
    setRegBit(mPeri->ODR, data, pin);
}

void Gpio::setPullUpDown(unsigned char pin, unsigned char pupd)
{
    setGpioPullUpDown(mPeri, pin, pupd);
}

void Gpio::setToAnalog(unsigned char pin)
{
    mPeri->MODER |= 0x03 << (pin * 2);
}

bool Gpio::getData(unsigned char pin)
{
    return getGpioInputData(mPeri, pin);
}
}

#endif