/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/I2c.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>
#include <util/Timeout.h>

I2c::I2c(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mDma = nullptr;
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
	mDma = allocateDma();

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
	
	mDma->setSource(mTxDmaInfo.src);
	mDma->ready(mTxDmaInfo, src, size);
	mDev->DAT = addr;
	mDev->CTL0 |= I2C_CTL0_STA_Msk;

	while(!mDma->isComplete())
	{
		if(tout.isTimeout())
		{
			return error_t::TIMEOUT;
		}

		thread::yield();
	}

	if(mDma->isError())
		return error_t::DMA_ERROR;
	else
		return error_t::ERROR_NONE;
}

void I2c::isr(void)
{
	switch(mDev->STATUS0)
	{
	case 0x18 : // Write ACK
		mDev->CTL1 |= I2C_CTL1_PDMASTR_Msk | I2C_CTL1_TXPDMAEN_Msk;
		mDma->trigger();
	case 0x28 :
	case 0x08 : // Start
		mDev->CTL0 |= I2C_CTL0_SI_Msk;
		break;
	}
}

#endif

