/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(DAC1)

#if defined(STM32F4) || defined(STM32F7)

#include <drv/Dac.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Dac::Dac(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
}

void Dac::initialize(void)
{

}

void Dac::enableChannel1(bool en)
{
	setBitData(mDev->CR, en, DAC_CR_EN1_Pos);	// DAC Enable
}

void Dac::enableChannel2(bool en)
{
	setBitData(mDev->CR, en, DAC_CR_EN2_Pos);	// DAC Enable
}

void Dac::setOutputChannel1(uint16_t value)
{
	mDev->DHR12R1 = value;
}

void Dac::setOutputChannel2(uint16_t value)
{
	mDev->DHR12R2 = value;
}
#endif

#endif

