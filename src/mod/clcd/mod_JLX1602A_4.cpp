/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/clcd/JLX1602A_4.h>
#include <string.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

#define ADDR 0x78
#define LINE_SIZE 2
#define COLUMN_SIZE 16

namespace mod
{
namespace clcd
{
static char gLine1[19] = {0x80, 0x80, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
static char gLine2[19] = {0x80, 0xc0, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};

JLX1602A_4::JLX1602A_4(void)
{
	mDetectedFlag = false;
}

bool JLX1602A_4::init(I2c &peri, pin_t backLight)
{
	int8_t buf[5] = {0x00, 0x38, 0x0c, 0x01, 0x06};
	bool rt = true;

	mPeri = &peri;
	mBL.port = backLight.port;
	mBL.pin = backLight.pin;

	mPeri->lock();
	mDetectedFlag = mPeri->send(ADDR, buf, 5, 300);
	mPeri->stop();
	mPeri->unlock();

	return rt;
}

void JLX1602A_4::setBlackLight(bool en)
{
	mBL.port->setOutput(mBL.pin, en);
}

bool JLX1602A_4::isConnected(void)
{
	return mDetectedFlag;
}

bool JLX1602A_4::refresh(void)
{
	bool rt1, rt2;

	if (mDetectedFlag == false)
		return false;

	mPeri->lock();
	rt1 = mPeri->send(0x78, gLine1, 19, 300);
	mPeri->stop();
	mPeri->unlock();
	thread::delay(10);
	mPeri->lock();
	rt2 = mPeri->send(0x78, gLine2, 19, 300);
	mPeri->stop();
	mPeri->unlock();
	thread::delay(10);

	if (rt1 == false || rt2 == false)
		return false;
	else
		return true;
}

void JLX1602A_4::write(uint8_t line, uint8_t column, void *src)
{
	char *cSrc = (char *)src, *des;
	uint8_t len = strlen(cSrc);

	if (mDetectedFlag == false)
		return;

	if (line >= LINE_SIZE)
		return;

	if (column + len > COLUMN_SIZE)
		len = COLUMN_SIZE - column;

	if (line == 0)
	{
		des = &gLine1[3 + column];
	}
	else
	{
		des = &gLine2[3 + column];
	}

	for (uint8_t i = 0; i < len; i++)
	{
		*des++ = *cSrc++;
	}
}
}
}

#endif
