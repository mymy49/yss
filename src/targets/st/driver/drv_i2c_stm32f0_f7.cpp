/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F0) || defined(STM32F7)

#include <drv/peripheral.h>
#include <drv/I2c.h>

#include <yss/thread.h>
#include <yss/reg.h>
#include <util/ElapsedTime.h>
#include <targets/st/bitfield.h>

I2c::I2c(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDma = &setup.txDma;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDma = &setup.rxDma;
	mRxDmaInfo = setup.rxDmaInfo;
}

error_t I2c::initialize(config_t config)
{
	uint32_t clk = getClockFrequency();
	uint8_t scll, sclh, sdadel, scldel, pre;
	
	if(config.mode == MODE_MAIN)
	{
		switch(config.speed)
		{
		default :
		case SPEED_STANDARD :
			clk /= 100000;
			scll = 0x13;
			sclh = 0xF;
			sdadel = 2;
			scldel = 4;
			break;

		case SPEED_FAST :
			clk /= 400000;
			scll = 0x9;
			sclh = 0x3;
			sdadel = 3;
			scldel = 3;
			break;

		case SPEED_FAST_PLUS :
			if(clk < 16000000)
				clk /= 500000;
			else
				clk /= 1000000;
			scll = 0x6;
			sclh = 0x3;
			sdadel = 0;
			scldel = 2;
			break;
		}
	
		clk += clk / 8;
		pre = clk / ((scll + 1) + (sclh + 1) + (sdadel + 1) + (scldel + 1)) - 1;

		mDev->TIMINGR =	((pre << I2C_TIMINGR_PRESC_Pos) & I2C_TIMINGR_PRESC_Msk) |
						((scll << I2C_TIMINGR_SCLL_Pos) & I2C_TIMINGR_SCLL_Msk) |
						((sclh << I2C_TIMINGR_SCLH_Pos) & I2C_TIMINGR_SCLH_Msk) |
						((sdadel << I2C_TIMINGR_SDADEL_Pos) & I2C_TIMINGR_SDADEL_Msk) |
						((scldel << I2C_TIMINGR_SCLDEL_Pos) & I2C_TIMINGR_SCLDEL_Msk);

		mDev->CR1 |= I2C_CR1_TXDMAEN_Msk | I2C_CR1_RXDMAEN_Msk | I2C_CR1_PE_Msk;
	}
	else
	{
		return error_t::UNSUPPORTED_MODE;

		//mDev->OAR1 &= ~I2C_OAR1_OA1EN_Msk;
		//mDev->OAR2 &= ~I2C_OAR2_OA2EN_Msk;

		//reg =  I2C_OAR1_OA1EN_Msk | (config.addr1 & 0xFE) << I2C_OAR1_OA1_Pos;
		//mDev->OAR1 = reg;

		//if(config.addr2 > 0)
		//{
		//	reg = 0;
		//	reg |=  I2C_OAR2_OA2EN_Msk | (config.addr2 & 0xFE);
		//	mDev->OAR2 = reg;
		//}

		//reg = I2C_CR1_RXDMAEN_Msk | I2C_CR1_TXDMAEN_Msk | I2C_CR1_ADDRIE_Msk | I2C_CR1_PE_Msk;
		//mDev->CR1 = reg;
	}

	return error_t::ERROR_NONE;
}

inline error_t waitUntilComplete(YSS_I2C_Peri *peri, ElapsedTime &time, uint32_t timeout)
{
	uint32_t sr;
	while (true)
	{
		sr = peri->ISR;
		if(sr & I2C_ISR_TC)
			return error_t::ERROR_NONE;
		
		if(sr & I2C_ISR_NACKF_Msk)
			return error_t::FAIL;

		if(time.getMsec() > timeout)
			return error_t::TIMEOUT;

		thread::yield();
	}
}

#define setNbytes(data, x)	setFieldData(data, I2C_CR2_NBYTES_Msk, x, I2C_CR2_NBYTES_Pos)
#define setSaddr(data, x)	setFieldData(data, I2C_CR2_SADD_Msk, x, I2C_CR2_SADD_Pos)

error_t I2c::send(uint8_t addr, void *src, uint32_t size, uint32_t timeout)
{
	if(size == 0)
		return  error_t::ERROR_NONE;

	uint32_t cr2 = I2C_CR2_START;
	volatile uint32_t isr;
	error_t result = error_t::UNKNOWN;
	ElapsedTime time;
	
	mDev->ICR = 0xffff;
	
	setNbytes(cr2, size);
	setSaddr(cr2, addr);
	mDev->CR2 = cr2;
	__DSB();

	do
	{
		isr = mDev->ISR;

		if (isr & I2C_ISR_NACKF)
		{
			result = error_t::NACK;
			goto error_t;
		}

		if(time.getMsec() > timeout)
		{
			result = error_t::TIMEOUT;
			goto error_t;
		}

		thread::yield();
	} while ((isr & I2C_ISR_TXIS) == false);
	
	if(size > 1)
	{
		mTxDma->lock();
		result = mTxDma->transfer(mTxDmaInfo, src, size);
		mTxDma->unlock();

		if(result != error_t::ERROR_NONE)
			return result;
	}
	else
		mDev->TXDR = *(uint8_t*)src;

	result = waitUntilComplete(mDev, time, timeout);

error_t :
	return result;
}

error_t I2c::receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout)
{
	if(size == 0)
		return  error_t::ERROR_NONE;

	uint32_t cr2 = I2C_CR2_START | I2C_CR2_RD_WRN;
	volatile uint32_t isr;
	error_t result = error_t::ERROR_NONE;
	ElapsedTime time;

	mDev->ICR = 0xffff;
	setNbytes(cr2, size);
	setSaddr(cr2, addr);
	mDev->CR2 = cr2;

	__DSB();
	isr = mDev->ISR;

	while ((isr & I2C_ISR_RXNE) == false)
	{
		isr = mDev->ISR;

		if (isr & I2C_ISR_NACKF)
		{
			result = error_t::NACK;
			goto error_t;
		}

		if(time.getMsec() > timeout)
		{
			result = error_t::TIMEOUT;
			goto error_t;
		}

		thread::yield();
	} 

	if(size > 1)
	{
		mRxDma->lock();
		result = mRxDma->transfer(mRxDmaInfo, des, size);
		mRxDma->unlock();

		if(result != error_t::ERROR_NONE)
			goto error_t;

		result = waitUntilComplete(mDev, time, timeout);
	}
	else
	{
		*((uint8_t*)des) = mDev->RXDR;
	}

error_t :
	return result;
}

void I2c::stop(void)
{
	setBitData(mDev->CR2, true, I2C_CR2_STOP_Pos);
}

#endif

