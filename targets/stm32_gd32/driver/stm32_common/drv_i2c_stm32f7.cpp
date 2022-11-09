////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if false

#include <drv/I2c.h>
#include <drv/Dma.h>
#include <drv/i2c/register_i2c_stm32f7.h>

#include <util/time.h>
#include <yss/thread.h>

I2c::I2c(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
}

bool I2c::init(uint8_t speed)
{
	switch (speed)
	{
	case define::i2c::speed::STANDARD:
		setI2cPresc(mPeri, 3);
		setI2cScll(mPeri, 0xc7);
		setI2cSclh(mPeri, 0xc3);
		setI2cSdaDel(mPeri, 0x02);
		setI2cSclDel(mPeri, 0x04);
		break;
	case define::i2c::speed::FAST:
		setI2cPresc(mPeri, 1);
		setI2cScll(mPeri, 0x09);
		setI2cSclh(mPeri, 0x03);
		setI2cSdaDel(mPeri, 0x02);
		setI2cSclDel(mPeri, 0x03);
		break;
	case define::i2c::speed::FAST_PLUS:
		setI2cPresc(mPeri, 0);
		setI2cScll(mPeri, 0x04);
		setI2cSclh(mPeri, 0x02);
		setI2cSdaDel(mPeri, 0x00);
		setI2cSclDel(mPeri, 0x02);
		break;
	}

	setI2cTxDmaEn(mPeri, true);
	setI2cRxDmaEn(mPeri, true);

	setI2cEn(mPeri, true);

	return true;
}

bool I2c::initAsSlave(void *rcvBuf, uint16_t rcvBufSize, uint8_t addr1, uint8_t addr2)
{
	register uint32_t reg;

	mPeri->OAR1 &= ~I2C_OAR1_OA1EN_Msk;
	mPeri->OAR2 &= ~I2C_OAR2_OA2EN_Msk;

	reg =  I2C_OAR1_OA1EN_Msk | (addr1 & 0xFE) << I2C_OAR1_OA1_Pos;
	mPeri->OAR1 = reg;

	if(addr2 > 0)
	{
		reg = 0;
		reg |=  I2C_OAR2_OA2EN_Msk | (addr2 & 0xFE);
		mPeri->OAR2 = reg;
	}

	reg = I2C_CR1_RXDMAEN_Msk | I2C_CR1_TXDMAEN_Msk | I2C_CR1_ADDRIE_Msk | I2C_CR1_PE_Msk;
	mPeri->CR1 = reg;

	return true;
}

inline void waitUntilComplete(I2C_TypeDef *peri)
{
	while ((peri->ISR & I2C_ISR_TC) == false)
		thread::yield();
}

#define setNbytes(data, x) setRegField(data, 0xFFUL, x, 16)
#define setSaddr(data, x) setRegField(data, 0x3FFUL, x, 0)

bool I2c::send(uint8_t addr, void *src, uint32_t size, uint32_t timeout)
{
	uint32_t cr2 = I2C_CR2_START;
	volatile uint32_t isr;
	bool rt = false;
	
	mTxDma->lock();
	mPeri->ICR = 0xffff;
	setNbytes(cr2, size);
	setSaddr(cr2, addr);
	mPeri->CR2 = cr2;

#if !defined(__CORE_CM0_H_GENERIC)
	thread::delayUs(2);
#else
	thread::yield();
#endif

	do
	{
		isr = mPeri->ISR;

		if (isr & I2C_ISR_NACKF)
			goto error;

		thread::yield();
	} while ((isr & I2C_ISR_TXIS) == false);

	rt = mTxDma->send(mTxDmaInfo, src, size);

	waitUntilComplete(mPeri);

error :
	mTxDma->unlock();
	return rt;
}

bool I2c::receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout)
{
	uint32_t cr2 = I2C_CR2_START | I2C_CR2_RD_WRN;
	volatile uint32_t isr;
	bool rt = false;

	mRxDma->lock();

	mPeri->ICR = 0xffff;
	setNbytes(cr2, size);
	setSaddr(cr2, addr);
	mPeri->CR2 = cr2;

#if !defined(__CORE_CM0_H_GENERIC)
	thread::delayUs(2);
#else
	thread::yield();
#endif

	do
	{
		isr = mPeri->ISR;

		if (isr & I2C_ISR_NACKF)
			goto error;

		thread::yield();
	} while ((isr & I2C_ISR_RXNE) == false);

	rt = mRxDma->receive(mRxDmaInfo, des, size);
	waitUntilComplete(mPeri);
	
error :
	mRxDma->unlock();
	return rt;
}

void I2c::stop(void)
{
	setI2cStop(mPeri);
}

#endif

