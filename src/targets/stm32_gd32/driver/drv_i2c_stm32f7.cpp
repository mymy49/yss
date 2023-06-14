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

#if defined(STM32F7)

#include <drv/I2c.h>
#include <targets/st_gigadevice/i2c_stm32f7.h>
#include <drv/Dma.h>

#include <util/runtime.h>
#include <yss/thread.h>

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
	switch (speed)
	{
	case STANDARD:
		mDev[I2C_REG::TIMINGR] =	((3 << I2C_TIMINGR_PRESC_Pos) & I2C_TIMINGR_PRESC_Msk) |
									((0xC7 << I2C_TIMINGR_SCLL_Pos) & I2C_TIMINGR_SCLL_Msk) |
									((0xC3 << I2C_TIMINGR_SCLH_Pos) & I2C_TIMINGR_SCLH_Msk) |
									((0x02 << I2C_TIMINGR_SDADEL_Pos) & I2C_TIMINGR_SDADEL_Msk) |
									((0x04 << I2C_TIMINGR_SCLDEL_Pos) & I2C_TIMINGR_SCLDEL_Msk);
		break;

	case FAST:
		mDev[I2C_REG::TIMINGR] =	((1 << I2C_TIMINGR_PRESC_Pos) & I2C_TIMINGR_PRESC_Msk) |
									((0x09 << I2C_TIMINGR_SCLL_Pos) & I2C_TIMINGR_SCLL_Msk) |
									((0x03 << I2C_TIMINGR_SCLH_Pos) & I2C_TIMINGR_SCLH_Msk) |
									((0x02 << I2C_TIMINGR_SDADEL_Pos) & I2C_TIMINGR_SDADEL_Msk) |
									((0x03 << I2C_TIMINGR_SCLDEL_Pos) & I2C_TIMINGR_SCLDEL_Msk);
		break;

	case FAST_PLUS:
		mDev[I2C_REG::TIMINGR] =	((0 << I2C_TIMINGR_PRESC_Pos) & I2C_TIMINGR_PRESC_Msk) |
									((0x04 << I2C_TIMINGR_SCLL_Pos) & I2C_TIMINGR_SCLL_Msk) |
									((0x02 << I2C_TIMINGR_SCLH_Pos) & I2C_TIMINGR_SCLH_Msk) |
									((0x00 << I2C_TIMINGR_SDADEL_Pos) & I2C_TIMINGR_SDADEL_Msk) |
									((0x02 << I2C_TIMINGR_SCLDEL_Pos) & I2C_TIMINGR_SCLDEL_Msk);
		break;
	}

	mDev[I2C_REG::CR1] |= I2C_CR1_TXDMAEN_Msk | I2C_CR1_RXDMAEN_Msk | I2C_CR1_PE_Msk;

	return error::ERROR_NONE;
}

error I2c::initializeAsSub(void *rcvBuf, uint16_t rcvBufSize, uint8_t addr1, uint8_t addr2)
{
	register uint32_t reg;

	mDev[I2C_REG::OAR1] &= ~I2C_OAR1_OA1EN_Msk;
	mDev[I2C_REG::OAR2] &= ~I2C_OAR2_OA2EN_Msk;

	reg =  I2C_OAR1_OA1EN_Msk | (addr1 & 0xFE) << I2C_OAR1_OA1_Pos;
	mDev[I2C_REG::OAR1] = reg;

	if(addr2 > 0)
	{
		reg = 0;
		reg |=  I2C_OAR2_OA2EN_Msk | (addr2 & 0xFE);
		mDev[I2C_REG::OAR2] = reg;
	}

	reg = I2C_CR1_RXDMAEN_Msk | I2C_CR1_TXDMAEN_Msk | I2C_CR1_ADDRIE_Msk | I2C_CR1_PE_Msk;
	mDev[I2C_REG::CR1] = reg;

	return error::ERROR_NONE;
}

inline void waitUntilComplete(YSS_I2C_Peri *peri)
{
	while ((peri[I2C_REG::ISR] & I2C_ISR_TC) == false)
		thread::yield();
}

#define setNbytes(data, x)	setFieldData(data, I2C_CR2_NBYTES_Msk, x, I2C_CR2_NBYTES_Pos)
#define setSaddr(data, x)	setFieldData(data, I2C_CR2_SADD_Msk, x, I2C_CR2_SADD_Pos)

error I2c::send(uint8_t addr, void *src, uint32_t size, uint32_t timeout)
{
	uint32_t cr2 = I2C_CR2_START;
	volatile uint32_t isr;
	error rt = error::UNKNOWN;
	
	mTxDma->lock();
	mDev[I2C_REG::ICR] = 0xffff;
	
	setNbytes(cr2, size);
	setSaddr(cr2, addr);
	mDev[I2C_REG::CR2] = cr2;

#if !defined(__CORE_CM0_H_GENERIC)
	thread::delayUs(2);
#else
	thread::yield();
#endif

	do
	{
		isr = mDev[I2C_REG::ISR];

		if (isr & I2C_ISR_NACKF)
		{
			rt = error::NACK;
			goto error;
		}

		thread::yield();
	} while ((isr & I2C_ISR_TXIS) == false);

	rt = mTxDma->send(mTxDmaInfo, src, size);

	waitUntilComplete(mDev);

error :
	mTxDma->unlock();
	return rt;
}

error I2c::receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout)
{
	uint32_t cr2 = I2C_CR2_START | I2C_CR2_RD_WRN;
	volatile uint32_t isr;
	error rt = error::UNKNOWN;

	mRxDma->lock();

	mDev[I2C_REG::ICR] = 0xffff;
	setNbytes(cr2, size);
	setSaddr(cr2, addr);
	mDev[I2C_REG::CR2] = cr2;

#if !defined(__CORE_CM0_H_GENERIC)
	thread::delayUs(2);
#else
	thread::yield();
#endif

	do
	{
		isr = mDev[I2C_REG::ISR];

		if (isr & I2C_ISR_NACKF)
			goto error;

		thread::yield();
	} while ((isr & I2C_ISR_RXNE) == false);

	rt = mRxDma->receive(mRxDmaInfo, des, size);
	waitUntilComplete(mDev);
	
error :
	mRxDma->unlock();
	return rt;
}

void I2c::stop(void)
{
	setBitData(mDev[I2C_REG::CR2], true, I2C_CR2_STOP_Pos);
}

#endif

