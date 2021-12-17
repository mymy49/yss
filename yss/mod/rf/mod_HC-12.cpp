#include <__cross_studio_io.h>
#include <mod/rf/HC-12.h>
#include <util/ElapsedTime.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

namespace mod
{
namespace rf
{
HC_12::HC_12(void)
{
	mPeri = 0;
}

bool HC_12::init(Config config)
{
	mPeri = &config.peri;
	mSet = config.set;
	mSet.port->setOutput(mSet.pin, true);

	return true;
}

bool HC_12::send(void *src, unsigned int size)
{
	return mPeri->send(src, size);
}

char HC_12::getWaitUntilReceive(void)
{
	return mPeri->getWaitUntilReceive();
}

signed short HC_12::get(void)
{
	return mPeri->get();
}

bool HC_12::checkOk(char *src, unsigned char len)
{
	ElapsedTime timeout;
	signed short data;
	unsigned char index = 0;

	while (1)
	{
		data = mPeri->get();
		if (data >= 0)
		{
			if (src[index] == (char)data)
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

bool HC_12::setBaudrate(unsigned char baud)
{
	char str[16] = {
		'A',
		'T',
		'+',
		'B',
	};
	unsigned char index = 4;

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

bool HC_12::setChannel(unsigned char channel)
{
	if (channel < 1 || channel > 127)
		return false;

	char str[16] = {
		'A',
		'T',
		'+',
		'C',
	};
	unsigned char index = 4, buf;

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

bool HC_12::setFU(unsigned char fu)
{
	if (fu < 1 || fu > 4)
		return false;

	char str[16] = {
		'A',
		'T',
		'+',
		'F',
		'U',
	};
	unsigned char index = 5, buf;

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

bool HC_12::setTransmittingPower(unsigned char power)
{
	if (power < 1 || power > 8)
		return false;

	char str[16] = {
		'A',
		'T',
		'+',
		'P',
	};
	unsigned char index = 4, buf;

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

