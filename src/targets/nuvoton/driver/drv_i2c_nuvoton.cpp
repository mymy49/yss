/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/I2c.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <yss/debug.h>
#include <targets/nuvoton/bitfield_m4xx.h>
#include <util/Timeout.h>

I2c::I2c(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
}

error_t I2c::initialize(config_t config)
{
	int32_t div = getClockFrequency() / 4;
	
	switch(config.speed)
	{
	case SPEED_STANDARD :
		div /= 100000;
		div -= 1;
		break;
	
	case SPEED_FAST :
		div /= 400000;
		div -= 1;
		break;

	default :
		return error_t::NOT_SUPPORTED_YET;
	}

	if(div < 4)
		return error_t::WRONG_CLOCK_FREQUENCY;

	mDev->CLKDIV = div;
	mDev->CTL0 |= I2C_CTL0_I2CEN_Msk | I2C_CTL0_INTEN_Msk;
	mDev->CTL1 |= I2C_CTL1_PDMASTR_Msk;

	return error_t::ERROR_NONE;
}

error_t I2c::send(uint8_t addr, void *src, uint32_t size, uint32_t timeout)
{
	Timeout tout(timeout);

	while(mDev->STATUS1 & I2C_STATUS1_ONBUSY_Msk)
	{
		if(tout.isTimeout())
		{
			return error_t::BUSY;
		}

		thread::yield();
	}

	mError = error_t::ERROR_NONE;
	mComplete = false;
	mAddr = addr & 0xFE;
	mDataCount = size;
	mDataBuf = (uint8_t*)src;
	mDev->CTL0 |= I2C_CTL0_STA_Msk;

	while(!mComplete && mError == error_t::ERROR_NONE && !tout.isTimeout())
		thread::yield();

	if(tout.isTimeout())
		return error_t::TIMEOUT;
	else
		return mError;
}

error_t I2c::receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout)
{
	Timeout tout(timeout);

	mError = error_t::ERROR_NONE;
	mComplete = false;
	mAddr = addr | 0x01;
	mDataCount = size;
	if(size > 1)
		mDev->CTL0 |= I2C_CTL0_AA_Msk;
	else
		mDev->CTL0 &= ~I2C_CTL0_AA_Msk;

	mDataBuf = (uint8_t*)des;
	mDev->CTL0 |= I2C_CTL0_STA_Msk;

	while(!mComplete && mError == error_t::ERROR_NONE && !tout.isTimeout())
		thread::yield();

	if(tout.isTimeout())
		return error_t::TIMEOUT;
	else
		return mError;
}

void I2c::stop(void)
{
	if(mDev->STATUS1 & I2C_STATUS1_ONBUSY_Msk)
	{
		mDev->CTL0 |= I2C_CTL0_STO_Msk;
	}
}

void I2c::isr(void)
{
	switch(mDev->STATUS0)
	{
	case 0x08 : // Start
	case 0x10 : // Master Repeat Start
		mDev->DAT = mAddr;
		mDev->CTL0 |= I2C_CTL0_SI_Msk;
		break;

	case 0x18 : // Master Transmit Address ACK
		mDataCount--;
		mDev->DAT = *mDataBuf++;
		mDev->CTL0 |= I2C_CTL0_SI_Msk;
		break;

	case 0x28 : // Master Transmit Data ACK
		if(mDataCount > 0)
		{
			mDataCount--;
			mDev->DAT = *mDataBuf++;
		}
		else
		{
			mComplete = true;
		}
		mDev->CTL0 |= I2C_CTL0_SI_Msk;
		break;

	case 0x40 : // Master Receive Address ACK
		mDev->CTL0 |= I2C_CTL0_SI_Msk;
		break;
	
	case 0x50 : // Master Receive Data ACK
		*mDataBuf++ = mDev->DAT;
		if(mDataCount == 1)
			mDev->CTL0 &= ~I2C_CTL0_AA_Msk;
		break;
	
	case 0x58 : // Master Receive Data NACK
		*mDataBuf++ = mDev->DAT;
		mComplete = true;
		mDev->CTL0 |= I2C_CTL0_SI_Msk;
		break;

	case 0x00 : // Bus error
		mDev->CTL0 |= I2C_CTL0_SI_Msk | I2C_CTL0_STO_Msk;
		break;

	case 0x20 : // Master Transmit Address NACK
	case 0x30 : // Master Transmit Data NACK
	case 0x48 : // Master Receive Address NACK
		mError = error_t::NACK;
		mComplete = true;
		mDev->CTL0 |= I2C_CTL0_SI_Msk;
		break;

	default:
		mDev->CTL0 |= I2C_CTL0_SI_Msk;
		break;
	}

}

#endif

