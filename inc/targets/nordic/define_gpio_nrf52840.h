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

#ifndef YSS_DRV_GPIO_DEFINE_NRF52840__H_
#define YSS_DRV_GPIO_DEFINE_NRF52840__H_

namespace define
{
namespace gpio
{
namespace altfunc
{
enum
{
	UART0_RTS = 0,
	UART0_TXD,
	UART0_CTS,
	UART0_RXD,
};
}

namespace ospeed
{
enum
{
	LOW = 0,
	MID = 1,
	FAST = 2,
	HIGH = 3,
};
}

namespace otype
{
enum
{
	PUSH_PULL = 0,
	OPEN_DRAIN = 1,
};
}

namespace mode
{
enum
{
	INPUT = 0,
	OUTPUT = 1,
	ALT_FUNC = 2,
	ANALOG = 3
};
}

namespace pupd
{
enum
{
	NONE = 0,
	PULL_UP = 3,
	PULL_DOWN = 1
};
}

namespace exti
{
enum
{
	PORTA = 0,
	PORTB = 1,
	PORTC = 2,
	PORTD = 3,
	PORTE = 4,
	PORTF = 5,
	PORTG = 6,
	PORTH = 7,
	PORTI = 8,
	PORTJ = 9,
	PORTK = 10
};
}

}
}

#endif