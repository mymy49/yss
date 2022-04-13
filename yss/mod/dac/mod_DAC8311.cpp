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

#include <mod/dac/DAC8311.h>
#include <string.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

namespace mod
{
namespace dac
{
static config::spi::Config gConfig =
	{
		define::spi::mode::MODE1, //unsigned char mode;
		20000000,                 //unsigned int maxFreq;
		define::spi::bit::BIT8};  //unsigned char bit;

DAC8311::DAC8311(void)
{
	mPowerDown = PD_1KOHM_PULL_DOWN;
	mValue = 0;
}

bool DAC8311::init(const Config config)
{
	mPeri = &config.peri;
	mCs = config.chipSelect;
	mCs.port->setOutput(mCs.pin, true);

	return send();
}

bool DAC8311::setValue(unsigned short value)
{
	mValue = value & 0x3FFF;

	return send();
}

void DAC8311::setPowerDown(unsigned short mode)
{
	mPowerDown = mode & 0xC000;
}

union Data
{
	unsigned short halfword;
	unsigned char byte[2];
};

bool DAC8311::send(void)
{
	bool rt;
	Data data;
	unsigned char buf;

	data.halfword = mValue | mPowerDown;
	buf = data.byte[0];
	data.byte[0] = data.byte[1];
	data.byte[1] = buf;

	mPeri->lock();
	mPeri->setConfig(gConfig);
	mPeri->enable(true);
	mCs.port->setOutput(mCs.pin, false);
	rt = mPeri->send(&data, 2);
	mCs.port->setOutput(mCs.pin, true);
	mPeri->enable(false);
	mPeri->unlock();

	return rt;
}
}
}

#endif
