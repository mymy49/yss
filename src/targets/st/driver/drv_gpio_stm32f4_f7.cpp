/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F7) || defined(STM32F0) || defined(STM32G4)

#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mExti = setup.exti;
}

void Gpio::setExti(uint8_t pin)
{
	uint8_t field = pin % 4 * 4;
	setFieldData(SYSCFG->EXTICR[pin / 4], 0xF << field, mExti, field);
}

error_t Gpio::setAsAltFunc(uint8_t pin, altFunc_t altFunc, ospeed_t ospeed, otype_t otype)
{
	if(pin > 15)
		return error_t::WRONG_CONFIG;

	uint8_t pinOffset = pin * 2;

	setFieldData(mDev->MODER, 0x3 << pinOffset, Gpio::MODE_ALT_FUNC, pinOffset);
	setBitData(mDev->OTYPER, otype, pin);
	setFieldData(mDev->OSPEEDR, 0x3 << pinOffset, ospeed, pinOffset);
	pinOffset = (pin % 0x8) * 4;
	setFieldData(mDev->AFR[pin / 8], 0xF << pinOffset, altFunc, pinOffset);

	return error_t::ERROR_NONE;
}

void Gpio::setAsInput(uint8_t pin, pupd_t pullUpDown)
{
	pin <<= 1;
	setFieldData(mDev->MODER, 0x3 << pin, Gpio::MODE_INPUT, pin);
	setFieldData(mDev->PUPDR, 0x3 << pin, pullUpDown, pin);
}

void Gpio::setPackageAsAltFunc(altFuncPort_t *altport, uint8_t numOfPort, ospeed_t ospeed, otype_t otype)
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
		
		setFieldData(port->MODER, 0x3 << pinOffset, Gpio::MODE_ALT_FUNC, pinOffset);
		setBitData(port->OTYPER, otype, pin);
		setFieldData(port->OSPEEDR, 0x3 << pinOffset, ospeed, pinOffset);
		pinOffset = (pin % 0x8) * 4;
		setFieldData(port->AFR[pin / 8], 0xF << pinOffset, func, pinOffset);
	}
}

error_t Gpio::setAsOutput(uint8_t pin, ospeed_t ospeed, otype_t otype)
{
	if(pin > 15)
		return error_t::WRONG_CONFIG;

	uint8_t pinOffset = pin * 2;

	setFieldData(mDev->MODER, 0x3 << pinOffset, Gpio::MODE_OUTPUT, pinOffset);
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

void Gpio::setPullUpDown(uint8_t pin, pupd_t pupd)
{
	pin <<= 1;
	setFieldData(mDev->PUPDR, 0x3 << pin, pupd, pin);
}

void Gpio::setAsAnalog(uint8_t pin)
{
	pin <<= 1;
	setFieldData(mDev->PUPDR, 0x3 << pin, PUPD_NONE, pin);
	setFieldData(mDev->MODER, 0x3 << pin, MODE_ANALOG, pin);
}

bool Gpio::getInputData(uint8_t pin)
{
	return (mDev->IDR >> pin) & 0x01;
}

#endif
