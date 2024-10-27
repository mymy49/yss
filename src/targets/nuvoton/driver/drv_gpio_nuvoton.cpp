/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mMfp = setup.mfp;
	mOutputReg = (volatile uint32_t*)(((uint32_t)&mDev->DOUT - 0x40000000) * 32 + 0x42000000);
}

error_t Gpio::setAsOutput(uint8_t pin, otype_t otype)
{
	uint32_t reg;
	uint8_t pinf;
	
	if(pin > 8)
	{
		reg = 1;
		pinf = (pin - 8) << 2;
	}
	else
	{
		reg = 0;
		pinf = pin << 2;
	}

	setAsAltFunc(pin, ALTFUNC_GPIO);

	__disable_irq();
	mMfp[reg] &= ~(0xF << pinf);

	pin <<= 1;
	reg = mDev->MODE;
	reg &= ~(0x3 << pin);
	reg |= otype << pin;
	mDev->MODE = reg;
	__enable_irq();

	return error_t::ERROR_NONE;
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	mOutputReg[pin] = data;
}

error_t Gpio::setAsAltFunc(uint8_t pin, altfunc_t altfunc, otype_t otype)
{
	uint32_t reg, index;
	
	index = pin / 8;
	pin = (pin << 2) & 0x1F;
	
	__disable_irq();
	reg = mMfp[index];
	reg &= ~(0xF << pin);
	reg |= altfunc << pin;
	mMfp[index] = reg;
	__enable_irq();

	return error_t::ERROR_NONE;
}


#endif

