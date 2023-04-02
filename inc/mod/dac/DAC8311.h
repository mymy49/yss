////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MOD_DAC_DAC7574__H_
#define YSS_MOD_DAC_DAC7574__H_

#include <sac/SerialMemory.h>
#include <yss/instance.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

namespace mod
{
namespace dac
{
class DAC8311
{
  public:
	struct Config
	{
		Spi &peri;
		Gpio::Pin chipSelect;
	};

	enum
	{
		PD_NORMAL = 0x0000,
		PD_1KOHM_PULL_DOWN = 0x4000,
		PD_100KOHM_PULL_DOWN = 0x8000,
		PD_HIGH_Z = 0xC000
	};

	DAC8311(void);
	bool initialize(const Config config);
	bool setValue(uint16_t value);
	void setPowerDown(uint16_t mode);

  private:
	Spi *mPeri;
	Gpio::Pin mCs;
	uint16_t mPowerDown;
	uint16_t mValue;

	bool send(void);
};
}
}

#endif

#endif
