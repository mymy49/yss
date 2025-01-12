/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

// 일시적으로 지원을 중단합니다.

/*
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

int16_t HC_12::getRxByte(void)
{
	return mPeri->getRxByte();
}

bool HC_12::checkOk(int8_t *src, uint8_t len)
{
	ElapsedTime timeout;
	int16_t data;
	uint8_t index = 0;

	while (1)
	{
		data = mPeri->getRxByte();
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

*/
