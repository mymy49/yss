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
#include <mod/eeprom/CAT24C256.h>

CAT24C256 eeprom;

int main(void)
{
	yss::init();

	using namespace define::gpio;
	
	// I2C2 초기화
	gpioB.setAsAltFunc(10, altfunc::PB10_I2C2_SCL, ospeed::MID, otype::OPEN_DRAIN);
	gpioB.setAsAltFunc(11, altfunc::PB11_I2C2_SDA, ospeed::MID, otype::OPEN_DRAIN);

	i2c2.setClockEn(true);
	i2c2.init(define::i2c::speed::STANDARD);
	i2c2.setInterruptEn(true);

	// CAT24C256 초기화
	CAT24C256::Config cat24c256Config =
	{
		i2c2,	//drv::I2c &peri;
		{0, 0},	//config::gpio::Set writeProtectPin;
		0		//unsigned char addr;
	};

	if(eeprom.init(cat24c256Config))
	{
		debug_printf("CAT24C256 Initialization OK!!\n");
	}
	else
	{
		debug_printf("CAT24C256 Initialization Failed!!\n");
	}
	
	unsigned int data = 0x12345678;	
	eeprom.write(0, data);
	data = 0;
	eeprom.read(0, data);

	if(data == 0x12345678)
	{
		debug_printf("CAT24C256 Read/Write Testing OK!!\n");
	}
	else
	{
		debug_printf("CAT24C256 Read/Write Testing Failed!!\n");
	}

	while (1)
	{
		thread::yield();
	}
	return 0;
}
