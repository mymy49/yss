/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M251_SUBFAMILY__)

#include <drv/Gpio.h>
#include <yss/reg.h>

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mMfp = setup.mfp;
#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
	mOutputReg = (volatile uint32_t*)(((uint32_t)&mDev->DOUT - 0x40000000) * 32 + 0x42000000);
#elif defined(__M251_SUBFAMILY__)
	mOutputReg = (volatile uint32_t*)(((uint32_t)mDev + 0x800));
#endif
	for(uint32_t i = 0; i < 16; i++)
		mIsr[i] = nullptr;
}

error_t Gpio::setAsOutput(uint8_t pin, otype_t otype, slewrate_t slewrate)
{
	if(pin > 15)
		return error_t::OUT_OF_PIN_INDEX_RANGE;
	
	setAsAltFunc(pin, PA0_GPIO, AF_PUSH_PULL, slewrate);

	pin <<= 1;
	__disable_irq();
	setFieldData(mDev->MODE, 0x03 << pin, otype, pin);
	__enable_irq();

	return error_t::ERROR_NONE;
}

error_t Gpio::setAsInput(uint8_t pin)
{
	uint32_t reg;

	if(pin > 15)
		return error_t::OUT_OF_PIN_INDEX_RANGE;
	
	pin <<= 1;
	__disable_irq();
	setFieldData(mDev->MODE, 0x03 << pin, 0x00, pin);
	__enable_irq();
	 
		
	return error_t::ERROR_NONE;
}


void Gpio::setOutput(uint8_t pin, bool data)
{
	mOutputReg[pin] = data;
}

error_t Gpio::setAsAltFunc(uint8_t pin, altFunc_t altfunc, atype_t atype, slewrate_t slewrate)
{
	uint32_t reg, index;
	volatile uint32_t *des;

	if(pin > 15)
		return error_t::OUT_OF_PIN_INDEX_RANGE;
#if defined(__M46x_SUBFAMILY)
	__disable_irq();
	des = &SYS->GPA_MFOS;
	des = &des[((uint32_t)mDev - GPIOA_BASE) / 0x40];
	setBitData(*des, atype, pin);

	index = pin << 1;
	setFieldData(mDev->SLEWCTL, 0x03 << index, slewrate, index);

	index = pin >> 2;
	pin = (pin << 3) & 0x1F;
	des = &SYS->GPA_MFP0;
	des = &des[((uint32_t)mDev - GPIOA_BASE) / 0x10];
	setFieldData(des[index], 0x1F << pin, altfunc, pin);
	__enable_irq();
#elif defined(__M480_FAMILY) || defined(__M43x_SUBFAMILY) || defined(__M251_SUBFAMILY__)
	__disable_irq();
	des = &SYS->GPA_MFOS;
	des = &des[((uint32_t)mDev - GPIOA_BASE) / 0x40];
	setBitData(*des, atype, pin);

	index = pin << 1;
	setFieldData(mDev->SLEWCTL, 0x03 << index, slewrate, index);

	index = pin >> 3;
	pin = (pin << 2) & 0x1F;
	des = &SYS->GPA_MFPL;
	des = &des[((uint32_t)mDev - GPIOA_BASE) / 0x20];
	setFieldData(des[index], 0x0F << pin, altfunc, pin);
	__enable_irq();
#endif

	return error_t::ERROR_NONE;
}

error_t Gpio::setPackageAsAltFunc(altFuncPackage_t *package, uint8_t count, atype_t atype, slewrate_t slewrate)
{
	GPIO_T *port;
	uint8_t pin, pinOffset;
	uint32_t reg, index;
	volatile uint32_t *des;
	
	for (uint8_t i = 0; i < count; i++)
	{
		port = package[i].port;
		pin = package[i].pin;
	
		if(pin > 15)
			return error_t::OUT_OF_PIN_INDEX_RANGE;
		
#if defined(__M46x_SUBFAMILY)
		des = &SYS->GPA_MFOS;
		des = &des[((uint32_t)port - GPIOA_BASE) / 0x10];
		setBitData(*des, atype, pin);

		index = pin << 1;
		setFieldData(port->SLEWCTL, 0x03 << index, slewrate, index);

		index = pin >> 2;
		pin = (pin << 3) & 0x1F;
		des = &SYS->GPA_MFP0;
		des = &des[((uint32_t)port - GPIOA_BASE) / 0x10];
		setFieldData(des[index], 0x1F << pin, package[i].func, pin);
#elif defined(__M251_SUBFAMILY__) || defined(__M43x_SUBFAMILY)
		des = &SYS->GPA_MFOS;
		des = &des[((uint32_t)port - GPIOA_BASE) / 0x10];
		setBitData(*des, atype, pin);

		index = pin << 1;
		setFieldData(port->SLEWCTL, 0x03 << index, slewrate, index);

		index = pin >> 3;
		pin = (pin << 2) & 0x1F;
		des = &SYS->GPA_MFPL;
		des = &des[((uint32_t)port - GPIOA_BASE) / 0x10];
		setFieldData(des[index], 0x0F << pin, package[i].func, pin);
#endif
	}

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

error_t Gpio::setGpioInterrupt(uint8_t pin, source_t src, void (*isr)(void))
{
	if(pin >= 16)
		return error_t::OUT_OF_PIN_INDEX_RANGE;

	bool level = false;

	mTriggerFlag[pin] = false;
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

error_t Gpio::setGpioInterrupt(uint8_t pin, source_t src, triggerId_t trigger)
{
	if(pin >= 16)
		return error_t::OUT_OF_PIN_INDEX_RANGE;

	bool level = false;
	
	mTriggerFlag[pin] = true;
	mTriggerNum[pin] = trigger;

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
			if (mTriggerFlag[i])
				trigger::run(mTriggerNum[i]);
			else if(mIsr[i])
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

