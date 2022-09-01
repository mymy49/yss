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

#include <drv/mcu.h>

#if defined(GD32F1)

#include <drv/peripheral.h>
#include <drv/I2c.h>

#include <yss/thread.h>
#include <util/time.h>
#include <yss/reg.h>

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
	
	// soft reset
	setBitData(mPeri->CTLR1, true, 15);
	setBitData(mPeri->CTLR1, false, 15);

	setFieldData(mPeri->CTLR2, 0x3F << 0, clk / 1000000, 0);

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

	// Status Clear
	mPeri->STR1;
	mPeri->STR2;
	
	setBitData(mPeri->CLKR, speed, 15);				// 통신 속도 설정
	setFieldData(mPeri->CLKR, 0xFFF << 0, clk, 0);	// 분주 설정
	setBitData(mPeri->CTLR1, true, 0);				// I2C 활성화

	return true;
}

bool I2c::send(unsigned char addr, void *src, unsigned int size, unsigned int timeout)
{
	unsigned char *data = (unsigned char *)src;
	unsigned long long endingTime = time::getRunningMsec() + timeout;

	setBitData(mPeri->CTLR1, true, 8);		// start
	mDir = TRANSMIT;
	mAddr = addr;
	mDataCount = size;
	mDataBuf = (unsigned char*)src;
	mPeri->CTLR2 |= I2C_CTLR2_BIE | I2C_CTLR2_EE;

	while (mDataCount || getBitData(mPeri->STR1, 2) == false) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= time::getRunningMsec())
		{
			mPeri->CTLR2 &= ~(I2C_CTLR2_BIE | I2C_CTLR2_EE);
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

	switch (size)
	{
	case 0:
		return true;
	case 1:
		setBitData(mPeri->CTLR1, false, 10);	// ACK 비활성
		break;
	default:
		setBitData(mPeri->CTLR1, true, 10);	// ACK 활성
		break;
	}

	mPeri->STR1;
	mPeri->STR2;
	setBitData(mPeri->CTLR1, true, 8);		// start
	mDir = RECEIVE;
	mAddr = addr;
	mDataCount = size;
	mDataBuf = (unsigned char*)des;
	mPeri->CTLR2 |= I2C_CTLR2_BIE | I2C_CTLR2_EE;

	while (mDataCount) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= time::getRunningMsec())
		{
			mPeri->CTLR2 &= ~(I2C_CTLR2_BIE | I2C_CTLR2_EE);
			return false;
		}
		thread::yield();
	}
	
	stop();

	return true;
error:
	mPeri->CTLR2 &= ~(I2C_CTLR2_BIE | I2C_CTLR2_EE);
	stop();
	return false;
}

void I2c::stop(void)
{
	if (getBitData(mPeri->STR2, 1)) // Busy 확인
	{
		setBitData(mPeri->CTLR1, true, 9);		// Stop
		setBitData(mPeri->CTLR1, false, 10);	// ACK 비활성

		__ISB();
		while(getBitData(mPeri->STR2, 1))
			thread::yield();
	}
}

void I2c::isr(void)
{
	unsigned int sr1 = mPeri->STR1;

	if(mDir == TRANSMIT)
	{
		if(sr1 & I2C_STR1_SBSEND)
		{
			mPeri->STR2;
			mPeri->DTR = mAddr & 0xFE;	// ADDR 전송
		}
		else if(sr1 & I2C_STR1_ADDSEND)
		{
			mPeri->STR2;
		}
		else if(sr1 & I2C_STR1_TBE)
		{
			if(mDataCount == 0)
				mPeri->CTLR2 &= ~(I2C_CTLR2_BIE | I2C_CTLR2_EE);
			else
			{
				mPeri->DTR = *mDataBuf++;
				mDataCount--;
			}
		}
	}
	else
	{
		if(sr1 & I2C_STR1_SBSEND)
		{
			mPeri->STR2;
			mPeri->DTR = mAddr | 0x01;	// ADDR 전송
		}
		else if(sr1 & I2C_STR1_ADDSEND)
		{
			mPeri->STR2;
			switch (mDataCount)
			{
			case 0:
			case 1:
				setBitData(mPeri->CTLR1, false, 10);	// ACK 비활성
				setBitData(mPeri->CTLR1, true, 9);		// Stop
				break;
			default:
				setBitData(mPeri->CTLR1, true, 10);	// ACK 활성
				break;
			}
		}
		else if(sr1 & I2C_STR1_RBNE)
		{
			if(mDataCount == 2)
			{
				setBitData(mPeri->CTLR1, false, 10);	// ACK 비활성
				setBitData(mPeri->CTLR1, true, 9);		// Stop
			}

			mDataCount--;
			*mDataBuf++ = mPeri->DTR;

			if(mDataCount == 0)
			{
				mPeri->CTLR2 &= ~(I2C_CTLR2_BIE | I2C_CTLR2_EE);
			}
		}
	}
}

#endif

