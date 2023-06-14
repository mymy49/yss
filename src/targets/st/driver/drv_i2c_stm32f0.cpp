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

#include <drv/peripheral.h>

#if defined(STM32F0_N)

#include <drv/peripheral.h>
#include <drv/I2c.h>

#include <yss/thread.h>
#include <yss/reg.h>
#include <util/ElapsedTime.h>

#if defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#endif

I2c::I2c(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mDev = config.dev;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
}

error I2c::initializeAsMain(uint8_t speed)
{
	uint32_t clk = getClockFrequency();
	uint8_t scll, sclh, sdadel, scldel, pre;

	using namespace define::i2c::speed;

	switch (speed)
	{
	default :
	case STANDARD :
		clk /= 100000;
		scll = 0x13;
		sclh = 0xF;
		sdadel = 2;
		scldel = 4;
		break;

	case FAST :
		clk /= 400000;
		scll = 0x9;
		sclh = 0x3;
		sdadel = 3;
		scldel = 3;
		break;

	case FAST_PLUS :
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

	return error::ERROR_NONE;
}

error I2c::initializeAsSub(void *rcvBuf, uint16_t rcvBufSize, uint8_t addr1, uint8_t addr2)
{
	register uint32_t reg;

	mDev->OAR1 &= ~I2C_OAR1_OA1EN_Msk;
	mDev->OAR2 &= ~I2C_OAR2_OA2EN_Msk;

	reg =  I2C_OAR1_OA1EN_Msk | (addr1 & 0xFE) << I2C_OAR1_OA1_Pos;
	mDev->OAR1 = reg;

	if(addr2 > 0)
	{
		reg = 0;
		reg |=  I2C_OAR2_OA2EN_Msk | (addr2 & 0xFE);
		mDev->OAR2 = reg;
	}

	reg = I2C_CR1_RXDMAEN_Msk | I2C_CR1_TXDMAEN_Msk | I2C_CR1_ADDRIE_Msk | I2C_CR1_PE_Msk;
	mDev->CR1 = reg;

	return error::ERROR_NONE;
}

inline error waitUntilComplete(YSS_I2C_Peri *peri, ElapsedTime &time, uint32_t timeout)
{
	uint32_t sr;
	while (true)
	{
		sr = peri->ISR;
		if(sr & I2C_ISR_TC)
			return error::ERROR_NONE;
		
		if(sr & I2C_ISR_NACKF_Msk)
			return error::FAIL;

		if(time.getMsec() > timeout)
			return error::TIMEOUT;

		thread::yield();
	}
}

#define setNbytes(data, x)	setFieldData(data, I2C_CR2_NBYTES_Msk, x, I2C_CR2_NBYTES_Pos)
#define setSaddr(data, x)	setFieldData(data, I2C_CR2_SADD_Msk, x, I2C_CR2_SADD_Pos)

error I2c::send(uint8_t addr, void *src, uint32_t size, uint32_t timeout)
{
	if(size == 0)
		return  error::ERROR_NONE;

	uint32_t cr2 = I2C_CR2_START;
	volatile uint32_t isr;
	error result = error::UNKNOWN;
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
			result = error::NACK;
			goto error;
		}

		if(time.getMsec() > timeout)
		{
			result = error::TIMEOUT;
			goto error;
		}

		thread::yield();
	} while ((isr & I2C_ISR_TXIS) == false);
	
	if(size > 1)
	{
		mTxDma->lock();
		result = mTxDma->send(mTxDmaInfo, src, size);
		mTxDma->unlock();

		if(result != error::ERROR_NONE)
			return result;
	}
	else
		mDev->TXDR = *(uint8_t*)src;

	result = waitUntilComplete(mDev, time, timeout);

error :
	return result;
}

error I2c::receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout)
{
	if(size == 0)
		return  error::ERROR_NONE;

	uint32_t cr2 = I2C_CR2_START | I2C_CR2_RD_WRN;
	volatile uint32_t isr;
	error result = error::ERROR_NONE;
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
			result = error::NACK;
			goto error;
		}

		if(time.getMsec() > timeout)
		{
			result = error::TIMEOUT;
			goto error;
		}

		thread::yield();
	} 

	if(size > 1)
	{
		mRxDma->lock();
		result = mRxDma->receive(mRxDmaInfo, des, size);
		mRxDma->unlock();

		if(result != error::ERROR_NONE)
			goto error;

		result = waitUntilComplete(mDev, time, timeout);
	}
	else
	{
		*((uint8_t*)des) = mDev->RXDR;
	}

error :
	return result;
}

void I2c::stop(void)
{
	setBitData(mDev->CR2, true, I2C_CR2_STOP_Pos);
}

#endif

