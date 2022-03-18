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

#include <mod/adc/ADC121C021.h>

#ifndef YSS_DRV_I2C_UNSUPPORTED

#include <string.h>

#define ADDR 0xA8

#define ADDR_RESULT 0
#define ADDR_STATUS 1
#define ADDR_CONFIG 2
#define ADDR_LOW_LIMIT 3
#define ADDR_HIGH_LIMIT 4
#define ADDR_HYSTERESIS 5
#define ADDR_LOW_CONVERSION 6
#define ADDR_HIGH_CONVERSION 7

namespace mod
{
namespace adc
{
ADC121C021::ADC121C021(void)
{
	mInitFlag = false;
	mPeri = 0;
	mConfigReg = 0;
}

bool ADC121C021::init(const Config config)
{
	unsigned char data = 0x00;

	mPeri = &config.peri;

	mInitFlag = true;
	mPeri->lock();
	mInitFlag = mPeri->send(ADDR, &data, 1);
	mPeri->stop();
	mPeri->unlock();

	return mInitFlag;
}

void ADC121C021::setConversionTime(unsigned char cycleTime)
{
	mConfigReg &= ~0xE0;
	mConfigReg |= (cycleTime & 0x07) << 5;

	sendResistor(ADDR_CONFIG, mConfigReg);
}

void ADC121C021::sendResistor(unsigned char addr, unsigned char data)
{
	if (mInitFlag == false)
		return;

	unsigned char sendBuf[2] = {addr, data};

	mPeri->lock();
	mPeri->send(ADDR, sendBuf, 2);
	mPeri->stop();
	mPeri->unlock();
}

void ADC121C021::setAddr(unsigned char addr)
{
	if (mInitFlag == false)
		return;

	mPeri->lock();
	mPeri->send(ADDR, &addr, 2);
	mPeri->stop();
	mPeri->unlock();
}

unsigned short ADC121C021::getResult(void)
{
	if (mInitFlag == false)
		return 0;

	unsigned char data[2] = {
		ADDR_RESULT,
	};

	mPeri->lock();
	mPeri->send(ADDR, data, 1);
	mPeri->receive(ADDR, data, 2);
	mPeri->stop();
	mPeri->unlock();

	return ((unsigned short)data[0] << 8) | (unsigned short)data[1];
}
}
}

#endif

