/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__MAX32665_FAMILY)

#include <drv/Gpio.h>
#include <yss/reg.h>

/**
 * @file drv_gpio_nuvoton.cpp
 * @brief GPIO target-specific driver source file for Nuvoton.
 */

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
}


error_t Gpio::setAsOutput(uint8_t pin, outputDriveStrength_t strength)
{
	if(pin > 31)
		return error_t::OUT_OF_PIN_INDEX_RANGE;
	
	mDev->out_en_set = 1 << pin;
	
	semaphore::lockPeripherals();
	__disable_irq();
	setOutputDriverStrength(pin, strength);
	
	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Gpio::setAsInput(uint8_t pin)
{
	return error_t::ERROR_NONE;
}


void Gpio::setOutput(uint8_t pin, bool data)
{
	if(data)
		mDev->out_set = 1 << pin;
	else
		mDev->out_clr = 1 << pin;
}

error_t Gpio::setAsAltFunc(uint8_t pin, altFunc_t altfunc, atype_t atype, outputDriveStrength_t strength)
{
	return error_t::ERROR_NONE;
}

error_t Gpio::setPackageAsAltFunc(altFuncPackage_t *package, uint8_t count, atype_t atype, outputDriveStrength_t strength)
{
	return error_t::ERROR_NONE;
}

error_t Gpio::setPullUpDown(uint8_t pin, pupd_t pupd)
{
	return error_t::ERROR_NONE;
}

error_t Gpio::setGpioInterrupt(uint8_t pin, source_t src, void (*isr)(void))
{
	return error_t::ERROR_NONE;
}

error_t Gpio::setGpioInterrupt(uint8_t pin, source_t src, triggerId_t trigger)
{
	return error_t::ERROR_NONE;
}

void Gpio::isr(void)
{
}

bool Gpio::getInputData(uint8_t pin)
{
	return false;
}

void Gpio::setOutputDriverStrength(uint8_t pin, outputDriveStrength_t strength)
{
	switch(strength)
	{
	case STRENGTH_LOW :
		setBitData(mDev->ds, 0, pin);
		setBitData(mDev->ds1, 0, pin);
		break;

	case STRENGTH_MEDIUM_LOW :
		setBitData(mDev->ds, 1, pin);
		setBitData(mDev->ds1, 0, pin);
		break;

	case STRENGTH_MEDIUM_HIGH :
		setBitData(mDev->ds, 0, pin);
		setBitData(mDev->ds1, 1, pin);
		break;

	case STRENGTH_HIGH :
		setBitData(mDev->ds, 1, pin);
		setBitData(mDev->ds1, 1, pin);
		break;
	}
}

void Gpio::setAltFunction(uint8_t pin, altFunc_t altfunc)
{
	switch((uint8_t)altfunc)
	{
	case 0 :
		mDev->en1_clr = 1 << pin;
		mDev->en2_clr = 1 << pin;
		break;

	case 1 :
		mDev->en1_set = 1 << pin;
		mDev->en2_clr = 1 << pin;
		break;

	case 2 :
		mDev->en1_clr = 1 << pin;
		mDev->en2_set = 1 << pin;
		break;

	case 3 :
		mDev->en1_set = 1 << pin;
		mDev->en2_set = 1 << pin;
		break;
	}
}

#endif

