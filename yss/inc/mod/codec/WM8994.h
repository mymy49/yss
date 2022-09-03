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

#ifndef YSS_MOD_CODEC_WM8994__H_
#define YSS_MOD_CODEC_WM8994__H_

#include <yss/instance.h>

#ifndef YSS_DRV_I2C_UNSUPPORTED || YSS_DRV_SAI_UNSUPPORTED

class WM8994
{
	I2c *mPeri;
	bool mInitFlag;
	Gpio::Pin mCMFMODpin;
	uint8_t mAddr;

  public:
	enum
	{
		ADDR_LOW = 0x34,
		ADDR_HIGH = 0x36
	};

	struct Config
	{
		I2c &peri;
		Gpio::Pin CMFMOD;
		uint8_t addr;
	};

	WM8994(void);
	bool init(const Config config);
	bool read(uint16_t addr, void *des, uint32_t len);
};

#endif

#endif


/*
1. 사용전 회로 설정 사항
	1.1. CMFMOD 핀은 반드시 Low로 고정되어 있어야 한다. (현재 제어 인터페이스는 I2C만 지원됨)
	1.2. Config의 addr은 ADDR 핀의 실제 설정 상태를 반영하여 enum으로 정의된 ADDR_LOW 또는 ADDR_HIGH를 
			사용하여 설정한다.
*/

