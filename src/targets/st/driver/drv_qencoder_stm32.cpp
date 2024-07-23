/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F7)

#include <drv/peripheral.h>
#include <drv/Qencoder.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Qencoder::Qencoder(const Drv::setup_t &drvSetup, const setup_t &setup) : Drv(drvSetup)
{
	mPeri = setup.peri;
}

void Qencoder::initialize(void)
{
	setFieldData(mPeri->SMCR, TIM_SMCR_SMS_Msk, 3, TIM_SMCR_SMS_Pos);
}

void Qencoder::start(void)
{
	setBitData(mPeri->CR1, true, TIM_CR1_CEN_Pos);	// Timer Enable
}

void Qencoder::stop(void)
{
	setBitData(mPeri->CR1, false, TIM_CR1_CEN_Pos);	// Timer Enable
}

int16_t Qencoder::getCount(void)
{
	return mPeri->CNT;
}

void Qencoder::resetCount(void)
{
	mPeri->CNT = 0;
}

#endif

