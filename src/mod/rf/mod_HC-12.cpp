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

#include <mod/rf/HC-12.h>
#include <util/ElapsedTime.h>
#include <yss/thread.h>

#if !defined(YSS_DRV_UART_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

namespace mod
{
namespace rf
{
HC_12::HC_12(void)
{
	mPeri = 0;
}

bool HC_12::initialize(Config config)
{
	mPeri = &config.peri;
	mSet = config.set;
	mSet.port->setOutput(mSet.pin, true);

	return true;
}

bool HC_12::send(void *src, uint32_t size)
{
	return mPeri->send(src, size);
}

int8_t HC_12::getWaitUntilReceive(void)
{
	return mPeri->getWaitUntilReceive();
}

int16_t HC_12::get(void)
{
	return mPeri->get();
}

bool HC_12::checkOk(int8_t *src, uint8_t len)
{
	ElapsedTime timeout;
	int16_t data;
	uint8_t index = 0;

	while (1)
	{
		data = mPeri->get();
		if (data >= 0)
		{
			if (src[index] == (int8_t)data)
				index++;
			else
			{
				mSet.port->setOutput(mSet.pin, true);
				return false;
			}

			if (index == len)
			{
				mSet.port->setOutput(mSet.pin, true);
				return true;
			}
		}

		if (timeout.getMsec() >= 500)
		{
			mSet.port->setOutput(mSet.pin, true);
			return false;
		}
	}
}

bool HC_12::setBaudrate(uint8_t baud)
{
	int8_t str[16] = {
		'A',
		'T',
		'+',
		'B',
	};
	uint8_t index = 4;

	mSet.port->setOutput(mSet.pin, false);
	thread::delay(100);
	mPeri->flush();

	switch (baud)
	{
	case BAUD_1200:
		str[index++] = '1';
		str[index++] = '2';
		break;
	case BAUD_2400:
		str[index++] = '2';
		str[index++] = '4';
		break;
	case BAUD_4800:
		str[index++] = '4';
		str[index++] = '8';
		break;
	case BAUD_9600:
		str[index++] = '9';
		str[index++] = '6';
		break;
	case BAUD_19200:
		str[index++] = '1';
		str[index++] = '9';
		str[index++] = '2';
		break;
	case BAUD_38400:
		str[index++] = '3';
		str[index++] = '8';
		str[index++] = '4';
		break;
	case BAUD_57600:
		str[index++] = '5';
		str[index++] = '7';
		str[index++] = '6';
		break;
	case BAUD_115200:
		str[index++] = '1';
		str[index++] = '1';
		str[index++] = '5';
		str[index++] = '2';
		break;
	}

	str[index++] = '0';
	str[index++] = '0';
	str[index++] = 0x0D;
	str[index++] = 0x0A;

	mPeri->send(str, index);

	str[0] = 'O';
	str[1] = 'K';

	return checkOk(str, index);
}

bool HC_12::setChannel(uint8_t channel)
{
	if (channel < 1 || channel > 127)
		return false;

	int8_t str[16] = {
		'A',
		'T',
		'+',
		'C',
	};
	uint8_t index = 4, buf;

	mSet.port->setOutput(mSet.pin, false);
	thread::delay(100);
	mPeri->flush();

	buf = channel / 100;
	str[index++] = '0' + buf;

	buf = channel % 100 / 10;
	str[index++] = '0' + buf;

	buf = channel % 10;
	str[index++] = '0' + buf;

	str[index++] = 0x0D;
	str[index++] = 0x0A;

	mPeri->send(str, index);

	str[0] = 'O';
	str[1] = 'K';

	return checkOk(str, index);
}

bool HC_12::setFU(uint8_t fu)
{
	if (fu < 1 || fu > 4)
		return false;

	int8_t str[16] = {
		'A',
		'T',
		'+',
		'F',
		'U',
	};
	uint8_t index = 5;

	mSet.port->setOutput(mSet.pin, false);
	thread::delay(100);
	mPeri->flush();

	str[index++] = '0' + fu;

	str[index++] = 0x0D;
	str[index++] = 0x0A;

	mPeri->send(str, index);

	str[0] = 'O';
	str[1] = 'K';

	return checkOk(str, index);
}

bool HC_12::setTransmittingPower(uint8_t power)
{
	if (power < 1 || power > 8)
		return false;

	int8_t str[16] = {
		'A',
		'T',
		'+',
		'P',
	};
	uint8_t index = 4;

	mSet.port->setOutput(mSet.pin, false);
	thread::delay(100);
	mPeri->flush();

	str[index++] = '0' + power;

	str[index++] = 0x0D;
	str[index++] = 0x0A;

	mPeri->send(str, index);

	str[0] = 'O';
	str[1] = 'K';

	return checkOk(str, index);
}
}
}

#endif

