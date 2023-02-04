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

#include <drv/peripheral.h>

#if defined(GD32F4) || defined(STM32F4) || defined(STM32F7) || defined(STM32L1) || defined(STM32F0)

#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/gpio_stm32_gd32f4_l1.h>
#include <targets/st_gigadevice/exti_stm32_gd32f1_f4_f7.h>
#if defined(STM32F7)
#include <targets/st_gigadevice/syscfg_stm32f7.h>
#elif defined(STM32F4) || defined(GD32F4)
#include <targets/st_gigadevice/syscfg_stm32f4.h>
#elif defined(STM32F0)
#include <targets/st_gigadevice/syscfg_stm32f0.h>
#endif

Gpio::Gpio(YSS_GPIO_Peri *peri, void (*clockFunc)(bool en), void (*resetFunc)(void), uint8_t exti) : Drv(clockFunc, 0, resetFunc)
{
	mPeri = peri;
	mExti = exti;
}

void Gpio::setExti(uint8_t pin)
{
	uint8_t field = pin % 4 * 4;
	setFieldData(SYSCFG[SYSCFG_REG::EXTICR0 + pin / 4], 0xF << field, mExti, field);
}

void Gpio::setAsAltFunc(uint8_t pin, uint8_t altFunc, uint8_t ospeed, uint8_t otype)
{
	uint8_t pinOffset = pin * 2;

	setFieldData(mPeri[GPIO_REG::MODER], 0x3 << pinOffset, define::gpio::mode::ALT_FUNC, pinOffset);
	setBitData(mPeri[GPIO_REG::OTYPER], otype, pin);
	setFieldData(mPeri[GPIO_REG::OSPEEDR], 0x3 << pinOffset, ospeed, pinOffset);
	pinOffset = (pin % 0x8) * 4;
	setFieldData(mPeri[GPIO_REG::AFRL + pin / 8], 0xF << pinOffset, altFunc, pinOffset);
}

void Gpio::setAsInput(uint8_t pin, uint8_t pullUpDown)
{
	pin <<= 1;
	setFieldData(mPeri[GPIO_REG::MODER], 0x3 << pin, define::gpio::mode::INPUT, pin);
	setFieldData(mPeri[GPIO_REG::PUPDR], 0x3 << pin, pullUpDown, pin);
}

void Gpio::setPackageAsAltFunc(AltFunc *altport, uint8_t numOfPort, uint8_t ospeed, uint8_t otype)
{
	YSS_GPIO_Peri *port;
	uint8_t pin, pinOffset;
	uint8_t func;

	for (uint8_t i = 0; i < numOfPort; i++)
	{
		port = altport[i].port;
		pin = altport[i].pin;
		pinOffset = pin * 2;
		func = altport[i].func;
		
		setFieldData(port[GPIO_REG::MODER], 0x3 << pinOffset, define::gpio::mode::ALT_FUNC, pinOffset);
		setBitData(port[GPIO_REG::OTYPER], otype, pin);
		setFieldData(port[GPIO_REG::OSPEEDR], 0x3 << pinOffset, ospeed, pinOffset);
		pinOffset = (pin % 0x8) * 4;
		setFieldData(port[GPIO_REG::AFRL + pin / 8], 0xF << pinOffset, func, pinOffset);
	}
}

void Gpio::setAsOutput(uint8_t pin, uint8_t ospeed, uint8_t otype)
{
	uint8_t pinOffset = pin * 2;

	setFieldData(mPeri[GPIO_REG::MODER], 0x3 << pinOffset, define::gpio::mode::OUTPUT, pinOffset);
	setBitData(mPeri[GPIO_REG::OTYPER], otype, pin);
	setFieldData(mPeri[GPIO_REG::OSPEEDR], 0x3 << pinOffset, ospeed, pinOffset);
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	if(data)
		mPeri[GPIO_REG::BSRR] = 1 << pin;
	else
		mPeri[GPIO_REG::BSRR] = 1 << pin + 16;
}

void Gpio::setPullUpDown(uint8_t pin, uint8_t pupd)
{
	pin <<= 1;
	setFieldData(mPeri[GPIO_REG::PUPDR], 0x3 << pin, pupd, pin);
}

void Gpio::setAsAnalog(uint8_t pin)
{
	pin <<= 1;
	setFieldData(mPeri[GPIO_REG::PUPDR], 0x3 << pin, define::gpio::pupd::NONE, pin);
	setFieldData(mPeri[GPIO_REG::MODER], 0x3 << pin, define::gpio::mode::ANALOG, pin);
}

bool Gpio::getInputData(uint8_t pin)
{
	return (mPeri[GPIO_REG::IDR] >> pin) & 0x01;
}

#endif
