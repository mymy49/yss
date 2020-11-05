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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/peripherals.h>
#include <drv/i2c/drv_st_i2c_type_A_register.h>

#if	defined(I2C1_ENABLE) && defined(I2C1)
static void setI2c1ClockEn(bool en)
{
	clock.peripheral.setI2c1En(en);
} 

drv::I2c i2c1(I2C1, setI2c1ClockEn, 0, YSS_DMA_MAP_I2C1_TX_STREAM, YSS_DMA_MAP_I2C1_RX_STREAM, YSS_DMA_MAP_I2C1_TX_CHANNEL, YSS_DMA_MAP_I2C1_RX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(I2C2_ENABLE) && defined(I2C2)
static void setI2c2ClockEn(bool en)
{
	clock.peripheral.setI2c2En(en);
} 

drv::I2c i2c2(I2C2, setI2c2ClockEn, 0, YSS_DMA_MAP_I2C2_TX_STREAM, YSS_DMA_MAP_I2C2_RX_STREAM, YSS_DMA_MAP_I2C2_TX_CHANNEL, YSS_DMA_MAP_I2C2_RX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(I2C3_ENABLE) && defined(I2C3)
static void setI2c3ClockEn(bool en)
{
	clock.peripheral.setI2c3En(en);
} 

drv::I2c i2c3(I2C3, setI2c3ClockEn, 0, YSS_DMA_MAP_I2C3_TX_STREAM, YSS_DMA_MAP_I2C3_RX_STREAM, YSS_DMA_MAP_I2C3_TX_CHANNEL, YSS_DMA_MAP_I2C3_RX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(I2C4_ENABLE) && defined(I2C4)
static void setI2c4ClockEn(bool en)
{
	clock.peripheral.setI2c4En(en);
} 

drv::I2c i2c4(I2C4, setI2c4ClockEn, 0, YSS_DMA_MAP_I2C4_TX_STREAM, YSS_DMA_MAP_I2C4_RX_STREAM, YSS_DMA_MAP_I2C4_TX_CHANNEL, YSS_DMA_MAP_I2C4_RX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

namespace drv
{
	I2c::I2c(I2C_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChannel, unsigned short priority) :  Drv(clockFunc, nvicFunc)
	{
		this->set(txChannel, rxChannel, (void*)&(peri->TXDR), (void*)&(peri->RXDR), priority);

		mTxStream = txStream;
		mRxStream = rxStream;
		mPeri = peri;
	}

	bool I2c::init(unsigned char speed)
	{
		switch(speed)
		{
		case define::i2c::speed::STANDARD :
			setI2cPresc(mPeri, 3);
			setI2cScll(mPeri, 0xc7);
			setI2cSclh(mPeri, 0xc3);
			setI2cSdaDel(mPeri, 0x02);
			setI2cSclDel(mPeri, 0x04);
			break;
		case define::i2c::speed::FAST :
			setI2cPresc(mPeri, 1);
			setI2cScll(mPeri, 0x09);
			setI2cSclh(mPeri, 0x03);
			setI2cSdaDel(mPeri, 0x02);
			setI2cSclDel(mPeri, 0x03);
			break;
		case define::i2c::speed::FAST_PLUS :
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

	inline void waitUntilComplete(I2C_TypeDef* peri)
	{
		while((peri->ISR & I2C_ISR_TC) == false)
			thread::switchContext();
	}

#define setNbytes(data, x)		setRegField(data, 0xFFUL, x, 16)
#define setSaddr(data, x)		setRegField(data, 0x3FFUL, x, 0)

	bool I2c::send(unsigned char addr, void *src, unsigned long size, unsigned long timeout)
	{
		unsigned long cr2 = I2C_CR2_START;
		volatile unsigned long isr;
		bool rt;

		if(mTxStream)
		{
			mPeri->ICR = 0xffff;
			setNbytes(cr2, size);
			setSaddr(cr2, addr);
			mPeri->CR2 = cr2;

			thread::delayUs(2);

			do
			{
				isr = mPeri->ISR;

				if(isr & I2C_ISR_NACKF)
					return false;

				thread::switchContext();
			}while((isr & I2C_ISR_TXIS) == false);

			rt = mTxStream->send(this, src, size, timeout);

			waitUntilComplete(mPeri);

			return rt;
		}
		else
			return false;
	}

	bool I2c::receive(unsigned char addr, void *des, unsigned long size, unsigned long timeout)
	{
		unsigned long cr2 = I2C_CR2_START | I2C_CR2_RD_WRN;
		volatile unsigned long isr;
		bool rt;

		if(mRxStream)
		{
			mPeri->ICR = 0xffff;
			setNbytes(cr2, size);
			setSaddr(cr2, addr);
			mPeri->CR2 = cr2;

			thread::delayUs(2);

			do
			{
				isr = mPeri->ISR;

				if(isr & I2C_ISR_NACKF)
					return false;

				thread::switchContext();
			}while((isr & I2C_ISR_RXNE) == false);

			rt = mRxStream->receive(this, des, size, timeout);
			waitUntilComplete(mPeri);

			return true;
		}
		else
			return false;
	}

	void I2c::stop(void)
	{
		setI2cStop(mPeri);
	}
}

#endif
