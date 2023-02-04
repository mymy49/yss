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

#ifndef YSS_DRV_DMA_ST_TYPE_B_DEFINE__H_
#define YSS_DRV_DMA_ST_TYPE_B_DEFINE__H_

#include <drv/mcu.h>

namespace define
{

namespace dma
{
namespace priorityLevel
{
enum
{
	LOW = 0,
	MEDIUM = 1,
	HIGH = 2,
	VERY_HIGH = 3
};
}

namespace dir
{
enum
{
	PERI_TO_MEM = 0,
	MEM_TO_PERI = 1,
	MEM_TO_MEM = 2
};
}

namespace addr
{
enum
{
	FIXED = 0,
	ADDR_INC = 1
};
}

namespace burst
{
enum
{
	SINGLE = 0,
	INCR4 = 1,
	INCR8 = 2,
	INCR16 = 3
};
}

namespace size
{
enum
{
	BYTE = 0,
	HALF_WORD = 1,
	WORD = 2
};
}
}
}

#if defined(STM32L0)

namespace define
{
namespace dma1
{
namespace stream1
{
enum
{
	ADC_CH1 = 0,
	TIM2_CH3 = 8,
	AES_IN = 11,
};
}

namespace stream2
{
enum
{
	ADC_CH1 = 0,
	SPI1_RX = 1,
	USART1_TX = 3,
	LPUART1_TX = 5,
	I2C1_TX = 6,
	TIM2_UP = 8,
	TIM6_UP = 9,
	DAC_CH1 = 9,
	TIM3_CH3 = 10,
	AES_OUT = 11,
	USART4_RX = 12,
	USART5_RX = 13,
	I2C3_TX = 14
};
}

namespace stream3
{
enum
{
	SPI1_TX = 1,
	USART1_RX = 3,
	LPUART1_RX = 5,
	I2C1_RX = 6,
	TIM2_CH2 = 8,
	TIM3_CH4 = 10,
	TIM3_UP = 10,
	AES_OUT = 11,
	USART4_TX = 12,
	USART5_TX = 13,
	I2C3_RX = 14
};
}

namespace stream4
{
enum
{
	SPI2_RX = 2,
	USART1_TX = 3,
	USART2_TX = 4,
	I2C2_TX = 7,
	TIM2_CH4 = 8,
	I2C3_TX = 14,
	TIM7_UP = 15,
	DAC_CH2 = 15
};
}

namespace stream5
{
enum
{
	SPI2_TX = 2,
	USART1_RX = 3,
	USART2_RX = 4,
	I2C2_RX = 7,
	TIM2_CH1 = 8,
	TIM3_CH1 = 10,
	AES_IN = 11,
	I2C3_RX = 14
};
}

namespace stream6
{
enum
{
	SPI2_RX = 2,
	USART2_RX = 4,
	LPUART1_RX = 5,
	I2C1_TX = 6,
	TIM3_TRIG = 10,
	USART4_RX = 12,
	USART5_RX = 13
};
}

namespace stream7
{
enum
{
	SPI2_TX = 2,
	USART2_TX = 4,
	LPUART1_TX = 5,
	I2C1_RX = 6,
	TIM2_CH2 = 8,
	TIM2_CH4 = 8,
	USART4_TX = 12,
	USART5_TX = 13
};
}
}
}
#endif

#endif