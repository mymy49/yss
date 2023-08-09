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

#ifndef YSS_DEFINE_STM32F030XX__H_
#define YSS_DEFINE_STM32F030XX__H_

namespace define
{
	namespace clock
	{
		namespace pll
		{
			namespace src
			{
				enum
				{
					HSI_DIV2 = 0,
					HSE = 1
				};
			}

			namespace xtpre
			{
				enum
				{
					NO_DIV = 0,
					DIV2 = 1
				};
			}
		}

		namespace usbclk
		{
			namespace src
			{
				enum
				{
					MAIN_PLL = 0,
					SAI_PLL = 1,
				};
			}
		}

		namespace sysclk
		{
			namespace src
			{
				enum
				{
					HSI = 0,
					HSE = 1,
					PLL = 2
				};
			}
		}

		namespace divFactor
		{
			namespace ahb
			{
				enum
				{
					NO_DIV = 0,
					DIV2 = 0x8,
					DIV4 = 0x9,
					DIV8 = 0xa,
					DIV16 = 0xb,
					DIV64 = 0xc,
					DIV128 = 0xd,
					DIV256 = 0xe,
					DIV512 = 0xf
				};
			}

			namespace apb
			{
				enum
				{
					NO_DIV = 0,
					DIV2 = 0x4,
					DIV4 = 0x5,
					DIV8 = 0x6,
					DIV16 = 0x7,
				};
			}
		}
	}

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

	namespace i2c
	{
		namespace speed
		{
			enum
			{
				STANDARD = 0,
				FAST,
				FAST_PLUS,
			};
		}
	}

	namespace adc
	{
		namespace sampleTime
		{
			enum
			{
				CYCLE_1_5 = 0,
				CYCLE_7_5,
				CYCLE_13_5,
				CYCLE_28_5,
				CYCLE_41_5,
				CYCLE_55_5,
				CYCLE_71_5,
				CYCLE_239_5,
			};
		}
	}

	namespace spi
	{
		namespace mode
		{
			enum
			{
				MODE0 = 0,
				MODE1,
				MODE2,
				MODE3
			};
		}

		namespace bit
		{
			enum
			{
				BIT4 = 3,
				BIT5,
				BIT6,
				BIT7,
				BIT8,
				BIT9,
				BIT10,
				BIT11,
				BIT12,
				BIT13,
				BIT14,
				BIT15,
				BIT16,
			};
		}
	}

	namespace flash
	{
		namespace bank
		{
			enum
			{
				DUAL_BANK = 0,
				SINGLE_BANK,
			};
		}
	}

	namespace usart
	{
		namespace stopBit
		{
			enum
			{
				BIT_1 = 0,
				BIT_2,
			};
		}
	}

	namespace uart
	{
		namespace stopBit
		{
			enum
			{
				BIT_1 = 0,
				BIT_2,
			};
		}
	}

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


// 사용 가능한 DMA 채널 정의
#define DMA_CH1			0
#define DMA_CH2			1
#define DMA_CH3			2
#define DMA_CH4			3
#define DMA_CH5			4

#endif


