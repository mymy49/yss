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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.02.12 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/logic/SN74LV595A.h>
#include <yss/malloc.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

namespace mod
{
namespace logic
{
static config::spi::Config gConfig =
	{
		define::spi::mode::MODE0,
		4500000};

SN74LV595A::SN74LV595A(void)
{
	reset();
}

void SN74LV595A::reset(void)
{
	mOe.port = 0;
	mRclk.port = 0;
	mSrclr.port = 0;
	mPeri = 0;
}

bool SN74LV595A::init(drv::Spi &spi, config::gpio::Set &oe, config::gpio::Set &rclk, config::gpio::Set &srclr)
{
	mPeri = &spi;
	mOe = oe;
	mRclk = rclk;
	mSrclr = srclr;

	if(mOe.port)
		mOe.port->setOutput(mOe.pin, false);

	if(mRclk.port)
		mRclk.port->setOutput(mRclk.pin, false);

	if (mSrclr.port)
	{
		mSrclr.port->setOutput(mSrclr.pin, false);
		mSrclr.port->setOutput(mSrclr.pin, true);
	}

	return true;
}

void SN74LV595A::set(unsigned char data)
{
	mPeri->lock();
	mPeri->setConfig(gConfig);
	mPeri->enable(true);
	mPeri->exchange(data);
	if(mRclk.port)
	{
		mRclk.port->setOutput(mRclk.pin, false);
		mRclk.port->setOutput(mRclk.pin, true);
	}
	mPeri->enable(false);
	mPeri->unlock();
}

void SN74LV595A::set(unsigned char *data, unsigned char size)
{
	mPeri->lock();
	mPeri->setConfig(gConfig);
	mPeri->enable(true);
	mPeri->send((char *)data, size, 300);
	if(mRclk.port)
	{
		mRclk.port->setOutput(mRclk.pin, false);
		mRclk.port->setOutput(mRclk.pin, true);
	}
	mPeri->enable(false);
	mPeri->unlock();
}

void SN74LV595A::setOutputEn(bool en)
{
	if (mRclk.port)
		mRclk.port->setOutput(mRclk.pin, !en);
}
}
}

#endif