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

#include <__cross_studio_io.h>
#include <config.h>
#include <string.h>
#include <yss/yss.h>
#include <mod/codec/WM8994.h>

WM8994 wm8994;

int main(void)
{
	yss::init();
	
	using namespace define::gpio;

	// I2C3 초기화
	gpioH.setAsAltFunc(7, altfunc::PH7_I2C3_SCL, ospeed::LOW, otype::OPEN_DRAIN);
	gpioH.setAsAltFunc(8, altfunc::PH8_I2C3_SDA, ospeed::LOW, otype::OPEN_DRAIN);

	i2c3.setClockEn(true);
	i2c3.init(define::i2c::speed::STANDARD);
	i2c3.setInterruptEn(true);
	
	// WM8994 초기화
	gpioD.setAsInput(6);	// Audio_INT
	gpioG.setAsAltFunc(10, altfunc::PG10_SAI2_SD_B, ospeed::MID);
	gpioI.setAsAltFunc(4, altfunc::PI4_SAI2_MCK_A, ospeed::MID);
	gpioI.setAsAltFunc(5, altfunc::PI5_SAI2_SCK_A, ospeed::MID);
	gpioI.setAsAltFunc(6, altfunc::PI6_SAI2_SD_A, ospeed::MID);
	gpioI.setAsAltFunc(7, altfunc::PI7_SAI2_FS_A, ospeed::MID);


	WM8994::Config wm8994Config =
	{
		i2c3,				// drv::I2c &peri;
		{0, 0},				// const config::gpio::Set *CMFMOD;
		WM8994::ADDR_LOW	// unsigned char addr;
	};

	wm8994.init(wm8994Config);

	//sai2.setClockEn(true);
	//sai2.initBlockA();
	//sai2.setInterruptEn(true);

	while(1)
	{
		thread::yield();
	}
	return 0;
}