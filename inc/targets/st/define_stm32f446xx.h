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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

