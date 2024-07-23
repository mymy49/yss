/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

				PB8_I2C1_SCL = 1,
				PB8_TIM16_CH1 = 2,

				PB9_IR_OUT = 0,
				PB9_I2C1_SDA = 1,
				PB9_TIM17_CH1 = 2,
				PB9_EVENTOUT = 3,
				PB9_SPI2_NSS = 5,

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


