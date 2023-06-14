////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F4_N) || defined(GD32F1)

#include <drv/peripheral.h>
#include <drv/I2c.h>

#include <yss/thread.h>
#include <util/runtime.h>
#include <yss/reg.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(GD32F1)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

#define TRANSMIT	false
#define RECEIVE		true

I2c::I2c(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mDev = config.dev;
	mDataCount = 0;
	mDataBuf = 0;
	mDir = TRANSMIT;
}

error I2c::initializeAsMain(uint8_t speed)
{
	uint32_t clk = getClockFrequency(), mod;
	
	// soft reset
	setBitData(mDev->CR1, true, 15);
	setBitData(mDev->CR1, false, 15);

	setFieldData(mDev->CR2, 0x3F << 0, clk / 1000000, 0);

	switch (speed)
	{
	case define::i2c::speed::STANDARD:
		mod = clk % 200000;
		clk /= 200000;
		if (mod)
			clk++;
		break;
	case define::i2c::speed::FAST:
		mod = clk % 1200000;
		clk /= 1200000;
		if (mod)
			clk++;
		break;
	default:
		return error::WRONG_CONFIG;
	}

	// Status Clear
	mDev->SR1;
	mDev->SR2;
	
	setBitData(mDev->CCR, speed, 15);				// 통신 속도 설정
	setFieldData(mDev->CCR, 0xFFF << 0, clk, 0);	// 분주 설정
	setBitData(mDev->CR1, true, 0);				// I2C 활성화

	return error::ERROR_NONE;
}

error I2c::send(uint8_t addr, void *src, uint32_t size, uint32_t timeout)
{
	uint8_t *data = (uint8_t *)src;
	uint64_t endingTime = runtime::getMsec() + timeout;

	setBitData(mDev->CR1, true, 8);		// start
	mDir = TRANSMIT;
	mAddr = addr;
	mDataCount = size;
	mDataBuf = (uint8_t*)src;
	mDev->CR2 |= I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk;

	while (mDataCount || getBitData(mDev->SR1, 2) == false) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= runtime::getMsec())
		{
			mDev->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			return error::TIMEOUT;
		}
		thread::yield();
	}

	return error::ERROR_NONE;
}

error I2c::receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout)
{
	uint64_t endingTime = runtime::getMsec() + timeout;
	uint8_t *data = (uint8_t *)des;
	volatile uint16_t sr;

	switch (size)
	{
	case 0:
		return error::ERROR_NONE;
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
	mDev->CR2 |= I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk;

	while (mDataCount) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= runtime::getMsec())
		{
			mDev->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			return error::TIMEOUT;
		}
		thread::yield();
	}
	
	stop();

	return error::TIMEOUT;
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
	}
}

#endif

