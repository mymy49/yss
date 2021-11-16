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

#include <mod/clcd/JLX1602A_4.h>
#include <string.h>

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

bool JLX1602A_4::init(drv::I2c &peri, config::gpio::Set backLight)
{
	char buf[5] = {0x00, 0x38, 0x0c, 0x01, 0x06};
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

void JLX1602A_4::write(unsigned char line, unsigned char column, void *src)
{
	char *cSrc = (char *)src, *des;
	unsigned char len = strlen(cSrc);

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

	for (unsigned char i = 0; i < len; i++)
	{
		*des++ = *cSrc++;
	}
}
}
}