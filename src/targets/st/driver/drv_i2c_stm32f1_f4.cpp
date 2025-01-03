/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined(GD32F1) || defined(STM32F1)

#include <drv/peripheral.h>
#include <drv/I2c.h>

#include <yss/thread.h>
#include <util/runtime.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

#define TRANSMIT	false
#define RECEIVE		true

I2c::I2c(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mDataCount = 0;
	mDataBuf = 0;
	mDir = TRANSMIT;
}

error_t I2c::initialize(config_t config)
{
	if(config.mode == MODE_SUB)
		return error_t::NOT_SUPPORTED_YET;

	uint32_t clk = getClockFrequency(), mod;
	
	// soft reset
	setBitData(mDev->CR1, true, 15);
	setBitData(mDev->CR1, false, 15);

	setFieldData(mDev->CR2, 0x3F << 0, clk / 1000000, 0);

	switch (config.speed)
	{
	case SPEED_STANDARD:
		mod = clk % 200000;
		clk /= 200000;
		if (mod)
			clk++;
		break;
	case SPEED_FAST:
		mod = clk % 1200000;
		clk /= 1200000;
		if (mod)
			clk++;
		break;
	default:
		return error_t::WRONG_CONFIG;
	}

	// Status Clear
	mDev->SR1;
	mDev->SR2;
	
	setBitData(mDev->CCR, config.speed, 15);				// 통신 속도 설정
	setFieldData(mDev->CCR, 0xFFF << 0, clk, 0);	// 분주 설정
	setBitData(mDev->CR1, true, 0);				// I2C 활성화

	return error_t::ERROR_NONE;
}

error_t I2c::send(uint8_t addr, void *src, uint32_t size, uint32_t timeout)
{
	uint64_t endingTime = runtime::getMsec() + timeout;

	setBitData(mDev->CR1, true, 8);		// start
	mDir = TRANSMIT;
	mAddr = addr;
	mDataCount = size;
	mDataBuf = (uint8_t*)src;
	mDev->CR2 |= I2C_CR2_ITEVTEN_Msk;

	while (mDataCount || getBitData(mDev->SR1, 2) == false) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= runtime::getMsec())
		{
			mDev->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			return error_t::TIMEOUT;
		}
		thread::yield();
	}

	return error_t::ERROR_NONE;
}

error_t I2c::receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout)
{
	uint64_t endingTime = runtime::getMsec() + timeout;

	switch (size)
	{
	case 0:
		return error_t::ERROR_NONE;
	case 1:
		setBitData(mDev->CR1, false, 10);	// ACK 비활성
		break;
	default:
		setBitData(mDev->CR1, true, 10);	// ACK 활성
		break;
	}

	mDev->SR1;
	mDev->SR2;
	setBitData(mDev->CR1, true, 8);		// start
	mDir = RECEIVE;
	mAddr = addr;
	mDataCount = size;
	mDataBuf = (uint8_t*)des;
	mDev->CR2 |= I2C_CR2_ITEVTEN_Msk;

	while (mDataCount) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= runtime::getMsec())
		{
			mDev->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			return error_t::TIMEOUT;
		}
		thread::yield();
	}
	
	stop();

	return error_t::ERROR_NONE;
}

void I2c::stop(void)
{
	if (getBitData(mDev->SR2, 1)) // Busy 확인
	{
		setBitData(mDev->CR1, true, 9);		// Stop
		setBitData(mDev->CR1, false, 10);	// ACK 비활성

		__ISB();
		while(getBitData(mDev->SR2, 1))
			thread::yield();
	}
}

void I2c::isr(void)
{
	uint32_t sr1 = mDev->SR1;
	
	if(mDir == TRANSMIT)
	{
		if(sr1 & I2C_SR1_SB_Msk)
		{
			mDev->SR2;
			mDev->DR = mAddr & 0xFE;	// ADDR 전송
		}
		else if(sr1 & I2C_SR1_ADDR_Msk)
		{
			mDev->SR2;
			mDev->CR2 |= I2C_CR2_ITBUFEN_Msk;
		}
		else if(sr1 & I2C_SR1_TXE_Msk)
		{
			if(mDataCount == 0)
				mDev->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			else
			{
				mDev->DR = *mDataBuf++;
				mDataCount--;
			}
		}
		else
		{
			mDev->SR2;
		}
	}
	else
	{
		if(sr1 & I2C_SR1_SB_Msk)
		{
			mDev->SR2;
			mDev->DR = mAddr | 0x01;	// ADDR 전송
		}
		else if(sr1 & I2C_SR1_ADDR_Msk)
		{
			mDev->SR2;
			mDev->CR2 |= I2C_CR2_ITBUFEN_Msk;

			switch (mDataCount)
			{
			case 0:
			case 1:
				setBitData(mDev->CR1, false, 10);	// ACK 비활성
				setBitData(mDev->CR1, true, 9);		// Stop
				break;
			default:
				setBitData(mDev->CR1, true, 10);	// ACK 활성
				break;
			}
		}
		else if(sr1 & I2C_SR1_RXNE_Msk)
		{
			if(mDataCount == 2)
			{
				setBitData(mDev->CR1, false, 10);	// ACK 비활성
				setBitData(mDev->CR1, true, 9);		// Stop
			}

			mDataCount--;
			*mDataBuf++ = mDev->DR;

			if(mDataCount == 0)
			{
				mDev->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			}
		}
		else if(sr1 & I2C_SR1_TXE_Msk)
		{
			mDev->DR;
		}
		else
		{
			mDev->SR2;
		}
	}
}

#endif

