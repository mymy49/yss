////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DEFINE_STM32F030XX__H_
#define YSS_DEFINE_STM32F030XX__H_

namespace define
{
	namespace gpio
	{
		namespace analog
		{
			enum
			{
				PA0_ADC_IN0 = 0,
				PA1_ADC_IN1 = 1,
				PA2_ADC_IN2 = 2,
				PA3_ADC_IN3 = 3,
				PA4_ADC_IN4 = 4,
				PA5_ADC_IN5 = 5,
				PA6_ADC_IN6 = 6,
				PA7_ADC_IN7 = 7,
				PB0_ADC_IN8 = 8,
				PB1_ADC_IN9 = 9,
				PC0_ADC_IN10 = 10,
				PC1_ADC_IN11 = 11,
				PC2_ADC_IN12 = 12,
				PC3_ADC_IN13 = 13,
			};
		}

		namespace altfunc
		{
			enum
			{
				PA0_USART1_CTS = 1,
				PA0_USART2_CTS = 1,
				PA0_USART4_TX = 4,

				PA1_EVENTOUT = 0,
				PA1_USART1_RTS = 1,
				PA1_USART2_RTS = 1,
				PA1_USART4_RX = 4,
				PA1_TIM15_CH1N = 5,

				PA2_TIM15_CH1 = 0,
				PA2_USART1_TX = 1,
				PA2_USART2_TX = 1,

				PA3_TIM15_CH2 = 0,
				PA3_USART1_RX = 1,
				PA3_USART2_RX = 1,

				PB6_USART1_TX = 0,
				PB6_I2C1_SCL = 1,
				PB6_TIM16_CH1N = 2,

				PB7_USART1_RX = 0,
				PB7_I2C1_SDA = 1,
				PB7_TIM17_CH1N = 2,
				PB7_USART4_CTS = 4,

				PB10_I2C1_SCL = 1,
				PB10_I2C2_SCL = 1,
				PB10_USART3_TX = 4,
				PB10_SPI2_SCK = 5,

				PB11_EVENTOUT = 0,
				PB11_I2C1_SDA = 1,
				PB11_I2C2_SDA = 1,
				PB11_USART3_RX = 4,

				PB12_SPI1_NSS = 0,
				PB12_SPI2_NSS = 0,
				PB12_EVENTOUT = 1,
				PB12_TIM1_BKIN = 2,
				PB12_USART3_RTS = 4,
				PB12_TIM15 = 5,

				PB13_SPI1_SCK = 0,
				PB13_SPI2_SCK = 0,
				PB13_TIM1_CH1N = 2,
				PB13_USART3_CTS = 4,
				PB13_I2C2_SCL = 5,

				PB14_SPI1_MISO = 0,
				PB14_SPI2_MISO = 0,
				PB14_TIM15_CH1 = 1,
				PB14_TIM1_CH2N = 2,
				PB14_USART3_RTS = 4,
				PB14_I2C2_SDA = 5,

				PB15_SPI1_MOSI = 0,
				PB15_SPI2_MOSI = 0,
				PB15_TIM15_CH2 = 1,
				PB15_TIM1_CH3N = 2,
				PB15_TIM15_CH1N = 3,
			};
		}

		namespace ospeed
		{
			enum
			{
				LOW = 0,
				MID,
				FAST,
				HIGH,
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
				OUTPUT,
				ALT_FUNC,
				ANALOG
			};
		}

		namespace pupd
		{
			enum
			{
				NONE = 0,
				PULL_UP,
				PULL_DOWN
			};
		}
	}
}

// 사용 가능한 DMA 채널 정의
#define DMA_CH1			0
#define DMA_CH2			1
#define DMA_CH3			2
#define DMA_CH4			3
#define DMA_CH5			4

#endif


