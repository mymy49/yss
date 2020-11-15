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

#ifndef YSS_DRV_GPIO_MICROCHIP_TYPE_A_DEFINE__H_
#define YSS_DRV_GPIO_MICROCHIP_TYPE_A_DEFINE__H_

namespace define
{
namespace gpio
{
	namespace altfunc
	{
		enum
		{
			P0_0_GPIO = 1,
			P0_0_AF1_SWDIO = 0,
			P0_0_AF2_SPI1_MISO = 2,
			P0_0_AF3_UART1_TX = 3,

			P0_1_GPIO = 1,
			P0_1_AF1_SWDCLK = 0,
			P0_1_AF2_SPI1_MOSI = 2,
			P0_1_AF3_UART1_RX = 3,

			P0_2_GPIO = 1,
			P0_2_AF1_I2C_SCL = 0,
			P0_2_AF2_SPI1_SCK = 2,
			P0_2_AF3_32K_CAL = 3,

			P0_3_GPIO = 1,
			P0_3_AF1_I2C_SDA = 0,
			P0_3_AF2_SPI1_SS0 = 2,
			P0_3_AF3_TMR0 = 3,

			P0_4_GPIO = 1,
			P0_4_AF1_SPI0_MISO = 0,
			P0_4_AF2_UART0_TX = 2,

			P0_5_GPIO = 1,
			P0_5_AF1_SPI0_MOSI = 0,
			P0_5_AF2_UART0_RX = 2,

			P0_6_GPIO = 1,
			P0_6_AF1_SPI0_SCK = 0,
			P0_6_AF2_UART0_CTS = 2,
			P0_6_AF3_UART1_TX = 3,

			P0_7_GPIO = 1,
			P0_7_AF1_SPI0_SS0 = 0,
			P0_7_AF2_UART0_RTS = 2,
			P0_7_AF3_UART1_RX = 3,

			P0_8_GPIO = 1,
			P0_8_AF1_I2C0_SCL = 0,
			P0_8_AF2_SWDIO = 2,

			P0_9_GPIO = 1,
			P0_9_AF1_I2C0_SDA = 0,
			P0_9_AF2_SWDCLK = 2,

			P0_10_GPIO = 1,
			P0_10_AF1_SPI1_MISO = 0,
			P0_10_AF2_UART1_TX = 2,

			P0_11_GPIO = 1,
			P0_11_AF1_SPI1_MOSI = 0,
			P0_11_AF2_UART1_RX = 2,

			P0_12_GPIO = 1,
			P0_12_AF1_SPI1_SCK = 0,
			P0_12_AF2_UART1_CTS = 2,

			P0_13_GPIO = 1,
			P0_13_AF1_SPI1_SS0 = 0,
			P0_13_AF2_UART1_RTS = 2,
		};
	}

	namespace ospeed
	{
		enum
		{
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

	namespace pupd
	{
		enum
		{
			NONE = 0,
			PULL_UP = 1,
			PULL_DOWN = 2
		};
	}
}
}

#endif
