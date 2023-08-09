////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
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
	uint8_t data = 0x00;

	mPeri = &config.peri;

	mInitFlag = true;
	mPeri->lock();
	mInitFlag = mPeri->send(ADDR, &data, 1);
	mPeri->stop();
	mPeri->unlock();

	return mInitFlag;
}

void ADC121C021::setConversionTime(uint8_t cycleTime)
{
	mConfigReg &= ~0xE0;
	mConfigReg |= (cycleTime & 0x07) << 5;

	sendResistor(ADDR_CONFIG, mConfigReg);
}

void ADC121C021::sendResistor(uint8_t addr, uint8_t data)
{
	if (mInitFlag == false)
		return;

	uint8_t sendBuf[2] = {addr, data};

	mPeri->lock();
	mPeri->send(ADDR, sendBuf, 2);
	mPeri->stop();
	mPeri->unlock();
}

void ADC121C021::setAddr(uint8_t addr)
{
	if (mInitFlag == false)
		return;

	mPeri->lock();
	mPeri->send(ADDR, &addr, 2);
	mPeri->stop();
	mPeri->unlock();
}

uint16_t ADC121C021::getResult(void)
{
	if (mInitFlag == false)
		return 0;

	uint8_t data[2] = {
		ADDR_RESULT,
	};

	mPeri->lock();
	mPeri->send(ADDR, data, 1);
	mPeri->receive(ADDR, data, 2);
	mPeri->stop();
	mPeri->unlock();

	return ((uint16_t)data[0] << 8) | (uint16_t)data[1];
}
}
}

#endif

