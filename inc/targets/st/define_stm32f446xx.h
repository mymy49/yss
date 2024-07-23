/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEFINE_STM32F446XX__H_
#define YSS_DEFINE_STM32F446XX__H_

namespace define
{
	namespace dma1
	{
		namespace stream0
		{
			enum
			{
				SPI3_RX = 0,
				I2C1_RX = 1,
				TIM4_CH1 = 2,
				I2S3_EXT_RX = 3,
				UART5_RX = 4,
				UART8_TX = 5,
				TIM5_CH3 = 6,
				TIM5_UP = 6
			};
		}

		namespace stream1
		{
			enum
			{
				TIM2_UP = 3,
				TIM2_CH3 = 3,
				UART3_RX = 4,
				UART7_TX = 5,
				TIM5_CH4 = 6,
				TIM5_TRIG = 6,
				TIM6_UP = 7,
				I2C4_RX = 8
			};
		}

		namespace stream2
		{
			enum
			{
				SPI3_RX = 0,
				TIM7_UP = 1,
				I2S3_EXT_RX = 2,
				I2C3_RX = 3,
				UART4_RX = 4,
				TIM3_CH4 = 5,
				TIM3_UP = 5,
				TIM5_CH1 = 6,
				I2C2_RX = 7
			};
		}

		namespace stream3
		{
			enum
			{
				SPI2_RX = 0,
				TIM4_CH2 = 2,
				I2S2_EXT_RX = 3,
				USART3_TX = 4,
				UART7_RX = 5,
				TIM5_CH4 = 6,
				TIM5_TRIG = 6,
				I2C2_RX = 7
			};
		}

		namespace stream4
		{
			enum
			{
				SPI2_TX = 0,
				TIM7_UP = 1,
				I2S2_EXT_TX = 2,
				I2C3_TX = 3,
				UART4_TX = 4,
				TIM3_CH1 = 5,
				TIM3_TRIG = 5,
				TIM5_CH2 = 6,
				USART3_TX = 7
			};
		}

		namespace stream5
		{
			enum
			{
				SPI3_TX = 0,
				I2C1_RX = 1,
				I2S3_EXT_TX = 2,
				TIM2_CH1 = 3,
				USART2_RX = 4,
				TIM3_CH2 = 5,
				DAC_CH1 = 7
			};
		}

		namespace stream6
		{
			enum
			{
				I2C1_TX = 1,
				TIM4_UP = 2,
				TIM2_CH2 = 3,
				TIM2_CH4 = 3,
				USART2_TX = 4,
				UART8_RX = 5,
				TIM5_UP = 6,
				DAC_CH2 = 7,
				I2C4_TX = 8
			};
		}

		namespace stream7
		{
			enum
			{
				SPI3_TX = 0,
				I2C1_TX = 1,
				TIM4_CH3 = 2,
				TIM2_UP = 3,
				TIM2_CH4 = 3,
				UART5_TX = 4,
				TIM3_CH3 = 5,
				I2C2_TX = 7
			};
		}
	}

	namespace dma2
	{
		namespace stream0
		{
			enum
			{
				ADC_CH1 = 0,
				ADC_CH3 = 2,
				SPI1_RX = 3,
				SPI4_RX = 4,
				TIM1_TRIG = 6
			};
		}

		namespace stream1
		{
			enum
			{
				SAI1_A = 0,
				DCMI_DMA = 1,
				ADC_CH3 = 2,
				SPI4_TX = 4,
				USART6_RX = 5,
				TIM1_CH1 = 6,
				TIM8_UP = 7
			};
		}

		namespace stream2
		{
			enum
			{
				TIM8_CH1_0 = 0,
				TIM8_CH2 = 0,
				TIM8_CH3 = 0,
				ADC_CH2 = 1,
				SPI1_RX = 3,
				USART1_RX = 4,
				USART6_RX = 5,
				TIM1_CH2 = 6,
				TIM8_CH1_7 = 7
			};
		}

		namespace stream3
		{
			enum
			{
				SAI1_A = 0,
				ADC_CH2 = 1,
				SPI5_RX = 2,
				SPI1_TX = 3,
				SDIO_DMA = 4,
				SPI4_RX = 5,
				TIM1_CH1 = 6,
				TIM8_CH2 = 7
			};
		}

		namespace stream4
		{
			enum
			{
				ADC_CH1 = 0,
				SAI1_B = 1,
				SPI5_TX = 2,
				SAI2_A = 3,
				SPI4_TX = 5,
				TIM1_CH4 = 6,
				TIM1_TRIG = 6,
				TIM1_COM = 6,
				TIM8_CH3 = 7
			};
		}

		namespace stream5
		{
			enum
			{
				SAI1_B = 0,
				SPI6_TX = 1,
				CRYP_OUT = 2,
				SPI1_TX = 3,
				USART1_RX = 4,
				TIM1_UP = 6,
				SPI5_RX = 7
			};
		}

		namespace stream6
		{
			enum
			{
				TIM1_CH1 = 0,
				TIM1_CH2 = 0,
				TIM1_CH3_0 = 0,
				SPI6_RX = 1,
				CRYP_IN = 2,
				SAI2_B = 3,
				SDIO_DMA = 4,
				USART6_TX = 5,
				TIM1_CH3_6 = 6,
				SPI5_TX = 7
			};
		}

		namespace stream7
		{
			enum
			{
				DCMI_DMA = 1,
				HASH_IN = 2,
				QUADSPI_DMA = 3,
				USART1_TX = 4,
				USART6_TX = 5,
				TIM8_CH4 = 7,
				TIM8_TRIG = 7,
				TIM8_COM = 7
			};
		}
	}
}

#endif

