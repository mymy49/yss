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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/interface/PCA9555A.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED)

#define ADDR 0x40

PCA9555A::PCA9555A(void)
{
	mDev = 0;
	mInitFlag = false;
	mAddr = ADDR;
}

error_t PCA9555A::initialize(const config_t config)
{
	error_t result;
	char data = 0;

	mDev = &config.dev;
	mAddr |= config.addr & 0x0E;

	mDev->lock();
	result = mDev->send(mAddr, &data, 1);
	mDev->stop();
	mDev->unlock();

	if(result == error_t::ERROR_NONE)
		mInitFlag = true;

	return result;
}

uint8_t PCA9555A::read(uint8_t port)
{
	if(mInitFlag == false)
		return 0;

	error_t result;

	port &= 0x03;
	
	mDev->lock();
	result = mDev->send(mAddr, &port, 1);
	if(result == error_t::ERROR_NONE)
	{
		result = mDev->receive(mAddr, &port, 1);
	}
	mDev->stop();
	mDev->unlock();
	
	if(result == error_t::ERROR_NONE)
		return port;
	else
		return 0;
}

void PCA9555A::config(uint8_t port, uint8_t config)
{
	uint8_t data[2] = {port, config};

	if(mInitFlag == false)
		return;

	data[0] &= 0x03;
	data[0] += 6;

	mDev->lock();
	mDev->send(mAddr, &data, 2);
	mDev->stop();
	mDev->unlock();
}

void PCA9555A::write(uint8_t port, uint8_t data)
{
	uint8_t buf[2] = {port, data};

	if(mInitFlag == false)
		return;

	buf[0] &= 0x03;
	buf[0] += 2;

	mDev->lock();
	mDev->send(mAddr, &buf, 2);
	mDev->stop();
	mDev->unlock();
}

void PCA9555A::polarity(uint8_t port, uint8_t polarity)
{
	uint8_t data[2] = {port, polarity};

	if(mInitFlag == false)
		return;

	data[0] &= 0x03;
	data[0] += 4;

	mDev->lock();
	mDev->send(mAddr, &data, 2);
	mDev->stop();
	mDev->unlock();
}

#endif

