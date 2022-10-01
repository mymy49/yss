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

#if defined(STM32G4)

#include <drv/I2c.h>
#include <util/time.h>
#include <yss/thread.h>

namespace drv
{
I2c::I2c(I2C_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), Stream *txStream, Stream *rxStream, uint8_t txChannel, uint8_t rxChannel, uint32_t (*getClockFrequencyFunc)(void), uint16_t priority) : Drv(clockFunc, nvicFunc, resetFunc)
{
	mPeri = peri;
}

bool I2c::init(uint8_t speed)
{
	switch (speed)
	{
	case define::i2c::speed::STANDARD:
		mPeri->TIMINGR = 3 << I2C_TIMINGR_PRESC_Pos |
						 4 << I2C_TIMINGR_SCLDEL_Pos |
						 2 << I2C_TIMINGR_SDADEL_Pos |
						 0xC3 << I2C_TIMINGR_SCLH_Pos |
						 0xC7 << I2C_TIMINGR_SCLL_Pos;
		break;
	case define::i2c::speed::FAST:
		mPeri->TIMINGR = 1 << I2C_TIMINGR_PRESC_Pos |
						 3 << I2C_TIMINGR_SCLDEL_Pos |
						 2 << I2C_TIMINGR_SDADEL_Pos |
						 3 << I2C_TIMINGR_SCLH_Pos |
						 9 << I2C_TIMINGR_SCLL_Pos;
		break;
	case define::i2c::speed::FAST_PLUS:
		mPeri->TIMINGR = 0 << I2C_TIMINGR_PRESC_Pos |
						 2 << I2C_TIMINGR_SCLDEL_Pos |
						 0 << I2C_TIMINGR_SDADEL_Pos |
						 2 << I2C_TIMINGR_SCLH_Pos |
						 4 << I2C_TIMINGR_SCLL_Pos;
		break;
	}

	mPeri->CR1 |= I2C_CR1_PE_Msk;

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
	uint32_t isr;
	uint64_t endTime = time::getRunningMsec() + timeout;
	uint8_t *csrc = (uint8_t *)src;

	mPeri->ICR = 0xffff;
	mPeri->CR2 = I2C_CR2_START_Msk | ((size << I2C_CR2_NBYTES_Pos) & I2C_CR2_NBYTES_Msk) | (addr & I2C_CR2_SADD_Msk);


#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	thread::delayUs(2);
#else
	thread::yield();
#endif

	do
	{
		isr = mPeri->ISR;
		if (isr & I2C_ISR_NACKF)
			return false;
		thread::yield();

		if (endTime < time::getRunningMsec())
			return false;
	} while (!(isr & I2C_ISR_TXIS));

	while (size)
	{
		while (!(mPeri->ISR & I2C_ISR_TXE_Msk))
		{
			if (endTime < time::getRunningMsec())
				return false;
			thread::yield();
		}

		mPeri->TXDR = *csrc++;

		size--;
	}

	while (!(mPeri->ISR & I2C_ISR_TXE_Msk))
	{
		if (endTime < time::getRunningMsec())
			return false;
		thread::yield();
	}

	return true;
}

bool I2c::receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout)
{
	uint32_t isr;
	uint64_t endTime = time::getRunningMsec() + timeout;
	uint8_t *cdes = (uint8_t *)des;

	mPeri->ICR = 0xffff;
	mPeri->CR2 = I2C_CR2_START_Msk | I2C_CR2_RD_WRN_Msk | ((size << I2C_CR2_NBYTES_Pos) & I2C_CR2_NBYTES_Msk) | (addr & I2C_CR2_SADD_Msk);

	while (size)
	{
		while (!(mPeri->ISR & I2C_ISR_RXNE_Msk))
		{
			if (endTime < time::getRunningMsec())
				return false;
			thread::yield();
		}

		*cdes++ = mPeri->RXDR;
		size--;
	}

	return true;
}

void I2c::stop(void)
{
	mPeri->CR2 = I2C_CR2_STOP_Msk;
}
}

#endif