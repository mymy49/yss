/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(W7500)

#include <drv/Gpio.h>
#include <yss/reg.h>
#include <targets/wiznet/bitfield_w7500x.h>

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : GpioBase(drvSetup)
{
	mDev = setup.dev;
	mAfc = setup.afc;
	mPadcon = setup.padcon;
	mOutputAf = setup.outputAf;
}

error_t Gpio::setAsOutput(uint8_t pin, strength_t strength, otype_t otype)
{
	if(pin > 15)
		return error_t::PIN_INDEX_OVER;
	
	if(strength > 1)
		return error_t::WRONG_CONFIG;

	if(otype > 1)
		return error_t::WRONG_CONFIG;
	
	if(mOutputAf[pin] < 0)
		return error_t::THIS_PIN_DO_NOT_HAVE_GPIO_OUTPUT;

	__disable_irq();
	mAfc->REGISTER[pin] = mOutputAf[pin];
	mPadcon->REGISTER[pin] = (strength & 0x01) << 2 | (otype & 0x01) << 3 | 0x03 << 5;
	mDev->OUTENSET = 1 << pin;
	__enable_irq();

	return error_t::ERROR_NONE;
}

error_t Gpio::setAsAltFunc(uint8_t pin, altfunc_t altfunc, strength_t strength, otype_t otype)
{
	if(pin > 15)
		return error_t::PIN_INDEX_OVER;
	
	if(strength > 1)
		return error_t::WRONG_CONFIG;

	if(otype > 1)
		return error_t::WRONG_CONFIG;
	
	__disable_irq();
	mAfc->REGISTER[pin] = altfunc;
	mPadcon->REGISTER[pin] = (strength & 0x01) << 2 | (otype & 0x01) << 3 | 0x03 << 5;
	__enable_irq();

	return error_t::ERROR_NONE;
}

void Gpio::setOutput(uint8_t pin, bool data)
{
	__disable_irq();
	if(data)
		mDev->DATAOUT |= 1 << pin;
	else
		mDev->DATAOUT &= ~(1 << pin);		
	__enable_irq();
}

#endif

