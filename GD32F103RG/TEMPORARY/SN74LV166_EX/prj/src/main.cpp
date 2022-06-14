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
#include <string.h>
#include <yss/yss.h>
#include <mod/logic/SN74LV166A.h>

SN74LV166A sn74lv166;

int main(void)
{
	yss::init();

	using namespace define::gpio;
	
	// SPI1 초기화
	gpioB.setAsAltFunc(3, altfunc::PB3_SPI1_SCK);
	gpioB.setAsAltFunc(4, altfunc::PB4_SPI1_MISO);
	gpioB.setAsAltFunc(5, altfunc::PB5_SPI1_MOSI);

	spi1.setClockEn(true);
	spi1.init();
	spi1.setInterruptEn(true);

	// SN74LV166A 초기화
	gpioB.setAsOutput(0);

	SN74LV166A::Config sn74lv166Config =
	{
		spi1,		//drv::Spi &spi;
		1,			//unsigned char depth;
		{0, 0},		//config::gpio::Set CLK_INH;
		{&gpioB, 0},	//config::gpio::Set SH_LD;
		{0, 0}		//config::gpio::Set CLR;
	};

	sn74lv166.init(sn74lv166Config);

	while (1)
	{
		sn74lv166.refresh();	// 값을 SN74LV166에서 SPI를 통해 읽어옴
		sn74lv166.get(0);		// SPI를 통해 읽어온 값을 얻어오기
	}
	return 0;
}
