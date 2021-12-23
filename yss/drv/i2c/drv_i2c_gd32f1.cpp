////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(GD32F10X_XD)

#include <drv/peripheral.h>
#include <drv/I2c.h>

#include <yss/thread.h>
#include <util/time.h>
#include <yss/reg.h>
#include <__cross_studio_io.h>

namespace drv
{
I2c::I2c(I2C_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChannel, unsigned int (*getClockFrequencyFunc)(void), unsigned short priority) : Drv(clockFunc, nvicFunc, resetFunc)
{
	this->set(0, 0, (void *)&(peri->DTR), (void *)&(peri->DTR), priority);

	mGetClockFrequency = getClockFrequencyFunc;
	mTxStream = txStream;
	mRxStream = rxStream;
	mPeri = peri;
}

bool I2c::init(unsigned char speed)
{
	unsigned long clk = mGetClockFrequency(), mod;
	
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

#define setNbytes(data, x) setRegField(data, 0xFFUL, x, 16)
#define setSaddr(data, x) setRegField(data, 0x3FFUL, x, 0)
#define checkBusError(sr) (sr & 0x0100)
#define checkStart(sr) (sr & 0x0001)
#define checkAddress(sr) (sr & 0x0002)

inline bool isStartingComplete(I2C_TypeDef *peri, unsigned int timeout)
{
	volatile unsigned int sr1, sr2;

	thread::delayUs(10);
	while (1)
	{
		sr1 = peri->STR1;
		if (timeout <= time::getRunningMsec())
			goto error;
		if (checkBusError(sr1))
			goto error;
		if (checkStart(sr1))
			break;
		thread::yield();
	}

	return true;
error:
	return false;
}

inline bool isAddressComplete(I2C_TypeDef *peri, unsigned int timeout)
{
	volatile unsigned int sr1, sr2;

	thread::delayUs(20);
	while (1)
	{
		sr1 = peri->STR1;
		if (timeout <= time::getRunningMsec())
			goto error;
		if (checkBusError(sr1))
			goto error;
		if (checkAddress(sr1))
			break;
		thread::yield();
	}

	sr1 = peri->STR1;
	sr2 = peri->STR2;
	return true;
error:
	sr1 = peri->STR1;
	sr2 = peri->STR2;
	return false;
}

bool I2c::send(unsigned char addr, void *src, unsigned int size, unsigned int timeout)
{
	unsigned char *data = (unsigned char *)src;
	unsigned long long endingTime = time::getRunningMsec() + timeout;

	setBitData(mPeri->CTLR1, true, 8);		// start
	if (isStartingComplete(mPeri, endingTime) == false)
	{
//		debug_printf("sTP1\n");
		return false;
	}
	
	mPeri->STR1;
	mPeri->STR2;
	mPeri->DTR = addr & 0xFE;	// ADDR 전송

	if (isAddressComplete(mPeri, endingTime) == false)
	{
//		debug_printf("sTP1\n");
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		while (getBitData(mPeri->STR1, 7) == false)	// 전송중 송신 버퍼 비워짐 플래그 점검
		{
			if (endingTime <= time::getRunningMsec())
			{
//				debug_printf("sTP2\n");
				return false;
			}

			thread::yield();
		}

		mPeri->DTR = data[i];
	}

	while (getBitData(mPeri->STR1, 2) == false) // Byte 전송 완료 비트 확인
	{
		if (endingTime <= time::getRunningMsec())
		{
//			debug_printf("sTP3\n");
			return false;
		}
		
		thread::yield();
	}

//	debug_printf("sTP_ok\n");
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
		size = 0;
		break;
	default:
		setBitData(mPeri->CTLR1, true, 10);	// ACK 활성
		break;
	}

	mPeri->STR1;
	mPeri->STR2;
	setBitData(mPeri->CTLR1, true, 8);		// start
	if (isStartingComplete(mPeri, endingTime) == false)
	{
//		debug_printf("rTP1\n");
		goto error;
	}

	mPeri->DTR = addr | 0x01;	// ADDR 전송

	if (isAddressComplete(mPeri, endingTime) == false)
	{
//		debug_printf("rTP2\n");
		goto error;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		thread::yield();
		
		do
		{
			thread::yield();

			sr = ~mPeri->STR1;
			if (endingTime <= time::getRunningMsec())
			{
//				debug_printf("rTP3\n");
				goto error;
			}

		}while (sr & (I2C_STR1_RBNE | I2C_STR1_BTC));
	
		if (size - 2 == i)
			setBitData(mPeri->CTLR1, false, 10);	// ACK 비활성
		data[i] = mPeri->DTR;
//		debug_printf("rcv\n");
	}

	if (size == 0)
	{
		stop();
		while (getBitData(mPeri->STR1, 6) == false)
		{
			if (endingTime <= time::getRunningMsec())
			{
//				debug_printf("rTP4\n");
				goto error;
			}

			thread::yield();
		}
		data[0] = mPeri->DTR;
//		debug_printf("rcv\n");
	}
	else
	{
		stop();
	}

//	debug_printf("rTP_ok (%d)\n", size);
	return true;
error:
	stop();
	return false;
}

void I2c::stop(void)
{
	if (getBitData(mPeri->STR2, 1)) // Busy 확인
	{
		setBitData(mPeri->CTLR1, true, 9);	// Stop
		setBitData(mPeri->CTLR1, false, 10);	// ACK 비활성

		while(getBitData(mPeri->STR2, 1))
			thread::yield();
	}
}
}

#endif