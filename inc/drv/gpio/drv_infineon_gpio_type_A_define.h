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

#ifndef YSS_DRV_GPIO_ST_TYPE_A_DEFINE__H_
#define YSS_DRV_GPIO_ST_TYPE_A_DEFINE__H_

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

namespace define
{
namespace gpio
{
	namespace altfunc
	{
		enum
		{
			SYS_AF0 = 0,
			TIM1_AF1 = 1,
			TIM2_AF1 = 1,
			TIM3_AF2 = 2,
			TIM4_AF2 = 2,
			TIM5_AF2 = 2,
			TIM8_AF3 = 3,
			TIM9_AF3 = 3,
			TIM10_AF3 = 3,
			TIM11_AF3 = 3,
			I2C1_AF4 = 4,
			I2C2_AF4 = 4,
			I2C3_AF4 = 4,
			I2C4_AF4 = 4,
			SPI_AF5 = 5,
			SPI_AF6 = 6,
			SPI_AF7 = 7,
			USART1_AF7 = 7,
			USART2_AF7 = 7,
			USART3_AF7 = 7,
			UART5_AF7 = 7,
			USART6_AF8 = 8,
			UART4_AF8 = 8,
			UART5_AF8 = 8,
			UART7_AF8 = 8,
			UART8_AF8 = 8,
			CAN1_AF9 = 9,
			CAN2_AF9 = 9,
			TIM12_AF9 = 9,
			TIM13_AF9 = 9,
			TIM14_AF9 = 9,
			LCD_AF9 = 9,
			QUADSPI_AF9 = 9,
			OTG2_HS_AF10 = 10,
			OTG1_FS_AF10 = 10,
			QUADSPI_AF10 = 10,
			ETH_AF11 = 11,
			OTG1_FS_AF11 = 11,
			FMC_AF12 = 12,
			SDRAM_AF12 = 12,
			SDMMC1_AF12 = 12,
			OTG2_FS_AF12 = 12,
			DCMI_AF13 = 13,
			LCD_AF14 = 14,
			SYS_AF15 = 15
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
			PULL_UP = 1,
			PULL_DOWN = 2
		};
	}
}
}

#endif

#endif
