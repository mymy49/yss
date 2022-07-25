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

//#include <__cross_studio_io.h>
#include <drv/mcu.h>

#if defined(STM32F1) || defined(STM32F4)

#include <drv/peripheral.h>
#include <drv/I2c.h>
#include <drv/i2c/register_i2c_stm32f1_f4.h>

#include <yss/thread.h>
#include <util/time.h>

#define TRANSMIT	false
#define RECEIVE		true

I2c::I2c(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mDataCount = 0;
	mDataBuf = 0;
	mDir = TRANSMIT;
}

bool I2c::init(unsigned char speed)
{
	unsigned long clk = getClockFrequency(), mod;

	setI2cSoftReset(mPeri, true);
	setI2cSoftReset(mPeri, false);

	setI2cFreq(mPeri, clk / 1000000);

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
		return false;
	}

	getI2cSr1(mPeri);
	setI2cSpeed(mPeri, speed);
	setI2cFastModeDuty(mPeri, define::i2c::duty::DUTY_1_2);

	setI2cClockControl(mPeri, clk);
	setI2cEn(mPeri, true);

	return true;
}

bool I2c::send(unsigned char addr, void *src, unsigned int size, unsigned int timeout)
{
	unsigned char *data = (unsigned char *)src;
	unsigned long long endingTime = time::getRunningMsec() + timeout;

	setBitData(mPeri->CR1, true, 8);		// start
	mDir = TRANSMIT;
	mAddr = addr;
	mDataCount = size;
	mDataBuf = (unsigned char*)src;
	mPeri->CR2 |= I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk;

	while (mDataCount || getBitData(mPeri->SR1, 2) == false) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= time::getRunningMsec())
		{
			mPeri->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			return false;
		}
		thread::yield();
	}

	return true;
}

bool I2c::receive(unsigned char addr, void *des, unsigned int size, unsigned int timeout)
{
	unsigned long long endingTime = time::getRunningMsec() + timeout;
	unsigned char *data = (unsigned char *)des;
	volatile unsigned short sr;

	mPeri->SR1;
	mPeri->SR2;
	setBitData(mPeri->CR1, true, 8);		// start
	mDir = RECEIVE;
	mAddr = addr;
	mDataCount = size;
	mDataBuf = (unsigned char*)des;
	mPeri->CR2 |= I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk;

	while (mDataCount) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= time::getRunningMsec())
		{
			mPeri->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			stop();
			return false;
		}
		thread::yield();
	}

	return true;
}

void I2c::stop(void)
{
	if (getI2cBusy(mPeri) == true)
	{
		setI2cStop(mPeri);
		setI2cLast(mPeri, false);
		setI2cAck(mPeri, false);
	}
}

void I2c::isr(void)
{
	unsigned int sr1 = mPeri->SR1;

	if(mDir == TRANSMIT)
	{
		if(sr1 & I2C_SR1_SB_Msk)
		{
			mPeri->SR2;
			mPeri->DR = mAddr & 0xFE;	// ADDR 전송
		}
		else if(sr1 & I2C_SR1_ADDR_Msk)
		{
			mPeri->SR2;
		}
		else if(sr1 & I2C_SR1_TXE_Msk)
		{
			mPeri->DR = *mDataBuf++;
			mDataCount--;
			if(mDataCount == 0)
			{
				mPeri->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			}
		}
		else
		{
			mPeri->SR2;
		}
	}
	else
	{
		if(sr1 & I2C_SR1_SB_Msk)
		{
			mPeri->SR2;
			mPeri->DR = mAddr | 0x01;	// ADDR 전송
		}
		else if(sr1 & I2C_SR1_ADDR_Msk)
		{
			mPeri->SR2;
			switch (mDataCount)
			{
			case 0:
			case 1:
				setBitData(mPeri->CR1, false, 10);	// ACK 비활성
				setI2cStop(mPeri);
				break;
			default:
				setBitData(mPeri->CR1, true, 10);	// ACK 활성
				break;
			}
		}
		else if(sr1 & I2C_SR1_RXNE_Msk)
		{
			switch (mDataCount)
			{
			case 2:
				setBitData(mPeri->CR1, false, 10);	// ACK 비활성
				setI2cStop(mPeri);
				break;
			}

			mDataCount--;
			*mDataBuf++ = mPeri->DR;

			if(mDataCount == 0)
			{
				mPeri->CR2 &= ~(I2C_CR2_ITBUFEN_Msk | I2C_CR2_ITEVTEN_Msk);
			}
		}
	}
}

#endif

