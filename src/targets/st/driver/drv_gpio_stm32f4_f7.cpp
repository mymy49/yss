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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F7) || defined(STM32F0) || defined(STM32G4)

#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : GpioBase(drvSetup)
{
	mDev = setup.dev;
	mExti = setup.exti;
}

void Gpio::setExti(uint8_t pin)
{
	uint8_t field = pin % 4 * 4;
	setFieldData(SYSCFG->EXTICR[pin / 4], 0xF << field, mExti, field);
}

error_t Gpio::setAsAltFunc(uint8_t pin, uint16_t altFunc, uint8_t ospeed, uint8_t otype)
{
	if(pin > 15)
		return error_t::WRONG_CONFIG;

	uint8_t pinOffset = pin * 2;

	setFieldData(mDev->MODER, 0x3 << pinOffset, define::gpio::mode::ALT_FUNC, pinOffset);
	setBitData(mDev->OTYPER, otype, pin);
	setFieldData(mDev->OSPEEDR, 0x3 << pinOffset, ospeed, pinOffset);
	pinOffset = (pin % 0x8) * 4;
	setFieldData(mDev->AFR[pin / 8], 0xF << pinOffset, altFunc, pinOffset);

	return error_t::ERROR_NONE;
}

void Gpio::setAsInput(uint8_t pin, uint8_t pullUpDown)
{
	pin <<= 1;
	setFieldData(mDev->MODER, 0x3 << pin, define::gpio::mode::INPUT, pin);
	setFieldData(mDev->PUPDR, 0x3 << pin, pullUpDown, pin);
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
		
		setFieldData(port->MODER, 0x3 << pinOffset, define::gpio::mode::ALT_FUNC, pinOffset);
		setBitData(port->OTYPER, otype, pin);
		setFieldData(port->OSPEEDR, 0x3 << pinOffset, ospeed, pinOffset);
		pinOffset = (pin % 0x8) * 4;
		setFieldData(port->AFR[pin / 8], 0xF << pinOffset, func, pinOffset);
	}
}

error_t Gpio::setAsOutput(uint8_t pin, uint8_t ospeed, uint8_t otype)
{
	if(pin > 15)
		return error_t::WRONG_CONFIG;

	uint8_t pinOffset = pin * 2;

	setFieldData(mDev->MODER, 0x3 << pinOffset, define::gpio::mode::OUTPUT, pinOffset);
	setBitData(mDev->OTYPER, otype, pin);
	setFieldData(mDev->OSPEEDR, 0x3 << pinOffset, ospeed, pinOffset);

	return error_t::ERROR_NONE;
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	if(data)
		mDev->BSRR = 1 << pin;
	else
		mDev->BSRR = 1 << (pin + 16);
}

void Gpio::setPullUpDown(uint8_t pin, uint8_t pupd)
{
	pin <<= 1;
	setFieldData(mDev->PUPDR, 0x3 << pin, pupd, pin);
}

void Gpio::setAsAnalog(uint8_t pin)
{
	pin <<= 1;
	setFieldData(mDev->PUPDR, 0x3 << pin, define::gpio::pupd::NONE, pin);
	setFieldData(mDev->MODER, 0x3 << pin, define::gpio::mode::ANALOG, pin);
}

bool Gpio::getInputData(uint8_t pin)
{
	return (mDev->IDR >> pin) & 0x01;
}

#endif
