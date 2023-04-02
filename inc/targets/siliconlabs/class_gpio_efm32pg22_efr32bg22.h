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

#ifndef YSS_CLASS_GPIO_EFM32PG22__H_
#define YSS_CLASS_GPIO_EFM32PG22__H_

#include <yss/error.h>
#include "define_efm32pg22_efr32bg22.h"

class Gpio : public GpioBase
{
public:
	enum PORT
	{
		PORTA = 0,
		PORTB,
		PORTC,
		PORTD
	};

	struct Setup
	{
		YSS_GPIO_Peri *dev;
		uint8_t port;
		uint8_t pinCount;
	};
	
	// 핀을 출력으로 설정한다.
	// 
	// 반환
	//		에러를 반환한다.
	// uint8_t pin
	//		출력으로 변경할 핀의 번호를 설정한다.
	// uint8_t otype
	//		출력핀의 출력 타입을 설정한다. enum OTYPE을 사용한다.
	error setAsOutput(uint8_t pin, uint8_t otype = define::gpio::otype::PUSHPULL);

	error setAsAltFunc(uint8_t pin, uint8_t altFunc, uint8_t alttype = define::gpio::alttype::PUSHPULL);

	void setAsInput(uint8_t pin);

	void setOutput(uint8_t pin, bool data);
	
	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	Gpio(const Drv::Setup drvSetup, const Setup setup);

private:
	YSS_GPIO_Peri *mDev;
	uint8_t mPort, mPinCount;
};

#endif