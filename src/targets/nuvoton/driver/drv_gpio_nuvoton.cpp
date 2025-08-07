/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <drv/Gpio.h>
#include <yss/reg.h>
#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include <targets/nuvoton/bitfield_m4xx.h>
#elif defined(__M2xx_FAMILY)
#include <targets/nuvoton/bitfield_m2xx.h>
#endif

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mMfp = setup.mfp;
#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
	mOutputReg = (volatile uint32_t*)(((uint32_t)&mDev->DOUT - 0x40000000) * 32 + 0x42000000);
#elif defined(__M2xx_FAMILY)
	mOutputReg = (volatile uint32_t*)(((uint32_t)mDev + 0x800));
#endif
	for(uint32_t i = 0; i < 16; i++)
		mIsr[i] = nullptr;
}

error_t Gpio::setAsOutput(uint8_t pin, otype_t otype)
{
	uint32_t reg;
	uint8_t pinf;

	if(pin > 15)
		return error_t::OUT_OF_PIN_INDEX_RANGE;
	
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

error_t Gpio::setAsAltFunc(uint8_t pin, altFunc_t altfunc, otype_t otype)
{
	uint32_t reg, index;

	if(pin > 15)
		return error_t::OUT_OF_PIN_INDEX_RANGE;
	
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

error_t Gpio::setPullUpDown(uint8_t pin, pupd_t pupd)
{
	uint32_t reg;

	if(pin > 15)
		return error_t::OUT_OF_PIN_INDEX_RANGE;
	
	pin *= 2;
	
	__disable_irq();
	reg = mDev->PUSEL;
	reg &= ~(0x3 << pin);
	reg |= pupd << pin;
	mDev->PUSEL = reg;
	__enable_irq();

	return error_t::ERROR_NONE;
}

error_t Gpio::enablInterrupt(uint8_t pin, source_t src, void (*isr)(void))
{
	if(pin >= 16)
		return error_t::OUT_OF_PIN_INDEX_RANGE;

	bool level = false;

	mIsr[pin] = isr;

	switch((uint8_t)src)
	{
	case EDGE_BOTH :
		setBitData(mDev->INTEN, true, pin);
		
	case EDGE_RISING :
		setBitData(mDev->INTEN, true, (pin + 16));
		break;
	
	case EDGE_FALLING :
		setBitData(mDev->INTEN, true, pin);
		break;

	case LEVEL_HIGH :
		setBitData(mDev->INTEN, true, (pin + 16));
		level = true;
		break;
	
	case LEVEL_LOW :
		setBitData(mDev->INTEN, true, pin);
		level = true;
		break;
	}

	setBitData(mDev->INTTYPE, level, pin);

	return error_t::ERROR_NONE;
}

void Gpio::isr(void)
{
	uint16_t comp = 0x01;

	for(uint32_t i = 0; i < 16; i++)
	{
		if(mDev->INTSRC & comp)
		{
			if(mIsr[i])
				mIsr[i]();
		
			mDev->INTSRC |= comp;
		}

		comp <<= 1;
	}
}

bool Gpio::getInputData(uint8_t pin)
{
	return (mDev->PIN >> pin) & 0x01;
}

#endif

